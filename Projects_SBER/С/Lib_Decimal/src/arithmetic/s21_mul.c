#include "s21_arithmetic.h"

int s21_mul_main(s21_my_decimal value_1, s21_my_decimal value_2,
                 s21_my_decimal *result) {
  s21_my_decimal res;
  int error = 0, bin = 0;
  while (value_2.bits[0] + value_2.bits[1] + value_2.bits[2] + value_2.bits[3] +
             value_2.bits[4] + value_2.bits[5] !=
         0) {
    if (get_bit(value_2.bits[0], 0) & 1) {
      res = *result;
      my_decimal_zero(result);
      s21_add_main(value_1, res, result, &bin);
    }
    shift_bit_left(&value_1);
    shift_bit_right(&value_2);
  }
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_my_decimal value1 = {0}, value2 = {0}, res = {0};
  convert_to_my_dec(value_1, value_2, &value1, &value2);
  int error = 0, sign = value1.sign + value2.sign == 1 ? 1 : 0;
  align_values(&value1, &value2);
  int point = value1.point_pos;
  s21_mul_main(value1, value2, &res);
  res.sign = sign;
  res.point_pos = point * 2;
  error = s21_convert_my_dec_to_result(result, res);
  if (s21_is_zero0(*result) || error != 0) decimal_zero(result);
  return error;
}

int mul_10(s21_my_decimal *value, int quantity) {
  s21_my_decimal num10 = {{10, 0, 0, 0, 0, 0}, 0, 0}, val = *value;
  int error = 0, point = value->point_pos;
  for (int i = 0; i < quantity; i++) {
    my_decimal_zero(value);
    s21_mul_main(val, num10, value);
    val = *value;
  }
  value->point_pos = point;
  return error;
}