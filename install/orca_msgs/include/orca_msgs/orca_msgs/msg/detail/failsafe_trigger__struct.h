// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/failsafe_trigger.h"


#ifndef ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__STRUCT_H_
#define ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/FailsafeTrigger in the package orca_msgs.
typedef struct orca_msgs__msg__FailsafeTrigger
{
  uint8_t structure_needs_at_least_one_member;
} orca_msgs__msg__FailsafeTrigger;

// Struct for a sequence of orca_msgs__msg__FailsafeTrigger.
typedef struct orca_msgs__msg__FailsafeTrigger__Sequence
{
  orca_msgs__msg__FailsafeTrigger * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} orca_msgs__msg__FailsafeTrigger__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__STRUCT_H_
