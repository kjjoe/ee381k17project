/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemProp.c
 *
 * Code generation for function 'SystemProp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_tx.h"
#include "SystemProp.h"
#include "warning.h"
#include "reportDrivers.h"
#include "deleteDriver.h"
#include "run_usrp_tx_data.h"

/* Function Definitions */
void c_SystemProp_matlabCodegenSetAn(const emlrtStack *sp, comm_SDRuTransmitter *
  obj)
{
  boolean_T disconnected;
  UsrpErrorCapiEnumT errStatus;
  char_T errMsg_data[1024];
  int32_T errMsg_size[2];
  char_T tmp_data[3000];
  int32_T tmp_size[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (obj->pConnected) {
    b_st.site = &m_emlrtRSI;
    c_st.site = &m_emlrtRSI;
    disconnected = true;
    if (obj->pConnected) {
      d_st.site = &m_emlrtRSI;
      deleteDriver(&d_st, obj->pDriverHandle, &errStatus, errMsg_data,
                   errMsg_size);
      if (errStatus == UsrpDriverSuccess) {
        obj->pDriverHandle = 0;
      } else {
        d_st.site = &m_emlrtRSI;
        reportDrivers(&d_st, tmp_data, tmp_size);
        if ((int16_T)tmp_size[1] != 0) {
          disconnected = false;
          d_st.site = &m_emlrtRSI;
          warning(&d_st, errMsg_data, errMsg_size);
        }
      }

      obj->pConnected = !disconnected;
    }
  }
}

/* End of code generation (SystemProp.c) */
