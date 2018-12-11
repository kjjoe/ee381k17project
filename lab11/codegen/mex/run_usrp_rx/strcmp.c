/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.c
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "run_usrp_rx.h"
#include "strcmp.h"

/* Function Definitions */
boolean_T b_strcmp(const char_T a[5])
{
  boolean_T b_bool;
  int32_T kstr;
  int32_T exitg1;
  static const char_T cv9[5] = { 'u', 's', 'r', 'p', '2' };

  b_bool = false;
  kstr = 0;
  do {
    exitg1 = 0;
    if (kstr < 5) {
      if (a[kstr] != cv9[kstr]) {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return b_bool;
}

/* End of code generation (strcmp.c) */
