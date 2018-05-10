/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OL_Step_Resp_Arduino_private.h
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

#ifndef RTW_HEADER_OL_Step_Resp_Arduino_private_h_
#define RTW_HEADER_OL_Step_Resp_Arduino_private_h_
#include "rtwtypes.h"

extern void sf_QuadEncoderCarion_Outputs_wrapper(int16_T *pos,
  int16_T *overflow,
  int16_T *underflow ,
  const real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const uint8_T *pinA, const int_T p_width1,
  const uint8_T *pinB, const int_T p_width2);
extern void sf_QuadEncoderCarion_Update_wrapper(const int16_T *pos,
  const int16_T *overflow,
  const int16_T *underflow ,
  real_T *xD,
  const uint8_T *enc, const int_T p_width0,
  const uint8_T *pinA, const int_T p_width1,
  const uint8_T *pinB, const int_T p_width2);
extern void sf_float2bytes_Outputs_wrapper(const real32_T *fin,
  uint8_T *bout);

#endif                                 /* RTW_HEADER_OL_Step_Resp_Arduino_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
