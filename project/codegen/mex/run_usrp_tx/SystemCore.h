/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

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

/* Function Declarations */
extern void SystemCore_release(const emlrtStack *sp, comm_SDRuTransmitter *obj);
extern void SystemCore_releaseWrapper(const emlrtStack *sp, comm_SDRuTransmitter
  *obj);
extern void SystemCore_step(run_usrp_txStackData *SD, const emlrtStack *sp,
  comm_SDRuTransmitter *obj, const creal_T varargin_1[15680]);

#endif

/* End of code generation (SystemCore.h) */
