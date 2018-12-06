/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx_mexutil.h
 *
 * Code generation for function 'run_usrp_rx_mexutil'
 *
 */

#ifndef RUN_USRP_RX_MEXUTIL_H
#define RUN_USRP_RX_MEXUTIL_H

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

/* Function Declarations */
extern void d_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
extern void drawnow(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);
extern const mxArray *sdruroot(const emlrtStack *sp, emlrtMCInfo *location);
extern void setupsdru(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                      emlrtMCInfo *location);

#endif

/* End of code generation (run_usrp_rx_mexutil.h) */
