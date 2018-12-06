/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SDRuReceiver.h
 *
 * Code generation for function 'SDRuReceiver'
 *
 */

#ifndef SDRURECEIVER_H
#define SDRURECEIVER_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "run_usrp_rx_types.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"

/* Function Declarations */
extern comm_SDRuReceiver *SDRuReceiver_SDRuReceiver(const emlrtStack *sp,
  comm_SDRuReceiver *obj);
extern void SDRuReceiver_setupImplLocal(const emlrtStack *sp, comm_SDRuReceiver *
  obj, UsrpErrorCapiEnumT *deviceStatus, char_T errMsg_data[], int32_T
  errMsg_size[2]);
extern void SDRuReceiver_stepImpl(run_usrp_rxStackData *SD, const emlrtStack *sp,
  const comm_SDRuReceiver *obj, creal_T y[156800], uint32_T *dataLen);

#endif

/* End of code generation (SDRuReceiver.h) */
