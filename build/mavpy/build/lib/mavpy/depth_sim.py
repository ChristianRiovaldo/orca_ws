#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Pose
from orca_msgs.msg import OrcaDepth

import random


class DepthSim(Node):
    def __init__(self):
        super().__init__('depth_sim')

        self.pub = self.create_publisher(
            OrcaDepth,
            '/orca/sensor/depth',
            10
        )

        self.sub = self.create_subscription(
            Pose,
            '/model/ORCA_V3/pose',
            self.pose_callback,
            10
        )

        self.noise_std = 0.02
        self.rho = 1000.0
        self.g = 9.81
        self.P0 = 101325.0

        self.get_logger().info("✅ DepthSim OPSI 3 FULL running")

    def pose_callback(self, msg: Pose):
        z = msg.position.z
        depth = -z

        depth += random.gauss(0, self.noise_std)

        pressure = self.P0 + (self.rho * self.g * depth)

        out = OrcaDepth()
        out.depth = float(depth)
        out.pressure = float(pressure)

        self.pub.publish(out)

        # ✅ PRINT DEPTH (ROS2 logger)
        self.get_logger().info(f"Depth: {depth:.3f} m | Pressure: {pressure:.1f} Pa")


def main():
    rclpy.init()
    node = DepthSim()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()