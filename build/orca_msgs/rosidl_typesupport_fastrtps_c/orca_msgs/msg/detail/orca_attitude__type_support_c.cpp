// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_attitude__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "orca_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "orca_msgs/msg/detail/orca_attitude__struct.h"
#include "orca_msgs/msg/detail/orca_attitude__functions.h"
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


using _OrcaAttitude__ros_msg_type = orca_msgs__msg__OrcaAttitude;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_orca_msgs__msg__OrcaAttitude(
  const orca_msgs__msg__OrcaAttitude * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: initial_x
  {
    cdr << ros_message->initial_x;
  }

  // Field name: initial_y
  {
    cdr << ros_message->initial_y;
  }

  // Field name: initial_z
  {
    cdr << ros_message->initial_z;
  }

  // Field name: yaw_deg
  {
    cdr << ros_message->yaw_deg;
  }

  // Field name: initial_deg
  {
    cdr << ros_message->initial_deg;
  }

  // Field name: roll_deg
  {
    cdr << ros_message->roll_deg;
  }

  // Field name: pitch_deg
  {
    cdr << ros_message->pitch_deg;
  }

  // Field name: rollspeed_deg_s
  {
    cdr << ros_message->rollspeed_deg_s;
  }

  // Field name: pitchspeed_deg_s
  {
    cdr << ros_message->pitchspeed_deg_s;
  }

  // Field name: yawspeed_deg_s
  {
    cdr << ros_message->yawspeed_deg_s;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_deserialize_orca_msgs__msg__OrcaAttitude(
  eprosima::fastcdr::Cdr & cdr,
  orca_msgs__msg__OrcaAttitude * ros_message)
{
  // Field name: initial_x
  {
    cdr >> ros_message->initial_x;
  }

  // Field name: initial_y
  {
    cdr >> ros_message->initial_y;
  }

  // Field name: initial_z
  {
    cdr >> ros_message->initial_z;
  }

  // Field name: yaw_deg
  {
    cdr >> ros_message->yaw_deg;
  }

  // Field name: initial_deg
  {
    cdr >> ros_message->initial_deg;
  }

  // Field name: roll_deg
  {
    cdr >> ros_message->roll_deg;
  }

  // Field name: pitch_deg
  {
    cdr >> ros_message->pitch_deg;
  }

  // Field name: rollspeed_deg_s
  {
    cdr >> ros_message->rollspeed_deg_s;
  }

  // Field name: pitchspeed_deg_s
  {
    cdr >> ros_message->pitchspeed_deg_s;
  }

  // Field name: yawspeed_deg_s
  {
    cdr >> ros_message->yawspeed_deg_s;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_orca_msgs__msg__OrcaAttitude(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrcaAttitude__ros_msg_type * ros_message = static_cast<const _OrcaAttitude__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: initial_x
  {
    size_t item_size = sizeof(ros_message->initial_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_y
  {
    size_t item_size = sizeof(ros_message->initial_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_z
  {
    size_t item_size = sizeof(ros_message->initial_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_deg
  {
    size_t item_size = sizeof(ros_message->yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_deg
  {
    size_t item_size = sizeof(ros_message->initial_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll_deg
  {
    size_t item_size = sizeof(ros_message->roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch_deg
  {
    size_t item_size = sizeof(ros_message->pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rollspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->rollspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitchspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->pitchspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yawspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->yawspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_orca_msgs__msg__OrcaAttitude(
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

  // Field name: initial_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rollspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pitchspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yawspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orca_msgs__msg__OrcaAttitude;
    is_plain =
      (
      offsetof(DataType, yawspeed_deg_s) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
bool cdr_serialize_key_orca_msgs__msg__OrcaAttitude(
  const orca_msgs__msg__OrcaAttitude * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: initial_x
  {
    cdr << ros_message->initial_x;
  }

  // Field name: initial_y
  {
    cdr << ros_message->initial_y;
  }

  // Field name: initial_z
  {
    cdr << ros_message->initial_z;
  }

  // Field name: yaw_deg
  {
    cdr << ros_message->yaw_deg;
  }

  // Field name: initial_deg
  {
    cdr << ros_message->initial_deg;
  }

  // Field name: roll_deg
  {
    cdr << ros_message->roll_deg;
  }

  // Field name: pitch_deg
  {
    cdr << ros_message->pitch_deg;
  }

  // Field name: rollspeed_deg_s
  {
    cdr << ros_message->rollspeed_deg_s;
  }

  // Field name: pitchspeed_deg_s
  {
    cdr << ros_message->pitchspeed_deg_s;
  }

  // Field name: yawspeed_deg_s
  {
    cdr << ros_message->yawspeed_deg_s;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t get_serialized_size_key_orca_msgs__msg__OrcaAttitude(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrcaAttitude__ros_msg_type * ros_message = static_cast<const _OrcaAttitude__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: initial_x
  {
    size_t item_size = sizeof(ros_message->initial_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_y
  {
    size_t item_size = sizeof(ros_message->initial_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_z
  {
    size_t item_size = sizeof(ros_message->initial_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw_deg
  {
    size_t item_size = sizeof(ros_message->yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: initial_deg
  {
    size_t item_size = sizeof(ros_message->initial_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll_deg
  {
    size_t item_size = sizeof(ros_message->roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch_deg
  {
    size_t item_size = sizeof(ros_message->pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rollspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->rollspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitchspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->pitchspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yawspeed_deg_s
  {
    size_t item_size = sizeof(ros_message->yawspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_orca_msgs
size_t max_serialized_size_key_orca_msgs__msg__OrcaAttitude(
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
  // Field name: initial_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: initial_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rollspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: pitchspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: yawspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = orca_msgs__msg__OrcaAttitude;
    is_plain =
      (
      offsetof(DataType, yawspeed_deg_s) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _OrcaAttitude__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const orca_msgs__msg__OrcaAttitude * ros_message = static_cast<const orca_msgs__msg__OrcaAttitude *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_orca_msgs__msg__OrcaAttitude(ros_message, cdr);
}

static bool _OrcaAttitude__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  orca_msgs__msg__OrcaAttitude * ros_message = static_cast<orca_msgs__msg__OrcaAttitude *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_orca_msgs__msg__OrcaAttitude(cdr, ros_message);
}

static uint32_t _OrcaAttitude__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_orca_msgs__msg__OrcaAttitude(
      untyped_ros_message, 0));
}

static size_t _OrcaAttitude__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_orca_msgs__msg__OrcaAttitude(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OrcaAttitude = {
  "orca_msgs::msg",
  "OrcaAttitude",
  _OrcaAttitude__cdr_serialize,
  _OrcaAttitude__cdr_deserialize,
  _OrcaAttitude__get_serialized_size,
  _OrcaAttitude__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _OrcaAttitude__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OrcaAttitude,
  get_message_typesupport_handle_function,
  &orca_msgs__msg__OrcaAttitude__get_type_hash,
  &orca_msgs__msg__OrcaAttitude__get_type_description,
  &orca_msgs__msg__OrcaAttitude__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, orca_msgs, msg, OrcaAttitude)() {
  return &_OrcaAttitude__type_support;
}

#if defined(__cplusplus)
}
#endif
