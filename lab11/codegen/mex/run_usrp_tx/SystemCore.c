/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "SystemCore.h"
#include "warning.h"
#include "reportDrivers.h"
#include "mapiPrivate.h"
#include "SDRuTransmitter.h"
#include "run_usrp_tx_mexutil.h"
#include "run_usrp_tx_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 6,  /* lineNo */
  "closeDataConnection",               /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/closeDataConnection.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 9,  /* lineNo */
  "sendComplexDoubleData",             /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/sendComplexDoubleData.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 50,/* lineNo */
  22,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 67,/* lineNo */
  15,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 78,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 98,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 107,/* lineNo */
  62,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

/* Function Declarations */
static void SystemCore_setupAndReset(const emlrtStack *sp, comm_SDRuTransmitter *
  obj);

/* Function Definitions */
static void SystemCore_setupAndReset(const emlrtStack *sp, comm_SDRuTransmitter *
  obj)
{
  UsrpErrorCapiEnumT deviceStatus;
  char_T errMsg_data[1024];
  int32_T errMsg_size[2];
  int32_T driverApiH;
  UsrpErrorCapiEnumT errStat;
  char_T errStr_data[1024];
  int32_T errStr_size[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  obj->isSetupComplete = false;
  if (obj->isInitialized != 0) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
  }

  obj->isInitialized = 1;
  b_st.site = &f_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  SDRuTransmitter_setupImplLocal(&c_st, obj, &deviceStatus, errMsg_data,
    errMsg_size);
  if (deviceStatus == UsrpDriverSuccess) {
    obj->pConnected = true;
  } else {
    c_st.site = &m_emlrtRSI;
    driverApiH = obj->pDriverHandle;

    /*    Copyright 2011-2012 The MathWorks, Inc. */
    d_st.site = &eb_emlrtRSI;
    mapiPrivate(&d_st, driverApiH, &errStat, errStr_data, errStr_size);
    obj->pConnected = false;
  }

  c_st.site = &m_emlrtRSI;

  /* reportSDRuStatus SDRu status reporter */
  /*    reportSDRuStatus(STATUS,MSG,IP,METHOD) reports the SDRu status based on */
  /*    the STATUS input. STATUS is a UsrpErrorCapiEnumT type. IP is the IP */
  /*    address of the USRP(R) radio. METHOD is a UsrpReportMethodEnumT type and */
  /*    can be Warning, Error , or None. */
  /*  */
  /*    USRP(R) is a trademark of National Instruments Corp. */
  /*    Copyright 2012-2014 The MathWorks, Inc. */
  switch (deviceStatus) {
   case UsrpDriverNotCompatible:
    if (deviceStatus == UsrpDriverNotCompatible) {
      emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
        "sdru:reportSDRuStatus:NotCompatible",
        "sdru:reportSDRuStatus:NotCompatible", 6, 4, 25,
        "192.168.10.3,192.168.10.2", 4, 43,
        "returned by \'getSDRuDriverVersion\' function");
    }
    break;

   case UsrpDriverNotResponding:
    if (deviceStatus == UsrpDriverNotResponding) {
      emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
        "sdru:reportSDRuStatus:NotResponding",
        "sdru:reportSDRuStatus:NotResponding", 3, 4, 25,
        "192.168.10.3,192.168.10.2");
    }
    break;

   case UsrpDriverRxBusy:
    if (deviceStatus == UsrpDriverRxBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
        "sdru:reportSDRuStatus:RxBusy", "sdru:reportSDRuStatus:RxBusy", 3, 4, 25,
        "192.168.10.3,192.168.10.2");
    }
    break;

   case UsrpDriverTxBusy:
    if (deviceStatus == UsrpDriverTxBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
        "sdru:reportSDRuStatus:TxBusy", "sdru:reportSDRuStatus:TxBusy", 3, 4, 25,
        "192.168.10.3,192.168.10.2");
    }
    break;

   case UsrpDriverBusy:
    if (deviceStatus == UsrpDriverBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
        "sdru:reportSDRuStatus:Busy", "sdru:reportSDRuStatus:Busy", 3, 4, 25,
        "192.168.10.3,192.168.10.2");
    }
    break;

   case UsrpDriverError:
    if (deviceStatus == UsrpDriverError) {
      emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI,
        "sdru:reportSDRuStatus:UnknownStatus",
        "sdru:reportSDRuStatus:UnknownStatus", 3, 4, errMsg_size[1],
        &errMsg_data[0]);
    }
    break;
  }

  obj->isSetupComplete = true;
}

void SystemCore_release(const emlrtStack *sp, comm_SDRuTransmitter *obj)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
    st.site = &f_emlrtRSI;
    SystemCore_releaseWrapper(&st, obj);
  }
}

void SystemCore_releaseWrapper(const emlrtStack *sp, comm_SDRuTransmitter *obj)
{
  boolean_T disconnected;
  UsrpErrorCapiEnumT errStatus;
  char_T errStr_data[1024];
  int32_T errStr_size[2];
  char_T tmp_data[3000];
  int32_T tmp_size[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (obj->isSetupComplete) {
    st.site = &f_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    disconnected = true;
    if (obj->pConnected) {
      c_st.site = &m_emlrtRSI;

      /*    Copyright 2011-2012 The MathWorks, Inc. */
      d_st.site = &eb_emlrtRSI;
      mapiPrivate(&d_st, obj->pDriverHandle, &errStatus, errStr_data,
                  errStr_size);
      if (errStatus == UsrpDriverSuccess) {
        obj->pDriverHandle = 0;
      } else {
        c_st.site = &m_emlrtRSI;
        reportDrivers(&c_st, tmp_data, tmp_size);
        if ((int16_T)tmp_size[1] != 0) {
          disconnected = false;
          c_st.site = &m_emlrtRSI;
          warning(&c_st, errStr_data, errStr_size);
        }
      }

      obj->pConnected = !disconnected;
    }
  }
}

void SystemCore_step(run_usrp_txStackData *SD, const emlrtStack *sp,
                     comm_SDRuTransmitter *obj, const creal_T varargin_1[15680])
{
  real_T a;
  real_T fc[2];
  real_T loOffset[2];
  boolean_T y;
  int32_T errStrSize;
  boolean_T exitg1;
  real_T gain[2];
  const mxArray *b_y;
  const mxArray *m14;
  static const int32_T iv13[2] = { 1, 35 };

  const mxArray *c_y;
  const mxArray *m15;
  static const int32_T iv14[2] = { 1, 66 };

  static const char_T varargin_2[66] = { 'L', 'o', 'c', 'a', 'l', 'O', 's', 'c',
    'i', 'l', 'l', 'a', 't', 'o', 'r', 'O', 'f', 'f', 's', 'e', 't', ' ', 'm',
    'u', 's', 't', ' ', 'b', 'e', ' ', 'z', 'e', 'r', 'o', ' ', 'w', 'h', 'e',
    'n', ' ', 'm', 'u', 'l', 't', 'i', 'p', 'l', 'e', ' ', 'c', 'h', 'a', 'n',
    'n', 'e', 'l', 's', ' ', 'a', 'r', 'e', ' ', 'u', 's', 'e', 'd' };

  const mxArray *m16;
  static const int32_T iv15[2] = { 1, 6 };

  static const char_T u[6] = { 's', 'i', 'l', 'e', 'n', 't' };

  int32_T errStr_size[2];
  char_T errStr_data[1024];
  uint32_T underflow;
  UsrpErrorCapiEnumT errStatus;
  const mxArray *m17;
  static const int32_T iv16[2] = { 1, 9 };

  const mxArray *m18;
  static const int32_T iv17[2] = { 1, 41 };

  static const char_T b_varargin_1[41] = { 's', 'd', 'r', 'u', ':', 'S', 'D',
    'R', 'u', 'T', 'r', 'a', 'n', 's', 'm', 'i', 't', 't', 'e', 'r', ':', 'T',
    'r', 'a', 'n', 's', 'm', 'i', 't', 'U', 'n', 's', 'u', 'c', 'c', 'e', 's',
    's', 'f', 'u', 'l' };

  const mxArray *m19;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(sp, &h_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    st.site = &f_emlrtRSI;
    SystemCore_setupAndReset(&st, obj);
  }

  st.site = &f_emlrtRSI;
  a = obj->CenterFrequency;
  fc[0] = a;
  fc[1] = a;
  a = obj->LocalOscillatorOffset;
  loOffset[0] = a;
  loOffset[1] = a;
  y = true;
  errStrSize = 0;
  exitg1 = false;
  while ((!exitg1) && (errStrSize < 2)) {
    if (!(a == 0.0)) {
      y = false;
      exitg1 = true;
    } else {
      errStrSize++;
    }
  }

  if (!y) {
    b_st.site = &l_emlrtRSI;
    b_y = NULL;
    m14 = emlrtCreateCharArray(2, iv13);
    emlrtInitCharArrayR2013a(&b_st, 35, m14, &cv1[0]);
    emlrtAssign(&b_y, m14);
    c_y = NULL;
    m15 = emlrtCreateCharArray(2, iv14);
    emlrtInitCharArrayR2013a(&b_st, 66, m15, &varargin_2[0]);
    emlrtAssign(&c_y, m15);
    c_st.site = &kb_emlrtRSI;
    b_error(&c_st, b_y, c_y, &c_emlrtMCI);
  }

  a = obj->Gain;
  gain[0] = a;
  gain[1] = a;
  a = obj->InterpolationFactor;
  b_st.site = &l_emlrtRSI;
  errStrSize = obj->pDriverHandle;

  /*  bug: must pass as top-level arg */
  /*  dportDtype = DataPortDataTypeCapiEnumT.DPortDTypeCDouble; */
  /*    Copyright 2011-2012 The MathWorks, Inc. */
  c_st.site = &fb_emlrtRSI;

  /*  */
  /*  This function unifies handling of interp vs. codegen call as well as */
  /*  errStat / errStr assignment. */
  /*  */
  /*    Copyright 2011-2016 The MathWorks, Inc. */
  if (!isSetupsdruCalled) {
    b_y = NULL;
    m16 = emlrtCreateCharArray(2, iv15);
    emlrtInitCharArrayR2013a(&c_st, 6, m16, &u[0]);
    emlrtAssign(&b_y, m16);
    d_st.site = &lb_emlrtRSI;
    setupsdru(&d_st, sdruroot(&d_st, &d_emlrtMCI), b_y, &e_emlrtMCI);
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
  memcpy(&SD->f0.varargin_1[0], &varargin_1[0], 15680U * sizeof(creal_T));
  sendData_c(errStrSize, SD->f0.varargin_1, fc, loOffset, gain, a, &underflow,
             &errStatus, &errStr_data[0]);
  b_y = NULL;
  m17 = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(&c_st, 9, m17, &cv2[0]);
  emlrtAssign(&b_y, m17);
  d_st.site = &mb_emlrtRSI;
  drawnow(&d_st, b_y, &f_emlrtMCI);

  /* errStat = UsrpErrorCapiEnumT(errStat_i); */
  errStrSize = strlen(&errStr_data[0]);
  if (errStrSize > 1024) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > errStrSize) {
    errStr_size[1] = 0;
  } else {
    errStr_size[1] = errStrSize;
  }

  if (errStatus != UsrpDriverSuccess) {
    b_st.site = &l_emlrtRSI;
    b_y = NULL;
    m18 = emlrtCreateCharArray(2, iv17);
    emlrtInitCharArrayR2013a(&b_st, 41, m18, &b_varargin_1[0]);
    emlrtAssign(&b_y, m18);
    c_y = NULL;
    m19 = emlrtCreateCharArray(2, errStr_size);
    emlrtInitCharArrayR2013a(&b_st, errStr_size[1], m19, &errStr_data[0]);
    emlrtAssign(&c_y, m19);
    c_st.site = &kb_emlrtRSI;
    b_error(&c_st, b_y, c_y, &c_emlrtMCI);
  }
}

/* End of code generation (SystemCore.c) */
