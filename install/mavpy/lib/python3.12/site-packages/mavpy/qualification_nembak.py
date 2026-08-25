#!/usr/bin/env python3
import rclpy
import time
from enum import Enum
from rclpy.node import Node
from std_msgs.msg import String
from orca_msgs.msg import OrcaAttitude, OrcaControl, OrcaDepth, OrcaProximity

class State(str, Enum):
    WAIT_ARM      = 'WAIT_ARM'
    INIT          = 'INIT'
    DIVE          = 'DIVE'
    HOLD          = 'HOLD'
    FORWARD_1     = 'FORWARD_1'
    STOP_1        = 'STOP_1'
    UTURN         = 'UTURN'
    FORWARD_2     = 'FORWARD_2'
    STOP_2        = 'STOP_2'
    SURFACE       = 'SURFACE'
    RESET_MISSION = 'RESET_MISSION'

class QualificationNembak(Node):
    def __init__(self):
        super().__init__('qualification_nembak')

        self.target_depth    = 0.7
        self.neutral         = 1500
        self.forward_fast    = 1800
        self.throttle_down   = 1350
        self.throttle_up     = 1550

        self.state           = State.WAIT_ARM
        self.state_since     = time.time()
        self.depth           = None
        self.yaw             = None
        self.is_armed        = False
        self.initial_heading = None

        self.control_pub = self.create_publisher(OrcaControl, '/orca/auto/control', 10)
        self.state_pub   = self.create_publisher(String,      '/orca/mission/state', 10)

        self.create_subscription(OrcaDepth,     '/orca/sensor/depth',    self.depth_cb,    10)
        self.create_subscription(OrcaAttitude,  '/orca/sensor/attitude', self.attitude_cb, 10)
        self.create_subscription(OrcaProximity, '/orca/start_trigger',   self.proximity_cb,10)

        self.create_timer(0.1, self.update)
        self.get_logger().info("MISSION READY — waiting for proximity trigger")

    # ------------------------------------------------------------------ callbacks
    def depth_cb(self, msg: OrcaDepth):
        self.depth = msg.depth

    def attitude_cb(self, msg: OrcaAttitude):
        self.yaw = msg.initial_deg

    def proximity_cb(self, msg: OrcaProximity):
        prev = self.is_armed
        self.is_armed = msg.triggered
        if self.is_armed and not prev:
            self.get_logger().info("PROXIMITY ON → arm & start mission")
        if not self.is_armed and prev:
            self.get_logger().warn("PROXIMITY OFF → disarm & reset mission")

    # ------------------------------------------------------------------ helpers
    def publish(self, throttle=None, forward=None, yaw=None, mode='ALT_HOLD'):
        msg = OrcaControl()
        msg.throttle     = int(self.neutral if throttle is None else throttle)
        msg.forward      = int(self.neutral if forward  is None else forward)
        msg.lateral      = int(self.neutral)
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
        self.initial_heading = None
        self.get_logger().info("Mission variables reset")

    def elapsed(self):
        return time.time() - self.state_since

    def uturn_done(self):
        if self.yaw is None or self.initial_heading is None:
            return False
        # delta positif = putar kanan
        delta = self.yaw - self.initial_heading
        while delta <    0: delta += 360
        while delta >= 360: delta -= 360
        return delta >= 160

    # ------------------------------------------------------------------ state machine
    def update(self):
        # disarm di tengah misi → paksa reset
        if not self.is_armed and self.state not in (State.WAIT_ARM, State.RESET_MISSION):
            self.reset_vars()
            self.set_state(State.WAIT_ARM)
            self.publish(mode='MANUAL')
            return

        # 1. Tunggu trigger proximity
        if self.state == State.WAIT_ARM:
            self.publish(mode='MANUAL')
            if self.is_armed:
                self.set_state(State.INIT)
            return

        # 2. Tunggu sensor depth siap
        if self.state == State.INIT:
            # self.initial_heading = self.yaw
            # self.get_logger().info(f"Initial heading locked → {self.initial_heading}°")
            if self.depth is not None:
                self.set_state(State.DIVE)
            return

        # 3. Turun
        if self.state == State.DIVE:
            self.publish(throttle=self.throttle_down, mode='MANUAL')
            if self.depth > self.target_depth:
                self.set_state(State.HOLD)
            return

        # 4. Depth hold 4 detik supaya stabil, kunci heading awal
        if self.state == State.HOLD:
            self.publish()
            if self.elapsed() > 4.0:
                self.set_state(State.FORWARD_1)
            return

        # 5. Maju 6 detik
        if self.state == State.FORWARD_1:
            self.publish(forward=self.forward_fast)
            if self.elapsed() > 3.0:
                self.set_state(State.STOP_1)
            return

        # 6. Stop sebentar sebelum U-turn
        if self.state == State.STOP_1:
            self.publish()
            if self.elapsed() > 1.0:
                self.set_state(State.UTURN)
            return

        # 7. U-turn yaw kanan sampai 160° dari heading awal
        if self.state == State.UTURN:
            if self.yaw is None:
                return
            if self.yaw > 165:
            # if self.uturn_done():
                self.get_logger().info("U-turn selesai → FORWARD_2")
                self.publish()
                self.set_state(State.FORWARD_2)
                return
            self.publish(yaw=1650)
            return

        # 8. Maju lagi 5 detik
        if self.state == State.FORWARD_2:
            self.publish(forward=self.forward_fast)
            if self.elapsed() > 5.0:
                self.set_state(State.STOP_2)
            return

        # 9. Stop sebelum surface
        if self.state == State.STOP_2:
            self.publish()
            if self.elapsed() > 1.0:
                self.set_state(State.SURFACE)
            return

        # 10. Naik sampai depth < 0.05 m
        if self.state == State.SURFACE:
            if self.elapsed() > 1.0:
                self.set_state(State.RESET_MISSION)
                return
            self.publish(throttle=self.throttle_up, mode='MANUAL')
            return

        # 11. Misi selesai — tunggu proximity dilepas untuk reset
        if self.state == State.RESET_MISSION:
            self.publish(mode='MANUAL')
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
    node = QualificationNembak()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()