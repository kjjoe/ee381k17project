/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_run_usrp_tx_api.c
 *
 * Code generation for function '_coder_run_usrp_tx_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "_coder_run_usrp_tx_api.h"
#include "run_usrp_tx_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[15680]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[15680]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *frame_to_send,
  const char_T *identifier, creal_T y[15680]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[15680])
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[15680])
{
  static const int32_T dims[2] = { 7840, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *frame_to_send,
  const char_T *identifier, creal_T y[15680])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(frame_to_send), &thisId, y);
  emlrtDestroyArray(&frame_to_send);
}

void run_usrp_tx_api(run_usrp_txStackData *SD, const mxArray * const prhs[2],
                     int32_T nlhs)
{
  int32_T iv24[1];
  static const char * sv0[1] = { "sys_params_tx" };

  static const uint32_T uv0[4] = { 3686791558U, 1740550047U, 2918583036U,
    1412096941U };

  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check constant function inputs */
  iv24[0] = 4;
  emlrtCheckArrayChecksumR2018b(&st, prhs[0], false, iv24, sv0, uv0);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "frame_to_send",
                   SD->f1.frame_to_send);

  /* Invoke the target function */
  run_usrp_tx(SD, &st, SD->f1.frame_to_send);
}

/* End of code generation (_coder_run_usrp_tx_api.c) */
