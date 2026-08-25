#!/usr/bin/env python3
import time
import rclpy
from rclpy.node import Node
from pymavlink import mavutil
from orca_msgs.msg import OrcaControl, OrcaProximity

class ControlBridge(Node):
    def __init__(self):
        super().__init__('control_bridge')

        self.declare_parameter('mavlink_url', 'udpin:0.0.0.0:14551')
        self.declare_parameter('manual_control_topic', '/orca/manual/control')
        self.declare_parameter('auto_control_topic', '/orca/auto/control')
        self.declare_parameter('proximity_topic', '/orca/start_trigger')

        self.declare_parameter('publish_override_hz', 10.0)
        self.declare_parameter('neutral_pwm', 1500)

        self.declare_parameter('auto_stale_timeout_sec', 0.6)
        self.declare_parameter('manual_stale_timeout_sec', 0.3)

        self.declare_parameter('manual_priority', True)
        self.declare_parameter('gripper_servo_channel', 10)
        self.declare_parameter('manual_release_mode', 'MISSION')

        self.declare_parameter('gripper_pwm_open_right', 2100)
        self.declare_parameter('gripper_pwm_open_left',  955)
        self.declare_parameter('gripper_pwm_close',      1500)

        self.mavlink_url          = str(self.get_parameter('mavlink_url').value)
        self.manual_control_topic = str(self.get_parameter('manual_control_topic').value)
        self.auto_control_topic   = str(self.get_parameter('auto_control_topic').value)
        self.proximity_topic      = str(self.get_parameter('proximity_topic').value)

        self.publish_override_hz      = float(self.get_parameter('publish_override_hz').value)
        self.neutral_pwm              = int(self.get_parameter('neutral_pwm').value)
        self.auto_stale_timeout_sec   = float(self.get_parameter('auto_stale_timeout_sec').value)
        self.manual_stale_timeout_sec = float(self.get_parameter('manual_stale_timeout_sec').value)
        self.manual_priority          = bool(self.get_parameter('manual_priority').value)
        self.gripper_servo_channel    = int(self.get_parameter('gripper_servo_channel').value)
        self.manual_release_mode      = str(self.get_parameter('manual_release_mode').value).upper().strip()

        self.gripper_pwm_map = {
            'open_right': int(self.get_parameter('gripper_pwm_open_right').value),
            'open_left':  int(self.get_parameter('gripper_pwm_open_left').value),
            'close':      int(self.get_parameter('gripper_pwm_close').value),
        }

        self.master = mavutil.mavlink_connection(self.mavlink_url)
        self.master.wait_heartbeat()
        self.get_logger().info(f'Pixhawk connected via {self.mavlink_url}')

        self.manual_cmd = self.make_neutral('manual_init')
        self.auto_cmd   = self.make_neutral('auto_init')

        self.last_manual_time = 0.0
        self.last_auto_time   = 0.0

        self.last_arm             = None
        self.last_mode            = None
        self.last_gripper         = None
        self.last_selected_source = ''

        self.proximity_triggered = False
        self.prev_proximity      = False

        self._in_failsafe = False

        self.create_subscription(OrcaControl, self.manual_control_topic, self.manual_cb, 10)
        self.create_subscription(OrcaControl, self.auto_control_topic,   self.auto_cb,   10)
        self.create_subscription(OrcaProximity, self.proximity_topic,    self.proximity_cb, 10)
        self.create_timer(1.0 / max(1.0, self.publish_override_hz), self.send_selected_control)

    # ── Helper ───────────────────────────────────────────────────────────────

    def make_neutral(self, source: str) -> OrcaControl:
        msg = OrcaControl()
        msg.throttle     = self.neutral_pwm
        msg.lateral      = self.neutral_pwm
        msg.forward      = self.neutral_pwm
        msg.yaw          = self.neutral_pwm
        msg.arm_mode     = ''
        msg.control_mode = ''
        msg.gripper_mode = ''
        msg.source       = source
        return msg

    def _is_fresh(self, last_time: float, timeout: float) -> bool:
        return last_time > 0.0 and (time.time() - last_time) <= timeout

    def manual_is_active(self) -> bool:
        if not self._is_fresh(self.last_manual_time, self.manual_stale_timeout_sec):
            return False
        mode = (self.manual_cmd.control_mode or '').upper().strip()
        return mode != self.manual_release_mode

    def auto_is_active(self) -> bool:
        return self._is_fresh(self.last_auto_time, self.auto_stale_timeout_sec)

    # ── Callbacks ────────────────────────────────────────────────────────────

    def manual_cb(self, msg: OrcaControl):
        source = (msg.source or '').strip()
        if source.startswith('tcp_failsafe'):
            self.manual_cmd       = msg
            self.last_manual_time = 0.0
            self.get_logger().warn(f'[FAILSAFE] Manual invalidated oleh pesan: source={source}')
            return

        self.manual_cmd       = msg
        self.last_manual_time = time.time()

    def auto_cb(self, msg: OrcaControl):
        self.auto_cmd     = msg
        self.last_auto_time = time.time()

    def proximity_cb(self, msg: OrcaProximity):
        self.proximity_triggered = msg.triggered

    # ── MAVLink commands ─────────────────────────────────────────────────────
    def _send_arm(self, arm_mode: str):
        arm_mode = (arm_mode or '').strip().lower()
        if arm_mode not in ('arm', 'disarm'):
            return
        arm = arm_mode == 'arm'
        if self.last_arm == arm:
            return
        self.last_arm = arm
        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0, 1 if arm else 0, 0, 0, 0, 0, 0, 0,
        )
        self.get_logger().info(f'ARM COMMAND: {arm_mode}')

    def _send_mode(self, mode_name: str):
        mode_name = (mode_name or '').upper().strip()
        if not mode_name:
            return
        if self.last_mode == mode_name:
            return
        mode_map = self.master.mode_mapping()
        mode_id  = mode_map.get(mode_name)
        if mode_id is None:
            self.get_logger().error(f'Mode tidak ditemukan: {mode_name}')
            return
        self.last_mode = mode_name
        self.master.set_mode(mode_id)
        self.get_logger().info(f'MODE: {mode_name}')

    def _send_gripper(self, gripper_mode: str):
        gripper_mode = (gripper_mode or '').strip().lower()
        if gripper_mode not in self.gripper_pwm_map:
            return
        if self.last_gripper == gripper_mode:
            return
        self.last_gripper = gripper_mode
        pwm = self.gripper_pwm_map[gripper_mode]
        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_DO_SET_SERVO,
            0, self.gripper_servo_channel, pwm, 0, 0, 0, 0, 0,
        )
        self.get_logger().info(f'GRIPPER: {gripper_mode} → PWM {pwm}')

    # ── Control selection ────────────────────────────────────────────────────

    def _select_control(self) -> tuple[OrcaControl, bool]:
        if self.manual_priority and self.manual_is_active():
            return self.manual_cmd, False

        if self.auto_is_active():
            return self.auto_cmd, False

        if self.manual_is_active():
            return self.manual_cmd, False

        return self.make_neutral('failsafe'), True

    def _handle_arm_logic(self, msg: OrcaControl):
        if msg.arm_mode in ('arm', 'disarm'):
            self._send_arm(msg.arm_mode)
            return

        if self.proximity_triggered and not self.prev_proximity:
            self.get_logger().info('Proximity → ARM')
            self._send_arm('arm')
        elif not self.proximity_triggered and self.prev_proximity:
            self.get_logger().info('Proximity → DISARM')
            self._send_arm('disarm')

        self.prev_proximity = self.proximity_triggered

    # ── Main timer loop ──────────────────────────────────────────────────────

    def send_selected_control(self):
        msg, is_failsafe = self._select_control()

        # Log perubahan status failsafe
        if is_failsafe and not self._in_failsafe:
            self._in_failsafe = True
            self.get_logger().warn(
                '[FAILSAFE] Tidak ada sumber kontrol aktif — mengirim neutral PWM ke Pixhawk.'
            )
        elif not is_failsafe and self._in_failsafe:
            self._in_failsafe = False
            self.get_logger().info(
                f'[FAILSAFE] Kontrol aktif kembali — source: {msg.source}'
            )

        # Log perubahan source (hanya saat tidak failsafe)
        source = msg.source or 'unknown'
        if source != self.last_selected_source:
            self.last_selected_source = source
            if not is_failsafe:
                self.get_logger().info(f'Control source: {source}')

        self._handle_arm_logic(msg)
        self._send_mode(msg.control_mode)
        self._send_gripper(msg.gripper_mode)

        self.master.mav.rc_channels_override_send(
            self.master.target_system,
            self.master.target_component,
            0, 0,
            int(msg.throttle),
            int(msg.yaw),
            int(msg.forward),
            int(msg.lateral),
            0, 0,
        )

    # ── Cleanup ──────────────────────────────────────────────────────────────

    def reset_override(self):
        self.master.mav.rc_channels_override_send(
            self.master.target_system,
            self.master.target_component,
            *([65535] * 8)
        )

    def destroy_node(self):
        self.reset_override()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = ControlBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()