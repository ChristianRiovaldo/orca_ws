#!/usr/bin/env python3
import threading
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from orca_msgs.msg import FlareSequence

VALID_SEQUENCES = {
    'ryb',
    'rby',
    'bry',
    'byr',
    'yrb',
    'ybr'
}

COLOR_LABEL = {
    'r': 'RED',
    'y': 'YELLOW',
    'b': 'BLUE'
}

class CommunicationSim(Node):
    def __init__(self):
        super().__init__('communication_sim')

        self.seq_pub = self.create_publisher(FlareSequence, '/orca/mission/flare_sequence', 10)
        self.status_pub = self.create_publisher(String, '/orca/mission/flare_status', 10)
        self.create_subscription(String, '/orca/mission/flare_ack', self.ack_cb, 10)

        self.current_seq = ''
        self.lock = threading.Lock()
        self.create_timer(0.5, self.publish_seq)

        self.get_logger().info("=" * 50)
        self.get_logger().info("FLARE SEQUENCE COMMUNICATION NODE")
        self.get_logger().info("=" * 50)
        self.get_logger().info(f"Valid sequences: {sorted(VALID_SEQUENCES)}")
        self.get_logger().info("Topic out : /orca/mission/flare_sequence")
        self.get_logger().info("Topic ack : /orca/mission/flare_ack")
        self.get_logger().info("=" * 50)

        self.input_thread = threading.Thread(target=self._input_loop, daemon=True)
        self.input_thread.start()
        self.publish_status("WAITING")

    def _input_loop(self):
        while rclpy.ok():
            try:
                raw = input(
                    "\nMasukkan urutan flare "
                    "(ryb/rby/bry/byr/yrb/ybr): "
                ).strip().lower()
            except EOFError:
                break

            if raw not in VALID_SEQUENCES:
                print(f"[ERROR] '{raw}' tidak valid.")
                continue

            with self.lock:
                self.current_seq = raw

            labels = ' -> '.join(COLOR_LABEL[c] for c in raw)
            print(
                f"[OK] Sequence set: "
                f"{raw.upper()} ({labels})"
            )

            self.get_logger().info(f"Flare sequence set: {raw}")
            self.publish_status(f"SET:{raw}")

    def publish_seq(self):
        with self.lock:
            seq = self.current_seq

        msg = FlareSequence()
        msg.sequence = seq
        self.seq_pub.publish(msg)

    def publish_status(self, status: str):
        msg = String()
        msg.data = status
        self.status_pub.publish(msg)

    def ack_cb(self, msg: String):
        self.get_logger().info(f"ACK dari final_sim: {msg.data}")
        self.publish_status(f"ACK:{msg.data}")

def main(args=None):
    rclpy.init(args=args)
    node = CommunicationSim()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()