/*
 * oneshotadder.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "oneshotadder".
 *
 * Model version              : 6.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Nov 26 15:46:59 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_oneshotadder_h_
#define RTW_HEADER_oneshotadder_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include <stddef.h>
#include "oneshotadder_types.h"
#include "rt_i32zcfcn.h"
#include <string.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S3>/Enabled Subsystem' */
struct B_EnabledSubsystem_oneshotadd_T {
  SL_Bus_oneshotadder_std_msgs_Float64 In1;/* '<S11>/In1' */
};

/* Block signals (default storage) */
struct B_oneshotadder_T {
  real_T previous;                     /* '<Root>/sendPrevious' */
  real_T next;                         /* '<Root>/sendNext' */
  real_T output;                       /* '<Root>/Chart' */
  SL_Bus_oneshotadder_std_msgs_Int8 In1;/* '<S13>/In1' */
  uint8_T mode;                        /* '<Root>/Chart' */
  int8_T Data;
  B_EnabledSubsystem_oneshotadd_T EnabledSubsystem_e;/* '<S4>/Enabled Subsystem' */
  B_EnabledSubsystem_oneshotadd_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_oneshotadder_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S14>/SinkBlock' */
  ros_slroscpp_internal_block_P_T obj_d;/* '<S9>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_p;/* '<S5>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_f;/* '<S4>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_h;/* '<S3>/SourceBlock' */
  real_T previous_msgData;             /* '<Root>/sendPrevious' */
  real_T next_msgData;                 /* '<Root>/sendNext' */
  real_T next_msgData_m;               /* '<Root>/Chart' */
  real_T previous_msgData_i;           /* '<Root>/Chart' */
  Msg_real_T Queue_InsertedFor_Chart_at_inpo[10];/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_in_o;/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_i_ol[10];/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_in_n;/* synthesized block */
  Queue_real_T Queue_InsertedFor_Chart_at_in_c;/* synthesized block */
  Queue_real_T Queue_InsertedFor_Chart_at_i_ou;/* synthesized block */
  void* previous_msgInterface;         /* '<Root>/sendPrevious' */
  void* next_msgInterface;             /* '<Root>/sendNext' */
  void* next_msgInterface_j;           /* '<Root>/Chart' */
  void* next_msgHandle;                /* '<Root>/Chart' */
  void* next_msgDataPtr;               /* '<Root>/Chart' */
  void* previous_msgInterface_g;       /* '<Root>/Chart' */
  void* previous_msgHandle;            /* '<Root>/Chart' */
  void* previous_msgDataPtr;           /* '<Root>/Chart' */
  uint8_T is_active_c5_oneshotadder;   /* '<Root>/sendPrevious' */
  uint8_T is_active_c4_oneshotadder;   /* '<Root>/sendNext' */
  uint8_T is_c1_oneshotadder;          /* '<Root>/Chart' */
  uint8_T is_active_c1_oneshotadder;   /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<S14>/SinkBlock' */
  boolean_T objisempty_d;              /* '<S5>/SourceBlock' */
  boolean_T objisempty_a;              /* '<S4>/SourceBlock' */
  boolean_T objisempty_l;              /* '<S3>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S9>/SinkBlock' */
  boolean_T next_isValid;              /* '<Root>/Chart' */
  boolean_T previous_isValid;          /* '<Root>/Chart' */
};

/* Zero-crossing (trigger) state */
struct PrevZCX_oneshotadder_T {
  ZCSigState sendPrevious_Trig_ZCE;    /* '<Root>/sendPrevious' */
  ZCSigState sendNext_Trig_ZCE;        /* '<Root>/sendNext' */
};

/* Parameters for system: '<S3>/Enabled Subsystem' */
struct P_EnabledSubsystem_oneshotadd_T_ {
  SL_Bus_oneshotadder_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                * Referenced by: '<S11>/Out1'
                                                */
};

/* Parameters (default storage) */
struct P_oneshotadder_T_ {
  SL_Bus_oneshotadder_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                       * Referenced by: '<S10>/Constant'
                                                       */
  SL_Bus_oneshotadder_std_msgs_Float64 Constant_Value_h;/* Computed Parameter: Constant_Value_h
                                                         * Referenced by: '<S3>/Constant'
                                                         */
  SL_Bus_oneshotadder_std_msgs_Float64 Constant_Value_m;/* Computed Parameter: Constant_Value_m
                                                         * Referenced by: '<S4>/Constant'
                                                         */
  SL_Bus_oneshotadder_std_msgs_Int8 Out1_Y0;/* Computed Parameter: Out1_Y0
                                             * Referenced by: '<S13>/Out1'
                                             */
  SL_Bus_oneshotadder_std_msgs_Int8 Constant_Value_n;/* Computed Parameter: Constant_Value_n
                                                      * Referenced by: '<S5>/Constant'
                                                      */
  SL_Bus_oneshotadder_std_msgs_UInt8 Constant_Value_hb;/* Computed Parameter: Constant_Value_hb
                                                        * Referenced by: '<S15>/Constant'
                                                        */
  P_EnabledSubsystem_oneshotadd_T EnabledSubsystem_e;/* '<S4>/Enabled Subsystem' */
  P_EnabledSubsystem_oneshotadd_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_oneshotadder_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_oneshotadder_T oneshotadder_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_oneshotadder_T oneshotadder_B;

#ifdef __cplusplus

}

#endif

/* Block states (default storage) */
extern struct DW_oneshotadder_T oneshotadder_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_oneshotadder_T oneshotadder_PrevZCX;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void oneshotadder_initialize(void);
  extern void oneshotadder_step(void);
  extern void oneshotadder_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_oneshotadder_T *const oneshotadder_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'oneshotadder'
 * '<S1>'   : 'oneshotadder/Chart'
 * '<S2>'   : 'oneshotadder/Output Publisher'
 * '<S3>'   : 'oneshotadder/Subscribe'
 * '<S4>'   : 'oneshotadder/Subscribe1'
 * '<S5>'   : 'oneshotadder/Subscribe2'
 * '<S6>'   : 'oneshotadder/mode publisher'
 * '<S7>'   : 'oneshotadder/sendNext'
 * '<S8>'   : 'oneshotadder/sendPrevious'
 * '<S9>'   : 'oneshotadder/Output Publisher/Publish1'
 * '<S10>'  : 'oneshotadder/Output Publisher/setpoint'
 * '<S11>'  : 'oneshotadder/Subscribe/Enabled Subsystem'
 * '<S12>'  : 'oneshotadder/Subscribe1/Enabled Subsystem'
 * '<S13>'  : 'oneshotadder/Subscribe2/Enabled Subsystem'
 * '<S14>'  : 'oneshotadder/mode publisher/Publish'
 * '<S15>'  : 'oneshotadder/mode publisher/mode'
 */
#endif                                 /* RTW_HEADER_oneshotadder_h_ */
