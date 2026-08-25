import time
import rclpy
from rclpy.node import Node
import cv2
import torch
from ultralytics import YOLO
from orca_msgs.msg import FinalDetection

# ==============================
# REAL WIDTH PER CLASS (meter)
# ==============================
REAL_WIDTH_MAP = {
    "gate":     1.50,
    "obstacle": 0.15,
    "ember":    0.60,
    "b-flare":  0.016,
    "r-flare":  0.016,
    "y-flare":  0.016,
}

class CameraFinal(Node):
    def __init__(self):
        super().__init__('camera_final')

        MODEL_PATH = "/home/jetson/orca_ws/src/mavpy/mavpy/models/final.engine"
        self.model = YOLO(MODEL_PATH, task='detect')

        device = 0 if torch.cuda.is_available() else "cpu"
        self.get_logger().info(f"Using device: {device}")

        # ==============================
        # PUBLISHER PER CLASS
        # ==============================
        self.pub_gate     = self.create_publisher(FinalDetection, '/orca/perception/gate',     10)
        self.pub_obstacle = self.create_publisher(FinalDetection, '/orca/perception/obstacle', 10)
        self.pub_ember    = self.create_publisher(FinalDetection, '/orca/perception/ember',    10)
        self.pub_b_flare  = self.create_publisher(FinalDetection, '/orca/perception/b-flare',  10)
        self.pub_r_flare  = self.create_publisher(FinalDetection, '/orca/perception/r-flare',  10)
        self.pub_y_flare  = self.create_publisher(FinalDetection, '/orca/perception/y-flare',  10)

        # ==============================
        # CAMERA
        # ==============================
        self.cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
        # self.cap = cv2.VideoCapture("/home/jetson/Downloads/video.mp4")
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)

        if not self.cap.isOpened():
            self.get_logger().error("Camera tidak terdeteksi!")
            exit()

        # ==============================
        # PARAMETER STABILISASI PER CLASS
        # ==============================
        self.tracked = {
            "gate":     {"last_box": None, "last_conf": 0.0, "missing": 0},
            "obstacle": {"last_box": None, "last_conf": 0.0, "missing": 0},
            "ember":    {"last_box": None, "last_conf": 0.0, "missing": 0},
            "b-flare":  {"last_box": None, "last_conf": 0.0, "missing": 0},
            "r-flare":  {"last_box": None, "last_conf": 0.0, "missing": 0},
            "y-flare":  {"last_box": None, "last_conf": 0.0, "missing": 0},
        }
        self.max_missing_frames = 5
        self.shrink_factor      = 0.8
        self.focal_length       = 700.0

        # ==============================
        # TIMER ROS
        # ==============================
        self.timer = self.create_timer(0.03, self.process_frame)

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            return

        frame_height, frame_width = frame.shape[:2]

        start = time.time()

        # ==============================
        # YOLO TRACKING
        # ==============================
        results = self.model.track(
            frame,
            persist=True,
            conf=0.6,
            verbose=False
        )

        end = time.time()
        fps = 1 / (end - start)
        print(f"FPS: {fps:.2f}")

        # ==============================
        # TANDAI CLASS YANG TERDETEKSI
        # ==============================
        detected_this_frame = set()

        for r in results:
            for box in r.boxes:
                conf = float(box.conf[0])

                if conf < 0.5:
                    continue

                x1, y1, x2, y2 = box.xyxy[0]
                cls_id     = int(box.cls[0])
                class_name = self.model.names[cls_id]

                if class_name not in self.tracked:
                    continue

                # ==========================
                # CENTER
                # ==========================
                cx = (x1 + x2) / 2
                cy = (y1 + y2) / 2

                # ==========================
                # SHRINK BBOX
                # ==========================
                width  = (x2 - x1) * self.shrink_factor
                height = (y2 - y1) * self.shrink_factor

                new_x1 = int(cx - width  / 2)
                new_y1 = int(cy - height / 2)
                new_x2 = int(cx + width  / 2)
                new_y2 = int(cy + height / 2)

                # ==========================
                # UPDATE TRACKER
                # ==========================
                self.tracked[class_name]["last_box"]  = (new_x1, new_y1, new_x2, new_y2)
                self.tracked[class_name]["last_conf"] = conf
                self.tracked[class_name]["missing"]   = 0

                detected_this_frame.add(class_name)

                # ==========================
                # DRAW BBOX
                # ==========================
                cv2.rectangle(frame, (new_x1, new_y1), (new_x2, new_y2), (0, 255, 0), 2)
                cv2.circle(frame, (int(cx), int(cy)), 5, (0, 0, 255), -1)

                real_w         = REAL_WIDTH_MAP.get(class_name, 0.3)
                distance_label = (real_w * self.focal_length) / width if width > 0 else 0.0

                cv2.putText(
                    frame,
                    f"{class_name} {conf:.2f} {distance_label:.2f}m",
                    (new_x1, new_y1 - 10),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.6, (0, 255, 0), 2
                )

        # ==============================
        # INCREMENT MISSING COUNTER
        # ==============================
        for cls_name in self.tracked:
            if cls_name not in detected_this_frame:
                self.tracked[cls_name]["missing"] += 1

        # ==============================
        # BUILD & PUBLISH PER CLASS
        # ==============================
        self.pub_gate.publish(    self._build_msg("gate",     frame_width, frame_height))
        self.pub_obstacle.publish(self._build_msg("obstacle", frame_width, frame_height))
        self.pub_ember.publish(   self._build_msg("ember",    frame_width, frame_height))
        self.pub_b_flare.publish( self._build_msg("b-flare",  frame_width, frame_height))
        self.pub_r_flare.publish( self._build_msg("r-flare",  frame_width, frame_height))
        self.pub_y_flare.publish( self._build_msg("y-flare",  frame_width, frame_height))

        # ==============================
        # SHOW FRAME
        # ==============================
        cv2.imshow("Camera Final", frame)

        key = cv2.waitKey(1)
        if key == ord('q'):
            self.get_logger().info("Shutdown camera node")
            self.cap.release()
            cv2.destroyAllWindows()
            rclpy.shutdown()

    def _build_msg(self, cls_name: str, frame_width: int, frame_height: int) -> FinalDetection:
        msg  = FinalDetection()
        data = self.tracked[cls_name]

        last_box = data["last_box"]
        missing  = data["missing"]
        conf     = data["last_conf"]

        # ==================================
        # OBJECT DETECTED
        # ==================================
        if last_box is not None and missing <= self.max_missing_frames:
            x1, y1, x2, y2 = last_box

            bbox_width  = float(x2 - x1)
            bbox_height = float(y2 - y1)
            center_x    = float((x1 + x2) / 2)
            center_y    = float((y1 + y2) / 2)

            center_x_norm   = (center_x - (frame_width  / 2)) / (frame_width  / 2)
            bbox_area_ratio = (bbox_width * bbox_height) / (frame_width * frame_height)

            real_w   = REAL_WIDTH_MAP.get(cls_name, 0.3)
            distance = (real_w * self.focal_length) / bbox_width if bbox_width > 0 else -1.0

            msg.detected        = True
            msg.class_name      = cls_name
            msg.confidence      = float(conf)
            msg.center_x        = center_x
            msg.center_y        = center_y
            msg.center_x_norm   = float(center_x_norm)
            msg.bbox_width      = bbox_width
            msg.bbox_height     = bbox_height
            msg.bbox_area_ratio = float(bbox_area_ratio)
            msg.distance        = float(distance)

            self.get_logger().info(
                f"[DETECTED] class={cls_name} "
                f"conf={conf:.2f} "
                f"cx={center_x:.1f} "
                f"dist={distance:.2f}"
            )

        # ==================================
        # OBJECT NOT DETECTED
        # ==================================
        else:
            msg.detected        = False
            msg.class_name      = cls_name
            msg.confidence      = 0.0
            msg.center_x        = 0.0
            msg.center_y        = 0.0
            msg.center_x_norm   = 0.0
            msg.bbox_width      = 0.0
            msg.bbox_height     = 0.0
            msg.bbox_area_ratio = 0.0
            msg.distance        = -1.0

        return msg

def main(args=None):
    rclpy.init(args=args)
    node = CameraFinal()
    rclpy.spin(node)
    node.cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()