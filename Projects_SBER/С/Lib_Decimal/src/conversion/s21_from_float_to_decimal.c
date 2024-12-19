#include "s21_conversion.h"
#include "string.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (dst == NULL || isnan(src) || isinf(src)) {
    error = 1;
  } else {
    char line[30] = {0};
    int i = 0, j = 0, k, num, pos_point;
    s21_my_decimal value = {0};
    sprintf(line, "%.6e", src);
    k = strlen(line);
    while (j < k) {
      if (line[j] == 'e') line[j] = ' ';
      if ((line[j] >= '0' && line[j] <= '9') || line[j] == '-' ||
          line[j] == ' ')
        line[i++] = line[j++];
      else
        j++;
    }
    line[i] = 0;
    sscanf(line, "%d %d", &num, &pos_point);
    if (num >= 0) {
      for (; num % 10 == 0;) {
        num /= 10;
        pos_point++;
      }
      value.bits[0] = num;
    } else {
      value.sign = 1;
      value.bits[0] = num * -1;
    }
    value.point_pos = 6 - pos_point;
    s21_convert_my_dec_to_result(dst, value);
    if (s21_is_zero0(*dst) || error) decimal_zero(dst);
  }
  return error;
}