#ifndef S21_OTHER_H_
#define S21_OTHER_H_

#include "../arithmetic/s21_arithmetic.h"
#include "../helper/s21_helper.h"
#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif