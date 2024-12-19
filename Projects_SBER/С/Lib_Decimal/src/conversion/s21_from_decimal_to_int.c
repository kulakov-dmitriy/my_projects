#include "s21_conversion.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0, sign = get_sign(src.bits[3]);
  if ((dst == NULL) || (src.bits[1] + src.bits[2] != 0) ||
      (get_sign(src.bits[0]) == 1 && sign == 0) ||
      (unsigned)src.bits[0] >= 2147483649) {
    error = 1;
  } else {
    *dst = src.bits[0];
    if (sign) {
      *dst *= -1;
    }
  }
  return error;
}