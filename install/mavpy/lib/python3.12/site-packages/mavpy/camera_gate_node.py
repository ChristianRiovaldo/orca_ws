# # Ini kode tanpa GUI
# import time
# import rclpy
# from rclpy.node import Node
# import cv2
# import torch
# from ultralytics import YOLO
# from orca_msgs.msg import GateDetection

# class CameraGateNode(Node):
#     def __init__(self):
#         super().__init__('camera_gate_node')

#         self.publisher = self.create_publisher(GateDetection, '/orca/perception/gate', 10)

#         MODEL_PATH = "/home/jetson/orca_ws/src/mavpy/mavpy/models/model_datafusion_masdzul.engine"
#         self.model = YOLO(MODEL_PATH, task='detect')

#         device = 0 if torch.cuda.is_available() else "cpu"
#         self.get_logger().info(f"Using device: {device}")

#         # ==============================
#         # CAMERA
#         # ==============================
#         self.cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
#         # self.cap = cv2.VideoCapture("/home/jetson/Downloads/DJI_20260426172057_0218_D.MP4")
#         self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
#         self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
#         self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)

#         if not self.cap.isOpened():
#             self.get_logger().error("Camera tidak terdeteksi!")
#             exit()

#         # ==============================
#         # PARAMETER STABILISASI
#         # ==============================
#         self.last_box = None
#         self.last_conf = 0
#         self.last_class = ""
#         self.max_missing_frames = 5
#         self.missing_counter = 0
#         self.shrink_factor = 0.8

#         # ==============================
#         # TIMER ROS
#         # ==============================
#         self.timer = self.create_timer(0.03, self.process_frame)

#     def process_frame(self):
#         ret, frame = self.cap.read()
#         if not ret:
#             return

#         frame_height, frame_width = frame.shape[:2]

#         start = time.time()

#         # ==============================
#         # YOLO TRACKING
#         # ==============================
#         results = self.model.track(
#             frame,
#             persist=True,
#             conf=0.6,
#             verbose=False
#         )

#         end = time.time()
#         fps = 1 / (end - start)
#         print(f"FPS: {fps:.2f}")

#         detected = False

#         for r in results:
#             boxes = r.boxes

#             for box in boxes:
#                 conf = float(box.conf[0])

#                 if conf > 0.5:
#                     x1, y1, x2, y2 = box.xyxy[0]
#                     cls_id = int(box.cls[0])
#                     class_name = self.model.names[cls_id]

#                     # ==========================
#                     # CENTER
#                     # ==========================
#                     cx = (x1 + x2) / 2
#                     cy = (y1 + y2) / 2

#                     # ==========================
#                     # SHRINK BBOX
#                     # ==========================
#                     width = (x2 - x1) * self.shrink_factor
#                     height = (y2 - y1) * self.shrink_factor

#                     new_x1 = int(cx - width / 2)
#                     new_y1 = int(cy - height / 2)
#                     new_x2 = int(cx + width / 2)
#                     new_y2 = int(cy + height / 2)

#                     self.last_box = (
#                         new_x1,
#                         new_y1,
#                         new_x2,
#                         new_y2
#                     )

#                     self.last_conf = conf
#                     self.last_class = class_name

#                     detected = True
#                     self.missing_counter = 0

#                     break

#         if not detected:
#             self.missing_counter += 1

#         msg = GateDetection()

#         if (self.last_box is not None and self.missing_counter <= self.max_missing_frames):
#             x1, y1, x2, y2 = self.last_box

#             bbox_width = float(x2 - x1)
#             bbox_height = float(y2 - y1)

#             center_x = float((x1 + x2) / 2)
#             center_y = float((y1 + y2) / 2)

#             # ==================================
#             # NORMALIZED CENTER
#             # ==================================
#             center_x_norm = ((center_x - (frame_width / 2)) / (frame_width / 2))

#             # ==================================
#             # BBOX AREA RATIO
#             # ==================================
#             bbox_area = bbox_width * bbox_height
#             frame_area = frame_width * frame_height
#             bbox_area_ratio = (bbox_area / frame_area)

#             # ==================================
#             # DISTANCE ESTIMATION
#             # ==================================
#             FOCAL_LENGTH = 700.0
#             REAL_GATE_WIDTH = 0.8
#             if bbox_width > 0:
#                 distance = (REAL_GATE_WIDTH * FOCAL_LENGTH) / bbox_width

#             msg.detected = True
#             msg.class_name = self.last_class
#             msg.confidence = float(self.last_conf)
#             msg.center_x = center_x
#             msg.center_y = center_y
#             msg.center_x_norm = float(center_x_norm)
#             msg.bbox_width = bbox_width
#             msg.bbox_height = bbox_height
#             msg.bbox_area_ratio = float(bbox_area_ratio)
#             msg.distance = float(distance)

#             self.get_logger().info(
#                 f"[DETECTED] "
#                 f"class={msg.class_name} "
#                 f"conf={msg.confidence:.2f} "
#                 f"cx={msg.center_x:.1f} "
#                 f"dist={msg.distance:.2f}"
#             )

#         else:
#             msg.detected = False
#             msg.class_name = ""
#             msg.confidence = 0.0
#             msg.center_x = 0.0
#             msg.center_y = 0.0
#             msg.center_x_norm = 0.0
#             msg.bbox_width = 0.0
#             msg.bbox_height = 0.0
#             msg.bbox_area_ratio = 0.0
#             msg.distance = -1.0
#             self.get_logger().info("[GATE NOT DETECTED]")

#         self.publisher.publish(msg)

# def main(args=None):
#     rclpy.init(args=args)
#     node = CameraGateNode()
#     rclpy.spin(node)
#     node.cap.release()

# if __name__ == '__main__':
#     main()

# ========================================================================================

# Ini kode dengan GUI
import time
import rclpy
from rclpy.node import Node
import cv2
import torch
from ultralytics import YOLO
from orca_msgs.msg import GateDetection

class CameraGateNode(Node):
    def __init__(self):
        super().__init__('camera_gate_node')

        self.publisher = self.create_publisher(GateDetection, '/orca/perception/gate', 10)

        MODEL_PATH = "/home/jetson/orca_ws/src/mavpy/mavpy/models/model_datafusion_masdzul.engine"
        self.model = YOLO(MODEL_PATH, task='detect')

        device = 0 if torch.cuda.is_available() else "cpu"
        self.get_logger().info(f"Using device: {device}")

        # ==============================
        # CAMERA
        # ==============================
        self.cap = cv2.VideoCapture(0, cv2.CAP_V4L2)
        # self.cap = cv2.VideoCapture("/home/jetson/Downloads/DJI_20260426172057_0218_D.MP4")
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
        self.cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)

        if not self.cap.isOpened():
            self.get_logger().error("Camera tidak terdeteksi!")
            exit()

        # ==============================
        # PARAMETER STABILISASI
        # ==============================
        self.last_box = None
        self.last_conf = 0
        self.last_class = ""
        self.max_missing_frames = 5
        self.missing_counter = 0
        self.shrink_factor = 0.8

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

        detected = False

        for r in results:
            boxes = r.boxes

            for box in boxes:
                conf = float(box.conf[0])

                if conf > 0.5:
                    x1, y1, x2, y2 = box.xyxy[0]
                    cls_id = int(box.cls[0])
                    class_name = self.model.names[cls_id]

                    # ==========================
                    # CENTER
                    # ==========================
                    cx = (x1 + x2) / 2
                    cy = (y1 + y2) / 2

                    # ==========================
                    # SHRINK BBOX
                    # ==========================
                    width = (x2 - x1) * self.shrink_factor
                    height = (y2 - y1) * self.shrink_factor

                    new_x1 = int(cx - width / 2)
                    new_y1 = int(cy - height / 2)
                    new_x2 = int(cx + width / 2)
                    new_y2 = int(cy + height / 2)

                    self.last_box = (
                        new_x1,
                        new_y1,
                        new_x2,
                        new_y2
                    )

                    self.last_conf = conf
                    self.last_class = class_name

                    detected = True
                    self.missing_counter = 0
                    break

        # ==============================
        # HANDLE MISSING
        # ==============================
        if not detected:

            self.missing_counter += 1

        msg = GateDetection()

        # ==============================
        # OBJECT DETECTED
        # ==============================
        if (self.last_box is not None and self.missing_counter <= self.max_missing_frames):
            x1, y1, x2, y2 = self.last_box

            bbox_width = float(x2 - x1)
            bbox_height = float(y2 - y1)

            center_x = float((x1 + x2) / 2)
            center_y = float((y1 + y2) / 2)

            # ==================================
            # NORMALIZED CENTER
            # ==================================
            center_x_norm = ((center_x - (frame_width / 2)) / (frame_width / 2))

            # ==================================
            # BBOX AREA RATIO
            # ==================================
            bbox_area = bbox_width * bbox_height
            frame_area = frame_width * frame_height
            bbox_area_ratio = (bbox_area / frame_area)

            # ==================================
            # DISTANCE ESTIMATION
            # ==================================
            FOCAL_LENGTH = 700.0
            REAL_GATE_WIDTH = 0.8
            if bbox_width > 0:
                distance = (REAL_GATE_WIDTH * FOCAL_LENGTH) / bbox_width

            # ==================================
            # MESSAGE
            # ==================================
            msg.detected = True
            msg.class_name = self.last_class
            msg.confidence = float(self.last_conf)
            msg.center_x = center_x
            msg.center_y = center_y
            msg.center_x_norm = float(center_x_norm)
            msg.bbox_width = bbox_width
            msg.bbox_height = bbox_height
            msg.bbox_area_ratio = float(bbox_area_ratio)
            msg.distance = float(distance)

            # ==================================
            # DRAW BBOX
            # ==================================
            cv2.rectangle(
                frame,
                (x1, y1),
                (x2, y2),
                (0, 255, 0),
                2
            )

            cv2.circle(
                frame,
                (int(center_x), int(center_y)),
                5,
                (0, 0, 255),
                -1
            )

            label = (
                f"{self.last_class} "
                f"{self.last_conf:.2f} "
                f"{distance:.2f}m"
            )

            cv2.putText(
                frame,
                label,
                (x1, y1 - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.6,
                (0, 255, 0),
                2
            )

            self.get_logger().info(
                f"[DETECTED] "
                f"class={msg.class_name} "
                f"conf={msg.confidence:.2f} "
                f"cx={msg.center_x:.1f} "
                f"dist={msg.distance:.2f}"
            )

        # ==============================
        # OBJECT NOT DETECTED
        # ==============================
        else:
            msg.detected = False
            msg.class_name = ""
            msg.confidence = 0.0
            msg.center_x = 0.0
            msg.center_y = 0.0
            msg.center_x_norm = 0.0
            msg.bbox_width = 0.0
            msg.bbox_height = 0.0
            msg.bbox_area_ratio = 0.0
            msg.distance = -1.0
            self.get_logger().info("[GATE NOT DETECTED]")

        # ==============================
        # SHOW FRAME
        # ==============================
        cv2.imshow("Gate Detection", frame)

        key = cv2.waitKey(1)
        if key == ord('q'):
            self.get_logger().info("Shutdown camera node")
            self.cap.release()
            cv2.destroyAllWindows()
            rclpy.shutdown()

        # ==============================
        # PUBLISH
        # ==============================
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CameraGateNode()
    rclpy.spin(node)
    node.cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()