#include "s21_other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    *result = value;
    set_bitt(result, 3, (((unsigned)(result->bits[3]) >> 31) + 1) % 2, 31);
  }
  return error;
}