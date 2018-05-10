/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OL_Step_Resp_Arduino_data.c
 *
 * Code generated for Simulink model 'OL_Step_Resp_Arduino'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Oct 19 17:07:57 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "OL_Step_Resp_Arduino.h"
#include "OL_Step_Resp_Arduino_private.h"

/* Block parameters (auto storage) */
P_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_P = {
  0.01,                                /* Variable: Ts
                                        * Referenced by: '<Root>/Velocity Scaling'
                                        */
  0.0047029830143559773,               /* Variable: rp
                                        * Referenced by: '<Root>/Steps to Radians'
                                        */
  0.0,                                 /* Mask Parameter: Difference_ICPrevInput
                                        * Referenced by: '<S1>/UD'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S2>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S4>/PWM'
                                        */
  0U,                                  /* Mask Parameter: SerialTransmit_portNumber
                                        * Referenced by: '<S6>/Serial Transmit'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Ref'
                                        */
  9.0,                                 /* Expression: 9
                                        * Referenced by: '<Root>/MotorVoltageMax'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.1,                                 /* Expression: [0.1]
                                        * Referenced by: '<Root>/Discrete Filter'
                                        */

  /*  Expression: [1 -0.9]
   * Referenced by: '<Root>/Discrete Filter'
   */
  { 1.0, -0.9 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete Filter'
                                        */
  0U,                                  /* Expression: uint8(0)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
  2U,                                  /* Expression: uint8(2)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
  3U                                   /* Expression: uint8(3)
                                        * Referenced by: '<S5>/Quad Encoder Pins 2 & 3'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
