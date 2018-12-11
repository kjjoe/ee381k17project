/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_usrp_rx_mex.c
 *
 * Code generation for function '_coder_run_usrp_rx_mex'
 *
 */

/* Include files */
#include "run_usrp_rx.h"
#include "_coder_run_usrp_rx_mex.h"
#include "run_usrp_rx_terminate.h"
#include "_coder_run_usrp_rx_api.h"
#include "run_usrp_rx_initialize.h"
#include "run_usrp_rx_data.h"

/* Function Declarations */
static void run_usrp_rx_mexFunction(run_usrp_rxStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void run_usrp_rx_mexFunction(run_usrp_rxStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs < 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 11,
                        "run_usrp_rx", 4, 11, "run_usrp_rx", 4, 11,
                        "run_usrp_rx");
  }

  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        11, "run_usrp_rx");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "run_usrp_rx");
  }

  /* Call the function. */
  run_usrp_rx_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  run_usrp_rxStackData *run_usrp_rxStackDataGlobal = NULL;
  run_usrp_rxStackDataGlobal = (run_usrp_rxStackData *)emlrtMxCalloc(1, 1U *
    sizeof(run_usrp_rxStackData));
  mexAtExit(run_usrp_rx_atexit);

  /* Module initialization. */
  run_usrp_rx_initialize();

  /* Dispatch the entry-point. */
  run_usrp_rx_mexFunction(run_usrp_rxStackDataGlobal, nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  run_usrp_rx_terminate();
  emlrtMxFree(run_usrp_rxStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_run_usrp_rx_mex.c) */
