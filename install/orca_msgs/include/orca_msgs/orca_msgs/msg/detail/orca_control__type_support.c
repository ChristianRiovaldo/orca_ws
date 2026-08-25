// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from orca_msgs:msg/OrcaControl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "orca_msgs/msg/detail/orca_control__rosidl_typesupport_introspection_c.h"
#include "orca_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "orca_msgs/msg/detail/orca_control__functions.h"
#include "orca_msgs/msg/detail/orca_control__struct.h"


// Include directives for member types
// Member `arm_mode`
// Member `control_mode`
// Member `gripper_mode`
// Member `source`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  orca_msgs__msg__OrcaControl__init(message_memory);
}

void orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_fini_function(void * message_memory)
{
  orca_msgs__msg__OrcaControl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_member_array[8] = {
  {
    "throttle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, throttle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lateral",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, lateral),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "forward",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, forward),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "arm_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, arm_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gripper_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, gripper_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "source",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(orca_msgs__msg__OrcaControl, source),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_members = {
  "orca_msgs__msg",  // message namespace
  "OrcaControl",  // message name
  8,  // number of fields
  sizeof(orca_msgs__msg__OrcaControl),
  false,  // has_any_key_member_
  orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_member_array,  // message members
  orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_init_function,  // function to initialize message memory (memory has to be allocated)
  orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_type_support_handle = {
  0,
  &orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_members,
  get_message_typesupport_handle_function,
  &orca_msgs__msg__OrcaControl__get_type_hash,
  &orca_msgs__msg__OrcaControl__get_type_description,
  &orca_msgs__msg__OrcaControl__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_orca_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, orca_msgs, msg, OrcaControl)() {
  if (!orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_type_support_handle.typesupport_identifier) {
    orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &orca_msgs__msg__OrcaControl__rosidl_typesupport_introspection_c__OrcaControl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
