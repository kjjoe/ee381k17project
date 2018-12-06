/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_tx.h
 *
 * Code generation for function 'run_usrp_tx'
 *
 */

#ifndef RUN_USRP_TX_H
#define RUN_USRP_TX_H

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
extern void run_usrp_tx(run_usrp_txStackData *SD, const emlrtStack *sp, const
  creal_T frame_to_send[15680]);
extern void run_usrp_tx_free(const emlrtStack *sp);
extern void run_usrp_tx_init(void);

#endif

/* End of code generation (run_usrp_tx.h) */
