/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mapiPrivate.c
 *
 * Code generation for function 'mapiPrivate'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "mapiPrivate.h"
#include "reportDrivers.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Function Definitions */
void mapiPrivate(const emlrtStack *sp, int32_T varargin_1, UsrpErrorCapiEnumT
                 *varargout_1, char_T varargout_2_data[], int32_T
                 varargout_2_size[2])
{
  const mxArray *y;
  const mxArray *m18;
  static const int32_T iv18[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  const mxArray *m19;
  static const int32_T iv19[2] = { 1, 9 };

  int32_T errStrSize;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m18 = emlrtCreateCharArray(2, iv18);
    emlrtInitCharArrayR2013a(sp, 6, m18, &u[0]);
    emlrtAssign(&y, m18);
    st.site = &lb_emlrtRSI;
    setupsdru(&st, sdruroot(&st, &d_emlrtMCI), y, &e_emlrtMCI);
    isSetupsdruCalled = true;
  }

  /*  These sizes must match those in C code. */
  /*  Arbitrary max imposed on ML/SL side */
  /*  function is being called in interpreted mode */
  /*  not being found:  */
  /*  eml_allow_enum_inputs; */
  /* errStat_i = int32(0); */
  varargout_2_size[0] = 1;
  memset(&varargout_2_data[0], 0, sizeof(char_T) << 10);
  closeDataConnection_c(varargin_1, varargout_1, &varargout_2_data[0]);
  y = NULL;
  m19 = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(sp, 9, m19, &cv2[0]);
  emlrtAssign(&y, m19);
  st.site = &mb_emlrtRSI;
  drawnow(&st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&varargout_2_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(sp, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    varargout_2_size[1] = 0;
  } else {
    varargout_2_size[1] = errStrSize;
  }
}

void mapiPrivate_init(void)
{
  isSetupsdruCalled = false;
}

/* End of code generation (mapiPrivate.c) */
