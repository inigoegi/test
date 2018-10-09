/*
 * GMV_Code.h
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

#ifndef RTW_HEADER_GMV_Code_h_
#define RTW_HEADER_GMV_Code_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef GMV_Code_COMMON_INCLUDES_
# define GMV_Code_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* GMV_Code_COMMON_INCLUDES_ */

#include "GMV_Code_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->paramIsMalloced = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#define GMV_Code_M_TYPE                RT_MODEL_GMV_Code_T

/* Block signals (auto storage) */
typedef struct {
  real_T RateTransition3;              /* '<S9>/Rate Transition3' */
  real_T RateTransition;               /* '<S9>/Rate Transition' */
  real_T RateTransition1;              /* '<S9>/Rate Transition1' */
  real_T RateTransition2;              /* '<S9>/Rate Transition2' */
  real_T DiscreteTimeIntegrator_j;     /* '<S13>/Discrete-Time Integrator' */
} B_GMV_Code_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay4_DSTATE[2];             /* '<S8>/Delay4' */
  real_T Delay_DSTATE[10];             /* '<S8>/Delay' */
  real_T Delay1_DSTATE;                /* '<S8>/Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S34>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S34>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S34>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S34>/Integer Delay3' */
  real_T Delay_x_DSTATE;               /* '<S29>/Delay_x' */
  real_T Delay_x_DSTATE_p;             /* '<S30>/Delay_x' */
  real_T Delay_x_DSTATE_pq;            /* '<S31>/Delay_x' */
  real_T Delay_x_DSTATE_c;             /* '<S32>/Delay_x' */
  real_T Delay_x_DSTATE_j;             /* '<S33>/Delay_x' */
  real_T UnitDelay1_DSTATE;            /* '<S25>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S25>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S28>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S28>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_a;           /* '<S13>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S13>/Discrete-Time Integrator' */
  real_T RateTransition3_Buffer0;      /* '<S9>/Rate Transition3' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S25>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S28>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S13>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S25>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_d;/* '<S28>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_h;/* '<S13>/Discrete-Time Integrator' */
  boolean_T Relay_Mode;                /* '<S12>/Relay' */
} DW_GMV_Code_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T enable_control;               /* '<Root>/enable_control' */
  real_T SP_Speed;                     /* '<Root>/SP_Speed' */
  real_T EnableDCBus;                  /* '<Root>/EnableDCBus' */
  real_T PV_IBus_A;                    /* '<Root>/PV_IBus_A' */
  real_T PV_Iu_A;                      /* '<Root>/PV_Iu_A' */
  real_T PV_Iv_A;                      /* '<Root>/PV_Iv_A' */
  real_T PV_Iw_A;                      /* '<Root>/PV_Iw_A' */
  real_T PV_VBus_A;                    /* '<Root>/PV_VBus_A' */
  real_T PV_PosMech_Deg;               /* '<Root>/PV_PosMech_Deg' */
  real_T enable_autoph;                /* '<Root>/enable_autoph' */
  real_T enable_comp;                  /* '<Root>/enable_comp' */
} ExtU_GMV_Code_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T ControlSignals[6];            /* '<Root>/ControlSignals' */
  real_T DutyA;                        /* '<Root>/DutyA' */
  real_T DutyB;                        /* '<Root>/DutyB' */
  real_T DutyC;                        /* '<Root>/DutyC' */
  real_T Crowbar_Out;                  /* '<Root>/Crowbar_Out' */
  real_T Autoph_offset;                /* '<Root>/Autoph_offset' */
  real_T Autoph_ready;                 /* '<Root>/Autoph_ready' */
  real_T EnableBus;                    /* '<Root>/EnableBus' */
} ExtY_GMV_Code_T;

/* Parameters (auto storage) */
struct P_GMV_Code_T_ {
  real_T CTE_1divSQRT3;                /* Variable: CTE_1divSQRT3
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T CTE_Clarke_11;                /* Variable: CTE_Clarke_11
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T CTE_Clarke_12;                /* Variable: CTE_Clarke_12
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T CTE_Clarke_13;                /* Variable: CTE_Clarke_13
                                        * Referenced by: '<S21>/Gain4'
                                        */
  real_T CTE_Clarke_21;                /* Variable: CTE_Clarke_21
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T CTE_Clarke_22;                /* Variable: CTE_Clarke_22
                                        * Referenced by: '<S21>/Gain3'
                                        */
  real_T CTE_Clarke_23;                /* Variable: CTE_Clarke_23
                                        * Referenced by: '<S21>/Gain5'
                                        */
  real_T CTE_Clarke_inv_11;            /* Variable: CTE_Clarke_inv_11
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T CTE_Clarke_inv_12;            /* Variable: CTE_Clarke_inv_12
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real_T CTE_Clarke_inv_21;            /* Variable: CTE_Clarke_inv_21
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T CTE_Clarke_inv_22;            /* Variable: CTE_Clarke_inv_22
                                        * Referenced by: '<S18>/Gain4'
                                        */
  real_T CTE_Clarke_inv_31;            /* Variable: CTE_Clarke_inv_31
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T CTE_Clarke_inv_32;            /* Variable: CTE_Clarke_inv_32
                                        * Referenced by: '<S18>/Gain5'
                                        */
  real_T CTE_r32_Ld_nom_H;             /* Variable: CTE_r32_Ld_nom_H
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T CTE_r32_Lq_nom_H;             /* Variable: CTE_r32_Lq_nom_H
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Fluxm;                        /* Variable: Fluxm
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Iq_Limit_Max_A;               /* Variable: Iq_Limit_Max_A
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Iq_Limit_Min_A;               /* Variable: Iq_Limit_Min_A
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T K_antiwindup_corriente;       /* Variable: K_antiwindup_corriente
                                        * Referenced by: '<S11>/K_antiwindup_corriente'
                                        */
  real_T K_antiwindup_velocidad;       /* Variable: K_antiwindup_velocidad
                                        * Referenced by: '<S13>/K_antiwindup_velocidad'
                                        */
  real_T Kc;                           /* Variable: Kc
                                        * Referenced by: '<S13>/Kc'
                                        */
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S13>/Kd'
                                        */
  real_T PARAM_DUTY_ON_CB_per;         /* Variable: PARAM_DUTY_ON_CB_per
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T PARAM_VDC_OFF_CB_V;           /* Variable: PARAM_VDC_OFF_CB_V
                                        * Referenced by: '<S12>/Relay'
                                        */
  real_T PARAM_VDC_ON_CB_V;            /* Variable: PARAM_VDC_ON_CB_V
                                        * Referenced by: '<S12>/Relay'
                                        */
  real_T PARAM_r32_1divTiIdReg_s;      /* Variable: PARAM_r32_1divTiIdReg_s
                                        * Referenced by: '<S11>/Ki'
                                        */
  real_T PARAM_r32_kpIdReg_V_A;        /* Variable: PARAM_r32_kpIdReg_V_A
                                        * Referenced by: '<S11>/Kp'
                                        */
  real_T Tc;                           /* Variable: Tc
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T a0;                           /* Variable: a0
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T a1;                           /* Variable: a1
                                        * Referenced by: '<S34>/Gain1'
                                        */
  real_T a2;                           /* Variable: a2
                                        * Referenced by: '<S34>/Gain2'
                                        */
  real_T b1;                           /* Variable: b1
                                        * Referenced by: '<S34>/Gain3'
                                        */
  real_T b2;                           /* Variable: b2
                                        * Referenced by: '<S34>/Gain4'
                                        */
  real_T p;                            /* Variable: p
                                        * Referenced by:
                                        *   '<Root>/deg2rad1'
                                        *   '<S8>/Gain1'
                                        *   '<S14>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S12>/Switch'
                                        */
  real_T alfa_Value;                   /* Expression: 0
                                        * Referenced by: '<S18>/alfa'
                                        */
  real_T Gain6_Gain;                   /* Expression: 10
                                        * Referenced by: '<S18>/Gain6'
                                        */
  real_T Beta_Value;                   /* Expression: 0
                                        * Referenced by: '<S18>/Beta'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay4'
                                        */
  real_T Constant11_Value;             /* Expression: 360
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T deg2rad2_Gain;                /* Expression: -pi/180
                                        * Referenced by: '<Root>/deg2rad2'
                                        */
  real_T OffsetResolver_Value;         /* Expression: 0.055
                                        * Referenced by: '<Root>/OffsetResolver'
                                        */
  real_T Constant12_Value;             /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant12'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay'
                                        */
  real_T Switch_Threshold_n;           /* Expression: pi
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S8>/Delay1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 50
                                        * Referenced by: '<S8>/Switch1'
                                        */
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S34>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S34>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S34>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S34>/Integer Delay3'
                                         */
  real_T D_Gain;                       /* Expression: sps.D
                                        * Referenced by: '<S29>/D'
                                        */
  real_T Delay_x_InitialCondition;     /* Expression: sps.x0
                                        * Referenced by: '<S29>/Delay_x'
                                        */
  real_T C_Gain;                       /* Expression: sps.C
                                        * Referenced by: '<S29>/C'
                                        */
  real_T D_Gain_k;                     /* Expression: sps.D
                                        * Referenced by: '<S30>/D'
                                        */
  real_T Delay_x_InitialCondition_j;   /* Expression: sps.x0
                                        * Referenced by: '<S30>/Delay_x'
                                        */
  real_T C_Gain_d;                     /* Expression: sps.C
                                        * Referenced by: '<S30>/C'
                                        */
  real_T D_Gain_l;                     /* Expression: sps.D
                                        * Referenced by: '<S31>/D'
                                        */
  real_T Delay_x_InitialCondition_o;   /* Expression: sps.x0
                                        * Referenced by: '<S31>/Delay_x'
                                        */
  real_T C_Gain_g;                     /* Expression: sps.C
                                        * Referenced by: '<S31>/C'
                                        */
  real_T D_Gain_m;                     /* Expression: sps.D
                                        * Referenced by: '<S32>/D'
                                        */
  real_T Delay_x_InitialCondition_d;   /* Expression: sps.x0
                                        * Referenced by: '<S32>/Delay_x'
                                        */
  real_T C_Gain_k;                     /* Expression: sps.C
                                        * Referenced by: '<S32>/C'
                                        */
  real_T D_Gain_h;                     /* Expression: sps.D
                                        * Referenced by: '<S33>/D'
                                        */
  real_T Delay_x_InitialCondition_l;   /* Expression: sps.x0
                                        * Referenced by: '<S33>/Delay_x'
                                        */
  real_T C_Gain_dv;                    /* Expression: sps.C
                                        * Referenced by: '<S33>/C'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S25>/Unit Delay1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S25>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T RateTransition3_X0;           /* Expression: 0
                                        * Referenced by: '<S9>/Rate Transition3'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S28>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S28>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S28>/Discrete-Time Integrator'
                                        */
  real_T Switch_Threshold_ax;          /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<S18>/Switch3'
                                        */
  real_T Switch1_Threshold_g;          /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S22>/Switch'
                                        */
  real_T Gain1_Gain;                   /* Expression: 3
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Constant1_Value_n;            /* Expression: -1/6
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 0.5
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 0.5
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Relay_YOn;                    /* Expression: 1
                                        * Referenced by: '<S12>/Relay'
                                        */
  real_T Relay_YOff;                   /* Expression: 0
                                        * Referenced by: '<S12>/Relay'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S13>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S13>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real_T A_Gain;                       /* Expression: sps.A
                                        * Referenced by: '<S29>/A'
                                        */
  real_T B_Gain;                       /* Expression: sps.B
                                        * Referenced by: '<S29>/B'
                                        */
  real_T A_Gain_j;                     /* Expression: sps.A
                                        * Referenced by: '<S30>/A'
                                        */
  real_T B_Gain_i;                     /* Expression: sps.B
                                        * Referenced by: '<S30>/B'
                                        */
  real_T A_Gain_d;                     /* Expression: sps.A
                                        * Referenced by: '<S31>/A'
                                        */
  real_T B_Gain_n;                     /* Expression: sps.B
                                        * Referenced by: '<S31>/B'
                                        */
  real_T A_Gain_p;                     /* Expression: sps.A
                                        * Referenced by: '<S32>/A'
                                        */
  real_T B_Gain_a;                     /* Expression: sps.B
                                        * Referenced by: '<S32>/B'
                                        */
  real_T A_Gain_l;                     /* Expression: sps.A
                                        * Referenced by: '<S33>/A'
                                        */
  real_T B_Gain_o;                     /* Expression: sps.B
                                        * Referenced by: '<S33>/B'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S8>/Constant'
                                        */
  real32_T Id_ref_Value;               /* Computed Parameter: Id_ref_Value
                                        * Referenced by: '<S9>/Id_ref'
                                        */
  uint32_T Delay4_DelayLength;         /* Computed Parameter: Delay4_DelayLength
                                        * Referenced by: '<S8>/Delay4'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S8>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S8>/Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S34>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S34>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S34>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength;  /* Computed Parameter: IntegerDelay3_DelayLength
                                        * Referenced by: '<S34>/Integer Delay3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GMV_Code_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  B_GMV_Code_T *blockIO;
  P_GMV_Code_T *defaultParam;
  ExtU_GMV_Code_T *inputs;
  ExtY_GMV_Code_T *outputs;
  boolean_T paramIsMalloced;
  DW_GMV_Code_T *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern P_GMV_Code_T GMV_Code_P;        /* parameters */

/* Model entry point functions */
extern RT_MODEL_GMV_Code_T *GMV_Code(void);
extern void GMV_Code_initialize(RT_MODEL_GMV_Code_T *const GMV_Code_M);
extern void GMV_Code_step(RT_MODEL_GMV_Code_T *const GMV_Code_M);
extern void GMV_Code_terminate(RT_MODEL_GMV_Code_T * GMV_Code_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition7' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition9' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'GMV_Code'
 * '<S1>'   : 'GMV_Code/Controller'
 * '<S2>'   : 'GMV_Code/First-Order Filter'
 * '<S3>'   : 'GMV_Code/First-Order Filter1'
 * '<S4>'   : 'GMV_Code/First-Order Filter2'
 * '<S5>'   : 'GMV_Code/First-Order Filter3'
 * '<S6>'   : 'GMV_Code/First-Order Filter4'
 * '<S7>'   : 'GMV_Code/scaling rotor angle1'
 * '<S8>'   : 'GMV_Code/speedStimator'
 * '<S9>'   : 'GMV_Code/Controller/FOC'
 * '<S10>'  : 'GMV_Code/Controller/FOC/Discrete_PI_W'
 * '<S11>'  : 'GMV_Code/Controller/FOC/Torque loop'
 * '<S12>'  : 'GMV_Code/Controller/FOC/crowbar_control'
 * '<S13>'  : 'GMV_Code/Controller/FOC/Discrete_PI_W/PI_Antiwindup'
 * '<S14>'  : 'GMV_Code/Controller/FOC/Torque loop/AngleCompensation'
 * '<S15>'  : 'GMV_Code/Controller/FOC/Torque loop/Scaling '
 * '<S16>'  : 'GMV_Code/Controller/FOC/Torque loop/Vsd_limiter'
 * '<S17>'  : 'GMV_Code/Controller/FOC/Torque loop/abc_dq'
 * '<S18>'  : 'GMV_Code/Controller/FOC/Torque loop/dq_abc_3rdArmonic'
 * '<S19>'  : 'GMV_Code/Controller/FOC/Torque loop/isd PI control '
 * '<S20>'  : 'GMV_Code/Controller/FOC/Torque loop/isq PI control'
 * '<S21>'  : 'GMV_Code/Controller/FOC/Torque loop/abc_dq/ClarkeSubsystem'
 * '<S22>'  : 'GMV_Code/Controller/FOC/Torque loop/dq_abc_3rdArmonic/3rd_Harmonic_Injection '
 * '<S23>'  : 'GMV_Code/Controller/FOC/Torque loop/isd PI control /Discrete_PI_Id'
 * '<S24>'  : 'GMV_Code/Controller/FOC/Torque loop/isd PI control /FeedForwardCalculation_Id'
 * '<S25>'  : 'GMV_Code/Controller/FOC/Torque loop/isd PI control /Discrete_PI_Id/PI_FF_Antiwindup'
 * '<S26>'  : 'GMV_Code/Controller/FOC/Torque loop/isq PI control/Discrete_PI_Iq'
 * '<S27>'  : 'GMV_Code/Controller/FOC/Torque loop/isq PI control/FeedForwardCalculation_Iq'
 * '<S28>'  : 'GMV_Code/Controller/FOC/Torque loop/isq PI control/Discrete_PI_Iq/PI_FF_Antiwindup1'
 * '<S29>'  : 'GMV_Code/First-Order Filter/Model'
 * '<S30>'  : 'GMV_Code/First-Order Filter1/Model'
 * '<S31>'  : 'GMV_Code/First-Order Filter2/Model'
 * '<S32>'  : 'GMV_Code/First-Order Filter3/Model'
 * '<S33>'  : 'GMV_Code/First-Order Filter4/Model'
 * '<S34>'  : 'GMV_Code/speedStimator/2nd order Butterwoth_discrete_filter1'
 */
#endif                                 /* RTW_HEADER_GMV_Code_h_ */
