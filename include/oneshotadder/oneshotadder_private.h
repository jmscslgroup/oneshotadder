/*
 * oneshotadder_private.h
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

#ifndef RTW_HEADER_oneshotadder_private_h_
#define RTW_HEADER_oneshotadder_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "oneshotadder.h"
#include "oneshotadder_types.h"

/* Exported functions */
extern void oneshotadder_initQueue(Queue_real_T *q, QueuePolicy_T policy,
  int32_T capacity, Msg_real_T *qPool);
extern Msg_real_T oneshotadder_createMsg(const real_T *data);
extern int32_T oneshotadder_size(const Queue_real_T *q);
extern boolean_T oneshotadder_push(Queue_real_T *q, const Msg_real_T *element);
extern int32_T oneshotadder_Chart_In1_SendData(const real_T *data);
extern int32_T oneshotadder_Chart_In2_SendData(const real_T *data);
extern boolean_T oneshotadder_pop(Queue_real_T *q, Msg_real_T *elementOut);
extern Msg_real_T *oneshotadder_Chart_In1_RecvMsg(void);
extern Msg_real_T *oneshotadder_Chart_In2_RecvMsg(void);
extern void oneshotad_EnabledSubsystem_Init(B_EnabledSubsystem_oneshotadd_T
  *localB, P_EnabledSubsystem_oneshotadd_T *localP);
extern void oneshotadder_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_oneshotadder_std_msgs_Float64 *rtu_In1, B_EnabledSubsystem_oneshotadd_T
  *localB);

#endif                                 /* RTW_HEADER_oneshotadder_private_h_ */
