/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_usrp_rx_api.c
 *
 * Code generation for function '_coder_run_usrp_rx_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "_coder_run_usrp_rx_api.h"
#include "run_usrp_rx_data.h"

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [156800]);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [156800])
{
  const mxArray *y;
  const mxArray *m26;
  static const int32_T iv26[2] = { 78400, 2 };

  y = NULL;
  m26 = emlrtCreateNumericArray(2, iv26, mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m26, (void *)&u[0], 8);
  emlrtAssign(&y, m26);
  return y;
}

void run_usrp_rx_api(run_usrp_rxStackData *SD, const mxArray * const prhs[1],
                     int32_T nlhs, const mxArray *plhs[1])
{
  int32_T iv25[1];
  static const char * sv0[1] = { "sys_params_rx" };

  static const uint32_T uv0[4] = { 3866644775U, 4148783165U, 199102426U,
    84318898U };

  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check constant function inputs */
  iv25[0] = 4;
  emlrtCheckArrayChecksumR2018b(&st, prhs[0], false, iv25, sv0, uv0);

  /* Invoke the target function */
  run_usrp_rx(SD, &st, SD->f2.rx_sig_all);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, SD->f2.rx_sig_all);
}

/* End of code generation (_coder_run_usrp_rx_api.c) */
