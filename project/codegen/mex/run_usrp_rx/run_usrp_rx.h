/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx.h
 *
 * Code generation for function 'run_usrp_rx'
 *
 */

#ifndef RUN_USRP_RX_H
#define RUN_USRP_RX_H

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
extern void run_usrp_rx(run_usrp_rxStackData *SD, const emlrtStack *sp, creal_T
  rx_sig_all[156800]);
extern void run_usrp_rx_free(const emlrtStack *sp);
extern void run_usrp_rx_init(void);

#endif

/* End of code generation (run_usrp_rx.h) */
