// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/OrcaDepth.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/orca_depth__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__OrcaDepth__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc3, 0xad, 0x13, 0xad, 0x82, 0x5f, 0x36, 0x61,
      0xb0, 0x5c, 0x51, 0xf4, 0xc2, 0x40, 0xb8, 0xb2,
      0x0c, 0xed, 0x5d, 0x04, 0x40, 0xa2, 0x81, 0xc4,
      0x4f, 0x06, 0xcb, 0x9e, 0x30, 0x5e, 0x06, 0xea,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__OrcaDepth__TYPE_NAME[] = "orca_msgs/msg/OrcaDepth";

// Define type names, field names, and default values
static char orca_msgs__msg__OrcaDepth__FIELD_NAME__depth[] = "depth";
static char orca_msgs__msg__OrcaDepth__FIELD_NAME__pressure[] = "pressure";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__OrcaDepth__FIELDS[] = {
  {
    {orca_msgs__msg__OrcaDepth__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaDepth__FIELD_NAME__pressure, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orca_msgs__msg__OrcaDepth__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__OrcaDepth__TYPE_NAME, 23, 23},
      {orca_msgs__msg__OrcaDepth__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "\n"
  "float32 depth\n"
  "float32 pressure";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__OrcaDepth__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__OrcaDepth__TYPE_NAME, 23, 23},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__OrcaDepth__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__OrcaDepth__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
