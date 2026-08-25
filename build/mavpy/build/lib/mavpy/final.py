#!/usr/bin/env python3
import rclpy
import time
from enum import Enum
from rclpy.node import Node
from std_msgs.msg import String
from orca_msgs.msg import OrcaAttitude, OrcaControl, OrcaDepth, OrcaProximity, FinalDetection

class State(str, Enum):
    WAIT_ARM          = 'WAIT_ARM'
    INIT              = 'INIT'
    DIVE              = 'DIVE'
    HOLD              = 'HOLD'

    APPROACH_OBSTACLE = 'APPROACH_OBSTACLE'
    OBSTACLE_DETECT   = 'OBSTACLE_DETECT'
    AVOID_OBSTACLE    = 'AVOID_OBSTACLE'

    GATE_SEARCH       = 'GATE_SEARCH'
    GATE_ALIGN        = 'GATE_ALIGN'

    BUCKET_SEARCH     = 'BUCKET_SEARCH'
    BUCKET_APPROACH   = 'BUCKET_APPROACH'
    BUCKET_HOLD       = 'BUCKET_HOLD'
    DROP_BALL         = 'DROP_BALL'

    UTURN             = 'UTURN'
    GATE_SEARCH_2     = 'GATE_SEARCH_2'
    GATE_ALIGN_2      = 'GATE_ALIGN_2'

    FLARE_SEARCH      = 'FLARE_SEARCH'
    FLARE_YAW         = 'FLARE_YAW'
    FLARE_ALIGN       = 'FLARE_ALIGN'

    STOP              = 'STOP'
    SURFACE           = 'SURFACE'
    RESET_MISSION     = 'RESET_MISSION'

class Final(Node):
    def __init__(self):
        super().__init__('final')

        # ==============================
        # PARAM GERAK
        # ==============================
        self.target_depth  = 0.8
        self.neutral       = 1500
        self.forward_fast  = 1800
        self.forward_slow  = 1650
        self.forward_crawl = 1580
        self.throttle_down = 1350
        self.throttle_up   = 1600
        self.lateral_avoid = 1650

        # ==============================
        # PARAM YAW
        # ==============================
        self.yaw_pwm       = 1650
        self.yaw_error     = 20
        self.uturn_heading = None

        # ==============================
        # PARAM LATERAL (semua objek)
        # ==============================
        self.lateral_dead = 0.1
        self.lateral_max  = 1700
        self.lateral_min  = 1300

        # ==============================
        # PARAM OBSTACLE
        # ==============================
        self.obstacle_detect_min_confidence = 0.6
        self.obstacle_detected              = False
        self.obstacle_cx_norm               = 0.0
        self.obstacle_area_ratio            = 0.0
        self.obstacle_distance              = None
        self.last_obstacle_seen_time        = 0.0
        self.avoid_direction                = 1

        # ==============================
        # PARAM GATE
        # ==============================
        self.gate_detect_min_confidence = 0.6
        self.last_gate_seen_time        = 0.0
        self.gate_detected              = False
        self.gate_cx_norm               = 0.0
        self.gate_confidence            = 0.0

        # ==============================
        # PARAM FLARE
        # ==============================
        self.flare_detect_min_confidence = 0.6

        self.red_detected       = False
        self.red_cx_norm        = 0.0
        self.last_red_seen_time = 0.0

        self.yellow_detected       = False
        self.yellow_cx_norm        = 0.0
        self.last_yellow_seen_time = 0.0

        self.blue_detected       = False
        self.blue_cx_norm        = 0.0
        self.last_blue_seen_time = 0.0

        self.flare_sequence  = ['r', 'y', 'b']
        self.flare_index     = 0
        self.flare_hit_count = 0
        self.target_cx_norm  = 0.0
        self.target_detected = False

        # ==============================
        # PARAM FLARE SEARCH YAW
        # ==============================
        self.flare_yaw_heading   = None    # heading awal saat mulai yaw
        self.flare_yaw_direction = 1       # 1 = kanan, -1 = kiri
        self.flare_yaw_count     = 0       # jumlah yaw yang sudah dilakukan
        self.flare_yaw_max       = 3       # max yaw kanan+kiri sebelum surface

        # ==============================
        # PARAM BUCKET
        # ==============================
        self.bucket_detect_min_confidence = 0.5
        self.bucket_area_threshold        = 0.20
        self.bucket_detected              = False
        self.bucket_cx_norm               = 0.0
        self.bucket_area_ratio            = 0.0
        self.last_bucket_seen_time        = 0.0

        # ==============================
        # STATE
        # ==============================
        self.state       = State.WAIT_ARM
        self.state_since = time.time()
        self.depth       = None
        self.yaw         = None
        self.is_armed    = False

        # ==============================
        # PUBLISHERS
        # ==============================
        self.control_pub = self.create_publisher(OrcaControl, '/orca/auto/control',  10)
        self.state_pub   = self.create_publisher(String,      '/orca/mission/state', 10)

        # ==============================
        # SUBSCRIBERS SENSOR
        # ==============================
        self.create_subscription(OrcaDepth,     '/orca/sensor/depth',    self.depth_cb,     10)
        self.create_subscription(OrcaAttitude,  '/orca/sensor/attitude', self.attitude_cb,  10)
        self.create_subscription(OrcaProximity, '/orca/start_trigger',   self.proximity_cb, 10)

        # ==============================
        # SUBSCRIBERS CAMERA
        # ==============================
        self.create_subscription(FinalDetection, '/orca/perception/gate',     self.gate_cb,     10)
        self.create_subscription(FinalDetection, '/orca/perception/obstacle', self.obstacle_cb, 10)
        self.create_subscription(FinalDetection, '/orca/perception/ember',    self.bucket_cb,   10)
        self.create_subscription(FinalDetection, '/orca/perception/r-flare',  self.red_cb,      10)
        self.create_subscription(FinalDetection, '/orca/perception/y-flare',  self.yellow_cb,   10)
        self.create_subscription(FinalDetection, '/orca/perception/b-flare',  self.blue_cb,     10)

        self.create_timer(0.1, self.update)
        self.get_logger().info("MISSION READY — waiting for proximity trigger")

    # ================================================================== CALLBACKS SENSOR

    def depth_cb(self, msg: OrcaDepth):
        self.depth = msg.depth

    def attitude_cb(self, msg: OrcaAttitude):
        self.yaw = msg.initial_deg

    def proximity_cb(self, msg: OrcaProximity):
        prev = self.is_armed
        self.is_armed = msg.triggered
        if self.is_armed and not prev:
            self.get_logger().info("PROXIMITY ON → arm & start mission")
        if not self.is_armed and prev:
            self.get_logger().warn("PROXIMITY OFF → disarm & reset mission")

    # ================================================================== CALLBACKS CAMERA

    def obstacle_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.obstacle_detect_min_confidence:
            self.obstacle_detected       = True
            self.obstacle_cx_norm        = msg.center_x_norm
            self.obstacle_area_ratio     = msg.bbox_area_ratio
            self.obstacle_distance       = msg.distance
            self.last_obstacle_seen_time = time.time()
        else:
            self.obstacle_detected = False

    def gate_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.gate_detect_min_confidence:
            self.gate_detected       = True
            self.gate_cx_norm        = msg.center_x_norm
            self.gate_confidence     = msg.confidence
            self.last_gate_seen_time = time.time()
        else:
            self.gate_detected = False

    def red_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.flare_detect_min_confidence:
            self.red_detected       = True
            self.red_cx_norm        = msg.center_x_norm
            self.last_red_seen_time = time.time()
        else:
            self.red_detected = False

    def yellow_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.flare_detect_min_confidence:
            self.yellow_detected       = True
            self.yellow_cx_norm        = msg.center_x_norm
            self.last_yellow_seen_time = time.time()
        else:
            self.yellow_detected = False

    def blue_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.flare_detect_min_confidence:
            self.blue_detected       = True
            self.blue_cx_norm        = msg.center_x_norm
            self.last_blue_seen_time = time.time()
        else:
            self.blue_detected = False

    def bucket_cb(self, msg: FinalDetection):
        if msg.detected and msg.confidence >= self.bucket_detect_min_confidence:
            self.bucket_detected       = True
            self.bucket_cx_norm        = msg.center_x_norm
            self.bucket_area_ratio     = msg.bbox_area_ratio
            self.last_bucket_seen_time = time.time()
        else:
            self.bucket_detected = False

    # ================================================================== HELPERS DETEKSI

    def current_target_color(self):
        if self.flare_index < len(self.flare_sequence):
            return self.flare_sequence[self.flare_index]
        return None

    def update_target(self):
        color = self.current_target_color()
        now   = time.time()
        if color == 'r':
            self.target_detected = self.red_detected    and now - self.last_red_seen_time    < 0.5
            self.target_cx_norm  = self.red_cx_norm
        elif color == 'y':
            self.target_detected = self.yellow_detected and now - self.last_yellow_seen_time < 0.5
            self.target_cx_norm  = self.yellow_cx_norm
        elif color == 'b':
            self.target_detected = self.blue_detected   and now - self.last_blue_seen_time   < 0.5
            self.target_cx_norm  = self.blue_cx_norm
        else:
            self.target_detected = False
            self.target_cx_norm  = 0.0

    def is_bucket_detected(self):
        return self.bucket_detected and (time.time() - self.last_bucket_seen_time < 0.5)

    # ================================================================== HELPERS YAW

    def yaw_reached(self, target_deg: float) -> bool:
        """Cek delta putar searah jarum jam dari heading awal."""
        if self.yaw is None or self.uturn_heading is None:
            return False
        delta = self.yaw - self.uturn_heading
        while delta <   0: delta += 360
        while delta >= 360: delta -= 360
        threshold = target_deg - self.yaw_error
        reached   = delta >= threshold
        self.get_logger().info(
            f"[YAW] heading={self.yaw:.1f}° "
            f"initial={self.uturn_heading:.1f}° "
            f"delta={delta:.1f}° "
            f"target={target_deg}° "
            f"threshold={threshold}° "
            f"reached={reached}",
            throttle_duration_sec=0.5
        )
        return reached

    def flare_yaw_reached(self, target_deg: float) -> bool:
        """
        Cek delta putar dari heading awal FLARE_YAW.
        Kanan (+) → delta positif searah jarum jam.
        Kiri  (-) → delta positif berlawanan jarum jam.
        """
        if self.yaw is None or self.flare_yaw_heading is None:
            return False

        if self.flare_yaw_direction > 0:
            # Putar kanan → delta CW
            delta = self.yaw - self.flare_yaw_heading
            while delta <   0: delta += 360
            while delta >= 360: delta -= 360
        else:
            # Putar kiri → delta CCW
            delta = self.flare_yaw_heading - self.yaw
            while delta <   0: delta += 360
            while delta >= 360: delta -= 360

        threshold = target_deg - self.yaw_error
        reached   = delta >= threshold

        self.get_logger().info(
            f"[FLARE_YAW] dir={'kanan' if self.flare_yaw_direction > 0 else 'kiri'} "
            f"heading={self.yaw:.1f}° "
            f"initial={self.flare_yaw_heading:.1f}° "
            f"delta={delta:.1f}° "
            f"threshold={threshold}° "
            f"reached={reached}",
            throttle_duration_sec=0.5
        )
        return reached

    # ================================================================== HELPERS KONTROL

    def lateral_cmd(self, cx_norm: float) -> int:
        cx_norm = max(-1.0, min(1.0, cx_norm))
        if cx_norm > self.lateral_dead:
            ratio = (cx_norm - self.lateral_dead) / (1.0 - self.lateral_dead)
            pwm   = int(1600 + ratio * (self.lateral_max - 1600))
            return min(pwm, self.lateral_max)
        elif cx_norm < -self.lateral_dead:
            ratio = (-cx_norm - self.lateral_dead) / (1.0 - self.lateral_dead)
            pwm   = int(1400 - ratio * (1400 - self.lateral_min))
            return max(pwm, self.lateral_min)
        else:
            return self.neutral

    def avoid_lateral_cmd(self):
        return int(self.lateral_avoid if self.avoid_direction > 0 else (3000 - self.lateral_avoid))

    def publish(self, throttle=None, forward=None, lateral=None, yaw=None, mode='ALT_HOLD', gripper=None):
        msg = OrcaControl()
        msg.throttle     = int(self.neutral if throttle is None else throttle)
        msg.forward      = int(self.neutral if forward  is None else forward)
        msg.lateral      = int(self.neutral if lateral  is None else lateral)
        msg.yaw          = int(self.neutral if yaw      is None else yaw)
        msg.control_mode = mode
        msg.arm_mode     = 'arm' if self.is_armed else 'disarm'
        msg.gripper_mode = gripper if gripper is not None else ''
        msg.source       = 'auto'
        self.control_pub.publish(msg)

    def set_state(self, s: State):
        self.state       = s
        self.state_since = time.time()
        self.get_logger().info(f"STATE → {s}")
        msg = String(); msg.data = str(s)
        self.state_pub.publish(msg)

    def reset_vars(self):
        self.gate_detected       = False
        self.obstacle_detected   = False
        self.bucket_detected     = False
        self.red_detected        = False
        self.yellow_detected     = False
        self.blue_detected       = False
        self.flare_sequence      = ['r', 'y', 'b']
        self.flare_index         = 0
        self.flare_hit_count     = 0
        self.last_gate_seen_time = 0.0
        self.uturn_heading       = None
        self.flare_yaw_heading   = None
        self.flare_yaw_direction = 1
        self.flare_yaw_count     = 0
        self.get_logger().info("Mission variables reset")

    def elapsed(self):
        return time.time() - self.state_since

    # ================================================================== STATE MACHINE

    def update(self):
        now = time.time()

        # Disarm di tengah misi → paksa reset
        if not self.is_armed and self.state not in (State.WAIT_ARM, State.RESET_MISSION):
            self.reset_vars()
            self.set_state(State.WAIT_ARM)
            self.publish(mode='MANUAL')
            return

        # -------------------------------------------------------------- 1. WAIT ARM
        if self.state == State.WAIT_ARM:
            self.publish(mode='MANUAL')
            if self.is_armed:
                self.set_state(State.INIT)
            return

        # -------------------------------------------------------------- 2. INIT
        if self.state == State.INIT:
            if self.elapsed() > 5.0:
                self.set_state(State.DIVE)
            return

        # -------------------------------------------------------------- 3. DIVE
        if self.state == State.DIVE:
            if self.depth < self.target_depth:
                self.publish(throttle=self.throttle_down)
            else:
                self.set_state(State.HOLD)
            return

        # -------------------------------------------------------------- 4. HOLD
        if self.state == State.HOLD:
            self.publish()
            if self.elapsed() > 2.0:
                self.set_state(State.APPROACH_OBSTACLE)
            return

        # -------------------------------------------------------------- 5. APPROACH OBSTACLE
        if self.state == State.APPROACH_OBSTACLE:
            self.publish(forward=self.forward_fast)

            if self.obstacle_detected:
                self.get_logger().info(
                    f"[OBSTACLE] cx_norm={self.obstacle_cx_norm:.2f} "
                    f"dist={self.obstacle_distance:.2f}m → OBSTACLE_DETECT"
                )
                self.set_state(State.OBSTACLE_DETECT)
                return

            if self.elapsed() > 10.0:
                self.get_logger().warn("Obstacle not found → GATE_SEARCH")
                self.set_state(State.GATE_SEARCH)
            return

        # -------------------------------------------------------------- 6. OBSTACLE DETECT
        if self.state == State.OBSTACLE_DETECT:
            self.publish()

            if self.elapsed() > 1.0:
                if self.obstacle_cx_norm >= 0:
                    self.avoid_direction = -1
                    self.get_logger().info("Obstacle RIGHT → lateral LEFT")
                else:
                    self.avoid_direction = 1
                    self.get_logger().info("Obstacle LEFT → lateral RIGHT")
                self.set_state(State.AVOID_OBSTACLE)
            return

        # -------------------------------------------------------------- 7. AVOID OBSTACLE
        if self.state == State.AVOID_OBSTACLE:
            self.publish(lateral=self.avoid_lateral_cmd())

            if self.elapsed() > 1.0:
                self.set_state(State.GATE_SEARCH)
            return

        # -------------------------------------------------------------- 8. GATE SEARCH
        if self.state == State.GATE_SEARCH:
            self.publish(forward=self.forward_fast)

            if self.gate_detected and (now - self.last_gate_seen_time < 0.5):
                self.set_state(State.GATE_ALIGN)
                return

            if self.elapsed() > 10.0:
                self.get_logger().warn("Gate timeout → SURFACE")
                self.set_state(State.SURFACE)
            return

        # -------------------------------------------------------------- 9. GATE ALIGN
        if self.state == State.GATE_ALIGN:
            if self.gate_detected:
                self.publish(
                    forward=self.forward_slow,
                    lateral=self.lateral_cmd(self.gate_cx_norm)
                )
                self.get_logger().info(
                    f"[GATE_ALIGN] cx_norm={self.gate_cx_norm:.2f} "
                    f"lateral={self.lateral_cmd(self.gate_cx_norm)}"
                )
            else:
                self.publish(forward=self.forward_fast)
                if now - self.last_gate_seen_time > 5.0:
                    self.get_logger().info("Gate passed → BUCKET_SEARCH")
                    self.set_state(State.BUCKET_SEARCH)
            return

        # -------------------------------------------------------------- 10. BUCKET SEARCH
        if self.state == State.BUCKET_SEARCH:
            self.publish()

            if self.is_bucket_detected():
                self.publish(lateral=self.lateral_cmd(self.bucket_cx_norm))
                self.get_logger().info("Bucket found → align")
                if abs(self.bucket_cx_norm) < self.lateral_dead:
                    self.set_state(State.BUCKET_APPROACH)
                return

            if self.elapsed() > 10.0:
                self.set_state(State.SURFACE)
            return

        # -------------------------------------------------------------- 11. BUCKET APPROACH
        if self.state == State.BUCKET_APPROACH:
            if self.is_bucket_detected():
                self.publish(
                    forward=self.forward_crawl,
                    lateral=self.lateral_cmd(self.bucket_cx_norm)
                )
                if self.bucket_area_ratio >= self.bucket_area_threshold:
                    self.get_logger().info("Bucket in position → BUCKET_HOLD")
                    self.set_state(State.BUCKET_HOLD)
            else:
                self.publish()
                if self.elapsed() > 10.0:
                    self.set_state(State.SURFACE)
            return

        # -------------------------------------------------------------- 12. BUCKET HOLD
        if self.state == State.BUCKET_HOLD:
            self.publish(lateral=self.lateral_cmd(self.bucket_cx_norm))
            if self.elapsed() > 8.0:
                self.get_logger().info("Hold done → DROP_BALL")
                self.set_state(State.DROP_BALL)
            return

        # -------------------------------------------------------------- 13. DROP BALL
        if self.state == State.DROP_BALL:
            if self.elapsed() < 3.0:
                self.publish(gripper='open_right')
                self.get_logger().info(
                    f"[DROP_BALL] Gripper open_right {self.elapsed():.1f}s / 3.0s",
                    throttle_duration_sec=1.0
                )
            else:
                self.publish(gripper='close')
                self.get_logger().info("[DROP_BALL] Gripper close → UTURN")
                self.set_state(State.UTURN)
            return

        # -------------------------------------------------------------- 14. UTURN
        if self.state == State.UTURN:
            if self.yaw is None:
                return

            if self.uturn_heading is None:
                self.uturn_heading = self.yaw
                self.get_logger().info(f"[UTURN] Heading awal = {self.uturn_heading:.1f}°")

            if self.yaw_reached(180):
                self.get_logger().info(f"[UTURN] Selesai di {self.yaw:.1f}° → GATE_SEARCH_2")
                self.publish()
                self.uturn_heading = None
                self.set_state(State.GATE_SEARCH_2)
            else:
                self.publish(yaw=self.yaw_pwm)
            return

        # -------------------------------------------------------------- 15. GATE SEARCH 2
        if self.state == State.GATE_SEARCH_2:
            self.publish(forward=self.forward_fast)

            if self.gate_detected and (now - self.last_gate_seen_time < 0.5):
                self.set_state(State.GATE_ALIGN_2)
                return

            if self.elapsed() > 20.0:
                self.get_logger().info("Gate not found → FLARE_SEARCH")
                self.set_state(State.FLARE_SEARCH)
            return

        # -------------------------------------------------------------- 16. GATE ALIGN 2
        if self.state == State.GATE_ALIGN_2:
            if self.gate_detected:
                self.publish(
                    forward=self.forward_slow,
                    lateral=self.lateral_cmd(self.gate_cx_norm)
                )
                self.get_logger().info(
                    f"[GATE_ALIGN_2] cx_norm={self.gate_cx_norm:.2f} "
                    f"lateral={self.lateral_cmd(self.gate_cx_norm)}"
                )
            else:
                self.publish(forward=self.forward_fast)
                if now - self.last_gate_seen_time > 5.0:
                    self.get_logger().info("Gate passed → FLARE_SEARCH")
                    if self.elapsed() > 12.0:
                        self.set_state(State.FLARE_SEARCH)
            return

        # -------------------------------------------------------------- 17. FLARE SEARCH
        if self.state == State.FLARE_SEARCH:
            color = self.current_target_color()

            if color is None:
                self.get_logger().info("All flares hit → STOP")
                self.set_state(State.STOP)
                return

            self.update_target()
            self.publish()

            if self.target_detected:
                self.get_logger().info(
                    f"[FLARE_SEARCH] Flare {color.upper()} terdeteksi → FLARE_ALIGN"
                )
                self.flare_yaw_heading   = None
                self.flare_yaw_direction = 1
                self.flare_yaw_count     = 0
                self.set_state(State.FLARE_ALIGN)
                return

            if self.elapsed() > 7.0:
                if self.flare_yaw_count >= self.flare_yaw_max:
                    self.get_logger().warn(
                        f"[FLARE_SEARCH] Sudah {self.flare_yaw_max}x yaw, "
                        f"flare {color.upper()} tidak ditemukan → SURFACE"
                    )
                    self.set_state(State.SURFACE)
                    return
                self.flare_yaw_heading = self.yaw
                self.set_state(State.FLARE_YAW)
            return

        # -------------------------------------------------------------- 18. FLARE YAW
        if self.state == State.FLARE_YAW:
            if self.yaw is None:
                return

            color = self.current_target_color()

            self.update_target()
            if self.target_detected:
                self.get_logger().info(
                    f"[FLARE_YAW] Flare {color.upper()} terdeteksi saat yaw → FLARE_ALIGN"
                )
                self.flare_yaw_heading   = None
                self.flare_yaw_direction = 1
                self.flare_yaw_count     = 0
                self.set_state(State.FLARE_ALIGN)
                return

            # Tentukan PWM yaw berdasarkan arah
            # Kanan (+1) → 1650, Kiri (-1) → 1350
            yaw_pwm = self.yaw_pwm if self.flare_yaw_direction > 0 else (3000 - self.yaw_pwm)
            self.publish(yaw=yaw_pwm)

            if self.flare_yaw_reached(90):
                self.flare_yaw_count += 1

                self.flare_yaw_direction *= -1
                self.flare_yaw_heading    = None
                self.publish()
                self.set_state(State.FLARE_SEARCH)
            return

        # -------------------------------------------------------------- 19. FLARE ALIGN
        if self.state == State.FLARE_ALIGN:
            self.update_target()

            if self.target_detected:
                self.publish(
                    forward=self.forward_fast,
                    lateral=self.lateral_cmd(self.target_cx_norm)
                )
                self.get_logger().info(
                    f"[FLARE_ALIGN] cx_norm={self.target_cx_norm:.2f} "
                    f"lateral={self.lateral_cmd(self.target_cx_norm)}"
                )
            else:
                self.publish(forward=1400)

                if self.elapsed() > 2.0:
                    color = self.current_target_color()
                    if color:
                        self.get_logger().info(f"[HIT] Flare {color.upper()} tertabrak")
                        self.flare_index     += 1
                        self.flare_hit_count += 1

                    # Reset yaw counter untuk flare berikutnya
                    self.flare_yaw_heading   = None
                    self.flare_yaw_direction = 1
                    self.flare_yaw_count     = 0

                    if self.flare_index >= len(self.flare_sequence):
                        self.get_logger().info("All flares hit! → STOP")
                        self.set_state(State.STOP)
                    else:
                        next_c = self.flare_sequence[self.flare_index]
                        self.get_logger().info(
                            f"Hit done → next: {next_c.upper()} → FLARE_SEARCH"
                        )
                        self.set_state(State.FLARE_SEARCH)
            return

        # -------------------------------------------------------------- 20. STOP
        if self.state == State.STOP:
            self.publish(mode='MANUAL')
            if self.elapsed() > 1.0:
                self.set_state(State.SURFACE)
            return

        # -------------------------------------------------------------- 21. SURFACE
        if self.state == State.SURFACE:
            self.publish(throttle=self.throttle_up, mode='MANUAL')
            if self.elapsed() > 1:
                self.set_state(State.RESET_MISSION)
                return
            return

        # -------------------------------------------------------------- 22. RESET MISSION
        if self.state == State.RESET_MISSION:
            self.publish(mode='MANUAL')
            if not self.is_armed:
                self.get_logger().info("PROXIMITY OFF → mission reset → WAIT_ARM")
                self.reset_vars()
                self.set_state(State.WAIT_ARM)
            else:
                self.get_logger().info(
                    "MISSION COMPLETE — ketuk proximity untuk reset",
                    throttle_duration_sec=5
                )
            return


def main():
    rclpy.init()
    node = Final()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()