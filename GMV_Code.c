/*
 * GMV_Code.c
 *
 * Code generation for model "GMV_Code".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Fri Aug 31 11:49:02 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GMV_Code.h"
#include "GMV_Code_private.h"

static void rate_scheduler(RT_MODEL_GMV_Code_T *const GMV_Code_M);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(RT_MODEL_GMV_Code_T *const GMV_Code_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (GMV_Code_M->Timing.TaskCounters.TID[1])++;
  if ((GMV_Code_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    GMV_Code_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tr;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    tr = u0 / u1;
    if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void GMV_Code_step(RT_MODEL_GMV_Code_T *const GMV_Code_M)
{
  P_GMV_Code_T *GMV_Code_P = ((P_GMV_Code_T *) GMV_Code_M->defaultParam);
  B_GMV_Code_T *GMV_Code_B = ((B_GMV_Code_T *) GMV_Code_M->blockIO);
  DW_GMV_Code_T *GMV_Code_DW = ((DW_GMV_Code_T *) GMV_Code_M->dwork);
  ExtU_GMV_Code_T *GMV_Code_U = (ExtU_GMV_Code_T *) GMV_Code_M->inputs;
  ExtY_GMV_Code_T *GMV_Code_Y = (ExtY_GMV_Code_T *) GMV_Code_M->outputs;
  int_T idxDelay;
  real_T rtb_Add2_a;
  real_T rtb_Switch;
  real_T rtb_Add;
  real_T rtb_yk;
  real_T rtb_Switch1;
  real_T rtb_IntegerDelay;
  real_T rtb_IntegerDelay2;
  real_T rtb_Sum;
  real_T rtb_Gain1_o;
  real_T rtb_Add6;
  real_T rtb_TrigonometricFunction2;
  real_T rtb_Fcn1;
  real_T rtb_Add5;
  real_T rtb_MultiportSwitch1;
  real_T rtb_Product3_l;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Product3_k;
  boolean_T rtb_LogicalOperator_e;
  boolean_T rtb_RelationalOperator1;
  real_T rtb_Fcn2;
  real_T rtb_Add_f;
  real_T rtb_Add1_h;
  boolean_T rtb_LogicalOperator_c;
  real_T rtb_Saturation;
  real_T rtb_SP_VqLim_V;
  real_T DiscreteTimeIntegrator;

  /* Fcn: '<S7>/Eje_cuadatura2' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/OffsetResolver'
   *  Gain: '<Root>/deg2rad1'
   *  Gain: '<Root>/deg2rad2'
   *  Inport: '<Root>/PV_PosMech_Deg'
   *  Math: '<Root>/Math Function'
   *  Sum: '<Root>/Sum6'
   */
  rtb_Switch = rt_remd_snf(rt_remd_snf(GMV_Code_P->p *
    GMV_Code_U->PV_PosMech_Deg, GMV_Code_P->Constant11_Value) *
    GMV_Code_P->deg2rad2_Gain - GMV_Code_P->OffsetResolver_Value,
    GMV_Code_P->Constant12_Value);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Fcn: '<S7>/Eje_cuadatura2'
   *  Sum: '<S7>/Sum'
   */
  if (!(rtb_Switch >= GMV_Code_P->Switch_Threshold_a)) {
    rtb_Switch += GMV_Code_P->Constant12_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Sum: '<S8>/Add' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Add = rtb_Switch - GMV_Code_DW->Delay_DSTATE[0];

  /* Switch: '<S8>/Switch' incorporates:
   *  Abs: '<S8>/Abs'
   *  Constant: '<S8>/Constant1'
   *  Product: '<S8>/Product'
   *  Sum: '<S8>/Add1'
   */
  if (fabs(rtb_Add) >= GMV_Code_P->Switch_Threshold_n) {
    /* Gain: '<S8>/Gain' */
    rtb_Add *= GMV_Code_P->Gain_Gain;

    /* Signum: '<S8>/Sign' */
    if (rtb_Add < 0.0) {
      rtb_Add = -1.0;
    } else if (rtb_Add > 0.0) {
      rtb_Add = 1.0;
    } else {
      if (rtb_Add == 0.0) {
        rtb_Add = 0.0;
      }
    }

    /* End of Signum: '<S8>/Sign' */
    rtb_Add2_a = GMV_Code_P->Constant1_Value_k * rtb_Add + rtb_Switch;
  } else {
    rtb_Add2_a = rtb_Switch;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Sum: '<S8>/Add2' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Add2_a -= GMV_Code_DW->Delay_DSTATE[0];

  /* Product: '<S8>/Divide' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_Add = rtb_Add2_a / GMV_Code_P->Constant_Value_c;

  /* Switch: '<S8>/Switch1' incorporates:
   *  Abs: '<S8>/Abs1'
   *  Abs: '<S8>/Abs2'
   *  Delay: '<S8>/Delay1'
   *  Delay: '<S8>/Delay4'
   *  Sum: '<S8>/Add3'
   */
  if (fabs(rtb_Add) - fabs(GMV_Code_DW->Delay1_DSTATE) >=
      GMV_Code_P->Switch1_Threshold) {
    rtb_Switch1 = GMV_Code_DW->Delay4_DSTATE[0];
  } else {
    rtb_Switch1 = rtb_Add;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Delay: '<S34>/Integer Delay' */
  rtb_IntegerDelay = GMV_Code_DW->IntegerDelay_DSTATE;

  /* Delay: '<S34>/Integer Delay2' */
  rtb_IntegerDelay2 = GMV_Code_DW->IntegerDelay2_DSTATE;

  /* Sum: '<S34>/Sum' incorporates:
   *  Delay: '<S34>/Integer Delay'
   *  Delay: '<S34>/Integer Delay1'
   *  Delay: '<S34>/Integer Delay2'
   *  Delay: '<S34>/Integer Delay3'
   *  Gain: '<S34>/Gain'
   *  Gain: '<S34>/Gain1'
   *  Gain: '<S34>/Gain2'
   *  Gain: '<S34>/Gain3'
   *  Gain: '<S34>/Gain4'
   */
  rtb_Sum = (((GMV_Code_P->a0 * rtb_Switch1 + GMV_Code_P->a1 *
               GMV_Code_DW->IntegerDelay_DSTATE) + GMV_Code_P->a2 *
              GMV_Code_DW->IntegerDelay1_DSTATE) - GMV_Code_P->b1 *
             GMV_Code_DW->IntegerDelay2_DSTATE) - GMV_Code_P->b2 *
    GMV_Code_DW->IntegerDelay3_DSTATE;

  /* Gain: '<S8>/Gain1' */
  rtb_Gain1_o = 1.0 / GMV_Code_P->p * rtb_Sum;

  /* Sum: '<S29>/sum1' incorporates:
   *  Gain: '<S29>/C'
   *  Gain: '<S29>/D'
   *  Inport: '<Root>/PV_VBus_A'
   *  UnitDelay: '<S29>/Delay_x'
   */
  rtb_yk = GMV_Code_P->D_Gain * GMV_Code_U->PV_VBus_A + GMV_Code_P->C_Gain *
    GMV_Code_DW->Delay_x_DSTATE;

  /* Sum: '<S30>/sum1' incorporates:
   *  Gain: '<S30>/C'
   *  Gain: '<S30>/D'
   *  Inport: '<Root>/PV_Iu_A'
   *  UnitDelay: '<S30>/Delay_x'
   */
  rtb_Add2_a = GMV_Code_P->D_Gain_k * GMV_Code_U->PV_Iu_A + GMV_Code_P->C_Gain_d
    * GMV_Code_DW->Delay_x_DSTATE_p;

  /* Sum: '<S31>/sum1' incorporates:
   *  Gain: '<S31>/C'
   *  Gain: '<S31>/D'
   *  Inport: '<Root>/PV_Iv_A'
   *  UnitDelay: '<S31>/Delay_x'
   */
  rtb_TrigonometricFunction2 = GMV_Code_P->D_Gain_l * GMV_Code_U->PV_Iv_A +
    GMV_Code_P->C_Gain_g * GMV_Code_DW->Delay_x_DSTATE_pq;

  /* Sum: '<S32>/sum1' incorporates:
   *  Gain: '<S32>/C'
   *  Gain: '<S32>/D'
   *  Inport: '<Root>/PV_Iw_A'
   *  UnitDelay: '<S32>/Delay_x'
   */
  rtb_Fcn1 = GMV_Code_P->D_Gain_m * GMV_Code_U->PV_Iw_A + GMV_Code_P->C_Gain_k *
    GMV_Code_DW->Delay_x_DSTATE_c;

  /* Outport: '<Root>/ControlSignals' incorporates:
   *  Gain: '<S33>/C'
   *  Gain: '<S33>/D'
   *  Inport: '<Root>/PV_IBus_A'
   *  Sum: '<S33>/sum1'
   *  UnitDelay: '<S33>/Delay_x'
   */
  GMV_Code_Y->ControlSignals[0] = rtb_Gain1_o;
  GMV_Code_Y->ControlSignals[1] = rtb_yk;
  GMV_Code_Y->ControlSignals[2] = rtb_Add2_a;
  GMV_Code_Y->ControlSignals[3] = rtb_TrigonometricFunction2;
  GMV_Code_Y->ControlSignals[4] = rtb_Fcn1;
  GMV_Code_Y->ControlSignals[5] = GMV_Code_P->D_Gain_h * GMV_Code_U->PV_IBus_A +
    GMV_Code_P->C_Gain_dv * GMV_Code_DW->Delay_x_DSTATE_j;

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Inport: '<Root>/enable_control'
   */
  rtb_Add_f = GMV_Code_U->enable_control + GMV_Code_P->Constant1_Value_f;

  /* Product: '<S16>/Product' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  rtb_Add6 = rtb_yk * GMV_Code_P->CTE_1divSQRT3;

  /* Sum: '<S21>/Add' incorporates:
   *  Gain: '<S21>/Gain'
   *  Gain: '<S21>/Gain2'
   *  Gain: '<S21>/Gain4'
   */
  rtb_Add5 = (GMV_Code_P->CTE_Clarke_11 * rtb_Add2_a + GMV_Code_P->CTE_Clarke_12
              * rtb_TrigonometricFunction2) + GMV_Code_P->CTE_Clarke_13 *
    rtb_Fcn1;

  /* Trigonometry: '<S11>/Trigonometric Function1' */
  rtb_Fcn2 = cos(rtb_Switch);

  /* Sum: '<S21>/Add1' incorporates:
   *  Gain: '<S21>/Gain1'
   *  Gain: '<S21>/Gain3'
   *  Gain: '<S21>/Gain5'
   */
  rtb_Fcn1 = (GMV_Code_P->CTE_Clarke_21 * rtb_Add2_a + GMV_Code_P->CTE_Clarke_22
              * rtb_TrigonometricFunction2) + GMV_Code_P->CTE_Clarke_23 *
    rtb_Fcn1;

  /* Trigonometry: '<S11>/Trigonometric Function2' */
  rtb_TrigonometricFunction2 = sin(rtb_Switch);

  /* Sum: '<S17>/Add2' incorporates:
   *  Product: '<S17>/Product3'
   *  Product: '<S17>/Product4'
   */
  rtb_Add2_a = rtb_Add5 * rtb_Fcn2 + rtb_Fcn1 * rtb_TrigonometricFunction2;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S9>/Id_ref'
   *  Inport: '<Root>/enable_control'
   *  Sum: '<S23>/Add'
   */
  rtb_MultiportSwitch1 = (GMV_Code_P->Id_ref_Value - rtb_Add2_a) *
    GMV_Code_U->enable_control;

  /* Product: '<S25>/Product3' incorporates:
   *  Constant: '<S11>/Kp'
   */
  rtb_Product3_l = rtb_MultiportSwitch1 * GMV_Code_P->PARAM_r32_kpIdReg_V_A;

  /* Logic: '<S25>/Logical Operator' incorporates:
   *  Inport: '<Root>/enable_control'
   */
  rtb_LogicalOperator = !(GMV_Code_U->enable_control != 0.0);

  /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Ki'
   *  Product: '<S25>/Product1'
   *  Sum: '<S25>/Add'
   *  UnitDelay: '<S25>/Unit Delay1'
   */
  if (GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_E != 0) {
    DiscreteTimeIntegrator = GMV_Code_DW->DiscreteTimeIntegrator_DSTATE;
  } else if (rtb_LogicalOperator ||
             (GMV_Code_DW->DiscreteTimeIntegrator_PrevRese != 0)) {
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE =
      GMV_Code_P->DiscreteTimeIntegrator_IC;
    DiscreteTimeIntegrator = GMV_Code_DW->DiscreteTimeIntegrator_DSTATE;
  } else {
    DiscreteTimeIntegrator = (rtb_MultiportSwitch1 +
      GMV_Code_DW->UnitDelay1_DSTATE) * GMV_Code_P->PARAM_r32_1divTiIdReg_s *
      GMV_Code_P->DiscreteTimeIntegrator_gainval +
      GMV_Code_DW->DiscreteTimeIntegrator_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

  /* Sum: '<S17>/Add3' incorporates:
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product2'
   */
  rtb_MultiportSwitch1 = rtb_Fcn1 * rtb_Fcn2 - rtb_Add5 *
    rtb_TrigonometricFunction2;

  /* Sum: '<S25>/Add2' incorporates:
   *  Constant: '<S24>/Constant1'
   *  Gain: '<S19>/Gain'
   *  Inport: '<Root>/enable_control'
   *  Product: '<S23>/Product1'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Sum: '<S25>/Add1'
   */
  rtb_TrigonometricFunction2 = (rtb_Product3_l + DiscreteTimeIntegrator) -
    GMV_Code_P->p * rtb_Gain1_o * GMV_Code_P->CTE_r32_Lq_nom_H *
    rtb_MultiportSwitch1 * GMV_Code_U->enable_control;

  /* RateTransition: '<S9>/Rate Transition3' */
  if (GMV_Code_M->Timing.TaskCounters.TID[1] == 0) {
    GMV_Code_B->RateTransition3 = GMV_Code_DW->RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S9>/Rate Transition3' */

  /* Product: '<S26>/Product' incorporates:
   *  Inport: '<Root>/enable_control'
   *  Sum: '<S26>/Add'
   */
  rtb_MultiportSwitch1 = (GMV_Code_B->RateTransition3 - rtb_MultiportSwitch1) *
    GMV_Code_U->enable_control;

  /* Product: '<S28>/Product3' incorporates:
   *  Constant: '<S11>/Kp'
   */
  rtb_Product3_k = rtb_MultiportSwitch1 * GMV_Code_P->PARAM_r32_kpIdReg_V_A;

  /* Logic: '<S28>/Logical Operator' incorporates:
   *  Inport: '<Root>/enable_control'
   */
  rtb_LogicalOperator_e = !(GMV_Code_U->enable_control != 0.0);

  /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Ki'
   *  Product: '<S28>/Product1'
   *  Sum: '<S28>/Add'
   *  UnitDelay: '<S28>/Unit Delay'
   */
  if (GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_d != 0) {
    rtb_Product3_l = GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e;
  } else if (rtb_LogicalOperator_e ||
             (GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_i != 0)) {
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e =
      GMV_Code_P->DiscreteTimeIntegrator_IC_j;
    rtb_Product3_l = GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e;
  } else {
    rtb_Product3_l = (rtb_MultiportSwitch1 + GMV_Code_DW->UnitDelay_DSTATE) *
      GMV_Code_P->PARAM_r32_1divTiIdReg_s *
      GMV_Code_P->DiscreteTimeIntegrator_gainva_k +
      GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e;
  }

  /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

  /* Gain: '<S20>/Gain' */
  rtb_MultiportSwitch1 = GMV_Code_P->p * rtb_Gain1_o;

  /* Sum: '<S28>/Add2' incorporates:
   *  Constant: '<S27>/Constant2'
   *  Constant: '<S27>/Constant3'
   *  Inport: '<Root>/enable_control'
   *  Product: '<S26>/Product1'
   *  Product: '<S27>/Product'
   *  Product: '<S27>/Product1'
   *  Product: '<S27>/Product2'
   *  Sum: '<S27>/Add'
   *  Sum: '<S28>/Add1'
   */
  rtb_Add2_a = (GMV_Code_P->CTE_r32_Ld_nom_H * rtb_Add2_a * rtb_MultiportSwitch1
                + rtb_MultiportSwitch1 * GMV_Code_P->Fluxm) *
    GMV_Code_U->enable_control + (rtb_Product3_k + rtb_Product3_l);

  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  rtb_MultiportSwitch1 = rtb_TrigonometricFunction2 * rtb_TrigonometricFunction2
    + rtb_Add2_a * rtb_Add2_a;

  /* Math: '<S11>/Sqrt'
   *
   * About '<S11>/Sqrt':
   *  Operator: sqrt
   */
  if (rtb_MultiportSwitch1 < 0.0) {
    rtb_MultiportSwitch1 = -sqrt(fabs(rtb_MultiportSwitch1));
  } else {
    rtb_MultiportSwitch1 = sqrt(rtb_MultiportSwitch1);
  }

  /* End of Math: '<S11>/Sqrt' */

  /* Product: '<S16>/Divide' */
  rtb_Add5 = rtb_Add6 / rtb_MultiportSwitch1;

  /* RelationalOperator: '<S16>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_MultiportSwitch1 >= rtb_Add6);

  /* Switch: '<S16>/Switch' incorporates:
   *  Product: '<S16>/Product1'
   */
  if (rtb_RelationalOperator1) {
    rtb_Product3_k = rtb_Add5 * rtb_TrigonometricFunction2;
  } else {
    rtb_Product3_k = rtb_TrigonometricFunction2;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S14>/Switch' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/enable_comp'
   *  Sum: '<S14>/Sum'
   */
  if (GMV_Code_U->enable_comp > GMV_Code_P->Switch_Threshold_ax) {
    rtb_MultiportSwitch1 = GMV_Code_P->p * GMV_Code_P->Tc * 1.5 * rtb_Gain1_o +
      rtb_Switch;
  } else {
    rtb_MultiportSwitch1 = rtb_Switch;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Trigonometry: '<S14>/Trigonometric Function3' */
  rtb_Add6 = cos(rtb_MultiportSwitch1);

  /* Switch: '<S16>/Switch1' incorporates:
   *  Product: '<S16>/Product2'
   */
  if (rtb_RelationalOperator1) {
    rtb_SP_VqLim_V = rtb_Add5 * rtb_Add2_a;
  } else {
    rtb_SP_VqLim_V = rtb_Add2_a;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Trigonometry: '<S14>/Trigonometric Function4' */
  rtb_Add5 = sin(rtb_MultiportSwitch1);

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S18>/alfa'
   *  Gain: '<S18>/Gain6'
   *  Inport: '<Root>/enable_autoph'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Sum: '<S18>/Add1'
   */
  if (GMV_Code_U->enable_autoph > GMV_Code_P->Switch3_Threshold) {
    rtb_MultiportSwitch1 = GMV_Code_P->Gain6_Gain * GMV_Code_P->alfa_Value;
  } else {
    rtb_MultiportSwitch1 = rtb_Product3_k * rtb_Add6 - rtb_SP_VqLim_V * rtb_Add5;
  }

  /* End of Switch: '<S18>/Switch3' */

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/Beta'
   *  Inport: '<Root>/enable_autoph'
   *  Product: '<S18>/Product2'
   *  Product: '<S18>/Product3'
   *  Sum: '<S18>/Add'
   */
  if (GMV_Code_U->enable_autoph > GMV_Code_P->Switch1_Threshold_g) {
    rtb_Fcn2 = GMV_Code_P->Beta_Value;
  } else {
    rtb_Fcn2 = rtb_Product3_k * rtb_Add5 + rtb_SP_VqLim_V * rtb_Add6;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* Sum: '<S18>/Add2' incorporates:
   *  Gain: '<S18>/Gain'
   *  Gain: '<S18>/Gain3'
   */
  rtb_Add5 = GMV_Code_P->CTE_Clarke_inv_11 * rtb_MultiportSwitch1 +
    GMV_Code_P->CTE_Clarke_inv_12 * rtb_Fcn2;

  /* Sum: '<S18>/Add3' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Gain: '<S18>/Gain4'
   */
  rtb_Add6 = GMV_Code_P->CTE_Clarke_inv_21 * rtb_MultiportSwitch1 +
    GMV_Code_P->CTE_Clarke_inv_22 * rtb_Fcn2;

  /* Sum: '<S18>/Add4' incorporates:
   *  Gain: '<S18>/Gain2'
   *  Gain: '<S18>/Gain5'
   */
  rtb_MultiportSwitch1 = GMV_Code_P->CTE_Clarke_inv_31 * rtb_MultiportSwitch1 +
    GMV_Code_P->CTE_Clarke_inv_32 * rtb_Fcn2;

  /* Fcn: '<S22>/Fcn2' incorporates:
   *  Fcn: '<S22>/Fcn'
   *  Fcn: '<S22>/Fcn1'
   */
  rtb_Fcn2 = rt_atan2d_snf((rtb_Add6 - rtb_MultiportSwitch1) /
    1.7320508075688772, ((2.0 * rtb_Add5 - rtb_Add6) - rtb_MultiportSwitch1) /
    3.0);

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  Sum: '<S22>/Sum'
   */
  if (!(rtb_Fcn2 > GMV_Code_P->Switch_Threshold_c)) {
    rtb_Fcn2 += GMV_Code_P->Constant_Value;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Fcn: '<S22>/Fcn3' */
  rtb_Fcn1 = (rt_powd_snf(rtb_Add5, 2.0) + rt_powd_snf(rtb_Add6, 2.0)) +
    rt_powd_snf(rtb_MultiportSwitch1, 2.0);
  if (rtb_Fcn1 < 0.0) {
    rtb_Fcn1 = -sqrt(-rtb_Fcn1);
  } else {
    rtb_Fcn1 = sqrt(rtb_Fcn1);
  }

  /* End of Fcn: '<S22>/Fcn3' */

  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Gain: '<S22>/Gain1'
   *  Product: '<S22>/Product'
   *  Trigonometry: '<S22>/Trigonometric Function'
   */
  rtb_Fcn2 = cos(GMV_Code_P->Gain1_Gain * rtb_Fcn2) *
    GMV_Code_P->Constant1_Value_n * rtb_Fcn1;

  /* Sum: '<S18>/Add5' */
  rtb_Add5 -= rtb_Fcn2;

  /* Sum: '<S18>/Add6' */
  rtb_Add6 -= rtb_Fcn2;

  /* Sum: '<S18>/Add7' */
  rtb_MultiportSwitch1 -= rtb_Fcn2;

  /* MultiPortSwitch: '<Root>/Multiport Switch3' */
  if ((int32_T)rtb_Add_f == 1) {
    /* Outport: '<Root>/DutyA' incorporates:
     *  Constant: '<Root>/Constant'
     */
    GMV_Code_Y->DutyA = GMV_Code_P->Constant_Value_j;

    /* Outport: '<Root>/DutyB' incorporates:
     *  Constant: '<Root>/Constant'
     *  MultiPortSwitch: '<Root>/Multiport Switch4'
     */
    GMV_Code_Y->DutyB = GMV_Code_P->Constant_Value_j;

    /* Outport: '<Root>/DutyC' incorporates:
     *  Constant: '<Root>/Constant'
     *  MultiPortSwitch: '<Root>/Multiport Switch5'
     */
    GMV_Code_Y->DutyC = GMV_Code_P->Constant_Value_j;
  } else {
    /* Outport: '<Root>/DutyA' incorporates:
     *  Constant: '<S15>/Constant'
     *  Gain: '<S15>/Gain'
     *  Product: '<S15>/Product3'
     *  Sum: '<S15>/Sum'
     */
    GMV_Code_Y->DutyA = rtb_Add5 / rtb_yk * GMV_Code_P->Gain_Gain_d +
      GMV_Code_P->Constant_Value_g;

    /* Outport: '<Root>/DutyB' incorporates:
     *  Constant: '<S15>/Constant'
     *  Gain: '<S15>/Gain'
     *  MultiPortSwitch: '<Root>/Multiport Switch4'
     *  Product: '<S15>/Product3'
     *  Sum: '<S15>/Sum'
     */
    GMV_Code_Y->DutyB = rtb_Add6 / rtb_yk * GMV_Code_P->Gain_Gain_d +
      GMV_Code_P->Constant_Value_g;

    /* Outport: '<Root>/DutyC' incorporates:
     *  Constant: '<S15>/Constant'
     *  Gain: '<S15>/Gain'
     *  MultiPortSwitch: '<Root>/Multiport Switch5'
     *  Product: '<S15>/Product3'
     *  Sum: '<S15>/Sum'
     */
    GMV_Code_Y->DutyC = rtb_MultiportSwitch1 / rtb_yk * GMV_Code_P->Gain_Gain_d
      + GMV_Code_P->Constant_Value_g;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch3' */

  /* Relay: '<S12>/Relay' */
  if (rtb_yk >= GMV_Code_P->PARAM_VDC_ON_CB_V) {
    GMV_Code_DW->Relay_Mode = true;
  } else {
    if (rtb_yk <= GMV_Code_P->PARAM_VDC_OFF_CB_V) {
      GMV_Code_DW->Relay_Mode = false;
    }
  }

  /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
   *  Relay: '<S12>/Relay'
   */
  if ((int32_T)rtb_Add_f == 1) {
    /* Outport: '<Root>/Crowbar_Out' incorporates:
     *  Constant: '<Root>/Constant'
     */
    GMV_Code_Y->Crowbar_Out = GMV_Code_P->Constant_Value_j;
  } else {
    if (GMV_Code_DW->Relay_Mode) {
      /* Relay: '<S12>/Relay' */
      rtb_yk = GMV_Code_P->Relay_YOn;
    } else {
      /* Relay: '<S12>/Relay' */
      rtb_yk = GMV_Code_P->Relay_YOff;
    }

    /* Switch: '<S12>/Switch' */
    if (rtb_yk > GMV_Code_P->Switch_Threshold) {
      /* Outport: '<Root>/Crowbar_Out' incorporates:
       *  Constant: '<S12>/Constant1'
       */
      GMV_Code_Y->Crowbar_Out = GMV_Code_P->Constant1_Value;
    } else {
      /* Outport: '<Root>/Crowbar_Out' incorporates:
       *  Constant: '<S12>/Constant2'
       */
      GMV_Code_Y->Crowbar_Out = GMV_Code_P->PARAM_DUTY_ON_CB_per;
    }

    /* End of Switch: '<S12>/Switch' */
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

  /* Outport: '<Root>/Autoph_offset' */
  GMV_Code_Y->Autoph_offset = rtb_Switch;

  /* Outport: '<Root>/Autoph_ready' */
  GMV_Code_Y->Autoph_ready = 0.0;

  /* Outport: '<Root>/EnableBus' incorporates:
   *  Inport: '<Root>/EnableDCBus'
   *  Inport: '<Root>/enable_control'
   *  Product: '<Root>/Product'
   */
  GMV_Code_Y->EnableBus = GMV_Code_U->EnableDCBus * GMV_Code_U->enable_control;

  /* RateTransition: '<S9>/Rate Transition' incorporates:
   *  Inport: '<Root>/SP_Speed'
   */
  if (GMV_Code_M->Timing.TaskCounters.TID[1] == 0) {
    GMV_Code_B->RateTransition = GMV_Code_U->SP_Speed;

    /* RateTransition: '<S9>/Rate Transition1' incorporates:
     *  Inport: '<Root>/SP_Speed'
     */
    GMV_Code_B->RateTransition1 = rtb_Gain1_o;

    /* RateTransition: '<S9>/Rate Transition2' incorporates:
     *  Inport: '<Root>/enable_control'
     */
    GMV_Code_B->RateTransition2 = GMV_Code_U->enable_control;

    /* Product: '<S10>/Product' incorporates:
     *  Sum: '<S10>/Add'
     */
    rtb_Add1_h = (GMV_Code_B->RateTransition - GMV_Code_B->RateTransition1) *
      GMV_Code_B->RateTransition2;

    /* Logic: '<S13>/Logical Operator' */
    rtb_LogicalOperator_c = !(GMV_Code_B->RateTransition2 != 0.0);

    /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S13>/Kd'
     *  Product: '<S13>/Product1'
     *  Sum: '<S13>/Add'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    if (GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_h != 0) {
      GMV_Code_B->DiscreteTimeIntegrator_j =
        GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p;
    } else if (rtb_LogicalOperator_c ||
               (GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_b != 0)) {
      GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p =
        GMV_Code_P->DiscreteTimeIntegrator_IC_l;
      GMV_Code_B->DiscreteTimeIntegrator_j =
        GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p;
    } else {
      GMV_Code_B->DiscreteTimeIntegrator_j = (rtb_Add1_h +
        GMV_Code_DW->UnitDelay_DSTATE_a) * GMV_Code_P->Kd *
        GMV_Code_P->DiscreteTimeIntegrator_gainva_f +
        GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p;
    }

    /* End of DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

    /* Sum: '<S13>/Add1' incorporates:
     *  Constant: '<S13>/Kc'
     *  Product: '<S13>/Product3'
     */
    rtb_Add1_h = rtb_Add1_h * GMV_Code_P->Kc +
      GMV_Code_B->DiscreteTimeIntegrator_j;

    /* Saturate: '<S13>/Saturation' */
    if (rtb_Add1_h > GMV_Code_P->Iq_Limit_Max_A) {
      rtb_Saturation = GMV_Code_P->Iq_Limit_Max_A;
    } else if (rtb_Add1_h < GMV_Code_P->Iq_Limit_Min_A) {
      rtb_Saturation = GMV_Code_P->Iq_Limit_Min_A;
    } else {
      rtb_Saturation = rtb_Add1_h;
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Product: '<S13>/Product2' incorporates:
     *  Constant: '<S13>/K_antiwindup_velocidad'
     *  Sum: '<S13>/Add3'
     */
    rtb_Add1_h = (rtb_Saturation - rtb_Add1_h) *
      GMV_Code_P->K_antiwindup_velocidad;
  }

  /* End of RateTransition: '<S9>/Rate Transition' */

  /* Update for Delay: '<S8>/Delay4' */
  GMV_Code_DW->Delay4_DSTATE[0] = GMV_Code_DW->Delay4_DSTATE[1];
  GMV_Code_DW->Delay4_DSTATE[1] = rtb_Add;

  /* Update for Delay: '<S8>/Delay' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++) {
    GMV_Code_DW->Delay_DSTATE[idxDelay] = GMV_Code_DW->Delay_DSTATE[idxDelay + 1];
  }

  GMV_Code_DW->Delay_DSTATE[9] = rtb_Switch;

  /* End of Update for Delay: '<S8>/Delay' */

  /* Update for Delay: '<S8>/Delay1' */
  GMV_Code_DW->Delay1_DSTATE = rtb_Add;

  /* Update for Delay: '<S34>/Integer Delay' */
  GMV_Code_DW->IntegerDelay_DSTATE = rtb_Switch1;

  /* Update for Delay: '<S34>/Integer Delay1' */
  GMV_Code_DW->IntegerDelay1_DSTATE = rtb_IntegerDelay;

  /* Update for Delay: '<S34>/Integer Delay2' */
  GMV_Code_DW->IntegerDelay2_DSTATE = rtb_Sum;

  /* Update for Delay: '<S34>/Integer Delay3' */
  GMV_Code_DW->IntegerDelay3_DSTATE = rtb_IntegerDelay2;

  /* Update for UnitDelay: '<S29>/Delay_x' incorporates:
   *  Gain: '<S29>/A'
   *  Gain: '<S29>/B'
   *  Inport: '<Root>/PV_VBus_A'
   *  Sum: '<S29>/A*x(k) + B*u(k)'
   *  UnitDelay: '<S29>/Delay_x'
   */
  GMV_Code_DW->Delay_x_DSTATE = GMV_Code_P->A_Gain * GMV_Code_DW->Delay_x_DSTATE
    + GMV_Code_P->B_Gain * GMV_Code_U->PV_VBus_A;

  /* Update for UnitDelay: '<S30>/Delay_x' incorporates:
   *  Gain: '<S30>/A'
   *  Gain: '<S30>/B'
   *  Inport: '<Root>/PV_Iu_A'
   *  Sum: '<S30>/A*x(k) + B*u(k)'
   *  UnitDelay: '<S30>/Delay_x'
   */
  GMV_Code_DW->Delay_x_DSTATE_p = GMV_Code_P->A_Gain_j *
    GMV_Code_DW->Delay_x_DSTATE_p + GMV_Code_P->B_Gain_i * GMV_Code_U->PV_Iu_A;

  /* Update for UnitDelay: '<S31>/Delay_x' incorporates:
   *  Gain: '<S31>/A'
   *  Gain: '<S31>/B'
   *  Inport: '<Root>/PV_Iv_A'
   *  Sum: '<S31>/A*x(k) + B*u(k)'
   *  UnitDelay: '<S31>/Delay_x'
   */
  GMV_Code_DW->Delay_x_DSTATE_pq = GMV_Code_P->A_Gain_d *
    GMV_Code_DW->Delay_x_DSTATE_pq + GMV_Code_P->B_Gain_n * GMV_Code_U->PV_Iv_A;

  /* Update for UnitDelay: '<S32>/Delay_x' incorporates:
   *  Gain: '<S32>/A'
   *  Gain: '<S32>/B'
   *  Inport: '<Root>/PV_Iw_A'
   *  Sum: '<S32>/A*x(k) + B*u(k)'
   *  UnitDelay: '<S32>/Delay_x'
   */
  GMV_Code_DW->Delay_x_DSTATE_c = GMV_Code_P->A_Gain_p *
    GMV_Code_DW->Delay_x_DSTATE_c + GMV_Code_P->B_Gain_a * GMV_Code_U->PV_Iw_A;

  /* Update for UnitDelay: '<S33>/Delay_x' incorporates:
   *  Gain: '<S33>/A'
   *  Gain: '<S33>/B'
   *  Inport: '<Root>/PV_IBus_A'
   *  Sum: '<S33>/A*x(k) + B*u(k)'
   *  UnitDelay: '<S33>/Delay_x'
   */
  GMV_Code_DW->Delay_x_DSTATE_j = GMV_Code_P->A_Gain_l *
    GMV_Code_DW->Delay_x_DSTATE_j + GMV_Code_P->B_Gain_o * GMV_Code_U->PV_IBus_A;

  /* Update for UnitDelay: '<S25>/Unit Delay1' incorporates:
   *  Constant: '<S11>/K_antiwindup_corriente'
   *  Product: '<S25>/Product2'
   *  Sum: '<S25>/Add3'
   */
  GMV_Code_DW->UnitDelay1_DSTATE = (rtb_Product3_k - rtb_TrigonometricFunction2)
    * GMV_Code_P->K_antiwindup_corriente;

  /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_E = 0U;
  GMV_Code_DW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator;
  GMV_Code_DW->DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_LogicalOperator;

  /* Update for RateTransition: '<S9>/Rate Transition3' */
  if (GMV_Code_M->Timing.TaskCounters.TID[1] == 0) {
    GMV_Code_DW->RateTransition3_Buffer0 = rtb_Saturation;

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    GMV_Code_DW->UnitDelay_DSTATE_a = rtb_Add1_h;

    /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_h = 0U;
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p =
      GMV_Code_B->DiscreteTimeIntegrator_j;
    GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_b = (int8_T)rtb_LogicalOperator_c;
  }

  /* End of Update for RateTransition: '<S9>/Rate Transition3' */

  /* Update for UnitDelay: '<S28>/Unit Delay' incorporates:
   *  Constant: '<S11>/K_antiwindup_corriente'
   *  Product: '<S28>/Product2'
   *  Sum: '<S28>/Add3'
   */
  GMV_Code_DW->UnitDelay_DSTATE = (rtb_SP_VqLim_V - rtb_Add2_a) *
    GMV_Code_P->K_antiwindup_corriente;

  /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_d = 0U;
  GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e = rtb_Product3_l;
  GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_i = (int8_T)rtb_LogicalOperator_e;

  /* Matfile logging */
  rt_UpdateTXYLogVars(GMV_Code_M->rtwLogInfo, (&GMV_Code_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0001s, 0.0s] */
    if ((rtmGetTFinal(GMV_Code_M)!=-1) &&
        !((rtmGetTFinal(GMV_Code_M)-GMV_Code_M->Timing.taskTime0) >
          GMV_Code_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(GMV_Code_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++GMV_Code_M->Timing.clockTick0)) {
    ++GMV_Code_M->Timing.clockTickH0;
  }

  GMV_Code_M->Timing.taskTime0 = GMV_Code_M->Timing.clockTick0 *
    GMV_Code_M->Timing.stepSize0 + GMV_Code_M->Timing.clockTickH0 *
    GMV_Code_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler(GMV_Code_M);
}

/* Model initialize function */
void GMV_Code_initialize(RT_MODEL_GMV_Code_T *const GMV_Code_M)
{
  P_GMV_Code_T *GMV_Code_P = ((P_GMV_Code_T *) GMV_Code_M->defaultParam);
  B_GMV_Code_T *GMV_Code_B = ((B_GMV_Code_T *) GMV_Code_M->blockIO);
  DW_GMV_Code_T *GMV_Code_DW = ((DW_GMV_Code_T *) GMV_Code_M->dwork);

  /* Start for RateTransition: '<S9>/Rate Transition3' */
  GMV_Code_B->RateTransition3 = GMV_Code_P->RateTransition3_X0;

  {
    int32_T i;

    /* InitializeConditions for Delay: '<S8>/Delay4' */
    GMV_Code_DW->Delay4_DSTATE[0] = GMV_Code_P->Delay4_InitialCondition;
    GMV_Code_DW->Delay4_DSTATE[1] = GMV_Code_P->Delay4_InitialCondition;

    /* InitializeConditions for Delay: '<S8>/Delay' */
    for (i = 0; i < 10; i++) {
      GMV_Code_DW->Delay_DSTATE[i] = GMV_Code_P->Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S8>/Delay' */

    /* InitializeConditions for Delay: '<S8>/Delay1' */
    GMV_Code_DW->Delay1_DSTATE = GMV_Code_P->Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S34>/Integer Delay' */
    GMV_Code_DW->IntegerDelay_DSTATE = GMV_Code_P->IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S34>/Integer Delay1' */
    GMV_Code_DW->IntegerDelay1_DSTATE =
      GMV_Code_P->IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S34>/Integer Delay2' */
    GMV_Code_DW->IntegerDelay2_DSTATE =
      GMV_Code_P->IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S34>/Integer Delay3' */
    GMV_Code_DW->IntegerDelay3_DSTATE =
      GMV_Code_P->IntegerDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S29>/Delay_x' */
    GMV_Code_DW->Delay_x_DSTATE = GMV_Code_P->Delay_x_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S30>/Delay_x' */
    GMV_Code_DW->Delay_x_DSTATE_p = GMV_Code_P->Delay_x_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S31>/Delay_x' */
    GMV_Code_DW->Delay_x_DSTATE_pq = GMV_Code_P->Delay_x_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S32>/Delay_x' */
    GMV_Code_DW->Delay_x_DSTATE_c = GMV_Code_P->Delay_x_InitialCondition_d;

    /* InitializeConditions for UnitDelay: '<S33>/Delay_x' */
    GMV_Code_DW->Delay_x_DSTATE_j = GMV_Code_P->Delay_x_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay1' */
    GMV_Code_DW->UnitDelay1_DSTATE = GMV_Code_P->UnitDelay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE =
      GMV_Code_P->DiscreteTimeIntegrator_IC;
    GMV_Code_DW->DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for RateTransition: '<S9>/Rate Transition3' */
    GMV_Code_DW->RateTransition3_Buffer0 = GMV_Code_P->RateTransition3_X0;

    /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
    GMV_Code_DW->UnitDelay_DSTATE = GMV_Code_P->UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_e =
      GMV_Code_P->DiscreteTimeIntegrator_IC_j;
    GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_i = 0;

    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    GMV_Code_DW->UnitDelay_DSTATE_a = GMV_Code_P->UnitDelay_InitialCondition_a;

    /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
    GMV_Code_DW->DiscreteTimeIntegrator_DSTATE_p =
      GMV_Code_P->DiscreteTimeIntegrator_IC_l;
    GMV_Code_DW->DiscreteTimeIntegrator_PrevRe_b = 0;
  }

  /* Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
  GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_d = 1U;

  /* Enable for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  GMV_Code_DW->DiscreteTimeIntegrator_SYSTEM_h = 1U;
}

/* Model terminate function */
void GMV_Code_terminate(RT_MODEL_GMV_Code_T * GMV_Code_M)
{
  /* model code */
  rt_FREE(GMV_Code_M->blockIO);
  rt_FREE(GMV_Code_M->inputs);
  rt_FREE(GMV_Code_M->outputs);
  if (GMV_Code_M->paramIsMalloced) {
    rt_FREE(GMV_Code_M->defaultParam);
  }

  rt_FREE(GMV_Code_M->dwork);

  {
    void *xptr = (void *) rtliGetLogXSignalPtrs(GMV_Code_M->rtwLogInfo);
    void *yptr = (void *) rtliGetLogYSignalPtrs(GMV_Code_M->rtwLogInfo);
    rt_FREE(xptr);
    rt_FREE(yptr);
  }

  rt_FREE(GMV_Code_M->rtwLogInfo);
  rt_FREE(GMV_Code_M);
}

/* Model data allocation function */
RT_MODEL_GMV_Code_T *GMV_Code(void)
{
  RT_MODEL_GMV_Code_T *GMV_Code_M;
  GMV_Code_M = (RT_MODEL_GMV_Code_T *) malloc(sizeof(RT_MODEL_GMV_Code_T));
  if (GMV_Code_M == NULL) {
    return NULL;
  }

  (void) memset((char *)GMV_Code_M, 0,
                sizeof(RT_MODEL_GMV_Code_T));

  /* Setup for data logging */
  {
    RTWLogInfo *rt_DataLoggingInfo = (RTWLogInfo *) malloc(sizeof(RTWLogInfo));
    rt_VALIDATE_MEMORY(GMV_Code_M,rt_DataLoggingInfo);
    rt_DataLoggingInfo->loggingInterval = NULL;
    GMV_Code_M->rtwLogInfo = rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(GMV_Code_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(GMV_Code_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalInfo(GMV_Code_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(GMV_Code_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  {
    B_GMV_Code_T *b = (B_GMV_Code_T *) malloc(sizeof(B_GMV_Code_T));
    rt_VALIDATE_MEMORY(GMV_Code_M,b);
    GMV_Code_M->blockIO = (b);
  }

  /* parameters */
  {
    P_GMV_Code_T *p;
    static int_T pSeen = 0;

    /* only malloc on multiple model instantiation */
    if (pSeen == 1 ) {
      p = (P_GMV_Code_T *) malloc(sizeof(P_GMV_Code_T));
      rt_VALIDATE_MEMORY(GMV_Code_M,p);
      (void) memcpy(p, &GMV_Code_P,
                    sizeof(P_GMV_Code_T));
      GMV_Code_M->paramIsMalloced = (true);
    } else {
      p = &GMV_Code_P;
      GMV_Code_M->paramIsMalloced = (false);
      pSeen = 1;
    }

    GMV_Code_M->defaultParam = (p);
  }

  /* states (dwork) */
  {
    DW_GMV_Code_T *dwork = (DW_GMV_Code_T *) malloc(sizeof(DW_GMV_Code_T));
    rt_VALIDATE_MEMORY(GMV_Code_M,dwork);
    GMV_Code_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_GMV_Code_T *GMV_Code_U = (ExtU_GMV_Code_T *) malloc(sizeof
      (ExtU_GMV_Code_T));
    rt_VALIDATE_MEMORY(GMV_Code_M,GMV_Code_U);
    GMV_Code_M->inputs = (((ExtU_GMV_Code_T *) GMV_Code_U));
  }

  /* external outputs */
  {
    ExtY_GMV_Code_T *GMV_Code_Y = (ExtY_GMV_Code_T *) malloc(sizeof
      (ExtY_GMV_Code_T));
    rt_VALIDATE_MEMORY(GMV_Code_M,GMV_Code_Y);
    GMV_Code_M->outputs = (GMV_Code_Y);
  }

  {
    P_GMV_Code_T *GMV_Code_P = ((P_GMV_Code_T *) GMV_Code_M->defaultParam);
    B_GMV_Code_T *GMV_Code_B = ((B_GMV_Code_T *) GMV_Code_M->blockIO);
    DW_GMV_Code_T *GMV_Code_DW = ((DW_GMV_Code_T *) GMV_Code_M->dwork);
    ExtU_GMV_Code_T *GMV_Code_U = (ExtU_GMV_Code_T *) GMV_Code_M->inputs;
    ExtY_GMV_Code_T *GMV_Code_Y = (ExtY_GMV_Code_T *) GMV_Code_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtmSetTFinal(GMV_Code_M, 10.0);
    GMV_Code_M->Timing.stepSize0 = 0.0001;

    /* Setup for data logging */
    {
      rtliSetLogT(GMV_Code_M->rtwLogInfo, "tout");
      rtliSetLogX(GMV_Code_M->rtwLogInfo, "");
      rtliSetLogXFinal(GMV_Code_M->rtwLogInfo, "");
      rtliSetLogVarNameModifier(GMV_Code_M->rtwLogInfo, "rt_");
      rtliSetLogFormat(GMV_Code_M->rtwLogInfo, 4);
      rtliSetLogMaxRows(GMV_Code_M->rtwLogInfo, 0);
      rtliSetLogDecimation(GMV_Code_M->rtwLogInfo, 1);
      rtliSetLogY(GMV_Code_M->rtwLogInfo, "");
    }

    GMV_Code_M->Timing.stepSize = (0.0001);

    /* block I/O */
    (void) memset(((void *) GMV_Code_B), 0,
                  sizeof(B_GMV_Code_T));

    /* states (dwork) */
    (void) memset((void *)GMV_Code_DW, 0,
                  sizeof(DW_GMV_Code_T));

    /* external inputs */
    (void)memset((void *)GMV_Code_U, 0, sizeof(ExtU_GMV_Code_T));

    /* external outputs */
    (void) memset((void *)GMV_Code_Y, 0,
                  sizeof(ExtY_GMV_Code_T));
  }

  return GMV_Code_M;
}
