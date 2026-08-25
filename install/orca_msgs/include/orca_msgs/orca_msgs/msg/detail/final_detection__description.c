// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from orca_msgs:msg/FinalDetection.idl
// generated code does not contain a copyright notice

#include "orca_msgs/msg/detail/final_detection__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_orca_msgs
const rosidl_type_hash_t *
orca_msgs__msg__FinalDetection__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x97, 0x79, 0x72, 0xea, 0xad, 0x62, 0x44, 0x55,
      0x73, 0x48, 0xd0, 0xf5, 0xeb, 0xf8, 0x1f, 0x39,
      0xff, 0x62, 0x0d, 0xb4, 0xe9, 0x9e, 0x87, 0x77,
      0xdb, 0xd2, 0x12, 0xfb, 0x95, 0x90, 0xdd, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char orca_msgs__msg__FinalDetection__TYPE_NAME[] = "orca_msgs/msg/FinalDetection";

// Define type names, field names, and default values
static char orca_msgs__msg__FinalDetection__FIELD_NAME__detected[] = "detected";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__class_name[] = "class_name";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__confidence[] = "confidence";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__center_x[] = "center_x";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__center_y[] = "center_y";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__center_x_norm[] = "center_x_norm";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_width[] = "bbox_width";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_height[] = "bbox_height";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_area_ratio[] = "bbox_area_ratio";
static char orca_msgs__msg__FinalDetection__FIELD_NAME__distance[] = "distance";

static rosidl_runtime_c__type_description__Field orca_msgs__msg__FinalDetection__FIELDS[] = {
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__detected, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__class_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__confidence, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__center_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__center_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__center_x_norm, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_width, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_height, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__bbox_area_ratio, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {orca_msgs__msg__FinalDetection__FIELD_NAME__distance, 8, 8},
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
orca_msgs__msg__FinalDetection__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {orca_msgs__msg__FinalDetection__TYPE_NAME, 28, 28},
      {orca_msgs__msg__FinalDetection__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool detected\n"
  "string class_name\n"
  "float32 confidence\n"
  "float32 center_x\n"
  "float32 center_y\n"
  "float32 center_x_norm\n"
  "float32 bbox_width\n"
  "float32 bbox_height\n"
  "float32 bbox_area_ratio\n"
  "float32 distance";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
orca_msgs__msg__FinalDetection__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {orca_msgs__msg__FinalDetection__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 186, 186},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
orca_msgs__msg__FinalDetection__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *orca_msgs__msg__FinalDetection__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
