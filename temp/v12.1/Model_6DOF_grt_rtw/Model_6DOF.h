

        /*
    * Model_6DOF.h
    *
            * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "Model_6DOF".
    *
    * Model version              : 9.27
    * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
        * C source code generated on : Thu Nov 17 09:41:05 2022
 * 
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
    */


    #ifndef RTW_HEADER_Model_6DOF_h_
    #define RTW_HEADER_Model_6DOF_h_



                    #ifndef Model_6DOF_COMMON_INCLUDES_
            #define Model_6DOF_COMMON_INCLUDES_
                #include "rtwtypes.h"
        #include "rtw_continuous.h"
        #include "rtw_solver.h"
        #include "rt_logging.h"

            #endif /* Model_6DOF_COMMON_INCLUDES_ */



#include "Model_6DOF_types.h"

#include "rtGetInf.h"

#include "rt_nonfinite.h"

#include <stddef.h>

#include <float.h>

#include <string.h>


    

    

    

    
            /* Macros for accessing real-time model data structure */
                    #ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm) ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm) ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val) ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm) ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val) ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm) ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val) ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm) ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val) ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm) ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm) ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm) ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val) ((rtm)->derivs = (val))
#endif




        #ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm) (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm) ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) ((rtm)->Timing.t)
#endif


    







    

    

    

    

                    /* Block signals for system '<S39>/MATLAB Function4' */
                    
        typedef struct  {
        




                    
                    


                        



                                   real_T vert1[600]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert2[600]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert3[600]; 

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fx_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fy_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Fz_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mx_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T My_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mz_total; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    





        } B_MATLABFunction4_Model_6DOF_T;

                            /* Block signals (default storage) */
                    
        typedef struct  {
        




                    
                    


                        



                                   real_T vert1[1848]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert2[1848]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert3[1848]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert1_m[600]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert2_c[600]; 

                        
                        
                        


                    






                    
                    


                        



                                   real_T vert3_k[600]; 

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator[6]; /* '<S65>/Integrator' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2[5]; /* '<S65>/Gain2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Integrator_d[6]; /* '<S64>/Integrator' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dmasskg; /* '<S71>/Max Mass Change' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dLCGm; /* '<S70>/ LCG Change Saturation' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch3; /* '<S68>/I-Pitch3' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch1; /* '<S68>/I-Pitch1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch2; /* '<S68>/I-Pitch2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch4; /* '<S68>/I-Pitch4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch5; /* '<S68>/I-Pitch5' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Memory1[6]; /* '<S65>/Memory1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Add[45]; /* '<S15>/Add' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Add_p; /* '<S30>/Add' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain9[3]; /* '<S31>/Gain9' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain10; /* '<S31>/Gain10' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1[3]; /* '<S31>/Gain1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_f; /* '<S31>/Gain2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain3[3]; /* '<S31>/Gain3' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4; /* '<S31>/Gain4' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain5[3]; /* '<S31>/Gain5' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain6; /* '<S31>/Gain6' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain7[3]; /* '<S31>/Gain7' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain8; /* '<S31>/Gain8' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6; /* '<S69>/Saturation6' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T out[6]; /* '<S65>/MATLAB Function2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T out_f[6]; /* '<S64>/MATLAB Function2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T L_wave; /* '<S30>/Wave Properties' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T A_wave; /* '<S30>/Wave Properties' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T k_wave; /* '<S30>/Wave Properties' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T w_wave; /* '<S30>/Wave Properties' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction4_c; /* '<S42>/MATLAB Function4' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction1_h; /* '<S42>/MATLAB Function1' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction4_p; /* '<S41>/MATLAB Function4' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction1_p; /* '<S41>/MATLAB Function1' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction4_m; /* '<S40>/MATLAB Function4' */

                        
                        
                        


                    





                    
                    


                        



                            
                                   B_MATLABFunction4_Model_6DOF_T sf_MATLABFunction4_f; /* '<S39>/MATLAB Function4' */

                        
                        
                        


                    





        } B_Model_6DOF_T;

            
                /* Block states (default storage) for system '<Root>' */
                    
        typedef struct  {
        




                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE; /* '<S86>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_o; /* '<S84>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_a; /* '<S72>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_i; /* '<S73>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_f; /* '<S74>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_g; /* '<S75>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_j; /* '<S76>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_DSTATE_m; /* '<S82>/Delay Input2' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Memory1_PreviousInput[6]; /* '<S65>/Memory1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T TimeStampA; /* '<S15>/Derivative1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LastUAtTimeA[45]; /* '<S15>/Derivative1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T TimeStampB; /* '<S15>/Derivative1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LastUAtTimeB[45]; /* '<S15>/Derivative1' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T zerr_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T zerr_int_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T thetaerr_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T thetaerr_int_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T psierr_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T psierr_int_prev; /* '<S1>/pf_controller' */

                        
                        
                        


                    






                    
                    


                        
                                    
                            
        struct {
                    void *LoggedData[6];
        } BV_PWORK; /* '<Root>/BV' */
    

            



                    






                    
                    


                        
                                    
                            
        struct {
                    void *LoggedData[6];
        } BX_PWORK; /* '<Root>/BX' */
    

            



                    





        } DW_Model_6DOF_T;

            
        
                /* Continuous states (default storage) */
                typedef struct  {
                            
                        real_T Integrator_CSTATE[6]; /* '<S65>/Integrator' */
                    
                    
                        real_T Integrator_CSTATE_h[6]; /* '<S64>/Integrator' */
                    
    
        } X_Model_6DOF_T;
        
                                /* State derivatives (default storage) */
                        typedef struct  {
                                
                        real_T Integrator_CSTATE[6]; /* '<S65>/Integrator' */
                    
                    
                        real_T Integrator_CSTATE_h[6]; /* '<S64>/Integrator' */
                    
                } XDot_Model_6DOF_T;                    
                /* State disabled  */
                typedef struct  {                            
                        boolean_T Integrator_CSTATE[6]; /* '<S65>/Integrator' */
                    
                    
                        boolean_T Integrator_CSTATE_h[6]; /* '<S64>/Integrator' */
                    
            } XDis_Model_6DOF_T;        
                        #ifndef ODE3_INTG
        #define ODE3_INTG
        /* ODE3 Integration Data */
        typedef struct  {
        real_T *y; /* output */
        real_T *f[3]; /* derivatives */
        } ODE3_IntgData;
        #endif
        
                        /* Parameters (default storage) */
                struct P_Model_6DOF_T_ {
                    




                    
                    


                        



                            
                            
                                   real_T Ba_0[6]; /* Variable: Ba_0
  * Referenced by: '<S65>/Memory1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bb; /* Variable: Bb
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S16>/Fx'
*   '<S17>/Fy'
*   '<S18>/Fz'
*   '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bv_0[6]; /* Variable: Bv_0
  * Referenced by: '<S65>/Integrator'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Bx_0[6]; /* Variable: Bx_0
  * Referenced by: '<S64>/Integrator'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Ixx; /* Variable: Ixx
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Ixy; /* Variable: Ixy
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Ixz; /* Variable: Ixz
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Iyy; /* Variable: Iyy
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Iyz; /* Variable: Iyz
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Izz; /* Variable: Izz
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mb; /* Variable: Mb
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S16>/Fx'
*   '<S17>/Fy'
*   '<S18>/Fz'
*   '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Seastate; /* Variable: Seastate
  * Referenced by: '<S3>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Ts; /* Variable: Ts
  * Referenced by:
*   '<S1>/pf_controller'
*   '<S1>/pf_controller1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Xb; /* Variable: Xb
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Xcg[3]; /* Variable: Xcg
  * Referenced by: '<S15>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Xg; /* Variable: Xg
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yb; /* Variable: Yb
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yg; /* Variable: Yg
  * Referenced by: '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zb; /* Variable: Zb
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S65>/MATLAB Function2'
*   '<S30>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zg; /* Variable: Zg
  * Referenced by:
*   '<S11>/Mx'
*   '<S12>/My'
*   '<S13>/Mz'
*   '<S65>/MATLAB Function2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_BP1[616]; /* Variable: dA_BP1
  * Referenced by: '<S31>/Constant14'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_BP2[616]; /* Variable: dA_BP2
  * Referenced by: '<S31>/Constant68'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_Hull[2914]; /* Variable: dA_Hull
  * Referenced by: '<S31>/Constant8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_PH[550]; /* Variable: dA_PH
  * Referenced by: '<S31>/Constant101'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_SProot[904]; /* Variable: dA_SProot
  * Referenced by: '<S31>/Constant107'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_Sail[564]; /* Variable: dA_Sail
  * Referenced by: '<S31>/Constant95'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X1a[200]; /* Variable: dA_X1a
  * Referenced by: '<S31>/Constant21'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X1b[200]; /* Variable: dA_X1b
  * Referenced by: '<S31>/Constant28'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X2a[200]; /* Variable: dA_X2a
  * Referenced by: '<S31>/Constant33'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X2b[200]; /* Variable: dA_X2b
  * Referenced by: '<S31>/Constant39'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X3a[200]; /* Variable: dA_X3a
  * Referenced by: '<S31>/Constant45'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X3b[200]; /* Variable: dA_X3b
  * Referenced by: '<S31>/Constant51'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X4a[200]; /* Variable: dA_X4a
  * Referenced by: '<S31>/Constant57'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T dA_X4b[200]; /* Variable: dA_X4b
  * Referenced by: '<S31>/Constant63'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n_Hull[8742]; /* Variable: n_Hull
  * Referenced by: '<S31>/Constant5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n_PH[1650]; /* Variable: n_PH
  * Referenced by: '<S31>/Constant100'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n_SProot[2712]; /* Variable: n_SProot
  * Referenced by: '<S31>/Constant106'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n_Sail[1692]; /* Variable: n_Sail
  * Referenced by: '<S31>/Constant94'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_BP1; /* Variable: nt_BP1
  * Referenced by: '<S31>/Constant12'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_BP2; /* Variable: nt_BP2
  * Referenced by: '<S31>/Constant66'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_Hull; /* Variable: nt_Hull
  * Referenced by: '<S31>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_PH; /* Variable: nt_PH
  * Referenced by: '<S31>/Constant99'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_SProot; /* Variable: nt_SProot
  * Referenced by: '<S31>/Constant105'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_Sail; /* Variable: nt_Sail
  * Referenced by: '<S31>/Constant93'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X1a; /* Variable: nt_X1a
  * Referenced by: '<S31>/Constant19'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X1b; /* Variable: nt_X1b
  * Referenced by: '<S31>/Constant26'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X2a; /* Variable: nt_X2a
  * Referenced by: '<S31>/Constant31'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X2b; /* Variable: nt_X2b
  * Referenced by: '<S31>/Constant37'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X3a; /* Variable: nt_X3a
  * Referenced by: '<S31>/Constant43'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X3b; /* Variable: nt_X3b
  * Referenced by: '<S31>/Constant49'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X4a; /* Variable: nt_X4a
  * Referenced by: '<S31>/Constant55'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nt_X4b; /* Variable: nt_X4b
  * Referenced by: '<S31>/Constant61'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T psi_ref; /* Variable: psi_ref
  * Referenced by: '<S1>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T v_ref; /* Variable: v_ref
  * Referenced by: '<S1>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_BP1[1848]; /* Variable: vt1_BP1
  * Referenced by: '<S31>/Constant9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_BP2[1848]; /* Variable: vt1_BP2
  * Referenced by: '<S31>/Constant69'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_Hull[8742]; /* Variable: vt1_Hull
  * Referenced by: '<S31>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_PH[1650]; /* Variable: vt1_PH
  * Referenced by: '<S31>/Constant96'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_SProot[2712]; /* Variable: vt1_SProot
  * Referenced by: '<S31>/Constant102'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_Sail[1692]; /* Variable: vt1_Sail
  * Referenced by: '<S31>/Constant90'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X1a[600]; /* Variable: vt1_X1a
  * Referenced by: '<S31>/Constant23'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X1b[600]; /* Variable: vt1_X1b
  * Referenced by: '<S31>/Constant30'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X2a[600]; /* Variable: vt1_X2a
  * Referenced by: '<S31>/Constant34'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X2b[600]; /* Variable: vt1_X2b
  * Referenced by: '<S31>/Constant40'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X3a[600]; /* Variable: vt1_X3a
  * Referenced by: '<S31>/Constant46'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X3b[600]; /* Variable: vt1_X3b
  * Referenced by: '<S31>/Constant52'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X4a[600]; /* Variable: vt1_X4a
  * Referenced by: '<S31>/Constant58'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt1_X4b[600]; /* Variable: vt1_X4b
  * Referenced by: '<S31>/Constant64'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_BP1[1848]; /* Variable: vt2_BP1
  * Referenced by: '<S31>/Constant10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_BP2[1848]; /* Variable: vt2_BP2
  * Referenced by: '<S31>/Constant16'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_Hull[8742]; /* Variable: vt2_Hull
  * Referenced by: '<S31>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_PH[1650]; /* Variable: vt2_PH
  * Referenced by: '<S31>/Constant97'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_SProot[2712]; /* Variable: vt2_SProot
  * Referenced by: '<S31>/Constant103'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_Sail[1692]; /* Variable: vt2_Sail
  * Referenced by: '<S31>/Constant91'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X1a[600]; /* Variable: vt2_X1a
  * Referenced by: '<S31>/Constant17'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X1b[600]; /* Variable: vt2_X1b
  * Referenced by: '<S31>/Constant24'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X2a[600]; /* Variable: vt2_X2a
  * Referenced by: '<S31>/Constant22'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X2b[600]; /* Variable: vt2_X2b
  * Referenced by: '<S31>/Constant35'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X3a[600]; /* Variable: vt2_X3a
  * Referenced by: '<S31>/Constant41'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X3b[600]; /* Variable: vt2_X3b
  * Referenced by: '<S31>/Constant47'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X4a[600]; /* Variable: vt2_X4a
  * Referenced by: '<S31>/Constant53'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt2_X4b[600]; /* Variable: vt2_X4b
  * Referenced by: '<S31>/Constant59'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_BP1[1848]; /* Variable: vt3_BP1
  * Referenced by: '<S31>/Constant11'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_BP2[1848]; /* Variable: vt3_BP2
  * Referenced by: '<S31>/Constant65'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_Hull[8742]; /* Variable: vt3_Hull
  * Referenced by: '<S31>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_PH[1650]; /* Variable: vt3_PH
  * Referenced by: '<S31>/Constant98'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_SProot[2712]; /* Variable: vt3_SProot
  * Referenced by: '<S31>/Constant104'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_Sail[1692]; /* Variable: vt3_Sail
  * Referenced by: '<S31>/Constant92'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X1a[600]; /* Variable: vt3_X1a
  * Referenced by: '<S31>/Constant18'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X1b[600]; /* Variable: vt3_X1b
  * Referenced by: '<S31>/Constant25'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X2a[600]; /* Variable: vt3_X2a
  * Referenced by: '<S31>/Constant29'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X2b[600]; /* Variable: vt3_X2b
  * Referenced by: '<S31>/Constant36'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X3a[600]; /* Variable: vt3_X3a
  * Referenced by: '<S31>/Constant42'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X3b[600]; /* Variable: vt3_X3b
  * Referenced by: '<S31>/Constant48'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X4a[600]; /* Variable: vt3_X4a
  * Referenced by: '<S31>/Constant54'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T vt3_X4b[600]; /* Variable: vt3_X4b
  * Referenced by: '<S31>/Constant60'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T z_ref; /* Variable: z_ref
  * Referenced by: '<S1>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value; /* Expression: -7.11
  * Referenced by: '<S68>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant4_Value; /* Expression: -7.11
  * Referenced by: '<S68>/Constant4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant6_Value; /* Expression: -7.11
  * Referenced by: '<S68>/Constant6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant8_Value; /* Expression: -7.11
  * Referenced by: '<S68>/Constant8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant10_Value; /* Expression: -7.11
  * Referenced by: '<S68>/Constant10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RateMin_Value; /* Expression: -14.65
  * Referenced by: '<S69>/Rate Min'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LowerRatelimit_Value; /* Expression: -5.83e-4
  * Referenced by: '<S70>/Lower Rate limit'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant3_Value; /* Expression: -100
  * Referenced by: '<S71>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain; /* Expression: 1
  * Referenced by: '<S65>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant1_Value; /* Expression: 0
  * Referenced by: '<S1>/Constant1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_l; /* Expression: 100
  * Referenced by: '<S71>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt; /* Computed Parameter: sampletime_WtEt
  * Referenced by: '<S86>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition; /* Expression: 0
  * Referenced by: '<S86>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxMassChange_UpperSat; /* Expression: 20000
  * Referenced by: '<S71>/Max Mass Change'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxMassChange_LowerSat; /* Expression: -20000
  * Referenced by: '<S71>/Max Mass Change'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP1_Value[3]; /* Expression: [31.924; 3.861; -3.861;]
  * Referenced by: '<S9>/X_SP1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP2_Value[3]; /* Expression: [31.924; 3.861; 3.861;]
  * Referenced by: '<S9>/X_SP2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP3_Value[3]; /* Expression: [31.924; -3.861; 3.861;]
  * Referenced by: '<S9>/X_SP3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP4_Value[3]; /* Expression: [31.924; -3.861; -3.861;]
  * Referenced by: '<S9>/X_SP4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_XB_Value[3]; /* Expression: [-10.465; 0; 9.732;]
  * Referenced by: '<S9>/X_XB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP1_Value_c[3]; /* Expression: [31.924; 3.861; -3.861;]
  * Referenced by: '<S30>/X_SP1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP2_Value_j[3]; /* Expression: [31.924; 3.861; 3.861;]
  * Referenced by: '<S30>/X_SP2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP3_Value_n[3]; /* Expression: [31.924; -3.861; 3.861;]
  * Referenced by: '<S30>/X_SP3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_SP4_Value_f[3]; /* Expression: [31.924; -3.861; -3.861;]
  * Referenced by: '<S30>/X_SP4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T X_XB_Value_i[3]; /* Expression: [-10.465; 0; 9.732;]
  * Referenced by: '<S30>/X_XB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T phi_wave_Value; /* Expression: 0
  * Referenced by: '<S15>/phi_wave'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T beta_wave_Value; /* Expression: 0
  * Referenced by: '<S15>/beta_wave'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T nh_Value[3]; /* Expression: [-1; 0; 0;]
  * Referenced by: '<S9>/nh'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n1_Value[3]; /* Expression: [0; 1/sqrt(2); -1/sqrt(2);]
  * Referenced by: '<S9>/n1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n2_Value[3]; /* Expression: [0; 1/sqrt(2); 1/sqrt(2);]
  * Referenced by: '<S9>/n2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n3_Value[3]; /* Expression: [0; -1/sqrt(2); 1/sqrt(2);]
  * Referenced by: '<S9>/n3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n4_Value[3]; /* Expression: [0; -1/sqrt(2); -1/sqrt(2);]
  * Referenced by: '<S9>/n4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T n5_Value[3]; /* Expression: [0; 1; 0;]
  * Referenced by: '<S9>/n5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T UpperRatelimit_Value; /* Expression: 5.83e-4
  * Referenced by: '<S70>/Upper Rate limit'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_l; /* Computed Parameter: sampletime_WtEt_l
  * Referenced by: '<S84>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_c; /* Expression: 0
  * Referenced by: '<S84>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LCGChangeSaturation_UpperSat; /* Expression: 0.5
  * Referenced by: '<S70>/ LCG Change Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T LCGChangeSaturation_LowerSat; /* Expression: -0.5
  * Referenced by: '<S70>/ LCG Change Saturation'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant_Value; /* Expression: 7.11
  * Referenced by: '<S68>/Constant'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_m; /* Computed Parameter: sampletime_WtEt_m
  * Referenced by: '<S72>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_n; /* Expression: 0
  * Referenced by: '<S72>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection_UpperSat; /* Expression: 30
  * Referenced by: '<S68>/Max Deflection'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection_LowerSat; /* Expression: -30
  * Referenced by: '<S68>/Max Deflection'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch3_Gain; /* Expression: 1
  * Referenced by: '<S68>/I-Pitch3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant3_Value_a; /* Expression: 7.11
  * Referenced by: '<S68>/Constant3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_f; /* Computed Parameter: sampletime_WtEt_f
  * Referenced by: '<S73>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_g; /* Expression: 0
  * Referenced by: '<S73>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection1_UpperSat; /* Expression: 30
  * Referenced by: '<S68>/Max Deflection1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection1_LowerSat; /* Expression: -30
  * Referenced by: '<S68>/Max Deflection1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch1_Gain; /* Expression: 1
  * Referenced by: '<S68>/I-Pitch1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant5_Value; /* Expression: 7.11
  * Referenced by: '<S68>/Constant5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_g; /* Computed Parameter: sampletime_WtEt_g
  * Referenced by: '<S74>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_m; /* Expression: 0
  * Referenced by: '<S74>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection2_UpperSat; /* Expression: 30
  * Referenced by: '<S68>/Max Deflection2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection2_LowerSat; /* Expression: -30
  * Referenced by: '<S68>/Max Deflection2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch2_Gain; /* Expression: 1
  * Referenced by: '<S68>/I-Pitch2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant7_Value; /* Expression: 7.11
  * Referenced by: '<S68>/Constant7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_k; /* Computed Parameter: sampletime_WtEt_k
  * Referenced by: '<S75>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_j; /* Expression: 0
  * Referenced by: '<S75>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection3_UpperSat; /* Expression: 30
  * Referenced by: '<S68>/Max Deflection3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection3_LowerSat; /* Expression: -30
  * Referenced by: '<S68>/Max Deflection3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch4_Gain; /* Expression: 1
  * Referenced by: '<S68>/I-Pitch4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant9_Value; /* Expression: 7.11
  * Referenced by: '<S68>/Constant9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_o; /* Computed Parameter: sampletime_WtEt_o
  * Referenced by: '<S76>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_jw; /* Expression: 0
  * Referenced by: '<S76>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection4_UpperSat; /* Expression: 30
  * Referenced by: '<S68>/Max Deflection4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T MaxDeflection4_LowerSat; /* Expression: -30
  * Referenced by: '<S68>/Max Deflection4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T IPitch5_Gain; /* Expression: 1
  * Referenced by: '<S68>/I-Pitch5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kpp_tableData[12]; /* Expression: [-1.3011E-02
-1.6962E-02
-2.0682E-02
-3.1419E-02
-6.4407E-02
-1.9322E-01
1.9322E-01
6.4378E-02
3.1944E-02
2.1072E-02
1.6415E-02
1.3407E-02]
  * Referenced by: '<S11>/K'p|p|'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kpp_bp01Data[12]; /* Expression: [-0.0015
-0.0012
-0.0009
-0.0006
-0.0003
-0.0001
0.0001
0.0003
0.0006
0.0009
0.0012
0.0015]
  * Referenced by: '<S11>/K'p|p|'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kup_tableData[4]; /* Expression: [-4.0344E-04
-8.1402E-04
-1.2116E-03
-1.6125E-03]
  * Referenced by: '<S11>/K'up'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kup_bp01Data[4]; /* Expression: [0.03999989
0.079999993
0.11999963
0.15999956]
  * Referenced by: '<S11>/K'up'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kur_tableData[12]; /* Expression: [-1.3011E-02
-1.6962E-02
-2.0682E-02
-3.1419E-02
-6.4407E-02
-1.9322E-01
1.9322E-01
6.4378E-02
3.1944E-02
2.1072E-02
1.6415E-02
1.3407E-02]
  * Referenced by: '<S11>/K'ur'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kur_bp01Data[12]; /* Expression: [-0.0015
-0.0012
-0.0009
-0.0006
-0.0003
-0.0001
0.0001
0.0003
0.0006
0.0009
0.0012
0.0015]
  * Referenced by: '<S11>/K'ur'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat; /* Expression: -13.8724
  * Referenced by: '<S11>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat; /* Expression: -35.0624
  * Referenced by: '<S11>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kuvw_tableData[48]; /* Expression: reshape([0.0000000E+00
1.5570290E-04
3.7677829E-04
6.0025374E-04
0.0000000E+00
1.5575678E-04
3.8557685E-04
6.0103850E-04
0.0000000E+00
1.7511088E-04
3.8376789E-04
6.0108480E-04
0.0000000E+00
1.9071552E-04
4.0986649E-04
6.4012030E-04
0.0000000E+00
1.8940622E-04
4.0946931E-04
6.3613461E-04
0.0000000E+00
1.8621071E-04
4.0619654E-04
7.0286379E-04
0.0000000E+00
2.0712189E-04
4.4751988E-04
7.0514631E-04
0.0000000E+00
1.9895751E-04
4.3099356E-04
6.6994571E-04
0.0000000E+00
1.9568554E-04
4.2679977E-04
6.6445067E-04
0.0000000E+00
2.4359563E-04
5.3740096E-04
8.5879902E-04
0.0000000E+00
2.0890025E-04
4.5502130E-04
7.1388224E-04
0.0000000E+00
2.0575072E-04
4.5505766E-04
7.0285206E-04],[4,3,4])
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kuvw_bp01Data[4]; /* Expression: [0
4
8
12]
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kuvw_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Kuvw_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX1_tableData[36]; /* Expression: reshape([-3.9047E-05
4.5684E-07
3.9769E-05
-3.8309E-05
1.2643E-06
4.0809E-05
-3.0256E-05
1.2643E-06
4.8387E-05
-3.7558E-05
2.1545E-06
4.2083E-05
-3.9057E-05
3.6064E-07
3.9562E-05
-3.8473E-05
1.0476E-06
4.0437E-05
-3.0256E-05
1.4418E-06
4.8387E-05
-3.7906E-05
1.7415E-06
4.1434E-05
-3.8945E-05
2.8249E-07
3.9429E-05
-3.8396E-05
9.1134E-07
4.0237E-05
-3.8190E-05
9.1134E-07
4.0733E-05
-3.7932E-05
1.5343E-06
4.1020E-05
],[3,4,3])
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX1_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX1_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX1_bp03Data[3]; /* Expression: [-5.14444 -3.08666664 -1.54332]
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX2_tableData[36]; /* Expression: reshape([-3.5775E-05
-2.4080E-07
3.3150E-05
-3.4263E-05
1.2268E-06
3.5342E-05
-2.3577E-05
1.2268E-06
4.6338E-05
-3.2368E-05
3.5682E-06
3.9469E-05
-3.5785E-05
-3.3131E-07
3.3067E-05
-3.4544E-05
8.9010E-07
3.4889E-05
-2.3577E-05
1.7076E-06
4.6338E-05
-3.3141E-05
2.4187E-06
3.7389E-05
-3.5809E-05
-5.7189E-07
3.3046E-05
-3.4706E-05
4.2723E-07
3.4588E-05
-3.4017E-05
4.2723E-07
3.5657E-05
-3.3562E-05
1.6134E-06
3.6605E-05
],[3,4,3])
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX2_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX2_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX2_bp03Data[3]; /* Expression: [-5.14444 -3.08666664 -1.54332]
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX3_tableData[36]; /* Expression: reshape([-4.3139E-05
1.7292E-07
4.5001E-05
-4.4081E-05
-1.2796E-06
4.2448E-05
-4.9749E-05
-1.2796E-06
2.6691E-05
-4.5613E-05
-3.5861E-06
3.8362E-05
-4.2707E-05
2.7384E-07
4.4575E-05
-4.3360E-05
-9.3523E-07
4.2465E-05
-4.9749E-05
-1.7362E-06
2.6691E-05
-4.4279E-05
-2.4363E-06
3.9821E-05
-4.1687E-05
5.3371E-07
4.3082E-05
-4.2289E-05
-4.5361E-07
4.1207E-05
-4.2616E-05
-4.5361E-07
4.0204E-05
-4.2521E-05
-1.6159E-06
3.9463E-05
],[3,4,3])
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX3_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX3_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX3_bp03Data[3]; /* Expression: [-5.14444 -3.08666664 -1.54332]
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX4_tableData[36]; /* Expression: reshape([-4.0969E-05
-4.5313E-07
4.0019E-05
-4.1787E-05
-1.2714E-06
3.9006E-05
-4.8908E-05
-1.2714E-06
3.0663E-05
-4.2681E-05
-2.1920E-06
3.7920E-05
-4.0777E-05
-3.6185E-07
4.0047E-05
-4.1470E-05
-1.0577E-06
3.9147E-05
-4.8908E-05
-1.4679E-06
3.0663E-05
-4.2187E-05
-1.7779E-06
3.8312E-05
-4.0496E-05
-2.8854E-07
4.0049E-05
-4.1082E-05
-9.2714E-07
3.9223E-05
-4.1472E-05
-9.2714E-07
3.8784E-05
-4.1733E-05
-1.5768E-06
3.8383E-05
],[3,4,3])
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX4_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX4_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T KdX4_bp03Data[3]; /* Expression: [-5.14444 -3.08666664 -1.54332]
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CGi_Value[45]; /* Expression: [5.0784E+00	0.0000E+00	8.0728E-03;
1.1013E+01	0.0000E+00	2.5384E-01;
1.7302E+01	0.0000E+00	3.0728E-01;
2.5741E+01	0.0000E+00	4.1417E-01;
3.4688E+01	0.0000E+00	4.1585E-01;
4.2324E+01	0.0000E+00	3.2444E-01;
4.9992E+01	0.0000E+00	3.3454E-01;
5.7427E+01	0.0000E+00	1.7420E-02;
6.3078E+01	0.0000E+00	1.8824E-02;
6.6703E+01	0.0000E+00	1.1340E-02;
2.5141E+01	0.0000E+00	8.6491E+00;
2.1732E+01	0.0000E+00	9.7273E+00;
6.3166E+01	0.0000E+00	-4.0823E-17;
2.2043E+01	0.0000E+00	9.7261E+00;
6.3451E+01	0.0000E+00	-6.2238E-17;
]
  * Referenced by: '<S15>/CGi'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Cvmdm_Value[45]; /* Expression: [8.4658E+04	1.7229E+05	1.6487E+05
2.3551E+04	4.3394E+05	3.6176E+05
1.1585E+03	5.9767E+05	4.2996E+05
1.4123E+02	1.1354E+06	6.5606E+05
9.1503E+01	6.9712E+05	5.1688E+05
9.6110E+01	6.7201E+05	5.1905E+05
1.2163E+04	5.7818E+05	4.7547E+05
3.7219E+04	3.4697E+05	3.3508E+05
1.9318E+04	7.7284E+04	7.6560E+04
1.5368E+04	2.6375E+04	2.6268E+04
1.8312E+04	4.5870E+05	5.1108E+04
3.1859E+02	1.2645E+04	3.4886E+02
3.0285E+03	4.4945E+04	4.4489E+04
7.9160E+02	8.8963E+02	1.3306E+04
1.2115E+03	3.9547E+04	3.9205E+04
]
  * Referenced by: '<S15>/Cvm*dm'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant6_Value_a; /* Expression: 1025
  * Referenced by: '<S30>/Constant6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant7_Value_i; /* Expression: 9.81
  * Referenced by: '<S30>/Constant7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant2_Value_l5; /* Expression: 0.4406
  * Referenced by: '<S30>/Constant2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant77_Value[3]; /* Expression: [-90; 0; 0;]
  * Referenced by: '<S31>/Constant77'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain9_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain10_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant76_Value[3]; /* Expression: [0.313941517;
0;
0.138536015;]
  * Referenced by: '<S31>/Constant76'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CG_Value[3]; /* Expression: [32.3114; 0; 0;]
  * Referenced by: '<S43>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant6_Value_h[3]; /* Expression: [-135; -20; 0;]
  * Referenced by: '<S31>/Constant6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_n; /* Expression: pi/180
  * Referenced by: '<S31>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant15_Value[3]; /* Expression: [0.893348257;
0.043600552;
-0.043394945;]
  * Referenced by: '<S31>/Constant15'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CG_Value_n[3]; /* Expression: [32.3114; 0; 0;]
  * Referenced by: '<S39>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant70_Value[3]; /* Expression: [-45; -20; 0;]
  * Referenced by: '<S31>/Constant70'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain3_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant71_Value[3]; /* Expression: [0.892195724;
0.043607982;
0.043868661;]
  * Referenced by: '<S31>/Constant71'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CG_Value_h[3]; /* Expression: [32.3114; 0; 0;]
  * Referenced by: '<S40>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant72_Value[3]; /* Expression: [45; -20; 0;]
  * Referenced by: '<S31>/Constant72'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain5_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain6_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant73_Value[3]; /* Expression: [0.892195724;
-0.043607982;
0.043868661;]
  * Referenced by: '<S31>/Constant73'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CG_Value_nc[3]; /* Expression: [32.3114; 0; 0;]
  * Referenced by: '<S41>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant74_Value[3]; /* Expression: [135; -20; 0;]
  * Referenced by: '<S31>/Constant74'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain7_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain8_Gain; /* Expression: pi/180
  * Referenced by: '<S31>/Gain8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Constant75_Value[3]; /* Expression: [0.892195724;
-0.043607982;
-0.043868661;]
  * Referenced by: '<S31>/Constant75'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T CG_Value_nd[3]; /* Expression: [32.3114; 0; 0;]
  * Referenced by: '<S42>/CG'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain20_Gain; /* Expression: -1
  * Referenced by: '<S14>/Gain20'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation5_UpperSat; /* Expression: -13.8724

  * Referenced by: '<S14>/Saturation5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation5_LowerSat; /* Expression: -36.3724

  * Referenced by: '<S14>/Saturation5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation7_UpperSat; /* Expression: -1.54333333
  * Referenced by: '<S14>/Saturation7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation7_LowerSat; /* Expression: -5.14444

  * Referenced by: '<S14>/Saturation7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ThrustDeduction25m1_tableData[12]; /* Expression: reshape([0.245958
0.251311246
0.25251
0.251322
0.2444134
0.2498597
0.2509219
0.2498992
0.2496
0.2594532
0.257802
0.2475762],[4,3])
  * Referenced by: '<S14>/Thrust Deduction, 25m1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ThrustDeduction25m1_bp01Data[4]; /* Expression: [-36.3724
-18.3724
-15.3724
-13.8724]
  * Referenced by: '<S14>/Thrust Deduction, 25m1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ThrustDeduction25m1_bp02Data[3]; /* Expression: [-5.14444 -3.086664 -1.543332]
  * Referenced by: '<S14>/Thrust Deduction, 25m1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T RateMax_Value; /* Expression: 14.65
  * Referenced by: '<S69>/Rate Max'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T sampletime_WtEt_d; /* Computed Parameter: sampletime_WtEt_d
  * Referenced by: '<S82>/sample time'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T DelayInput2_InitialCondition_e; /* Expression: 0
  * Referenced by: '<S82>/Delay Input2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_UpperSat; /* Expression: 10
  * Referenced by: '<S69>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_LowerSat; /* Expression: 0.01
  * Referenced by: '<S69>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat_a; /* Expression: -13.8724
  * Referenced by: '<S12>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat_d; /* Expression: -35.0624
  * Referenced by: '<S12>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T M_uvwa_tableData[84]; /* Expression: reshape([-2.40251E-03
-1.59538E-03
-8.21748E-04
-3.60182E-06
8.13350E-04
1.50586E-03
2.39707E-03
-2.43392E-03
-1.61509E-03
-8.50748E-04
-3.60182E-06
8.24271E-04
1.51842E-03
2.43805E-03
-2.45014E-03
-1.65711E-03
-9.11210E-04
-3.60182E-06
8.61300E-04
1.57459E-03
2.42777E-03
-2.54380E-03
-1.68842E-03
-8.33041E-04
2.23377E-05
8.77717E-04
1.73310E-03
2.58847E-03
-2.63734E-03
-1.75078E-03
-8.64221E-04
2.23377E-05
9.08896E-04
1.79546E-03
2.68201E-03
-2.83738E-03
-1.88414E-03
-9.30902E-04
2.23377E-05
9.75577E-04
1.92882E-03
2.88206E-03
-2.63786E-03
-1.74504E-03
-8.52211E-04
4.06140E-05
9.33439E-04
1.82626E-03
2.71909E-03
-2.63728E-03
-1.74465E-03
-8.52017E-04
4.06140E-05
9.33245E-04
1.82588E-03
2.71851E-03
-2.86138E-03
-1.89405E-03
-9.26716E-04
4.06140E-05
1.00794E-03
1.97527E-03
2.94260E-03
-0.002723494
-0.001792522
-0.000861549
6.9423E-05
0.001000396
0.001931368
0.002862341
-0.002736476
-0.001798489
-0.000860502
6.9423E-05
0.001015473
0.00195346
0.002891447
-0.002765582
-0.00182058
-0.000875579
6.9423E-05
0.001014425
0.001959426
0.002904428],[7,3,4])
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T M_uvwa_bp01Data[7]; /* Expression: [-12
-8
-4
0
4
8
12]
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T M_uvwa_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T M_uvwa_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain; /* Expression: 1.1
  * Referenced by: '<S12>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q1_tableData[21]; /* Expression: reshape([0.000594819
0.000394915
0.000195011
-4.89222E-06
-0.000204796
-0.0004047
-0.000604603
0.000596203
0.000392018
0.000187833
-1.6352E-05
-0.000220537
-0.000424722
-0.000628907
0.000582351
0.000381446
0.000180542
-2.03625E-05
-0.000221267
-0.000422171
-0.000623076
],[7,3])
  * Referenced by: '<S24>/ZudX1 q+1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q1_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S24>/ZudX1 q+1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q1_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S24>/ZudX1 q+1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain_j; /* Expression: 1
  * Referenced by: '<S24>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q2_tableData[21]; /* Expression: reshape([0.000583784
0.000394316
0.000204847
1.53782E-05
-0.000174091
-0.000363559
-0.000553028
0.00056228
0.000374724
0.000187169
-3.86644E-07
-0.000187942
-0.000375498
-0.000563053
0.000546298
0.000362052
0.000177806
-6.43933E-06
-0.000190685
-0.000374931
-0.000559176],[7,3])
  * Referenced by: '<S24>/ZudX1 q+2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q2_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S24>/ZudX1 q+2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q2_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S24>/ZudX1 q+2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain3_Gain_c; /* Expression: 1
  * Referenced by: '<S24>/Gain3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q3_tableData[21]; /* Expression: reshape([-0.000586989
-0.000395541
-0.000204094
-1.26467E-05
0.000178801
0.000370248
0.000561695
-0.000568868
-0.000379268
-0.000189669
-6.86388E-08
0.000189531
0.000379131
0.000568731
-0.000565299
-0.000378949
-0.000192598
-6.24776E-06
0.000180103
0.000366453
0.000552804],[7,3])
  * Referenced by: '<S24>/ZudX1 q+3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q3_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S24>/ZudX1 q+3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q3_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S24>/ZudX1 q+3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_nk; /* Expression: 1
  * Referenced by: '<S24>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q4_tableData[21]; /* Expression: reshape([-0.000638396
-0.000426715
-0.000215035
-3.35454E-06
0.000208326
0.000420006
0.000631687
-0.000598951
-0.000393944
-0.000188937
1.60698E-05
0.000221077
0.000426084
0.000631091
-0.000622514
-0.000421726
-0.000220939
-2.01522E-05
0.000180635
0.000381422
0.000582209],[7,3])
  * Referenced by: '<S24>/ZudX1 q+4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q4_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S24>/ZudX1 q+4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q4_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S24>/ZudX1 q+4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_c; /* Expression: 1
  * Referenced by: '<S24>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q5_tableData[21]; /* Expression: reshape([-0.000461714
-0.000296336
-0.000130959
3.44194E-05
0.000199797
0.000365175
0.000530553
-0.000503641
-0.000327652
-0.000151663
2.43257E-05
0.000200315
0.000376303
0.000552292
-0.000536558
-0.000356664
-0.00017677
3.1235E-06
0.000183017
0.000362911
0.000542805],[7,3])
  * Referenced by: '<S24>/ZudX1 q+5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q5_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S24>/ZudX1 q+5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q5_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S24>/ZudX1 q+5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain_l; /* Expression: 1
  * Referenced by: '<S24>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_a; /* Expression: 1.3
  * Referenced by: '<S12>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mprop_tableData[3]; /* Expression: [-0.00022 -0.0002 -0.00015]
  * Referenced by: '<S12>/M'prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mprop_bp01Data[3]; /* Expression: [-7.7166666 -5.1444444 -3.08666664]
  * Referenced by: '<S12>/M'prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation3_UpperSat; /* Expression: 0.02
  * Referenced by: '<S12>/Saturation3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation3_LowerSat; /* Expression: -0.02
  * Referenced by: '<S12>/Saturation3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mqq2_tableData[16]; /* Expression: [-2.2571E-03
-2.3029E-03
-2.0965E-03
-2.0229E-03
-2.1546E-03
-1.4789E-03
-1.5664E-03
-1.4544E-03
-1.4705E-03
-1.4942E-03
-1.8790E-03
-1.8821E-03
-2.1009E-03
-2.0521E-03
-2.1685E-03
-2.0822E-03
]
  * Referenced by: '<S12>/Mqq2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mqq2_bp01Data[16]; /* Expression: [-0.02
-0.015
-0.012958963
-0.009719222
-0.006479482
-0.003239741
-0.00161987
-0.000647948
0.000647948
0.00161987
0.003239741
0.006479482
0.009719222
0.012958963
0.015
0.02
]
  * Referenced by: '<S12>/Mqq2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_UpperSat; /* Expression: 0.0015
  * Referenced by: '<S12>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_LowerSat; /* Expression: -0.0015
  * Referenced by: '<S12>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mwq_tableData[12]; /* Expression: [-1.3011E-02
-1.6962E-02
-2.0682E-02
-3.1419E-02
-6.4407E-02
-1.9322E-01
1.9322E-01
6.4378E-02
3.1944E-02
2.1072E-02
1.6415E-02
1.3407E-02]
  * Referenced by: '<S12>/Mwq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Mwq_bp01Data[12]; /* Expression: [-0.0015
-0.0012
-0.0009
-0.0006
-0.0003
-0.0001
0.0001
0.0003
0.0006
0.0009
0.0012
0.0015]
  * Referenced by: '<S12>/Mwq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat_d; /* Expression: -13.8724
  * Referenced by: '<S13>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat_o; /* Expression: -35.0624
  * Referenced by: '<S13>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nuvw_tableData[48]; /* Expression: reshape([0.0000000E+00
1.1975814E-03
2.7970643E-03
4.1308534E-03
0.0000000E+00
1.2111628E-03
2.9207146E-03
4.1207837E-03
0.0000000E+00
1.4959851E-03
2.9486406E-03
4.1213058E-03
0.0000000E+00
1.4879743E-03
2.9975710E-03
4.2577903E-03
0.0000000E+00
1.4933232E-03
3.0017417E-03
4.2334501E-03
0.0000000E+00
1.5365285E-03
3.0446384E-03
4.4091424E-03
0.0000000E+00
1.5329300E-03
3.0664177E-03
4.3937198E-03
0.0000000E+00
1.5274021E-03
3.0742094E-03
4.3066710E-03
0.0000000E+00
1.5692494E-03
3.1052278E-03
4.3211963E-03
0.0000000E+00
1.5996020E-03
3.2227652E-03
4.5425478E-03
0.0000000E+00
1.5650123E-03
3.1236229E-03
4.4022471E-03
0.0000000E+00
1.6041810E-03
3.1241151E-03
4.4103656E-03],[4,3,4])
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nuvw_bp01Data[4]; /* Expression: [0
4
8
12]
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nuvw_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nuvw_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain_i; /* Expression: 0.6
  * Referenced by: '<S13>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX1_tableData[12]; /* Expression: reshape([-8.13475E-05
-3.25752E-06
6.9363E-05
-8.00129E-05
-1.7093E-06
7.14001E-05
-6.46417E-05
-1.7093E-06
8.57128E-05
-7.85432E-05
-1.19372E-08
7.37459E-05],[3,4])
  * Referenced by: '<S27>/NdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX1_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S27>/NdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX1_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S27>/NdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX2_tableData[12]; /* Expression: reshape([6.2278E-05
-3.5277E-06
-7.1028E-05
5.9473E-05
-6.2352E-06
-7.5067E-05
3.9525E-05
-6.2352E-06
-9.4282E-05
5.5892E-05
-1.0640E-05
-8.2654E-05],[3,4])
  * Referenced by: '<S27>/NdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX2_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S27>/NdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX2_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S27>/NdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX3_tableData[12]; /* Expression: reshape([8.96891E-05
3.65995E-06
-8.07998E-05
9.13096E-05
6.34009E-06
-7.59117E-05
0.000100356
6.34009E-06
-4.56822E-05
9.40576E-05
1.06795E-05
-6.79415E-05],[3,4])
  * Referenced by: '<S27>/NdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX3_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S27>/NdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX3_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S27>/NdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX4_tableData[12]; /* Expression: reshape([-7.16232E-05
3.25314E-06
8.32589E-05
-7.3213E-05
1.68586E-06
8.13825E-05
-8.66615E-05
1.68586E-06
6.54218E-05
-7.48528E-05
-6.7812E-08
7.92559E-05],[3,4])
  * Referenced by: '<S27>/NdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX4_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S27>/NdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T NdX4_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S27>/NdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain1_Gain_i; /* Expression: 1.5
  * Referenced by: '<S13>/Gain1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nr_tableData[4]; /* Expression: [-4.0344E-04
-8.1402E-04
-1.2116E-03
-1.6125E-03]
  * Referenced by: '<S13>/N'r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nr_bp01Data[4]; /* Expression: [0.03999989
0.079999993
0.11999963
0.15999956]
  * Referenced by: '<S13>/N'r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_o; /* Expression: 1
  * Referenced by: '<S13>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nrr_tableData[6]; /* Expression: [1.93E-01
6.44E-02
3.19E-02
2.11E-02
1.64E-02
1.34E-02
]
  * Referenced by: '<S13>/N'r|r|'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nrr_bp01Data[6]; /* Expression: [0.0001
0.0003
0.0006
0.0009
0.0012
0.0015
]
  * Referenced by: '<S13>/N'r|r|'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain3_Gain_d; /* Expression: 1
  * Referenced by: '<S13>/Gain3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nvr_tableData[5]; /* Expression: [0.0000E+00
-1.9921E-03
-9.2025E-03
-3.2154E-02
-1.3255E-01]
  * Referenced by: '<S13>/N'vr'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Nvr_bp01Data[5]; /* Expression: [0
0.051444
0.102888
0.205776
0.411552]
  * Referenced by: '<S13>/N'vr'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain_h; /* Expression: 0.5
  * Referenced by: '<S13>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Xqq_tableData[16]; /* Expression: [1.5581E-04
1.1369E-04
2.0348E-04
4.5268E-04
3.8456E-04
9.9241E-05
3.8998E-04
9.1300E-05
-3.1574E-04
-7.9139E-05
-9.0517E-04
-4.4764E-04
-5.9612E-04
-5.5873E-04
-5.9343E-04
-5.5869E-04
]
  * Referenced by: '<S16>/Xqq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Xqq_bp01Data[16]; /* Expression: [-0.02
-0.015
-0.012958963
-0.009719222
-0.006479482
-0.003239741
-0.00161987
-0.000647948
0.000647948
0.00161987
0.003239741
0.006479482
0.009719222
0.012958963
0.015
0.02
]
  * Referenced by: '<S16>/Xqq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_UpperSat_i; /* Expression: 30
  * Referenced by: '<S16>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_LowerSat_e; /* Expression: -30
  * Referenced by: '<S16>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_UpperSat_f; /* Expression: -1.543332
  * Referenced by: '<S16>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_LowerSat_i; /* Expression: -5.14444
  * Referenced by: '<S16>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwV_tableData[21]; /* Expression: reshape([8.5556500E-04
9.0045500E-04
9.7379500E-04
1.0292250E-03
1.0286950E-03
9.7963500E-04
1.0147450E-03
9.0637500E-04
9.3710500E-04
1.0133950E-03
1.0723650E-03
1.0693650E-03
1.0284650E-03
1.1084650E-03
9.8653120E-04
9.9350120E-04
1.0534412E-03
1.1098412E-03
1.1115412E-03
1.0836412E-03
1.1582412E-03],[7,3])
  * Referenced by: '<S16>/X'uvwV'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwV_bp01Data[7]; /* Expression: [-12
-8
-4
0
4
8
12]
  * Referenced by: '<S16>/X'uvwV'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwV_bp02Data[3]; /* Expression: [-5.1444
-3.08664
-1.54332]
  * Referenced by: '<S16>/X'uvwV'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_UpperSat; /* Expression: -1.543332
  * Referenced by: '<S16>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_LowerSat; /* Expression: -5.14444
  * Referenced by: '<S16>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat_b; /* Expression: -13.8724
  * Referenced by: '<S16>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat_f; /* Expression: -35.0624
  * Referenced by: '<S16>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwH_tableData[48]; /* Expression: reshape([0.0000000E+00
8.7490400E-05
-4.2970032E-04
-8.6882993E-04
0.0000000E+00
9.2255510E-05
-3.6462757E-04
-8.6516720E-04
0.0000000E+00
-8.0508235E-05
-3.3610820E-04
-9.1603355E-04
0.0000000E+00
-9.0915847E-05
-3.9252667E-04
-9.2068441E-04
0.0000000E+00
-1.0407599E-04
-3.8836462E-04
-9.1865822E-04
0.0000000E+00
-8.4723950E-05
-3.5324770E-04
-9.7126434E-04
0.0000000E+00
-9.3766627E-05
-4.1342843E-04
-9.4161914E-04
0.0000000E+00
-1.0916277E-04
-4.0683220E-04
-9.6707684E-04
0.0000000E+00
-8.8664811E-05
-3.7605406E-04
-9.4194453E-04
0.0000000E+00
-9.2876985E-05
-4.0365964E-04
-9.3239814E-04
0.0000000E+00
-1.1414747E-04
-4.4323139E-04
-1.0049645E-03
0.0000000E+00
-9.4615234E-05
-4.9251136E-04
-9.8471513E-04],[4,3,4])
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwH_bp01Data[4]; /* Expression: [0
4
8
12]
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwH_bp02Data[3]; /* Expression: [-5.1444
-3.08664
-1.54332]
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XuvwH_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain_Gain_g; /* Expression: -1
  * Referenced by: '<S59>/Gain'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_UpperSat_d; /* Expression: -1.543332
  * Referenced by: '<S59>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation6_LowerSat_io; /* Expression: -5.14444
  * Referenced by: '<S59>/Saturation6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX1_tableData[28]; /* Expression: reshape([3.2151E-04
1.4055E-04
2.3723E-05
-2.9685E-05
2.3777E-05
1.3375E-04
3.3722E-04
1.6076E-04
7.0275E-05
1.1862E-05
-1.4843E-05
1.1889E-05
6.6875E-05
1.6861E-04
1.6698E-04
6.8790E-05
1.2322E-05
-1.4312E-05
1.2274E-05
6.7265E-05
1.7083E-04
3.4224E-04
1.3333E-04
2.5937E-05
-6.5668E-05
2.5937E-05
1.3102E-04
3.4214E-04
],[7,4])
  * Referenced by: '<S59>/XudX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX1_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S59>/XudX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX1_bp02Data[4]; /* Expression: [-7.716666
-5.144444
-3.0866664
-1.5433332
]
  * Referenced by: '<S59>/XudX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain4_Gain_e; /* Expression: 1
  * Referenced by: '<S59>/Gain4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX2_tableData[28]; /* Expression: reshape([2.9233E-04
1.3189E-04
2.3224E-05
-2.9022E-05
1.9675E-05
1.4726E-04
3.7676E-04
1.4617E-04
6.5945E-05
1.1612E-05
-1.4511E-05
9.8375E-06
7.3630E-05
1.8838E-04
1.7319E-04
6.7285E-05
1.2060E-05
-2.5958E-05
1.0337E-05
7.6660E-05
1.8963E-04
3.4748E-04
1.3335E-04
2.2395E-05
-2.6403E-05
2.2395E-05
1.5181E-04
3.8598E-04
],[7,4])
  * Referenced by: '<S59>/XudX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX2_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S59>/XudX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX2_bp02Data[4]; /* Expression: [-7.716666
-5.144444
-3.0866664
-1.5433332
]
  * Referenced by: '<S59>/XudX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain6_Gain_c; /* Expression: 1
  * Referenced by: '<S59>/Gain6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX3_tableData[28]; /* Expression: reshape([3.5642E-04
1.5674E-04
2.5449E-05
-2.9060E-05
2.6726E-05
1.6225E-04
3.1115E-04
1.7821E-04
7.8370E-05
1.2725E-05
-1.4530E-05
1.3363E-05
8.1125E-05
1.5558E-04
1.9053E-04
8.0600E-05
1.2911E-05
-1.3998E-05
1.3672E-05
7.4645E-05
1.6290E-04
3.8447E-04
1.4526E-04
2.7824E-05
-2.6434E-05
2.7824E-05
1.5039E-04
3.2499E-04
],[7,4])
  * Referenced by: '<S59>/XudX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX3_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S59>/XudX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX3_bp02Data[4]; /* Expression: [-7.716666
-5.144444
-3.0866664
-1.5433332
]
  * Referenced by: '<S59>/XudX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain5_Gain_m; /* Expression: 1
  * Referenced by: '<S59>/Gain5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX4_tableData[28]; /* Expression: reshape([3.4525E-04
1.3840E-04
2.4668E-05
-2.9702E-05
2.4205E-05
1.2737E-04
3.2790E-04
1.7263E-04
6.9200E-05
1.2334E-05
-1.4851E-05
1.2103E-05
6.3685E-05
1.6395E-04
1.7298E-04
6.9435E-05
1.2696E-05
-1.4315E-05
1.2608E-05
6.9175E-05
1.6779E-04
3.3803E-04
1.5513E-04
2.6677E-05
-2.7052E-05
2.6677E-05
1.3644E-04
3.3780E-04
],[7,4])
  * Referenced by: '<S59>/XudX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX4_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S59>/XudX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudX4_bp02Data[4]; /* Expression: [-7.716666
-5.144444
-3.0866664
-1.5433332
]
  * Referenced by: '<S59>/XudX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain7_Gain_b; /* Expression: 1
  * Referenced by: '<S59>/Gain7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudXB_tableData[21]; /* Expression: reshape([6.9060E-04
3.9256E-04
1.5651E-04
0.0000E+00
1.1449E-04
4.2412E-04
5.7370E-04
6.4542E-04
3.9138E-04
1.5593E-04
0.0000E+00
1.1381E-04
4.1205E-04
5.6813E-04
6.5675E-04
3.9410E-04
1.1271E-04
0.0000E+00
1.1271E-04
4.2649E-04
5.7604E-04
],[7,3])
  * Referenced by: '<S59>/XudXB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudXB_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30] 
  * Referenced by: '<S59>/XudXB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T XudXB_bp02Data[3]; /* Expression: [-5.14444 -3.08666664 -1.54332]
  * Referenced by: '<S59>/XudXB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yrr_tableData[16]; /* Expression: [3.6478E-03
3.8686E-03
3.4313E-03
4.0790E-03
3.9500E-03
3.6018E-03
3.6796E-03
3.5502E-03
3.4310E-03
3.4872E-03
4.2239E-03
4.0934E-03
3.0314E-03
2.5726E-03
2.9188E-03
2.7740E-03
]
  * Referenced by: '<S17>/Y|r|r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yrr_bp01Data[16]; /* Expression: [-0.02
-0.015
-0.012958963
-0.009719222
-0.006479482
-0.003239741
-0.00161987
-0.000647948
0.000647948
0.00161987
0.003239741
0.006479482
0.009719222
0.012958963
0.015
0.02
]
  * Referenced by: '<S17>/Y|r|r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yur_tableData[4]; /* Expression: [-5.2094E-04
-1.0594E-03
-1.5649E-03
-2.0981E-03]
  * Referenced by: '<S17>/Y'ur'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yur_bp01Data[4]; /* Expression: [0.03999989
0.079999993
0.11999963
0.15999956]
  * Referenced by: '<S17>/Y'ur'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yvr_tableData[12]; /* Expression: [-2.9784E-01
-2.6725E-01
-2.3292E-01
-2.0077E-01
-1.1489E-01
-7.6673E-03
-7.5516E-03
-1.1617E-01
-2.0077E-01
-2.9128E-01
-3.5974E-01
-4.7839E-01]
  * Referenced by: '<S17>/Y'|v|r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yvr_bp01Data[12]; /* Expression: [-0.0015
-0.0012
-0.0009
-0.0006
-0.0003
-0.0001
0.0001
0.0003
0.0006
0.0009
0.0012
0.0015]
  * Referenced by: '<S17>/Y'|v|r'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat_e; /* Expression: -13.8724
  * Referenced by: '<S17>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat_ou; /* Expression: -35.0624
  * Referenced by: '<S17>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yuvw_tableData[48]; /* Expression: reshape([0.0000000E+00
-5.0280621E-03
-9.4175348E-03
-1.4397458E-02
0.0000000E+00
-5.0037454E-03
-9.1645405E-03
-1.4507402E-02
0.0000000E+00
-4.2819107E-03
-9.0361786E-03
-1.4507235E-02
0.0000000E+00
-4.7723270E-03
-9.7378407E-03
-1.5377541E-02
0.0000000E+00
-4.7276301E-03
-9.6949815E-03
-1.5393721E-02
0.0000000E+00
-4.5359209E-03
-9.4966039E-03
-1.6947859E-02
0.0000000E+00
-5.1295007E-03
-1.0575377E-02
-1.6672924E-02
0.0000000E+00
-4.9811404E-03
-1.0209461E-02
-1.6298327E-02
0.0000000E+00
-4.7780219E-03
-1.0008968E-02
-1.6115181E-02
0.0000000E+00
-5.7252015E-03
-1.1973447E-02
-1.9152812E-02
0.0000000E+00
-5.2128737E-03
-1.0845978E-02
-1.7281669E-02
0.0000000E+00
-4.9979037E-03
-1.0845685E-02
-1.6944141E-02],[4,3,4])
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yuvw_bp01Data[4]; /* Expression: [0
4
8
12]
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yuvw_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Yuvw_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Gain2_Gain_l; /* Expression: 2
  * Referenced by: '<S17>/Gain2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX1_tableData[12]; /* Expression: reshape([-1.8282E-04
-6.0037E-06
1.6496E-04
-1.7978E-04
-2.4314E-06
1.6969E-04
-1.4480E-04
-2.4314E-06
2.0267E-04
-1.7641E-04
1.4850E-06
1.7514E-04],[3,4])
  * Referenced by: '<S61>/YdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX1_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S61>/YdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX1_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S61>/YdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX2_tableData[12]; /* Expression: reshape([1.4857E-04
-6.6611E-06
-1.5932E-04
1.4200E-04
-1.2968E-05
-1.6860E-04
9.4982E-05
-1.2968E-05
-2.1344E-04
1.3366E-04
-2.3176E-05
-1.8599E-04],[3,4])
  * Referenced by: '<S61>/YdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX2_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S61>/YdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX2_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S61>/YdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX3_tableData[12]; /* Expression: reshape([2.0207E-04
6.9701E-06
-1.9141E-04
2.0588E-04
1.3213E-05
-1.8007E-04
2.2753E-04
1.3213E-05
-1.0937E-04
2.1222E-04
2.3270E-05
-1.6161E-04],[3,4])
  * Referenced by: '<S61>/YdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX3_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S61>/YdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX3_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S61>/YdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX4_tableData[12]; /* Expression: reshape([-1.7022E-04
5.9932E-06
1.8722E-04
-1.7390E-04
2.3770E-06
1.8293E-04
-2.0489E-04
2.3770E-06
1.4658E-04
-1.7771E-04
-1.6689E-06
1.7805E-04],[3,4])
  * Referenced by: '<S61>/YdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX4_bp01Data[3]; /* Expression: [-10 0 10]
  * Referenced by: '<S61>/YdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T YdX4_bp02Data[4]; /* Expression: [-36.4062987
-18.4062987
-15.4062987
-13.9062987]
  * Referenced by: '<S61>/YdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation3_UpperSat_b; /* Expression: 0.02
  * Referenced by: '<S18>/Saturation3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation3_LowerSat_k; /* Expression: -0.02
  * Referenced by: '<S18>/Saturation3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zqq_tableData[5]; /* Expression: [-1.5611E-03
-1.0379E-04
3.9238E-05
1.1475E-04
1.3579E-04
]
  * Referenced by: '<S18>/Zqq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zqq_bp01Data[5]; /* Expression: [0.000127901
0.000383704
0.000639507
0.001279013
0.002558026
]
  * Referenced by: '<S18>/Zqq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation5_UpperSat_i; /* Expression: -1.5433E+00
  * Referenced by: '<S18>/Saturation5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation5_LowerSat_d; /* Expression: -5.14444
  * Referenced by: '<S18>/Saturation5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_UpperSat_l; /* Expression: 0.04
  * Referenced by: '<S18>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation1_LowerSat_c; /* Expression: -0.04
  * Referenced by: '<S18>/Saturation1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuq_tableData[12]; /* Expression: [-9.8908E-03
-9.0784E-03
-8.9566E-03
-1.0733E-02
-1.4141E-02
-2.4189E-02
-6.5605E-03
-7.1594E-03
-7.6366E-03
-7.9008E-03
-6.1794E-03
-6.1029E-03
]
  * Referenced by: '<S18>/Zuq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuq_bp01Data[12]; /* Expression: [-0.04
-0.03
-0.02
-0.01
-0.005
-0.002
0.002
0.005
0.01
0.02
0.03
0.04
]
  * Referenced by: '<S18>/Zuq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_UpperSat_o; /* Expression: 0.0015
  * Referenced by: '<S18>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation2_LowerSat_d; /* Expression: -0.0015
  * Referenced by: '<S18>/Saturation2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zwq_tableData[12]; /* Expression: [-2.9784E-01
-2.6725E-01
-2.3292E-01
-2.0077E-01
-1.1489E-01
-7.6673E-03
-7.5516E-03
-1.1617E-01
-2.0077E-01
-2.9128E-01
-3.5974E-01
-4.7839E-01]
  * Referenced by: '<S18>/Zwq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zwq_bp01Data[12]; /* Expression: [-0.0015
-0.0012
-0.0009
-0.0006
-0.0003
-0.0001
0.0001
0.0003
0.0006
0.0009
0.0012
0.0015]
  * Referenced by: '<S18>/Zwq'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_UpperSat_p; /* Expression: -13.8724
  * Referenced by: '<S18>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Saturation4_LowerSat_b; /* Expression: -35.0624
  * Referenced by: '<S18>/Saturation4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwa_tableData[84]; /* Expression: reshape([-3.82587E-03
-2.42543E-03
-1.05453E-03
1.94202E-04
1.48991E-03
3.04047E-03
4.14104E-03
-3.76348E-03
-2.38508E-03
-9.82619E-04
1.94202E-04
1.47560E-03
3.02863E-03
4.06663E-03
-3.75964E-03
-2.29001E-03
-8.34074E-04
1.94202E-04
1.38956E-03
2.91153E-03
4.15251E-03
-3.11218E-03
-1.80502E-03
-4.97855E-04
8.09305E-04
2.11647E-03
3.42363E-03
4.73079E-03
-2.62573E-03
-1.48072E-03
-3.35708E-04
8.09305E-04
1.95432E-03
3.09933E-03
4.24434E-03
-2.06413E-03
-1.10632E-03
-1.48507E-04
8.09305E-04
1.76712E-03
2.72493E-03
3.68274E-03
-3.09997E-03
-1.76300E-03
-4.26025E-04
9.10947E-04
2.24792E-03
3.58489E-03
4.92186E-03
-2.49055E-03
-1.35672E-03
-2.22886E-04
9.10947E-04
2.04478E-03
3.17861E-03
4.31245E-03
-2.64104E-03
-1.45704E-03
-2.73048E-04
9.10947E-04
2.09494E-03
3.27894E-03
4.46293E-03
-0.003059752
-0.001711935
-0.000364117
0.0009837
0.002331518
0.003679335
0.005027153
-0.002351082
-0.0012256
-0.000100118
0.0009837
0.002109182
0.003234664
0.004360146
-0.001725739
-0.000822593
8.05539E-05
0.0009837
0.001886847
0.002789993
0.00369314],[7,3,4])
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwa_bp01Data[7]; /* Expression: [-12
-8
-4
0
4
8
12]
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwa_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwa_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwb_tableData[48]; /* Expression: reshape([0.0000000E+00
-5.9986916E-04
-2.7503348E-03
-5.0777589E-03
0.0000000E+00
-6.0654884E-04
-2.4512564E-03
-5.2464901E-03
0.0000000E+00
-7.6137528E-04
-2.4084463E-03
-5.2118678E-03
0.0000000E+00
-8.2427914E-04
-2.5250249E-03
-5.3103563E-03
0.0000000E+00
-8.1036019E-04
-2.5315266E-03
-5.5141459E-03
0.0000000E+00
-7.9799041E-04
-2.5595242E-03
-5.2319004E-03
0.0000000E+00
-8.6989011E-04
-2.5865820E-03
-5.6151595E-03
0.0000000E+00
-8.4361582E-04
-2.6124115E-03
-5.7143353E-03
0.0000000E+00
-8.2567611E-04
-2.6088331E-03
-5.6150660E-03
0.0000000E+00
-9.1003224E-04
-2.7683191E-03
-6.0189061E-03
0.0000000E+00
-8.4211433E-04
-2.5899187E-03
-5.7497784E-03
0.0000000E+00
-8.2014014E-04
-2.4092466E-03
-5.6643347E-03],[4,3,4])
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwb_bp01Data[4]; /* Expression: [0
4
8
12]
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwb_bp02Data[3]; /* Expression: [-5.1444E+00
-3.0866E+00
-1.5433E+00
]
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T Zuvwb_bp03Data[4]; /* Expression: [-35.0624 -18.3724 -15.3724 -13.8724
]
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZuqProp_tableData[36]; /* Expression: reshape([1.3913E-04
1.0452E-04
6.9900E-05
3.5283E-05
6.6700E-07
-3.3949E-05
-6.8566E-05
-1.0318E-04
-1.3780E-04
2.8914E-04
2.1702E-04
1.4490E-04
7.2785E-05
6.6700E-07
-7.1451E-05
-1.4357E-04
-2.1569E-04
-2.8780E-04
1.1606E-04
8.7208E-05
5.8361E-05
2.9514E-05
6.6700E-07
-2.8180E-05
-5.7027E-05
-8.5874E-05
-1.1472E-04
1.1606E-04
8.7208E-05
5.8361E-05
2.9514E-05
6.6700E-07
-2.8180E-05
-5.7027E-05
-8.5874E-05
-1.1472E-04],[9,4])
  * Referenced by: '<S18>/Z'uq Prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZuqProp_bp01Data[9]; /* Expression: [-2.0E-01
-1.5E-01
-1.0E-01
-5.0E-02
0.0E+00
5.0E-02
1.0E-01
1.5E-01
2.0E-01
]
  * Referenced by: '<S18>/Z'uq Prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZuqProp_bp02Data[4]; /* Expression: [-7.71666 -5.14444 -3.086664 -1.543332]
  * Referenced by: '<S18>/Z'uq Prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q6_tableData[21]; /* Expression: reshape([-0.001383757
-0.000911
-0.000438243
3.45135E-05
0.00050727
0.000980027
0.001452784
-0.001383757
-0.000911
-0.000438243
3.45135E-05
0.00050727
0.000980027
0.001452784
-0.001353354
-0.000887631
-0.000421908
4.38143E-05
0.000509537
0.00097526
0.001440982],[7,3])
  * Referenced by: '<S63>/ZudX1 q+6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q6_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S63>/ZudX1 q+6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q6_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S63>/ZudX1 q+6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q7_tableData[21]; /* Expression: reshape([-0.001358511
-0.00091651
-0.000474508
-3.25062E-05
0.000409495
0.000851497
0.001293499
-0.001303275
-0.00086798
-0.000432686
2.60877E-06
0.000437903
0.000873198
0.001308493
-0.001263287
-0.000836064
-0.00040884
1.83841E-05
0.000445608
0.000872832
0.001300056],[7,3])
  * Referenced by: '<S63>/ZudX1 q+7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q7_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S63>/ZudX1 q+7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q7_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S63>/ZudX1 q+7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q8_tableData[21]; /* Expression: reshape([0.001309084
0.000864124
0.000419163
-2.5798E-05
-0.000470759
-0.000915719
-0.00136068
0.001321953
0.000882434
0.000442915
3.39516E-06
-0.000436124
-0.000875644
-0.001315163
0.001313186
0.000881448
0.000449709
1.79712E-05
-0.000413767
-0.000845505
-0.001277243],[7,3])
  * Referenced by: '<S63>/ZudX1 q+8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q8_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S63>/ZudX1 q+8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q8_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S63>/ZudX1 q+8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q9_tableData[21]; /* Expression: reshape([0.001464336
0.000977857
0.000491377
4.89775E-06
-0.000481582
-0.000968061
-0.00145454
0.001455937
0.00098192
0.000507903
3.38863E-05
-0.00044013
-0.000914147
-0.001388164
0.001460604
0.00098818
0.000515756
4.33325E-05
-0.000429091
-0.000901515
-0.001373939],[7,3])
  * Referenced by: '<S63>/ZudX1 q+9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q9_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S63>/ZudX1 q+9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q9_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S63>/ZudX1 q+9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q10_tableData[21]; /* Expression: reshape([-0.003226964
-0.002116041
-0.001005119
0.000105803
0.001216725
0.002327647
0.003438569
-0.003036597
-0.001876165
-0.000715732
0.0004447
0.001605132
0.002765565
0.003925997
-0.003676642
-0.002490275
-0.001303908
-0.000117541
0.001068826
0.002255193
0.00344156],[7,3])
  * Referenced by: '<S63>/ZudX1 q+10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q10_bp01Data[7]; /* Expression: [-30 -20 -10 0 10 20 30]
  * Referenced by: '<S63>/ZudX1 q+10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   real_T ZudX1q10_bp02Data[3]; /* Expression: [-35.0624 -15.3724 -13.8724]
  * Referenced by: '<S63>/ZudX1 q+10'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Kuvw_maxIndex[3]; /* Computed Parameter: Kuvw_maxIndex
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Kuvw_dimSizes[3]; /* Computed Parameter: Kuvw_dimSizes
  * Referenced by: '<S11>/K'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX1_maxIndex[3]; /* Computed Parameter: KdX1_maxIndex
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX1_dimSizes[3]; /* Computed Parameter: KdX1_dimSizes
  * Referenced by: '<S22>/KdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX2_maxIndex[3]; /* Computed Parameter: KdX2_maxIndex
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX2_dimSizes[3]; /* Computed Parameter: KdX2_dimSizes
  * Referenced by: '<S22>/KdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX3_maxIndex[3]; /* Computed Parameter: KdX3_maxIndex
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX3_dimSizes[3]; /* Computed Parameter: KdX3_dimSizes
  * Referenced by: '<S22>/KdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX4_maxIndex[3]; /* Computed Parameter: KdX4_maxIndex
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T KdX4_dimSizes[3]; /* Computed Parameter: KdX4_dimSizes
  * Referenced by: '<S22>/KdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ThrustDeduction25m1_maxIndex[2]; /* Computed Parameter: ThrustDeduction25m1_maxIndex
  * Referenced by: '<S14>/Thrust Deduction, 25m1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T M_uvwa_maxIndex[3]; /* Computed Parameter: M_uvwa_maxIndex
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T M_uvwa_dimSizes[3]; /* Computed Parameter: M_uvwa_dimSizes
  * Referenced by: '<S12>/M_uvwa'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q1_maxIndex[2]; /* Computed Parameter: ZudX1q1_maxIndex
  * Referenced by: '<S24>/ZudX1 q+1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q2_maxIndex[2]; /* Computed Parameter: ZudX1q2_maxIndex
  * Referenced by: '<S24>/ZudX1 q+2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q3_maxIndex[2]; /* Computed Parameter: ZudX1q3_maxIndex
  * Referenced by: '<S24>/ZudX1 q+3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q4_maxIndex[2]; /* Computed Parameter: ZudX1q4_maxIndex
  * Referenced by: '<S24>/ZudX1 q+4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q5_maxIndex[2]; /* Computed Parameter: ZudX1q5_maxIndex
  * Referenced by: '<S24>/ZudX1 q+5'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Nuvw_maxIndex[3]; /* Computed Parameter: Nuvw_maxIndex
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Nuvw_dimSizes[3]; /* Computed Parameter: Nuvw_dimSizes
  * Referenced by: '<S13>/N'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T NdX1_maxIndex[2]; /* Computed Parameter: NdX1_maxIndex
  * Referenced by: '<S27>/NdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T NdX2_maxIndex[2]; /* Computed Parameter: NdX2_maxIndex
  * Referenced by: '<S27>/NdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T NdX3_maxIndex[2]; /* Computed Parameter: NdX3_maxIndex
  * Referenced by: '<S27>/NdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T NdX4_maxIndex[2]; /* Computed Parameter: NdX4_maxIndex
  * Referenced by: '<S27>/NdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XuvwV_maxIndex[2]; /* Computed Parameter: XuvwV_maxIndex
  * Referenced by: '<S16>/X'uvwV'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XuvwH_maxIndex[3]; /* Computed Parameter: XuvwH_maxIndex
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XuvwH_dimSizes[3]; /* Computed Parameter: XuvwH_dimSizes
  * Referenced by: '<S16>/X'uvwH'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XudX1_maxIndex[2]; /* Computed Parameter: XudX1_maxIndex
  * Referenced by: '<S59>/XudX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XudX2_maxIndex[2]; /* Computed Parameter: XudX2_maxIndex
  * Referenced by: '<S59>/XudX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XudX3_maxIndex[2]; /* Computed Parameter: XudX3_maxIndex
  * Referenced by: '<S59>/XudX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XudX4_maxIndex[2]; /* Computed Parameter: XudX4_maxIndex
  * Referenced by: '<S59>/XudX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T XudXB_maxIndex[2]; /* Computed Parameter: XudXB_maxIndex
  * Referenced by: '<S59>/XudXB'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Yuvw_maxIndex[3]; /* Computed Parameter: Yuvw_maxIndex
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Yuvw_dimSizes[3]; /* Computed Parameter: Yuvw_dimSizes
  * Referenced by: '<S17>/Y'uvw'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T YdX1_maxIndex[2]; /* Computed Parameter: YdX1_maxIndex
  * Referenced by: '<S61>/YdX1'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T YdX2_maxIndex[2]; /* Computed Parameter: YdX2_maxIndex
  * Referenced by: '<S61>/YdX2'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T YdX3_maxIndex[2]; /* Computed Parameter: YdX3_maxIndex
  * Referenced by: '<S61>/YdX3'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T YdX4_maxIndex[2]; /* Computed Parameter: YdX4_maxIndex
  * Referenced by: '<S61>/YdX4'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Zuvwa_maxIndex[3]; /* Computed Parameter: Zuvwa_maxIndex
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Zuvwa_dimSizes[3]; /* Computed Parameter: Zuvwa_dimSizes
  * Referenced by: '<S18>/Z'uvw(a)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Zuvwb_maxIndex[3]; /* Computed Parameter: Zuvwb_maxIndex
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T Zuvwb_dimSizes[3]; /* Computed Parameter: Zuvwb_dimSizes
  * Referenced by: '<S18>/Z'uvw(b)'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZuqProp_maxIndex[2]; /* Computed Parameter: ZuqProp_maxIndex
  * Referenced by: '<S18>/Z'uq Prop'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q6_maxIndex[2]; /* Computed Parameter: ZudX1q6_maxIndex
  * Referenced by: '<S63>/ZudX1 q+6'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q7_maxIndex[2]; /* Computed Parameter: ZudX1q7_maxIndex
  * Referenced by: '<S63>/ZudX1 q+7'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q8_maxIndex[2]; /* Computed Parameter: ZudX1q8_maxIndex
  * Referenced by: '<S63>/ZudX1 q+8'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q9_maxIndex[2]; /* Computed Parameter: ZudX1q9_maxIndex
  * Referenced by: '<S63>/ZudX1 q+9'
   */

                        
                        
                        


                    






                    
                    


                        



                            
                            
                                   uint32_T ZudX1q10_maxIndex[2]; /* Computed Parameter: ZudX1q10_maxIndex
  * Referenced by: '<S63>/ZudX1 q+10'
   */

                        
                        
                        


                    





                };

        


            /* Real-time Model Data Structure */
            
    struct tag_RTM_Model_6DOF_T {
                    const char_T *errorStatus;
                    RTWLogInfo *rtwLogInfo;
        RTWSolverInfo solverInfo;
        X_Model_6DOF_T *contStates;
                    int_T *periodicContStateIndices;
                    real_T *periodicContStateRanges;
                    real_T *derivs;
                    boolean_T *contStateDisabled;
                    boolean_T zCCacheNeedsReset;
                    boolean_T derivCacheNeedsReset;
                    boolean_T CTOutputIncnstWithState;
                    real_T odeY[12];
                    real_T odeF[3][12];
                    ODE3_IntgData intgData;

                        /*
        * Sizes:
                * The following substructure contains sizes information
        * for many of the model attributes such as inputs, outputs,
        * dwork, sample times, etc.
         */
 
    struct  {
                    int_T numContStates;
                    int_T numPeriodicContStates;
                    int_T numSampTimes;
            


    } Sizes;

                        /*
        * Timing:
                * The following substructure contains information regarding
        * the timing information for the model.
         */
 
    struct  {
                    uint32_T clockTick0;
                    uint32_T clockTickH0;
                    time_T stepSize0;
                    uint32_T clockTick1;
                    uint32_T clockTickH1;
                    time_T tFinal;
                    SimTimeStep simTimeStep;
        boolean_T stopRequestedFlag;
                    time_T *t;
                    time_T tArray[2];
            


    } Timing;



    };





    

    

    
            /* Block parameters (default storage) */
            

            extern                 P_Model_6DOF_T Model_6DOF_P;




            /* Block signals (default storage) */
            

            extern                 B_Model_6DOF_T Model_6DOF_B;




            /* Continuous states (default storage) */
            

            extern                 X_Model_6DOF_T Model_6DOF_X;




                /* Block states (default storage) */
            

            extern                 DW_Model_6DOF_T Model_6DOF_DW;





    
            /* Model entry point functions */
                                        extern void Model_6DOF_initialize(void);
                


                                                            extern void Model_6DOF_step(void);
                        

                                        extern void Model_6DOF_terminate(void);
                


    

    
                    /* Real-time Model object */

                    

            extern                         RT_MODEL_Model_6DOF_T *const Model_6DOF_M;






    

    

    

            
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
            * '<Root>' : 'Model_6DOF'
                * '<S1>'   : 'Model_6DOF/Controller'
                * '<S2>'   : 'Model_6DOF/Environment'
                * '<S3>'   : 'Model_6DOF/HDM'
                * '<S4>'   : 'Model_6DOF/Controller/pf_controller'
                * '<S5>'   : 'Model_6DOF/Controller/pf_controller1'
                * '<S6>'   : 'Model_6DOF/HDM/HDM B3'
                * '<S7>'   : 'Model_6DOF/HDM/Integration and Coord. Transfrom'
                * '<S8>'   : 'Model_6DOF/HDM/actuator saturation'
                * '<S9>'   : 'Model_6DOF/HDM/HDM B3/Effective Veloicity Calclation'
                * '<S10>'  : 'Model_6DOF/HDM/HDM B3/Effective dX Calculation'
                * '<S11>'  : 'Model_6DOF/HDM/HDM B3/K'
                * '<S12>'  : 'Model_6DOF/HDM/HDM B3/M'
                * '<S13>'  : 'Model_6DOF/HDM/HDM B3/N'
                * '<S14>'  : 'Model_6DOF/HDM/HDM B3/Thrust & Torque'
                * '<S15>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic'
                * '<S16>'  : 'Model_6DOF/HDM/HDM B3/X'
                * '<S17>'  : 'Model_6DOF/HDM/HDM B3/Y'
                * '<S18>'  : 'Model_6DOF/HDM/HDM B3/Z'
                * '<S19>'  : 'Model_6DOF/HDM/HDM B3/Effective Veloicity Calclation/MATLAB Function'
                * '<S20>'  : 'Model_6DOF/HDM/HDM B3/Effective Veloicity Calclation/MATLAB Function1'
                * '<S21>'  : 'Model_6DOF/HDM/HDM B3/Effective Veloicity Calclation/MATLAB Function2'
                * '<S22>'  : 'Model_6DOF/HDM/HDM B3/K/KdXi'
                * '<S23>'  : 'Model_6DOF/HDM/HDM B3/K/Mx'
                * '<S24>'  : 'Model_6DOF/HDM/HDM B3/M/Mdxi'
                * '<S25>'  : 'Model_6DOF/HDM/HDM B3/M/My'
                * '<S26>'  : 'Model_6DOF/HDM/HDM B3/N/Mz'
                * '<S27>'  : 'Model_6DOF/HDM/HDM B3/N/NdXi'
                * '<S28>'  : 'Model_6DOF/HDM/HDM B3/Thrust & Torque/Tprop'
                * '<S29>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/MATLAB Function'
                * '<S30>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions'
                * '<S31>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments'
                * '<S32>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Local eff. Depth'
                * '<S33>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Sectional Position Vectors'
                * '<S34>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Sectional Wave Particle & Rigid Body Velocities'
                * '<S35>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Wave Properties'
                * '<S36>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Wave particle velocity at hull CG'
                * '<S37>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Wave particle velocity at the center of Appendages'
                * '<S38>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/Subsystem'
                * '<S39>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X1'
                * '<S40>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X2'
                * '<S41>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X3'
                * '<S42>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X4'
                * '<S43>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/XB'
                * '<S44>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/Subsystem/MATLAB Function1'
                * '<S45>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/Subsystem/MATLAB Function3'
                * '<S46>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/Subsystem/MATLAB Function4'
                * '<S47>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/Subsystem/MATLAB Function5'
                * '<S48>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X1/MATLAB Function1'
                * '<S49>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X1/MATLAB Function4'
                * '<S50>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X2/MATLAB Function1'
                * '<S51>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X2/MATLAB Function4'
                * '<S52>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X3/MATLAB Function1'
                * '<S53>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X3/MATLAB Function4'
                * '<S54>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X4/MATLAB Function1'
                * '<S55>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/X4/MATLAB Function4'
                * '<S56>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/XB/MATLAB Function1'
                * '<S57>'  : 'Model_6DOF/HDM/HDM B3/Wave, Virtual Mass and Hydrostatic/Wave Particle Motions/Hydrostatic Forces and Moments/XB/MATLAB Function4'
                * '<S58>'  : 'Model_6DOF/HDM/HDM B3/X/Fx'
                * '<S59>'  : 'Model_6DOF/HDM/HDM B3/X/X'dXi'
                * '<S60>'  : 'Model_6DOF/HDM/HDM B3/Y/Fy'
                * '<S61>'  : 'Model_6DOF/HDM/HDM B3/Y/YdXi'
                * '<S62>'  : 'Model_6DOF/HDM/HDM B3/Z/Fz'
                * '<S63>'  : 'Model_6DOF/HDM/HDM B3/Z/ZdXi'
                * '<S64>'  : 'Model_6DOF/HDM/Integration and Coord. Transfrom/Coordinate Transform'
                * '<S65>'  : 'Model_6DOF/HDM/Integration and Coord. Transfrom/Rigid Body Motion'
                * '<S66>'  : 'Model_6DOF/HDM/Integration and Coord. Transfrom/Coordinate Transform/MATLAB Function2'
                * '<S67>'  : 'Model_6DOF/HDM/Integration and Coord. Transfrom/Rigid Body Motion/MATLAB Function2'
                * '<S68>'  : 'Model_6DOF/HDM/actuator saturation/ '
                * '<S69>'  : 'Model_6DOF/HDM/actuator saturation/   '
                * '<S70>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem1'
                * '<S71>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem2'
                * '<S72>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic'
                * '<S73>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic1'
                * '<S74>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic2'
                * '<S75>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic3'
                * '<S76>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic4'
                * '<S77>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic/Saturation Dynamic'
                * '<S78>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic1/Saturation Dynamic'
                * '<S79>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic2/Saturation Dynamic'
                * '<S80>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic3/Saturation Dynamic'
                * '<S81>'  : 'Model_6DOF/HDM/actuator saturation/ /Rate Limiter Dynamic4/Saturation Dynamic'
                * '<S82>'  : 'Model_6DOF/HDM/actuator saturation/   /Rate Limiter Dynamic'
                * '<S83>'  : 'Model_6DOF/HDM/actuator saturation/   /Rate Limiter Dynamic/Saturation Dynamic'
                * '<S84>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem1/Rate Limiter Dynamic'
                * '<S85>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem1/Rate Limiter Dynamic/Saturation Dynamic'
                * '<S86>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem2/Rate Limiter Dynamic1'
                * '<S87>'  : 'Model_6DOF/HDM/actuator saturation/Subsystem2/Rate Limiter Dynamic1/Saturation Dynamic'
    */


    

    #endif /* RTW_HEADER_Model_6DOF_h_ */
