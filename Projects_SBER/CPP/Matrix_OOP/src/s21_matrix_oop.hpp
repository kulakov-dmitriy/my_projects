#ifndef S21_MATRIX_OOP_HPP_
#define S21_MATRIX_OOP_HPP_

#include <math.h>

#include <cstring>
#include <iostream>
#include <vector>

#define IS_OK 0
#define UNCORRECTED_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+(S21Matrix& other);
  S21Matrix operator-(S21Matrix& other);
  S21Matrix operator*(S21Matrix& other);
  S21Matrix operator*(double other);
  bool operator==(S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  void operator+=(S21Matrix& other);
  void operator-=(S21Matrix& other);
  void operator*=(S21Matrix& other);
  double& operator()(int i, int l);

  int GetRows();
  int GetCols();
  void SetRows(const int& rows);
  void SetCols(const int& cols);
  void CreateMatrix();
  void RemoveMatrix();
  bool SizeIsNotEqual(const S21Matrix& other);

  void FreeMatrix();
};

#endif