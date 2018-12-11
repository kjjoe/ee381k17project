/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * deleteDriver.c
 *
 * Code generation for function 'deleteDriver'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "deleteDriver.h"
#include "reportDrivers.h"
#include "run_usrp_tx_mexutil.h"
#include "run_usrp_tx_data.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 6,   /* lineNo */
  "deleteDriver",                      /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/deleteDriver.m"/* pathName */
};

/* Function Definitions */
void deleteDriver(const emlrtStack *sp, int32_T driverApiH, UsrpErrorCapiEnumT
                  *errStat, char_T errStr_data[], int32_T errStr_size[2])
{
  const mxArray *y;
  const mxArray *m6;
  static const int32_T iv6[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  const mxArray *m7;
  static const int32_T iv7[2] = { 1, 9 };

  int32_T errStrSize;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*    Copyright 2011-2012 The MathWorks, Inc. */
  st.site = &x_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m6 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&st, 6, m6, &u[0]);
    emlrtAssign(&y, m6);
    b_st.site = &lb_emlrtRSI;
    setupsdru(&b_st, sdruroot(&b_st, &d_emlrtMCI), y, &e_emlrtMCI);
    isSetupsdruCalled = true;
  }

  /*  These sizes must match those in C code. */
  /*  Arbitrary max imposed on ML/SL side */
  /*  function is being called in interpreted mode */
  /*  not being found:  */
  /*  eml_allow_enum_inputs; */
  /* errStat_i = int32(0); */
  errStr_size[0] = 1;
  memset(&errStr_data[0], 0, sizeof(char_T) << 10);
  deleteDriver_c(driverApiH, errStat, &errStr_data[0]);
  y = NULL;
  m7 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(&st, 9, m7, &cv2[0]);
  emlrtAssign(&y, m7);
  b_st.site = &mb_emlrtRSI;
  drawnow(&b_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&errStr_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    errStr_size[1] = 0;
  } else {
    errStr_size[1] = errStrSize;
  }
}

/* End of code generation (deleteDriver.c) */
