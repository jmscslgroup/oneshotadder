/*
 * oneshotadder_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "oneshotadder".
 *
 * Model version              : 6.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Nov 26 15:23:32 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_oneshotadder_types_h_
#define RTW_HEADER_oneshotadder_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_Float64_

struct SL_Bus_oneshotadder_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_Int8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_Int8_

struct SL_Bus_oneshotadder_std_msgs_Int8
{
  int8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_oneshotadder_std_msgs_UInt8_

struct SL_Bus_oneshotadder_std_msgs_UInt8
{
  uint8_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
  MSG_QUEUE_UNUSED = -1,               /* Default value */
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_real_T_
#define DEFINED_TYPEDEF_FOR_Msg_real_T_

struct Msg_real_T
{
  real_T fData;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_real_T_
#define DEFINED_TYPEDEF_FOR_Queue_real_T_

struct Queue_real_T
{
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_real_T *fArray;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_P_T */

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_S_T */

/* Parameters for system: '<S3>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_oneshotadd_T_ P_EnabledSubsystem_oneshotadd_T;

/* Parameters (default storage) */
typedef struct P_oneshotadder_T_ P_oneshotadder_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_oneshotadder_T RT_MODEL_oneshotadder_T;

#endif                                 /* RTW_HEADER_oneshotadder_types_h_ */
