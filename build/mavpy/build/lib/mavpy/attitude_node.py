#!/usr/bin/env python3
import math
import rclpy
from orca_msgs.msg import OrcaAttitude
from pymavlink import mavutil
from rclpy.node import Node

class AttitudeNode(Node):
    def __init__(self):
        super().__init__('attitude_node')
        self.declare_parameter('mavlink_url', 'udpin:0.0.0.0:14553')
        self.declare_parameter('topic_name', '/orca/sensor/attitude')

        self.mavlink_url = self.get_parameter('mavlink_url').value
        topic_name = self.get_parameter('topic_name').value

        self.publisher_ = self.create_publisher(OrcaAttitude, topic_name, 10)
        self.master = mavutil.mavlink_connection(self.mavlink_url)
        self.master.wait_heartbeat()
        self.get_logger().info(f'Pixhawk attitude stream connected via {self.mavlink_url}')

        self.master.mav.request_data_stream_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_DATA_STREAM_EXTRA1,
            50,
            1,
        )

        self.master.mav.request_data_stream_send(
            self.master.target_system,
            self.master.target_component,
            mavutil.mavlink.MAV_DATA_STREAM_POSITION,
            50,
            1,
        )

        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.initial_x = None
        self.initial_y = None
        self.initial_z = None
        self.initial_heading = None

        self.last_log_time = 0.0
        self.create_timer(0.02, self.poll_mavlink)

    @staticmethod
    def wrap_angle_deg(angle):
        return (angle + 180) % 360 - 180

    def poll_mavlink(self):
        while True:
            msg = self.master.recv_match(type=['ATTITUDE', 'LOCAL_POSITION_NED'], blocking=False)
            if msg is None:
                break

            # Akses koordinat x, y, z secara lokal
            msg_type = msg.get_type()
            if msg_type == 'LOCAL_POSITION_NED':
                self.x = float(msg.x)
                self.y = float(msg.y)
                self.z = float(msg.z)
                if self.initial_x is None:
                    self.initial_x = self.x
                    self.initial_y = self.y
                    self.initial_z = self.z
                continue

            dx = self.x - self.initial_x if self.initial_x is not None else 0.0
            dy = self.y - self.initial_y if self.initial_y is not None else 0.0
            dz = self.z - self.initial_z if self.initial_z is not None else 0.0

            # Akses attitude
            raw_yaw = float(math.degrees(msg.yaw))
            if self.initial_heading is None:
                self.initial_heading = raw_yaw

            relative_yaw = raw_yaw - self.initial_heading
            relative_yaw = self.wrap_angle_deg(relative_yaw)

            out = OrcaAttitude()

            out.initial_x = dx
            out.initial_y = dy
            out.initial_z = dz
            
            out.yaw_deg = raw_yaw
            out.initial_deg = relative_yaw

            out.roll_deg = float(math.degrees(msg.roll))
            out.pitch_deg = float(math.degrees(msg.pitch))
            out.rollspeed_deg_s = float(math.degrees(msg.rollspeed))
            out.pitchspeed_deg_s = float(math.degrees(msg.pitchspeed))
            out.yawspeed_deg_s = float(math.degrees(msg.yawspeed))

            self.publisher_.publish(out)

            now = self.get_clock().now().nanoseconds * 1e-9
            if now - self.last_log_time > 1.0:
                self.get_logger().info(
                    f"Yaw: {out.yaw_deg:.2f} deg | "
                    f"Initial: {out.initial_deg:.2f} deg | "
                    f"X: {dx:.2f} | "
                    f"Y: {dy:.2f} | "
                    f"Z: {dz:.2f}"
                )
                self.last_log_time = now

def main(args=None):
    rclpy.init(args=args)
    node = AttitudeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()