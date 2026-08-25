// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_attitude.h"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/OrcaAttitude in the package orca_msgs.
typedef struct orca_msgs__msg__OrcaAttitude
{
  float initial_x;
  float initial_y;
  float initial_z;
  float yaw_deg;
  float initial_deg;
  float roll_deg;
  float pitch_deg;
  float rollspeed_deg_s;
  float pitchspeed_deg_s;
  float yawspeed_deg_s;
} orca_msgs__msg__OrcaAttitude;

// Struct for a sequence of orca_msgs__msg__OrcaAttitude.
typedef struct orca_msgs__msg__OrcaAttitude__Sequence
{
  orca_msgs__msg__OrcaAttitude * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__OrcaAttitude__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__STRUCT_H_
