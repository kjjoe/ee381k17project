/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "warning.h"

/* Variable Definitions */
static emlrtMCInfo g_emlrtMCI = { 14,  /* lineNo */
  25,                                  /* colNo */
  "warning",                           /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtMCInfo h_emlrtMCI = { 14,  /* lineNo */
  9,                                   /* colNo */
  "warning",                           /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pName */
};

static emlrtRSInfo nb_emlrtRSI = { 14, /* lineNo */
  "warning",                           /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"/* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m27;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m27, 3, pArrays, "feval", true, location);
}

void warning(const emlrtStack *sp, const char_T varargin_1_data[], const int32_T
             varargin_1_size[2])
{
  const mxArray *y;
  const mxArray *m10;
  static const int32_T iv10[2] = { 1, 7 };

  static const char_T u[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *b_y;
  const mxArray *m11;
  static const int32_T iv11[2] = { 1, 7 };

  static const char_T b_u[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  const mxArray *c_y;
  const mxArray *m12;
  static const int32_T iv12[2] = { 1, 31 };

  static const char_T msgID[31] = { 's', 'd', 'r', 'u', ':', 'S', 'D', 'R', 'u',
    'B', 'a', 's', 'e', ':', 'D', 'i', 's', 'c', 'o', 'n', 'n', 'e', 'c', 't',
    'P', 'r', 'o', 'b', 'l', 'e', 'm' };

  const mxArray *d_y;
  const mxArray *m13;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m10 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 7, m10, &u[0]);
  emlrtAssign(&y, m10);
  b_y = NULL;
  m11 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 7, m11, &b_u[0]);
  emlrtAssign(&b_y, m11);
  c_y = NULL;
  m12 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 31, m12, &msgID[0]);
  emlrtAssign(&c_y, m12);
  d_y = NULL;
  m13 = emlrtCreateCharArray(2, varargin_1_size);
  emlrtInitCharArrayR2013a(sp, varargin_1_size[1], m13, &varargin_1_data[0]);
  emlrtAssign(&d_y, m13);
  st.site = &nb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, d_y, &g_emlrtMCI), &h_emlrtMCI);
}

/* End of code generation (warning.c) */
