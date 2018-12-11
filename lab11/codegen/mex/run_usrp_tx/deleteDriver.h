/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * deleteDriver.h
 *
 * Code generation for function 'deleteDriver'
 *
 */

#ifndef DELETEDRIVER_H
#define DELETEDRIVER_H

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
extern void deleteDriver(const emlrtStack *sp, int32_T driverApiH,
  UsrpErrorCapiEnumT *errStat, char_T errStr_data[], int32_T errStr_size[2]);

#endif

/* End of code generation (deleteDriver.h) */
