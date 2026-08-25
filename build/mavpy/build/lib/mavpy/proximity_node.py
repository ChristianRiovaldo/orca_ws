# #!/usr/bin/env python3
# import rclpy
# from orca_msgs.msg import OrcaProximity
# from rclpy.node import Node
# from std_msgs.msg import Empty
# from orca_msgs.msg import OrcaAttitude

# try:
#     import Jetson.GPIO as GPIO
# except Exception:  # pragma: no cover
#     GPIO = None

# class ProximityNode(Node):
#     def __init__(self):
#         super().__init__('proximity_node')
#         self.declare_parameter('pin_sensor', 11)
#         self.declare_parameter('topic_name', '/orca/start_trigger')
#         self.declare_parameter('reset_topic_name', '/orca/proximity/reset_toggle')
#         self.declare_parameter('publish_rate_hz', 10.0)

#         self.pin_sensor = int(self.get_parameter('pin_sensor').value)
#         self.topic_name = self.get_parameter('topic_name').value
#         self.reset_topic_name = self.get_parameter('reset_topic_name').value
#         self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)

#         self.publisher_ = self.create_publisher(OrcaProximity, self.topic_name, 10)
#         self.create_subscription(Empty, self.reset_topic_name, self.reset_toggle_cb, 10)
#         self.create_subscription(OrcaAttitude,  '/orca/sensor/attitude',  self.attitude_cb,  10)

#         self.status = False
#         self.prev_input = False

#         if GPIO is None:
#             self.get_logger().warning('Jetson.GPIO tidak tersedia. Proximity node masuk mode dummy.')
#         else:
#             GPIO.setmode(GPIO.BOARD)
#             GPIO.setup(self.pin_sensor, GPIO.IN)
#             self.prev_input = bool(GPIO.input(self.pin_sensor))
#             self.get_logger().info(
#                 f'Proximity sensor menggunakan pin BOARD {self.pin_sensor}, reset topic: {self.reset_topic_name}'
#             )

#         timer = 1.0 / max(1.0, self.publish_rate_hz)
#         self.create_timer(timer, self.timer_callback)

#     def reset_toggle_cb(self, _msg: Empty):
#         self.status = False
#         self.get_logger().info('Toggle proximity di-reset ke OFF oleh mission node')

#     def timer_callback(self):
#         current_input = False
#         if GPIO is not None:
#             current_input = bool(GPIO.input(self.pin_sensor))

#         if current_input and not self.prev_input:
#             self.status = not self.status
#             self.get_logger().info(f'Proximity toggled -> {"ON" if self.status else "OFF"}')

#         self.prev_input = current_input

#         msg = OrcaProximity()
#         msg.triggered = bool(self.status)
#         self.publisher_.publish(msg)

#     def destroy_node(self):
#         if GPIO is not None:
#             GPIO.cleanup()
#         super().destroy_node()

# def main(args=None):
#     rclpy.init(args=args)
#     node = ProximityNode()
#     try:
#         rclpy.spin(node)
#     except KeyboardInterrupt:
#         pass
#     finally:
#         node.destroy_node()
#         rclpy.shutdown()

#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Empty
from orca_msgs.msg import OrcaAttitude, OrcaProximity

class ProximityNode(Node):
    def __init__(self):
        super().__init__('proximity_node')
        self.declare_parameter('topic_name',       '/orca/start_trigger')
        self.declare_parameter('reset_topic_name', '/orca/proximity/reset_toggle')
        self.declare_parameter('publish_rate_hz',  10.0)
        self.declare_parameter('roll_threshold',   45.0)

        self.topic_name       = self.get_parameter('topic_name').value
        self.reset_topic_name = self.get_parameter('reset_topic_name').value
        self.publish_rate_hz  = float(self.get_parameter('publish_rate_hz').value)
        self.roll_threshold   = float(self.get_parameter('roll_threshold').value)

        self.publisher_ = self.create_publisher(OrcaProximity, self.topic_name, 10)

        self.create_subscription(Empty,       self.reset_topic_name,    self.reset_toggle_cb, 10)
        self.create_subscription(OrcaAttitude,'/orca/sensor/attitude',  self.attitude_cb,     10)

        self.status        = False
        self.roll_high     = False
        self.roll_deg      = 0.0

        timer_period = 1.0 / max(1.0, self.publish_rate_hz)
        self.create_timer(timer_period, self.timer_callback)
        self.get_logger().info(
            f'Proximity node aktif — trigger dari roll >{self.roll_threshold}°'
        )

    def reset_toggle_cb(self, _msg: Empty):
        self.status = False
        self.get_logger().info('Toggle proximity di-reset ke OFF oleh mission node')

    def attitude_cb(self, msg: OrcaAttitude):
        self.roll_deg = msg.roll_deg
        # roll_abs      = abs(self.roll_deg)

        if self.roll_deg > self.roll_threshold and not self.roll_high:
            self.roll_high = True
            self.status    = not self.status
            self.get_logger().info(
                f'Roll {self.roll_deg:.1f}° > {self.roll_threshold}° → '
                f'proximity toggled {"ON" if self.status else "OFF"}'
            )

        elif self.roll_deg <= self.roll_threshold and self.roll_high:
            self.roll_high = False
            self.get_logger().info(
                f'Roll kembali normal ({self.roll_deg:.1f}°) — siap trigger berikutnya'
            )

    def timer_callback(self):
        msg          = OrcaProximity()
        msg.triggered = bool(self.status)
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ProximityNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()