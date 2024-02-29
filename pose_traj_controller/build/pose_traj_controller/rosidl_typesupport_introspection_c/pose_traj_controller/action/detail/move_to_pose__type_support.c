// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
#include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pose_traj_controller/action/detail/move_to_pose__functions.h"
#include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_Goal__init(message_memory);
}

void MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_member_array[3] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_Goal, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_Goal, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "orientation_required",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_Goal, orientation_required),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_Goal",  // message name
  3,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_Goal),
  MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_member_array,  // message members
  MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_type_support_handle = {
  0,
  &MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Goal)() {
  MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_type_support_handle.typesupport_identifier) {
    MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_Goal__rosidl_typesupport_introspection_c__MoveToPose_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_Result__init(message_memory);
}

void MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_member_array[1] = {
  {
    "pose_reached",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_Result, pose_reached),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_Result",  // message name
  1,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_Result),
  MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_member_array,  // message members
  MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_type_support_handle = {
  0,
  &MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Result)() {
  if (!MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_type_support_handle.typesupport_identifier) {
    MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_Result__rosidl_typesupport_introspection_c__MoveToPose_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `feedback_string`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_Feedback__init(message_memory);
}

void MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_member_array[1] = {
  {
    "feedback_string",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_Feedback, feedback_string),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_Feedback",  // message name
  1,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_Feedback),
  MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_member_array,  // message members
  MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_type_support_handle = {
  0,
  &MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Feedback)() {
  if (!MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_type_support_handle.typesupport_identifier) {
    MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_Feedback__rosidl_typesupport_introspection_c__MoveToPose_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "pose_traj_controller/action/move_to_pose.h"
// Member `goal`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_SendGoal_Request__init(message_memory);
}

void MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request),
  MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_member_array,  // message members
  MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_type_support_handle = {
  0,
  &MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)() {
  MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Goal)();
  if (!MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_SendGoal_Request__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_SendGoal_Response__init(message_memory);
}

void MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response),
  MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_member_array,  // message members
  MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_type_support_handle = {
  0,
  &MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)() {
  MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_SendGoal_Response__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_members = {
  "pose_traj_controller__action",  // service namespace
  "MoveToPose_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_type_support_handle = {
  0,
  &pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal)() {
  if (!pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_type_support_handle.typesupport_identifier) {
    pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)()->data;
  }

  return &pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_GetResult_Request__init(message_memory);
}

void MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request),
  MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_member_array,  // message members
  MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_type_support_handle = {
  0,
  &MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Request)() {
  MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_GetResult_Request__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "pose_traj_controller/action/move_to_pose.h"
// Member `result`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_GetResult_Response__init(message_memory);
}

void MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response),
  MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_member_array,  // message members
  MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_type_support_handle = {
  0,
  &MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Response)() {
  MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Result)();
  if (!MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_GetResult_Response__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_members = {
  "pose_traj_controller__action",  // service namespace
  "MoveToPose_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_type_support_handle = {
  0,
  &pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult)() {
  if (!pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_type_support_handle.typesupport_identifier) {
    pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Response)()->data;
  }

  return &pose_traj_controller__action__detail__move_to_pose__rosidl_typesupport_introspection_c__MoveToPose_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "pose_traj_controller/action/move_to_pose.h"
// Member `feedback`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pose_traj_controller__action__MoveToPose_FeedbackMessage__init(message_memory);
}

void MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_fini_function(void * message_memory)
{
  pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pose_traj_controller__action__MoveToPose_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_members = {
  "pose_traj_controller__action",  // message namespace
  "MoveToPose_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage),
  MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_member_array,  // message members
  MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_type_support_handle = {
  0,
  &MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_FeedbackMessage)() {
  MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Feedback)();
  if (!MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveToPose_FeedbackMessage__rosidl_typesupport_introspection_c__MoveToPose_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
