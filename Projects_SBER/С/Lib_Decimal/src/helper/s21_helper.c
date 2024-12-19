#include "s21_helper.h"

int check_error(s21_my_decimal value, int sign1, int sign2) {
  int error = 0;
  if (value.bits[3] + value.bits[4] + value.bits[5] != 0) {
    if (sign1 == 1)
      error = 1;
    else if (sign2 == 1)
      error = 2;
  }
  return error;
}

int s21_is_zero(s21_my_decimal value) {
  int is_zero = 0;
  for (int i = 0; i < 6; i++) {
    is_zero += value.bits[i];
  }
  return is_zero == 0 ? 1 : 0;
}

int s21_is_zero0(s21_decimal value) {
  int is_zero = 0;
  for (int i = 0; i < 3; i++) {
    is_zero += value.bits[i];
  }
  return is_zero == 0 ? 1 : 0;
}

int greater_no_sign(s21_my_decimal value_1, s21_my_decimal value_2) {
  int result = 0;
  for (int i = 5; i >= 0; i--) {
    if ((unsigned)value_1.bits[i] - (unsigned)value_2.bits[i] == 0) {
      continue;
    }
    if ((unsigned)value_1.bits[i] > (unsigned)value_2.bits[i]) {
      result = 1;
    }
    break;
  }
  return result;
}

void my_rounding(s21_my_decimal *value_1, s21_my_decimal last_num) {
  s21_my_decimal num1 = {{1, 0, 0, 0, 0, 0}, 0, 0}, value_2 = {0},
                 remainder = {0}, value_3 = {0};
  int bit = 0;
  switch (last_num.bits[0]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      value_2 = *value_1;
      my_decimal_zero(value_1);
      s21_add_main(value_2, num1, value_1, &bit);
      break;
    case 5:
      value_2 = *value_1;
      num1.bits[0] = 10;
      remainder = s21_div_main(value_2, num1, &value_3);
      if (remainder.bits[0] % 2) {
        num1.bits[0] = 1;
        s21_add_main(*value_1, num1, &value_2, &bit);
        *value_1 = value_2;
      }
  }
}

void align_values(s21_my_decimal *value_1, s21_my_decimal *value_2) {
  if (value_1->point_pos > value_2->point_pos) {
    mul_10(value_2, value_1->point_pos - value_2->point_pos);
    value_2->point_pos = value_1->point_pos;
  } else if (value_2->point_pos > value_1->point_pos) {
    mul_10(value_1, value_2->point_pos - value_1->point_pos);
    value_1->point_pos = value_2->point_pos;
  }
}

void my_decimal_zero(s21_my_decimal *value) {
  for (int i = 0; i < 6; i++) {
    value->bits[i] = 0;
  }
  value->sign = 0;
  value->point_pos = 0;
}

void decimal_zero(s21_decimal *value) {
  for (int i = 0; i < 4; i++) {
    value->bits[i] = 0;
  }
}

int s21_is_equal_my_dec(s21_my_decimal value_1, s21_my_decimal value_2) {
  int equal = 1;
  align_values(&value_1, &value_2);
  if (s21_is_zero(value_1) && s21_is_zero(value_2)) {
    return 1;
  }
  if (value_1.sign != value_2.sign) {
    equal = 0;
  }
  for (int i = 0; i < 127; i++) {
    if (value_1.bits[0] != value_2.bits[0]) {
      equal = 0;
      break;
    }
    shift_bit_right(&value_1);
    shift_bit_right(&value_2);
  }
  return equal;
}