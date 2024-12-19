#include "s21_helper.h"

void convert_to_my_dec(s21_decimal value_1, s21_decimal value_2,
                       s21_my_decimal *num1, s21_my_decimal *num2) {
  for (int i = 0; i < 3; i++) {
    num1->bits[i] = value_1.bits[i];
    num2->bits[i] = value_2.bits[i];
  }

  num1->sign = get_sign(value_1.bits[3]);
  num2->sign = get_sign(value_2.bits[3]);

  num1->point_pos = get_degree(value_1.bits[3]);
  num2->point_pos = get_degree(value_2.bits[3]);
}

int s21_convert_my_dec_to_result(s21_decimal *result,
                                 s21_my_decimal my_dec_res) {
  s21_my_decimal remainder, value10 = {{10, 0, 0, 0, 0, 0}, 0, 0}, res = {0};
  int point_pos = my_dec_res.point_pos;
  int sign = my_dec_res.sign;
  int error = 0;
  while (my_dec_res.bits[3] + my_dec_res.bits[4] + my_dec_res.bits[5] != 0) {
    remainder = s21_div_main(my_dec_res, value10, &res);
    my_rounding(&res, remainder);
    my_dec_res = res;
    my_decimal_zero(&res);
    point_pos--;
  }

  if (point_pos > 28 || point_pos < 0) {
    if (sign) {
      error = 2;
    } else {
      error = 1;
    }
  } else {
    decimal_zero(result);
    for (int i = 0; i < 3; i++) {
      result->bits[i] = my_dec_res.bits[i];
    }
    result->bits[3] = point_pos << 16;
    result->bits[3] |= (unsigned)sign << 31;
  }
  if (s21_is_zero0(*result)) {
    decimal_zero(result);
  }
  return error;
}