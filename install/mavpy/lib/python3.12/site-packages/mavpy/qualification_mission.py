#!/usr/bin/env python3
import rclpy
import time
from enum import Enum
from rclpy.node import Node
from std_msgs.msg import String
from orca_msgs.msg import OrcaAttitude, OrcaControl, OrcaDepth, GateDetection, OrcaProximity

class State(str, Enum):
    WAIT_ARM      = 'WAIT_ARM'
    INIT          = 'INIT'
    DIVE          = 'DIVE'
    HOLD          = 'HOLD'
    FORWARD_1     = 'FORWARD_1'
    GATE_ALIGN    = 'GATE_ALIGN'
    STOP_1        = 'STOP_1'
    UTURN         = 'UTURN'
    GATE_ALIGN_2  = 'GATE_ALIGN_2'
    FORWARD_2     = 'FORWARD_2'
    STOP_2        = 'STOP_2'
    SURFACE       = 'SURFACE'
    RESET_MISSION = 'RESET_MISSION'


class RateLimitedPWM:
    """
    Membatasi seberapa sering nilai PWM boleh diperbarui.
    Nilai baru hanya diterapkan jika sudah melewati `interval` detik
    sejak pembaruan terakhir. Selama belum waktunya, nilai lama dipertahankan.
    """
    def __init__(self, initial: int = 1500, interval: float = 1.0):
        self._value    = initial
        self._interval = interval
        self._last_update = 0.0   # belum pernah diupdate

    def update(self, new_value: int) -> int:
        """
        Coba perbarui nilai PWM.
        Mengembalikan nilai PWM yang aktif (baru atau lama).
        """
        now = time.time()
        if now - self._last_update >= self._interval:
            self._value       = new_value
            self._last_update = now
        return self._value

    def reset(self, value: int = 1500):
        """Reset ke nilai netral dan hapus timer."""
        self._value       = value
        self._last_update = 0.0


class QualificationMission(Node):
    def __init__(self):
        super().__init__('qualification_mission')

        # --- PARAMETER MISI ---
        self.target_depth         = 12
        self.neutral              = 1500
        self.forward_fast         = 1750
        self.forward_slow         = 1600
        self.throttle_down        = 1300
        self.throttle_up          = 1700
        self.yaw_kp               = 4.0
        self.lateral_kp           = 250.0
        self.lateral_dead         = 0.08
        self.gate_detect_min_conf = 0.5

        # --- RATE-LIMITED PWM (update max 1x per detik) ---
        self.rl_yaw     = RateLimitedPWM(initial=1500, interval=1.0)
        self.rl_lateral = RateLimitedPWM(initial=1500, interval=1.0)

        # --- DATA & STATE ---
        self.state           = State.WAIT_ARM
        self.state_since     = time.time()
        self.depth           = None
        self.yaw             = None
        self.initial_heading = None
        self.is_armed        = False

        self.gate_detected       = False
        self.gate_cx_norm        = 0.0
        self.last_gate_seen_time = 0.0

        # --- PUBLISHERS ---
        self.control_pub = self.create_publisher(OrcaControl, '/orca/auto/control', 10)
        self.state_pub   = self.create_publisher(String,      '/orca/mission/state', 10)

        # --- SUBSCRIPTIONS ---
        self.create_subscription(OrcaDepth,     '/orca/sensor/depth',    self.depth_cb,     10)
        self.create_subscription(OrcaAttitude,  '/orca/sensor/attitude', self.attitude_cb,  10)
        self.create_subscription(GateDetection, '/orca/perception/gate', self.gate_cb,      10)
        self.create_subscription(OrcaProximity, '/orca/start_trigger',   self.proximity_cb, 10)

        self.create_timer(0.1, self.update)
        self.get_logger().info("MISSION READY — waiting for proximity trigger")

    # ------------------------------------------------------------------ #
    #  CALLBACKS                                                           #
    # ------------------------------------------------------------------ #

    def depth_cb(self, msg: OrcaDepth):
        self.depth = msg.depth

    def attitude_cb(self, msg: OrcaAttitude):
        self.yaw = msg.initial_deg

    def gate_cb(self, msg: GateDetection):
        if msg.detected and msg.confidence >= self.gate_detect_min_conf:
            self.gate_detected       = True
            self.gate_cx_norm        = msg.center_x_norm
            self.last_gate_seen_time = time.time()
        else:
            self.gate_detected = False

    def proximity_cb(self, msg: OrcaProximity):
        prev          = self.is_armed
        self.is_armed = msg.triggered
        if self.is_armed and not prev:
            self.get_logger().info("PROXIMITY ON → arm & start mission")
        if not self.is_armed and prev:
            self.get_logger().warn("PROXIMITY OFF → disarm & reset mission")

    # ------------------------------------------------------------------ #
    #  HELPERS                                                             #
    # ------------------------------------------------------------------ #

    def publish(self, throttle=None, forward=None, lateral=None, yaw=None, mode='ALT_HOLD'):
        msg = OrcaControl()
        msg.throttle     = int(self.neutral if throttle is None else throttle)
        msg.forward      = int(self.neutral if forward  is None else forward)
        msg.lateral      = int(self.neutral if lateral  is None else lateral)
        msg.yaw          = int(self.neutral if yaw      is None else yaw)
        msg.control_mode = mode
        msg.arm_mode     = 'arm' if self.is_armed else 'disarm'
        msg.source       = 'auto'
        self.control_pub.publish(msg)

    def set_state(self, s: State):
        self.state       = s
        self.state_since = time.time()
        self.get_logger().info(f"STATE → {s}")
        msg = String(); msg.data = str(s)
        self.state_pub.publish(msg)

    def reset_vars(self):
        self.initial_heading     = None
        self.gate_detected       = False
        self.gate_cx_norm        = 0.0
        self.last_gate_seen_time = 0.0
        # Reset rate limiter ke netral saat misi direset
        self.rl_yaw.reset(self.neutral)
        self.rl_lateral.reset(self.neutral)
        self.get_logger().info("Mission variables reset")

    def elapsed(self) -> float:
        return time.time() - self.state_since

    def yaw_cmd(self) -> int:
        """
        Hitung PWM yaw dari PID, lalu lewatkan rate limiter.
        Nilai PWM hanya berubah maksimal 1x per detik.
        """
        if self.yaw is None:
            return self.neutral
        target = self.initial_heading if self.initial_heading is not None else 0.0
        err = target - self.yaw
        while err >  180: err -= 360
        while err < -180: err += 360
        raw = max(1300, min(1700, self.neutral + int(self.yaw_kp * err)))
        return self.rl_yaw.update(raw)

    def lateral_cmd(self) -> int:
        """
        Hitung PWM lateral dari PID, lalu lewatkan rate limiter.
        Nilai PWM hanya berubah maksimal 1x per detik.
        """
        cx = self.gate_cx_norm
        if abs(cx) < self.lateral_dead:
            # Langsung reset rate limiter agar netral segera berlaku
            self.rl_lateral.reset(self.neutral)
            return self.neutral
        raw = max(1300, min(1700, self.neutral + int(self.lateral_kp * cx)))
        return self.rl_lateral.update(raw)

    # ------------------------------------------------------------------ #
    #  FINITE STATE MACHINE                                                #
    # ------------------------------------------------------------------ #

    def update(self):
        now = time.time()

        # Guard global: disarm di luar state aman → reset
        if not self.is_armed and self.state not in (State.WAIT_ARM, State.RESET_MISSION):
            self.reset_vars()
            self.set_state(State.WAIT_ARM)
            self.publish(mode='MANUAL')
            return

        # 0. WAIT_ARM
        if self.state == State.WAIT_ARM:
            self.publish()
            if self.is_armed:
                self.set_state(State.INIT)
            return

        # 1. INIT
        if self.state == State.INIT:
            if self.depth is not None and self.yaw is not None:
                self.initial_heading = self.yaw
                self.set_state(State.DIVE)
            return

        # 2. DIVE
        if self.state == State.DIVE:
            if self.depth < self.target_depth:
                self.publish(throttle=self.throttle_down)
            else:
                self.set_state(State.HOLD)
            return

        # 3. HOLD
        if self.state == State.HOLD:
            self.publish()
            if self.elapsed() > 2.0:
                self.set_state(State.FORWARD_1)
            return

        # 4. FORWARD_1
        if self.state == State.FORWARD_1:
            self.publish(forward=self.forward_fast)
            if self.gate_detected and (now - self.last_gate_seen_time < 0.3):
                self.set_state(State.GATE_ALIGN)
                return
            if self.elapsed() > 10.0:
                self.get_logger().warn("Gate NOT detected in FORWARD_1")
                self.set_state(State.STOP_1)
            return

        # 5. GATE_ALIGN
        if self.state == State.GATE_ALIGN:
            if self.gate_detected:
                self.publish(
                    forward=self.forward_slow,
                    lateral=self.lateral_cmd(),
                    yaw=self.yaw_cmd()
                )
            else:
                lost_time = now - self.last_gate_seen_time
                if lost_time > 3.0:
                    self.get_logger().info("Gate passed → STOP_1")
                    self.set_state(State.STOP_1)
                else:
                    self.publish(forward=self.forward_fast, yaw=self.yaw_cmd())
            return

        # 6. STOP_1
        if self.state == State.STOP_1:
            self.publish()
            if self.elapsed() > 1.0:
                self.set_state(State.UTURN)
            return

        # 7. UTURN
        if self.state == State.UTURN:
            if self.yaw is None:
                return
            if self.yaw >= 160:
                self.publish()
                self.set_state(State.GATE_ALIGN_2)
                return
            self.publish(yaw=1700)
            return

        # 8. GATE_ALIGN_2
        if self.state == State.GATE_ALIGN_2:
            if self.gate_detected and (now - self.last_gate_seen_time < 0.3):
                self.publish(
                    forward=self.forward_slow,
                    lateral=self.lateral_cmd(),
                    yaw=self.yaw_cmd()
                )
                self.get_logger().info("Gate detected again → ALIGN")
            else:
                self.set_state(State.FORWARD_2)
            return

        # 9. FORWARD_2
        if self.state == State.FORWARD_2:
            self.publish(forward=self.forward_fast)
            if self.elapsed() > 7.0:
                self.set_state(State.STOP_2)
            return

        # 10. STOP_2
        if self.state == State.STOP_2:
            self.publish()
            if self.elapsed() > 2.0:
                self.set_state(State.SURFACE)
            return

        # 11. SURFACE
        if self.state == State.SURFACE:
            if self.depth is not None and self.depth < 0.1:
                self.set_state(State.RESET_MISSION)
                return
            self.publish(throttle=self.throttle_up)
            return

        # 12. RESET_MISSION
        if self.state == State.RESET_MISSION:
            self.publish()
            if not self.is_armed:
                self.get_logger().info("PROXIMITY OFF → mission reset → WAIT_ARM")
                self.reset_vars()
                self.set_state(State.WAIT_ARM)
            else:
                self.get_logger().info(
                    "MISSION COMPLETE — ketuk proximity untuk reset",
                    throttle_duration_sec=5
                )
            return

def main():
    rclpy.init()
    node = QualificationMission()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()