// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orca_msgs:msg/FailsafeTrigger.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/failsafe_trigger.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__TRAITS_HPP_
#define ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orca_msgs/msg/detail/failsafe_trigger__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orca_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FailsafeTrigger & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FailsafeTrigger & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FailsafeTrigger & msg, bool use_flow_style = false)
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
  const orca_msgs::msg::FailsafeTrigger & msg,
  std::ostream & out, size_t indentation = 0)
{
  orca_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orca_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const orca_msgs::msg::FailsafeTrigger & msg)
{
  return orca_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orca_msgs::msg::FailsafeTrigger>()
{
  return "orca_msgs::msg::FailsafeTrigger";
}

template<>
inline const char * name<orca_msgs::msg::FailsafeTrigger>()
{
  return "orca_msgs/msg/FailsafeTrigger";
}

template<>
struct has_fixed_size<orca_msgs::msg::FailsafeTrigger>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<orca_msgs::msg::FailsafeTrigger>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<orca_msgs::msg::FailsafeTrigger>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORCA_MSGS__MSG__DETAIL__FAILSAFE_TRIGGER__TRAITS_HPP_
