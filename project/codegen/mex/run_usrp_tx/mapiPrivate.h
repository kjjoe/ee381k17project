/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mapiPrivate.h
 *
 * Code generation for function 'mapiPrivate'
 *
 */

#ifndef MAPIPRIVATE_H
#define MAPIPRIVATE_H

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
extern void mapiPrivate(const emlrtStack *sp, int32_T varargin_1,
  UsrpErrorCapiEnumT *varargout_1, char_T varargout_2_data[], int32_T
  varargout_2_size[2]);
extern void mapiPrivate_init(void);

#endif

/* End of code generation (mapiPrivate.h) */
