/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_tx.c
 *
 * Code generation for function 'run_usrp_tx'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "SystemCore.h"
#include "SDRuTransmitter.h"
#include "run_usrp_tx_data.h"

/* Variable Definitions */
static comm_SDRuTransmitter tx_radio;
static boolean_T tx_radio_not_empty;
static emlrtRSInfo emlrtRSI = { 19,    /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 40,  /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 45,  /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 1,  /* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "/Applications/MATLAB_R2018b.app/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 16, /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 36,    /* lineNo */
  9,                                   /* colNo */
  "run_usrp_tx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 44,  /* lineNo */
  9,                                   /* colNo */
  "run_usrp_tx",                       /* fName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pName */
};

static emlrtRSInfo ib_emlrtRSI = { 44, /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 36, /* lineNo */
  "run_usrp_tx",                       /* fcnName */
  "/Users/kj23458/Dropbox/UT Austin/EE 381K/ee381k17project/project/Libs/InterfaceFunctions/run_usrp_tx.m"/* pathName */
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

void run_usrp_tx(run_usrp_txStackData *SD, const emlrtStack *sp, const creal_T
                 frame_to_send[15680])
{
  int32_T frame_id;
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv2[2] = { 1, 47 };

  static const char_T u[47] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*',
    ' ', 'S', 't', 'a', 'r', 't', ' ', 't', 'r', 'a', 'n', 's', 'm', 'i', 't',
    't', 'i', 'n', 'g', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*' };

  const mxArray *m3;
  static const int32_T iv3[2] = { 1, 46 };

  static const char_T b_u[46] = { '*', '*', '*', '*', '*', '*', '*', '*', '*',
    '*', ' ', 'S', 't', 'o', 'p', ' ', 't', 'r', 'a', 'n', 's', 'm', 'i', 't',
    't', 'i', 'n', 'g', ' ', 's', 'i', 'g', 'n', 'a', 'l', ' ', '*', '*', '*',
    '*', '*', '*', '*', '*', '*', '*' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  run_usrp_tx.m */
  /*  function run_usrp_tx(sys_params_tx,frame_to_send)  */
  /*  */
  /*  This function allows creating an interface function for a transmitter */
  /*  USRP and further feed the data to it for transmission */
  /*  */
  /*  Created August 30, 2018  */
  /*  Robert W. Heath Jr. */
  /*  Yi Zhang */
  /*  The University of Texas at Austin */
  /*  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  if (!tx_radio_not_empty) {
    /*  Create the interface function to control the Tx USRP  */
    st.site = &emlrtRSI;
    SDRuTransmitter_SDRuTransmitter(&st, &tx_radio);
    tx_radio_not_empty = true;

    /* coder.varsize('tx_radio.ChannelMapping'); */
    /* tx_radio.ChannelMapping =  sys_params_tx.usrp_channelmapping; */
    /* set(tx_radio,'ChannelMapping',sys_params_tx.usrp_channelmapping); */
    /*  Initialize the number of frame to be sent */
    frame_id = 1;

    /*  Transmitting signal */
    y = NULL;
    m2 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(sp, 47, m2, &u[0]);
    emlrtAssign(&y, m2);
    st.site = &jb_emlrtRSI;
    disp(&st, y, &emlrtMCI);
    while (frame_id <= 300000) {
      /*  Feed one frame to the USRP device and the frame is */
      /*  automatically transmitted by the USRP device */
      st.site = &b_emlrtRSI;
      SystemCore_step(SD, &st, &tx_radio, frame_to_send);

      /*  Update the number of next frame to be transmitted */
      frame_id++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(sp, 46, m3, &b_u[0]);
    emlrtAssign(&y, m3);
    st.site = &ib_emlrtRSI;
    disp(&st, y, &b_emlrtMCI);
    st.site = &c_emlrtRSI;
    SystemCore_release(&st, &tx_radio);
  }
}

void run_usrp_tx_free(const emlrtStack *sp)
{
  comm_SDRuTransmitter *obj;
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
  obj = &tx_radio;
  if (!tx_radio.matlabCodegenIsDeleted) {
    tx_radio.matlabCodegenIsDeleted = true;
    b_st.site = &gb_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    if (tx_radio.isInitialized == 1) {
      tx_radio.isInitialized = 2;
      d_st.site = &f_emlrtRSI;
      SystemCore_releaseWrapper(&d_st, obj);
    }
  }
}

void run_usrp_tx_init(void)
{
  tx_radio_not_empty = false;
  tx_radio.matlabCodegenIsDeleted = true;
}

/* End of code generation (run_usrp_tx.c) */
