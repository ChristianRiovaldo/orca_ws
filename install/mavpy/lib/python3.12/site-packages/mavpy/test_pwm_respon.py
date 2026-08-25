#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from orca_msgs.msg import OrcaAttitude, OrcaControl, GateDetection

class TestPwmRespon(Node):
    def __init__(self):
        super().__init__('test_pwm_respon')

        self.neutral      = 1500
        self.yaw_kp       = 4.0
        self.lateral_kp   = 300.0
        self.lateral_dead = 0.08
        self.gate_detect_min_confidence = 0.5

        self.control_pub = self.create_publisher(OrcaControl, '/orca/auto/control', 10)

        self.create_subscription(OrcaAttitude,  '/orca/sensor/attitude', self.attitude_cb, 10)
        self.create_subscription(GateDetection, '/orca/perception/gate', self.gate_cb, 10)

        self.yaw   = None
        self.initial_heading = None

        self.gate_detected = False
        self.gate_cx_norm  = 0.0

        self.create_timer(0.1, self.update)
        self.get_logger().info("Test Yaw & Lateral PWM Response")

    def attitude_cb(self, msg):
        self.yaw = msg.initial_deg

    def gate_cb(self, msg: GateDetection):
        if msg.detected and msg.confidence >= self.gate_detect_min_confidence:
            self.gate_detected = True
            self.gate_cx_norm  = msg.center_x_norm
        else:
            self.gate_detected = False

    def publish(self, throttle=None, forward=None, lateral=None, yaw=None, mode='ALT_HOLD'):
        msg = OrcaControl()
        msg.throttle = int(self.neutral if throttle is None else throttle)
        msg.forward  = int(self.neutral if forward  is None else forward)
        msg.lateral  = int(self.neutral if lateral  is None else lateral)
        msg.yaw      = int(self.neutral if yaw      is None else yaw)
        msg.control_mode = mode
        msg.arm_mode = 'arm'
        msg.source   = 'auto'
        self.control_pub.publish(msg)

    def yaw_cmd(self):
        if self.yaw is None:
            return self.neutral

        target = self.initial_heading
        err = target - self.yaw

        while err > 180: err -= 360
        while err < -180: err += 360

        return max(1300, min(1700, self.neutral + int(self.yaw_kp * err))), err

    def lateral_cmd(self):
        cx = self.gate_cx_norm

        if abs(cx) < self.lateral_dead:
            return self.neutral, cx

        cmd = self.neutral + int(self.lateral_kp * cx)
        cmd = max(1300, min(1700, cmd))

        return cmd, cx

    def update(self):
        if not self.gate_detected:
            self.publish()
            self.get_logger().info("No detection")
            return

        yaw_cmd, yaw_err = self.yaw_cmd()
        lat_cmd, lat_err = self.lateral_cmd()

        self.publish(
            yaw=yaw_cmd,
            lateral=lat_cmd
        )

        self.get_logger().info(
            f"yaw_err={yaw_err:.2f} | lat_err={lat_err:.2f} | "
            f"yaw_pwm={yaw_cmd} | lat_pwm={lat_cmd}"
        )

def main():
    rclpy.init()
    node = TestPwmRespon()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()