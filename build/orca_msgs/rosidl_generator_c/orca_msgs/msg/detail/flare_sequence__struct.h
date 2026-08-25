// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/FlareSequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/flare_sequence.h"


#ifndef ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'sequence'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/FlareSequence in the package orca_msgs.
typedef struct orca_msgs__msg__FlareSequence
{
  rosidl_runtime_c__String sequence;
} orca_msgs__msg__FlareSequence;

// Struct for a sequence of orca_msgs__msg__FlareSequence.
typedef struct orca_msgs__msg__FlareSequence__Sequence
{
  orca_msgs__msg__FlareSequence * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__FlareSequence__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__STRUCT_H_
