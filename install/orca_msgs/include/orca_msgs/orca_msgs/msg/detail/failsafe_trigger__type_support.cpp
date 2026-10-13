// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "orca_msgs/msg/detail/failsafe_trigger__functions.h"
#include "orca_msgs/msg/detail/failsafe_trigger__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace orca_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FailsafeTrigger_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) orca_msgs::msg::FailsafeTrigger(_init);
}

void FailsafeTrigger_fini_function(void * message_memory)
{
  auto typed_message = static_cast<orca_msgs::msg::FailsafeTrigger *>(message_memory);
  typed_message->~FailsafeTrigger();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FailsafeTrigger_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs::msg::FailsafeTrigger, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FailsafeTrigger_message_members = {
  "orca_msgs::msg",  // message namespace
  "FailsafeTrigger",  // message name
  1,  // number of fields
  sizeof(orca_msgs::msg::FailsafeTrigger),
  false,  // has_any_key_member_
  FailsafeTrigger_message_member_array,  // message members
  FailsafeTrigger_init_function,  // function to initialize message memory (memory has to be allocated)
  FailsafeTrigger_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FailsafeTrigger_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FailsafeTrigger_message_members,
  get_message_typesupport_handle_function,
  &orca_msgs__msg__FailsafeTrigger__get_type_hash,
  &orca_msgs__msg__FailsafeTrigger__get_type_description,
  &orca_msgs__msg__FailsafeTrigger__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace orca_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<orca_msgs::msg::FailsafeTrigger>()
{
  return &::orca_msgs::msg::rosidl_typesupport_introspection_cpp::FailsafeTrigger_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, orca_msgs, msg, FailsafeTrigger)() {
  return &::orca_msgs::msg::rosidl_typesupport_introspection_cpp::FailsafeTrigger_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
