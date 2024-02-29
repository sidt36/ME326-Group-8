// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__TRAITS_HPP_
#define POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__TRAITS_HPP_

#include "pose_traj_controller/action/detail/move_to_pose__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_yaml(msg.position, out, indentation + 2);
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: orientation_required
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "orientation_required: ";
    value_to_yaml(msg.orientation_required, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_Goal & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_Goal>()
{
  return "pose_traj_controller::action::MoveToPose_Goal";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_Goal>()
{
  return "pose_traj_controller/action/MoveToPose_Goal";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_Goal>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_Goal>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_reached
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_reached: ";
    value_to_yaml(msg.pose_reached, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_Result & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_Result>()
{
  return "pose_traj_controller::action::MoveToPose_Result";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_Result>()
{
  return "pose_traj_controller/action/MoveToPose_Result";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: feedback_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback_string: ";
    value_to_yaml(msg.feedback_string, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_Feedback & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_Feedback>()
{
  return "pose_traj_controller::action::MoveToPose_Feedback";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_Feedback>()
{
  return "pose_traj_controller/action/MoveToPose_Feedback";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "pose_traj_controller/action/detail/move_to_pose__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_SendGoal_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_SendGoal_Request>()
{
  return "pose_traj_controller::action::MoveToPose_SendGoal_Request";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_SendGoal_Request>()
{
  return "pose_traj_controller/action/MoveToPose_SendGoal_Request";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<pose_traj_controller::action::MoveToPose_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<pose_traj_controller::action::MoveToPose_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_SendGoal_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_SendGoal_Response>()
{
  return "pose_traj_controller::action::MoveToPose_SendGoal_Response";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_SendGoal_Response>()
{
  return "pose_traj_controller/action/MoveToPose_SendGoal_Response";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_SendGoal>()
{
  return "pose_traj_controller::action::MoveToPose_SendGoal";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_SendGoal>()
{
  return "pose_traj_controller/action/MoveToPose_SendGoal";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<pose_traj_controller::action::MoveToPose_SendGoal_Request>::value &&
    has_fixed_size<pose_traj_controller::action::MoveToPose_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<pose_traj_controller::action::MoveToPose_SendGoal_Request>::value &&
    has_bounded_size<pose_traj_controller::action::MoveToPose_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<pose_traj_controller::action::MoveToPose_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<pose_traj_controller::action::MoveToPose_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<pose_traj_controller::action::MoveToPose_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_GetResult_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_GetResult_Request>()
{
  return "pose_traj_controller::action::MoveToPose_GetResult_Request";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_GetResult_Request>()
{
  return "pose_traj_controller/action/MoveToPose_GetResult_Request";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_GetResult_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_GetResult_Response>()
{
  return "pose_traj_controller::action::MoveToPose_GetResult_Response";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_GetResult_Response>()
{
  return "pose_traj_controller/action/MoveToPose_GetResult_Response";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<pose_traj_controller::action::MoveToPose_Result>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<pose_traj_controller::action::MoveToPose_Result>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_GetResult>()
{
  return "pose_traj_controller::action::MoveToPose_GetResult";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_GetResult>()
{
  return "pose_traj_controller/action/MoveToPose_GetResult";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<pose_traj_controller::action::MoveToPose_GetResult_Request>::value &&
    has_fixed_size<pose_traj_controller::action::MoveToPose_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<pose_traj_controller::action::MoveToPose_GetResult_Request>::value &&
    has_bounded_size<pose_traj_controller::action::MoveToPose_GetResult_Response>::value
  >
{
};

template<>
struct is_service<pose_traj_controller::action::MoveToPose_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<pose_traj_controller::action::MoveToPose_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<pose_traj_controller::action::MoveToPose_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const pose_traj_controller::action::MoveToPose_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const pose_traj_controller::action::MoveToPose_FeedbackMessage & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<pose_traj_controller::action::MoveToPose_FeedbackMessage>()
{
  return "pose_traj_controller::action::MoveToPose_FeedbackMessage";
}

template<>
inline const char * name<pose_traj_controller::action::MoveToPose_FeedbackMessage>()
{
  return "pose_traj_controller/action/MoveToPose_FeedbackMessage";
}

template<>
struct has_fixed_size<pose_traj_controller::action::MoveToPose_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<pose_traj_controller::action::MoveToPose_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<pose_traj_controller::action::MoveToPose_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<pose_traj_controller::action::MoveToPose_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<pose_traj_controller::action::MoveToPose_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<pose_traj_controller::action::MoveToPose>
  : std::true_type
{
};

template<>
struct is_action_goal<pose_traj_controller::action::MoveToPose_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<pose_traj_controller::action::MoveToPose_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<pose_traj_controller::action::MoveToPose_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__TRAITS_HPP_
