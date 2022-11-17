

    /*
* Model_6DOF_private.h
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


    #ifndef RTW_HEADER_Model_6DOF_private_h_
    #define RTW_HEADER_Model_6DOF_private_h_



                #include "rtwtypes.h"
            #include "builtin_typeid_types.h"
            #include "multiword_types.h"


#include "Model_6DOF.h"


    

    

    

                /* Private macros used by the generated code to access rtModel */
            

        #ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm) (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm) (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val) ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val) ((rtm)->Timing.t = (val))
#endif


    



    

    

    

    

    

    

    

    

    
            extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[], uint32_T maxIndex);

      extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);

      extern uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T *fraction);

      extern real_T intrp3d_l_pw(const uint32_T bpIndex[], const real_T frac[], const real_T table[], const uint32_T stride[]);

      extern uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex, uint32_T maxIndex);

              
                extern void Model_6DOF_MATLABFunction4(real_T rtu_time, const real_T rtu_Xearth[6], const real_T rtu_vert1[600], const real_T rtu_vert2[600], const real_T rtu_vert3[600], const real_T rtu_dA[200], real_T rtu_ntri, real_T rtu_A_wave, real_T rtu_k_wave, real_T rtu_w_wave, real_T rtu_rho, real_T rtu_g, real_T rtu_Zb, const real_T rtu_EAX[3], real_T rtu_dX, const real_T rtu_origin[3], const real_T rtu_xcg[3], B_MATLABFunction4_Model_6DOF_T *localB);
                

    /* private model entry point functions */
        extern void     Model_6DOF_derivatives(void);
    

    

    

    

    

    

    

    

    #endif /* RTW_HEADER_Model_6DOF_private_h_ */
