// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orca_msgs:msg/GateDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/gate_detection.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_
#define ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orca_msgs/msg/detail/gate_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orca_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GateDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << ", ";
  }

  // member: center_x_norm
  {
    out << "center_x_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x_norm, out);
    out << ", ";
  }

  // member: bbox_width
  {
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << ", ";
  }

  // member: bbox_height
  {
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
    out << ", ";
  }

  // member: bbox_area_ratio
  {
    out << "bbox_area_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_area_ratio, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GateDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }

  // member: class_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << "\n";
  }

  // member: center_x_norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x_norm, out);
    out << "\n";
  }

  // member: bbox_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << "\n";
  }

  // member: bbox_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
    out << "\n";
  }

  // member: bbox_area_ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_area_ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_area_ratio, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GateDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace orca_msgs

namespace rosidl_generator_traits
{

[[deprecated("use orca_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const orca_msgs::msg::GateDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  orca_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orca_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const orca_msgs::msg::GateDetection & msg)
{
  return orca_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orca_msgs::msg::GateDetection>()
{
  return "orca_msgs::msg::GateDetection";
}

template<>
inline const char * name<orca_msgs::msg::GateDetection>()
{
  return "orca_msgs/msg/GateDetection";
}

template<>
struct has_fixed_size<orca_msgs::msg::GateDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<orca_msgs::msg::GateDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<orca_msgs::msg::GateDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORCA_MSGS__MSG__DETAIL__GATE_DETECTION__TRAITS_HPP_
