// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/OrcaControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_control.h"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'arm_mode'
// Member 'control_mode'
// Member 'gripper_mode'
// Member 'source'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/OrcaControl in the package orca_msgs.
typedef struct orca_msgs__msg__OrcaControl
{
  int16_t throttle;
  int16_t lateral;
  int16_t forward;
  int16_t yaw;
  int16_t pitch;
  int16_t roll;
  rosidl_runtime_c__String arm_mode;
  rosidl_runtime_c__String control_mode;
  rosidl_runtime_c__String gripper_mode;
  rosidl_runtime_c__String source;
} orca_msgs__msg__OrcaControl;

// Struct for a sequence of orca_msgs__msg__OrcaControl.
typedef struct orca_msgs__msg__OrcaControl__Sequence
{
  orca_msgs__msg__OrcaControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__OrcaControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__STRUCT_H_
