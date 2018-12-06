/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx.c
 *
 * Code generation for function 'run_usrp_rx'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "SystemCore.h"
#include "run_usrp_rx_emxutil.h"
#include "SDRuReceiver.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static comm_SDRuReceiver rx_radio;
static boolean_T rx_radio_not_empty;
static emlrtRSInfo emlrtRSI = { 59,    /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 46,  /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 23,  /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 1,  /* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 20, /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 41,    /* lineNo */
  9,                                   /* colNo */
  "run_usrp_rx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 58,  /* lineNo */
  9,                                   /* colNo */
  "run_usrp_rx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 17,  /* lineNo */
  5,                                   /* colNo */
  "run_usrp_rx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 46,/* lineNo */
  18,                                  /* colNo */
  "run_usrp_rx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  49,                                  /* lineNo */
  13,                                  /* colNo */
  "run_usrp_rx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pName */
};

static emlrtRSInfo ib_emlrtRSI = { 58, /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 41, /* lineNo */
  "run_usrp_rx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_rx.m"/* pathName */
};

/* Function Declarations */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
}

void run_usrp_rx(run_usrp_rxStackData *SD, const emlrtStack *sp, creal_T
                 rx_sig_all[156800])
{
  emxArray_creal_T *rx_sig_temp;
  boolean_T b0;
  int32_T i0;
  int32_T frame_id;
  int32_T frames_to_ignore_id;
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv2[2] = { 1, 44 };

  static const char_T u[44] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
    ' ', 'S', 't', 'a', 'r', 't', ' ', 'r', 'e', 'c', 'e', 'i', 'v', 'i', 'n',
    'g', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*' };

  const mxArray *m3;
  static const int32_T iv3[2] = { 1, 43 };

  uint32_T len;
  static const char_T b_u[43] = { '*', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', ' ', 'S', 't', 'o', 'p', ' ', 'r', 'e', 'c', 'e', 'i', 'v', 'i', 'n',
    'g', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', '*', '*', '*', '*', '*', '*',
    '*', '*', '*', '*' };

  int32_T iv4[2];
  int32_T i1;
  int32_T rx_sig_all_tmp;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_creal_T(sp, &rx_sig_temp, 2, &emlrtRTEI, true);
  b0 = false;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  run_usrp_rx.m */
  /*  function rx_sig_all = run_usrp_rx(sys_params_rx)  */
  /*  */
  /*  This function allows creating an interface function for a receiver USRP  */
  /*  and further fetch the data received */
  /*  */
  /*  Created August 30, 2018  */
  /*  Robert W. Heath Jr. */
  /*  Yi Zhang */
  /*  The University of Texas at Austin */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Create the signal sink for storing the received signal */
  i0 = rx_sig_temp->size[0] * rx_sig_temp->size[1];
  rx_sig_temp->size[0] = 78400;
  rx_sig_temp->size[1] = 1;
  emxEnsureCapacity_creal_T(sp, rx_sig_temp, i0, &emlrtRTEI);
  for (i0 = 0; i0 < 78400; i0++) {
    rx_sig_temp->data[i0].re = 0.0;
    rx_sig_temp->data[i0].im = 0.0;
  }

  /*  Temporal signal sink */
  memset(&rx_sig_all[0], 0, 156800U * sizeof(creal_T));

  /*  Signal sink */
  if (!rx_radio_not_empty) {
    /*  Create the interface function to control the Rx USRP  */
    st.site = &c_emlrtRSI;
    SDRuReceiver_SDRuReceiver(&st, &rx_radio);
    rx_radio_not_empty = true;

    /*  Initialize the number of frame to be received */
    frame_id = 1;
    frames_to_ignore_id = 1;

    /*  Receving singal */
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(sp, 44, m2, &u[0]);
    emlrtAssign(&y, m2);
    st.site = &jb_emlrtRSI;
    disp(&st, y, &emlrtMCI);
    while (frame_id <= 1) {
      /* Fetch one frame from the USRP device */
      len = 0U;
      while (len <= 0U) {
        st.site = &b_emlrtRSI;
        SystemCore_step(SD, &st, &rx_radio, SD->f1.rx_sig_temp, &len);
        i0 = rx_sig_temp->size[0] * rx_sig_temp->size[1];
        rx_sig_temp->size[0] = 78400;
        rx_sig_temp->size[1] = 2;
        emxEnsureCapacity_creal_T(sp, rx_sig_temp, i0, &b_emlrtRTEI);
        for (i0 = 0; i0 < 156800; i0++) {
          rx_sig_temp->data[i0] = SD->f1.rx_sig_temp[i0];
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /*  Put the fetched frame into the signal sink */
      if (!b0) {
        iv4[0] = 78400;
        iv4[1] = 2;
        b0 = true;
      }

      emlrtSubAssignSizeCheckR2012b(&iv4[0], 2, &(*(int32_T (*)[2])
        rx_sig_temp->size)[0], 2, &emlrtECI, sp);
      for (i0 = 0; i0 < 2; i0++) {
        for (i1 = 0; i1 < 78400; i1++) {
          rx_sig_all_tmp = i1 + 78400 * i0;
          rx_sig_all[rx_sig_all_tmp] = rx_sig_temp->data[rx_sig_all_tmp];
        }
      }

      /*  Update the number of next frame to be received */
      if (frames_to_ignore_id < 100) {
        frames_to_ignore_id++;
      } else {
        frame_id = 2;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(sp, 43, m3, &b_u[0]);
    emlrtAssign(&y, m3);
    st.site = &ib_emlrtRSI;
    disp(&st, y, &b_emlrtMCI);
    st.site = &emlrtRSI;
    SystemCore_release(&st, &rx_radio);
  }

  emxFree_creal_T(&rx_sig_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void run_usrp_rx_free(const emlrtStack *sp)
{
  comm_SDRuReceiver *obj;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  obj = &rx_radio;
  if (!rx_radio.matlabCodegenIsDeleted) {
    rx_radio.matlabCodegenIsDeleted = true;
    b_st.site = &gb_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    if (rx_radio.isInitialized == 1) {
      rx_radio.isInitialized = 2;
      d_st.site = &f_emlrtRSI;
      SystemCore_releaseWrapper(&d_st, obj);
    }
  }
}

void run_usrp_rx_init(void)
{
  rx_radio_not_empty = false;
  rx_radio.matlabCodegenIsDeleted = true;
}

/* End of code generation (run_usrp_rx.c) */
