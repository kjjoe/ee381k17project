/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDRuBase.c
 *
 * Code generation for function 'SDRuBase'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "SDRuBase.h"
#include "error1.h"
#include "SystemProp.h"
#include "checkIPAddressFormat.h"
#include "error.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 43,  /* lineNo */
  "ExternalDependency",                /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/coder/coder/+coder/ExternalDependency.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 61,  /* lineNo */
  "randi",                             /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/randfun/randi.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 26,  /* lineNo */
  "char",                              /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/strfun/char.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 38,  /* lineNo */
  "charCastCheck",                     /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/eml/+coder/+internal/charCastCheck.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 54,  /* lineNo */
  "charCastCheck",                     /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/eml/+coder/+internal/charCastCheck.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 1,   /* lineNo */
  "pvParse",                           /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/matlab/system/+matlab/+system/pvParse.p"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "SDRuBase",                          /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/+internal/SDRuBase.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  25,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "SDRuBase",                          /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/+internal/SDRuBase.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
comm_SDRuReceiver *SDRuBase_SDRuBase(const emlrtStack *sp, comm_SDRuReceiver
  *obj)
{
  comm_SDRuReceiver *b_obj;
  real_T varargin_1[10];
  int32_T k;
  int32_T i2;
  static const char_T cv3[5] = { 'S', 'D', 'R', 'u', '_' };

  real_T u;
  int32_T idx;
  boolean_T exitg1;
  int32_T loc_size_idx_1;
  int8_T ii_data[25];
  int8_T loc_data[27];
  int32_T i3;
  static const boolean_T bv1[25] = { false, false, false, true, false, false,
    false, true, false, false, true, false, false, false, false, false, true,
    false, false, false, true, false, false, true, false };

  boolean_T p;
  boolean_T b_p;
  int8_T y_data[8];
  int32_T tmp_size[2];
  int32_T tmp_size_tmp;
  const mxArray *y;
  char_T tmp_data[25];
  const mxArray *m4;
  static const int32_T iv5[2] = { 1, 35 };

  const mxArray *b_y;
  const mxArray *m5;
  static const int32_T iv6[2] = { 1, 126 };

  static const char_T varargin_2[126] = { 'W', 'h', 'e', 'n', ' ', 'P', 'l', 'a',
    't', 'f', 'o', 'r', 'm', ' ', 'i', 's', ' ', '\'', 'N', '2', '0', '0', '/',
    'N', '2', '1', '0', '/', 'U', 'S', 'R', 'P', '2', '\'', ',', ' ', 'C', 'h',
    'a', 'n', 'n', 'e', 'l', 'M', 'a', 'p', 'p', 'i', 'n', 'g', ' ', 'm', 'u',
    's', 't', ' ', 'b', 'e', ' ', '[', '1', ':', 'N', ']', ' ', 'w', 'h', 'e',
    'r', 'e', ' ', 'N', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'n', 'u', 'm',
    'b', 'e', 'r', ' ', 'o', 'f', ' ', 'I', 'P', ' ', 'a', 'd', 'd', 'r', 'e',
    's', 's', 'e', 's', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ',
    'b', 'y', ' ', 'I', 'P', 'A', 'd', 'd', 'r', 'e', 's', 's', '.' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_obj = obj;
  b_obj->pConnected = false;
  b_obj->pDriverHandle = 0;
  st.site = &m_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_obj->isInitialized = 0;
  c_st.site = &f_emlrtRSI;
  st.site = &m_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  st.site = &m_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  emlrtRandu(&varargin_1[0], 10);
  for (k = 0; k < 10; k++) {
    varargin_1[k] = 48.0 + muDoubleScalarFloor(varargin_1[k] * 10.0);
  }

  st.site = &m_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  for (k = 0; k < 10; k++) {
    c_st.site = &j_emlrtRSI;
    if ((0.0 <= varargin_1[k]) && (varargin_1[k] <= 255.0)) {
    } else {
      d_st.site = &k_emlrtRSI;
      error(&d_st);
    }
  }

  for (i2 = 0; i2 < 5; i2++) {
    b_obj->ObjectID[i2] = cv3[i2];
  }

  for (i2 = 0; i2 < 10; i2++) {
    u = varargin_1[i2];
    if (u < 0.0) {
      u = muDoubleScalarCeil(u);
    } else {
      u = muDoubleScalarFloor(u);
    }

    if (muDoubleScalarIsNaN(u) || muDoubleScalarIsInf(u)) {
      u = 0.0;
    } else {
      u = muDoubleScalarRem(u, 256.0);
    }

    if (u < 0.0) {
      b_obj->ObjectID[i2 + 5] = (int8_T)-(int8_T)(uint8_T)-u;
    } else {
      b_obj->ObjectID[i2 + 5] = (int8_T)(uint8_T)u;
    }
  }

  st.site = &m_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  idx = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 25)) {
    if (bv0[k]) {
      idx++;
      ii_data[idx - 1] = (int8_T)(k + 1);
      if (idx >= 25) {
        exitg1 = true;
      } else {
        k++;
      }
    } else {
      k++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  loc_size_idx_1 = 2 + idx;
  loc_data[0] = 0;
  if (0 <= idx - 1) {
    memcpy(&loc_data[1], &ii_data[0], (uint32_T)(idx * (int32_T)sizeof(int8_T)));
  }

  loc_data[1 + idx] = 26;
  i2 = 2 + idx;
  for (k = 0; k <= i2 - 2; k++) {
    idx = 1 + k;
    if (idx > loc_size_idx_1) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, loc_size_idx_1, &emlrtBCI, &d_st);
    }

    i3 = k + 2;
    if (i3 > loc_size_idx_1) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, loc_size_idx_1, &emlrtBCI, &d_st);
    }

    if (loc_data[idx - 1] != loc_data[i3 - 1] - 1) {
      idx = 1 + k;
      if (idx > loc_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, loc_size_idx_1, &emlrtBCI, &d_st);
      }

      idx = k + 2;
      if (idx > loc_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, loc_size_idx_1, &emlrtBCI, &d_st);
      }

      idx = loc_data[k] + 1;
      i3 = loc_data[k + 1] - 1;
      if (idx > i3) {
        idx = 0;
        i3 = 0;
      } else {
        if ((idx < 1) || (idx > 25)) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, 25, &b_emlrtBCI, &d_st);
        }

        idx--;
        if ((i3 < 1) || (i3 > 25)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 25, &b_emlrtBCI, &d_st);
        }
      }

      tmp_size[0] = 1;
      tmp_size_tmp = i3 - idx;
      tmp_size[1] = tmp_size_tmp;
      for (i3 = 0; i3 < tmp_size_tmp; i3++) {
        tmp_data[i3] = cv0[idx + i3];
      }

      e_st.site = &m_emlrtRSI;
      checkIPAddressFormat(&e_st, tmp_data, tmp_size);
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&d_st);
    }
  }

  d_st.site = &n_emlrtRSI;
  idx = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 25)) {
    if (bv1[k]) {
      idx++;
      if (idx >= 25) {
        exitg1 = true;
      } else {
        k++;
      }
    } else {
      k++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  u = (real_T)idx / 3.0;
  if (u < 1.0) {
    idx = 0;
  } else {
    k = (int32_T)muDoubleScalarFloor(u - 1.0);
    idx = k + 1;
    for (i2 = 0; i2 <= k; i2++) {
      y_data[i2] = (int8_T)(1 + i2);
    }
  }

  p = false;
  b_p = false;
  if (2 == idx) {
    b_p = true;
  }

  if (b_p && (idx != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (1 + k != y_data[k]) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    e_st.site = &m_emlrtRSI;
    y = NULL;
    m4 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(&e_st, 35, m4, &cv1[0]);
    emlrtAssign(&y, m4);
    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(&e_st, 126, m5, &varargin_2[0]);
    emlrtAssign(&b_y, m5);
    f_st.site = &kb_emlrtRSI;
    d_error(&f_st, y, b_y, &c_emlrtMCI);
  }

  d_st.site = &n_emlrtRSI;
  c_SystemProp_matlabCodegenSetAn(&d_st, b_obj);
  d_st.site = &n_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  b_obj->DecimationFactor = 20.0;
  d_st.site = &n_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  b_obj->Gain = 10.0;
  d_st.site = &n_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  b_obj->CenterFrequency = 2.4E+9;
  d_st.site = &n_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  b_obj->LocalOscillatorOffset = 0.0;
  return b_obj;
}

/* End of code generation (SDRuBase.c) */
