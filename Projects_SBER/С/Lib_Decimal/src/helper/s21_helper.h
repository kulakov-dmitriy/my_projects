#ifndef S21_HELPER_H_
#define S21_HELPER_H_

#include "../arithmetic/s21_arithmetic.h"
#include "../s21_decimal.h"

int s21_is_zero(s21_my_decimal value);
int s21_is_zero0(s21_decimal value);
int greater_no_sign(s21_my_decimal value_1, s21_my_decimal value_2);
void my_rounding(s21_my_decimal *value_1, s21_my_decimal last_num);
void align_values(s21_my_decimal *value_1, s21_my_decimal *value_2);
void my_decimal_zero(s21_my_decimal *value);
void decimal_zero(s21_decimal *value);
int s21_is_equal_my_dec(s21_my_decimal value_1, s21_my_decimal value_2);

void convert_to_my_dec(s21_decimal value_1, s21_decimal value_2,
                       s21_my_decimal *num1, s21_my_decimal *num2);
int s21_convert_my_dec_to_result(s21_decimal *result,
                                 s21_my_decimal my_dec_res);

int get_bit(int src, int pos);
int get_degree(int sign);
int get_sign(int sign);
void set_bit(s21_my_decimal *value, int number_elements, int bit_value,
             int position);
void set_bitt(s21_decimal *value, int number_elements, int bit_value,
              int position);
void shift_bit_left(s21_my_decimal *value);
void shift_bit_right(s21_my_decimal *value);
int check_error(s21_my_decimal value, int sign1, int sign2);

#endif