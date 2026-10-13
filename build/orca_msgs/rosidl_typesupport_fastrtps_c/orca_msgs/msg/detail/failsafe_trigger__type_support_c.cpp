// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/failsafe_trigger__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "orca_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "orca_msgs/msg/detail/failsafe_trigger__struct.h"
#include "orca_msgs/msg/detail/failsafe_trigger__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _FailsafeTrigger__ros_msg_type = orca_msgs__msg__FailsafeTrigger;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_orca_msgs__msg__FailsafeTrigger(
  const orca_msgs__msg__FailsafeTrigger * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_deserialize_orca_msgs__msg__FailsafeTrigger(
  eprosima::fastcdr::Cdr & cdr,
  orca_msgs__msg__FailsafeTrigger * ros_message)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_orca_msgs__msg__FailsafeTrigger(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FailsafeTrigger__ros_msg_type * ros_message = static_cast<const _FailsafeTrigger__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_orca_msgs__msg__FailsafeTrigger(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: structure_needs_at_least_one_member
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orca_msgs__msg__FailsafeTrigger;
    is_plain =
      (
      offsetof(DataType, structure_needs_at_least_one_member) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_key_orca_msgs__msg__FailsafeTrigger(
  const orca_msgs__msg__FailsafeTrigger * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_key_orca_msgs__msg__FailsafeTrigger(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FailsafeTrigger__ros_msg_type * ros_message = static_cast<const _FailsafeTrigger__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_key_orca_msgs__msg__FailsafeTrigger(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: structure_needs_at_least_one_member
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orca_msgs__msg__FailsafeTrigger;
    is_plain =
      (
      offsetof(DataType, structure_needs_at_least_one_member) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FailsafeTrigger__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const orca_msgs__msg__FailsafeTrigger * ros_message = static_cast<const orca_msgs__msg__FailsafeTrigger *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_orca_msgs__msg__FailsafeTrigger(ros_message, cdr);
}

static bool _FailsafeTrigger__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  orca_msgs__msg__FailsafeTrigger * ros_message = static_cast<orca_msgs__msg__FailsafeTrigger *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_orca_msgs__msg__FailsafeTrigger(cdr, ros_message);
}

static uint32_t _FailsafeTrigger__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_orca_msgs__msg__FailsafeTrigger(
      untyped_ros_message, 0));
}

static size_t _FailsafeTrigger__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_orca_msgs__msg__FailsafeTrigger(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FailsafeTrigger = {
  "orca_msgs::msg",
  "FailsafeTrigger",
  _FailsafeTrigger__cdr_serialize,
  _FailsafeTrigger__cdr_deserialize,
  _FailsafeTrigger__get_serialized_size,
  _FailsafeTrigger__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FailsafeTrigger__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FailsafeTrigger,
  get_message_typesupport_handle_function,
  &orca_msgs__msg__FailsafeTrigger__get_type_hash,
  &orca_msgs__msg__FailsafeTrigger__get_type_description,
  &orca_msgs__msg__FailsafeTrigger__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, orca_msgs, msg, FailsafeTrigger)() {
  return &_FailsafeTrigger__type_support;
}

#if defined(__cplusplus)
}
#endif
