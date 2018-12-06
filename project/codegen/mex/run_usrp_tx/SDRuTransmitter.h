/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDRuTransmitter.h
 *
 * Code generation for function 'SDRuTransmitter'
 *
 */

#ifndef SDRUTRANSMITTER_H
#define SDRUTRANSMITTER_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "run_usrp_tx_types.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"

/* Function Declarations */
extern comm_SDRuTransmitter *SDRuTransmitter_SDRuTransmitter(const emlrtStack
  *sp, comm_SDRuTransmitter *obj);
extern void SDRuTransmitter_setupImplLocal(const emlrtStack *sp,
  comm_SDRuTransmitter *obj, UsrpErrorCapiEnumT *errStatus, char_T errMsg_data[],
  int32_T errMsg_size[2]);

#endif

/* End of code generation (SDRuTransmitter.h) */
