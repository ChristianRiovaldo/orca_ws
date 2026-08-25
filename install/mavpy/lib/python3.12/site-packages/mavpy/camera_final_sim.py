import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from orca_msgs.msg import GateDetection

class CameraFinalSim(Node):
    def __init__(self):
        super().__init__('camera_final_sim')

        self.bridge = CvBridge()
        self.sub = self.create_subscription(Image, '/camera/image_raw', self.image_callback, 10)

        self.pub_obstacle = self.create_publisher(GateDetection, '/orca/perception/orange_flare', 10)
        self.pub_gate = self.create_publisher(GateDetection, '/orca/perception/gate_final', 10)
        self.pub_red_flare = self.create_publisher(GateDetection, '/orca/perception/red_flare', 10)
        self.pub_yellow_flare = self.create_publisher(GateDetection, '/orca/perception/yellow_flare', 10)
        self.pub_blue_flare = self.create_publisher(GateDetection, '/orca/perception/blue_flare', 10)
        self.pub_bucket_blue = self.create_publisher(GateDetection, '/orca/perception/bucket_blue', 10)

        self.OBS_LO = np.array([5, 100, 100])
        self.OBS_HI = np.array([25, 255, 255])

        self.GATE_R1_LO = np.array([0, 120, 40])
        self.GATE_R1_HI = np.array([12, 255, 210])
        self.GATE_R2_LO = np.array([155, 120, 40])
        self.GATE_R2_HI = np.array([180, 255, 210])

        self.GATE_G_LO = np.array([40, 120, 40])
        self.GATE_G_HI = np.array([80, 255, 220])

        self.RED_FL1_LO = np.array([0, 150, 150])
        self.RED_FL1_HI = np.array([12, 255, 255])
        self.RED_FL2_LO = np.array([155, 150, 150])
        self.RED_FL2_HI = np.array([180, 255, 255])

        self.YEL_LO = np.array([15, 100, 100])
        self.YEL_HI = np.array([35, 255, 255])

        self.BLU_FL_LO = np.array([85, 100, 150])
        self.BLU_FL_HI = np.array([125, 255, 255])

        self.BKT_LO = np.array([95, 120, 30])
        self.BKT_HI = np.array([130, 255, 180])

        self.get_logger().info("Camera Final SIM Node Started")

    def _empty_msg(self, class_name):
        msg = GateDetection()
        msg.detected = False
        msg.class_name = class_name
        msg.confidence = 0.0
        msg.center_x = 0.0
        msg.center_y = 0.0
        msg.center_x_norm = 0.0
        msg.bbox_width = 0.0
        msg.bbox_height = 0.0
        msg.bbox_area_ratio = 0.0
        msg.distance = 0.0
        return msg

    def _fill_msg(self, msg, box, frame_w, frame_h):
        fx, fy, fw, fh = box['x'], box['y'], box['w'], box['h']
        frame_cx = frame_w / 2.0
        frame_cy = frame_h / 2.0
        cx = fx + fw / 2.0
        cy = fy + fh / 2.0
        dx = cx - frame_cx
        dy = cy - frame_cy
        msg.detected = True
        msg.confidence = 1.0
        msg.center_x = float(cx)
        msg.center_y = float(cy)
        msg.center_x_norm = float(dx / (frame_w / 2.0))
        msg.bbox_width = float(fw)
        msg.bbox_height = float(fh)
        msg.bbox_area_ratio = float((fw * fh) / (frame_w * frame_h))
        msg.distance = float(np.sqrt(dx**2 + dy**2) / np.sqrt(frame_w**2 + frame_h**2))
        return msg, (int(cx), int(cy)), (int(dx), int(dy))

    def _clean(self, mask, k=5):
        kernel = np.ones((k, k), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN,  kernel)
        return mask

    def _dilate_mask(self, mask, px=20):
        kernel = np.ones((px, px), np.uint8)
        return cv2.dilate(mask, kernel, iterations=2)

    def _exclude(self, mask, *exclude_masks):
        result = mask.copy()
        for ex in exclude_masks:
            if ex is not None:
                result = cv2.bitwise_and(result, cv2.bitwise_not(self._dilate_mask(ex)))
        return result

    def _merge(self, mask):
        kernel = np.ones((7, 7), np.uint8)
        merged = cv2.dilate(mask, kernel, iterations=3)
        merged = cv2.erode(merged,  kernel, iterations=3)
        return merged
    
    def _best_vertical(self, mask, min_area=50):
        merged = self._merge(mask)
        cnts, _ = cv2.findContours(merged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        best = None
        best_area = 0
        for c in cnts:
            area = cv2.contourArea(c)
            if area < min_area:
                continue
            x, y, w, h = cv2.boundingRect(cv2.convexHull(c))
            if h > w and area > best_area:
                best_area = area
                best = {'x': x, 'y': y, 'w': w, 'h': h, 'area': area}
        return best

    def _best_blob(self, mask, min_area=100):
        merged = self._merge(mask)
        cnts, _ = cv2.findContours(merged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        best = None
        best_area = 0
        for c in cnts:
            area = cv2.contourArea(c)
            if area < min_area:
                continue
            x, y, w, h = cv2.boundingRect(cv2.convexHull(c))
            if area > best_area:
                best_area = area
                best = {'x': x, 'y': y, 'w': w, 'h': h, 'area': area}
        return best

    def _top_n_vertical(self, mask, n, min_area=50):
        merged = self._merge(mask)
        cnts, _ = cv2.findContours(merged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        boxes = []
        for c in cnts:
            area = cv2.contourArea(c)
            if area < min_area:
                continue
            x, y, w, h = cv2.boundingRect(cv2.convexHull(c))
            if h > w:
                boxes.append({'x': x, 'y': y, 'w': w, 'h': h, 'area': area})
        boxes = sorted(boxes, key=lambda b: b['area'], reverse=True)[:n]
        boxes = sorted(boxes, key=lambda b: b['y'])
        return boxes

    def _raw_obstacle(self, hsv):
        m = cv2.inRange(hsv, self.OBS_LO, self.OBS_HI)
        return self._clean(m)

    def _raw_gate_red(self, hsv):
        m1 = cv2.inRange(hsv, self.GATE_R1_LO, self.GATE_R1_HI)
        m2 = cv2.inRange(hsv, self.GATE_R2_LO, self.GATE_R2_HI)
        return self._clean(cv2.bitwise_or(m1, m2))

    def _raw_gate_green(self, hsv):
        m = cv2.inRange(hsv, self.GATE_G_LO, self.GATE_G_HI)
        return self._clean(m)

    def _raw_red_flare(self, hsv):
        m1 = cv2.inRange(hsv, self.RED_FL1_LO, self.RED_FL1_HI)
        m2 = cv2.inRange(hsv, self.RED_FL2_LO, self.RED_FL2_HI)
        return self._clean(cv2.bitwise_or(m1, m2))

    def _raw_yellow_flare(self, hsv):
        m = cv2.inRange(hsv, self.YEL_LO, self.YEL_HI)
        return self._clean(m)

    def _raw_blue_flare(self, hsv):
        m = cv2.inRange(hsv, self.BLU_FL_LO, self.BLU_FL_HI)
        return self._clean(m)

    def _raw_bucket_blue(self, hsv):
        m = cv2.inRange(hsv, self.BKT_LO, self.BKT_HI)
        return self._clean(m)

    def detect_gate_final(self, hsv):
        mask_red = self._raw_gate_red(hsv)
        mask_green = self._raw_gate_green(hsv)

        segs_red = self._top_n_vertical(mask_red, 3)
        segs_green = self._top_n_vertical(mask_green, 3)

        mask_vis = cv2.bitwise_or(mask_red, mask_green)

        if len(segs_red) != 3 or len(segs_green) != 3:
            self.get_logger().debug(f"[GATE] kurang: red={len(segs_red)}/3 green={len(segs_green)}/3")
            return None, mask_vis, mask_red, mask_green

        return {'segs_red': segs_red, 'segs_green': segs_green}, mask_vis, mask_red, mask_green

    def _build_gate_msg(self, gate_result, frame_w, frame_h):
        msg = self._empty_msg("gate_final")
        if gate_result is None:
            return msg

        all_boxes = gate_result['segs_red'] + gate_result['segs_green']
        frame_cx = frame_w / 2.0
        frame_cy = frame_h / 2.0

        x_min = min(b['x'] for b in all_boxes)
        y_min = min(b['y'] for b in all_boxes)
        x_max = max(b['x'] + b['w'] for b in all_boxes)
        y_max = max(b['y'] + b['h'] for b in all_boxes)

        bbox_w = x_max - x_min
        bbox_h = y_max - y_min
        cx = x_min + bbox_w / 2.0
        cy = y_min + bbox_h / 2.0
        dx = cx - frame_cx
        dy = cy - frame_cy

        msg.detected = True
        msg.confidence = 1.0
        msg.center_x = float(cx)
        msg.center_y = float(cy)
        msg.center_x_norm = float(dx / (frame_w / 2.0))
        msg.bbox_width = float(bbox_w)
        msg.bbox_height = float(bbox_h)
        msg.bbox_area_ratio = float((bbox_w * bbox_h) / (frame_w * frame_h))
        msg.distance = float(np.sqrt(dx**2 + dy**2) / np.sqrt(frame_w**2 + frame_h**2))
        return msg

    def detect_obstacle(self, hsv):
        mask = self._raw_obstacle(hsv)
        return self._best_vertical(mask), mask

    def detect_bucket_blue(self, hsv):
        mask = self._raw_bucket_blue(hsv)
        return self._best_blob(mask), mask

    def detect_red_flare(self, hsv, mask_gate_red=None, mask_obs=None):
        mask = self._raw_red_flare(hsv)
        mask = self._exclude(mask, mask_gate_red, mask_obs)
        return self._best_vertical(mask), mask

    def detect_yellow_flare(self, hsv, mask_obs=None):
        mask = self._raw_yellow_flare(hsv)
        mask = self._exclude(mask, mask_obs)
        return self._best_vertical(mask), mask

    def detect_blue_flare(self, hsv, mask_bkt=None):
        mask = self._raw_blue_flare(hsv)
        mask = self._exclude(mask, mask_bkt)
        return self._best_vertical(mask), mask

    def _annotate_flare(self, frame, box, frame_cx, frame_cy, color, label):
        fx, fy, fw, fh = box['x'], box['y'], box['w'], box['h']
        cx = int(fx + fw / 2.0)
        cy = int(fy + fh / 2.0)
        dx = cx - int(frame_cx)
        area_r = (fw * fh) / (frame.shape[1] * frame.shape[0])
        cv2.rectangle(frame, (fx, fy), (fx + fw, fy + fh), color, 2)
        cv2.circle(frame, (cx, cy), 5, (0, 0, 255), -1)
        cv2.line(frame, (int(frame_cx), int(frame_cy)), (cx, cy), (255, 255, 255), 1)
        cv2.putText(frame,
                    f"{label} dx={dx:+.0f} area={area_r:.4f}",
                    (fx, max(fy - 6, 12)),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.45, color, 1)

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        h, w, _ = frame.shape

        frame_cx = w / 2.0
        frame_cy = h / 2.0

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        cv2.circle(frame, (int(frame_cx), int(frame_cy)), 6, (0, 255, 255), -1)

        # ─────────────────────────────────────────────────
        # 1. GATE FINAL
        # ─────────────────────────────────────────────────
        gate_result, _, mask_gate_red, mask_gate_green = self.detect_gate_final(hsv)
        msg_gate = self._build_gate_msg(gate_result, w, h)

        if gate_result is not None:
            all_boxes = gate_result['segs_red'] + gate_result['segs_green']
            for b in gate_result['segs_red']:
                cv2.rectangle(frame,
                              (b['x'], b['y']), (b['x'] + b['w'], b['y'] + b['h']),
                              (0, 0, 200), 1)
            for b in gate_result['segs_green']:
                cv2.rectangle(frame,
                              (b['x'], b['y']), (b['x'] + b['w'], b['y'] + b['h']),
                              (0, 200, 0), 1)
            gx_min = min(b['x'] for b in all_boxes)
            gy_min = min(b['y'] for b in all_boxes)
            gx_max = max(b['x'] + b['w'] for b in all_boxes)
            gy_max = max(b['y'] + b['h'] for b in all_boxes)
            cv2.rectangle(frame, (int(gx_min), int(gy_min)), (int(gx_max), int(gy_max)), (0, 255, 0), 3)
            cv2.circle(frame, (int(msg_gate.center_x), int(msg_gate.center_y)), 6, (0, 0, 255), -1)
            cv2.line(frame,
                     (int(frame_cx), int(frame_cy)),
                     (int(msg_gate.center_x), int(msg_gate.center_y)),
                     (255, 255, 255), 2)
            cv2.putText(frame,
                        f"[GATE] cx_norm={msg_gate.center_x_norm:+.2f} dist={msg_gate.distance:.3f}",
                        (10, 105), cv2.FONT_HERSHEY_SIMPLEX, 0.55, (0, 255, 0), 2)
            self.get_logger().info(f"[GATE] cx_norm={msg_gate.center_x_norm:.3f} dist={msg_gate.distance:.3f}")
        else:
            cv2.putText(frame, "Gate NOT detected", (10, 105), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)

        # ─────────────────────────────────────────────────
        # 2. OBSTACLE
        # ─────────────────────────────────────────────────
        orange_box, mask_obs = self.detect_obstacle(hsv)
        msg_obstacle = self._empty_msg("orange_flare")

        if orange_box is not None:
            msg_obstacle, _, _ = self._fill_msg(msg_obstacle, orange_box, w, h)
            self._annotate_flare(frame, orange_box, frame_cx, frame_cy, (0, 165, 255), "[OBS]")
            self.get_logger().info(f"[OBSTACLE] cx_norm={msg_obstacle.center_x_norm:+.2f} dist={msg_obstacle.distance:.3f}")
        else:
            cv2.putText(frame, "Obstacle NOT detected", (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 165, 255), 1)

        # ─────────────────────────────────────────────────
        # 3. BUCKET BLUE
        # ─────────────────────────────────────────────────
        bucket_box, mask_bkt = self.detect_bucket_blue(hsv)
        msg_bucket = self._empty_msg("bucket_blue")

        if bucket_box is not None:
            msg_bucket, _, _ = self._fill_msg(msg_bucket, bucket_box, w, h)
            bx, by, bw, bh   = bucket_box['x'], bucket_box['y'], bucket_box['w'], bucket_box['h']
            bcx = int(bx + bw / 2.0)
            bcy = int(by + bh / 2.0)
            cv2.rectangle(frame, (bx, by), (bx + bw, by + bh), (255, 180, 0), 3)
            cv2.circle(frame, (bcx, bcy), 6, (0, 255, 255), -1)
            cv2.line(frame, (int(frame_cx), int(frame_cy)), (bcx, bcy), (255, 255, 255), 1)
            cv2.putText(frame,
                        f"[BUCKET] cx_norm={msg_bucket.center_x_norm:+.2f} "
                        f"area={msg_bucket.bbox_area_ratio:.4f}",
                        (bx, max(by - 6, 12)),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 180, 0), 2)
            self.get_logger().info(
                f"[BUCKET_BLUE] cx_norm={msg_bucket.center_x_norm:+.2f} "
                f"area={msg_bucket.bbox_area_ratio:.4f}")
        else:
            cv2.putText(frame, "Bucket Blue NOT detected", (10, 125), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 180, 0), 1)

        # ─────────────────────────────────────────────────
        # 4. RED FLARE
        # ─────────────────────────────────────────────────
        red_box, _ = self.detect_red_flare(hsv, mask_gate_red=mask_gate_red, mask_obs=mask_obs)
        msg_red = self._empty_msg("red_flare")

        if red_box is not None:
            msg_red, _, _ = self._fill_msg(msg_red, red_box, w, h)
            self._annotate_flare(frame, red_box, frame_cx, frame_cy, (0, 0, 220), "[RED]")
            self.get_logger().info(f"[RED] cx_norm={msg_red.center_x_norm:+.2f} dist={msg_red.distance:.3f}")
        else:
            cv2.putText(frame, "Red Flare NOT detected", (10, 45), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 220), 1)

        # ─────────────────────────────────────────────────
        # 5. YELLOW FLARE
        # ─────────────────────────────────────────────────
        yellow_box, _ = self.detect_yellow_flare(hsv, mask_obs=mask_obs)
        msg_yellow = self._empty_msg("yellow_flare")

        if yellow_box is not None:
            msg_yellow, _, _ = self._fill_msg(msg_yellow, yellow_box, w, h)
            self._annotate_flare(frame, yellow_box, frame_cx, frame_cy, (0, 220, 220), "[YEL]")
            self.get_logger().info(f"[YELLOW] cx_norm={msg_yellow.center_x_norm:+.2f} dist={msg_yellow.distance:.3f}")
        else:
            cv2.putText(frame, "Yellow Flare NOT detected", (10, 65), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 220, 220), 1)

        # ─────────────────────────────────────────────────
        # 6. BLUE FLARE
        # ─────────────────────────────────────────────────
        blue_box, _ = self.detect_blue_flare(hsv, mask_bkt=mask_bkt)
        msg_blue = self._empty_msg("blue_flare")

        if blue_box is not None:
            msg_blue, _, _ = self._fill_msg(msg_blue, blue_box, w, h)
            self._annotate_flare(frame, blue_box, frame_cx, frame_cy, (220, 100, 0), "[BLU]")
            self.get_logger().info(f"[BLUE] cx_norm={msg_blue.center_x_norm:+.2f} dist={msg_blue.distance:.3f}")
        else:
            cv2.putText(frame, "Blue NOT detected", (10, 85), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (220, 100, 0), 1)

        self.pub_obstacle.publish(msg_obstacle)
        self.pub_gate.publish(msg_gate)
        self.pub_red_flare.publish(msg_red)
        self.pub_yellow_flare.publish(msg_yellow)
        self.pub_blue_flare.publish(msg_blue)
        self.pub_bucket_blue.publish(msg_bucket)

        cv2.imshow("SIM Final Detection", frame)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = CameraFinalSim()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()