#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FinalDetection() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__FinalDetection__init(msg: *mut FinalDetection) -> bool;
    fn orca_msgs__msg__FinalDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FinalDetection>, size: usize) -> bool;
    fn orca_msgs__msg__FinalDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FinalDetection>);
    fn orca_msgs__msg__FinalDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FinalDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<FinalDetection>) -> bool;
}

// Corresponds to orca_msgs__msg__FinalDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FinalDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__FinalDetection__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__FinalDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FinalDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FinalDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FinalDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FinalDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FinalDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FinalDetection where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/FinalDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FinalDetection() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__GateDetection() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__GateDetection__init(msg: *mut GateDetection) -> bool;
    fn orca_msgs__msg__GateDetection__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GateDetection>, size: usize) -> bool;
    fn orca_msgs__msg__GateDetection__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GateDetection>);
    fn orca_msgs__msg__GateDetection__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GateDetection>, out_seq: *mut rosidl_runtime_rs::Sequence<GateDetection>) -> bool;
}

// Corresponds to orca_msgs__msg__GateDetection
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GateDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub class_name: rosidl_runtime_rs::String,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__GateDetection__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__GateDetection__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GateDetection {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__GateDetection__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__GateDetection__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__GateDetection__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GateDetection {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GateDetection where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/GateDetection";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__GateDetection() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaDepth() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__OrcaDepth__init(msg: *mut OrcaDepth) -> bool;
    fn orca_msgs__msg__OrcaDepth__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OrcaDepth>, size: usize) -> bool;
    fn orca_msgs__msg__OrcaDepth__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OrcaDepth>);
    fn orca_msgs__msg__OrcaDepth__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OrcaDepth>, out_seq: *mut rosidl_runtime_rs::Sequence<OrcaDepth>) -> bool;
}

// Corresponds to orca_msgs__msg__OrcaDepth
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__OrcaDepth__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__OrcaDepth__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OrcaDepth {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaDepth__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaDepth__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaDepth__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OrcaDepth {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OrcaDepth where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/OrcaDepth";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaDepth() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaAttitude() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__OrcaAttitude__init(msg: *mut OrcaAttitude) -> bool;
    fn orca_msgs__msg__OrcaAttitude__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OrcaAttitude>, size: usize) -> bool;
    fn orca_msgs__msg__OrcaAttitude__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OrcaAttitude>);
    fn orca_msgs__msg__OrcaAttitude__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OrcaAttitude>, out_seq: *mut rosidl_runtime_rs::Sequence<OrcaAttitude>) -> bool;
}

// Corresponds to orca_msgs__msg__OrcaAttitude
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__OrcaAttitude__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__OrcaAttitude__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OrcaAttitude {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaAttitude__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaAttitude__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaAttitude__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OrcaAttitude {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OrcaAttitude where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/OrcaAttitude";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaAttitude() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaProximity() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__OrcaProximity__init(msg: *mut OrcaProximity) -> bool;
    fn orca_msgs__msg__OrcaProximity__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OrcaProximity>, size: usize) -> bool;
    fn orca_msgs__msg__OrcaProximity__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OrcaProximity>);
    fn orca_msgs__msg__OrcaProximity__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OrcaProximity>, out_seq: *mut rosidl_runtime_rs::Sequence<OrcaProximity>) -> bool;
}

// Corresponds to orca_msgs__msg__OrcaProximity
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// data proximity isinya boolean doang njir
/// true = arm
/// false = disarm

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrcaProximity {

    // This member is not documented.
    #[allow(missing_docs)]
    pub arm_mode: bool,

}



impl Default for OrcaProximity {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__OrcaProximity__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__OrcaProximity__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OrcaProximity {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaProximity__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaProximity__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaProximity__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OrcaProximity {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OrcaProximity where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/OrcaProximity";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaProximity() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaControl() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__OrcaControl__init(msg: *mut OrcaControl) -> bool;
    fn orca_msgs__msg__OrcaControl__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<OrcaControl>, size: usize) -> bool;
    fn orca_msgs__msg__OrcaControl__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<OrcaControl>);
    fn orca_msgs__msg__OrcaControl__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<OrcaControl>, out_seq: *mut rosidl_runtime_rs::Sequence<OrcaControl>) -> bool;
}

// Corresponds to orca_msgs__msg__OrcaControl
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    pub arm_mode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub control_mode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gripper_mode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub source: rosidl_runtime_rs::String,

}



impl Default for OrcaControl {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__OrcaControl__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__OrcaControl__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for OrcaControl {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaControl__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaControl__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__OrcaControl__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for OrcaControl {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for OrcaControl where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/OrcaControl";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__OrcaControl() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FlareSequence() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__FlareSequence__init(msg: *mut FlareSequence) -> bool;
    fn orca_msgs__msg__FlareSequence__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FlareSequence>, size: usize) -> bool;
    fn orca_msgs__msg__FlareSequence__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FlareSequence>);
    fn orca_msgs__msg__FlareSequence__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FlareSequence>, out_seq: *mut rosidl_runtime_rs::Sequence<FlareSequence>) -> bool;
}

// Corresponds to orca_msgs__msg__FlareSequence
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FlareSequence {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sequence: rosidl_runtime_rs::String,

}



impl Default for FlareSequence {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__FlareSequence__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__FlareSequence__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FlareSequence {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FlareSequence__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FlareSequence__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FlareSequence__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FlareSequence {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FlareSequence where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/FlareSequence";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FlareSequence() }
  }
}


#[link(name = "orca_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FailsafeTrigger() -> *const std::ffi::c_void;
}

#[link(name = "orca_msgs__rosidl_generator_c")]
extern "C" {
    fn orca_msgs__msg__FailsafeTrigger__init(msg: *mut FailsafeTrigger) -> bool;
    fn orca_msgs__msg__FailsafeTrigger__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FailsafeTrigger>, size: usize) -> bool;
    fn orca_msgs__msg__FailsafeTrigger__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FailsafeTrigger>);
    fn orca_msgs__msg__FailsafeTrigger__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FailsafeTrigger>, out_seq: *mut rosidl_runtime_rs::Sequence<FailsafeTrigger>) -> bool;
}

// Corresponds to orca_msgs__msg__FailsafeTrigger
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FailsafeTrigger {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for FailsafeTrigger {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !orca_msgs__msg__FailsafeTrigger__init(&mut msg as *mut _) {
        panic!("Call to orca_msgs__msg__FailsafeTrigger__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FailsafeTrigger {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FailsafeTrigger__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FailsafeTrigger__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { orca_msgs__msg__FailsafeTrigger__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FailsafeTrigger {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FailsafeTrigger where Self: Sized {
  const TYPE_NAME: &'static str = "orca_msgs/msg/FailsafeTrigger";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__orca_msgs__msg__FailsafeTrigger() }
  }
}


