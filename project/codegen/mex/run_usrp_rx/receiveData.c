/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveData.c
 *
 * Code generation for function 'receiveData'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "receiveData.h"
#include "reportDrivers.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 7,  /* lineNo */
  "receiveData",                       /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/receiveData.m"/* pathName */
};

/* Function Definitions */
void receiveData(const emlrtStack *sp, int32_T driverApiH, const real_T freq[2],
                 const real_T loOffset[2], const real_T gain[2], real_T decim,
                 cint16_T data[375000], uint32_T *dataLength, uint32_T *overflow,
                 UsrpErrorCapiEnumT *errStat, char_T errStr_data[], int32_T
                 errStr_size[2])
{
  const mxArray *y;
  const mxArray *m22;
  static const int32_T iv22[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  const mxArray *m23;
  static const int32_T iv23[2] = { 1, 9 };

  int32_T errStrSize;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*    Copyright 2011-2015 The MathWorks, Inc. */
  st.site = &fb_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m22 = emlrtCreateCharArray(2, iv22);
    emlrtInitCharArrayR2013a(&st, 6, m22, &u[0]);
    emlrtAssign(&y, m22);
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

  /*  46336 represents 0.00185344 seconds at 25Msps.  1 ms seems to be a decent */
  /*  time interval to interact with the IP stack on a default glnxa64 machine. */
  /*  32768 seems to be the max for UHD(TM) so we may want to change to that. */
  receiveData_c(driverApiH, freq, loOffset, gain, decim, data, dataLength,
                overflow, errStat, &errStr_data[0]);
  y = NULL;
  m23 = emlrtCreateCharArray(2, iv23);
  emlrtInitCharArrayR2013a(&st, 9, m23, &cv2[0]);
  emlrtAssign(&y, m23);
  b_st.site = &mb_emlrtRSI;
  drawnow(&b_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&errStr_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    errStr_size[1] = 0;
  } else {
    errStr_size[1] = errStrSize;
  }
}

/* End of code generation (receiveData.c) */
