/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkIPAddressFormat.c
 *
 * Code generation for function 'checkIPAddressFormat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "checkIPAddressFormat.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = { 32,  /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 43,  /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 44,  /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 45,  /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 46,  /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 41,  /* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 153, /* lineNo */
  "find",                              /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "find",                              /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  31,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  15,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  31,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  15,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  31,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  15,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  17,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  15,                                  /* colNo */
  "aAddrs",                            /* aName */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 35,/* lineNo */
  3,                                   /* colNo */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 54,/* lineNo */
  3,                                   /* colNo */
  "checkIPAddressFormat",              /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pName */
};

/* Function Declarations */
static void checkNumeric(const emlrtStack *sp, const int16_T x_data[], const
  int32_T x_size[2]);

/* Function Definitions */
static void checkNumeric(const emlrtStack *sp, const int16_T x_data[], const
  int32_T x_size[2])
{
  boolean_T guard1 = false;
  int32_T loop_ub_tmp;
  int32_T i8;
  boolean_T b_x_data[25];
  boolean_T tmp_data[25];
  boolean_T y;
  boolean_T exitg1;
  guard1 = false;
  if (x_size[1] == 0) {
    guard1 = true;
  } else {
    loop_ub_tmp = x_size[0] * x_size[1];
    for (i8 = 0; i8 < loop_ub_tmp; i8++) {
      b_x_data[i8] = (x_data[i8] >= 48);
    }

    for (i8 = 0; i8 < loop_ub_tmp; i8++) {
      tmp_data[i8] = (x_data[i8] <= 57);
    }

    loop_ub_tmp = x_size[1] - 1;
    for (i8 = 0; i8 <= loop_ub_tmp; i8++) {
      b_x_data[i8] = ((!b_x_data[i8]) || (!tmp_data[i8]));
    }

    y = false;
    loop_ub_tmp = 1;
    exitg1 = false;
    while ((!exitg1) && (loop_ub_tmp <= x_size[1])) {
      if (b_x_data[loop_ub_tmp - 1]) {
        y = true;
        exitg1 = true;
      } else {
        loop_ub_tmp++;
      }
    }

    if (y) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
      "sdru:checkIPAddressFormat:InvalidIPAddress",
      "sdru:checkIPAddressFormat:InvalidIPAddress", 3, 4, 9, "IPAddress");
  }
}

void checkIPAddressFormat(const emlrtStack *sp, const char_T aAddrs_data[],
  const int32_T aAddrs_size[2])
{
  int32_T nx;
  int32_T ii_size_idx_1;
  boolean_T x_data[25];
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  int8_T ii_data[25];
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T b_aAddrs_size[2];
  int16_T b_aAddrs_data[24];
  int32_T c_aAddrs_size[2];
  int32_T d_aAddrs_size[2];
  int32_T e_aAddrs_size[2];
  int16_T c_aAddrs_data[25];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /* checkIPAddressFormat IP address format checker */
  /*  */
  /*    Warning: This function is an internal MathWorks function and may be removed */
  /*    in a future release. */
  /*  */
  /*    checkIPAddressFormat(ADDRS, NAME) returns true if the ADDRS is a valid */
  /*    dotted quad IP address. Otherwise, it errors out and prompts that variable */
  /*    NAME is not a valid IP address. */
  /*  */
  /*    % Example: */
  /*    %   Check if the string '192.168.10.a' is a valid IP address for variable */
  /*    %   IPAddress */
  /*    checkIPAddressFormat('192.168.10.a', 'IPAddress') */
  /*    Copyright 2012-2015 The MathWorks, Inc. */
  /*  Look for three dots */
  st.site = &o_emlrtRSI;
  nx = aAddrs_size[0] * aAddrs_size[1];
  for (ii_size_idx_1 = 0; ii_size_idx_1 < nx; ii_size_idx_1++) {
    x_data[ii_size_idx_1] = (aAddrs_data[ii_size_idx_1] == '.');
  }

  b_st.site = &t_emlrtRSI;
  nx = aAddrs_size[1];
  c_st.site = &u_emlrtRSI;
  idx = 0;
  ii_size_idx_1 = aAddrs_size[1];
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x_data[ii]) {
      idx++;
      ii_data[idx - 1] = (int8_T)(ii + 1);
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (idx > aAddrs_size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (aAddrs_size[1] == 1) {
    if (idx == 0) {
      ii_size_idx_1 = 0;
    }
  } else if (1 > idx) {
    ii_size_idx_1 = 0;
  } else {
    ii_size_idx_1 = idx;
  }

  /*  Used instead of findstr since */
  /*  findstr does not generate code */
  if (ii_size_idx_1 != 3) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
      "sdru:checkIPAddressFormat:InvalidIPAddress",
      "sdru:checkIPAddressFormat:InvalidIPAddress", 3, 4, 9, "IPAddress");
  }

  /*  Check if all the elements other than the dots are numbers */
  nx = ii_data[0] - 1;
  if (1 > nx) {
    nx = 0;
  } else {
    if (1 > aAddrs_size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, aAddrs_size[1], &j_emlrtBCI, sp);
    }

    if ((nx < 1) || (nx > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, aAddrs_size[1], &i_emlrtBCI, sp);
    }
  }

  ii_size_idx_1 = ii_data[0] + 1;
  ii = ii_data[1] - 1;
  if (ii_size_idx_1 > ii) {
    ii_size_idx_1 = 0;
    ii = 0;
  } else {
    if ((ii_size_idx_1 < 1) || (ii_size_idx_1 > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(ii_size_idx_1, 1, aAddrs_size[1],
        &h_emlrtBCI, sp);
    }

    ii_size_idx_1--;
    if ((ii < 1) || (ii > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(ii, 1, aAddrs_size[1], &g_emlrtBCI, sp);
    }
  }

  i4 = ii_data[1] + 1;
  i5 = ii_data[2] - 1;
  if (i4 > i5) {
    i4 = 0;
    i5 = 0;
  } else {
    if ((i4 < 1) || (i4 > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(i4, 1, aAddrs_size[1], &f_emlrtBCI, sp);
    }

    i4--;
    if ((i5 < 1) || (i5 > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, aAddrs_size[1], &e_emlrtBCI, sp);
    }
  }

  i6 = ii_data[2] + 1;
  if (i6 > aAddrs_size[1]) {
    i6 = 0;
    i7 = 0;
  } else {
    if ((i6 < 1) || (i6 > aAddrs_size[1])) {
      emlrtDynamicBoundsCheckR2012b(i6, 1, aAddrs_size[1], &d_emlrtBCI, sp);
    }

    i6--;
    if (aAddrs_size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(aAddrs_size[1], 1, aAddrs_size[1],
        &c_emlrtBCI, sp);
    }

    i7 = aAddrs_size[1];
  }

  b_aAddrs_size[0] = 1;
  b_aAddrs_size[1] = nx;
  for (idx = 0; idx < nx; idx++) {
    b_aAddrs_data[idx] = (uint8_T)aAddrs_data[idx];
  }

  st.site = &p_emlrtRSI;
  checkNumeric(&st, b_aAddrs_data, b_aAddrs_size);
  c_aAddrs_size[0] = 1;
  nx = ii - ii_size_idx_1;
  c_aAddrs_size[1] = nx;
  for (ii = 0; ii < nx; ii++) {
    b_aAddrs_data[ii] = (uint8_T)aAddrs_data[ii_size_idx_1 + ii];
  }

  st.site = &q_emlrtRSI;
  checkNumeric(&st, b_aAddrs_data, c_aAddrs_size);
  d_aAddrs_size[0] = 1;
  nx = i5 - i4;
  d_aAddrs_size[1] = nx;
  for (ii_size_idx_1 = 0; ii_size_idx_1 < nx; ii_size_idx_1++) {
    b_aAddrs_data[ii_size_idx_1] = (uint8_T)aAddrs_data[i4 + ii_size_idx_1];
  }

  st.site = &r_emlrtRSI;
  checkNumeric(&st, b_aAddrs_data, d_aAddrs_size);
  e_aAddrs_size[0] = 1;
  nx = i7 - i6;
  e_aAddrs_size[1] = nx;
  for (ii_size_idx_1 = 0; ii_size_idx_1 < nx; ii_size_idx_1++) {
    c_aAddrs_data[ii_size_idx_1] = (uint8_T)aAddrs_data[i6 + ii_size_idx_1];
  }

  st.site = &s_emlrtRSI;
  checkNumeric(&st, c_aAddrs_data, e_aAddrs_size);
}

/* End of code generation (checkIPAddressFormat.c) */
