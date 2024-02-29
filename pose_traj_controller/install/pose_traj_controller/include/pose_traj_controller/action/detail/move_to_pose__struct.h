// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#ifndef POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_H_
#define POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_Goal
{
  geometry_msgs__msg__Point position;
  double yaw;
  bool orientation_required;
} pose_traj_controller__action__MoveToPose_Goal;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_Goal.
typedef struct pose_traj_controller__action__MoveToPose_Goal__Sequence
{
  pose_traj_controller__action__MoveToPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_Goal__Sequence;


// Constants defined in the message

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_Result
{
  bool pose_reached;
} pose_traj_controller__action__MoveToPose_Result;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_Result.
typedef struct pose_traj_controller__action__MoveToPose_Result__Sequence
{
  pose_traj_controller__action__MoveToPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback_string'
#include "rosidl_runtime_c/string.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_Feedback
{
  rosidl_runtime_c__String feedback_string;
} pose_traj_controller__action__MoveToPose_Feedback;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_Feedback.
typedef struct pose_traj_controller__action__MoveToPose_Feedback__Sequence
{
  pose_traj_controller__action__MoveToPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "pose_traj_controller/action/detail/move_to_pose__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  pose_traj_controller__action__MoveToPose_Goal goal;
} pose_traj_controller__action__MoveToPose_SendGoal_Request;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_SendGoal_Request.
typedef struct pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence
{
  pose_traj_controller__action__MoveToPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} pose_traj_controller__action__MoveToPose_SendGoal_Response;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_SendGoal_Response.
typedef struct pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence
{
  pose_traj_controller__action__MoveToPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} pose_traj_controller__action__MoveToPose_GetResult_Request;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_GetResult_Request.
typedef struct pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence
{
  pose_traj_controller__action__MoveToPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_GetResult_Response
{
  int8_t status;
  pose_traj_controller__action__MoveToPose_Result result;
} pose_traj_controller__action__MoveToPose_GetResult_Response;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_GetResult_Response.
typedef struct pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence
{
  pose_traj_controller__action__MoveToPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"

// Struct defined in action/MoveToPose in the package pose_traj_controller.
typedef struct pose_traj_controller__action__MoveToPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  pose_traj_controller__action__MoveToPose_Feedback feedback;
} pose_traj_controller__action__MoveToPose_FeedbackMessage;

// Struct for a sequence of pose_traj_controller__action__MoveToPose_FeedbackMessage.
typedef struct pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence
{
  pose_traj_controller__action__MoveToPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POSE_TRAJ_CONTROLLER__ACTION__DETAIL__MOVE_TO_POSE__STRUCT_H_
