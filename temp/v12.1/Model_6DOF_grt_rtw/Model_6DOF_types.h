

    /*
* Model_6DOF_types.h
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


    #ifndef RTW_HEADER_Model_6DOF_types_h_
    #define RTW_HEADER_Model_6DOF_types_h_



    
#include "rtwtypes.h"
                /* Model Code Variants */
        





    

    

    

    

    

    

    

    

    
    
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T_Model_6DOF_T
#define typedef_emxArray_real_T_Model_6DOF_T
typedef struct emxArray_real_T emxArray_real_T_Model_6DOF_T;
#endif /* typedef_emxArray_real_T_Model_6DOF_T */


                            /* Parameters (default storage) */
                 typedef struct P_Model_6DOF_T_ P_Model_6DOF_T;
                /* Forward declaration for rtModel */
            typedef struct tag_RTM_Model_6DOF_T RT_MODEL_Model_6DOF_T;


    

    

    

    

    

    

    

    

    

    

    

    #endif /* RTW_HEADER_Model_6DOF_types_h_ */
