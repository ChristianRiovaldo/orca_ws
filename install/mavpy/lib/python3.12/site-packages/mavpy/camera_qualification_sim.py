#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from orca_msgs.msg import GateDetection

ORANGE_LOW = np.array([0, 100, 100])
ORANGE_HIGH = np.array([30, 255, 255])
DARK_LOW = np.array([0, 0, 0])
DARK_HIGH = np.array([180, 80, 60])
MIN_POST_AREA = 80
MIN_BAR_AREA = 50
POST_ASPECT_MIN = 1.5
BAR_ASPECT_MAX = 0.8
POST_HEIGHT_RATIO = 0.40
POST_TOP_DIFF_FRAC = 0.60
GAP_MIN_PX = 30
GAP_MAX_FRAC = 0.92
BAR_OVERLAP_MIN = 0.35
BAR_Y_MAX_FRAC = 0.40

class CameraQualificationSim(Node):
    def __init__(self):
        super().__init__('camera_qualification_sim')
        self.bridge = CvBridge()
        self.sub = self.create_subscription(Image, '/camera/image_raw', self.image_callback, 10)
        self.pub = self.create_publisher(GateDetection, '/orca/perception/gate', 10)
        self.get_logger().info("Camera Qualification SIM Node Started")

    def segment(self, hsv):
        k = np.ones((5, 5), np.uint8)

        mask_orange = cv2.inRange(hsv, ORANGE_LOW, ORANGE_HIGH)
        mask_orange = cv2.morphologyEx(mask_orange, cv2.MORPH_CLOSE, k)
        mask_orange = cv2.morphologyEx(mask_orange, cv2.MORPH_OPEN,  k)

        mask_dark = cv2.inRange(hsv, DARK_LOW, DARK_HIGH)
        mask_dark = cv2.morphologyEx(mask_dark, cv2.MORPH_CLOSE, k)
        mask_dark = cv2.morphologyEx(mask_dark, cv2.MORPH_OPEN,  k)

        return mask_orange, mask_dark

    def extract_posts(self, mask_orange):
        contours, _ = cv2.findContours(mask_orange, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        posts = []
        for c in contours:
            area = cv2.contourArea(c)
            if area < MIN_POST_AREA:
                continue
            x, y, w, h = cv2.boundingRect(c)
            if w == 0:
                continue
            aspect = h / float(w)
            if aspect >= POST_ASPECT_MIN:
                posts.append({
                    'x': x, 'y': y, 'w': w, 'h': h,
                    'area': area,
                    'cx': x + w / 2.0,
                    'cy': y + h / 2.0,
                })
        return posts

    def extract_bars(self, mask_dark):
        contours, _ = cv2.findContours(mask_dark, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        bars = []
        for c in contours:
            area = cv2.contourArea(c)
            if area < MIN_BAR_AREA:
                continue
            x, y, w, h = cv2.boundingRect(c)
            if h == 0:
                continue
            aspect = h / float(w)
            if aspect <= BAR_ASPECT_MAX:
                bars.append({
                    'x': x, 'y': y, 'w': w, 'h': h,
                    'area': area,
                    'cx': x + w / 2.0,
                    'cy': y + h / 2.0,
                })
        return bars

    def match_gate(self, posts, bars, frame_w, frame_h):
        if len(posts) < 2 or len(bars) < 1:
            return None

        posts = sorted(posts, key=lambda b: b['area'], reverse=True)[:6]

        best_gate  = None
        best_score = -1

        for i in range(len(posts)):
            for j in range(i + 1, len(posts)):
                left  = posts[i] if posts[i]['cx'] <= posts[j]['cx'] else posts[j]
                right = posts[i] if posts[i]['cx'] >  posts[j]['cx'] else posts[j]

                gap = right['cx'] - left['cx']
                if gap < GAP_MIN_PX:
                    continue
                if gap > frame_w * GAP_MAX_FRAC:
                    continue

                h_ratio = (min(left['h'], right['h']) / max(left['h'], right['h']))
                if h_ratio < POST_HEIGHT_RATIO:
                    continue

                top_diff = abs(left['y'] - right['y'])
                if top_diff > max(left['h'], right['h']) * POST_TOP_DIFF_FRAC:
                    continue

                gate_top = min(left['y'], right['y'])
                gate_bottom = max(left['y'] + left['h'], right['y'] + right['h'])
                gate_left = left['x']
                gate_right = right['x'] + right['w']
                gate_width = gate_right - gate_left
                gate_height = gate_bottom - gate_top

                matched_bar = None
                for bar in bars:
                    bar_y_ok = bar['cy'] < (gate_top + gate_height * BAR_Y_MAX_FRAC)
                    overlap_left = max(bar['x'], gate_left)
                    overlap_right = min(bar['x'] + bar['w'], gate_right)
                    overlap_w = overlap_right - overlap_left
                    bar_x_ok = overlap_w >= gate_width * BAR_OVERLAP_MIN

                    if bar_y_ok and bar_x_ok:
                        matched_bar = bar
                        break

                if matched_bar is None:
                    continue

                area_ratio = (gate_width * gate_height) / (frame_w * frame_h)
                score = h_ratio * 0.5 + area_ratio * 0.5

                if score > best_score:
                    best_score = score
                    best_gate = {
                        'x_min': gate_left,
                        'y_min': gate_top,
                        'x_max': gate_right,
                        'y_max': gate_bottom,
                        'left_post': left,
                        'right_post': right,
                        'top_bar': matched_bar,
                        'score': score,
                        'confidence': 1.0,
                    }

        return best_gate

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        h, w, _ = frame.shape
        frame_cx = w / 2.0
        frame_cy = h / 2.0

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        mask_orange, mask_dark = self.segment(hsv)
        posts = self.extract_posts(mask_orange)
        bars = self.extract_bars(mask_dark)
        gate = self.match_gate(posts, bars, w, h)

        msg_out = GateDetection()
        msg_out.detected = False
        msg_out.class_name = "gate"
        msg_out.distance = 0.0

        if gate is not None:
            x_min, y_min = gate['x_min'], gate['y_min']
            x_max, y_max = gate['x_max'], gate['y_max']
            bbox_w = x_max - x_min
            bbox_h = y_max - y_min
            gate_cx = x_min + bbox_w / 2.0
            gate_cy = y_min + bbox_h / 2.0

            dx = gate_cx - frame_cx
            dy = gate_cy - frame_cy
            pixel_distance = float(np.sqrt(dx**2 + dy**2))
            frame_diagonal = float(np.sqrt(w**2 + h**2))
            distance_norm = pixel_distance / frame_diagonal
            center_x_norm = dx / (w / 2.0)
            area_ratio = (bbox_w * bbox_h) / (w * h)

            msg_out.detected = True
            msg_out.confidence = float(gate['confidence'])
            msg_out.center_x = float(gate_cx)
            msg_out.center_y = float(gate_cy)
            msg_out.center_x_norm = float(center_x_norm)
            msg_out.bbox_width = float(bbox_w)
            msg_out.bbox_height = float(bbox_h)
            msg_out.bbox_area_ratio = float(area_ratio)
            msg_out.distance = float(distance_norm)

            cv2.rectangle(frame, (int(x_min), int(y_min)), (int(x_max), int(y_max)), (0, 255, 0), 3)
            cv2.circle(frame, (int(gate_cx), int(gate_cy)), 7, (0, 0, 255), -1)
            cv2.circle(frame, (int(frame_cx), int(frame_cy)), 7, (0, 255, 255), -1)
            cv2.line(frame, (int(frame_cx), int(frame_cy)), (int(gate_cx), int(gate_cy)), (255, 255, 255), 2)

            cv2.putText(frame, "GATE DETECTED", (10, 28), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
            cv2.putText(frame, f"dx={dx:+.1f}  dy={dy:+.1f}", (10, 55), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 2)
            cv2.putText(frame, f"dist={distance_norm:.3f} conf={gate['confidence']:.2f}", (10, 80), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 2)

            self.get_logger().info(f"[GATE] dx={dx:+.1f} dy={dy:+.1f}" f"dist={distance_norm:.3f} conf={gate['confidence']:.2f}")

        else:
            n_posts = len(posts)
            n_bars  = len(bars)

            for p in posts:
                cv2.rectangle(frame, (p['x'], p['y']), (p['x'] + p['w'], p['y'] + p['h']), (0, 80, 200), 1)
            
            for b in bars:
                cv2.rectangle(frame, (b['x'], b['y']), (b['x'] + b['w'], b['y'] + b['h']), (80, 80, 0), 1)

            missing = []
            if n_posts < 2:
                missing.append(f"posts:{n_posts}/2")
            if n_bars < 1:
                missing.append("bar:0/1")
            if n_posts >= 2 and n_bars >= 1:
                missing.append("geometry mismatch")

            cv2.putText(frame, "GATE NOT DETECTED", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
            self.get_logger().warn(f"Gate NOT detected")

        self.pub.publish(msg_out)
        cv2.imshow("SIM Gate Detection", frame)
        # cv2.imshow("mask_orange", mask_orange)
        # cv2.imshow("mask_dark",   mask_dark)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = CameraQualificationSim()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()