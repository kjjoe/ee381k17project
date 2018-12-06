/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_tx_mexutil.c
 *
 * Code generation for function 'run_usrp_tx_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "run_usrp_tx_mexutil.h"

/* Function Definitions */
void b_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
             emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "error", true, location);
}

void drawnow(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "drawnow", true, location);
}

const mxArray *sdruroot(const emlrtStack *sp, emlrtMCInfo *location)
{
  const mxArray *m26;
  return emlrtCallMATLABR2012b(sp, 1, &m26, 0, NULL, "sdruroot", true, location);
}

void setupsdru(const emlrtStack *sp, const mxArray *b, const mxArray *c,
               emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "setupsdru", true, location);
}

/* End of code generation (run_usrp_tx_mexutil.c) */
