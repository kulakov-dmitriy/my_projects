#include "s21_arithmetic.h"

void s21_add_main(s21_my_decimal value_1, s21_my_decimal value_2,
                  s21_my_decimal *result, int *bit) {
  my_decimal_zero(result);
  for (int pos_arr = 0; pos_arr < 6; pos_arr++) {
    for (int pos = 0; pos < 32; pos++) {
      switch (get_bit(value_1.bits[pos_arr], pos) +
              get_bit(value_2.bits[pos_arr], pos) + *bit) {
        case 3:
          *bit = 1;
          result->bits[pos_arr] |= 1 << pos;
          break;
        case 2:
          *bit = 1;
          result->bits[pos_arr] |= 0 << pos;
          break;
        case 1:
          *bit = 0;
          result->bits[pos_arr] |= 1 << pos;
          break;
        case 0:
          *bit = 0;
          result->bits[pos_arr] |= 0 << pos;
          break;
      }
    }
  }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  *result = (s21_decimal){0};
  int error = 0, bit = 0;
  s21_my_decimal value1 = {0}, value2 = {0}, res = {0};
  convert_to_my_dec(value_1, value_2, &value1, &value2);
  int sign1 = value1.sign, sign2 = value2.sign;
  align_values(&value1, &value2);
  value1.sign = sign1, value2.sign = sign2;
  if (value1.sign + value2.sign == 0) {
    s21_add_main(value1, value2, &res, &bit);
    error = check_error(res, 1, 0);
  } else if (value1.sign + value2.sign == 2) {
    s21_add_main(value1, value2, &res, &bit);
    res.sign = 1;
    error = check_error(res, 0, 1);
  } else if (greater_no_sign(value1, value2)) {
    s21_sub_main(value1, value2, &res);
    res.sign = value1.sign;
  } else {
    s21_sub_main(value2, value1, &res);
    res.sign = value2.sign;
  }
  res.point_pos = value1.point_pos;
  s21_convert_my_dec_to_result(result, res);
  if (s21_is_zero0(*result) || error != 0) decimal_zero(result);
  return error;
}