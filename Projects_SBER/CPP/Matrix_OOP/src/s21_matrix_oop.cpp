#include "s21_matrix_oop.hpp"

void S21Matrix::CreateMatrix() {
  this->matrix_ = new double *[this->rows_];
  for (int i = 0; i < this->rows_; i++)
    this->matrix_[i] = new double[this->cols_]{0};
}

void S21Matrix::RemoveMatrix() {
  if (this->matrix_)
    for (int i = 0; i < this->rows_; i++) delete[] this->matrix_[i];
  delete[] this->matrix_;
  this->matrix_ = nullptr;
}

bool S21Matrix::SizeIsNotEqual(const S21Matrix &other) {
  return this->cols_ != other.cols_ || this->rows_ != other.rows_;
}

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(const int &rows) {
  if (rows < 1) throw std::out_of_range("ivalid size");

  for (int i = rows; i < rows_; i++) delete[] matrix_[i];

  double **tmp = new double *[rows];
  for (int i = 0; i < rows; i++)
    if (i < rows_)
      tmp[i] = matrix_[i];
    else
      tmp[i] = new double[cols_]{0};
  delete[] matrix_;
  matrix_ = tmp;

  rows_ = rows;
}

void S21Matrix::SetCols(const int &cols) {
  if (cols < 1) throw std::out_of_range("ivalid size");
  for (int i = 0; i < rows_; i++) {
    double *tmp = new double[cols]{0};
    for (int j = 0; j < cols; j++)
      if (j < cols_) tmp[j] = matrix_[i][j];

    delete[] matrix_[i];
    matrix_[i] = tmp;
  }
  cols_ = cols;
}

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->CreateMatrix();
}

S21Matrix::S21Matrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->CreateMatrix();
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  this->RemoveMatrix();
  this->rows_ = 0;
  this->cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = true;
  if (this->SizeIsNotEqual(other)) {
    result = false;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int l = 0; l < this->cols_; l++) {
        if (fabs(this->matrix_[i][l] - other.matrix_[i][l]) >= 1e-7)
          result = false;
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->SizeIsNotEqual(other)) {
    throw std::exception();
  } else {
    for (int i = 0; i < this->rows_; i++)
      for (int l = 0; l < this->cols_; l++)
        this->matrix_[i][l] += other.matrix_[i][l];
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->SizeIsNotEqual(other)) {
    throw std::exception();
  } else {
    for (int i = 0; i < this->rows_; i++)
      for (int l = 0; l < this->cols_; l++)
        this->matrix_[i][l] -= other.matrix_[i][l];
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++)
    for (int l = 0; l < this->cols_; l++) this->matrix_[i][l] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->cols_ != other.rows_) {
    throw std::exception();
  } else {
    S21Matrix result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < other.cols_; j++)
        for (int l = 0; l < this->cols_; l++)
          result.matrix_[i][j] += other.matrix_[l][j] * this->matrix_[i][l];
    }
    *this = result;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      res.matrix_[j][i] = this->matrix_[i][j];
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result = S21Matrix(this->rows_, this->cols_);
  if (this->rows_ != this->cols_) {
    throw std::exception();
  } else if (this->rows_ == 1) {
    result.matrix_[0][0] = 1;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        S21Matrix minor = S21Matrix(this->rows_ - 1, this->cols_ - 1);
        for (int r = 0, minor_row = 0; r < this->rows_; r++) {
          if (r == i) continue;
          for (int c = 0, minor_col = 0; c < this->cols_; c++) {
            if (c == j) continue;
            minor.matrix_[minor_row][minor_col] = this->matrix_[r][c];
            minor_col++;
          }
          minor_row++;
        }
        double minor_determinant = minor.Determinant();
        result.matrix_[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor_determinant;
        minor.RemoveMatrix();
      }
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0.0;
  if (this->rows_ != this->cols_) {
    throw std::exception();
  } else if (this->rows_ == 1) {
    result = this->matrix_[0][0];
  } else if (this->rows_ == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[0][1] * this->matrix_[1][0];
  } else {
    result = 0.0;
    for (int j = 0; j < this->cols_; j++) {
      S21Matrix minor = S21Matrix(this->rows_ - 1, this->cols_ - 1);
      for (int r = 1; r < this->rows_; r++) {
        for (int c = 0, minor_col = 0; c < this->cols_; c++) {
          if (c == j) continue;
          minor.matrix_[r - 1][minor_col] = this->matrix_[r][c];
          minor_col++;
        }
      }
      double minor_determinant = minor.Determinant();
      result += (j % 2 == 0 ? 1 : -1) * this->matrix_[0][j] * minor_determinant;
      minor.RemoveMatrix();
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (rows_ != cols_ || fabs(det) < 1e-7) {
    throw std::exception();
  }
  S21Matrix result(rows_, cols_);
  S21Matrix comp_tr = this->CalcComplements().Transpose();
  for (int32_t i = 0; i < rows_; ++i)
    for (int32_t j = 0; j < cols_; ++j) result(i, j) = comp_tr(i, j) / det;
  return result;
}

S21Matrix S21Matrix::operator+(S21Matrix &other) {
  S21Matrix result = *this;
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(S21Matrix &other) {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(S21Matrix &other) {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double other) {
  S21Matrix result = *this;
  result.MulNumber(other);
  return result;
}

bool S21Matrix::operator==(S21Matrix &other) { return this->EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  this->RemoveMatrix();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_];

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];

  return *this;
}

void S21Matrix::operator+=(S21Matrix &other) { this->SumMatrix(other); }

void S21Matrix::operator-=(S21Matrix &other) { this->SubMatrix(other); }

void S21Matrix::operator*=(S21Matrix &other) { this->MulMatrix(other); }

double &S21Matrix::operator()(int i, int l) {
  if (i < this->rows_ && l < this->cols_ && i >= 0 && l >= 0)
    return this->matrix_[i][l];
  throw std::exception();
}