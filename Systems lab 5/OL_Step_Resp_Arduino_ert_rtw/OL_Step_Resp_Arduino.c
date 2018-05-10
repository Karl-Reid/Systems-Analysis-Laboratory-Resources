/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OL_Step_Resp_Arduino.c
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

#include "OL_Step_Resp_Arduino.h"
#include "OL_Step_Resp_Arduino_private.h"
#define OL_Step_Resp_Arduino_PinNumber (4.0)

/* Block signals (auto storage) */
B_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_B;

/* Block states (auto storage) */
DW_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_DW;

/* Real-time model */
RT_MODEL_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_M_;
RT_MODEL_OL_Step_Resp_Arduino_T *const OL_Step_Resp_Arduino_M =
  &OL_Step_Resp_Arduino_M_;

/* Model step function */
void OL_Step_Resp_Arduino_step(void)
{
  int8_T inSize[8];
  int16_T k;
  uint8_T dataIn[4];
  real_T rtb_y1;
  real_T rtb_y_j;
  uint8_T rtb_y_g;
  boolean_T exitg1;

  /* MATLAB Function: '<Root>/Motor Direction and Speed Logic' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'Motor Direction and Speed Logic': '<S3>:1' */
  /* '<S3>:1:3' if x>=0 */
  if (OL_Step_Resp_Arduino_P.Constant_Value >= 0.0) {
    /* '<S3>:1:4' y=x; */
    rtb_y_j = OL_Step_Resp_Arduino_P.Constant_Value;

    /* '<S3>:1:5' y1=0; */
    rtb_y1 = 0.0;
  } else {
    /* '<S3>:1:6' else */
    /* '<S3>:1:7' y=-x; */
    rtb_y_j = -OL_Step_Resp_Arduino_P.Constant_Value;

    /* '<S3>:1:8' y1=1; */
    rtb_y1 = 1.0;
  }

  /* End of MATLAB Function: '<Root>/Motor Direction and Speed Logic' */

  /* Start for MATLABSystem: '<S2>/Digital Output' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  MATLABSystem: '<S2>/Digital Output'
   */
  writeDigitalPin((uint8_T)OL_Step_Resp_Arduino_PinNumber, (uint8_T)(int16_T)
                  rtb_y1);

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/ '
   *  Constant: '<Root>/MotorVoltageMax'
   *  Product: '<Root>/Divide'
   */
  rtb_y_j = rtb_y_j / OL_Step_Resp_Arduino_P.MotorVoltageMax_Value *
    OL_Step_Resp_Arduino_P._Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_y_j < 256.0) {
    if (rtb_y_j >= 0.0) {
      rtb_y_g = (uint8_T)rtb_y_j;
    } else {
      rtb_y_g = 0U;
    }
  } else {
    rtb_y_g = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(OL_Step_Resp_Arduino_P.PWM_pinNumber, rtb_y_g);

  /* S-Function (sf_QuadEncoderCarion): '<S5>/Quad Encoder Pins 2 & 3' */
  sf_QuadEncoderCarion_Outputs_wrapper
    ( &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o1,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o2,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o3,
     &OL_Step_Resp_Arduino_DW.QuadEncoderPins23_DSTATE,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P1, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P2, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P3, 1);

  /* Gain: '<Root>/Steps to Radians' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  DataTypeConversion: '<S5>/Data Type Conversion2'
   *  MATLAB Function: '<S5>/MATLAB Function'
   */
  /* MATLAB Function 'QuadEncoder/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:3' max = 32767; */
  /* '<S7>:1:4' min = -32767; */
  /* '<S7>:1:6' y = u1*max + u2*min + u; */
  rtb_y1 = (real_T)((OL_Step_Resp_Arduino_B.QuadEncoderPins23_o2 * 32767L +
                     OL_Step_Resp_Arduino_B.QuadEncoderPins23_o3 * -32767L) +
                    OL_Step_Resp_Arduino_B.QuadEncoderPins23_o1) *
    OL_Step_Resp_Arduino_P.rp;

  /* DiscreteFilter: '<Root>/Discrete Filter' incorporates:
   *  Gain: '<Root>/Velocity Scaling'
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  rtb_y_j = (1.0 / OL_Step_Resp_Arduino_P.Ts * (rtb_y1 -
              OL_Step_Resp_Arduino_DW.UD_DSTATE) -
             OL_Step_Resp_Arduino_P.DiscreteFilter_DenCoef[1L] *
             OL_Step_Resp_Arduino_DW.DiscreteFilter_states) /
    OL_Step_Resp_Arduino_P.DiscreteFilter_DenCoef[0];

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  DiscreteFilter: '<Root>/Discrete Filter'
   */
  OL_Step_Resp_Arduino_B.DataTypeConversion = (real32_T)
    (OL_Step_Resp_Arduino_P.DiscreteFilter_NumCoef * rtb_y_j);

  /* S-Function (sf_float2bytes): '<S6>/Single  in Byte Stream Out' */
  sf_float2bytes_Outputs_wrapper(&OL_Step_Resp_Arduino_B.DataTypeConversion,
    &OL_Step_Resp_Arduino_B.SingleinByteStreamOut[0] );

  /* Start for MATLABSystem: '<S6>/Serial Transmit' incorporates:
   *  MATLABSystem: '<S6>/Serial Transmit'
   */
  inSize[0] = 4;
  inSize[1] = 1;
  for (k = 0; k < 6; k++) {
    inSize[k + 2] = 1;
  }

  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (OL_Step_Resp_Arduino_DW.obj.inputVarSize.f1[k] != (uint32_T)inSize[k]) {
      for (k = 0; k < 8; k++) {
        OL_Step_Resp_Arduino_DW.obj.inputVarSize.f1[k] = (uint32_T)inSize[k];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  dataIn[0] = OL_Step_Resp_Arduino_B.SingleinByteStreamOut[0];
  dataIn[1] = OL_Step_Resp_Arduino_B.SingleinByteStreamOut[1];
  dataIn[2] = OL_Step_Resp_Arduino_B.SingleinByteStreamOut[2];
  dataIn[3] = OL_Step_Resp_Arduino_B.SingleinByteStreamOut[3];
  MW_Serial_write(OL_Step_Resp_Arduino_DW.obj.port, dataIn, 4.0,
                  OL_Step_Resp_Arduino_DW.obj.dataSizeInBytes);

  /* End of Start for MATLABSystem: '<S6>/Serial Transmit' */

  /* S-Function "sf_QuadEncoderCarion_wrapper" Block: <S5>/Quad Encoder Pins 2 & 3 */
  sf_QuadEncoderCarion_Update_wrapper
    ( &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o1,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o2,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o3,
     &OL_Step_Resp_Arduino_DW.QuadEncoderPins23_DSTATE,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P1, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P2, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P3, 1);

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  OL_Step_Resp_Arduino_DW.UD_DSTATE = rtb_y1;

  /* Update for DiscreteFilter: '<Root>/Discrete Filter' */
  OL_Step_Resp_Arduino_DW.DiscreteFilter_states = rtb_y_j;
}

/* Model initialize function */
void OL_Step_Resp_Arduino_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(OL_Step_Resp_Arduino_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &OL_Step_Resp_Arduino_B), 0,
                sizeof(B_OL_Step_Resp_Arduino_T));

  /* states (dwork) */
  (void) memset((void *)&OL_Step_Resp_Arduino_DW, 0,
                sizeof(DW_OL_Step_Resp_Arduino_T));

  {
    cell_wrap_OL_Step_Resp_Arduin_T varSizes;
    int16_T i;

    /* Start for MATLABSystem: '<S2>/Digital Output' */
    OL_Step_Resp_Arduino_DW.obj_k.isInitialized = 0L;
    OL_Step_Resp_Arduino_DW.obj_k.isInitialized = 1L;
    digitalIOSetup((uint8_T)OL_Step_Resp_Arduino_PinNumber, true);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
    MW_pinModeOutput(OL_Step_Resp_Arduino_P.PWM_pinNumber);

    /* Start for MATLABSystem: '<S6>/Serial Transmit' */
    OL_Step_Resp_Arduino_DW.obj.isInitialized = 0L;
    OL_Step_Resp_Arduino_DW.obj.isInitialized = 1L;
    varSizes.f1[0] = 4UL;
    varSizes.f1[1] = 1UL;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1UL;
    }

    OL_Step_Resp_Arduino_DW.obj.inputVarSize = varSizes;
    OL_Step_Resp_Arduino_DW.obj.port = 0.0;
    OL_Step_Resp_Arduino_DW.obj.dataSizeInBytes = 1.0;

    /* End of Start for MATLABSystem: '<S6>/Serial Transmit' */

    /* S-Function Block: <S5>/Quad Encoder Pins 2 & 3 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          OL_Step_Resp_Arduino_DW.QuadEncoderPins23_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    OL_Step_Resp_Arduino_DW.UD_DSTATE =
      OL_Step_Resp_Arduino_P.Difference_ICPrevInput;

    /* InitializeConditions for DiscreteFilter: '<Root>/Discrete Filter' */
    OL_Step_Resp_Arduino_DW.DiscreteFilter_states =
      OL_Step_Resp_Arduino_P.DiscreteFilter_InitialStates;
  }
}

/* Model terminate function */
void OL_Step_Resp_Arduino_terminate(void)
{
  /* Start for MATLABSystem: '<S2>/Digital Output' incorporates:
   *  Terminate for MATLABSystem: '<S2>/Digital Output'
   */
  if (OL_Step_Resp_Arduino_DW.obj_k.isInitialized == 1L) {
    OL_Step_Resp_Arduino_DW.obj_k.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S2>/Digital Output' */

  /* Start for MATLABSystem: '<S6>/Serial Transmit' incorporates:
   *  Terminate for MATLABSystem: '<S6>/Serial Transmit'
   */
  if (OL_Step_Resp_Arduino_DW.obj.isInitialized == 1L) {
    OL_Step_Resp_Arduino_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S6>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
