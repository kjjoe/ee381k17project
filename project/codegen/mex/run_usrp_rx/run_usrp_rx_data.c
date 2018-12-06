/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx_data.c
 *
 * Code generation for function 'run_usrp_rx_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
boolean_T isSetupsdruCalled;
const mxArray *eml_mx;
const mxArray *b_eml_mx;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "run_usrp_rx",                       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 1359525326U, 1794498124U, 1706448398U, 1131923105U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo e_emlrtRSI = { 1,          /* lineNo */
  "SystemProp",                        /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"/* pathName */
};

emlrtRSInfo f_emlrtRSI = { 1,          /* lineNo */
  "SystemCore",                        /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"/* pathName */
};

emlrtRSInfo m_emlrtRSI = { 1,          /* lineNo */
  "SDRuBase",                          /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/+comm/+internal/SDRuBase.p"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 53,         /* lineNo */
  "checkIPAddressFormat",              /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkIPAddressFormat.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 12,         /* lineNo */
  "any",                               /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/ops/any.m"/* pathName */
};

emlrtMCInfo c_emlrtMCI = { 27,         /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/lang/error.m"/* pName */
};

emlrtMCInfo d_emlrtMCI = { 19,         /* lineNo */
  15,                                  /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

emlrtMCInfo e_emlrtMCI = { 19,         /* lineNo */
  5,                                   /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

emlrtMCInfo f_emlrtMCI = { 282,        /* lineNo */
  5,                                   /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

emlrtRTEInfo h_emlrtRTEI = { 286,      /* lineNo */
  5,                                   /* colNo */
  "mapiPrivate",                       /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pName */
};

const boolean_T bv0[25] = { false, false, false, false, false, false, false,
  false, false, false, false, false, true, false, false, false, false, false,
  false, false, false, false, false, false, false };

const char_T cv0[25] = { '1', '9', '2', '.', '1', '6', '8', '.', '1', '0', '.',
  '3', ',', '1', '9', '2', '.', '1', '6', '8', '.', '1', '0', '.', '2' };

const char_T cv1[35] = { 's', 'd', 'r', 'u', ':', 'r', 'e', 'p', 'o', 'r', 't',
  'S', 'D', 'R', 'u', 'S', 't', 'a', 't', 'u', 's', ':', 'U', 'n', 'k', 'n', 'o',
  'w', 'n', 'S', 't', 'a', 't', 'u', 's' };

const char_T cv2[9] = { 'l', 'i', 'm', 'i', 't', 'r', 'a', 't', 'e' };

emlrtRSInfo kb_emlrtRSI = { 27,        /* lineNo */
  "error",                             /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/eml/lib/matlab/lang/error.m"/* pathName */
};

emlrtRSInfo lb_emlrtRSI = { 19,        /* lineNo */
  "mapiPrivate",                       /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pathName */
};

emlrtRSInfo mb_emlrtRSI = { 282,       /* lineNo */
  "mapiPrivate",                       /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/usrp_uhd_mapi/mapiPrivate.m"/* pathName */
};

/* End of code generation (run_usrp_rx_data.c) */
