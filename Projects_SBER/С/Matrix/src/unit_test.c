#include <check.h>

#include "s21_matrix.h"

void init(matrix_t *A, int k, int c) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = k;
      k += c;
    }
  }
}

void s21_matrix_initialization(matrix_t *matrix, double num) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = num;
      num++;
    }
  }
}

START_TEST(create_matrix_1) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), IS_OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_3) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_4) {
  ck_assert_int_eq(s21_create_matrix(0, 0, NULL), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), IS_OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_6) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_7) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, 0, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_8) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 1, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_9) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_10) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-5, 1, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_11) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(-5, -1, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_12) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(5, -1, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(create_matrix_13) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(15, 25, &A), IS_OK);
  s21_remove_matrix(&A);
}
END_TEST

/////////////////////////////////////////////////////////////////////////////////

START_TEST(s21_remove_matrix_1) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_matrix_3) {
  matrix_t A = {0};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_matrix_4) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_5) {
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_6) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(s21_remove_matrix_7) {
  matrix_t A = {};
  s21_remove_matrix(&A);
}
END_TEST

/////////////////////////////////////////////////////////////////////////

START_TEST(s21_eq_matrix_1) {
  matrix_t A = {0}, B = {0};
  int result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  init(&A, 1, 1);
  init(&B, 1, 1);
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {0}, B = {0};
  int result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  init(&A, 1.0, 1.0);
  init(&B, 1.0, 1.0);
  B.matrix[1][1] = 0.0;
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A = {0}, B = {0};
  double num = 0.00001;
  int result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = num;
      B.matrix[i][j] = num;
      num += 0.00001;
    }
  }
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A = {0}, B = {0};
  double num = 1;
  int result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = num;
      B.matrix[i][j] = num;
      num++;
      num *= num;
    }
  }
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A = {0}, B = {0};
  int result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(1, 1, &B);
  init(&A, 1.0, 1.0);
  init(&A, 1.0, 1.0);
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A = {0};
  int result;
  s21_create_matrix(3, 3, &A);
  init(&A, 1.0, 1.0);
  result = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_7) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(0, 0, &A);
  init(&A, 1.0, 1.0);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_8) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  init(&A, 1.0, 1.0);
  init(&B, 1.0, 1.0);
  A.matrix[2][2] += 0.00000001;
  B.matrix[4][4] += 0.00000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_9) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  init(&A, 1.0, 1.0);
  init(&B, 1.0, 1.0);
  A.matrix[2][2] += 0.0000001;
  B.matrix[4][4] += 0.0000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_12) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[1][0] = 3,
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1, B.matrix[0][1] = 2, B.matrix[1][0] = 3,
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_13) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = -1.019999997, A.matrix[0][1] = -2.45678,
  A.matrix[1][0] = 3.0599991, A.matrix[1][1] = 4.000001;
  B.matrix[0][0] = -1.019999998, B.matrix[0][1] = -2.45678,
  B.matrix[1][0] = 3.0599991, B.matrix[1][1] = 4.000001;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_14) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = -1.0197, A.matrix[0][1] = 2.45678,
  A.matrix[1][0] = -3.0599991, A.matrix[1][1] = 4.000001;
  B.matrix[0][0] = -1.0198, B.matrix[0][1] = 2.45678,
  B.matrix[1][0] = -3.0599991, B.matrix[1][1] = 4.000001;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_15) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = -1.0000000197, A.matrix[0][1] = -2.000000045678,
  A.matrix[1][0] = -3.00000000599991, A.matrix[1][1] = -4.000001;
  B.matrix[0][0] = -1.00000000198, B.matrix[0][1] = -2.000000045678,
  B.matrix[1][0] = -3.00000000599991, B.matrix[1][1] = -4.000001;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_16) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 9, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_17) {
  int res = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_18) {
  matrix_t A, B;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 0.25, A.matrix[0][1] = 1.25, A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25, A.matrix[1][1] = 4.25, A.matrix[1][2] = 5.25;

  B.matrix[0][0] = 0.25, B.matrix[0][1] = 1.25, B.matrix[0][2] = 2.25;
  B.matrix[1][0] = 3.25, B.matrix[1][1] = 4.25, B.matrix[1][2] = 5.25;
  B.matrix[2][0] = 6.25, B.matrix[2][1] = 7.25, B.matrix[2][2] = 8.25;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

///////////////////////////////////////////////////////////////////////

START_TEST(s21_sum_matrix_1) {
  matrix_t A = {0}, B = {0}, result = {0}, check = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      B.matrix[i][j] = numB;
      check.matrix[i][j] = numA + numB;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, NULL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t B = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, NULL);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A = {0}, B = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
    }
  }

  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numB++;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A = {0}, B = {0}, result = {0};
  double numA = 1;
  double numB = 1;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numB++;
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(0, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 0, &A);
  s21_create_matrix(3, 0, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_sum_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), IS_OK);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = 3, eq_matrix.matrix[2][1] = 4,
  eq_matrix.matrix[2][2] = 7;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_11) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 38.12389;
  B.matrix[0][0] = -129.4910;
  eq_matrix.matrix[0][0] = -91.36711;
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(s21_eq_matrix(&eq_matrix, &result), SUCCESS);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_12) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &eq_matrix);

  A.matrix[0][0] = 121239.113, A.matrix[0][1] = 2401.12392;
  A.matrix[1][0] = -348901.2, A.matrix[1][1] = 2389014;
  B.matrix[0][0] = 109428035910.10189, B.matrix[0][1] = -19872409.1489;
  B.matrix[1][0] = 3, B.matrix[1][1] = 140912.5;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), IS_OK);

  eq_matrix.matrix[0][0] = 109428157149.21489,
  eq_matrix.matrix[0][1] = -19870008.02498;
  eq_matrix.matrix[1][0] = -348898.2, eq_matrix.matrix[1][1] = 2529926.5;

  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_13) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 121239.122013, A.matrix[0][1] = 2401.12392,
  A.matrix[0][2] = -348901.2;
  A.matrix[1][0] = 2389014, A.matrix[1][1] = 912039.12389,
  A.matrix[1][2] = 129034.23400;
  A.matrix[2][0] = 0, A.matrix[2][1] = 1203, A.matrix[2][2] = 9000000.123;

  B.matrix[0][0] = 109428035910.1024189, B.matrix[0][1] = -19872409.1489,
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 140912.5, B.matrix[1][1] = 0, B.matrix[1][2] = 12930124;
  B.matrix[2][0] = 1942.3489, B.matrix[2][1] = 102.234891,
  B.matrix[2][2] = 10230912.1;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), IS_OK);

  eq_matrix.matrix[0][0] = 109428157149.2244319,
  eq_matrix.matrix[0][1] = -19870008.02498, eq_matrix.matrix[0][2] = -348898.2;
  eq_matrix.matrix[1][0] = 2529926.5, eq_matrix.matrix[1][1] = 912039.12389,
  eq_matrix.matrix[1][2] = 13059158.234;
  eq_matrix.matrix[2][0] = 1942.3489, eq_matrix.matrix[2][1] = 1305.234891,
  eq_matrix.matrix[2][2] = 19230912.223;

  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_14) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &eq_matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j % 2) {
        A.matrix[i][j] = ((double)rand() + (double)rand() / RAND_MAX) * -1;
      } else {
        A.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
      }
      B.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
      eq_matrix.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), IS_OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

///////////////////////////////////////////////////////////////////////////////

START_TEST(s21_sub_matrix_1) {
  matrix_t A = {0}, B = {0}, result = {0}, check = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      B.matrix[i][j] = numB;
      check.matrix[i][j] = numA - numB;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, NULL);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t B = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, NULL);
  s21_create_matrix(3, 3, &B);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numA++;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A = {0}, B = {0}, result = {0};
  double numA = 1, numB = 2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A = {0}, B = {0}, result = {0};
  double numA = 1;
  double numB = 1;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = numB;
      numB++;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(0, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 0, &A);
  s21_create_matrix(3, 0, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_8) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(-5, 5, &A);
  s21_create_matrix(-5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 5, &A);
  s21_create_matrix(3, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_10) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &eq_matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j % 2) {
        A.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
        B.matrix[i][j] = ((double)rand() + (double)rand() / RAND_MAX) * -1;
      } else {
        A.matrix[i][j] = ((double)rand() + (double)rand() / RAND_MAX) * -1;
        B.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
      }
      eq_matrix.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), IS_OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

//////////////////////////////////////////////////////////////////////////////////

START_TEST(s21_mult_number_1) {
  matrix_t A = {0}, result = {0}, check = {0};
  double numA = 1.5, number = 5.0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      check.matrix[i][j] = numA * number;
      numA++;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A = {0}, result = {0};
  double numA = 1.5, number = 3;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      numA++;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t result = {0};
  double number = 5.0;
  s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(s21_mult_number(NULL, number, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t A = {0}, result = {0};
  double number = 5.0;
  s21_create_matrix(3, 0, &A);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t A = {0}, result = {0};
  double number = 5.0;
  s21_create_matrix(0, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_6) {
  matrix_t A = {0}, result = {0};
  double number = 5.0;

  ck_assert_int_eq(s21_mult_number(NULL, number, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_7) {
  matrix_t A = {0}, result = {0}, check = {0};
  double numA = 0.0, number = 5.0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = numA;
      check.matrix[i][j] = numA;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number_8) {
  matrix_t A = {0};
  double number = 3.14;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_9) {
  matrix_t A = {0}, B = {0};
  double number = 3.14;
  s21_create_matrix(-3, 3, &A);
  ck_assert_int_eq(s21_mult_number(&A, number, &B), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_10) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t eq_matrix = {0};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_mult_number_11) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t eq_matrix = {0};
  double number = ((double)rand() + (double)rand() / RAND_MAX) * -1;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(rows, cols, &eq_matrix);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j % 2) {
        A.matrix[i][j] = ((double)rand() + (double)rand() / RAND_MAX) * -1;
      } else {
        A.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
      }

      eq_matrix.matrix[i][j] = A.matrix[i][j] * number;
    }
  }

  ck_assert_int_eq(s21_mult_number(&A, number, &result), IS_OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

/////////////////////////////////////////////////////////////////////////////

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 5, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), IS_OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A = {0}, B = {0}, result = {0}, check = {0};
  // matrix_t A, B, result, check;
  double num = 1.0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 5, &B);
  s21_create_matrix(3, 5, &check);
  s21_matrix_initialization(&A, num);
  s21_matrix_initialization(&B, num);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < A.columns; k++) {
        check.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), IS_OK);
  // ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 5, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t result = {0};
  s21_create_matrix(3, 3, NULL);
  s21_create_matrix(3, 5, NULL);
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_6) {
  matrix_t A = {0}, B = {0}, res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_7) {
  matrix_t A = {0}, B = {0}, res;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &res), IS_OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_matrix_8) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(4, 5, &A);
  s21_create_matrix(5, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_9) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_10) {
  matrix_t B, res;
  int result = s21_mult_matrix(NULL, &B, &res);
  ck_assert_int_eq(result, UNCORRECTED_MATRIX);
}
END_TEST

///////////////////////////////////////////////////////////////////////////////////////

START_TEST(s21_transpose_1) {
  matrix_t A = {0}, result = {0}, check = {0};
  double num = 1.0;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = num;
      check.matrix[j][i] = num;
      num++;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t A = {0}, result = {0}, check = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1;
      check.matrix[i][j] = 1;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t A = {0}, result = {0}, check = {0};
  double num = 1.0;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &check);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = num;
      check.matrix[j][i] = num;
      num++;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_5) {
  matrix_t result = {0};
  s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(s21_transpose(NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_6) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, NULL);
  ck_assert_int_eq(s21_transpose(NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_7) {
  matrix_t A = {0}, check = {0}, res;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;

  s21_create_matrix(2, 3, &check);

  check.matrix[0][0] = 1, check.matrix[0][1] = 2, check.matrix[0][2] = 3;
  check.matrix[1][0] = 4, check.matrix[1][1] = 5, check.matrix[1][2] = 6;

  ck_assert_int_eq(s21_transpose(&A, &res), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_8) {
  matrix_t A;
  ck_assert_int_eq(s21_transpose(NULL, &A), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_transpose_9) {
  matrix_t A = {0}, check = {0}, res;
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &A);
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A.matrix[i][j] = (double)rand() + (double)rand() / RAND_MAX;
      check.matrix[j][i] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &res), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&res);
}
END_TEST

////////////////////////////////////////////////////////////////////////////////////

START_TEST(s21_determinant_1) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(1, 1, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(2, 2, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, -2.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(3, 3, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(4, 4, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(2, 3, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_determinant(&A, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_8) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(0, 2, &A);
  s21_matrix_initialization(&A, 1);
  ck_assert_int_eq(s21_determinant(&A, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_9) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(6, 6, &A);
  s21_matrix_initialization(&A, 1.0);
  ck_assert_int_eq(s21_determinant(&A, &result), IS_OK);
  ck_assert_double_eq(result, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_11) {
  matrix_t A = {0};
  double res = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = -2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 4, A.matrix[1][1] = 0, A.matrix[1][2] = 6;
  A.matrix[2][0] = -7, A.matrix[2][1] = 8, A.matrix[2][2] = 9;
  ck_assert_int_eq(IS_OK, s21_determinant(&A, &res));
  ck_assert_double_eq(204, res);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_12) {
  matrix_t A = {0};
  double res = 0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 3, A.matrix[0][1] = -3, A.matrix[0][2] = -5,
  A.matrix[0][3] = 8;
  A.matrix[1][0] = -3, A.matrix[1][1] = 2, A.matrix[1][2] = 4,
  A.matrix[1][3] = -6;
  A.matrix[2][0] = 2, A.matrix[2][1] = -5, A.matrix[2][2] = -7,
  A.matrix[2][3] = 5;
  A.matrix[3][0] = -4, A.matrix[3][1] = 3, A.matrix[3][2] = 5,
  A.matrix[3][3] = -6;
  ck_assert_int_eq(IS_OK, s21_determinant(&A, &res));
  ck_assert_double_eq(18, res);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_13) {
  matrix_t A = {};
  double res = 0;
  ck_assert_int_eq(s21_determinant(&A, &res), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_determinant_14) {
  matrix_t A = {};
  double res = 0;
  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = 3, A.matrix[0][1] = -3, A.matrix[0][2] = -5;
  A.matrix[1][0] = -3, A.matrix[1][1] = 2, A.matrix[1][2] = 4;
  A.matrix[2][0] = 2, A.matrix[2][1] = -5, A.matrix[2][2] = -7;
  A.matrix[3][0] = -4, A.matrix[3][1] = 3, A.matrix[3][2] = 5;
  ck_assert_int_eq(s21_determinant(&A, &res), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_15) {
  matrix_t A = {};
  double res = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &res), IS_OK);
  ck_assert_double_eq(res, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_16) {
  matrix_t A = {0};
  double res = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 182.2488, A.matrix[0][1] = 91.12498, A.matrix[0][2] = 300.1;
  A.matrix[1][0] = 1, A.matrix[1][1] = 44.5, A.matrix[1][2] = 6;
  A.matrix[2][0] = 2, A.matrix[2][1] = 1238.4, A.matrix[2][2] = 9999.99;
  ck_assert_int_eq(IS_OK, s21_determinant(&A, &res));
  ck_assert_double_eq_tol(79181232.9667738, res, 1e-07);

  s21_remove_matrix(&A);
}
END_TEST

////////////////////////////////////////////////////////////////////////////////////

START_TEST(s21_calc_complements_1) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), IS_OK);
  ck_assert_double_eq(result.matrix[0][0], 0.0);
  ck_assert_double_eq(result.matrix[0][1], 10.0);
  ck_assert_double_eq(result.matrix[0][2], -20.0);
  ck_assert_double_eq(result.matrix[1][0], 4.0);
  ck_assert_double_eq(result.matrix[1][1], -14.0);
  ck_assert_double_eq(result.matrix[1][2], 8.0);
  ck_assert_double_eq(result.matrix[2][0], -8.0);
  ck_assert_double_eq(result.matrix[2][1], -2.0);
  ck_assert_double_eq(result.matrix[2][2], 4.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t result = {0};
  s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(s21_calc_complements(NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), IS_OK);
  ck_assert_double_eq(result.matrix[0][0], 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;
  s21_calc_complements(&A, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = -2879514.0;
  X.matrix[0][1] = -1236631.0;
  X.matrix[0][2] = -1685096.0;
  X.matrix[0][3] = 880697.0;
  X.matrix[1][0] = 1162090.0;
  X.matrix[1][1] = -714015.0;
  X.matrix[1][2] = 4046255.0;
  X.matrix[1][3] = -3901600.0;
  X.matrix[2][0] = 4362897.0;
  X.matrix[2][1] = -2049432.0;
  X.matrix[2][2] = -532912.0;
  X.matrix[2][3] = -1370781.0;
  X.matrix[3][0] = 3412773.0;
  X.matrix[3][1] = -1569493.0;
  X.matrix[3][2] = 3144517.0;
  X.matrix[3][3] = 1284666.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_7) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_calc_complements(&A, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_8) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  res = s21_calc_complements(&A, &Z);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_calc_complements_9) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  res = s21_calc_complements(&A, &Z);
  ck_assert_int_eq(res, UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_10) {
  matrix_t A = {0}, check = {0}, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;

  check.matrix[0][0] = 0, check.matrix[0][1] = 10, check.matrix[0][2] = -20;
  check.matrix[1][0] = 4, check.matrix[1][1] = -14, check.matrix[1][2] = 8;
  check.matrix[2][0] = -8, check.matrix[2][1] = -2, check.matrix[2][2] = 4;

  ck_assert_int_eq(IS_OK, s21_calc_complements(&A, &result));
  //    for(int i = 0; i < result.rows; i++) {
  //     for(int j = 0; j < result.columns; j++) {
  //         printf("%lf ", result.matrix[i][j]);
  //     }
  //     printf("\n");
  //    }
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_11) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_12) {
  matrix_t A = {0}, result;
  s21_create_matrix(1, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_13) {
  matrix_t A = {0}, check = {0}, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 3, A.matrix[0][1] = 2, A.matrix[0][2] = 2;
  A.matrix[1][0] = 2, A.matrix[1][1] = 2, A.matrix[1][2] = 8;
  A.matrix[2][0] = 3, A.matrix[2][1] = 2, A.matrix[2][2] = 2;

  check.matrix[0][0] = -12, check.matrix[0][1] = 20, check.matrix[0][2] = -2;
  check.matrix[1][0] = 0, check.matrix[1][1] = 0, check.matrix[1][2] = 0;
  check.matrix[2][0] = 12, check.matrix[2][1] = -20, check.matrix[2][2] = 2;

  ck_assert_int_eq(IS_OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_14) {
  matrix_t A = {0}, check = {0}, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &check);

  A.matrix[0][0] = 1, A.matrix[0][1] = -5;
  A.matrix[1][0] = 3, A.matrix[1][1] = -4;

  check.matrix[0][0] = -4, check.matrix[0][1] = -3;
  check.matrix[1][0] = 5, check.matrix[1][1] = 1;

  ck_assert_int_eq(IS_OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_15) {
  matrix_t A = {0}, check = {0}, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &check);

  A.matrix[0][0] = 112.0, A.matrix[0][1] = 243.0, A.matrix[0][2] = 3.0,
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0, A.matrix[1][1] = 51.0, A.matrix[1][2] = -66.0,
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0, A.matrix[2][1] = 85.0, A.matrix[2][2] = 97.0,
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0, A.matrix[3][1] = 79.0, A.matrix[3][2] = -99.0,
  A.matrix[3][3] = -121.0;

  check.matrix[0][0] = -2879514.0, check.matrix[0][1] = -1236631.0,
  check.matrix[0][2] = -1685096.0, check.matrix[0][3] = 880697.0;
  check.matrix[1][0] = 1162090.0, check.matrix[1][1] = -714015.0,
  check.matrix[1][2] = 4046255.0, check.matrix[1][3] = -3901600.0;
  check.matrix[2][0] = 4362897.0, check.matrix[2][1] = -2049432.0,
  check.matrix[2][2] = -532912.0, check.matrix[2][3] = -1370781.0;
  check.matrix[3][0] = 3412773.0, check.matrix[3][1] = -1569493.0,
  check.matrix[3][2] = 3144517.0, check.matrix[3][3] = 1284666.0;

  ck_assert_int_eq(IS_OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_16) {
  matrix_t A = {0}, check = {0}, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);

  A.matrix[0][0] = 37.33, A.matrix[0][1] = -4, A.matrix[0][2] = -373.4;
  A.matrix[1][0] = 0, A.matrix[1][1] = 3673.4, A.matrix[1][2] = -637.4;
  A.matrix[2][0] = 89.8, A.matrix[2][1] = -6737.5, A.matrix[2][2] = 0;

  check.matrix[0][0] = -4294482.5, check.matrix[0][1] = -57238.52,
  check.matrix[0][2] = -329871.32;
  check.matrix[1][0] = 2515782.5, check.matrix[1][1] = 33531.32,
  check.matrix[1][2] = 251151.675;
  check.matrix[2][0] = 1374197.16, check.matrix[2][1] = 23794.142,
  check.matrix[2][2] = 137128.022;

  ck_assert_int_eq(IS_OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

/////////////////////////////////////////////////////////////////////

START_TEST(s21_inverse_matrix_1) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], -1.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][2], 1.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], -38.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 41.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][2], -34.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[2][0], 27.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[2][1], -29.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[2][2], 24.0, 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t result = {0};
  s21_create_matrix(3, 3, NULL);
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), UNCORRECTED_MATRIX);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 4, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.2, 1e-7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &A);
  init(&A, 1.0, 1.0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_8) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(5, 3, &A);
  init(&A, 1.0, 1.0);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_9) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 21.0;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_10) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 2.0, A.matrix[0][1] = 5.0, A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0, A.matrix[1][1] = 3.0, A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0, A.matrix[2][1] = -2.0, A.matrix[2][2] = -3.0;
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
  eq_matrix.matrix[0][2] = 1;
  eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
  eq_matrix.matrix[1][2] = -34;
  eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
  eq_matrix.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_11) {
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_12) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_inverse_matrix(&A, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_13) {
  int res;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(Z.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, IS_OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_14) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 3, &A);
  init(&A, 1.0, 1.0);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_15) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 2, &A);
  init(&A, 1.0, 1.0);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_16) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  s21_create_matrix(3, 3, &A);
  init(&A, 1.0, 1.0);
  s21_remove_matrix(&A);
  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_17) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;
  s21_inverse_matrix(&A, &Z);
  s21_create_matrix(3, 3, &X);
  X.matrix[0][0] = -3.0 / 5.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 1.0 / 5.0;
  X.matrix[1][0] = -4.0 / 5.0;
  X.matrix[1][1] = 1.0;
  X.matrix[1][2] = -2.0 / 5.0;
  X.matrix[2][0] = 16.0 / 15.0;
  X.matrix[2][1] = -2.0 / 3.0;
  X.matrix[2][2] = 1.0 / 5.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_18) {
  matrix_t A = {0}, result;
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), UNCORRECTED_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_19) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), UNCORRECTED_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_20) {
  matrix_t A = {0}, result;
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 1;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_21) {
  matrix_t A = {0}, result, check = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check);
  A.matrix[0][0] = 1.5;

  check.matrix[0][0] = 0.6666666666666666666666666666666;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_22) {
  matrix_t A = {0}, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 1, A.matrix[0][2] = 1;
  A.matrix[1][0] = 1, A.matrix[1][1] = 1, A.matrix[1][2] = 1;
  A.matrix[2][0] = 1, A.matrix[2][1] = 1, A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_23) {
  matrix_t A = {0}, result, check = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;

  check.matrix[0][0] = 1, check.matrix[0][1] = -1, check.matrix[0][2] = 1;
  check.matrix[1][0] = -38, check.matrix[1][1] = 41, check.matrix[1][2] = -34;
  check.matrix[2][0] = 27, check.matrix[2][1] = -29, check.matrix[2][2] = 24;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_inverse_matrix_24) {
  matrix_t A = {0}, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 3, A.matrix[0][1] = 2, A.matrix[0][2] = 2;
  A.matrix[1][0] = 2, A.matrix[1][1] = 2, A.matrix[1][2] = 8;
  A.matrix[2][0] = 3, A.matrix[2][1] = 2, A.matrix[2][2] = 2;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_25) {
  matrix_t A = {0}, result, check = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  check.matrix[0][0] = 1.0, check.matrix[0][1] = -1.0, check.matrix[0][2] = 1.0;
  check.matrix[1][0] = -38.0, check.matrix[1][1] = 41.0,
  check.matrix[1][2] = -34.0;
  check.matrix[2][0] = 27.0, check.matrix[2][1] = -29.0,
  check.matrix[2][2] = 24.0;

  A.matrix[0][0] = 2.0, A.matrix[0][1] = 5.0, A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0, A.matrix[1][1] = 3.0, A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0, A.matrix[2][1] = -2.0, A.matrix[2][2] = -3.0;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), IS_OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_inverse_matrix_26) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

int main() {
  Suite *s1 = suite_create("s21_matrix");
  TCase *tc = tcase_create("s21_matrix");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc);

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);
  tcase_add_test(tc, create_matrix_8);
  tcase_add_test(tc, create_matrix_9);
  tcase_add_test(tc, create_matrix_10);
  tcase_add_test(tc, create_matrix_11);
  tcase_add_test(tc, create_matrix_12);
  tcase_add_test(tc, create_matrix_13);

  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_2);
  tcase_add_test(tc, s21_remove_matrix_3);
  tcase_add_test(tc, s21_remove_matrix_4);
  tcase_add_test(tc, s21_remove_matrix_5);
  tcase_add_test(tc, s21_remove_matrix_6);
  tcase_add_test(tc, s21_remove_matrix_7);

  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);
  tcase_add_test(tc, s21_eq_matrix_5);
  tcase_add_test(tc, s21_eq_matrix_6);
  tcase_add_test(tc, s21_eq_matrix_7);
  tcase_add_test(tc, s21_eq_matrix_8);
  tcase_add_test(tc, s21_eq_matrix_9);
  tcase_add_test(tc, s21_eq_matrix_10);
  tcase_add_test(tc, s21_eq_matrix_11);
  tcase_add_test(tc, s21_eq_matrix_12);
  tcase_add_test(tc, s21_eq_matrix_13);
  tcase_add_test(tc, s21_eq_matrix_14);
  tcase_add_test(tc, s21_eq_matrix_15);
  tcase_add_test(tc, s21_eq_matrix_16);
  tcase_add_test(tc, s21_eq_matrix_17);
  tcase_add_test(tc, s21_eq_matrix_18);

  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  tcase_add_test(tc, s21_sum_matrix_4);
  tcase_add_test(tc, s21_sum_matrix_5);
  tcase_add_test(tc, s21_sum_matrix_6);
  tcase_add_test(tc, s21_sum_matrix_7);
  tcase_add_test(tc, s21_sum_matrix_8);
  tcase_add_test(tc, s21_sum_matrix_9);
  tcase_add_test(tc, s21_sum_matrix_10);
  tcase_add_test(tc, s21_sum_matrix_11);
  tcase_add_test(tc, s21_sum_matrix_12);
  tcase_add_test(tc, s21_sum_matrix_13);
  tcase_add_test(tc, s21_sum_matrix_14);

  tcase_add_test(tc, s21_sub_matrix_1);
  tcase_add_test(tc, s21_sub_matrix_2);
  tcase_add_test(tc, s21_sub_matrix_3);
  tcase_add_test(tc, s21_sub_matrix_4);
  tcase_add_test(tc, s21_sub_matrix_5);
  tcase_add_test(tc, s21_sub_matrix_6);
  tcase_add_test(tc, s21_sub_matrix_7);
  tcase_add_test(tc, s21_sub_matrix_8);
  tcase_add_test(tc, s21_sub_matrix_9);
  tcase_add_test(tc, s21_sub_matrix_10);

  tcase_add_test(tc, s21_mult_number_1);
  tcase_add_test(tc, s21_mult_number_2);
  tcase_add_test(tc, s21_mult_number_3);
  tcase_add_test(tc, s21_mult_number_4);
  tcase_add_test(tc, s21_mult_number_5);
  tcase_add_test(tc, s21_mult_number_6);
  tcase_add_test(tc, s21_mult_number_7);
  tcase_add_test(tc, s21_mult_number_8);
  tcase_add_test(tc, s21_mult_number_9);
  tcase_add_test(tc, s21_mult_number_10);
  tcase_add_test(tc, s21_mult_number_11);

  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);
  tcase_add_test(tc, s21_mult_matrix_5);
  tcase_add_test(tc, s21_mult_matrix_6);
  tcase_add_test(tc, s21_mult_matrix_7);
  tcase_add_test(tc, s21_mult_matrix_8);
  tcase_add_test(tc, s21_mult_matrix_9);
  tcase_add_test(tc, s21_mult_matrix_10);

  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);
  tcase_add_test(tc, s21_transpose_3);
  tcase_add_test(tc, s21_transpose_4);
  tcase_add_test(tc, s21_transpose_5);
  tcase_add_test(tc, s21_transpose_6);
  tcase_add_test(tc, s21_transpose_7);
  tcase_add_test(tc, s21_transpose_8);
  tcase_add_test(tc, s21_transpose_9);

  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_3);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);
  tcase_add_test(tc, s21_determinant_9);
  tcase_add_test(tc, s21_determinant_10);
  tcase_add_test(tc, s21_determinant_11);
  tcase_add_test(tc, s21_determinant_12);
  tcase_add_test(tc, s21_determinant_13);
  tcase_add_test(tc, s21_determinant_14);
  tcase_add_test(tc, s21_determinant_15);
  tcase_add_test(tc, s21_determinant_16);

  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);
  tcase_add_test(tc, s21_calc_complements_4);
  tcase_add_test(tc, s21_calc_complements_5);
  tcase_add_test(tc, s21_calc_complements_6);
  tcase_add_test(tc, s21_calc_complements_7);
  tcase_add_test(tc, s21_calc_complements_8);
  tcase_add_test(tc, s21_calc_complements_9);
  tcase_add_test(tc, s21_calc_complements_10);
  tcase_add_test(tc, s21_calc_complements_11);
  tcase_add_test(tc, s21_calc_complements_12);
  tcase_add_test(tc, s21_calc_complements_13);
  tcase_add_test(tc, s21_calc_complements_14);
  tcase_add_test(tc, s21_calc_complements_15);
  tcase_add_test(tc, s21_calc_complements_16);

  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);
  tcase_add_test(tc, s21_inverse_matrix_5);
  tcase_add_test(tc, s21_inverse_matrix_6);
  tcase_add_test(tc, s21_inverse_matrix_7);
  tcase_add_test(tc, s21_inverse_matrix_8);
  tcase_add_test(tc, s21_inverse_matrix_9);
  tcase_add_test(tc, s21_inverse_matrix_10);
  tcase_add_test(tc, s21_inverse_matrix_11);
  tcase_add_test(tc, s21_inverse_matrix_12);
  tcase_add_test(tc, s21_inverse_matrix_13);
  tcase_add_test(tc, s21_inverse_matrix_14);
  tcase_add_test(tc, s21_inverse_matrix_15);
  tcase_add_test(tc, s21_inverse_matrix_16);
  tcase_add_test(tc, s21_inverse_matrix_17);
  tcase_add_test(tc, s21_inverse_matrix_18);
  tcase_add_test(tc, s21_inverse_matrix_19);
  tcase_add_test(tc, s21_inverse_matrix_20);
  tcase_add_test(tc, s21_inverse_matrix_21);
  tcase_add_test(tc, s21_inverse_matrix_22);
  tcase_add_test(tc, s21_inverse_matrix_23);
  tcase_add_test(tc, s21_inverse_matrix_24);
  tcase_add_test(tc, s21_inverse_matrix_25);
  tcase_add_test(tc, s21_inverse_matrix_26);

  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}