/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDRuTransmitter.c
 *
 * Code generation for function 'SDRuTransmitter'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "SDRuTransmitter.h"
#include "reportDrivers.h"
#include "checkBundledIP.h"
#include "SDRuBase.h"
#include "run_usrp_tx_mexutil.h"
#include "run_usrp_tx_data.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = { 6,  /* lineNo */
  "openDataConnection",                /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/openDataConnection.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "SDRuTransmitter",                   /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/SDRuTransmitter.p"/* pName */
};

/* Function Definitions */
comm_SDRuTransmitter *SDRuTransmitter_SDRuTransmitter(const emlrtStack *sp,
  comm_SDRuTransmitter *obj)
{
  comm_SDRuTransmitter *b_obj;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_obj = obj;
  b_obj->pSubDevice = TxId;
  st.site = &l_emlrtRSI;
  b_obj = SDRuBase_SDRuBase(&st, b_obj);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void SDRuTransmitter_setupImplLocal(const emlrtStack *sp, comm_SDRuTransmitter
  *obj, UsrpErrorCapiEnumT *errStatus, char_T errMsg_data[], int32_T
  errMsg_size[2])
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
  const mxArray *m20;
  static const int32_T iv18[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  char * addr_c;
  static const uint8_T addr_null[26] = { 49U, 57U, 50U, 46U, 49U, 54U, 56U, 46U,
    49U, 48U, 46U, 51U, 44U, 49U, 57U, 50U, 46U, 49U, 54U, 56U, 46U, 49U, 48U,
    46U, 50U, 0U };

  uint8_T req_null[16];
  char * req_c;
  real_T channelMapping[2];
  int32_T i7;
  const mxArray *m21;
  static const int32_T iv19[2] = { 1, 9 };

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
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
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
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI,
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
    m20 = emlrtCreateCharArray(2, iv18);
    emlrtInitCharArrayR2013a(&b_st, 6, m20, &u[0]);
    emlrtAssign(&y, m20);
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
  openDataConnection_c(addr_c, varargin_2, req_c, 7840U, DPortDTypeCDouble,
                       false, 0U, 1.0E+8, channelMapping, 2.0, 16U, 2U, 3U, &i7,
                       errStatus, &errMsg_data[0]);

  /*  Tell coder that addr_null & req_null must be alive and separate throughout the call to cmd_c. */
  (void)(addr_null);
  (void)(req_null);
  y = NULL;
  m21 = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(&b_st, 9, m21, &cv2[0]);
  emlrtAssign(&y, m21);
  c_st.site = &mb_emlrtRSI;
  drawnow(&c_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&errMsg_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    errMsg_size[1] = 0;
  } else {
    errMsg_size[1] = errStrSize;
  }

  obj->pDriverHandle = i7;
}

/* End of code generation (SDRuTransmitter.c) */
