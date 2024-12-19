#include "s21_arithmetic.h"

s21_my_decimal s21_div_main(s21_my_decimal value_1, s21_my_decimal value_2,
                            s21_my_decimal *result) {
  value_1.sign = 0;
  value_2.sign = 0;
  s21_my_decimal current = value_1, remainder = {0}, value_3;
  for (int i = 0; i < 192; i++) {
    int bit = get_bit(current.bits[5], 31);
    shift_bit_left(&current);
    shift_bit_left(&remainder);
    if (bit) {
      set_bit(&remainder, 0, 1, 0);
    }
    if (greater_no_sign(value_2, remainder)) {
      shift_bit_left(result);
    } else {
      shift_bit_left(result);
      set_bit(result, 0, 1, 0);
      value_3 = remainder;
      my_decimal_zero(&remainder);
      s21_sub_main(value_3, value_2, &remainder);
    }
  }
  return remainder;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (s21_is_zero0(value_2)) {
    decimal_zero(result);
    return 3;
  }
  if (s21_is_zero0(value_1)) {
    decimal_zero(result);
    return 0;
  }
  s21_my_decimal value1 = {0}, value2 = {0}, value3 = {0}, value4, res = {0},
                 remainder = {0};
  convert_to_my_dec(value_1, value_2, &value1, &value2);

  align_values(&value1, &value2);
  int bit = 0, error = 0;
  int point_pos_res = 0, sign = value1.sign + value2.sign == 1 ? 1 : 0;
  remainder = s21_div_main(value1, value2, &res);

  while (!s21_is_zero(remainder) && res.bits[5] == 0) {
    while (greater_no_sign(value2, remainder)) {
      mul_10(&remainder, 1);
      mul_10(&res, 1);
      point_pos_res++;
    }
    remainder = s21_div_main(remainder, value2, &value3);
    value4 = res;
    my_decimal_zero(&res);
    s21_add_main(value4, value3, &res, &bit);
  }

  res.point_pos = point_pos_res;
  res.sign = sign;
  error = s21_convert_my_dec_to_result(result, res);
  if (s21_is_zero0(*result) || error != 0) decimal_zero(result);
  return error;
}