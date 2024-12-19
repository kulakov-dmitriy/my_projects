#include "s21_arithmetic.h"

void s21_sub_main(s21_my_decimal value_1, s21_my_decimal value_2,
                  s21_my_decimal *result) {
  my_decimal_zero(result);
  result->bits[0] = value_1.bits[0] - value_2.bits[0];
  result->bits[1] =
      value_1.bits[1] - value_2.bits[1] -
      (((unsigned)result->bits[0] > (unsigned)value_1.bits[0]) ? 1 : 0);
  result->bits[2] =
      value_1.bits[2] - value_2.bits[2] -
      (((unsigned)result->bits[1] > (unsigned)value_1.bits[1]) ? 1 : 0);
  result->bits[3] =
      value_1.bits[3] - value_2.bits[3] -
      (((unsigned)result->bits[2] > (unsigned)value_1.bits[2]) ? 1 : 0);
  result->bits[4] =
      value_1.bits[4] - value_2.bits[4] -
      (((unsigned)result->bits[3] > (unsigned)value_1.bits[3]) ? 1 : 0);
  result->bits[5] =
      value_1.bits[5] - value_2.bits[5] -
      (((unsigned)result->bits[4] > (unsigned)value_1.bits[4]) ? 1 : 0);
  result->sign = value_1.sign;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = (s21_decimal){0};
  s21_my_decimal value1 = {0}, value2 = {0}, res = {0};
  convert_to_my_dec(value_1, value_2, &value1, &value2);
  align_values(&value1, &value2);
  int sign_val, bit = 0, error = 0, point = value1.point_pos;
  if (s21_is_equal_my_dec(value1, value2)) {
    my_decimal_zero(&res);
  } else if (greater_no_sign(value1, value2)) {
    if (value1.sign + value2.sign == 0) {
      s21_sub_main(value1, value2, &res);
    } else if (value1.sign + value2.sign == 2) {
      s21_sub_main(value1, value2, &res);
    } else {
      sign_val = value1.sign;
      s21_add_main(value1, value2, &res, &bit);
      error = check_error(res, value2.sign, value1.sign);
      res.sign = sign_val;
    }
  } else {
    if (value1.sign + value2.sign == 0) {
      s21_sub_main(value2, value1, &res);
      if (!s21_is_zero(res)) {
        res.sign = 1;
      }
    } else if (value1.sign + value2.sign == 2) {
      s21_sub_main(value2, value1, &res);
      res.sign = 0;
    } else {
      sign_val = value1.sign;
      s21_add_main(value1, value2, &res, &bit);
      error = check_error(res, value2.sign, value1.sign);
      res.sign = sign_val;
    }
  }
  res.point_pos = point;
  s21_convert_my_dec_to_result(result, res);
  if (s21_is_zero0(*result) || error != 0) decimal_zero(result);
  return error;
}