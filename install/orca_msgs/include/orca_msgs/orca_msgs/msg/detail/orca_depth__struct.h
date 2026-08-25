// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/OrcaDepth.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_depth.h"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/OrcaDepth in the package orca_msgs.
typedef struct orca_msgs__msg__OrcaDepth
{
  float depth;
  float pressure;
} orca_msgs__msg__OrcaDepth;

// Struct for a sequence of orca_msgs__msg__OrcaDepth.
typedef struct orca_msgs__msg__OrcaDepth__Sequence
{
  orca_msgs__msg__OrcaDepth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__OrcaDepth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__STRUCT_H_
