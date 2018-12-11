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
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "SystemCore.h"
#include "warning.h"
#include "reportDrivers.h"
#include "mapiPrivate.h"
#include "SDRuReceiver.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 6,  /* lineNo */
  "closeDataConnection",               /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/closeDataConnection.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "SystemCore",                        /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 50,/* lineNo */
  22,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 67,/* lineNo */
  15,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 78,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 98,/* lineNo */
  13,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 107,/* lineNo */
  62,                                  /* colNo */
  "reportSDRuStatus",                  /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/reportSDRuStatus.m"/* pName */
};

/* Function Declarations */
static void SystemCore_setupAndReset(const emlrtStack *sp, comm_SDRuReceiver
  *obj);

/* Function Definitions */
static void SystemCore_setupAndReset(const emlrtStack *sp, comm_SDRuReceiver
  *obj)
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
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
  }

  obj->isInitialized = 1;
  b_st.site = &f_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  SDRuReceiver_setupImplLocal(&c_st, obj, &deviceStatus, errMsg_data,
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
      emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
        "sdru:reportSDRuStatus:NotCompatible",
        "sdru:reportSDRuStatus:NotCompatible", 6, 4, 25,
        "192.168.10.2,192.168.10.3", 4, 43,
        "returned by \'getSDRuDriverVersion\' function");
    }
    break;

   case UsrpDriverNotResponding:
    if (deviceStatus == UsrpDriverNotResponding) {
      emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
        "sdru:reportSDRuStatus:NotResponding",
        "sdru:reportSDRuStatus:NotResponding", 3, 4, 25,
        "192.168.10.2,192.168.10.3");
    }
    break;

   case UsrpDriverRxBusy:
    if (deviceStatus == UsrpDriverRxBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
        "sdru:reportSDRuStatus:RxBusy", "sdru:reportSDRuStatus:RxBusy", 3, 4, 25,
        "192.168.10.2,192.168.10.3");
    }
    break;

   case UsrpDriverTxBusy:
    if (deviceStatus == UsrpDriverTxBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &n_emlrtRTEI,
        "sdru:reportSDRuStatus:TxBusy", "sdru:reportSDRuStatus:TxBusy", 3, 4, 25,
        "192.168.10.2,192.168.10.3");
    }
    break;

   case UsrpDriverBusy:
    if (deviceStatus == UsrpDriverBusy) {
      emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
        "sdru:reportSDRuStatus:Busy", "sdru:reportSDRuStatus:Busy", 3, 4, 25,
        "192.168.10.2,192.168.10.3");
    }
    break;

   case UsrpDriverError:
    if (deviceStatus == UsrpDriverError) {
      emlrtErrorWithMessageIdR2018a(&c_st, &p_emlrtRTEI,
        "sdru:reportSDRuStatus:UnknownStatus",
        "sdru:reportSDRuStatus:UnknownStatus", 3, 4, errMsg_size[1],
        &errMsg_data[0]);
    }
    break;
  }

  obj->isSetupComplete = true;
}

void SystemCore_release(const emlrtStack *sp, comm_SDRuReceiver *obj)
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

void SystemCore_releaseWrapper(const emlrtStack *sp, comm_SDRuReceiver *obj)
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

void SystemCore_step(run_usrp_rxStackData *SD, const emlrtStack *sp,
                     comm_SDRuReceiver *obj, creal_T varargout_1[156800],
                     uint32_T *varargout_2)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(sp, &j_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen",
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    st.site = &f_emlrtRSI;
    SystemCore_setupAndReset(&st, obj);
  }

  st.site = &f_emlrtRSI;
  SDRuReceiver_stepImpl(SD, &st, obj, varargout_1, varargout_2);
}

/* End of code generation (SystemCore.c) */
