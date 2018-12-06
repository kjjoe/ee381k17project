/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error1.c
 *
 * Code generation for function 'error1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "error1.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  const mxArray *y;
  const mxArray *m20;
  static const int32_T iv20[2] = { 1, 35 };

  const mxArray *b_y;
  const mxArray *m21;
  static const int32_T iv21[2] = { 1, 66 };

  static const char_T varargin_2[66] = { 'L', 'o', 'c', 'a', 'l', 'O', 's', 'c',
    'i', 'l', 'l', 'a', 't', 'o', 'r', 'O', 'f', 'f', 's', 'e', 't', ' ', 'm',
    'u', 's', 't', ' ', 'b', 'e', ' ', 'z', 'e', 'r', 'o', ' ', 'w', 'h', 'e',
    'n', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', ' ', 'c', 'h', 'a', 'n',
    'n', 'e', 'l', 's', ' ', 'a', 'r', 'e', ' ', 'u', 's', 'e', 'd' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m20 = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(sp, 35, m20, &cv1[0]);
  emlrtAssign(&y, m20);
  b_y = NULL;
  m21 = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 66, m21, &varargin_2[0]);
  emlrtAssign(&b_y, m21);
  st.site = &kb_emlrtRSI;
  d_error(&st, y, b_y, &c_emlrtMCI);
}

void c_error(const emlrtStack *sp, const char_T varargin_2_data[], const int32_T
             varargin_2_size[2])
{
  const mxArray *y;
  const mxArray *m24;
  static const int32_T iv24[2] = { 1, 37 };

  static const char_T varargin_1[37] = { 's', 'd', 'r', 'u', ':', 'S', 'D', 'R',
    'u', 'R', 'e', 'c', 'e', 'i', 'v', 'e', 'r', ':', 'R', 'e', 'c', 'e', 'i',
    'v', 'e', 'U', 'n', 's', 'u', 'c', 'c', 'e', 's', 's', 'f', 'u', 'l' };

  const mxArray *b_y;
  const mxArray *m25;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m24 = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(sp, 37, m24, &varargin_1[0]);
  emlrtAssign(&y, m24);
  b_y = NULL;
  m25 = emlrtCreateCharArray(2, varargin_2_size);
  emlrtInitCharArrayR2013a(sp, varargin_2_size[1], m25, &varargin_2_data[0]);
  emlrtAssign(&b_y, m25);
  st.site = &kb_emlrtRSI;
  d_error(&st, y, b_y, &c_emlrtMCI);
}

/* End of code generation (error1.c) */
