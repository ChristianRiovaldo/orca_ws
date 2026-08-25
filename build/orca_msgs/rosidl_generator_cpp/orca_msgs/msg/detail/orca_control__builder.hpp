// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from orca_msgs:msg/OrcaControl.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/orca_control.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__BUILDER_HPP_
#define ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "orca_msgs/msg/detail/orca_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace orca_msgs
{

namespace msg
{

namespace builder
{

class Init_OrcaControl_source
{
public:
  explicit Init_OrcaControl_source(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  ::orca_msgs::msg::OrcaControl source(::orca_msgs::msg::OrcaControl::_source_type arg)
  {
    msg_.source = std::move(arg);
    return std::move(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_gripper_mode
{
public:
  explicit Init_OrcaControl_gripper_mode(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_source gripper_mode(::orca_msgs::msg::OrcaControl::_gripper_mode_type arg)
  {
    msg_.gripper_mode = std::move(arg);
    return Init_OrcaControl_source(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_control_mode
{
public:
  explicit Init_OrcaControl_control_mode(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_gripper_mode control_mode(::orca_msgs::msg::OrcaControl::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_OrcaControl_gripper_mode(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_arm_mode
{
public:
  explicit Init_OrcaControl_arm_mode(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_control_mode arm_mode(::orca_msgs::msg::OrcaControl::_arm_mode_type arg)
  {
    msg_.arm_mode = std::move(arg);
    return Init_OrcaControl_control_mode(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_yaw
{
public:
  explicit Init_OrcaControl_yaw(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_arm_mode yaw(::orca_msgs::msg::OrcaControl::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_OrcaControl_arm_mode(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_forward
{
public:
  explicit Init_OrcaControl_forward(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_yaw forward(::orca_msgs::msg::OrcaControl::_forward_type arg)
  {
    msg_.forward = std::move(arg);
    return Init_OrcaControl_yaw(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_lateral
{
public:
  explicit Init_OrcaControl_lateral(::orca_msgs::msg::OrcaControl & msg)
  : msg_(msg)
  {}
  Init_OrcaControl_forward lateral(::orca_msgs::msg::OrcaControl::_lateral_type arg)
  {
    msg_.lateral = std::move(arg);
    return Init_OrcaControl_forward(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

class Init_OrcaControl_throttle
{
public:
  Init_OrcaControl_throttle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrcaControl_lateral throttle(::orca_msgs::msg::OrcaControl::_throttle_type arg)
  {
    msg_.throttle = std::move(arg);
    return Init_OrcaControl_lateral(msg_);
  }

private:
  ::orca_msgs::msg::OrcaControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::orca_msgs::msg::OrcaControl>()
{
  return orca_msgs::msg::builder::Init_OrcaControl_throttle();
}

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__ORCA_CONTROL__BUILDER_HPP_
