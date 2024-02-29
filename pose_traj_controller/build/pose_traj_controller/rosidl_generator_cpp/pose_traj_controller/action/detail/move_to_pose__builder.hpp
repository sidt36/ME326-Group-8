// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
#define POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_

#include "pose_traj_controller/action/detail/move_to_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Goal_orientation_required
{
public:
  explicit Init_MoveToPose_Goal_orientation_required(::pose_traj_controller::action::MoveToPose_Goal & msg)
  : msg_(msg)
  {}
  ::pose_traj_controller::action::MoveToPose_Goal orientation_required(::pose_traj_controller::action::MoveToPose_Goal::_orientation_required_type arg)
  {
    msg_.orientation_required = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_Goal msg_;
};

class Init_MoveToPose_Goal_yaw
{
public:
  explicit Init_MoveToPose_Goal_yaw(::pose_traj_controller::action::MoveToPose_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveToPose_Goal_orientation_required yaw(::pose_traj_controller::action::MoveToPose_Goal::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_MoveToPose_Goal_orientation_required(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_Goal msg_;
};

class Init_MoveToPose_Goal_position
{
public:
  Init_MoveToPose_Goal_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_Goal_yaw position(::pose_traj_controller::action::MoveToPose_Goal::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MoveToPose_Goal_yaw(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_Goal>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_Goal_position();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Result_pose_reached
{
public:
  Init_MoveToPose_Result_pose_reached()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pose_traj_controller::action::MoveToPose_Result pose_reached(::pose_traj_controller::action::MoveToPose_Result::_pose_reached_type arg)
  {
    msg_.pose_reached = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_Result>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_Result_pose_reached();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Feedback_feedback_string
{
public:
  Init_MoveToPose_Feedback_feedback_string()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pose_traj_controller::action::MoveToPose_Feedback feedback_string(::pose_traj_controller::action::MoveToPose_Feedback::_feedback_string_type arg)
  {
    msg_.feedback_string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_Feedback>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_Feedback_feedback_string();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_SendGoal_Request_goal
{
public:
  explicit Init_MoveToPose_SendGoal_Request_goal(::pose_traj_controller::action::MoveToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::pose_traj_controller::action::MoveToPose_SendGoal_Request goal(::pose_traj_controller::action::MoveToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_SendGoal_Request msg_;
};

class Init_MoveToPose_SendGoal_Request_goal_id
{
public:
  Init_MoveToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_SendGoal_Request_goal goal_id(::pose_traj_controller::action::MoveToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_SendGoal_Request>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_SendGoal_Request_goal_id();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_SendGoal_Response_stamp
{
public:
  explicit Init_MoveToPose_SendGoal_Response_stamp(::pose_traj_controller::action::MoveToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::pose_traj_controller::action::MoveToPose_SendGoal_Response stamp(::pose_traj_controller::action::MoveToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_SendGoal_Response msg_;
};

class Init_MoveToPose_SendGoal_Response_accepted
{
public:
  Init_MoveToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_SendGoal_Response_stamp accepted(::pose_traj_controller::action::MoveToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_SendGoal_Response>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_SendGoal_Response_accepted();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_GetResult_Request_goal_id
{
public:
  Init_MoveToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pose_traj_controller::action::MoveToPose_GetResult_Request goal_id(::pose_traj_controller::action::MoveToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_GetResult_Request>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_GetResult_Request_goal_id();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_GetResult_Response_result
{
public:
  explicit Init_MoveToPose_GetResult_Response_result(::pose_traj_controller::action::MoveToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::pose_traj_controller::action::MoveToPose_GetResult_Response result(::pose_traj_controller::action::MoveToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_GetResult_Response msg_;
};

class Init_MoveToPose_GetResult_Response_status
{
public:
  Init_MoveToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_GetResult_Response_result status(::pose_traj_controller::action::MoveToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveToPose_GetResult_Response_result(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_GetResult_Response>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_GetResult_Response_status();
}

}  // namespace pose_traj_controller


namespace pose_traj_controller
{

namespace action
{

namespace builder
{

class Init_MoveToPose_FeedbackMessage_feedback
{
public:
  explicit Init_MoveToPose_FeedbackMessage_feedback(::pose_traj_controller::action::MoveToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::pose_traj_controller::action::MoveToPose_FeedbackMessage feedback(::pose_traj_controller::action::MoveToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_FeedbackMessage msg_;
};

class Init_MoveToPose_FeedbackMessage_goal_id
{
public:
  Init_MoveToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_FeedbackMessage_feedback goal_id(::pose_traj_controller::action::MoveToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::pose_traj_controller::action::MoveToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::pose_traj_controller::action::MoveToPose_FeedbackMessage>()
{
  return pose_traj_controller::action::builder::Init_MoveToPose_FeedbackMessage_goal_id();
}

}  // namespace pose_traj_controller

#endif  // POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
