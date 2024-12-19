#include <math.h>

#include "s21_conversion.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double res;
  int scale, error = 0;
  long long temp_int = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    for (unsigned i = 0; i < 96; i++) {
      if ((src.bits[i / 32] & (1U << i % 32)) != 0) {
        temp_int += pow(2, i);
      }
    }
    res = temp_int;
    if ((scale = (src.bits[3] >> 16) & 255) > 0) {
      for (int i = scale; i > 0; i--) {
        res /= 10.0;
      }
    }
    if (src.bits[3] < 0) res *= -1;
    *dst = res;
  }
  return error;
}