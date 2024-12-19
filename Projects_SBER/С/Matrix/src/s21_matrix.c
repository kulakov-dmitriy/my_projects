#include "s21_matrix.h"

int s21_is_correct_matrix(matrix_t *A) {
  return A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = IS_OK;
  if (rows < 1 || columns < 1 || result == NULL) {
    error = UNCORRECTED_MATRIX;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      error = UNCORRECTED_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          while (i--) {
            free(result->matrix[i]);
          }
          free(result->matrix);
          error = UNCORRECTED_MATRIX;
          break;
        }
      }
      result->rows = rows;
      result->columns = columns;
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (s21_is_correct_matrix(A)) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B) ||
      A->columns != B->columns || A->rows != B->rows) {
    return FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int l = 0; l < A->columns; l++) {
        if (fabs(A->matrix[i][l] - B->matrix[i][l]) > 1e-7) {
          return FAILURE;
        }
      }
    }
  }
  return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B)) {
    error = UNCORRECTED_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == IS_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int l = 0; l < A->columns; l++) {
          result->matrix[i][l] = A->matrix[i][l] + B->matrix[i][l];
        }
      }
    }
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B)) {
    error = UNCORRECTED_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    error = CALCULATION_ERROR;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == IS_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int l = 0; l < A->columns; l++) {
          result->matrix[i][l] = A->matrix[i][l] - B->matrix[i][l];
        }
      }
    }
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || result == NULL) {
    error = UNCORRECTED_MATRIX;
  } else if (s21_create_matrix(A->rows, A->columns, result) != IS_OK) {
    error = UNCORRECTED_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int l = 0; l < A->columns; l++) {
        result->matrix[i][l] = 0;
        result->matrix[i][l] = A->matrix[i][l] * number;
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B) ||
      result == NULL) {
    error = UNCORRECTED_MATRIX;
  } else if (A->columns != B->rows && A->rows != B->columns) {
    error = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, B->columns, result) != IS_OK) {
    error = UNCORRECTED_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int l = 0; l < A->columns; l++) {
          result->matrix[i][j] += A->matrix[i][l] * B->matrix[l][j];
        }
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || result == NULL) {
    error = UNCORRECTED_MATRIX;
  } else if (s21_create_matrix(A->columns, A->rows, result) != IS_OK) {
    error = UNCORRECTED_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A) || result == NULL)
    error = UNCORRECTED_MATRIX;
  else if (A->rows != A->columns)
    error = CALCULATION_ERROR;
  else if (A->rows == 1)
    *result = A->matrix[0][0];
  else if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else {
    *result = 0.0;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int r = 1; r < A->rows; r++) {
        for (int c = 0, minor_col = 0; c < A->columns; c++) {
          if (c == j) continue;
          minor.matrix[r - 1][minor_col] = A->matrix[r][c];
          minor_col++;
        }
      }
      double minor_determinant = 0.0;
      s21_determinant(&minor, &minor_determinant);
      *result += (j % 2 == 0 ? 1 : -1) * A->matrix[0][j] * minor_determinant;
      s21_remove_matrix(&minor);
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = IS_OK;
  if (!s21_is_correct_matrix(A)) {
    error = UNCORRECTED_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->columns, A->rows, result) != IS_OK) {
    error = UNCORRECTED_MATRIX;
  } else if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for (int r = 0, minor_row = 0; r < A->rows; r++) {
          if (r == i) continue;
          for (int c = 0, minor_col = 0; c < A->columns; c++) {
            if (c == j) continue;
            minor.matrix[minor_row][minor_col] = A->matrix[r][c];
            minor_col++;
          }
          minor_row++;
        }
        double minor_determinant = 0.0;
        s21_determinant(&minor, &minor_determinant);
        s21_remove_matrix(&minor);
        result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor_determinant;
      }
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = IS_OK;
  double determinant = 0.0;
  matrix_t complements;
  if (!s21_is_correct_matrix(A)) {
    error = UNCORRECTED_MATRIX;
  } else if (A->rows != A->columns) {
    error = CALCULATION_ERROR;
  } else if (s21_determinant(A, &determinant) != IS_OK ||
             fabs(determinant) < 1e-7) {
    error = CALCULATION_ERROR;
  } else if ((error = s21_calc_complements(A, &complements)) == IS_OK) {
    if ((error = s21_transpose(&complements, result)) == IS_OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] /= determinant;
        }
      }
    }
    s21_remove_matrix(&complements);
  }
  return error;
}