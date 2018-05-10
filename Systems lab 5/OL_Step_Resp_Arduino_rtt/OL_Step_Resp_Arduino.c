/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: OL_Step_Resp_Arduino.c
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

/* Block signals (auto storage) */
B_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_B;

/* Block states (auto storage) */
DW_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_DW;

/* Real-time model */
RT_MODEL_OL_Step_Resp_Arduino_T OL_Step_Resp_Arduino_M_;
RT_MODEL_OL_Step_Resp_Arduino_T *const OL_Step_Resp_Arduino_M =
  &OL_Step_Resp_Arduino_M_;

/* Model output function */
void OL_Step_Resp_Arduino_output(void)
{
  real_T rtb_y1;
  real_T rtb_y_a;
  uint8_T rtb_y_h;

  /* MATLAB Function: '<Root>/Motor Direction and Speed Logic' incorporates:
   *  Constant: '<Root>/Ref'
   */
  /* MATLAB Function 'Motor Direction and Speed Logic': '<S3>:1' */
  if (OL_Step_Resp_Arduino_P.Ref_Value >= 0.0) {
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    rtb_y_a = OL_Step_Resp_Arduino_P.Ref_Value;

    /* '<S3>:1:5' */
    rtb_y1 = 0.0;
  } else {
    /* '<S3>:1:7' */
    rtb_y_a = -OL_Step_Resp_Arduino_P.Ref_Value;

    /* '<S3>:1:8' */
    rtb_y1 = 1.0;
  }

  /* End of MATLAB Function: '<Root>/Motor Direction and Speed Logic' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  MW_digitalWrite(OL_Step_Resp_Arduino_P.DigitalOutput_pinNumber, (uint8_T)
                  (int16_T)rtb_y1);

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/MotorVoltageMax'
   *  Product: '<Root>/Divide'
   */
  rtb_y_a = rtb_y_a / OL_Step_Resp_Arduino_P.MotorVoltageMax_Value *
    OL_Step_Resp_Arduino_P.Constant_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  if (rtb_y_a < 256.0) {
    if (rtb_y_a >= 0.0) {
      rtb_y_h = (uint8_T)rtb_y_a;
    } else {
      rtb_y_h = 0U;
    }
  } else {
    rtb_y_h = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_analogWrite(OL_Step_Resp_Arduino_P.PWM_pinNumber, rtb_y_h);

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
  /* '<S7>:1:6' */
  OL_Step_Resp_Arduino_B.StepstoRadians = (real_T)
    ((OL_Step_Resp_Arduino_B.QuadEncoderPins23_o2 * 32767L +
      OL_Step_Resp_Arduino_B.QuadEncoderPins23_o3 * -32767L) +
     OL_Step_Resp_Arduino_B.QuadEncoderPins23_o1) * OL_Step_Resp_Arduino_P.rp;

  /* DiscreteFilter: '<Root>/Discrete Filter' incorporates:
   *  Gain: '<Root>/Velocity Scaling'
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  OL_Step_Resp_Arduino_DW.DiscreteFilter_tmp = (1.0 / OL_Step_Resp_Arduino_P.Ts *
    (OL_Step_Resp_Arduino_B.StepstoRadians - OL_Step_Resp_Arduino_DW.UD_DSTATE)
    - OL_Step_Resp_Arduino_P.DiscreteFilter_DenCoef[1L] *
    OL_Step_Resp_Arduino_DW.DiscreteFilter_states) /
    OL_Step_Resp_Arduino_P.DiscreteFilter_DenCoef[0];

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  DiscreteFilter: '<Root>/Discrete Filter'
   */
  OL_Step_Resp_Arduino_B.DataTypeConversion = (real32_T)
    (OL_Step_Resp_Arduino_P.DiscreteFilter_NumCoef *
     OL_Step_Resp_Arduino_DW.DiscreteFilter_tmp);

  /* S-Function (sf_float2bytes): '<S6>/Single  in Byte Stream Out' */
  sf_float2bytes_Outputs_wrapper(&OL_Step_Resp_Arduino_B.DataTypeConversion,
    &OL_Step_Resp_Arduino_B.SingleinByteStreamOut[0] );

  /* S-Function (arduinoserialwrite_sfcn): '<S6>/Serial Transmit' */
  Serial_write(OL_Step_Resp_Arduino_P.SerialTransmit_portNumber,
               OL_Step_Resp_Arduino_B.SingleinByteStreamOut, 4UL);
}

/* Model update function */
void OL_Step_Resp_Arduino_update(void)
{
  /* S-Function "sf_QuadEncoderCarion_wrapper" Block: <S5>/Quad Encoder Pins 2 & 3 */
  sf_QuadEncoderCarion_Update_wrapper
    ( &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o1,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o2,
     &OL_Step_Resp_Arduino_B.QuadEncoderPins23_o3,
     &OL_Step_Resp_Arduino_DW.QuadEncoderPins23_DSTATE,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P1, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P2, 1,
     &OL_Step_Resp_Arduino_P.QuadEncoderPins23_P3, 1);

  /* Update for UnitDelay: '<S1>/UD' */
  OL_Step_Resp_Arduino_DW.UD_DSTATE = OL_Step_Resp_Arduino_B.StepstoRadians;

  /* Update for DiscreteFilter: '<Root>/Discrete Filter' */
  OL_Step_Resp_Arduino_DW.DiscreteFilter_states =
    OL_Step_Resp_Arduino_DW.DiscreteFilter_tmp;
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

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(OL_Step_Resp_Arduino_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S4>/PWM' */
  MW_pinModeOutput(OL_Step_Resp_Arduino_P.PWM_pinNumber);

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

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  OL_Step_Resp_Arduino_DW.UD_DSTATE =
    OL_Step_Resp_Arduino_P.Difference_ICPrevInput;

  /* InitializeConditions for DiscreteFilter: '<Root>/Discrete Filter' */
  OL_Step_Resp_Arduino_DW.DiscreteFilter_states =
    OL_Step_Resp_Arduino_P.DiscreteFilter_InitialStates;
}

/* Model terminate function */
void OL_Step_Resp_Arduino_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
