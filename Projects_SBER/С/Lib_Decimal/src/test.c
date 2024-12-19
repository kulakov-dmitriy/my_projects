#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "arithmetic/s21_arithmetic.h"
#include "comparison/comparison.h"
#include "conversion/s21_conversion.h"
#include "other/s21_other.h"
#include "s21_decimal.h"

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
  // DEC (1 1 1 exp=1)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (1 1 1 exp=1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (2 2 2 exp=1)
  s21_decimal correct = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000010,
       0b00000000000000000000000000000010, 0b00000000000000010000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_18) {
  // DEC (1 1 1 exp=1)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (1 1 1 exp=10)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1844674409645126299.1004518913)
  s21_decimal correct = {
      {0b00111011100110101100101000000001, 0b00111011100110101100101000000001,
       0b00111011100110101100101000000001, 0b00000000000010100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_19) {
  // DEC (-1844674407800451893.6)
  s21_decimal val1 = {
      {0b00000000000000000000000000011000, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (1844674413.8134061057)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000001111,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (-1844674405955777479.7865938943)
  s21_decimal correct = {
      {0b10010110100000101110111111111111, 0b00111011100110101100100111110110,
       0b00111011100110101100100111111111, 0b10000000000010100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_20) {
  // DEC (-1844674407800451893.6)
  s21_decimal val1 = {
      {0b00000000000000000000000000011000, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (1844674413.8134061057)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000001111,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (-1844674405955777479.7865938943)
  s21_decimal correct = {
      {0b10010110100000101110111111111111, 0b00111011100110101100100111110110,
       0b00111011100110101100100111111111, 0b10000000000010100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_21) {
  // DEC (1 1 1 exp=10)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1 1 1 exp=1 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (-1844674405955777483.4995481087)
  s21_decimal correct = {
      {0b00111011100110101100100111111111, 0b00111011100110101100100111111111,
       0b00111011100110101100100111111111, 0b10000000000010100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(add_22) {
  // DEC (1 1 1 exp=1 -)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (1 1 1 exp=1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (-0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  // DEC (1 1 1 exp=1)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (1 1 1 exp=1 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (2 2 2 exp=1)
  s21_decimal correct = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000010,
       0b00000000000000000000000000000010, 0b00000000000000010000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_21) {
  // DEC (1 1 1 exp=1 -)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (1 1 1 exp=1 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (0 0 0 -)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_22) {
  // DEC (1 1 1 exp=1 -)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  // DEC (1 1 1 exp=1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (-3689348815600903782.6)
  s21_decimal correct = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000010,
       0b00000000000000000000000000000010, 0b10000000000000010000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(sub_23) {
  // DEC (0)
  s21_decimal val1 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (1 1 1 exp=1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000000010000000000000000}};
  // DEC (1 1 1 exp=1 -)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000000010000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

//////////////////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(mul_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul__10) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  // DEC (0)
  s21_decimal val1 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (0)
  s21_decimal val2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_13) {
  // DEC (-1)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (-1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (1)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_14) {
  // DEC (-1.00)
  s21_decimal val1 = {
      {0b00000000000000000000000001100100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000100000000000000000}};
  // DEC (-1)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (1)
  s21_decimal correct = {
      {0b00000000000000000010011100010000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_15) {
  // DEC (0.02)
  s21_decimal val1 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  // DEC (-0.2)
  s21_decimal val2 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  // DEC (-0.004)
  s21_decimal correct = {
      {0b00000000000000000000000000101000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000001000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_16) {
  // DEC (0.020)
  s21_decimal val1 = {
      {0b00000000000000000000000000010100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000110000000000000000}};
  // DEC (-0.2)
  s21_decimal val2 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  // DEC (-0.004)
  s21_decimal correct = {
      {0b00000000000000000000111110100000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000001100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_17) {
  // DEC (333.3330)
  s21_decimal val1 = {
      {0b00000000001100101101110011010010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001000000000000000000}};
  // DEC (-444.4440)
  s21_decimal val2 = {
      {0b00000000010000111101000100011000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000001000000000000000000}};
  // DEC (-148147,851852)
  s21_decimal correct = {
      {0b01010110000000100010010110110000, 0b00000000000000000000110101111001,
       0b00000000000000000000000000000000, 0b10000000000010000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_18) {
  // DEC (1000000000000000.1)
  s21_decimal val1 = {
      {0b01101111110000010000000000000001, 0b00000000001000111000011011110010,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  // DEC (1000000000000000.1)
  s21_decimal val2 = {
      {0b01101111110000010000000000000001, 0b00000000001000111000011011110010,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  // DEC (0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b0000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b0000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_19) {
  // DEC (1000000000000000.1)
  s21_decimal val1 = {
      {0b01101111110000010000000000000001, 0b00000000001000111000011011110010,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  // DEC (-1000000000000000.1)
  s21_decimal val2 = {
      {0b01101111110000010000000000000001, 0b00000000001000111000011011110010,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  // DEC (0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b0000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b0000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_20) {
  // DEC (max/2)
  s21_decimal val1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b01111111111111111111111111111111, 0b00000000000000000000000000000000}};
  // DEC (-2)
  s21_decimal val2 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (- (max - 1) )
  s21_decimal correct = {
      {0b11111111111111111111111111111110, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b10000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_21) {
  // DEC (1 1 1 exp=10)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000000, 0b00000000000010100000000000000000}};
  // DEC (1 1 1 exp=10)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000000, 0b00000000000010100000000000000000}};
  // DEC (3402823670793947885.4724351485)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000010,
       0b00000000000000000000000000000001, 0b00000000000101000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_22) {
  // DEC (1 exp=10)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000010100000000000000000}};
  // DEC (1 exp=10)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000010100000000000000000}};
  // DEC (0.00000000000000000001)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000101000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_23) {
  // DEC (1 exp=10)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000010100000000000000000}};
  // DEC (1 exp=10 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000010100000000000000000}};
  // DEC (-0.00000000000000000001)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000101000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_24) {
  // DEC (1 exp=10)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000001, 0b00000000000011100000000000000000}};
  // DEC (1 exp=10 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000010100000000000000000}};
  // DEC (-0.000018446744073709551617)
  s21_decimal correct = {
      {0b00000000000000000010011100010000, 0b00000000000000000000000000000000,
       0b00000000000000000010011100010000, 0b10000000000111000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(div_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_5) {
  s21_decimal x = {{3100000000, 0, 0, 0}};
  s21_decimal y = {{1, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  s21_div(x, y, &z);
  char res1[1000], res2[1000] = "3100000000 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", (unsigned int)z.bits[0],
           (unsigned int)z.bits[1], (unsigned int)z.bits[2],
           (unsigned int)z.bits[3]);
  ck_assert_str_eq(res1, res2);
}
END_TEST

// START_TEST(div_6) {
//   s21_decimal x = {{1, 0, 0, 0}};
//   s21_decimal y = {{3100000000, 0, 0, 0}};
//   s21_decimal z = {{0, 0, 0, 0}};

//   s21_div(x, y, &z);
//   char res1[1000], res2[1000] = "1854727994 751066592 0 1835008";
//   snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", (unsigned int)z.bits[0],
//            (unsigned int)z.bits[1], (unsigned int)z.bits[2],
//            (unsigned int)z.bits[3]);
//   ck_assert_str_eq(res1, res2);
// }
// END_TEST

START_TEST(div_7) {
  s21_decimal x = {{52525252, 0, 0, 0}};
  s21_decimal y = {{0, 0, 0, 0}};
  s21_decimal z = {{0, 0, 0, 0}};
  int n1 = 0;
  n1 = s21_div(x, y, &z);
  char res1[1000], res2[1000] = "0 0 0 0";
  snprintf(res1, sizeof(char) * 1000, "%u %u %u %u", (unsigned int)z.bits[0],
           (unsigned int)z.bits[1], (unsigned int)z.bits[2],
           (unsigned int)z.bits[3]);
  ck_assert_str_eq(res1, res2);
  ck_assert_int_eq(n1, 3);
}
END_TEST

START_TEST(div_8) {
  // DEC (max)
  s21_decimal val1 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  // DEC (-2)
  s21_decimal val2 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (-(max/2) )
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b10000000000000000000000000000000, 0b10000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_9) {
  // DEC (11)
  s21_decimal val1 = {
      {0b00000000000000000000000000001011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (-2)
  s21_decimal val2 = {
      {0b00000000000000000000000000000010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // DEC (5.5)
  s21_decimal correct = {
      {0b00000000000000000000000000110111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_10) {
  // DEC (3)
  s21_decimal val1 = {
      {0b00000000000000000000000000000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (4)
  s21_decimal val2 = {
      {0b00000000000000000000000000000100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (0.75)
  s21_decimal correct = {
      {0b00000000000000000000000001001011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_11) {
  // DEC (3.3)
  s21_decimal val1 = {
      {0b00000000000000000000000000100001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  // DEC (-4.4)
  s21_decimal val2 = {
      {0b00000000000000000000000000101100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000010000000000000000}};
  // DEC (-0.75)
  s21_decimal correct = {
      {0b00000000000000000000000001001011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_12) {
  // DEC (3.30)
  s21_decimal val1 = {
      {0b00000000000000000000000101001010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  // DEC (-4.40)
  s21_decimal val2 = {
      {0b00000000000000000000000110111000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000100000000000000000}};
  // DEC (-0.75)
  s21_decimal correct = {
      {0b00000000000000000000000001001011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_13) {
  // DEC (3333333)
  s21_decimal val1 = {
      {0b00000000001100101101110011010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (4444444)
  s21_decimal val2 = {
      {0b00000000010000111101000100011100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (0.75)
  s21_decimal correct = {
      {0b00000000000000000000000001001011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_14) {
  // DEC (1))
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (200000000000)
  s21_decimal val2 = {
      {0b10010000111011011101000000000000, 0b00000000000000000000000000101110,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (0.000000000005)
  s21_decimal correct = {
      {0b00000000000000000000000000000101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000011000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_15) {
  // DEC (1 1 1 exp=10))
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1 1 1 exp=10)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_16) {
  // DEC (1 1 1 exp=10))
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1 1 1 exp=15)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000011110000000000000000}};
  // DEC (100000)
  s21_decimal correct = {
      {0b00000000000000011000011010100000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_17) {
  // DEC (1 1 1 exp=10))
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000010100000000000000000}};
  // DEC (1 10 1 exp=15 sig=-)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000001010,
       0b00000000000000000000000000000001, 0b10000000000011110000000000000000}};
  // DEC (-99999.99979045242119940831048)
  s21_decimal correct = {
      {0b00111100110000010111011101001000, 0b00011011010101101100000100011100,
       0b00100000010011111100111001011101, 0b10000000000101110000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_18) {
  // DEC (1 1 1 exp=15)
  s21_decimal val1 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b00000000000011110000000000000000}};
  // DEC (1 1 1 exp=15 sig=-)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000011110000000000000000}};
  // DEC (-1)
  s21_decimal correct = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_19) {
  // DEC (0 0 0 exp=15)
  s21_decimal val1 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000011110000000000000000}};
  // DEC (1 1 1 exp=15 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000001,
       0b00000000000000000000000000000001, 0b10000000000011110000000000000000}};
  // DEC (-0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

START_TEST(mul_25) {
  // DEC (0)
  s21_decimal val1 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // DEC (1 exp=10 -)
  s21_decimal val2 = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000010100000000000000000}};
  // DEC (-0)
  s21_decimal correct = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
  ck_assert_int_eq(correct.bits[0], res.bits[0]);
  ck_assert_int_eq(correct.bits[1], res.bits[1]);
  ck_assert_int_eq(correct.bits[2], res.bits[2]);
  ck_assert_int_eq(correct.bits[3], res.bits[3]);
}
END_TEST

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(is_less_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_7) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_8) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

//////////////////////////////////////////////////////////////////////////////////////

START_TEST(is_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_1) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_4) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(0, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_5) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_6) {
  s21_decimal val1 = {{0, 0, 0, -2147418112}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

//////////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(is_less_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_8) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

/////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(is_greater_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

////////////////////////////////////////////////////////////////////////////

START_TEST(is_greater_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_1) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

////////////////////////////////////////////////////////////////////////////

START_TEST(is_not_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_1) {
  s21_decimal val1 = {{1, 2, 3, 655360}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal val1 = {{1, 2, 3, -2146828288}};
  s21_decimal val2 = {{3, 2, 1, -2146828288}};
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal val1 = {{1, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, -2146959360}};
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal val1 = {{10, 2, 3, -2146566144}};
  s21_decimal val2 = {{3, 2, 1, 524288}};
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal val1 = {{1, 2, 3, 917504}};
  s21_decimal val2 = {{1, 2, 3, 917504}};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

////////////////////////////////////////////////////////////////////////////

START_TEST(test_negate_positive_to_negative) {
  s21_decimal value = {{123, 0, 0, 0x00000000}};  // Положительное число
  s21_decimal expected = {
      {123, 0, 0, 0x80000000}};  // Ожидаемое отрицательное число
  s21_decimal result;

  int error_code = s21_negate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {{1, 1, 1, 917504}};          // 184467.44078004518913
  s21_decimal expected2 = {{1, 1, 1, -2146566144}};  // -184467.44078004518913
  s21_decimal result2;

  int error_code2 = s21_negate(value2, &result2);

  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_negate_negative_to_positive) {
  s21_decimal value = {{123, 0, 0, 0x80000000}};  // Отрицательное число
  s21_decimal expected = {
      {123, 0, 0, 0x00000000}};  // Ожидаемое положительное число
  s21_decimal result;

  int error_code = s21_negate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {
      {32444, 100, 343253, -2145976320}};  // -63.31900243533454217608892
  s21_decimal expected2 = {
      {32444, 100, 343253, 1507328}};  // 63.31900243533454217608892
  s21_decimal result2;

  int error_code2 = s21_negate(value2, &result2);

  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_negate_zero_positive) {
  s21_decimal value = {{0, 0, 0, 917504}};  // Положительный ноль
  s21_decimal expected = {
      {0, 0, 0, -2146566144}};  // Ожидаемый отрицательный ноль
  s21_decimal result;

  int error_code = s21_negate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_negate_zero_negative) {
  s21_decimal value = {{0, 0, 0, 0x80000000}};  // Отрицательный ноль
  s21_decimal expected = {
      {0, 0, 0, 0x00000000}};  // Ожидаемый положительный ноль
  s21_decimal result;

  int error_code = s21_negate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_negate_null_pointer) {
  s21_decimal value = {{123, 0, 0, 0}};  // Любое число

  int error_code =
      s21_negate(value, NULL);  // Передаем NULL как указатель на результат

  ck_assert_int_eq(error_code, 1);  // Ожидаем код ошибки 1
}
END_TEST

///////////////////////////////////////////////////////////////////////////////////////

START_TEST(test_truncate_no_fraction) {
  s21_decimal value = {
      {123456789, 0, 0, 0}};  // Целое число без дробной части (123456789)
  s21_decimal expected = {
      {123456789, 0, 0, 0}};  // Ожидаемое число без изменений (123456789)
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
  // ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_with_fraction) {
  s21_decimal value = {{123456789, 0, 0, 2 << 16}};  // 1234567.89
  s21_decimal expected = {{1234567, 0, 0, 0}};       // 1234567
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result.bits[0], expected.bits[0]);
  ck_assert_int_eq(result.bits[1], expected.bits[1]);
  ck_assert_int_eq(result.bits[2], expected.bits[2]);
  ck_assert_int_eq(result.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(test_truncate_with_fraction_2) {
  s21_decimal value = {{123456789, 0, 0, 0x00080000}};  // 1.23456789
  s21_decimal expected = {{1, 0, 0, 0x00000000}};       // 1
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_negative_number) {
  s21_decimal value = {
      {987654321, 0, 0, 0x80000000}};  // Отрицательное целое число (-987654321)
  s21_decimal expected = {
      {987654321, 0, 0, 0x80000000}};  // Ожидаемое отрицательное число без
                                       // изменений (-987654321)
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_with_fraction_negative) {
  s21_decimal value = {{123456789, 0, 0, 0x80020000}};   // -1234567.89
  s21_decimal expected = {{1234567, 0, 0, 0x80000000}};  // -1234567
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_with_fraction_negative_2) {
  s21_decimal value = {{123456789, 0, 0, 0x80080000}};  // -1.23456789
  s21_decimal expected = {{1, 0, 0, 0x80000000}};       // -1
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_large_scale) {
  s21_decimal value = {
      {1, 0, 0, 0x001C0000}};  // 0.0000000000000000000000000001
  s21_decimal expected = {{0, 0, 0, 0x00000000}};  // 0
  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_null_pointer) {
  s21_decimal value = {
      {123456789, 0, 0,
       0x00180000}};  // Любое число с дробной частью (например,
                      // 0.000000000000000000123456789)

  int error_code =
      s21_truncate(value, NULL);  // Передаем NULL как указатель на результат

  ck_assert_int_eq(error_code, 1);  // Ожидаем код ошибки 1
}
END_TEST

START_TEST(test_truncate_zero_with_large_negative_bit) {
  // Значение нуля с масштабом 28 и отрицательным знаком
  s21_decimal value = {{0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b00000000000000000000000000000000,
                        0b10000000000111000000000000000000}};  // 0

  // Ожидаемое значение после усечения: ноль остается нулем, знак отрицательный
  s21_decimal expected = {{0b00000000000000000000000000000000,
                           0b00000000000000000000000000000000,
                           0b00000000000000000000000000000000,
                           0b00000000000000000000000000000000}};  // 0

  s21_decimal result;

  int error_code = s21_truncate(value, &result);

  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_truncate_custom_values) {
  s21_decimal value1 = {{1, 2, 3, 917504}};     // 553402.32229718589441
  s21_decimal expected1 = {{553402, 0, 0, 0}};  // 553402
  s21_decimal result1;
  int error_code1 = s21_truncate(value1, &result1);
  ck_assert_int_eq(error_code1, 0);
  ck_assert_mem_eq(&result1, &expected1, sizeof(s21_decimal));

  s21_decimal value2 = {{1, 2, 3, -2146566144}};  // -553402.32229718589441
  s21_decimal expected2 = {{553402, 0, 0, -2147483648}};  // -553402
  s21_decimal result2;
  int error_code2 = s21_truncate(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));

  s21_decimal value3 = {
      {33, 2, 3000, -2146107392}};  // -55.340232221137244782625
  s21_decimal expected3 = {{55, 0, 0, -2147483648}};  // -55
  s21_decimal result3;
  int error_code3 = s21_truncate(value3, &result3);
  ck_assert_int_eq(error_code3, 0);
  ck_assert_mem_eq(&result3, &expected3, sizeof(s21_decimal));

  s21_decimal value4 = {{10, 100, 3, 1376256}};  // 0.055340232650625384458
  s21_decimal expected4 = {{0, 0, 0, 0}};        // 0
  s21_decimal result4;
  int error_code4 = s21_truncate(value4, &result4);
  ck_assert_int_eq(error_code4, 0);
  ck_assert_mem_eq(&result4, &expected4, sizeof(s21_decimal));

  s21_decimal value5 = {{16, 100, 3, 851968}};   // 5534023.2650625384464
  s21_decimal expected5 = {{5534023, 0, 0, 0}};  // 5534023
  s21_decimal result5;
  int error_code5 = s21_truncate(value5, &result5);
  ck_assert_int_eq(error_code5, 0);
  ck_assert_mem_eq(&result5, &expected5, sizeof(s21_decimal));

  s21_decimal value6 = {
      {32444, 100, 343253, -2145976320}};  // -63.31900243533454217608892
  s21_decimal expected6 = {{63, 0, 0, -2147483648}};  // -63
  s21_decimal result6;
  int error_code6 = s21_truncate(value6, &result6);
  ck_assert_int_eq(error_code6, 0);
  ck_assert_mem_eq(&result6, &expected6, sizeof(s21_decimal));

  s21_decimal value7 = {{0, 0, 0, 851968}};  // 0.0000000000000
  s21_decimal expected7 = {{0, 0, 0, 0}};    // 0
  s21_decimal result7;
  int error_code7 = s21_truncate(value7, &result7);
  ck_assert_int_eq(error_code7, 0);
  ck_assert_mem_eq(&result7, &expected7, sizeof(s21_decimal));

  s21_decimal value8 = {{1, 1, 1, 655360}};         // 1844674407.8004518913
  s21_decimal expected8 = {{1844674407, 0, 0, 0}};  // 1844674407
  s21_decimal result8;
  int error_code8 = s21_truncate(value8, &result8);
  ck_assert_int_eq(error_code8, 0);
  ck_assert_mem_eq(&result8, &expected8, sizeof(s21_decimal));

  s21_decimal value10 = {{1, 10, 1, -2146500608}};  // -18446.744116659224577
  s21_decimal expected10 = {{18446, 0, 0, -2147483648}};  // -18446
  s21_decimal result10;
  int error_code10 = s21_truncate(value10, &result10);
  ck_assert_int_eq(error_code10, 0);
  ck_assert_mem_eq(&result10, &expected10, sizeof(s21_decimal));

  s21_decimal value12 = {{1, 1, 1, 917504}};     // 184467.44078004518913
  s21_decimal expected12 = {{184467, 0, 0, 0}};  // 184467
  s21_decimal result12;
  int error_code12 = s21_truncate(value12, &result12);
  ck_assert_int_eq(error_code12, 0);
  ck_assert_mem_eq(&result12, &expected12, sizeof(s21_decimal));

  s21_decimal value14 = {{1, 15, 1, 655360}};        // 1844674413.8134061057
  s21_decimal expected14 = {{1844674413, 0, 0, 0}};  // 1844674413
  s21_decimal result14;
  int error_code14 = s21_truncate(value14, &result14);
  ck_assert_int_eq(error_code14, 0);
  ck_assert_mem_eq(&result14, &expected14, sizeof(s21_decimal));

  s21_decimal value9 = {{1, 1, 1, 65536}};  // 1844674407800451891.3
  s21_decimal expected9 = {
      {-1288490189, 429496729, 0, 0}};  // 1844674407800451891
  s21_decimal result9;
  int error_code9 = s21_truncate(value9, &result9);
  ck_assert_int_eq(error_code9, 0);
  ck_assert_mem_eq(&result9, &expected9, sizeof(s21_decimal));

  s21_decimal value11 = {{3, 2, 1, 524288}};          // 184467440822.99486211
  s21_decimal expected11 = {{-216152906, 42, 0, 0}};  // 184467440822
  s21_decimal result11;
  int error_code11 = s21_truncate(value11, &result11);
  ck_assert_int_eq(error_code11, 0);
  ck_assert_mem_eq(&result11, &expected11, sizeof(s21_decimal));

  s21_decimal value13 = {{24, 1, 1, -2147418112}};  // -1844674407800451893.6
  s21_decimal expected13 = {
      {-1288490187, 429496729, 0, -2147483648}};  // -1844674407800451893
  s21_decimal result13;
  int error_code13 = s21_truncate(value13, &result13);
  ck_assert_int_eq(error_code13, 0);
  ck_assert_mem_eq(&result13, &expected13, sizeof(s21_decimal));

  s21_decimal value15 = {{1, 1, 1, -2147418112}};  // -1844674407800451891.3
  s21_decimal expected15 = {
      {-1288490189, 429496729, 0, -2147483648}};  // -1844674407800451891
  s21_decimal result15;
  int error_code15 = s21_truncate(value15, &result15);
  ck_assert_int_eq(error_code15, 0);
  ck_assert_mem_eq(&result15, &expected15, sizeof(s21_decimal));

  s21_decimal value22 = {{1, 2, 3, 655360}};         // 5534023222.9718589441
  s21_decimal expected22 = {{1239055926, 1, 0, 0}};  // 5534023222
  s21_decimal result22;
  int error_code22 = s21_truncate(value22, &result22);
  ck_assert_int_eq(error_code22, 0);
  ck_assert_mem_eq(&result22, &expected22, sizeof(s21_decimal));

  s21_decimal value25 = {{1, 2, 3, -2146828288}};  // -5534023222.9718589441
  s21_decimal expected25 = {{1239055926, 1, 0, -2147483648}};  // -5534023222
  s21_decimal result25;
  int error_code25 = s21_truncate(value25, &result25);
  ck_assert_int_eq(error_code25, 0);
  ck_assert_mem_eq(&result25, &expected25, sizeof(s21_decimal));

  s21_decimal value26 = {{3, 2, 1, -2146959360}};  // -184467440822.99486211
  s21_decimal expected26 = {{-216152906, 42, 0, -2147483648}};  // -184467440822
  s21_decimal result26;
  int error_code26 = s21_truncate(value26, &result26);
  ck_assert_int_eq(error_code26, 0);
  ck_assert_mem_eq(&result26, &expected26, sizeof(s21_decimal));

  s21_decimal value18 = {{1, 0, 1, 917504}};     // 184467.44073709551617
  s21_decimal expected18 = {{184467, 0, 0, 0}};  // 184467
  s21_decimal result18;
  int error_code18 = s21_truncate(value18, &result18);
  ck_assert_int_eq(error_code18, 0);
  ck_assert_mem_eq(&result18, &expected18, sizeof(s21_decimal));

  s21_decimal value20 = {{1, 1, 1, 983040}};    // 18446.744078004518913
  s21_decimal expected20 = {{18446, 0, 0, 0}};  // 18446
  s21_decimal result20;
  int error_code20 = s21_truncate(value20, &result20);
  ck_assert_int_eq(error_code20, 0);
  ck_assert_mem_eq(&result20, &expected20, sizeof(s21_decimal));

  s21_decimal value21 = {{1, 1, 1, -2146500608}};  // -18446.744078004518913
  s21_decimal expected21 = {{18446, 0, 0, -2147483648}};  // -18446
  s21_decimal result21;
  int error_code21 = s21_truncate(value21, &result21);
  ck_assert_int_eq(error_code21, 0);
  ck_assert_mem_eq(&result21, &expected21, sizeof(s21_decimal));

  s21_decimal value24 = {{3, 2, 1, -2146828288}};  // -1844674408.2299486211
  s21_decimal expected24 = {{1844674408, 0, 0, -2147483648}};  // -1844674408
  s21_decimal result24;
  int error_code24 = s21_truncate(value24, &result24);
  ck_assert_int_eq(error_code24, 0);
  ck_assert_mem_eq(&result24, &expected24, sizeof(s21_decimal));

  s21_decimal value27 = {{10, 2, 3, -2146566144}};  // -553402.32229718589450
  s21_decimal expected27 = {{553402, 0, 0, -2147483648}};  // -553402
  s21_decimal result27;
  int error_code27 = s21_truncate(value27, &result27);
  ck_assert_int_eq(error_code27, 0);
  ck_assert_mem_eq(&result27, &expected27, sizeof(s21_decimal));

  s21_decimal value28 = {{1, 2, 3, 917504}};     // 553402.32229718589441
  s21_decimal expected28 = {{553402, 0, 0, 0}};  // 553402
  s21_decimal result28;
  int error_code28 = s21_truncate(value28, &result28);
  ck_assert_int_eq(error_code28, 0);
  ck_assert_mem_eq(&result28, &expected28, sizeof(s21_decimal));

  s21_decimal value29 = {{1, 2, 3, -2146566144}};  // -553402.32229718589441
  s21_decimal expected29 = {{553402, 0, 0, -2147483648}};  // -553402
  s21_decimal result29;
  int error_code29 = s21_truncate(value29, &result29);
  ck_assert_int_eq(error_code29, 0);
  ck_assert_mem_eq(&result29, &expected29, sizeof(s21_decimal));

  s21_decimal value30 = {{10, 0, 0, 0}};     // 10
  s21_decimal expected30 = {{10, 0, 0, 0}};  // 10
  s21_decimal result30;
  int error_code30 = s21_truncate(value30, &result30);
  ck_assert_int_eq(error_code30, 0);
  ck_assert_mem_eq(&result30, &expected30, sizeof(s21_decimal));

  s21_decimal value31 = {{133456435, 0, 0, -2147483648}};     // -133456435
  s21_decimal expected31 = {{133456435, 0, 0, -2147483648}};  // -133456435
  s21_decimal result31;
  int error_code31 = s21_truncate(value31, &result31);
  ck_assert_int_eq(error_code31, 0);
  ck_assert_mem_eq(&result31, &expected31, sizeof(s21_decimal));

  s21_decimal value32 = {{2343453, 0, 0, -2147024896}};  // -0.2343453
  s21_decimal expected32 = {{0, 0, 0, 0}};               // -0
  s21_decimal result32;
  int error_code32 = s21_truncate(value32, &result32);
  ck_assert_int_eq(error_code32, 0);
  ck_assert_mem_eq(&result32, &expected32, sizeof(s21_decimal));

  s21_decimal value33 = {{1272343, 0, 0, 262144}};  // 127.2343
  s21_decimal expected33 = {{127, 0, 0, 0}};        // 127
  s21_decimal result33;
  int error_code33 = s21_truncate(value33, &result33);
  ck_assert_int_eq(error_code33, 0);
  ck_assert_mem_eq(&result33, &expected33, sizeof(s21_decimal));
}
END_TEST

/////////////////////////////////////////////////////////////////////////////////

START_TEST(test_round_positive_no_fraction) {
  s21_decimal value = {{1, 2, 3, 917504}};     // 553402.32229718589441
  s21_decimal expected = {{553402, 0, 0, 0}};  // 553402
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {{16, 100, 3, 851968}};   // 5534023.2650625384464
  s21_decimal expected2 = {{5534023, 0, 0, 0}};  // 5534023
  s21_decimal result2;
  int error_code2 = s21_round(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));

  s21_decimal value3 = {{2112827408, 798, 3, 851968}};  // 5534023.5650625384464
  s21_decimal expected3 = {{5534024, 0, 0, 0}};         // 5534024
  s21_decimal result3;
  int error_code3 = s21_round(value3, &result3);
  ck_assert_int_eq(error_code3, 0);
  ck_assert_mem_eq(&result3, &expected3, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_negative_no_fraction) {
  s21_decimal value = {
      {-1662697471, 4658, 3, -2146566144}};  // -553402.52229718589441
  s21_decimal expected = {{553403, 0, 0, -2147483648}};  // -553403
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {{16, 100, 3, -2146631680}};  // -5534023.2650625384464
  s21_decimal expected2 = {{5534023, 0, 0, -2147483648}};  // 5534023
  s21_decimal result2;
  int error_code2 = s21_round(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_positive_fraction_half) {
  s21_decimal value = {{25, 30, 0, 65536}};  // 12884901890.5
  s21_decimal expected = {{3, 3, 0, 0}};     // 12884901891
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {{3, 3, 0, 0}};     // 12884901891
  s21_decimal expected2 = {{3, 3, 0, 0}};  // 12884901891
  s21_decimal result2;
  int error_code2 = s21_round(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_positive_fraction_less_half) {
  s21_decimal value = {{225, 300, 0, 131072}};  // 12884901890.25
  s21_decimal expected = {{2, 3, 0, 0}};        // 12884901890
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_negative_fraction_half) {
  s21_decimal value = {
      {792095801, -1320247423, 6, -2147418112}};  // -12345678901234567890.5
  s21_decimal expected = {
      {-350287149, -1420514932, 0, -2147483648}};  // -12345678901234567891
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_zero) {
  s21_decimal value = {{25, 0, 0, 131072}};  // 0.25
  s21_decimal expected = {{0, 0, 0, 0}};     // 0
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {{10, 100, 3, 1376256}};  // 0.055340232650625384458
  s21_decimal expected2 = {{0, 0, 0, 0}};        // 0
  s21_decimal result2;
  int error_code2 = s21_round(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_small_fraction_positive) {
  s21_decimal value = {{10625, 10000, 0, 262144}};  // 4294967297.0625
  s21_decimal expected = {{1, 1, 0, 0}};            // 4294967297
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_small_fraction_negative) {
  s21_decimal value = {{10625, 100000, 0, -2147221504}};  // -42949672961.0625
  s21_decimal expected = {{1, 10, 0, -2147483648}};       // -42949672961
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_positive_exact_half) {
  s21_decimal value = {{15, 10, 0, 65536}};  // 4294967297.5
  s21_decimal expected = {{2, 1, 0, 0}};     // 4294967298
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_round_negative_exact_half) {
  s21_decimal value = {{15, 10, 0, -2147418112}};   // -4294967297.5
  s21_decimal expected = {{2, 1, 0, -2147483648}};  // -4294967298
  s21_decimal result;
  int error_code = s21_round(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_positive_no_fraction) {
  s21_decimal value = {{1, 2, 3, 917504}};     // 553402.32229718589441
  s21_decimal expected = {{553402, 0, 0, 0}};  // 553402
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_negative_no_fraction) {
  s21_decimal value = {{1, 2, 3, -2146566144}};  // -553402.32229718589441
  s21_decimal expected = {{553403, 0, 0, -2147483648}};  // -553403
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_positive_fraction) {
  s21_decimal value = {{25, 30, 0, 65536}};  // 12884901890.5
  s21_decimal expected = {{2, 3, 0, 0}};     // 12884901890
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_positive_fraction_small) {
  s21_decimal value = {{225, 300, 0, 131072}};  // 12884901890.25
  s21_decimal expected = {{2, 3, 0, 0}};        // 12884901890
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_negative_fraction) {
  s21_decimal value = {
      {792095801, -1320247423, 6, -2147418112}};  // -12345678901234567890.5
  s21_decimal expected = {
      {-350287149, -1420514932, 0, -2147483648}};  // -12345678901234567891
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_zero) {
  s21_decimal value = {{25, 0, 0, 131072}};  // 0.25
  s21_decimal expected = {{0, 0, 0, 0}};     // 0
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_small_fraction_positive) {
  s21_decimal value = {{10625, 10000, 0, 262144}};  // 4294967297.0625
  s21_decimal expected = {{1, 1, 0, 0}};            // 4294967297
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_small_fraction_negative) {
  s21_decimal value = {{10625, 100000, 0, -2147221504}};  // -42949672961.0625
  s21_decimal expected = {{2, 10, 0, -2147483648}};       // -42949672962
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_negative_exact_half) {
  s21_decimal value = {{15, 10, 0, -2147418112}};   // -4294967297.5
  s21_decimal expected = {{2, 1, 0, -2147483648}};  // -4294967298
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));

  s21_decimal value2 = {
      {33, 2, 3000, -2146107392}};  // -55.340232221137244782625
  s21_decimal expected2 = {{56, 0, 0, -2147483648}};  // -56
  s21_decimal result2;
  int error_code2 = s21_floor(value2, &result2);
  ck_assert_int_eq(error_code2, 0);
  ck_assert_mem_eq(&result2, &expected2, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_floor_positive_large_integer) {
  s21_decimal value = {{133456435, 0, 0, 0}};     // 133456435
  s21_decimal expected = {{133456435, 0, 0, 0}};  // 133456435
  s21_decimal result;
  int error_code = s21_floor(value, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

///////////////////////////////////////////////////////////////////////////////

// Тест на преобразование положительного числа
START_TEST(test_from_int_to_decimal_positive) {
  int src = 123456;
  s21_decimal expected = {{123456, 0, 0, 0}};  // 123456
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование отрицательного числа
START_TEST(test_from_int_to_decimal_negative) {
  int src = -654321;
  s21_decimal expected = {{654321, 0, 0, 0x80000000}};  // -654321
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование нуля
START_TEST(test_from_int_to_decimal_zero) {
  int src = 0;
  s21_decimal expected = {{0, 0, 0, 0}};  // 0
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование минимального значения int
START_TEST(test_from_int_to_decimal_min) {
  int src = -2147483648;
  s21_decimal expected = {{-2147483648, 0, 0, -2147483648}};  // -2147483648
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование максимального значения int
START_TEST(test_from_int_to_decimal_max) {
  int src = 2147483647;
  s21_decimal expected = {{2147483647, 0, 0, 0}};  // 2147483647
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование небольшого отрицательного числа
START_TEST(test_from_int_to_decimal_small_negative) {
  int src = -1;
  s21_decimal expected = {{1, 0, 0, 0x80000000}};  // -1
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование числа в пределах значений short int
START_TEST(test_from_int_to_decimal_short_int) {
  int src = 32767;
  s21_decimal expected = {{32767, 0, 0, 0}};  // 32767
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование небольшого положительного числа
START_TEST(test_from_int_to_decimal_small_positive) {
  int src = 1;
  s21_decimal expected = {{1, 0, 0, 0}};  // 1
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование отрицательного числа в пределах значений short int
START_TEST(test_from_int_to_decimal_short_int_negative) {
  int src = -32768;
  s21_decimal expected = {{32768, 0, 0, 1U << 31}};  // -32768
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование числа 1000000
START_TEST(test_from_int_to_decimal_large_positive) {
  int src = 1000000;
  s21_decimal expected = {{1000000, 0, 0, 0}};  // 1000000
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_verter1) {
  int src = 10;
  s21_decimal expected = {{10, 0, 0, 0}};  // 1000000
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_verter2) {
  int src = -133546435;
  s21_decimal expected = {{133546435, 0, 0, -2147483648}};  // 1000000
  s21_decimal result;
  int error_code = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

START_TEST(test_from_int_to_decimal_NULL) {
  int src = -133546435;
  int error_code = s21_from_int_to_decimal(src, NULL);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

/////////////////////////////////////////////////////////////////////////////////

// Тест на преобразование положительного числа
START_TEST(test_from_float_verter_val1) {
  s21_decimal expected = {{2343453, 0, 0, -2147024896}};
  float val = -0.2343453;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST
START_TEST(test_from_float_verter_val2) {
  s21_decimal expected = {{1272343, 0, 0, 262144}};
  float val = 127.2343;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование положительного числа
START_TEST(test_from_float_to_decimal_positive) {
  s21_decimal expected = {{2343453, 0, 0, 0}};
  float val = 2343453.0;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование отрицательного числа
START_TEST(test_from_float_to_decimal_negative) {
  s21_decimal expected = {{2343453, 0, 0, -2147483648}};
  float val = -2343453.0;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование очень маленького числа
START_TEST(test_from_float_to_decimal_small_positive) {
  s21_decimal expected = {{1, 0, 0, 393216}};
  float val = 0.000001;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование числа с дробной частью
START_TEST(test_from_float_to_decimal_fractional) {
  s21_decimal expected = {{123456, 0, 0, 393216}};
  float val = 0.123456;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование отрицательного числа с дробной частью
START_TEST(test_from_float_to_decimal_negative_fractional) {
  s21_decimal expected = {{1234560, 0, 0, 2147942400}};
  float val = -0.123456;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование числа 1.5
START_TEST(test_from_float_to_decimal_one_point_five) {
  s21_decimal expected = {{15, 0, 0, 65536}};
  float val = 1.5;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование очень маленького отрицательного числа
START_TEST(test_from_float_to_decimal_very_small_negative) {
  s21_decimal expected = {{1000000, 0, 0, 2148532224}};
  float val = -1.0e-10;
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_mem_eq(&result, &expected, sizeof(s21_decimal));
}
END_TEST

// Тест на преобразование положительного бесконечного значения float
START_TEST(test_from_float_to_decimal_infinity) {
  float val = 1.0f / 0.0f;  // inf
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 1);  // Ожидаем, что функция вернет ошибку
}
END_TEST

// Тест на преобразование отрицательного бесконечного значения float
START_TEST(test_from_float_to_decimal_negative_infinity) {
  float val = -1.0f / 0.0f;  // -inf
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 1);  // Ожидаем, что функция вернет ошибку
}
END_TEST

// Тест на преобразование значения NaN float
START_TEST(test_from_float_to_decimal_nan) {
  float val = 0.0f / 0.0f;  // NaN
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = s21_from_float_to_decimal(val, &result);
  ck_assert_int_eq(error_code, 1);  // Ожидаем, что функция вернет ошибку
}
END_TEST

/////////////////////////////////////////////////////////////////////////////////////

START_TEST(test_from_decimal_to_int_positive) {
  s21_decimal src = {{123456, 0, 0, 0}};  // 123456
  int expected = 123456;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование отрицательного числа
START_TEST(test_from_decimal_to_int_negative) {
  s21_decimal src = {{654321, 0, 0, 0x80000000}};  // -654321
  int expected = -654321;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование нуля
START_TEST(test_from_decimal_to_int_zero) {
  s21_decimal src = {{0, 0, 0, 0}};  // 0
  int expected = 0;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование минимального значения int
START_TEST(test_from_decimal_to_int_min) {
  s21_decimal src = {{-2147483648, 0, 0, -2147483648}};  // -2147483648
  int expected = -2147483648;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование максимального значения int
START_TEST(test_from_decimal_to_int_max) {
  s21_decimal src = {{2147483647, 0, 0, 0}};  // 2147483647
  int expected = 2147483647;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование небольшого отрицательного числа
START_TEST(test_from_decimal_to_int_small_negative) {
  s21_decimal src = {{1, 0, 0, 0x80000000}};  // -1
  int expected = -1;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование числа в пределах значений short int
START_TEST(test_from_decimal_to_int_short_int) {
  s21_decimal src = {{32767, 0, 0, 0}};  // 32767
  int expected = 32767;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование небольшого положительного числа
START_TEST(test_from_decimal_to_int_small_positive) {
  s21_decimal src = {{1, 0, 0, 0}};  // 1
  int expected = 1;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование отрицательного числа в пределах значений short int
START_TEST(test_from_decimal_to_int_short_int_negative) {
  s21_decimal src = {{32768, 0, 0, 0x80000000}};  // -32768
  int expected = -32768;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на преобразование числа 1000000
START_TEST(test_from_decimal_to_int_large_positive) {
  s21_decimal src = {{1000000, 0, 0, 0}};  // 1000000
  int expected = 1000000;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// Тест на переполнение положительного значения
START_TEST(test_from_decimal_to_int_overflow_positive) {
  s21_decimal src = {
      {-2147483648, 0, 0, 0}};  // 2147483648 (выход за пределы int)
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 1);  // Ожидается ошибка переполнения
}
END_TEST

//Тест на переполнение отрицательного значения
START_TEST(test_from_decimal_to_int_overflow_negative) {
  s21_decimal src = {
      {-2147483647, 0, 0, -2147483648}};  // -2147483649 (выход за пределы
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 1);  // Ожидается ошибка переполнения
}
END_TEST

START_TEST(verter1) {
  s21_decimal src = {{10, 0, 0, 0}};  // 1000000
  int expected = 10;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(verter2) {
  s21_decimal src = {{133546435, 0, 0, -2147483648}};  // 1000000
  int expected = -133546435;
  int result;
  int error_code = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

/////////////////////////////////////////////////////////////////////////

// Тест на преобразование положительного числа
START_TEST(test_from_decimal_to_float_verter_val1) {
  s21_decimal val = {{2343453, 0, 0, -2147024896}};
  float expected = -0.2343453;
  float result = 0;
  int error_code = s21_from_decimal_to_float(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST
START_TEST(test_from_decimal_to_float_verter_val2) {
  s21_decimal val = {{1272343, 0, 0, 262144}};
  float expected = 127.2343;
  float result = 0;
  int error_code = s21_from_decimal_to_float(val, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование положительного числа
START_TEST(test_from_decimal_to_float_positive) {
  s21_decimal src = {{23434530, 0, 0, 65536}};  // 2343453.0
  float expected = 2343453.0f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование отрицательного числа
START_TEST(test_from_decimal_to_float_negative) {
  s21_decimal src = {{23434530, 0, 0, -2147418112}};  // -2343453.0
  float expected = -2343453.0f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование числа с дробной частью
START_TEST(test_from_decimal_to_float_fractional) {
  s21_decimal src = {{123456, 0, 0, 393216}};  // 0.123456
  float expected = 0.123456;
  float result = 0.0;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование отрицательного числа с дробной частью
START_TEST(test_from_decimal_to_float_negative_fractional) {
  s21_decimal src = {{123456, 0, 0, -2147090432}};  // -0.123456
  float expected = -0.123456f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование большого положительного числа
START_TEST(test_from_decimal_to_float_large_positive) {
  s21_decimal src = {{-10, 9, 0, 65536}};  // 4294967295.0
  float expected = 4294967295.0f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование маленького положительного числа
START_TEST(test_from_decimal_to_float_small_positive) {
  s21_decimal src = {{1, 0, 0, 393216}};  // 0.000001
  float expected = 0.000001f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование очень маленького отрицательного числа
START_TEST(test_from_decimal_to_float_very_small_negative) {
  s21_decimal src = {{10, 0, 0, -2146762752}};  // -1.0e-10
  float expected = -1.0e-10f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование очень большого отрицательного числа
START_TEST(test_from_decimal_to_float_very_large_negative) {
  s21_decimal src = {{-10, 9, 0, -2147418112}};  // -4294967295.0
  float expected = -4294967295.0f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на преобразование числа 1.5
START_TEST(test_from_decimal_to_float_one_point_five) {
  s21_decimal src = {{15, 0, 0, 65536}};  // 1.5
  float expected = 1.5f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

// Тест на 0
START_TEST(test_from_decimal_to_float_zero) {
  s21_decimal src = {{0, 0, 0, 0}};
  float expected = 0.0f;
  float result = 0.0f;
  int error_code = s21_from_decimal_to_float(src, &result);
  ck_assert_int_eq(error_code, 0);
  ck_assert_float_eq(result, expected);
}
END_TEST

START_TEST(test_from_decimal_to_float_NULL) {
  s21_decimal src = {{0, 0, 0, 0}};
  int error_code = s21_from_decimal_to_float(src, NULL);
  ck_assert_int_eq(error_code, 1);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_decimal");
  TCase *tc = tcase_create("s21_decimal");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc);

  tcase_add_test(tc, add_0);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, add_17);
  tcase_add_test(tc, add_18);
  tcase_add_test(tc, add_19);
  tcase_add_test(tc, add_20);
  tcase_add_test(tc, add_21);
  tcase_add_test(tc, add_22);

  ///////////////////////////////

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);
  tcase_add_test(tc, sub_20);
  tcase_add_test(tc, sub_21);
  tcase_add_test(tc, sub_22);
  tcase_add_test(tc, sub_23);

  ///////////////////////////////

  tcase_add_test(tc, mul_0);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul__10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);
  tcase_add_test(tc, mul_16);
  tcase_add_test(tc, mul_17);
  tcase_add_test(tc, mul_18);
  tcase_add_test(tc, mul_19);
  tcase_add_test(tc, mul_20);
  tcase_add_test(tc, mul_21);
  tcase_add_test(tc, mul_22);
  tcase_add_test(tc, mul_23);
  tcase_add_test(tc, mul_24);
  tcase_add_test(tc, mul_25);

  ////////////////////////////////

  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  // tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);
  tcase_add_test(tc, div_16);
  tcase_add_test(tc, div_17);
  tcase_add_test(tc, div_18);
  tcase_add_test(tc, div_19);

  /////////////////////////////////

  tcase_add_test(tc, is_less_0);
  tcase_add_test(tc, is_less_1);
  tcase_add_test(tc, is_less_2);
  tcase_add_test(tc, is_less_3);
  tcase_add_test(tc, is_less_4);
  tcase_add_test(tc, is_less_5);
  tcase_add_test(tc, is_less_6);
  tcase_add_test(tc, is_less_7);
  tcase_add_test(tc, is_less_8);

  //////////////////////////////////

  tcase_add_test(tc, is_equal_0);
  tcase_add_test(tc, is_equal_1);
  tcase_add_test(tc, is_equal_2);
  tcase_add_test(tc, is_equal_3);
  tcase_add_test(tc, is_equal_4);
  tcase_add_test(tc, is_equal_5);
  tcase_add_test(tc, is_equal_6);

  //////////////////////////////////

  tcase_add_test(tc, is_less_or_equal_0);
  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_7);
  tcase_add_test(tc, is_less_or_equal_8);

  /////////////////////////////////////////////

  tcase_add_test(tc, is_greater_0);
  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_7);
  tcase_add_test(tc, is_greater_8);

  /////////////////////////////////////////////

  tcase_add_test(tc, is_greater_or_equal_0);
  tcase_add_test(tc, is_greater_or_equal_1);
  tcase_add_test(tc, is_greater_or_equal_2);
  tcase_add_test(tc, is_greater_or_equal_3);
  tcase_add_test(tc, is_greater_or_equal_4);
  tcase_add_test(tc, is_greater_or_equal_5);

  //////////////////////////////////////////////////

  tcase_add_test(tc, is_not_equal_0);
  tcase_add_test(tc, is_not_equal_1);
  tcase_add_test(tc, is_not_equal_2);
  tcase_add_test(tc, is_not_equal_3);
  tcase_add_test(tc, is_not_equal_4);
  tcase_add_test(tc, is_not_equal_5);

  //////////////////////////////////////////////////

  tcase_add_test(tc, test_negate_positive_to_negative);
  tcase_add_test(tc, test_negate_negative_to_positive);
  tcase_add_test(tc, test_negate_zero_positive);
  tcase_add_test(tc, test_negate_zero_negative);
  tcase_add_test(tc, test_negate_null_pointer);

  ///////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_truncate_no_fraction);
  tcase_add_test(tc, test_truncate_with_fraction);
  tcase_add_test(tc, test_truncate_with_fraction_2);
  tcase_add_test(tc, test_truncate_with_fraction_negative);
  tcase_add_test(tc, test_truncate_with_fraction_negative_2);
  tcase_add_test(tc, test_truncate_negative_number);
  tcase_add_test(tc, test_truncate_large_scale);
  tcase_add_test(tc, test_truncate_null_pointer);
  tcase_add_test(tc, test_truncate_zero_with_large_negative_bit);
  tcase_add_test(tc, test_truncate_custom_values);

  ///////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_round_positive_no_fraction);
  tcase_add_test(tc, test_round_negative_no_fraction);
  tcase_add_test(tc, test_round_positive_fraction_half);
  tcase_add_test(tc, test_round_positive_fraction_less_half);
  tcase_add_test(tc, test_round_negative_fraction_half);
  tcase_add_test(tc, test_round_zero);
  tcase_add_test(tc, test_round_small_fraction_positive);
  tcase_add_test(tc, test_round_small_fraction_negative);
  tcase_add_test(tc, test_round_positive_exact_half);
  tcase_add_test(tc, test_round_negative_exact_half);

  ///////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_floor_positive_no_fraction);
  tcase_add_test(tc, test_floor_negative_no_fraction);
  tcase_add_test(tc, test_floor_positive_fraction);
  tcase_add_test(tc, test_floor_positive_fraction_small);
  tcase_add_test(tc, test_floor_negative_fraction);
  tcase_add_test(tc, test_floor_zero);
  tcase_add_test(tc, test_floor_small_fraction_positive);
  tcase_add_test(tc, test_floor_small_fraction_negative);
  tcase_add_test(tc, test_floor_negative_exact_half);
  tcase_add_test(tc, test_floor_positive_large_integer);

  //////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_from_int_to_decimal_positive);
  tcase_add_test(tc, test_from_int_to_decimal_negative);
  tcase_add_test(tc, test_from_int_to_decimal_zero);
  tcase_add_test(tc, test_from_int_to_decimal_min);
  tcase_add_test(tc, test_from_int_to_decimal_max);
  tcase_add_test(tc, test_from_int_to_decimal_small_negative);
  tcase_add_test(tc, test_from_int_to_decimal_short_int);
  tcase_add_test(tc, test_from_int_to_decimal_small_positive);
  tcase_add_test(tc, test_from_int_to_decimal_short_int_negative);
  tcase_add_test(tc, test_from_int_to_decimal_large_positive);
  tcase_add_test(tc, test_verter1);
  tcase_add_test(tc, test_verter2);
  tcase_add_test(tc, test_from_int_to_decimal_NULL);

  //////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_from_float_verter_val1);
  tcase_add_test(tc, test_from_float_verter_val2);
  tcase_add_test(tc, test_from_float_to_decimal_positive);
  tcase_add_test(tc, test_from_float_to_decimal_negative);
  tcase_add_test(tc, test_from_float_to_decimal_small_positive);
  tcase_add_test(tc, test_from_float_to_decimal_fractional);
  tcase_add_test(tc, test_from_float_to_decimal_negative_fractional);
  tcase_add_test(tc, test_from_float_to_decimal_one_point_five);
  tcase_add_test(tc, test_from_float_to_decimal_very_small_negative);
  tcase_add_test(tc, test_from_float_to_decimal_infinity);
  tcase_add_test(tc, test_from_float_to_decimal_negative_infinity);
  tcase_add_test(tc, test_from_float_to_decimal_nan);

  //////////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_from_decimal_to_int_positive);
  tcase_add_test(tc, test_from_decimal_to_int_negative);
  tcase_add_test(tc, test_from_decimal_to_int_zero);
  tcase_add_test(tc, test_from_decimal_to_int_min);
  tcase_add_test(tc, test_from_decimal_to_int_max);
  tcase_add_test(tc, test_from_decimal_to_int_small_negative);
  tcase_add_test(tc, test_from_decimal_to_int_short_int);
  tcase_add_test(tc, test_from_decimal_to_int_small_positive);
  tcase_add_test(tc, test_from_decimal_to_int_short_int_negative);
  tcase_add_test(tc, test_from_decimal_to_int_large_positive);
  tcase_add_test(tc, test_from_decimal_to_int_overflow_positive);
  tcase_add_test(tc, test_from_decimal_to_int_overflow_negative);
  tcase_add_test(tc, verter1);
  tcase_add_test(tc, verter2);

  ///////////////////////////////////////////////////////////////////////////

  tcase_add_test(tc, test_from_decimal_to_float_verter_val1);
  tcase_add_test(tc, test_from_decimal_to_float_verter_val2);
  tcase_add_test(tc, test_from_decimal_to_float_positive);
  tcase_add_test(tc, test_from_decimal_to_float_negative);
  tcase_add_test(tc, test_from_decimal_to_float_fractional);
  tcase_add_test(tc, test_from_decimal_to_float_negative_fractional);
  tcase_add_test(tc, test_from_decimal_to_float_large_positive);
  tcase_add_test(tc, test_from_decimal_to_float_small_positive);
  tcase_add_test(tc, test_from_decimal_to_float_very_small_negative);
  tcase_add_test(tc, test_from_decimal_to_float_very_large_negative);
  tcase_add_test(tc, test_from_decimal_to_float_one_point_five);
  tcase_add_test(tc, test_from_decimal_to_float_zero);
  tcase_add_test(tc, test_from_decimal_to_float_NULL);

  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
