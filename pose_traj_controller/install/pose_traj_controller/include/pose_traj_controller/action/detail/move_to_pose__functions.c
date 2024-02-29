// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pose_traj_controller:action/MoveToPose.idl
// generated code does not contain a copyright notice
#include "pose_traj_controller/action/detail/move_to_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
pose_traj_controller__action__MoveToPose_Goal__init(pose_traj_controller__action__MoveToPose_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    pose_traj_controller__action__MoveToPose_Goal__fini(msg);
    return false;
  }
  // yaw
  // orientation_required
  return true;
}

void
pose_traj_controller__action__MoveToPose_Goal__fini(pose_traj_controller__action__MoveToPose_Goal * msg)
{
  if (!msg) {
    return;
  }
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // yaw
  // orientation_required
}

bool
pose_traj_controller__action__MoveToPose_Goal__are_equal(const pose_traj_controller__action__MoveToPose_Goal * lhs, const pose_traj_controller__action__MoveToPose_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // orientation_required
  if (lhs->orientation_required != rhs->orientation_required) {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Goal__copy(
  const pose_traj_controller__action__MoveToPose_Goal * input,
  pose_traj_controller__action__MoveToPose_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  // orientation_required
  output->orientation_required = input->orientation_required;
  return true;
}

pose_traj_controller__action__MoveToPose_Goal *
pose_traj_controller__action__MoveToPose_Goal__create()
{
  pose_traj_controller__action__MoveToPose_Goal * msg = (pose_traj_controller__action__MoveToPose_Goal *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Goal));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_Goal));
  bool success = pose_traj_controller__action__MoveToPose_Goal__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_Goal__destroy(pose_traj_controller__action__MoveToPose_Goal * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_Goal__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__init(pose_traj_controller__action__MoveToPose_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_Goal * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_Goal *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_Goal));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_Goal__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_Goal__Sequence__fini(pose_traj_controller__action__MoveToPose_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_Goal__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_Goal__Sequence *
pose_traj_controller__action__MoveToPose_Goal__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_Goal__Sequence * array = (pose_traj_controller__action__MoveToPose_Goal__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Goal__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_Goal__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_Goal__Sequence__destroy(pose_traj_controller__action__MoveToPose_Goal__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_Goal__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Goal__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Goal__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Goal__Sequence * input,
  pose_traj_controller__action__MoveToPose_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_Goal);
    pose_traj_controller__action__MoveToPose_Goal * data =
      (pose_traj_controller__action__MoveToPose_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_Goal__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
pose_traj_controller__action__MoveToPose_Result__init(pose_traj_controller__action__MoveToPose_Result * msg)
{
  if (!msg) {
    return false;
  }
  // pose_reached
  return true;
}

void
pose_traj_controller__action__MoveToPose_Result__fini(pose_traj_controller__action__MoveToPose_Result * msg)
{
  if (!msg) {
    return;
  }
  // pose_reached
}

bool
pose_traj_controller__action__MoveToPose_Result__are_equal(const pose_traj_controller__action__MoveToPose_Result * lhs, const pose_traj_controller__action__MoveToPose_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pose_reached
  if (lhs->pose_reached != rhs->pose_reached) {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Result__copy(
  const pose_traj_controller__action__MoveToPose_Result * input,
  pose_traj_controller__action__MoveToPose_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // pose_reached
  output->pose_reached = input->pose_reached;
  return true;
}

pose_traj_controller__action__MoveToPose_Result *
pose_traj_controller__action__MoveToPose_Result__create()
{
  pose_traj_controller__action__MoveToPose_Result * msg = (pose_traj_controller__action__MoveToPose_Result *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Result));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_Result));
  bool success = pose_traj_controller__action__MoveToPose_Result__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_Result__destroy(pose_traj_controller__action__MoveToPose_Result * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_Result__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_Result__Sequence__init(pose_traj_controller__action__MoveToPose_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_Result * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_Result *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_Result));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_Result__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_Result__Sequence__fini(pose_traj_controller__action__MoveToPose_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_Result__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_Result__Sequence *
pose_traj_controller__action__MoveToPose_Result__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_Result__Sequence * array = (pose_traj_controller__action__MoveToPose_Result__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Result__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_Result__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_Result__Sequence__destroy(pose_traj_controller__action__MoveToPose_Result__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_Result__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_Result__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Result__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Result__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Result__Sequence * input,
  pose_traj_controller__action__MoveToPose_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_Result);
    pose_traj_controller__action__MoveToPose_Result * data =
      (pose_traj_controller__action__MoveToPose_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_Result__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `feedback_string`
#include "rosidl_runtime_c/string_functions.h"

bool
pose_traj_controller__action__MoveToPose_Feedback__init(pose_traj_controller__action__MoveToPose_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // feedback_string
  if (!rosidl_runtime_c__String__init(&msg->feedback_string)) {
    pose_traj_controller__action__MoveToPose_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_Feedback__fini(pose_traj_controller__action__MoveToPose_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // feedback_string
  rosidl_runtime_c__String__fini(&msg->feedback_string);
}

bool
pose_traj_controller__action__MoveToPose_Feedback__are_equal(const pose_traj_controller__action__MoveToPose_Feedback * lhs, const pose_traj_controller__action__MoveToPose_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // feedback_string
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->feedback_string), &(rhs->feedback_string)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Feedback__copy(
  const pose_traj_controller__action__MoveToPose_Feedback * input,
  pose_traj_controller__action__MoveToPose_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // feedback_string
  if (!rosidl_runtime_c__String__copy(
      &(input->feedback_string), &(output->feedback_string)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_Feedback *
pose_traj_controller__action__MoveToPose_Feedback__create()
{
  pose_traj_controller__action__MoveToPose_Feedback * msg = (pose_traj_controller__action__MoveToPose_Feedback *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Feedback));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_Feedback));
  bool success = pose_traj_controller__action__MoveToPose_Feedback__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_Feedback__destroy(pose_traj_controller__action__MoveToPose_Feedback * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_Feedback__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__init(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_Feedback * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_Feedback *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_Feedback));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_Feedback__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_Feedback__Sequence__fini(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_Feedback__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_Feedback__Sequence *
pose_traj_controller__action__MoveToPose_Feedback__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_Feedback__Sequence * array = (pose_traj_controller__action__MoveToPose_Feedback__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_Feedback__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_Feedback__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_Feedback__Sequence__destroy(pose_traj_controller__action__MoveToPose_Feedback__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_Feedback__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_Feedback__Sequence * lhs, const pose_traj_controller__action__MoveToPose_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_Feedback__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_Feedback__Sequence * input,
  pose_traj_controller__action__MoveToPose_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_Feedback);
    pose_traj_controller__action__MoveToPose_Feedback * data =
      (pose_traj_controller__action__MoveToPose_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_Feedback__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"

bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__init(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!pose_traj_controller__action__MoveToPose_Goal__init(&msg->goal)) {
    pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  pose_traj_controller__action__MoveToPose_Goal__fini(&msg->goal);
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Request * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!pose_traj_controller__action__MoveToPose_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Request * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!pose_traj_controller__action__MoveToPose_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_SendGoal_Request *
pose_traj_controller__action__MoveToPose_SendGoal_Request__create()
{
  pose_traj_controller__action__MoveToPose_SendGoal_Request * msg = (pose_traj_controller__action__MoveToPose_SendGoal_Request *)malloc(sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request));
  bool success = pose_traj_controller__action__MoveToPose_SendGoal_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Request__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Request * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__init(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_SendGoal_Request * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_SendGoal_Request *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__fini(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence *
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array = (pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Request);
    pose_traj_controller__action__MoveToPose_SendGoal_Request * data =
      (pose_traj_controller__action__MoveToPose_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_SendGoal_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__init(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Response * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Response * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_SendGoal_Response *
pose_traj_controller__action__MoveToPose_SendGoal_Response__create()
{
  pose_traj_controller__action__MoveToPose_SendGoal_Response * msg = (pose_traj_controller__action__MoveToPose_SendGoal_Response *)malloc(sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response));
  bool success = pose_traj_controller__action__MoveToPose_SendGoal_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Response__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Response * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__init(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_SendGoal_Response * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_SendGoal_Response *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__fini(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence *
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array = (pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__destroy(pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * lhs, const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * input,
  pose_traj_controller__action__MoveToPose_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_SendGoal_Response);
    pose_traj_controller__action__MoveToPose_SendGoal_Response * data =
      (pose_traj_controller__action__MoveToPose_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_SendGoal_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
pose_traj_controller__action__MoveToPose_GetResult_Request__init(pose_traj_controller__action__MoveToPose_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    pose_traj_controller__action__MoveToPose_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Request__fini(pose_traj_controller__action__MoveToPose_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Request__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Request * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Request__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Request * input,
  pose_traj_controller__action__MoveToPose_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_GetResult_Request *
pose_traj_controller__action__MoveToPose_GetResult_Request__create()
{
  pose_traj_controller__action__MoveToPose_GetResult_Request * msg = (pose_traj_controller__action__MoveToPose_GetResult_Request *)malloc(sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request));
  bool success = pose_traj_controller__action__MoveToPose_GetResult_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Request__destroy(pose_traj_controller__action__MoveToPose_GetResult_Request * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_GetResult_Request__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__init(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_GetResult_Request * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_GetResult_Request *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_GetResult_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__fini(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_GetResult_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence *
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array = (pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__destroy(pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * input,
  pose_traj_controller__action__MoveToPose_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_GetResult_Request);
    pose_traj_controller__action__MoveToPose_GetResult_Request * data =
      (pose_traj_controller__action__MoveToPose_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_GetResult_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"

bool
pose_traj_controller__action__MoveToPose_GetResult_Response__init(pose_traj_controller__action__MoveToPose_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!pose_traj_controller__action__MoveToPose_Result__init(&msg->result)) {
    pose_traj_controller__action__MoveToPose_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Response__fini(pose_traj_controller__action__MoveToPose_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  pose_traj_controller__action__MoveToPose_Result__fini(&msg->result);
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Response__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Response * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!pose_traj_controller__action__MoveToPose_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Response__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Response * input,
  pose_traj_controller__action__MoveToPose_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!pose_traj_controller__action__MoveToPose_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_GetResult_Response *
pose_traj_controller__action__MoveToPose_GetResult_Response__create()
{
  pose_traj_controller__action__MoveToPose_GetResult_Response * msg = (pose_traj_controller__action__MoveToPose_GetResult_Response *)malloc(sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response));
  bool success = pose_traj_controller__action__MoveToPose_GetResult_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Response__destroy(pose_traj_controller__action__MoveToPose_GetResult_Response * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_GetResult_Response__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__init(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_GetResult_Response * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_GetResult_Response *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_GetResult_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__fini(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_GetResult_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence *
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array = (pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__destroy(pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * lhs, const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * input,
  pose_traj_controller__action__MoveToPose_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_GetResult_Response);
    pose_traj_controller__action__MoveToPose_GetResult_Response * data =
      (pose_traj_controller__action__MoveToPose_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_GetResult_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "pose_traj_controller/action/detail/move_to_pose__functions.h"

bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__init(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!pose_traj_controller__action__MoveToPose_Feedback__init(&msg->feedback)) {
    pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  pose_traj_controller__action__MoveToPose_Feedback__fini(&msg->feedback);
}

bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__are_equal(const pose_traj_controller__action__MoveToPose_FeedbackMessage * lhs, const pose_traj_controller__action__MoveToPose_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!pose_traj_controller__action__MoveToPose_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__copy(
  const pose_traj_controller__action__MoveToPose_FeedbackMessage * input,
  pose_traj_controller__action__MoveToPose_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!pose_traj_controller__action__MoveToPose_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

pose_traj_controller__action__MoveToPose_FeedbackMessage *
pose_traj_controller__action__MoveToPose_FeedbackMessage__create()
{
  pose_traj_controller__action__MoveToPose_FeedbackMessage * msg = (pose_traj_controller__action__MoveToPose_FeedbackMessage *)malloc(sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage));
  bool success = pose_traj_controller__action__MoveToPose_FeedbackMessage__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
pose_traj_controller__action__MoveToPose_FeedbackMessage__destroy(pose_traj_controller__action__MoveToPose_FeedbackMessage * msg)
{
  if (msg) {
    pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(msg);
  }
  free(msg);
}


bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__init(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  pose_traj_controller__action__MoveToPose_FeedbackMessage * data = NULL;
  if (size) {
    data = (pose_traj_controller__action__MoveToPose_FeedbackMessage *)calloc(size, sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pose_traj_controller__action__MoveToPose_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__fini(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence *
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__create(size_t size)
{
  pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array = (pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence *)malloc(sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__destroy(pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * array)
{
  if (array) {
    pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__fini(array);
  }
  free(array);
}

bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__are_equal(const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * lhs, const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence__copy(
  const pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * input,
  pose_traj_controller__action__MoveToPose_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pose_traj_controller__action__MoveToPose_FeedbackMessage);
    pose_traj_controller__action__MoveToPose_FeedbackMessage * data =
      (pose_traj_controller__action__MoveToPose_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pose_traj_controller__action__MoveToPose_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          pose_traj_controller__action__MoveToPose_FeedbackMessage__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pose_traj_controller__action__MoveToPose_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
