/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkBundledIP.c
 *
 * Code generation for function 'checkBundledIP'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "checkBundledIP.h"
#include "strcmp.h"
#include "checkIPAddressFormat.h"
#include "getSDRuList.h"
#include "run_usrp_rx_data.h"

/* Variable Definitions */
static emlrtRSInfo ab_emlrtRSI = { 6,  /* lineNo */
  "checkBundledIP",                    /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 20, /* lineNo */
  "checkBundledIP",                    /* fcnName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m"/* pathName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  33,                                  /* colNo */
  "loc",                               /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  44,                                  /* colNo */
  "loc",                               /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  25,                                  /* iLast */
  19,                                  /* lineNo */
  29,                                  /* colNo */
  "IPAddress",                         /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  25,                                  /* iLast */
  19,                                  /* lineNo */
  40,                                  /* colNo */
  "IPAddress",                         /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  8,                                   /* colNo */
  "loc",                               /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  18,                                  /* colNo */
  "loc",                               /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  26,                                  /* lineNo */
  34,                                  /* colNo */
  "radiolist",                         /* aName */
  "checkBundledIP",                    /* fName */
  "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/checkBundledIP.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void checkBundledIP(const emlrtStack *sp, char_T ipNotFound_data[], int32_T
                    ipNotFound_size[2], char_T ipWrongPlatform_data[], int32_T
                    ipWrongPlatform_size[2])
{
  char_T radiolist_data[3000];
  int32_T radiolist_size[2];
  int32_T idx;
  int32_T match_idx;
  boolean_T exitg1;
  int32_T loc_size_idx_1;
  int8_T ii_data[25];
  int8_T loc_data[27];
  int32_T i;
  int32_T i10;
  boolean_T guard1 = false;
  int32_T ipAddr_size[2];
  int32_T ipAddr_size_tmp;
  char_T ipAddr_data[25];
  int16_T indx_data[3000];
  int32_T j;
  int16_T matches_data[3000];
  char_T radiolist[5];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*    Copyright 2016 The MathWorks, Inc. */
  st.site = &ab_emlrtRSI;
  getSDRuList(&st, radiolist_data, radiolist_size);
  ipNotFound_size[0] = 1;
  ipNotFound_size[1] = 0;
  ipWrongPlatform_size[0] = 1;
  ipWrongPlatform_size[1] = 0;
  idx = 0;
  match_idx = 0;
  exitg1 = false;
  while ((!exitg1) && (match_idx < 25)) {
    if (bv0[match_idx]) {
      idx++;
      ii_data[idx - 1] = (int8_T)(match_idx + 1);
      if (idx >= 25) {
        exitg1 = true;
      } else {
        match_idx++;
      }
    } else {
      match_idx++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  loc_size_idx_1 = 2 + idx;
  loc_data[0] = 0;
  if (0 <= idx - 1) {
    memcpy(&loc_data[1], &ii_data[0], (uint32_T)(idx * (int32_T)sizeof(int8_T)));
  }

  loc_data[1 + idx] = 26;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= loc_size_idx_1 - 2)) {
    i10 = 1 + i;
    if ((i10 < 1) || (i10 > loc_size_idx_1)) {
      emlrtDynamicBoundsCheckR2012b(i10, 1, loc_size_idx_1, &o_emlrtBCI, sp);
    }

    match_idx = i + 2;
    if ((match_idx < 1) || (match_idx > loc_size_idx_1)) {
      emlrtDynamicBoundsCheckR2012b(match_idx, 1, loc_size_idx_1, &p_emlrtBCI,
        sp);
    }

    guard1 = false;
    if (loc_data[i10 - 1] != loc_data[match_idx - 1] - 1) {
      i10 = 1 + i;
      if ((i10 < 1) || (i10 > loc_size_idx_1)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, loc_size_idx_1, &k_emlrtBCI, sp);
      }

      i10 = i + 2;
      if ((i10 < 1) || (i10 > loc_size_idx_1)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, loc_size_idx_1, &l_emlrtBCI, sp);
      }

      i10 = loc_data[i] + 1;
      match_idx = loc_data[i + 1] - 1;
      if (i10 > match_idx) {
        i10 = 0;
        match_idx = 0;
      } else {
        if ((i10 < 1) || (i10 > 25)) {
          emlrtDynamicBoundsCheckR2012b(i10, 1, 25, &m_emlrtBCI, sp);
        }

        i10--;
        if ((match_idx < 1) || (match_idx > 25)) {
          emlrtDynamicBoundsCheckR2012b(match_idx, 1, 25, &n_emlrtBCI, sp);
        }
      }

      ipAddr_size[0] = 1;
      ipAddr_size_tmp = match_idx - i10;
      ipAddr_size[1] = ipAddr_size_tmp;
      for (match_idx = 0; match_idx < ipAddr_size_tmp; match_idx++) {
        ipAddr_data[match_idx] = cv0[i10 + match_idx];
      }

      st.site = &bb_emlrtRSI;
      checkIPAddressFormat(&st, ipAddr_data, ipAddr_size);
      if ((radiolist_size[1] == 0) || (ipAddr_size_tmp == 0)) {
        match_idx = 0;
      } else {
        match_idx = 0;
        i10 = radiolist_size[1] - ipAddr_size_tmp;
        for (idx = 0; idx <= i10; idx++) {
          j = 1;
          while ((j <= ipAddr_size_tmp) && (radiolist_data[(idx + j) - 1] ==
                  ipAddr_data[j - 1])) {
            j++;
          }

          if (j > ipAddr_size_tmp) {
            matches_data[match_idx] = (int16_T)(idx + 1);
            match_idx++;
          }
        }

        if (0 <= match_idx - 1) {
          memcpy(&indx_data[0], &matches_data[0], (uint32_T)(match_idx *
                  (int32_T)sizeof(int16_T)));
        }
      }

      if (match_idx == 0) {
        ipNotFound_size[0] = 1;
        ipNotFound_size[1] = ipAddr_size_tmp;
        if (0 <= ipAddr_size_tmp - 1) {
          memcpy(&ipNotFound_data[0], &ipAddr_data[0], (uint32_T)
                 (ipAddr_size_tmp * (int32_T)sizeof(char_T)));
        }

        exitg1 = true;
      } else {
        idx = (indx_data[0] + ipAddr_size_tmp) + 1;
        for (i10 = 0; i10 < 5; i10++) {
          match_idx = i10 + idx;
          if ((match_idx < 1) || (match_idx > radiolist_size[1])) {
            emlrtDynamicBoundsCheckR2012b(match_idx, 1, radiolist_size[1],
              &q_emlrtBCI, sp);
          }

          radiolist[i10] = radiolist_data[match_idx - 1];
        }

        if (!b_strcmp(radiolist)) {
          ipWrongPlatform_size[0] = 1;
          ipWrongPlatform_size[1] = ipAddr_size_tmp;
          if (0 <= ipAddr_size_tmp - 1) {
            memcpy(&ipWrongPlatform_data[0], &ipAddr_data[0], (uint32_T)
                   (ipAddr_size_tmp * (int32_T)sizeof(char_T)));
          }

          exitg1 = true;
        } else {
          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }
}

/* End of code generation (checkBundledIP.c) */
