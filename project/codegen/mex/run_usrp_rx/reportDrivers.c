/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * reportDrivers.c
 *
 * Code generation for function 'reportDrivers'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "reportDrivers.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 6,   /* lineNo */
  "reportDrivers",                     /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/reportDrivers.m"/* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = { 107,/* lineNo */
  13,                                  /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

/* Function Definitions */
void reportDrivers(const emlrtStack *sp, char_T flatAddrList_data[], int32_T
                   flatAddrList_size[2])
{
  const mxArray *y;
  const mxArray *m8;
  static const int32_T iv9[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  char_T errStr_data[1024];
  UsrpErrorCapiEnumT errStat_i;
  int32_T flatAddrListSize;
  const mxArray *m9;
  static const int32_T iv10[2] = { 1, 9 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*    Copyright 2011-2012 The MathWorks, Inc. */
  st.site = &y_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m8 = emlrtCreateCharArray(2, iv9);
    emlrtInitCharArrayR2013a(&st, 6, m8, &u[0]);
    emlrtAssign(&y, m8);
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
  memset(&errStr_data[0], 0, sizeof(char_T) << 10);
  flatAddrList_size[0] = 1;
  memset(&flatAddrList_data[0], 0, 3000U * sizeof(char_T));
  reportDrivers_c(&flatAddrList_data[0], &errStat_i, &errStr_data[0]);
  flatAddrListSize = strlen(&flatAddrList_data[0]);
  if (flatAddrListSize > 3000) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > flatAddrListSize) {
    flatAddrList_size[1] = 0;
  } else {
    flatAddrList_size[1] = flatAddrListSize;
  }

  y = NULL;
  m9 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(&st, 9, m9, &cv2[0]);
  emlrtAssign(&y, m9);
  b_st.site = &mb_emlrtRSI;
  drawnow(&b_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  flatAddrListSize = strlen(&errStr_data[0]);
  if (flatAddrListSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }
}

/* End of code generation (reportDrivers.c) */
