"""
Joystick — menerima data joystick via TCP dan publish ke /orca/manual/control.

FAILSAFE: Saat koneksi TCP terputus (kabel LAN dicabut, laptop mati, dsb),
node ini langsung publish satu pesan neutral PWM + control_mode = release_mode
agar ControlBridge mendeteksi bahwa sumber manual sudah tidak aktif.
"""

import socket
import rclpy
from rclpy.node import Node
from orca_msgs.msg import OrcaControl

class Joystick(Node):
    def __init__(self):
        super().__init__('joystick')

        self.declare_parameter('tcp_host', '0.0.0.0')
        self.declare_parameter('tcp_port', 5000)
        self.declare_parameter('manual_control_topic', '/orca/manual/control')
        self.declare_parameter('recv_buffer_size', 1024)

        # Failsafe parameters — harus sinkron dengan ControlBridge
        self.declare_parameter('neutral_pwm', 1500)
        self.declare_parameter('release_mode', 'MISSION')   # harus sama dengan manual_release_mode di ControlBridge
        self.declare_parameter('failsafe_repeat', 5)        # kirim neutral N kali saat disconnect untuk keandalan

        self.host             = str(self.get_parameter('tcp_host').value)
        self.port             = int(self.get_parameter('tcp_port').value)
        self.topic_name       = str(self.get_parameter('manual_control_topic').value)
        self.recv_buffer_size = int(self.get_parameter('recv_buffer_size').value)
        self.neutral_pwm      = int(self.get_parameter('neutral_pwm').value)
        self.release_mode     = str(self.get_parameter('release_mode').value)
        self.failsafe_repeat  = int(self.get_parameter('failsafe_repeat').value)

        self.publisher_ = self.create_publisher(OrcaControl, self.topic_name, 10)

        self.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_sock.bind((self.host, self.port))
        self.server_sock.listen(1)
        self.server_sock.setblocking(False)

        self.conn           = None
        self.addr           = None
        self.partial_buffer = ''

        self.get_logger().info(f'Menunggu koneksi joystick TCP di {self.host}:{self.port}')
        self.create_timer(0.02, self.poll_socket)

    # ── Failsafe ─────────────────────────────────────────────────────────────

    def _publish_neutral(self, reason: str = 'disconnect'):
        """
        Publish PWM neutral + release_mode ke topik manual control.

        ControlBridge akan mendeteksi control_mode == release_mode dan
        menganggap sumber manual sudah tidak aktif (manual_is_active() → False).
        Pesan dikirim sebanyak failsafe_repeat kali agar tidak terlewat.
        """
        msg = OrcaControl()
        msg.forward      = self.neutral_pwm
        msg.lateral      = self.neutral_pwm
        msg.throttle     = self.neutral_pwm
        msg.yaw          = self.neutral_pwm
        msg.arm_mode     = ''
        msg.control_mode = self.release_mode    # trigger manual_release_mode check di ControlBridge
        msg.gripper_mode = ''
        msg.source       = f'tcp_failsafe_{reason}'

        for _ in range(self.failsafe_repeat):
            self.publisher_.publish(msg)

        self.get_logger().warn(
            f'[FAILSAFE] Neutral PWM={self.neutral_pwm} dikirim {self.failsafe_repeat}x '
            f'— alasan: {reason}'
        )

    # ── Koneksi ──────────────────────────────────────────────────────────────

    def _close_conn(self, reason: str = 'unknown'):
        """Tutup koneksi aktif dan publish failsafe neutral sebelum reset state."""
        if self.conn is not None:
            # Publish neutral SEBELUM menutup — ini inti failsafe
            self._publish_neutral(reason)
            try:
                self.conn.close()
            except Exception:
                pass

        self.conn           = None
        self.addr           = None
        self.partial_buffer = ''

    # ── Poll loop ────────────────────────────────────────────────────────────

    def poll_socket(self):
        # Coba terima koneksi baru jika belum ada
        if self.conn is None:
            try:
                conn, addr = self.server_sock.accept()
                conn.setblocking(False)
                self.conn           = conn
                self.addr           = addr
                self.partial_buffer = ''
                self.get_logger().info(f'Koneksi joystick diterima dari {addr}')
            except BlockingIOError:
                return
            except Exception as exc:
                self.get_logger().error(f'Gagal menerima koneksi joystick: {exc}')
                return

        # Baca data dari koneksi aktif
        try:
            data = self.conn.recv(self.recv_buffer_size)
            if not data:
                # Koneksi ditutup oleh remote (kabel dicabut / laptop mati)
                self.get_logger().warn('Koneksi joystick TCP terputus (EOF).')
                self._close_conn('tcp_eof')
                return

            self.partial_buffer += data.decode(errors='ignore')
            while '\n' in self.partial_buffer:
                line, self.partial_buffer = self.partial_buffer.split('\n', 1)
                self._parse_and_publish(line.strip())

        except BlockingIOError:
            return
        except ConnectionResetError:
            # TCP RST — biasanya terjadi saat kabel LAN dicabut paksa
            self.get_logger().warn('Koneksi joystick TCP reset (ConnectionResetError).')
            self._close_conn('tcp_reset')
        except OSError as exc:
            self.get_logger().error(f'OSError membaca joystick: {exc}')
            self._close_conn('tcp_oserror')
        except Exception as exc:
            self.get_logger().error(f'Error membaca data joystick: {exc}')
            self._close_conn('tcp_error')

    # ── Parse & publish ──────────────────────────────────────────────────────

    def _parse_and_publish(self, line: str):
        if not line:
            return

        decoded = [item.strip() for item in line.split(',')]
        if len(decoded) != 7:
            self.get_logger().warning(f'Format data joystick salah (expect 7 field): {line}')
            return

        try:
            msg = OrcaControl()
            msg.forward      = int(decoded[0])
            msg.lateral      = int(decoded[1])
            msg.throttle     = int(decoded[2])
            msg.yaw          = int(decoded[3])
            msg.arm_mode     = decoded[4]
            msg.control_mode = decoded[5]
            msg.gripper_mode = decoded[6]
            msg.source       = 'manual_tcp'
            self.publisher_.publish(msg)
        except ValueError as exc:
            self.get_logger().warning(f'Gagal parse data joystick: {exc} | raw={line}')

    # ── Cleanup ──────────────────────────────────────────────────────────────

    def destroy_node(self):
        self._close_conn('node_shutdown')
        try:
            self.server_sock.close()
        except Exception:
            pass
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = Joystick()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()