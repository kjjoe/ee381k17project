/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkBundledIP.h
 *
 * Code generation for function 'checkBundledIP'
 *
 */

#ifndef CHECKBUNDLEDIP_H
#define CHECKBUNDLEDIP_H

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
extern void checkBundledIP(const emlrtStack *sp, char_T ipNotFound_data[],
  int32_T ipNotFound_size[2], char_T ipWrongPlatform_data[], int32_T
  ipWrongPlatform_size[2]);

#endif

/* End of code generation (checkBundledIP.h) */
