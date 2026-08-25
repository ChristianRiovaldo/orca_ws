// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/OrcaProximity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_proximity.h"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/OrcaProximity in the package orca_msgs.
/**
  * data proximity isinya boolean doang njir
  * true = arm
  * false = disarm
 */
typedef struct orca_msgs__msg__OrcaProximity
{
  bool arm_mode;
} orca_msgs__msg__OrcaProximity;

// Struct for a sequence of orca_msgs__msg__OrcaProximity.
typedef struct orca_msgs__msg__OrcaProximity__Sequence
{
  orca_msgs__msg__OrcaProximity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__OrcaProximity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__STRUCT_H_
