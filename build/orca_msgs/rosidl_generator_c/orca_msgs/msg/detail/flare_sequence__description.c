// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/FlareSequence.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/flare_sequence__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__FlareSequence__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x84, 0xab, 0x30, 0x9a, 0xb6, 0x46, 0x33, 0x9c,
      0x74, 0xd7, 0x52, 0xce, 0xfc, 0x9a, 0x99, 0x56,
      0x27, 0x68, 0x1c, 0x3d, 0xe3, 0x0e, 0x2c, 0xf3,
      0xe0, 0x7f, 0x97, 0x7b, 0xdf, 0x54, 0x14, 0x78,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__FlareSequence__TYPE_NAME[] = "orca_msgs/msg/FlareSequence";

// Define type names, field names, and default values
static char orca_msgs__msg__FlareSequence__FIELD_NAME__sequence[] = "sequence";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__FlareSequence__FIELDS[] = {
  {
    {orca_msgs__msg__FlareSequence__FIELD_NAME__sequence, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
orca_msgs__msg__FlareSequence__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__FlareSequence__TYPE_NAME, 27, 27},
      {orca_msgs__msg__FlareSequence__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string sequence";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__FlareSequence__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__FlareSequence__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 15, 15},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__FlareSequence__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__FlareSequence__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
