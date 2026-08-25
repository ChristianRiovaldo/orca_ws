// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from orca_msgs:msg/FinalDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "orca_msgs/msg/final_detection.hpp"


#ifndef ORCA_MSGS__MSG__DETAIL__FINAL_DETECTION__BUILDER_HPP_
#define ORCA_MSGS__MSG__DETAIL__FINAL_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "orca_msgs/msg/detail/final_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace orca_msgs
{

namespace msg
{

namespace builder
{

class Init_FinalDetection_distance
{
public:
  explicit Init_FinalDetection_distance(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  ::orca_msgs::msg::FinalDetection distance(::orca_msgs::msg::FinalDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_bbox_area_ratio
{
public:
  explicit Init_FinalDetection_bbox_area_ratio(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_distance bbox_area_ratio(::orca_msgs::msg::FinalDetection::_bbox_area_ratio_type arg)
  {
    msg_.bbox_area_ratio = std::move(arg);
    return Init_FinalDetection_distance(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_bbox_height
{
public:
  explicit Init_FinalDetection_bbox_height(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_bbox_area_ratio bbox_height(::orca_msgs::msg::FinalDetection::_bbox_height_type arg)
  {
    msg_.bbox_height = std::move(arg);
    return Init_FinalDetection_bbox_area_ratio(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_bbox_width
{
public:
  explicit Init_FinalDetection_bbox_width(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_bbox_height bbox_width(::orca_msgs::msg::FinalDetection::_bbox_width_type arg)
  {
    msg_.bbox_width = std::move(arg);
    return Init_FinalDetection_bbox_height(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_center_x_norm
{
public:
  explicit Init_FinalDetection_center_x_norm(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_bbox_width center_x_norm(::orca_msgs::msg::FinalDetection::_center_x_norm_type arg)
  {
    msg_.center_x_norm = std::move(arg);
    return Init_FinalDetection_bbox_width(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_center_y
{
public:
  explicit Init_FinalDetection_center_y(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_center_x_norm center_y(::orca_msgs::msg::FinalDetection::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_FinalDetection_center_x_norm(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_center_x
{
public:
  explicit Init_FinalDetection_center_x(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_center_y center_x(::orca_msgs::msg::FinalDetection::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_FinalDetection_center_y(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_confidence
{
public:
  explicit Init_FinalDetection_confidence(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_center_x confidence(::orca_msgs::msg::FinalDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_FinalDetection_center_x(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_class_name
{
public:
  explicit Init_FinalDetection_class_name(::orca_msgs::msg::FinalDetection & msg)
  : msg_(msg)
  {}
  Init_FinalDetection_confidence class_name(::orca_msgs::msg::FinalDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_FinalDetection_confidence(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

class Init_FinalDetection_detected
{
public:
  Init_FinalDetection_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FinalDetection_class_name detected(::orca_msgs::msg::FinalDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_FinalDetection_class_name(msg_);
  }

private:
  ::orca_msgs::msg::FinalDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::orca_msgs::msg::FinalDetection>()
{
  return orca_msgs::msg::builder::Init_FinalDetection_detected();
}

}  // namespace orca_msgs

#endif  // ORCA_MSGS__MSG__DETAIL__FINAL_DETECTION__BUILDER_HPP_
