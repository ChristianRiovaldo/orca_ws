#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to orca_msgs__msg__FinalDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FinalDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_x_norm: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_area_ratio: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,

}



impl Default for FinalDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FinalDetection::default())
  }
}

impl rosidl_runtime_rs::Message for FinalDetection {
  type RmwMsg = super::msg::rmw::FinalDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        detected: msg.detected,
        class_name: msg.class_name.as_str().into(),
        confidence: msg.confidence,
        center_x: msg.center_x,
        center_y: msg.center_y,
        center_x_norm: msg.center_x_norm,
        bbox_width: msg.bbox_width,
        bbox_height: msg.bbox_height,
        bbox_area_ratio: msg.bbox_area_ratio,
        distance: msg.distance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      detected: msg.detected,
        class_name: msg.class_name.as_str().into(),
      confidence: msg.confidence,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x_norm: msg.center_x_norm,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_area_ratio: msg.bbox_area_ratio,
      distance: msg.distance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      detected: msg.detected,
      class_name: msg.class_name.to_string(),
      confidence: msg.confidence,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x_norm: msg.center_x_norm,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_area_ratio: msg.bbox_area_ratio,
      distance: msg.distance,
    }
  }
}


// Corresponds to orca_msgs__msg__GateDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GateDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center_x_norm: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_area_ratio: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,

}



impl Default for GateDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GateDetection::default())
  }
}

impl rosidl_runtime_rs::Message for GateDetection {
  type RmwMsg = super::msg::rmw::GateDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        detected: msg.detected,
        class_name: msg.class_name.as_str().into(),
        confidence: msg.confidence,
        center_x: msg.center_x,
        center_y: msg.center_y,
        center_x_norm: msg.center_x_norm,
        bbox_width: msg.bbox_width,
        bbox_height: msg.bbox_height,
        bbox_area_ratio: msg.bbox_area_ratio,
        distance: msg.distance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      detected: msg.detected,
        class_name: msg.class_name.as_str().into(),
      confidence: msg.confidence,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x_norm: msg.center_x_norm,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_area_ratio: msg.bbox_area_ratio,
      distance: msg.distance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      detected: msg.detected,
      class_name: msg.class_name.to_string(),
      confidence: msg.confidence,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x_norm: msg.center_x_norm,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      bbox_area_ratio: msg.bbox_area_ratio,
      distance: msg.distance,
    }
  }
}


// Corresponds to orca_msgs__msg__OrcaDepth

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrcaDepth {

    // This member is not documented.
    #[allow(missing_docs)]
    pub depth: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pressure: f32,

}



impl Default for OrcaDepth {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OrcaDepth::default())
  }
}

impl rosidl_runtime_rs::Message for OrcaDepth {
  type RmwMsg = super::msg::rmw::OrcaDepth;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        depth: msg.depth,
        pressure: msg.pressure,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      depth: msg.depth,
      pressure: msg.pressure,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      depth: msg.depth,
      pressure: msg.pressure,
    }
  }
}


// Corresponds to orca_msgs__msg__OrcaAttitude

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrcaAttitude {

    // This member is not documented.
    #[allow(missing_docs)]
    pub initial_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub initial_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub initial_z: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub initial_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub roll_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub rollspeed_deg_s: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitchspeed_deg_s: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yawspeed_deg_s: f32,

}



impl Default for OrcaAttitude {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OrcaAttitude::default())
  }
}

impl rosidl_runtime_rs::Message for OrcaAttitude {
  type RmwMsg = super::msg::rmw::OrcaAttitude;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        initial_x: msg.initial_x,
        initial_y: msg.initial_y,
        initial_z: msg.initial_z,
        yaw_deg: msg.yaw_deg,
        initial_deg: msg.initial_deg,
        roll_deg: msg.roll_deg,
        pitch_deg: msg.pitch_deg,
        rollspeed_deg_s: msg.rollspeed_deg_s,
        pitchspeed_deg_s: msg.pitchspeed_deg_s,
        yawspeed_deg_s: msg.yawspeed_deg_s,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      initial_x: msg.initial_x,
      initial_y: msg.initial_y,
      initial_z: msg.initial_z,
      yaw_deg: msg.yaw_deg,
      initial_deg: msg.initial_deg,
      roll_deg: msg.roll_deg,
      pitch_deg: msg.pitch_deg,
      rollspeed_deg_s: msg.rollspeed_deg_s,
      pitchspeed_deg_s: msg.pitchspeed_deg_s,
      yawspeed_deg_s: msg.yawspeed_deg_s,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      initial_x: msg.initial_x,
      initial_y: msg.initial_y,
      initial_z: msg.initial_z,
      yaw_deg: msg.yaw_deg,
      initial_deg: msg.initial_deg,
      roll_deg: msg.roll_deg,
      pitch_deg: msg.pitch_deg,
      rollspeed_deg_s: msg.rollspeed_deg_s,
      pitchspeed_deg_s: msg.pitchspeed_deg_s,
      yawspeed_deg_s: msg.yawspeed_deg_s,
    }
  }
}


// Corresponds to orca_msgs__msg__OrcaProximity
/// data proximity isinya boolean doang njir
/// true = arm
/// false = disarm

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrcaProximity {

    // This member is not documented.
    #[allow(missing_docs)]
    pub arm_mode: bool,

}



impl Default for OrcaProximity {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OrcaProximity::default())
  }
}

impl rosidl_runtime_rs::Message for OrcaProximity {
  type RmwMsg = super::msg::rmw::OrcaProximity;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        arm_mode: msg.arm_mode,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      arm_mode: msg.arm_mode,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      arm_mode: msg.arm_mode,
    }
  }
}


// Corresponds to orca_msgs__msg__OrcaControl

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrcaControl {

    // This member is not documented.
    #[allow(missing_docs)]
    pub throttle: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lateral: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub forward: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub roll: i16,


    // This member is not documented.
    #[allow(missing_docs)]
    pub arm_mode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_mode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripper_mode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source: std::string::String,

}



impl Default for OrcaControl {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OrcaControl::default())
  }
}

impl rosidl_runtime_rs::Message for OrcaControl {
  type RmwMsg = super::msg::rmw::OrcaControl;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        throttle: msg.throttle,
        lateral: msg.lateral,
        forward: msg.forward,
        yaw: msg.yaw,
        pitch: msg.pitch,
        roll: msg.roll,
        arm_mode: msg.arm_mode.as_str().into(),
        control_mode: msg.control_mode.as_str().into(),
        gripper_mode: msg.gripper_mode.as_str().into(),
        source: msg.source.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      throttle: msg.throttle,
      lateral: msg.lateral,
      forward: msg.forward,
      yaw: msg.yaw,
      pitch: msg.pitch,
      roll: msg.roll,
        arm_mode: msg.arm_mode.as_str().into(),
        control_mode: msg.control_mode.as_str().into(),
        gripper_mode: msg.gripper_mode.as_str().into(),
        source: msg.source.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      throttle: msg.throttle,
      lateral: msg.lateral,
      forward: msg.forward,
      yaw: msg.yaw,
      pitch: msg.pitch,
      roll: msg.roll,
      arm_mode: msg.arm_mode.to_string(),
      control_mode: msg.control_mode.to_string(),
      gripper_mode: msg.gripper_mode.to_string(),
      source: msg.source.to_string(),
    }
  }
}


// Corresponds to orca_msgs__msg__FlareSequence

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FlareSequence {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: std::string::String,

}



impl Default for FlareSequence {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FlareSequence::default())
  }
}

impl rosidl_runtime_rs::Message for FlareSequence {
  type RmwMsg = super::msg::rmw::FlareSequence;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sequence: msg.sequence.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sequence: msg.sequence.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sequence: msg.sequence.to_string(),
    }
  }
}


// Corresponds to orca_msgs__msg__FailsafeTrigger

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FailsafeTrigger {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for FailsafeTrigger {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FailsafeTrigger::default())
  }
}

impl rosidl_runtime_rs::Message for FailsafeTrigger {
  type RmwMsg = super::msg::rmw::FailsafeTrigger;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


