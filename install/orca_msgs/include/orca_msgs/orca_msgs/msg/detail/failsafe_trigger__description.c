// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/failsafe_trigger__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__FailsafeTrigger__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2f, 0x9f, 0x79, 0x16, 0x72, 0x4b, 0x75, 0x4e,
      0xb9, 0x84, 0x0a, 0x7b, 0xd4, 0x7b, 0x5b, 0xb9,
      0xbe, 0xcc, 0xbe, 0xa4, 0x43, 0xfe, 0xdd, 0x54,
      0x64, 0xdb, 0x64, 0x4d, 0x31, 0x0e, 0x69, 0xb0,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__FailsafeTrigger__TYPE_NAME[] = "orca_msgs/msg/FailsafeTrigger";

// Define type names, field names, and default values
static char orca_msgs__msg__FailsafeTrigger__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__FailsafeTrigger__FIELDS[] = {
  {
    {orca_msgs__msg__FailsafeTrigger__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orca_msgs__msg__FailsafeTrigger__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__FailsafeTrigger__TYPE_NAME, 29, 29},
      {orca_msgs__msg__FailsafeTrigger__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}


static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__FailsafeTrigger__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__FailsafeTrigger__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__FailsafeTrigger__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__FailsafeTrigger__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
