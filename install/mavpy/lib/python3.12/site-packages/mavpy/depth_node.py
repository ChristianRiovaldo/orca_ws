#!/usr/bin/env python3
import rclpy
from orca_msgs.msg import OrcaDepth
from pymavlink import mavutil
from rclpy.node import Node

class DepthNode(Node):
    def __init__(self):
        super().__init__('depth_node')
        self.declare_parameter('mavlink_url', 'udpin:0.0.0.0:14552')
        self.declare_parameter('pressure_offset_mbar', 89.35)
        self.declare_parameter('topic_name', '/orca/sensor/depth')

        self.mavlink_url = self.get_parameter('mavlink_url').value
        self.pressure_offset = float(self.get_parameter('pressure_offset_mbar').value)
        topic_name = self.get_parameter('topic_name').value

        self.publisher_ = self.create_publisher(OrcaDepth, topic_name, 10)
        self.master = mavutil.mavlink_connection(self.mavlink_url)
        self.master.wait_heartbeat()
        self.get_logger().info(f'Pixhawk depth stream connected via {self.mavlink_url}')

        self.create_timer(0.1, self.publish_depth)

    def publish_depth(self):
        latest_msg = None
        while True:
            msg = self.master.recv_match(type='SCALED_PRESSURE2', blocking=False)
            if msg is None:
                break
            latest_msg = msg

        if latest_msg is None:
            return

        pressure_mbar = float(latest_msg.press_abs + self.pressure_offset)
        depth_m = float((pressure_mbar - 1013.25) / 100.0)

        out = OrcaDepth()
        out.depth = depth_m
        out.pressure = pressure_mbar
        self.publisher_.publish(out)

def main(args=None):
    rclpy.init(args=args)
    node = DepthNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()