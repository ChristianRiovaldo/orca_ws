// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/GateDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/gate_detection.h"


#ifndef ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'class_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/GateDetection in the package orca_msgs.
typedef struct orca_msgs__msg__GateDetection
{
  bool detected;
  rosidl_runtime_c__String class_name;
  float confidence;
  float center_x;
  float center_y;
  float center_x_norm;
  float bbox_width;
  float bbox_height;
  float bbox_area_ratio;
  float distance;
} orca_msgs__msg__GateDetection;

// Struct for a sequence of orca_msgs__msg__GateDetection.
typedef struct orca_msgs__msg__GateDetection__Sequence
{
  orca_msgs__msg__GateDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__GateDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__STRUCT_H_
