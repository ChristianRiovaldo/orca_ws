#!/usr/bin/env python3
import pygame
import rclpy
from rclpy.node import Node
from orca_msgs.msg import OrcaControl


class ROVTeleop(Node):
    def __init__(self):
        super().__init__('orca_keyboard_node')
        self.declare_parameter('manual_control_topic', '/orca/manual/control')
        self.declare_parameter('keyboard_publish_hz', 20.0)
        self.declare_parameter('keyboard_step_pwm', 10)
        self.declare_parameter('keyboard_pwm_min', 1160)
        self.declare_parameter('keyboard_pwm_max', 1840)
        self.declare_parameter('window_size', 120)

        self.topic_name = str(self.get_parameter('manual_control_topic').value)
        self.publish_hz = float(self.get_parameter('keyboard_publish_hz').value)
        self.step_pwm = int(self.get_parameter('keyboard_step_pwm').value)
        self.pwm_min = int(self.get_parameter('keyboard_pwm_min').value)
        self.pwm_max = int(self.get_parameter('keyboard_pwm_max').value)
        self.window_size = int(self.get_parameter('window_size').value)

        pygame.init()
        self.screen = pygame.display.set_mode((self.window_size, self.window_size))
        pygame.display.set_caption('ORCA Keyboard Control')

        self.publisher_ = self.create_publisher(OrcaControl, self.topic_name, 10)
        self.get_logger().info(
            'Keyboard aktif.\n'
            '- W/S: Forward/Backward\n'
            '- A/D: Lateral Left/Right\n'
            '- Panah Kiri/Kanan: Yaw Left/Right\n'
            '- Panah Atas/Bawah: Throttle Up/Down\n'
            '- T/G: Pitch Up/Down\n'
            '- F/H: Roll Left/Right\n'
            '- 1: Open Left, 2: Close, 3: Open Right (Gripper)\n'
            '- J: Toggle Arm/Disarm\n'
            '- K: Toggle Mode'
        )

        self.axis_pwm = {
            'pitch': 1500,
            'roll': 1500,
            'forward': 1500,
            'lateral': 1500,
            'yaw': 1500,
            'throttle': 1500
        }
        self.axis_dir = {
            'pitch': 0,
            'roll': 0,
            'forward': 0,
            'lateral': 0,
            'yaw': 0,
            'throttle': 0
        }
        self.arm_toggle = 'disarm'
        self.control_modes = ['MANUAL', 'ALT_HOLD']
        self.control_mode_idx = 0

        self.gripper_states = ['open_right', 'close', 'open_left']
        self.gripper_idx = 1
        self.create_timer(1.0 / max(1.0, self.publish_hz), self.key_callback)

    def key_callback(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                raise KeyboardInterrupt
            if event.type == pygame.KEYDOWN:
                # Gripper control
                if event.key == pygame.K_1 or event.key == pygame.K_KP1:
                    self.gripper_idx = 2  # open_left
                elif event.key == pygame.K_2 or event.key == pygame.K_KP2:
                    self.gripper_idx = 1  # close
                elif event.key == pygame.K_3 or event.key == pygame.K_KP3:
                    self.gripper_idx = 0  # open_right

                # System toggles
                elif event.key == pygame.K_j:
                    self.arm_toggle = 'arm' if self.arm_toggle == 'disarm' else 'disarm'
                elif event.key == pygame.K_k:
                    self.control_mode_idx = (self.control_mode_idx + 1) % len(self.control_modes)

                # Movement - Forward/Backward
                elif event.key == pygame.K_w:
                    self.axis_dir['forward'] = 1
                elif event.key == pygame.K_s:
                    self.axis_dir['forward'] = -1

                # Movement - Lateral
                elif event.key == pygame.K_d:
                    self.axis_dir['lateral'] = 1
                elif event.key == pygame.K_a:
                    self.axis_dir['lateral'] = -1

                # Movement - Yaw
                elif event.key == pygame.K_RIGHT:
                    self.axis_dir['yaw'] = 1
                elif event.key == pygame.K_LEFT:
                    self.axis_dir['yaw'] = -1

                # Movement - Throttle
                elif event.key == pygame.K_UP:
                    self.axis_dir['throttle'] = 1
                elif event.key == pygame.K_DOWN:
                    self.axis_dir['throttle'] = -1

                # Movement - Pitch
                elif event.key == pygame.K_t:
                    self.axis_dir['pitch'] = 1
                elif event.key == pygame.K_g:
                    self.axis_dir['pitch'] = -1

                # Movement - Roll
                elif event.key == pygame.K_h:
                    self.axis_dir['roll'] = 1
                elif event.key == pygame.K_f:
                    self.axis_dir['roll'] = -1

            elif event.type == pygame.KEYUP:
                if event.key in [pygame.K_w, pygame.K_s]:
                    self.axis_dir['forward'] = 0
                elif event.key in [pygame.K_a, pygame.K_d]:
                    self.axis_dir['lateral'] = 0
                elif event.key in [pygame.K_LEFT, pygame.K_RIGHT]:
                    self.axis_dir['yaw'] = 0
                elif event.key in [pygame.K_UP, pygame.K_DOWN]:
                    self.axis_dir['throttle'] = 0
                elif event.key in [pygame.K_t, pygame.K_g]:
                    self.axis_dir['pitch'] = 0
                elif event.key in [pygame.K_f, pygame.K_h]:
                    self.axis_dir['roll'] = 0

        self.update_axis_pwm()

        msg = OrcaControl()
        msg.pitch = self.axis_pwm['pitch']
        msg.roll = self.axis_pwm['roll']
        msg.forward = self.axis_pwm['forward']
        msg.lateral = self.axis_pwm['lateral']
        msg.yaw = self.axis_pwm['yaw']
        msg.throttle = self.axis_pwm['throttle']
        msg.arm_mode = self.arm_toggle
        msg.control_mode = self.control_modes[self.control_mode_idx]
        msg.gripper_mode = self.gripper_states[self.gripper_idx]
        msg.source = 'manual_keyboard'
        self.publisher_.publish(msg)

    def update_axis_pwm(self):
        for axis in self.axis_pwm:
            direction = self.axis_dir[axis]
            if direction == 1:
                self.axis_pwm[axis] += self.step_pwm
            elif direction == -1:
                self.axis_pwm[axis] -= self.step_pwm
            else:
                if self.axis_pwm[axis] > 1500:
                    self.axis_pwm[axis] -= self.step_pwm
                elif self.axis_pwm[axis] < 1500:
                    self.axis_pwm[axis] += self.step_pwm
            self.axis_pwm[axis] = max(self.pwm_min, min(self.pwm_max, self.axis_pwm[axis]))

    def destroy_node(self):
        pygame.quit()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ROVTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()