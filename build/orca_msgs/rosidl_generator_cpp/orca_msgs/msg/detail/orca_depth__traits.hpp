// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orca_msgs:msg/OrcaDepth.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_depth.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__TRAITS_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orca_msgs/msg/detail/orca_depth__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orca_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrcaDepth & msg,
  std::ostream & out)
{
  out << "{";
  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

  // member: pressure
  {
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrcaDepth & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << "\n";
  }

  // member: pressure
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pressure: ";
    rosidl_generator_traits::value_to_yaml(msg.pressure, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrcaDepth & msg, bool use_flow_style = false)
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
  const orca_msgs::msg::OrcaDepth & msg,
  std::ostream & out, size_t indentation = 0)
{
  orca_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orca_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const orca_msgs::msg::OrcaDepth & msg)
{
  return orca_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orca_msgs::msg::OrcaDepth>()
{
  return "orca_msgs::msg::OrcaDepth";
}

template<>
inline const char * name<orca_msgs::msg::OrcaDepth>()
{
  return "orca_msgs/msg/OrcaDepth";
}

template<>
struct has_fixed_size<orca_msgs::msg::OrcaDepth>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<orca_msgs::msg::OrcaDepth>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<orca_msgs::msg::OrcaDepth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_DEPTH__TRAITS_HPP_
