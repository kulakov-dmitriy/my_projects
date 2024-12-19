#include "s21_other.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  int error = 0;
  s21_my_decimal num = {0}, num10 = {{10, 0, 0, 0, 0, 0}, 0, 0},
                 num1 = {{1, 0, 0, 0, 0, 0}, 0, 0}, res = {0}, remainder = {0};
  for (int i = 0; i < 3; i++) {
    num.bits[i] = value.bits[i];
  }
  int sign = get_sign(value.bits[3]);
  int point_pos = get_degree(value.bits[3]);
  int bit = 0;
  if (s21_is_zero(num)) {
    decimal_zero(result);
  } else if (point_pos < 0 || point_pos > 28) {
    error = 1;
  } else {
    for (; point_pos > 0; point_pos--) {
      remainder = s21_div_main(num, num10, &res);
      num = res;
      my_decimal_zero(&res);
    }
    if (remainder.bits[0] >= 5) {
      my_decimal_zero(&res);
      s21_add_main(num, num1, &res, &bit);
      num = res;
    }
    num.point_pos = point_pos;
    num.sign = sign;
    s21_convert_my_dec_to_result(result, num);
  }
  return error;
}