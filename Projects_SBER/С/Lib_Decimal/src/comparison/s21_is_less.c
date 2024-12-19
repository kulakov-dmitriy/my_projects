#include "comparison.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_my_decimal value1 = {0}, value2 = {0};
  convert_to_my_dec(value_1, value_2, &value1, &value2);
  int result = 0, sign1 = value1.sign, sign2 = value2.sign;
  align_values(&value1, &value2);
  if (s21_is_zero(value1) && s21_is_zero(value2)) {
    result = 0;
  } else if (sign1 == 1 && sign2 == 0) {
    result = 1;
  } else if (sign1 == 0 && sign2 == 1) {
    result = 0;
  } else {
    for (int i = 5; i >= 0; i--) {
      if ((unsigned)value1.bits[i] - (unsigned)value2.bits[i] == 0) {
        continue;
      }
      if ((unsigned)value1.bits[i] < (unsigned)value2.bits[i] &&
          sign1 + sign2 == 0) {
        result = 1;
        break;
      }
      if ((unsigned)value1.bits[i] > (unsigned)value2.bits[i] &&
          sign1 + sign2 == 2) {
        result = 1;
        break;
      }
    }
  }
  return result;
}
