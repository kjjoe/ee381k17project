/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDRuReceiver.c
 *
 * Code generation for function 'SDRuReceiver'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "SDRuReceiver.h"
#include "error1.h"
#include "receiveData.h"
#include "all.h"
#include "reportDrivers.h"
#include "checkBundledIP.h"
#include "SDRuBase.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 1,   /* lineNo */
  "SDRuReceiver",                      /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/SDRuReceiver.p"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 6,  /* lineNo */
  "openDataConnection",                /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/openDataConnection.m"/* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "SDRuReceiver",                      /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/SDRuReceiver.p"/* pName */
};

/* Function Definitions */
comm_SDRuReceiver *SDRuReceiver_SDRuReceiver(const emlrtStack *sp,
  comm_SDRuReceiver *obj)
{
  comm_SDRuReceiver *b_obj;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_obj = obj;
  b_obj->pSubDevice = RxId;
  st.site = &l_emlrtRSI;
  b_obj = SDRuBase_SDRuBase(&st, b_obj);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void SDRuReceiver_setupImplLocal(const emlrtStack *sp, comm_SDRuReceiver *obj,
  UsrpErrorCapiEnumT *deviceStatus, char_T errMsg_data[], int32_T errMsg_size[2])
{
  char_T ipNotFound_data[25];
  int32_T ipNotFound_size[2];
  char_T ipWrongPlatform_data[25];
  int32_T ipWrongPlatform_size[2];
  int32_T errStrSize;
  char_T tmp_data[137];
  static const char_T cv4[37] = { 'U', 'n', 'a', 'b', 'l', 'e', ' ', 't', 'o',
    ' ', 'f', 'i', 'n', 'd', ' ', 'r', 'a', 'd', 'i', 'o', ' ', 'w', 'i', 't',
    'h', ' ', 'I', 'P', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ' };

  BoardIdCapiEnumT varargin_2;
  char_T b_tmp_data[98];
  static const char_T cv5[22] = { 'R', 'a', 'd', 'i', 'o', ' ', 'w', 'i', 't',
    'h', ' ', 'I', 'P', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ' ' };

  static const char_T cv6[73] = { 'A', 't', 't', 'a', 'c', 'h', ' ', 'a', ' ',
    'd', 'e', 'v', 'i', 'c', 'e', ' ', 'w', 'i', 't', 'h', ' ', 't', 'h', 'i',
    's', ' ', 'I', 'P', ' ', 'a', 'd', 'd', 'r', 'e', 's', 's', ',', ' ', 'o',
    'r', ' ', 'c', 'o', 'n', 't', 'i', 'n', 'u', 'e', ' ', 'w', 'o', 'r', 'k',
    'i', 'n', 'g', ' ', 'i', 'n', ' ', 'o', 'f', 'f', 'l', 'i', 'n', 'e', ' ',
    'm', 'o', 'd', 'e' };

  uint8_T requester[15];
  static const char_T cv7[35] = { ' ', 'i', 's', ' ', 'n', 'o', 't', ' ', 'o',
    'f', ' ', 't', 'h', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd',
    ' ', 'p', 'l', 'a', 't', 'f', 'o', 'r', 'm', ' ', '\'' };

  static const char_T cv8[15] = { 'N', '2', '0', '0', '/', 'N', '2', '1', '0',
    '/', 'U', 'S', 'R', 'P', '2' };

  const mxArray *y;
  const mxArray *m14;
  static const int32_T iv14[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  char * addr_c;
  static const uint8_T addr_null[26] = { 49U, 57U, 50U, 46U, 49U, 54U, 56U, 46U,
    49U, 48U, 46U, 51U, 44U, 49U, 57U, 50U, 46U, 49U, 54U, 56U, 46U, 49U, 48U,
    46U, 50U, 0U };

  uint8_T req_null[16];
  char * req_c;
  real_T channelMapping[2];
  int32_T i9;
  const mxArray *m15;
  static const int32_T iv15[2] = { 1, 9 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  checkBundledIP(&st, ipNotFound_data, ipNotFound_size, ipWrongPlatform_data,
                 ipWrongPlatform_size);
  if (ipNotFound_size[1] != 0) {
    for (errStrSize = 0; errStrSize < 37; errStrSize++) {
      tmp_data[errStrSize] = cv4[errStrSize];
    }

    if (0 <= ipNotFound_size[1] - 1) {
      memcpy(&tmp_data[37], &ipNotFound_data[0], (uint32_T)(ipNotFound_size[1] *
              (int32_T)sizeof(char_T)));
    }

    tmp_data[37 + ipNotFound_size[1]] = '.';
    tmp_data[38 + ipNotFound_size[1]] = '\x0a';
    memcpy(&tmp_data[ipNotFound_size[1] + 39], &cv6[0], 73U * sizeof(char_T));
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
      "sdru:reportSDRuStatus:UnknownStatus",
      "sdru:reportSDRuStatus:UnknownStatus", 3, 4, 112 + ipNotFound_size[1],
      &tmp_data[0]);
  }

  if (ipWrongPlatform_size[1] != 0) {
    for (errStrSize = 0; errStrSize < 22; errStrSize++) {
      b_tmp_data[errStrSize] = cv5[errStrSize];
    }

    if (0 <= ipWrongPlatform_size[1] - 1) {
      memcpy(&b_tmp_data[22], &ipWrongPlatform_data[0], (uint32_T)
             (ipWrongPlatform_size[1] * (int32_T)sizeof(char_T)));
    }

    for (errStrSize = 0; errStrSize < 35; errStrSize++) {
      b_tmp_data[(errStrSize + ipWrongPlatform_size[1]) + 22] = cv7[errStrSize];
    }

    for (errStrSize = 0; errStrSize < 15; errStrSize++) {
      b_tmp_data[(errStrSize + ipWrongPlatform_size[1]) + 57] = cv8[errStrSize];
    }

    b_tmp_data[72 + ipWrongPlatform_size[1]] = '\'';
    emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
      "sdru:reportSDRuStatus:UnknownStatus",
      "sdru:reportSDRuStatus:UnknownStatus", 3, 4, 73 + ipWrongPlatform_size[1],
      &b_tmp_data[0]);
  }

  st.site = &l_emlrtRSI;
  varargin_2 = obj->pSubDevice;
  for (errStrSize = 0; errStrSize < 15; errStrSize++) {
    requester[errStrSize] = (uint8_T)obj->ObjectID[errStrSize];
  }

  /*    Copyright 2011-2016 The MathWorks, Inc. */
  b_st.site = &db_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m14 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(&b_st, 6, m14, &u[0]);
    emlrtAssign(&y, m14);
    c_st.site = &lb_emlrtRSI;
    setupsdru(&c_st, sdruroot(&c_st, &d_emlrtMCI), y, &e_emlrtMCI);
    isSetupsdruCalled = true;
  }

  /*  These sizes must match those in C code. */
  /*  Arbitrary max imposed on ML/SL side */
  /*  function is being called in interpreted mode */
  /*  not being found:  */
  /*  eml_allow_enum_inputs; */
  /* errStat_i = int32(0); */
  errMsg_size[0] = 1;
  memset(&errMsg_data[0], 0, sizeof(char_T) << 10);

  /*  varargin   1      2         3          4              5        6         7             8              9            10         11       12      13 */
  /*            addr, boardId, requester, frameLength, dportType, buffMode, buffSize, masterClockRate, channelMapping, numChannels, wireFormat, clkSrc, ppsSrc */
  /*  varargout  1         2         3 */
  /*            driverH, errStat, errMsg */
  addr_c = (char *)(addr_null);
  for (errStrSize = 0; errStrSize < 15; errStrSize++) {
    req_null[errStrSize] = requester[errStrSize];
  }

  req_null[15] = 0U;
  req_c = (char *)(req_null);
  channelMapping[0] = 0.0;
  channelMapping[1] = 1.0;
  openDataConnection_c(addr_c, varargin_2, req_c, 78400U, DPortDTypeCInt16,
                       false, 0U, 1.0E+8, channelMapping, 2.0, 16U, 2U, 3U, &i9,
                       deviceStatus, &errMsg_data[0]);

  /*  Tell coder that addr_null & req_null must be alive and separate throughout the call to cmd_c. */
  (void)(addr_null);
  (void)(req_null);
  y = NULL;
  m15 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(&b_st, 9, m15, &cv2[0]);
  emlrtAssign(&y, m15);
  c_st.site = &mb_emlrtRSI;
  drawnow(&c_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&errMsg_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    errMsg_size[1] = 0;
  } else {
    errMsg_size[1] = errStrSize;
  }

  obj->pDriverHandle = i9;
}

void SDRuReceiver_stepImpl(run_usrp_rxStackData *SD, const emlrtStack *sp, const
  comm_SDRuReceiver *obj, creal_T y[156800], uint32_T *dataLen)
{
  real_T a;
  real_T b_a;
  boolean_T c_a[2];
  real_T d_a;
  real_T e_a[2];
  real_T f_a[2];
  real_T g_a[2];
  uint32_T overrun;
  UsrpErrorCapiEnumT errStatus;
  char_T errMsg_data[1024];
  int32_T errMsg_size[2];
  int32_T i11;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  a = obj->CenterFrequency;
  b_a = obj->LocalOscillatorOffset;
  c_a[0] = (b_a == 0.0);
  c_a[1] = (b_a == 0.0);
  if (!all(c_a)) {
    st.site = &l_emlrtRSI;
    b_error(&st);
  }

  d_a = obj->Gain;
  e_a[0] = a;
  f_a[0] = b_a;
  g_a[0] = d_a;
  e_a[1] = a;
  f_a[1] = b_a;
  g_a[1] = d_a;
  st.site = &l_emlrtRSI;
  receiveData(&st, obj->pDriverHandle, e_a, f_a, g_a, obj->DecimationFactor,
              SD->f0.yTemp, dataLen, &overrun, &errStatus, errMsg_data,
              errMsg_size);
  if (errStatus != UsrpDriverSuccess) {
    st.site = &l_emlrtRSI;
    c_error(&st, errMsg_data, errMsg_size);
  }

  for (i11 = 0; i11 < 156800; i11++) {
    if (SD->f0.yTemp[i11].im == 0) {
      y[i11].re = (real_T)SD->f0.yTemp[i11].re / 32767.0;
      y[i11].im = 0.0;
    } else if (SD->f0.yTemp[i11].re == 0) {
      y[i11].re = 0.0;
      y[i11].im = (real_T)SD->f0.yTemp[i11].im / 32767.0;
    } else {
      y[i11].re = (real_T)SD->f0.yTemp[i11].re / 32767.0;
      y[i11].im = (real_T)SD->f0.yTemp[i11].im / 32767.0;
    }
  }
}

/* End of code generation (SDRuReceiver.c) */
