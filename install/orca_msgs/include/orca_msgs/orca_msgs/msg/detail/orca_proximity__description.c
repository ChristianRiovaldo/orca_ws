// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/OrcaProximity.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/orca_proximity__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__OrcaProximity__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x47, 0x9e, 0x79, 0x3a, 0x48, 0xa9, 0x34, 0x71,
      0x32, 0xfb, 0x81, 0xac, 0x57, 0xc0, 0x3e, 0x0c,
      0x2b, 0xee, 0x51, 0xb9, 0x5e, 0x12, 0xec, 0xdd,
      0xa1, 0x6c, 0x4c, 0x1c, 0xf3, 0xbf, 0x48, 0xd6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__OrcaProximity__TYPE_NAME[] = "orca_msgs/msg/OrcaProximity";

// Define type names, field names, and default values
static char orca_msgs__msg__OrcaProximity__FIELD_NAME__arm_mode[] = "arm_mode";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__OrcaProximity__FIELDS[] = {
  {
    {orca_msgs__msg__OrcaProximity__FIELD_NAME__arm_mode, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orca_msgs__msg__OrcaProximity__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__OrcaProximity__TYPE_NAME, 27, 27},
      {orca_msgs__msg__OrcaProximity__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "#data proximity isinya boolean doang njir\n"
  "#true = arm\n"
  "#false = disarm\n"
  "\n"
  "\n"
  "bool arm_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__OrcaProximity__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__OrcaProximity__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 85, 85},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__OrcaProximity__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__OrcaProximity__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
