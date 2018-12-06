/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_usrp_tx_mex.c
 *
 * Code generation for function '_coder_run_usrp_tx_mex'
 *
 */

/* Include files */
#include "run_usrp_tx.h"
#include "_coder_run_usrp_tx_mex.h"
#include "run_usrp_tx_terminate.h"
#include "_coder_run_usrp_tx_api.h"
#include "run_usrp_tx_initialize.h"
#include "run_usrp_tx_data.h"

/* Function Declarations */
static void run_usrp_tx_mexFunction(run_usrp_txStackData *SD, int32_T nlhs,
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void run_usrp_tx_mexFunction(run_usrp_txStackData *SD, int32_T nlhs,
  int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs < 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 11,
                        "run_usrp_tx", 4, 11, "run_usrp_tx", 4, 11,
                        "run_usrp_tx");
  }

  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        11, "run_usrp_tx");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "run_usrp_tx");
  }

  /* Call the function. */
  run_usrp_tx_api(SD, prhs, nlhs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  run_usrp_txStackData *run_usrp_txStackDataGlobal = NULL;
  (void)plhs;
  run_usrp_txStackDataGlobal = (run_usrp_txStackData *)emlrtMxCalloc(1, 1U *
    sizeof(run_usrp_txStackData));
  mexAtExit(run_usrp_tx_atexit);

  /* Module initialization. */
  run_usrp_tx_initialize();

  /* Dispatch the entry-point. */
  run_usrp_tx_mexFunction(run_usrp_txStackDataGlobal, nlhs, nrhs, prhs);

  /* Module termination. */
  run_usrp_tx_terminate();
  emlrtMxFree(run_usrp_txStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_run_usrp_tx_mex.c) */
