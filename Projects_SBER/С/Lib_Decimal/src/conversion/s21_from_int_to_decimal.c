#include "s21_conversion.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst == NULL) {
    error = 1;
  } else {
    decimal_zero(dst);
    if (src < 0) {
      dst->bits[3] = (unsigned)get_sign(src) << 31;
      src *= -1;
    }
    dst->bits[0] = src;
  }
  return error;
}