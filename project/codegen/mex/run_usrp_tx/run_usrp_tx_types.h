/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * run_usrp_tx_types.h
 *
 * Code generation for function 'run_usrp_tx'
 *
 */

#ifndef RUN_USRP_TX_TYPES_H
#define RUN_USRP_TX_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#include "usrp_uhd_capi.hpp"
#ifndef typedef_comm_SDRuTransmitter
#define typedef_comm_SDRuTransmitter

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
  real_T InterpolationFactor;
} comm_SDRuTransmitter;

#endif                                 /*typedef_comm_SDRuTransmitter*/

#ifndef typedef_run_usrp_txStackData
#define typedef_run_usrp_txStackData

typedef struct {
  struct {
    creal_T varargin_1[15680];
  } f0;

  struct {
    creal_T frame_to_send[15680];
  } f1;
} run_usrp_txStackData;

#endif                                 /*typedef_run_usrp_txStackData*/
#endif

/* End of code generation (run_usrp_tx_types.h) */
