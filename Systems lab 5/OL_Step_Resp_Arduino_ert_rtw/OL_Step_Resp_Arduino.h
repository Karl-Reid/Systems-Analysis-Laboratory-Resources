/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OL_Step_Resp_Arduino.h
 *
 * Code generated for Simulink model 'OL_Step_Resp_Arduino'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Oct 17 16:30:13 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_OL_Step_Resp_Arduino_h_
#define RTW_HEADER_OL_Step_Resp_Arduino_h_
#include <stddef.h>
#include <string.h>
#ifndef OL_Step_Resp_Arduino_COMMON_INCLUDES_
# define OL_Step_Resp_Arduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_digitalio.h"
#include "MW_SerialWrite.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* OL_Step_Resp_Arduino_COMMON_INCLUDES_ */

#include "OL_Step_Resp_Arduino_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T DataTypeConversion;         /* '<S6>/Data Type Conversion' */
  int16_T QuadEncoderPins23_o1;        /* '<S5>/Quad Encoder Pins 2 & 3' */
  int16_T QuadEncoderPins23_o2;        /* '<S5>/Quad Encoder Pins 2 & 3' */
  int16_T QuadEncoderPins23_o3;        /* '<S5>/Quad Encoder Pins 2 & 3' */
  uint8_T SingleinByteStreamOut[4];    /* '<S6>/Single  in Byte Stream Out' */
} B_OL_Step_Resp_Arduino_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S6>/Serial Transmit' */
  real_T QuadEncoderPins23_DSTATE;     /* '<S5>/Quad Encoder Pins 2 & 3' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T DiscreteFilter_states;        /* '<Root>/Discrete Filter' */
  void *SerialTransmit_PWORK;          /* '<S6>/Serial Transmit' */
  void *DigitalOutput_PWORK;           /* '<S2>/Digital Output' */
  codertarget_arduinobase_block_T obj_k;/* '<S2>/Digital Output' */
} DW_OL_Step_Resp_Arduino_T;

/* Parameters (auto storage) */
struct P_OL_Step_Resp_Arduino_T_ {
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<Root>/Velocity Scaling'
                                        */
  real_T rp;                           /* Variable: rp
                                        * Referenced by: '<Root>/Steps to Radians'
                                        */
  real_T Difference_ICPrevInput;       /* Mask Parameter: Difference_ICPrevInput
                                        * Referenced by: '<S1>/UD'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  real_T Constant_Value;               /* Expression: 5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T MotorVoltageMax_Value;        /* Expression: 9
                                        * Referenced by: '<Root>/MotorVoltageMax'
                                        */
  real_T _Value;                       /* Expression: 255
                                        * Referenced by: '<Root>/ '
                                        */
  real_T DiscreteFilter_NumCoef;       /* Expression: [0.1]
                                        * Referenced by: '<Root>/Discrete Filter'
                                        */
  real_T DiscreteFilter_DenCoef[2];    /* Expression: [1 -0.9]
                                        * Referenced by: '<Root>/Discrete Filter'
                                        */
  real_T DiscreteFilter_InitialStates; /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Filter'
                                        */
  uint8_T QuadEncoderPins23_P1;        /* Expression: uint8(0)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
  uint8_T QuadEncoderPins23_P2;        /* Expression: uint8(2)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
  uint8_T QuadEncoderPins23_P3;        /* Expression: uint8(3)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_OL_Step_Resp_Arduino_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_P;

/* Block signals (auto storage) */
extern B_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_B;

/* Block states (auto storage) */
extern DW_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_DW;

/* Model entry point functions */
extern void OL_Step_Resp_Arduino_initialize(void);
extern void OL_Step_Resp_Arduino_step(void);
extern void OL_Step_Resp_Arduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_OL_Step_Resp_Arduino_T *const OL_Step_Resp_Arduino_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
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
 * '<Root>' : 'OL_Step_Resp_Arduino'
 * '<S1>'   : 'OL_Step_Resp_Arduino/Difference'
 * '<S2>'   : 'OL_Step_Resp_Arduino/Digital Output - Motor Direction'
 * '<S3>'   : 'OL_Step_Resp_Arduino/Motor Direction and Speed Logic'
 * '<S4>'   : 'OL_Step_Resp_Arduino/PWM'
 * '<S5>'   : 'OL_Step_Resp_Arduino/QuadEncoder'
 * '<S6>'   : 'OL_Step_Resp_Arduino/Serial Send single Port0'
 * '<S7>'   : 'OL_Step_Resp_Arduino/QuadEncoder/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_OL_Step_Resp_Arduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
