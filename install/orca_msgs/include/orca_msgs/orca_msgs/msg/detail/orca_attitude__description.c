// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/orca_attitude__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__OrcaAttitude__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xed, 0x89, 0x72, 0x03, 0x1b, 0xcf, 0xaf, 0x48,
      0x95, 0x63, 0x55, 0x7d, 0xf1, 0x61, 0x0b, 0xa9,
      0x8b, 0x3f, 0xac, 0xf2, 0x58, 0xcd, 0x11, 0xfc,
      0x74, 0x52, 0x11, 0xb9, 0xda, 0x61, 0xc3, 0x80,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__OrcaAttitude__TYPE_NAME[] = "orca_msgs/msg/OrcaAttitude";

// Define type names, field names, and default values
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_x[] = "initial_x";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_y[] = "initial_y";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_z[] = "initial_z";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__yaw_deg[] = "yaw_deg";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_deg[] = "initial_deg";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__roll_deg[] = "roll_deg";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__pitch_deg[] = "pitch_deg";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__rollspeed_deg_s[] = "rollspeed_deg_s";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__pitchspeed_deg_s[] = "pitchspeed_deg_s";
static char orca_msgs__msg__OrcaAttitude__FIELD_NAME__yawspeed_deg_s[] = "yawspeed_deg_s";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__OrcaAttitude__FIELDS[] = {
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_x, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_y, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_z, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__yaw_deg, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__initial_deg, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__roll_deg, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__pitch_deg, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__rollspeed_deg_s, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__pitchspeed_deg_s, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__OrcaAttitude__FIELD_NAME__yawspeed_deg_s, 14, 14},
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
orca_msgs__msg__OrcaAttitude__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__OrcaAttitude__TYPE_NAME, 26, 26},
      {orca_msgs__msg__OrcaAttitude__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 initial_x\n"
  "float32 initial_y\n"
  "float32 initial_z\n"
  "\n"
  "float32 yaw_deg\n"
  "float32 initial_deg\n"
  "\n"
  "float32 roll_deg\n"
  "float32 pitch_deg\n"
  "float32 rollspeed_deg_s\n"
  "float32 pitchspeed_deg_s\n"
  "float32 yawspeed_deg_s";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__OrcaAttitude__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__OrcaAttitude__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 199, 199},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__OrcaAttitude__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__OrcaAttitude__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
