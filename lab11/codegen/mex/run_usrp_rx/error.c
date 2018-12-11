/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo d_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/coder/coder/+coder/+internal/error.m"/* pName */
};

/* Function Definitions */
void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
    "Coder:toolbox:OutOfTargetRangeTruncatedFloat",
    "Coder:toolbox:OutOfTargetRangeTruncatedFloat", 4, 6, 0.0, 6, 255.0);
}

/* End of code generation (error.c) */
