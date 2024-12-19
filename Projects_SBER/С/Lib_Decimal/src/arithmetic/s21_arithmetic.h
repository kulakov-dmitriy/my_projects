#ifndef S21_ARITHMETIC_H_
#define S21_ARITHMETIC_H_

#include "../helper/s21_helper.h"
#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

void s21_add_main(s21_my_decimal value_1, s21_my_decimal value_2,
                  s21_my_decimal *result, int *bit);
void s21_sub_main(s21_my_decimal value_1, s21_my_decimal value_2,
                  s21_my_decimal *result);
s21_my_decimal s21_div_main(s21_my_decimal value_1, s21_my_decimal value_2,
                            s21_my_decimal *result);
int s21_mul_main(s21_my_decimal value_1, s21_my_decimal value_2,
                 s21_my_decimal *result);
int mul_10(s21_my_decimal *value, int quantity);

#endif