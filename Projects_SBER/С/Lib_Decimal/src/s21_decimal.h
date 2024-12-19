#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[6];
  int point_pos;
  int sign;
} s21_my_decimal;

#endif
