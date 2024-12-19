#include "s21_helper.h"

int get_bit(int src, int pos) {
  int bit;
  if (src & (1 << pos)) {
    bit = 1;
  } else {
    bit = 0;
  }
  return bit;
}

int get_degree(int sign) { return sign << 8 >> 24; }

int get_sign(int sign) {
  int res;
  if ((unsigned)sign >> 31 != 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

void set_bit(s21_my_decimal *value, int number_elements, int bit_value,
             int position) {
  if (bit_value) {
    value->bits[number_elements] |= (1U << position);
  } else {
    value->bits[number_elements] &= ~(1U << position);
  }
}
void set_bitt(s21_decimal *value, int number_elements, int bit_value,
              int position) {
  if (bit_value) {
    value->bits[number_elements] |= (1 << position);
  } else {
    value->bits[number_elements] &= ~(1 << position);
  }
}

void shift_bit_left(s21_my_decimal *value) {
  int bit[7] = {0};
  for (int i = 0; i < 6; i++) {
    bit[i + 1] = ((unsigned)value->bits[i] >> 31) & 1;
    value->bits[i] <<= 1;
    value->bits[i] += bit[i];
  }
}

void shift_bit_right(s21_my_decimal *value) {
  for (int i = 0; i <= 6 - 2; i++) {
    value->bits[i] = (value->bits[i] >> 1);
    set_bit(value, i, value->bits[i + 1] & 1, 31);
  }
  value->bits[6 - 1] >>= 1;
  set_bit(value, 6 - 1, 0, 31);
}