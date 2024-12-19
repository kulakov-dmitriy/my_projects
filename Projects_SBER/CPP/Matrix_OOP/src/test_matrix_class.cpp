#include <gtest/gtest.h>

#include "s21_matrix_oop.hpp"

TEST(S21MatrixTest, EqualMatrices) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 7;
  B(2, 1) = 8;
  B(2, 2) = 9;

  EXPECT_TRUE(A.EqMatrix(B));
  EXPECT_TRUE(A == B);
}

TEST(S21MatrixTest, DifferentMatrices) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 5;
  B(2, 1) = 8;
  B(2, 2) = 9;

  EXPECT_FALSE(A.EqMatrix(B));
  EXPECT_FALSE(A == B);
}

TEST(S21MatrixTest, DifferentSizes) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;

  EXPECT_FALSE(A.EqMatrix(B));
  EXPECT_FALSE(A == B);
}

TEST(S21MatrixTest, SumMatrices) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix expected(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 7;
  B(2, 1) = 8;
  B(2, 2) = 9;

  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(0, 2) = 6;
  expected(1, 0) = 8;
  expected(1, 1) = 10;
  expected(1, 2) = 12;
  expected(2, 0) = 14;
  expected(2, 1) = 16;
  expected(2, 2) = 18;

  A.SumMatrix(B);

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, SumDifferentSizes) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;

  EXPECT_ANY_THROW(A.SumMatrix(B));
}

TEST(S21MatrixTest, SubMatrices) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 7;
  B(2, 1) = 8;
  B(2, 2) = 9;

  expected(0, 0) = 0;
  expected(0, 1) = 0;
  expected(0, 2) = 0;
  expected(1, 0) = 0;
  expected(1, 1) = 0;
  expected(1, 2) = 0;
  expected(2, 0) = 0;
  expected(2, 1) = 0;
  expected(2, 2) = 0;

  A.SubMatrix(B);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, SubDifferentSizes) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  EXPECT_ANY_THROW(A.SubMatrix(B));
}

TEST(S21MatrixTest, MultNumberMatrix) {
  S21Matrix A(3, 3);
  double number = 2;
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(0, 2) = 6;
  expected(1, 0) = 8;
  expected(1, 1) = 10;
  expected(1, 2) = 12;
  expected(2, 0) = 14;
  expected(2, 1) = 16;
  expected(2, 2) = 18;

  A.MulNumber(number);

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, MultNumber) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 12.8;
  expected(0, 2) = 19.2;
  expected(1, 0) = 25.6;
  expected(1, 1) = 32;
  expected(1, 2) = 38.4;
  expected(2, 0) = 44.8;
  expected(2, 1) = 51.2;
  expected(2, 2) = 57.6;

  A.MulNumber(6.4);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, MultMatrices) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(1, 0) = 4;
  B(1, 1) = 5;
  B(1, 2) = 6;
  B(2, 0) = 7;
  B(2, 1) = 8;
  B(2, 2) = 9;

  expected(0, 0) = 30;
  expected(0, 1) = 36;
  expected(0, 2) = 42;
  expected(1, 0) = 66;
  expected(1, 1) = 81;
  expected(1, 2) = 96;
  expected(2, 0) = 102;
  expected(2, 1) = 126;
  expected(2, 2) = 150;

  A.MulMatrix(B);

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, MultDifferentSize) {
  S21Matrix A(3, 3);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 4;
  B(1, 1) = 5;

  EXPECT_ANY_THROW(A.MulMatrix(B));
}

TEST(S21MatrixTest, TransposeMatrix) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 2);
  S21Matrix expected(3, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  expected(0, 0) = 1;
  expected(0, 1) = 4;
  expected(1, 0) = 2;
  expected(1, 1) = 5;
  expected(2, 0) = 3;
  expected(2, 1) = 6;

  B = A.Transpose();
  EXPECT_TRUE(B == expected);
}

TEST(S21MatrixTest, Determinant) {
  S21Matrix A(3, 3);
  double det;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  double expected_det = 0;
  det = A.Determinant();

  EXPECT_DOUBLE_EQ(expected_det, det);
}

TEST(S21MatrixTest, DeterminantUncorrectSize) {
  S21Matrix A(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  EXPECT_ANY_THROW(A.Determinant());
}

TEST(S21MatrixTest, CalcComplementsTest) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  S21Matrix result = A.CalcComplements();

  EXPECT_TRUE(result == expected);
}

TEST(S21MatrixTest, CalcComplementsTestUncorrect) {
  S21Matrix A(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;

  EXPECT_ANY_THROW(A.CalcComplements());
}

TEST(S21MatrixTest, setColsTestReduce) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(1, 0) = 4;
  expected(1, 1) = 5;
  expected(2, 0) = 7;
  expected(2, 1) = 8;

  A.SetCols(2);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, setColsTestIncrise) {
  S21Matrix A(2, 2);
  S21Matrix expected(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;

  A(1, 0) = 4;
  A(1, 1) = 5;

  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(0, 2) = 0;
  expected(1, 0) = 4;
  expected(1, 1) = 5;
  expected(1, 2) = 0;

  A.SetCols(3);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, setRowsTestreduce) {
  S21Matrix A(3, 3);
  S21Matrix expected(2, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;
  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(0, 2) = 3;
  expected(1, 0) = 4;
  expected(1, 1) = 5;
  expected(1, 2) = 6;

  A.SetRows(2);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, setRowsTestincrise) {
  S21Matrix A(2, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  expected(0, 0) = 1;
  expected(0, 1) = 2;
  expected(0, 2) = 3;
  expected(1, 0) = 4;
  expected(1, 1) = 5;
  expected(1, 2) = 6;
  expected(2, 0) = 0;
  expected(2, 1) = 0;
  expected(2, 2) = 0;
  A.SetRows(3);
  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, InverseMatrixTest) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  S21Matrix result = A.InverseMatrix();

  EXPECT_TRUE(result == expected);
}

TEST(S21MatrixTest, InverseMatrixTestUncorrect) {
  S21Matrix A(2, 3);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;

  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(S21MatrixTest, AddMatrices) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  S21Matrix result = A + B;
  EXPECT_TRUE(result == expected);
}

TEST(S21MatrixTest, SubtractMatrices) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 7;
  B(1, 1) = 8;

  expected(0, 0) = 4;
  expected(0, 1) = 4;
  expected(1, 0) = 4;
  expected(1, 1) = 4;

  S21Matrix result = B - A;
  EXPECT_TRUE(result == expected);
}

TEST(S21MatrixTest, MultiplyMatrices) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  B(0, 0) = 7;
  B(0, 1) = 10;
  B(1, 0) = 8;
  B(1, 1) = 11;
  B(2, 0) = 9;
  B(2, 1) = 12;

  expected(0, 0) = 50;
  expected(0, 1) = 68;
  expected(1, 0) = 122;
  expected(1, 1) = 167;

  S21Matrix result = A * B;
  EXPECT_TRUE(result == expected);
}

TEST(S21MatrixTest, MultiplyNumber) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  expected(0, 0) = 6.4;
  expected(0, 1) = 12.8;
  expected(0, 2) = 19.2;
  expected(1, 0) = 25.6;
  expected(1, 1) = 32;
  expected(1, 2) = 38.4;
  expected(2, 0) = 44.8;
  expected(2, 1) = 51.2;
  expected(2, 2) = 57.6;

  EXPECT_TRUE(A * 6.4 == expected);
}

TEST(S21MatrixTest, EqualOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 3;
  B(1, 1) = 4;
  EXPECT_TRUE(A == B);
}

TEST(S21MatrixTest, AssignmentOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B = A;

  EXPECT_TRUE(B == A);
}

TEST(S21MatrixTest, MultiplyAssignmentOperator) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;

  B(0, 0) = 7;
  B(0, 1) = 10;
  B(1, 0) = 8;
  B(1, 1) = 11;
  B(2, 0) = 9;
  B(2, 1) = 12;

  expected(0, 0) = 50;
  expected(0, 1) = 68;
  expected(1, 0) = 122;
  expected(1, 1) = 167;

  A *= B;

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, AddAssignmentOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  B(0, 0) = 5;
  B(0, 1) = 6;
  B(1, 0) = 7;
  B(1, 1) = 8;

  expected(0, 0) = 6;
  expected(0, 1) = 8;
  expected(1, 0) = 10;
  expected(1, 1) = 12;

  A += B;

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, SubtractAssignmentOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 5;
  A(0, 1) = 7;
  A(1, 0) = 9;
  A(1, 1) = 11;

  B(0, 0) = 2;
  B(0, 1) = 4;
  B(1, 0) = 6;
  B(1, 1) = 8;

  expected(0, 0) = 3;
  expected(0, 1) = 3;
  expected(1, 0) = 3;
  expected(1, 1) = 3;

  A -= B;

  EXPECT_TRUE(A == expected);
}

TEST(S21MatrixTest, GetCol) {
  S21Matrix mat(3, 2);
  EXPECT_NO_THROW(mat.GetCols());
  EXPECT_TRUE(mat.GetCols() == 2);
}

TEST(S21MatrixTest, GetRow) {
  S21Matrix mat(3, 2);
  EXPECT_NO_THROW(mat.GetRows());
  EXPECT_TRUE(mat.GetRows() == 3);
}

TEST(S21MatrixTest, SetValue) {
  S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(1, 1) = 2.0;

  EXPECT_NO_THROW(mat(1, 1) = 3.0);
  EXPECT_THROW(mat(2, 2) = 1.0, std::exception);
}

TEST(S21MatrixTest, DefaultConstructor) {
  S21Matrix mat;
  EXPECT_THROW(mat(6, 6), std::exception);
}

TEST(S21MatrixTest, ParameterizedConstructor) {
  S21Matrix mat(2, 3);
  EXPECT_NO_THROW(mat(1, 2) = 5.0);
}

TEST(S21MatrixTest, CopyConstructor) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21Matrix mat2(mat1);

  EXPECT_NO_THROW(mat2(0, 0) = 1.0);
  EXPECT_NO_THROW(mat2(1, 1) = 4.0);
}

TEST(S21MatrixTest, MoveConstructor) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;

  S21Matrix mat2(std::move(mat1));

  EXPECT_NO_THROW(mat2(0, 0) = 1.0);
  EXPECT_THROW(mat1(0, 0) = 1.0, std::exception);
}