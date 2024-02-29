// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
#include "pose_traj_controller/action/detail/move_to_pose__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_Goal_type_support_ids_t;

static const _MoveToPose_Goal_type_support_ids_t _MoveToPose_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_Goal_type_support_symbol_names_t _MoveToPose_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Goal)),
  }
};

typedef struct _MoveToPose_Goal_type_support_data_t
{
  void * data[2];
} _MoveToPose_Goal_type_support_data_t;

static _MoveToPose_Goal_type_support_data_t _MoveToPose_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_Goal_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_Goal)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_Result_type_support_ids_t;

static const _MoveToPose_Result_type_support_ids_t _MoveToPose_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_Result_type_support_symbol_names_t _MoveToPose_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Result)),
  }
};

typedef struct _MoveToPose_Result_type_support_data_t
{
  void * data[2];
} _MoveToPose_Result_type_support_data_t;

static _MoveToPose_Result_type_support_data_t _MoveToPose_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_Result_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_Result)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_Feedback_type_support_ids_t;

static const _MoveToPose_Feedback_type_support_ids_t _MoveToPose_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_Feedback_type_support_symbol_names_t _MoveToPose_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_Feedback)),
  }
};

typedef struct _MoveToPose_Feedback_type_support_data_t
{
  void * data[2];
} _MoveToPose_Feedback_type_support_data_t;

static _MoveToPose_Feedback_type_support_data_t _MoveToPose_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_Feedback_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_Feedback)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_SendGoal_Request_type_support_ids_t;

static const _MoveToPose_SendGoal_Request_type_support_ids_t _MoveToPose_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_SendGoal_Request_type_support_symbol_names_t _MoveToPose_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)),
  }
};

typedef struct _MoveToPose_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveToPose_SendGoal_Request_type_support_data_t;

static _MoveToPose_SendGoal_Request_type_support_data_t _MoveToPose_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_SendGoal_Request_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_SendGoal_Request)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_SendGoal_Response_type_support_ids_t;

static const _MoveToPose_SendGoal_Response_type_support_ids_t _MoveToPose_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_SendGoal_Response_type_support_symbol_names_t _MoveToPose_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)),
  }
};

typedef struct _MoveToPose_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveToPose_SendGoal_Response_type_support_data_t;

static _MoveToPose_SendGoal_Response_type_support_data_t _MoveToPose_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_SendGoal_Response_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_SendGoal_Response)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_SendGoal_type_support_ids_t;

static const _MoveToPose_SendGoal_type_support_ids_t _MoveToPose_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_SendGoal_type_support_symbol_names_t _MoveToPose_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_SendGoal)),
  }
};

typedef struct _MoveToPose_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveToPose_SendGoal_type_support_data_t;

static _MoveToPose_SendGoal_type_support_data_t _MoveToPose_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_SendGoal_service_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveToPose_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_SendGoal)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_GetResult_Request_type_support_ids_t;

static const _MoveToPose_GetResult_Request_type_support_ids_t _MoveToPose_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_GetResult_Request_type_support_symbol_names_t _MoveToPose_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Request)),
  }
};

typedef struct _MoveToPose_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveToPose_GetResult_Request_type_support_data_t;

static _MoveToPose_GetResult_Request_type_support_data_t _MoveToPose_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_GetResult_Request_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_GetResult_Request)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_GetResult_Response_type_support_ids_t;

static const _MoveToPose_GetResult_Response_type_support_ids_t _MoveToPose_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_GetResult_Response_type_support_symbol_names_t _MoveToPose_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult_Response)),
  }
};

typedef struct _MoveToPose_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveToPose_GetResult_Response_type_support_data_t;

static _MoveToPose_GetResult_Response_type_support_data_t _MoveToPose_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_GetResult_Response_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_GetResult_Response)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_GetResult_type_support_ids_t;

static const _MoveToPose_GetResult_type_support_ids_t _MoveToPose_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_GetResult_type_support_symbol_names_t _MoveToPose_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_GetResult)),
  }
};

typedef struct _MoveToPose_GetResult_type_support_data_t
{
  void * data[2];
} _MoveToPose_GetResult_type_support_data_t;

static _MoveToPose_GetResult_type_support_data_t _MoveToPose_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_GetResult_service_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveToPose_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_GetResult)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "pose_traj_controller/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace pose_traj_controller
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveToPose_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveToPose_FeedbackMessage_type_support_ids_t;

static const _MoveToPose_FeedbackMessage_type_support_ids_t _MoveToPose_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveToPose_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveToPose_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveToPose_FeedbackMessage_type_support_symbol_names_t _MoveToPose_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pose_traj_controller, action, MoveToPose_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pose_traj_controller, action, MoveToPose_FeedbackMessage)),
  }
};

typedef struct _MoveToPose_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveToPose_FeedbackMessage_type_support_data_t;

static _MoveToPose_FeedbackMessage_type_support_data_t _MoveToPose_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveToPose_FeedbackMessage_message_typesupport_map = {
  2,
  "pose_traj_controller",
  &_MoveToPose_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveToPose_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveToPose_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveToPose_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveToPose_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace pose_traj_controller

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_FeedbackMessage)() {
  return &::pose_traj_controller::action::rosidl_typesupport_c::MoveToPose_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "pose_traj_controller/action/move_to_pose.h"
#include "pose_traj_controller/action/detail/move_to_pose__type_support.h"

static rosidl_action_type_support_t _pose_traj_controller__action__MoveToPose__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_pose_traj_controller
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, pose_traj_controller, action, MoveToPose)()
{
  // Thread-safe by always writing the same values to the static struct
  _pose_traj_controller__action__MoveToPose__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_SendGoal)();
  _pose_traj_controller__action__MoveToPose__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_GetResult)();
  _pose_traj_controller__action__MoveToPose__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _pose_traj_controller__action__MoveToPose__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, pose_traj_controller, action, MoveToPose_FeedbackMessage)();
  _pose_traj_controller__action__MoveToPose__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_pose_traj_controller__action__MoveToPose__typesupport_c;
}

#ifdef __cplusplus
}
#endif
