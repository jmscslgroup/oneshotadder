/*
 * oneshotadder.cpp
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

#include "oneshotadder.h"
#include "rtwtypes.h"
#include "oneshotadder_types.h"
#include "oneshotadder_private.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include <cstring>

/* Named constants for Chart: '<Root>/Chart' */
const uint8_T oneshotadder_IN_Const_th = 1U;
const uint8_T oneshotadder_IN_Init = 2U;
const uint8_T oneshotadder_IN_NO_ACTIVE_CHILD = 0U;

/* Block signals (default storage) */
B_oneshotadder_T oneshotadder_B;

/* Block states (default storage) */
DW_oneshotadder_T oneshotadder_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_oneshotadder_T oneshotadder_PrevZCX;

/* Real-time model */
RT_MODEL_oneshotadder_T oneshotadder_M_ = RT_MODEL_oneshotadder_T();
RT_MODEL_oneshotadder_T *const oneshotadder_M = &oneshotadder_M_;

/* Forward declaration for local functions */
static real_T oneshotadder_checkHigh(int8_T data);
static void oneshotadder_sf_msg_send_next(void);
static real_T oneshotadder_checkLow(int8_T data);
static void oneshotadd_sf_msg_send_previous(void);
static boolean_T oneshotadder_sf_msg_pop_next(void);
static boolean_T oneshotadde_sf_msg_pop_previous(void);
static void oneshotadde_sf_msg_discard_next(void);
static void oneshot_sf_msg_discard_previous(void);

/*
 * System initialize for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void oneshotad_EnabledSubsystem_Init(B_EnabledSubsystem_oneshotadd_T *localB,
  P_EnabledSubsystem_oneshotadd_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
   *  Outport: '<S11>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void oneshotadder_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_oneshotadder_std_msgs_Float64 *rtu_In1, B_EnabledSubsystem_oneshotadd_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S11>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
}

void oneshotadder_initQueue(Queue_real_T *q, QueuePolicy_T policy, int32_T
  capacity, Msg_real_T *qPool)
{
  /* Start for Queue generated from: '<Root>/Chart' */
  q->fPolicy = policy;
  q->fCapacity = capacity;
  q->fHead = -1;
  q->fTail = -1;
  q->fArray = qPool;
}

/* Function for Chart: '<Root>/sendNext' */
static real_T oneshotadder_checkHigh(int8_T data)
{
  return data == 1;
}

Msg_real_T oneshotadder_createMsg(const real_T *data)
{
  Msg_real_T msg;

  /* DiscreteEventSubgraph generated from: '<Root>/Chart' */
  msg.fData = *data;
  return msg;
}

int32_T oneshotadder_size(const Queue_real_T *q)
{
  int32_T size;

  /* Queue generated from: '<Root>/Chart' */
  if (q->fTail == -1) {
    size = 0;
  } else {
    size = (q->fTail - q->fHead) + 1;
    if (size <= 0) {
      size += q->fCapacity;
    }
  }

  /* End of Queue generated from: '<Root>/Chart' */
  return size;
}

boolean_T oneshotadder_push(Queue_real_T *q, const Msg_real_T *element)
{
  int32_T newTail;
  boolean_T isPush;

  /* Queue generated from: '<Root>/Chart' */
  newTail = (q->fTail + 1) % q->fCapacity;
  if (q->fHead == newTail) {
    isPush = false;
  } else {
    q->fTail = newTail;
    q->fArray[newTail] = *element;
    if (q->fHead == -1) {
      q->fHead = q->fTail;
    }

    isPush = true;
  }

  /* End of Queue generated from: '<Root>/Chart' */
  return isPush;
}

int32_T oneshotadder_Chart_In1_SendData(const real_T *data)
{
  Msg_real_T msg;
  int32_T status = 1;
  boolean_T cond;

  /* DiscreteEventSubgraph generated from: '<Root>/Chart' incorporates:
   *  Queue generated from: '<Root>/Chart'
   */
  msg = oneshotadder_createMsg(data);
  cond = (oneshotadder_size(&oneshotadder_DW.Queue_InsertedFor_Chart_at_in_c) <
          oneshotadder_DW.Queue_InsertedFor_Chart_at_in_c.fCapacity);
  if (cond && oneshotadder_push(&oneshotadder_DW.Queue_InsertedFor_Chart_at_in_c,
       &msg)) {
    status = 0;
  }

  /* End of DiscreteEventSubgraph generated from: '<Root>/Chart' */
  return status;
}

/* Function for Chart: '<Root>/sendNext' */
static void oneshotadder_sf_msg_send_next(void)
{
  oneshotadder_Chart_In1_SendData(&oneshotadder_DW.next_msgData);
}

/* Function for Chart: '<Root>/sendPrevious' */
static real_T oneshotadder_checkLow(int8_T data)
{
  return data == -1;
}

int32_T oneshotadder_Chart_In2_SendData(const real_T *data)
{
  Msg_real_T msg;
  int32_T status = 1;
  boolean_T cond;

  /* DiscreteEventSubgraph generated from: '<Root>/Chart' incorporates:
   *  Queue generated from: '<Root>/Chart'
   */
  msg = oneshotadder_createMsg(data);
  cond = (oneshotadder_size(&oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ou) <
          oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ou.fCapacity);
  if (cond && oneshotadder_push(&oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ou,
       &msg)) {
    status = 0;
  }

  /* End of DiscreteEventSubgraph generated from: '<Root>/Chart' */
  return status;
}

/* Function for Chart: '<Root>/sendPrevious' */
static void oneshotadd_sf_msg_send_previous(void)
{
  oneshotadder_Chart_In2_SendData(&oneshotadder_DW.previous_msgData);
}

boolean_T oneshotadder_pop(Queue_real_T *q, Msg_real_T *elementOut)
{
  boolean_T isPop;

  /* Queue generated from: '<Root>/Chart' */
  if (q->fHead == -1) {
    isPop = false;
  } else {
    *elementOut = q->fArray[q->fHead];
    isPop = true;
    if (q->fHead == q->fTail) {
      q->fHead = -1;
      q->fTail = -1;
    } else {
      q->fHead = (q->fHead + 1) % q->fCapacity;
    }
  }

  /* End of Queue generated from: '<Root>/Chart' */
  return isPop;
}

Msg_real_T *oneshotadder_Chart_In1_RecvMsg(void)
{
  Msg_real_T *msg;

  /* DiscreteEventSubgraph generated from: '<Root>/Chart' */
  msg = &oneshotadder_DW.Queue_InsertedFor_Chart_at_in_o;

  /* Queue generated from: '<Root>/Chart' incorporates:
   *  DiscreteEventSubgraph generated from: '<Root>/Chart'
   */
  if (!oneshotadder_pop(&oneshotadder_DW.Queue_InsertedFor_Chart_at_in_c,
                        &oneshotadder_DW.Queue_InsertedFor_Chart_at_in_o)) {
    msg = NULL;
  }

  /* End of Queue generated from: '<Root>/Chart' */
  return msg;
}

/* Function for Chart: '<Root>/Chart' */
static boolean_T oneshotadder_sf_msg_pop_next(void)
{
  boolean_T isPresent;
  if (oneshotadder_DW.next_isValid) {
    isPresent = true;
  } else {
    oneshotadder_DW.next_msgHandle = oneshotadder_Chart_In1_RecvMsg();
    if (oneshotadder_DW.next_msgHandle != NULL) {
      oneshotadder_DW.next_msgDataPtr = &(static_cast<Msg_real_T *>
        (oneshotadder_DW.next_msgHandle))->fData;
      isPresent = true;
    } else {
      isPresent = false;
    }

    oneshotadder_DW.next_isValid = isPresent;
  }

  return isPresent;
}

Msg_real_T *oneshotadder_Chart_In2_RecvMsg(void)
{
  Msg_real_T *msg;

  /* DiscreteEventSubgraph generated from: '<Root>/Chart' */
  msg = &oneshotadder_DW.Queue_InsertedFor_Chart_at_in_n;

  /* Queue generated from: '<Root>/Chart' incorporates:
   *  DiscreteEventSubgraph generated from: '<Root>/Chart'
   */
  if (!oneshotadder_pop(&oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ou,
                        &oneshotadder_DW.Queue_InsertedFor_Chart_at_in_n)) {
    msg = NULL;
  }

  /* End of Queue generated from: '<Root>/Chart' */
  return msg;
}

/* Function for Chart: '<Root>/Chart' */
static boolean_T oneshotadde_sf_msg_pop_previous(void)
{
  boolean_T isPresent;
  if (oneshotadder_DW.previous_isValid) {
    isPresent = true;
  } else {
    oneshotadder_DW.previous_msgHandle = oneshotadder_Chart_In2_RecvMsg();
    if (oneshotadder_DW.previous_msgHandle != NULL) {
      oneshotadder_DW.previous_msgDataPtr = &(static_cast<Msg_real_T *>
        (oneshotadder_DW.previous_msgHandle))->fData;
      isPresent = true;
    } else {
      isPresent = false;
    }

    oneshotadder_DW.previous_isValid = isPresent;
  }

  return isPresent;
}

/* Function for Chart: '<Root>/Chart' */
static void oneshotadde_sf_msg_discard_next(void)
{
  oneshotadder_DW.next_isValid = false;
}

/* Function for Chart: '<Root>/Chart' */
static void oneshot_sf_msg_discard_previous(void)
{
  oneshotadder_DW.previous_isValid = false;
}

/* Model step function */
void oneshotadder_step(void)
{
  SL_Bus_oneshotadder_std_msgs_Float64 b_varargout_2;
  SL_Bus_oneshotadder_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_oneshotadder_std_msgs_Int8 b_varargout_2_0;
  SL_Bus_oneshotadder_std_msgs_UInt8 rtb_BusAssignment;
  boolean_T b_varargout_1;
  ZCEventType zcEvent;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
  /* MATLABSystem: '<S5>/SourceBlock' */
  b_varargout_1 = Sub_oneshotadder_14.getLatestMessage(&b_varargout_2_0);

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (b_varargout_1) {
    /* SignalConversion generated from: '<S13>/In1' */
    oneshotadder_B.In1 = b_varargout_2_0;
  }

  /* End of MATLABSystem: '<S5>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

  /* SignalConversion generated from: '<Root>/Bus Selector1' */
  oneshotadder_B.Data = oneshotadder_B.In1.Data;

  /* Chart: '<Root>/sendNext' incorporates:
   *  TriggerPort: '<S7>/event'
   */
  zcEvent = rt_I32ZCFcn(RISING_ZERO_CROSSING,
                        &oneshotadder_PrevZCX.sendNext_Trig_ZCE,
                        (oneshotadder_B.Data));
  if (zcEvent != NO_ZCEVENT) {
    if (oneshotadder_DW.is_active_c4_oneshotadder == 0U) {
      oneshotadder_DW.is_active_c4_oneshotadder = 1U;
    } else if (oneshotadder_checkHigh(oneshotadder_B.Data) != 0.0) {
      oneshotadder_DW.next_msgData = 1.0;
      oneshotadder_sf_msg_send_next();
    }
  }

  /* Chart: '<Root>/sendPrevious' incorporates:
   *  TriggerPort: '<S8>/event'
   */
  zcEvent = rt_I32ZCFcn(FALLING_ZERO_CROSSING,
                        &oneshotadder_PrevZCX.sendPrevious_Trig_ZCE,
                        (oneshotadder_B.Data));
  if (zcEvent != NO_ZCEVENT) {
    if (oneshotadder_DW.is_active_c5_oneshotadder == 0U) {
      oneshotadder_DW.is_active_c5_oneshotadder = 1U;
    } else if (oneshotadder_checkLow(oneshotadder_B.Data) != 0.0) {
      oneshotadder_DW.previous_msgData = 1.0;
      oneshotadd_sf_msg_send_previous();
    }
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
  /* MATLABSystem: '<S3>/SourceBlock' */
  b_varargout_1 = Sub_oneshotadder_38.getLatestMessage(&b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  oneshotadder_EnabledSubsystem(b_varargout_1, &b_varargout_2,
    &oneshotadder_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_oneshotadder_43.getLatestMessage(&b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  oneshotadder_EnabledSubsystem(b_varargout_1, &b_varargout_2,
    &oneshotadder_B.EnabledSubsystem_e);

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe1' */

  /* Chart: '<Root>/Chart' */
  oneshotadder_DW.next_isValid = false;
  oneshotadder_DW.previous_isValid = false;
  if (oneshotadder_DW.is_active_c1_oneshotadder == 0U) {
    oneshotadder_DW.is_active_c1_oneshotadder = 1U;
    oneshotadder_DW.is_c1_oneshotadder = oneshotadder_IN_Init;
    oneshotadder_B.mode = 1U;
    oneshotadder_B.output = -1.0;
  } else if (oneshotadder_DW.is_c1_oneshotadder == oneshotadder_IN_Const_th) {
    oneshotadder_B.mode = 2U;
    if (oneshotadder_sf_msg_pop_next()) {
      oneshotadder_B.mode = 2U;
    } else if (oneshotadde_sf_msg_pop_previous()) {
      oneshotadder_DW.is_c1_oneshotadder = oneshotadder_IN_Init;
      oneshotadder_B.mode = 1U;
      oneshotadder_B.output = -1.0;
    }
  } else {
    /* case IN_Init: */
    oneshotadder_B.mode = 1U;
    if (oneshotadder_sf_msg_pop_next()) {
      oneshotadder_B.output = oneshotadder_B.EnabledSubsystem.In1.Data +
        oneshotadder_B.EnabledSubsystem_e.In1.Data;
      oneshotadder_DW.is_c1_oneshotadder = oneshotadder_IN_Const_th;
      oneshotadder_B.mode = 2U;
    }
  }

  oneshotadde_sf_msg_discard_next();
  oneshot_sf_msg_discard_previous();

  /* End of Chart: '<Root>/Chart' */

  /* BusAssignment: '<S2>/Bus Assignment1' */
  rtb_BusAssignment1.Data = oneshotadder_B.output;

  /* Outputs for Atomic SubSystem: '<S2>/Publish1' */
  /* MATLABSystem: '<S9>/SinkBlock' */
  Pub_oneshotadder_5.publish(&rtb_BusAssignment1);

  /* End of Outputs for SubSystem: '<S2>/Publish1' */
  /* BusAssignment: '<S6>/Bus Assignment' */
  rtb_BusAssignment.Data = oneshotadder_B.mode;

  /* Outputs for Atomic SubSystem: '<S6>/Publish' */
  /* MATLABSystem: '<S14>/SinkBlock' */
  Pub_oneshotadder_1.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<S6>/Publish' */
}

/* Model initialize function */
void oneshotadder_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&oneshotadder_B)), 0,
                sizeof(B_oneshotadder_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&oneshotadder_DW), 0,
                sizeof(DW_oneshotadder_T));

  {
    char_T b_zeroDelimTopic[12];
    char_T b_zeroDelimTopic_1[7];
    char_T b_zeroDelimTopic_2[5];
    char_T b_zeroDelimTopic_0[4];
    static const char_T tmp[11] = { 'm', 'o', 'd', 'e', 'C', 'h', 'a', 'n', 'g',
      'e', 'r' };

    static const char_T tmp_0[6] = { 'o', 'u', 't', 'p', 'u', 't' };

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    oneshotadder_DW.obj_p.matlabCodegenIsDeleted = false;
    oneshotadder_DW.objisempty_d = true;
    oneshotadder_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[11] = '\x00';
    Sub_oneshotadder_14.createSubscriber(&b_zeroDelimTopic[0], 1);
    oneshotadder_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Queue generated from: '<Root>/Chart' */
    oneshotadder_initQueue(&oneshotadder_DW.Queue_InsertedFor_Chart_at_in_c,
      MSG_FIFO_QUEUE, 10, &oneshotadder_DW.Queue_InsertedFor_Chart_at_inpo[0]);

    /* Start for Queue generated from: '<Root>/Chart' */
    oneshotadder_initQueue(&oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ou,
      MSG_FIFO_QUEUE, 10, &oneshotadder_DW.Queue_InsertedFor_Chart_at_i_ol[0]);

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    oneshotadder_DW.obj_h.matlabCodegenIsDeleted = false;
    oneshotadder_DW.objisempty_l = true;
    oneshotadder_DW.obj_h.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'i';
    b_zeroDelimTopic_0[1] = 'n';
    b_zeroDelimTopic_0[2] = '1';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_oneshotadder_38.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    oneshotadder_DW.obj_h.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    oneshotadder_DW.obj_f.matlabCodegenIsDeleted = false;
    oneshotadder_DW.objisempty_a = true;
    oneshotadder_DW.obj_f.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'i';
    b_zeroDelimTopic_0[1] = 'n';
    b_zeroDelimTopic_0[2] = '2';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_oneshotadder_43.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    oneshotadder_DW.obj_f.isSetupComplete = true;

    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<S2>/Publish1' */
    /* Start for MATLABSystem: '<S9>/SinkBlock' */
    oneshotadder_DW.obj_d.matlabCodegenIsDeleted = false;
    oneshotadder_DW.objisempty_o = true;
    oneshotadder_DW.obj_d.isInitialized = 1;
    for (int32_T i = 0; i < 6; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[6] = '\x00';
    Pub_oneshotadder_5.createPublisher(&b_zeroDelimTopic_1[0], 1);
    oneshotadder_DW.obj_d.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S9>/SinkBlock' */
    /* End of Start for SubSystem: '<S2>/Publish1' */

    /* Start for Atomic SubSystem: '<S6>/Publish' */
    /* Start for MATLABSystem: '<S14>/SinkBlock' */
    oneshotadder_DW.obj.matlabCodegenIsDeleted = false;
    oneshotadder_DW.objisempty = true;
    oneshotadder_DW.obj.isInitialized = 1;
    b_zeroDelimTopic_2[0] = 'm';
    b_zeroDelimTopic_2[1] = 'o';
    b_zeroDelimTopic_2[2] = 'd';
    b_zeroDelimTopic_2[3] = 'e';
    b_zeroDelimTopic_2[4] = '\x00';
    Pub_oneshotadder_1.createPublisher(&b_zeroDelimTopic_2[0], 1);
    oneshotadder_DW.obj.isSetupComplete = true;

    /* End of Start for SubSystem: '<S6>/Publish' */
  }

  oneshotadder_PrevZCX.sendNext_Trig_ZCE = UNINITIALIZED_ZCSIG;
  oneshotadder_PrevZCX.sendPrevious_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
   *  Outport: '<S13>/Out1'
   */
  oneshotadder_B.In1 = oneshotadder_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Chart: '<Root>/sendNext' */
  oneshotadder_DW.is_active_c4_oneshotadder = 0U;

  /* SystemInitialize for Chart: '<Root>/sendPrevious' */
  oneshotadder_DW.is_active_c5_oneshotadder = 0U;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  oneshotad_EnabledSubsystem_Init(&oneshotadder_B.EnabledSubsystem,
    &oneshotadder_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  oneshotad_EnabledSubsystem_Init(&oneshotadder_B.EnabledSubsystem_e,
    &oneshotadder_P.EnabledSubsystem_e);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */

  /* SystemInitialize for Chart: '<Root>/Chart' */
  oneshotadder_DW.is_active_c1_oneshotadder = 0U;
  oneshotadder_DW.is_c1_oneshotadder = oneshotadder_IN_NO_ACTIVE_CHILD;
  oneshotadder_B.mode = 0U;
  oneshotadder_B.output = 0.0;
}

/* Model terminate function */
void oneshotadder_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!oneshotadder_DW.obj_p.matlabCodegenIsDeleted) {
    oneshotadder_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  if (!oneshotadder_DW.obj_h.matlabCodegenIsDeleted) {
    oneshotadder_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!oneshotadder_DW.obj_f.matlabCodegenIsDeleted) {
    oneshotadder_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<S2>/Publish1' */
  /* Terminate for MATLABSystem: '<S9>/SinkBlock' */
  if (!oneshotadder_DW.obj_d.matlabCodegenIsDeleted) {
    oneshotadder_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S9>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S2>/Publish1' */

  /* Terminate for Atomic SubSystem: '<S6>/Publish' */
  /* Terminate for MATLABSystem: '<S14>/SinkBlock' */
  if (!oneshotadder_DW.obj.matlabCodegenIsDeleted) {
    oneshotadder_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S14>/SinkBlock' */
  /* End of Terminate for SubSystem: '<S6>/Publish' */
}
