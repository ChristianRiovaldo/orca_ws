// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice
#include "orca_msgs/msg/detail/orca_attitude__rosidl_typesupport_fastrtps_cpp.hpp"
#include "orca_msgs/msg/detail/orca_attitude__functions.h"
#include "orca_msgs/msg/detail/orca_attitude__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace orca_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
cdr_serialize(
  const orca_msgs::msg::OrcaAttitude & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: initial_x
  cdr << ros_message.initial_x;

  // Member: initial_y
  cdr << ros_message.initial_y;

  // Member: initial_z
  cdr << ros_message.initial_z;

  // Member: yaw_deg
  cdr << ros_message.yaw_deg;

  // Member: initial_deg
  cdr << ros_message.initial_deg;

  // Member: roll_deg
  cdr << ros_message.roll_deg;

  // Member: pitch_deg
  cdr << ros_message.pitch_deg;

  // Member: rollspeed_deg_s
  cdr << ros_message.rollspeed_deg_s;

  // Member: pitchspeed_deg_s
  cdr << ros_message.pitchspeed_deg_s;

  // Member: yawspeed_deg_s
  cdr << ros_message.yawspeed_deg_s;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  orca_msgs::msg::OrcaAttitude & ros_message)
{
  // Member: initial_x
  cdr >> ros_message.initial_x;

  // Member: initial_y
  cdr >> ros_message.initial_y;

  // Member: initial_z
  cdr >> ros_message.initial_z;

  // Member: yaw_deg
  cdr >> ros_message.yaw_deg;

  // Member: initial_deg
  cdr >> ros_message.initial_deg;

  // Member: roll_deg
  cdr >> ros_message.roll_deg;

  // Member: pitch_deg
  cdr >> ros_message.pitch_deg;

  // Member: rollspeed_deg_s
  cdr >> ros_message.rollspeed_deg_s;

  // Member: pitchspeed_deg_s
  cdr >> ros_message.pitchspeed_deg_s;

  // Member: yawspeed_deg_s
  cdr >> ros_message.yawspeed_deg_s;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
get_serialized_size(
  const orca_msgs::msg::OrcaAttitude & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: initial_x
  {
    size_t item_size = sizeof(ros_message.initial_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_y
  {
    size_t item_size = sizeof(ros_message.initial_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_z
  {
    size_t item_size = sizeof(ros_message.initial_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw_deg
  {
    size_t item_size = sizeof(ros_message.yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_deg
  {
    size_t item_size = sizeof(ros_message.initial_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: roll_deg
  {
    size_t item_size = sizeof(ros_message.roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitch_deg
  {
    size_t item_size = sizeof(ros_message.pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rollspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.rollspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitchspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.pitchspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yawspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.yawspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
max_serialized_size_OrcaAttitude(
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

  // Member: initial_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: initial_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: initial_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: initial_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: rollspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: pitchspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: yawspeed_deg_s
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
    using DataType = orca_msgs::msg::OrcaAttitude;
    is_plain =
      (
      offsetof(DataType, yawspeed_deg_s) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
cdr_serialize_key(
  const orca_msgs::msg::OrcaAttitude & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: initial_x
  cdr << ros_message.initial_x;

  // Member: initial_y
  cdr << ros_message.initial_y;

  // Member: initial_z
  cdr << ros_message.initial_z;

  // Member: yaw_deg
  cdr << ros_message.yaw_deg;

  // Member: initial_deg
  cdr << ros_message.initial_deg;

  // Member: roll_deg
  cdr << ros_message.roll_deg;

  // Member: pitch_deg
  cdr << ros_message.pitch_deg;

  // Member: rollspeed_deg_s
  cdr << ros_message.rollspeed_deg_s;

  // Member: pitchspeed_deg_s
  cdr << ros_message.pitchspeed_deg_s;

  // Member: yawspeed_deg_s
  cdr << ros_message.yawspeed_deg_s;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
get_serialized_size_key(
  const orca_msgs::msg::OrcaAttitude & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: initial_x
  {
    size_t item_size = sizeof(ros_message.initial_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_y
  {
    size_t item_size = sizeof(ros_message.initial_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_z
  {
    size_t item_size = sizeof(ros_message.initial_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yaw_deg
  {
    size_t item_size = sizeof(ros_message.yaw_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: initial_deg
  {
    size_t item_size = sizeof(ros_message.initial_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: roll_deg
  {
    size_t item_size = sizeof(ros_message.roll_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitch_deg
  {
    size_t item_size = sizeof(ros_message.pitch_deg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: rollspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.rollspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: pitchspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.pitchspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: yawspeed_deg_s
  {
    size_t item_size = sizeof(ros_message.yawspeed_deg_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_orca_msgs
max_serialized_size_key_OrcaAttitude(
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

  // Member: initial_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: initial_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: initial_z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: initial_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: roll_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pitch_deg
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rollspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: pitchspeed_deg_s
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yawspeed_deg_s
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
    using DataType = orca_msgs::msg::OrcaAttitude;
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
  auto typed_message =
    static_cast<const orca_msgs::msg::OrcaAttitude *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _OrcaAttitude__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<orca_msgs::msg::OrcaAttitude *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _OrcaAttitude__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const orca_msgs::msg::OrcaAttitude *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _OrcaAttitude__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_OrcaAttitude(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _OrcaAttitude__callbacks = {
  "orca_msgs::msg",
  "OrcaAttitude",
  _OrcaAttitude__cdr_serialize,
  _OrcaAttitude__cdr_deserialize,
  _OrcaAttitude__get_serialized_size,
  _OrcaAttitude__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _OrcaAttitude__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_OrcaAttitude__callbacks,
  get_message_typesupport_handle_function,
  &orca_msgs__msg__OrcaAttitude__get_type_hash,
  &orca_msgs__msg__OrcaAttitude__get_type_description,
  &orca_msgs__msg__OrcaAttitude__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace orca_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_orca_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<orca_msgs::msg::OrcaAttitude>()
{
  return &orca_msgs::msg::typesupport_fastrtps_cpp::_OrcaAttitude__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, orca_msgs, msg, OrcaAttitude)() {
  return &orca_msgs::msg::typesupport_fastrtps_cpp::_OrcaAttitude__handle;
}

#ifdef __cplusplus
}
#endif
