// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orca_msgs:msg/OrcaProximity.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_proximity.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__TRAITS_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orca_msgs/msg/detail/orca_proximity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orca_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrcaProximity & msg,
  std::ostream & out)
{
  out << "{";
  // member: arm_mode
  {
    out << "arm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.arm_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrcaProximity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arm_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arm_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.arm_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrcaProximity & msg, bool use_flow_style = false)
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
  const orca_msgs::msg::OrcaProximity & msg,
  std::ostream & out, size_t indentation = 0)
{
  orca_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orca_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const orca_msgs::msg::OrcaProximity & msg)
{
  return orca_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orca_msgs::msg::OrcaProximity>()
{
  return "orca_msgs::msg::OrcaProximity";
}

template<>
inline const char * name<orca_msgs::msg::OrcaProximity>()
{
  return "orca_msgs/msg/OrcaProximity";
}

template<>
struct has_fixed_size<orca_msgs::msg::OrcaProximity>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<orca_msgs::msg::OrcaProximity>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<orca_msgs::msg::OrcaProximity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_PROXIMITY__TRAITS_HPP_
