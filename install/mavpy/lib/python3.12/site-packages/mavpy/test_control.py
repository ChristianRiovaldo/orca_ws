#!/usr/bin/env python3
import time
from typing import Optional

import rclpy
from rclpy.node import Node
from pymavlink import mavutil

from orca_msgs.msg import OrcaControl, OrcaProximity, FailsafeTrigger


class ControlBridge(Node):
    """
    Jalur tunggal dari ROS 2 menuju Pixhawk untuk Konfigurasi 8 Thruster (ArduSub Heavy / 6-DOF).

    Prioritas kendali:
    1. Fail-safe control
    2. Manual control dari GCS / Keyboard
    3. Auto control
    4. Neutral fallback
    """

    def __init__(self):
        super().__init__('orca_control_bridge_node')

        # =========================
        # Parameter topic
        # =========================
        self.declare_parameter('mavlink_url', 'udpin:0.0.0.0:14551')
        self.declare_parameter('manual_control_topic', '/orca/manual/control')
        self.declare_parameter('auto_control_topic', '/orca/auto/control')
        self.declare_parameter('failsafe_control_topic', '/orca/failsafe/control')
        self.declare_parameter('failsafe_trigger_topic', '/orca/failsafe/trigger')
        self.declare_parameter('proximity_topic', '/orca/start_trigger')

        # =========================
        # Parameter kendali
        # =========================
        self.declare_parameter('publish_override_hz', 10.0)
        self.declare_parameter('neutral_pwm', 1500)
        self.declare_parameter('auto_stale_timeout_sec', 0.6)
        self.declare_parameter('manual_stale_timeout_sec', 0.6)
        self.declare_parameter('failsafe_stale_timeout_sec', 0.6)
        self.declare_parameter('manual_priority', True)
        self.declare_parameter('manual_release_mode', 'MISSION')

        # Servo gripper
        self.declare_parameter('gripper_servo_channel', 10)
        self.declare_parameter('gripper_pwm_open_right', 955)
        self.declare_parameter('gripper_pwm_open_left', 2100)
        self.declare_parameter('gripper_pwm_close', 1500)

        self.mavlink_url = str(self.get_parameter('mavlink_url').value)
        self.manual_control_topic = str(self.get_parameter('manual_control_topic').value)
        self.auto_control_topic = str(self.get_parameter('auto_control_topic').value)
        self.failsafe_control_topic = str(self.get_parameter('failsafe_control_topic').value)
        self.failsafe_trigger_topic = str(self.get_parameter('failsafe_trigger_topic').value)
        self.proximity_topic = str(self.get_parameter('proximity_topic').value)

        self.publish_override_hz = float(self.get_parameter('publish_override_hz').value)
        self.neutral_pwm = int(self.get_parameter('neutral_pwm').value)
        self.auto_stale_timeout_sec = float(self.get_parameter('auto_stale_timeout_sec').value)
        self.manual_stale_timeout_sec = float(self.get_parameter('manual_stale_timeout_sec').value)
        self.failsafe_stale_timeout_sec = float(self.get_parameter('failsafe_stale_timeout_sec').value)
        self.manual_priority = bool(self.get_parameter('manual_priority').value)
        self.manual_release_mode = str(self.get_parameter('manual_release_mode').value).upper().strip()

        self.gripper_servo_channel = int(self.get_parameter('gripper_servo_channel').value)
        self.gripper_pwm_map = {
            'open_right': int(self.get_parameter('gripper_pwm_open_right').value),
            'open_left': int(self.get_parameter('gripper_pwm_open_left').value),
            'close': int(self.get_parameter('gripper_pwm_close').value),
        }

        # =========================
        # MAVLink Connection
        # =========================
        self.master = mavutil.mavlink_connection(self.mavlink_url)
        self.get_logger().info(f'Menunggu heartbeat Pixhawk di {self.mavlink_url}...')
        self.master.wait_heartbeat()
        self.get_logger().info(f'Pixhawk terhubung via {self.mavlink_url}')

        # Otomatis bebaskan fungsi channel servo agar MAV_CMD_DO_SET_SERVO tidak gagal
        self._set_servo_channel_disabled(self.gripper_servo_channel)

        # =========================
        # State command
        # =========================
        self.manual_cmd = self.make_neutral('manual_init')
        self.auto_cmd = self.make_neutral('auto_init')
        self.failsafe_cmd = self.make_neutral('failsafe_init')

        self.last_manual_time = 0.0
        self.last_auto_time = 0.0
        self.last_failsafe_control_time = 0.0
        self.failsafe_active = False

        self.last_arm: Optional[bool] = None
        self.last_mode: Optional[str] = None
        self.last_gripper: Optional[str] = None
        self.last_selected_source = ''
        self.last_failsafe_warning_time = 0.0

        self.proximity_triggered = False
        self.prev_proximity = False

        # =========================
        # ROS interface
        # =========================
        self.create_subscription(OrcaControl, self.manual_control_topic, self.manual_cb, 10)
        self.create_subscription(OrcaControl, self.auto_control_topic, self.auto_cb, 10)
        self.create_subscription(OrcaControl, self.failsafe_control_topic, self.failsafe_control_cb, 10)
        self.create_subscription(FailsafeTrigger, self.failsafe_trigger_topic, self.failsafe_trigger_cb, 10)
        self.create_subscription(OrcaProximity, self.proximity_topic, self.proximity_cb, 10)

        self.create_timer(
            1.0 / max(1.0, self.publish_override_hz),
            self.send_selected_control,
        )

    # ==========================================================
    # ArduPilot Parameter Config
    # ==========================================================
    def _set_servo_channel_disabled(self, channel: int):
        """
        Set SERVOx_FUNCTION ke 0 (Disabled) via MAVLink agar channel bisa
        di-override penuh oleh MAV_CMD_DO_SET_SERVO tanpa konflik di ArduPilot.
        """
        param_name = f'SERVO{channel}_FUNCTION'.encode('utf-8')
        self.get_logger().info(f'Mengatur parameter {param_name.decode()} -> 0 (Disabled)...')
        self.master.mav.param_set_send(
            self.master.target_system,
            self.master.target_component,
            param_name,
            0.0,
            mavutil.mavlink.MAV_PARAM_TYPE_REAL32
        )

    # ==========================================================
    # Message helpers
    # ==========================================================
    def make_neutral(self, source: str, disarm: bool = False) -> OrcaControl:
        msg = OrcaControl()
        msg.pitch = self.neutral_pwm
        msg.roll = self.neutral_pwm
        msg.throttle = self.neutral_pwm
        msg.lateral = self.neutral_pwm
        msg.forward = self.neutral_pwm
        msg.yaw = self.neutral_pwm
        msg.arm_mode = 'disarm' if disarm else ''
        msg.control_mode = ''
        msg.gripper_mode = ''
        msg.source = source
        return msg

    def _is_fresh(self, last_time: float, timeout: float) -> bool:
        return last_time > 0.0 and (time.monotonic() - last_time) <= timeout

    def manual_is_active(self) -> bool:
        if not self._is_fresh(self.last_manual_time, self.manual_stale_timeout_sec):
            return False

        mode = (self.manual_cmd.control_mode or '').upper().strip()
        return mode != self.manual_release_mode

    def auto_is_active(self) -> bool:
        return self._is_fresh(self.last_auto_time, self.auto_stale_timeout_sec)

    def failsafe_control_is_fresh(self) -> bool:
        return self._is_fresh(self.last_failsafe_control_time, self.failsafe_stale_timeout_sec)

    # ==========================================================
    # ROS callbacks
    # ==========================================================
    def manual_cb(self, msg: OrcaControl):
        self.manual_cmd = self._sanitize_control(msg)
        self.last_manual_time = time.monotonic()

    def auto_cb(self, msg: OrcaControl):
        self.auto_cmd = self._sanitize_control(msg)
        self.last_auto_time = time.monotonic()

    def failsafe_control_cb(self, msg: OrcaControl):
        self.failsafe_cmd = self._sanitize_control(msg)
        self.last_failsafe_control_time = time.monotonic()

    def failsafe_trigger_cb(self, msg: FailsafeTrigger):
        if msg.active and not self.failsafe_active:
            self.get_logger().fatal('Fail-safe trigger aktif. ControlBridge beralih ke /orca/failsafe/control.')
            self.last_selected_source = ''

        elif not msg.active and self.failsafe_active:
            self.get_logger().info('Fail-safe trigger nonaktif. Kendali manual/auto tersedia kembali. ARM ulang disarankan.')
            self.last_arm = None
            self.last_selected_source = ''

        self.failsafe_active = bool(msg.active)

    def proximity_cb(self, msg: OrcaProximity):
        self.proximity_triggered = bool(msg.triggered)

    # ==========================================================
    # Control selection
    # ==========================================================
    def _select_control(self) -> OrcaControl:
        if self.failsafe_active:
            if self.failsafe_control_is_fresh():
                return self.failsafe_cmd

            now = time.monotonic()
            if now - self.last_failsafe_warning_time > 0.5:
                self.last_failsafe_warning_time = now
                self.get_logger().error('Fail-safe aktif tetapi command fail-safe stale. Mengirim neutral disarm.')

            return self.make_neutral('failsafe_stale_neutral', disarm=True)

        if self.manual_priority and self.manual_is_active():
            return self.manual_cmd

        if self.auto_is_active():
            return self.auto_cmd

        if self.manual_is_active():
            return self.manual_cmd

        return self.make_neutral('neutral_no_active_source')

    def send_selected_control(self):
        msg = self._select_control()

        source = msg.source or 'unknown'
        if source != self.last_selected_source:
            self.last_selected_source = source
            self.get_logger().info(f'Control source: {source}')

        self._handle_arm_logic(msg)
        self._send_mode(msg.control_mode)
        self._send_gripper(msg.gripper_mode)
        self._send_rc_override(msg)

    # ==========================================================
    # MAVLink commands
    # ==========================================================
    def _send_rc_override(self, msg: OrcaControl):
        self.master.mav.rc_channels_override_send(
            self.master.target_system,
            self.master.target_component,
            int(msg.pitch),
            int(msg.roll),
            int(msg.throttle),
            int(msg.yaw),
            int(msg.forward),
            int(msg.lateral),
            0,
            0,
        )

    def _handle_arm_logic(self, msg: OrcaControl):
        arm_mode = (msg.arm_mode or '').strip().lower()

        if arm_mode in ('arm', 'disarm'):
            self._send_arm(arm_mode)
            return

        if self.failsafe_active:
            return

        if self.proximity_triggered and not self.prev_proximity:
            self.get_logger().info('Proximity trigger → ARM')
            self._send_arm('arm')

        elif not self.proximity_triggered and self.prev_proximity:
            self.get_logger().info('Proximity trigger off → DISARM')
            self._send_arm('disarm')

        self.prev_proximity = self.proximity_triggered

    def _send_arm(self, arm_mode: str):
        arm = arm_mode == 'arm'
        if self.last_arm == arm:
            return

        self.last_arm = arm

        self.master.mav.command_long_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_CMD_COMPONENT_ARM_DISARM,
            0,
            1 if arm else 0,
            0, 0, 0, 0, 0, 0,
        )

        self.get_logger().info(f'ARM COMMAND: {arm_mode}')

    def _send_mode(self, mode_name: str):
        mode_name = (mode_name or '').upper().strip()
        if not mode_name:
            return

        if self.last_mode == mode_name:
            return

        mode_map = self.master.mode_mapping()
        mode_id = mode_map.get(mode_name)

        if mode_id is None:
            self.get_logger().error(f'Mode tidak ditemukan: {mode_name}')
            return

        self.last_mode = mode_name
        self.master.set_mode(mode_id)
        self.get_logger().info(f'MODE COMMAND: {mode_name}')

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
            0,
            self.gripper_servo_channel,
            pwm,
            0, 0, 0, 0, 0,
        )

        self.get_logger().info(f'GRIPPER COMMAND: {gripper_mode} → PWM {pwm}')

    # ==========================================================
    # Utility
    # ==========================================================
    def _sanitize_control(self, msg: OrcaControl) -> OrcaControl:
        msg.pitch = self._clamp_pwm(int(msg.pitch))
        msg.roll = self._clamp_pwm(int(msg.roll))
        msg.forward = self._clamp_pwm(int(msg.forward))
        msg.lateral = self._clamp_pwm(int(msg.lateral))
        msg.throttle = self._clamp_pwm(int(msg.throttle))
        msg.yaw = self._clamp_pwm(int(msg.yaw))
        return msg

    def _clamp_pwm(self, value: int) -> int:
        if value < 1100 or value > 1900:
            return self.neutral_pwm
        return max(1100, min(1900, value))

    def reset_override(self):
        try:
            self.master.mav.rc_channels_override_send(
                self.master.target_system,
                self.master.target_component,
                *([65535] * 8),
            )
        except Exception:
            pass

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