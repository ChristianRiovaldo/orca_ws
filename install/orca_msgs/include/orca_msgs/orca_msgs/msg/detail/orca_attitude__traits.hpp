// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from orca_msgs:msg/OrcaAttitude.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_attitude.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__TRAITS_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "orca_msgs/msg/detail/orca_attitude__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace orca_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrcaAttitude & msg,
  std::ostream & out)
{
  out << "{";
  // member: initial_x
  {
    out << "initial_x: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_x, out);
    out << ", ";
  }

  // member: initial_y
  {
    out << "initial_y: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_y, out);
    out << ", ";
  }

  // member: initial_z
  {
    out << "initial_z: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_z, out);
    out << ", ";
  }

  // member: yaw_deg
  {
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << ", ";
  }

  // member: initial_deg
  {
    out << "initial_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_deg, out);
    out << ", ";
  }

  // member: roll_deg
  {
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << ", ";
  }

  // member: pitch_deg
  {
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << ", ";
  }

  // member: rollspeed_deg_s
  {
    out << "rollspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed_deg_s, out);
    out << ", ";
  }

  // member: pitchspeed_deg_s
  {
    out << "pitchspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed_deg_s, out);
    out << ", ";
  }

  // member: yawspeed_deg_s
  {
    out << "yawspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed_deg_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrcaAttitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: initial_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_x: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_x, out);
    out << "\n";
  }

  // member: initial_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_y: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_y, out);
    out << "\n";
  }

  // member: initial_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_z: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_z, out);
    out << "\n";
  }

  // member: yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << "\n";
  }

  // member: initial_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "initial_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.initial_deg, out);
    out << "\n";
  }

  // member: roll_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << "\n";
  }

  // member: pitch_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << "\n";
  }

  // member: rollspeed_deg_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rollspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.rollspeed_deg_s, out);
    out << "\n";
  }

  // member: pitchspeed_deg_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitchspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.pitchspeed_deg_s, out);
    out << "\n";
  }

  // member: yawspeed_deg_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yawspeed_deg_s: ";
    rosidl_generator_traits::value_to_yaml(msg.yawspeed_deg_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrcaAttitude & msg, bool use_flow_style = false)
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
  const orca_msgs::msg::OrcaAttitude & msg,
  std::ostream & out, size_t indentation = 0)
{
  orca_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use orca_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const orca_msgs::msg::OrcaAttitude & msg)
{
  return orca_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<orca_msgs::msg::OrcaAttitude>()
{
  return "orca_msgs::msg::OrcaAttitude";
}

template<>
inline const char * name<orca_msgs::msg::OrcaAttitude>()
{
  return "orca_msgs/msg/OrcaAttitude";
}

template<>
struct has_fixed_size<orca_msgs::msg::OrcaAttitude>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<orca_msgs::msg::OrcaAttitude>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<orca_msgs::msg::OrcaAttitude>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_ATTITUDE__TRAITS_HPP_
