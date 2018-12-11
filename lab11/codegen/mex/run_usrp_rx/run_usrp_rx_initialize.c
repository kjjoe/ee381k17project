/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx_initialize.c
 *
 * Code generation for function 'run_usrp_rx_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "run_usrp_rx_initialize.h"
#include "mapiPrivate.h"
#include "_coder_run_usrp_rx_mex.h"
#include "run_usrp_rx_data.h"

/* Function Declarations */
static void run_usrp_rx_once(void);

/* Function Definitions */
static void run_usrp_rx_once(void)
{
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  emlrtAssignP(&b_eml_mx, NULL);
  emlrtAssignP(&eml_mx, NULL);
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtAssignP(&b_eml_mx, m0);
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtAssignP(&eml_mx, m1);
  run_usrp_rx_init();
  mapiPrivate_init();
}

void run_usrp_rx_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Communication_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    run_usrp_rx_once();
  }
}

/* End of code generation (run_usrp_rx_initialize.c) */
