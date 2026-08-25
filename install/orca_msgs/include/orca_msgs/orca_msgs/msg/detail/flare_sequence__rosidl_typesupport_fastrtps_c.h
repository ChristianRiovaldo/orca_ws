// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from orca_msgs:msg/FlareSequence.idl
// generated code does not contain a copyright notice
#ifndef ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "orca_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "orca_msgs/msg/detail/flare_sequence__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_orca_msgs__msg__FlareSequence(
  const orca_msgs__msg__FlareSequence * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_deserialize_orca_msgs__msg__FlareSequence(
  eprosima::fastcdr::Cdr &,
  orca_msgs__msg__FlareSequence * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_orca_msgs__msg__FlareSequence(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_orca_msgs__msg__FlareSequence(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_key_orca_msgs__msg__FlareSequence(
  const orca_msgs__msg__FlareSequence * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_key_orca_msgs__msg__FlareSequence(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_key_orca_msgs__msg__FlareSequence(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, orca_msgs, msg, FlareSequence)();

#ifdef __cplusplus
}
#endif

#endif  // ORCA_MSGS__MSG__DETAIL__FLARE_SEQUENCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
