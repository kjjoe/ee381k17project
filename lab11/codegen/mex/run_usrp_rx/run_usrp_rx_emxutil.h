/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx_emxutil.h
 *
 * Code generation for function 'run_usrp_rx_emxutil'
 *
 */

#ifndef RUN_USRP_RX_EMXUTIL_H
#define RUN_USRP_RX_EMXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "run_usrp_rx_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (run_usrp_rx_emxutil.h) */
