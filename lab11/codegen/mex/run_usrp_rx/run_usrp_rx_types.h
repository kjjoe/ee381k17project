/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_rx_types.h
 *
 * Code generation for function 'run_usrp_rx'
 *
 */

#ifndef RUN_USRP_RX_TYPES_H
#define RUN_USRP_RX_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"
#ifndef typedef_comm_SDRuReceiver
#define typedef_comm_SDRuReceiver

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T CenterFrequency;
  real_T LocalOscillatorOffset;
  real_T Gain;
  boolean_T pConnected;
  int32_T pDriverHandle;
  BoardIdCapiEnumT pSubDevice;
  char_T ObjectID[15];
  real_T DecimationFactor;
} comm_SDRuReceiver;

#endif                                 /*typedef_comm_SDRuReceiver*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef typedef_run_usrp_rxStackData
#define typedef_run_usrp_rxStackData

typedef struct {
  struct {
    cint16_T yTemp[375000];
  } f0;

  struct {
    creal_T rx_sig_temp[156800];
  } f1;

  struct {
    creal_T rx_sig_all[156800];
  } f2;
} run_usrp_rxStackData;

#endif                                 /*typedef_run_usrp_rxStackData*/
#endif

/* End of code generation (run_usrp_rx_types.h) */
