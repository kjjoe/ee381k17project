/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getSDRuList.c
 *
 * Code generation for function 'getSDRuList'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "getSDRuList.h"
#include "reportDrivers.h"
#include "run_usrp_rx_mexutil.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 33, /* lineNo */
  "getSDRuList",                       /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/getSDRuList.m"/* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = { 120,/* lineNo */
  13,                                  /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

/* Function Definitions */
void getSDRuList(const emlrtStack *sp, char_T flatAddrList_data[], int32_T
                 flatAddrList_size[2])
{
  const mxArray *y;
  const mxArray *m16;
  static const int32_T iv16[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  char_T errStr_data[1024];
  uint8_T addr_null[2];
  char * addr_c;
  UsrpErrorCapiEnumT errStat_i;
  int32_T flatAddrListSize;
  const mxArray *m17;
  static const int32_T iv17[2] = { 1, 9 };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /* getSDRuList Report all USRP (R) devices connected to the host computer */
  /*    A = getSDRuList() returns a comma delimited list of IP addresses, A, */
  /*    that belong to USRP(R) devices connected to the host computer. */
  /*     */
  /*    % Example:  */
  /*    %   Create a cell array list of USRP(R) IP addresses */
  /*  */
  /*    % Discover all USRP(R) devices */
  /*    rawDeviceList = getSDRuList(); */
  /*    % Remove zeros from the end and use ',' as a token */
  /*    deviceList = [',' rawDeviceList(rawDeviceList~=0)]; */
  /*    tokIdx = [strfind(deviceList, ',') length(deviceList)+1]; */
  /*    usrpIP = cell(length(tokIdx) - 1, 1); */
  /*    for p=1:length(tokIdx)-1 */
  /*      usrpIP{p} = deviceList(tokIdx(p)+1:tokIdx(p+1)-1); */
  /*    end */
  /*    usrpIP */
  /*  */
  /*    USRP is a trademark of National Instruments Corp. */
  /*    Copyright 2012 The MathWorks, Inc. */
  st.site = &cb_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    y = NULL;
    m16 = emlrtCreateCharArray(2, iv16);
    emlrtInitCharArrayR2013a(&st, 6, m16, &u[0]);
    emlrtAssign(&y, m16);
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
  addr_null[0] = 0U;
  addr_null[1] = 0U;
  addr_c = (char *)(addr_null);
  flatAddrList_size[0] = 1;
  memset(&flatAddrList_data[0], 0, 3000U * sizeof(char_T));
  getSDRuList_c(addr_c, &flatAddrList_data[0], &errStat_i, &errStr_data[0]);
  flatAddrListSize = strlen(&flatAddrList_data[0]);
  if (flatAddrListSize > 3000) {
    emlrtErrorWithMessageIdR2018a(&st, &q_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > flatAddrListSize) {
    flatAddrList_size[1] = 0;
  } else {
    flatAddrList_size[1] = flatAddrListSize;
  }

  y = NULL;
  m17 = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(&st, 9, m17, &cv2[0]);
  emlrtAssign(&y, m17);
  b_st.site = &mb_emlrtRSI;
  drawnow(&b_st, y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  flatAddrListSize = strlen(&errStr_data[0]);
  if (flatAddrListSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }
}

/* End of code generation (getSDRuList.c) */
