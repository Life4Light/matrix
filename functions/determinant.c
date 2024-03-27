#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != A->rows) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result = calc_default_determinant(A);
  } else if (A->rows == 3) {
    *result = calc_third_determinant(A);
  } else {
    *result = gauss_method(*A);
  }
  return OK;
}

double calc_default_determinant(matrix_t *matrix) {
  return matrix->matrix[0][0] * matrix->matrix[1][1] -
         matrix->matrix[0][1] * matrix->matrix[1][0];
}

double calc_third_determinant(matrix_t *matrix) {
  return matrix->matrix[0][0] * matrix->matrix[1][1] * matrix->matrix[2][2] +
         matrix->matrix[0][1] * matrix->matrix[1][2] * matrix->matrix[2][0] +
         matrix->matrix[0][2] * matrix->matrix[1][0] * matrix->matrix[2][1] -
         matrix->matrix[0][2] * matrix->matrix[1][1] * matrix->matrix[2][0] -
         matrix->matrix[0][0] * matrix->matrix[1][2] * matrix->matrix[2][1] -
         matrix->matrix[0][1] * matrix->matrix[1][0] * matrix->matrix[2][2];
}

double gauss_method(matrix_t matrix) {
  double result = 1;
  for (int gauss_counter = 0; gauss_counter < matrix.rows; gauss_counter++) {
    for (int i = 1; i < matrix.rows; i++) {
      calc_gauss_triangle_matrix(&matrix, i);
    }
  }

  for (int i = 0; i < matrix.rows; i++) {
    result *= matrix.matrix[i][i];
  }
  if (result == -0) {
    result = 0;
  }

  return result;
}

void calc_gauss_triangle_matrix(matrix_t *matrix, int row) {
  for (int j = 0; j < matrix->columns; j++) {
    if (matrix->matrix[row][j] != 0 && j < row) {
      if (matrix->matrix[j][j] == 0) {
        swap_rows(matrix, j);
      }
      double multiplier = matrix->matrix[row][j] / matrix->matrix[j][j];
      for (int helper_counter = 0; helper_counter < matrix->columns;
           helper_counter++) {
        matrix->matrix[row][helper_counter] +=
            matrix->matrix[j][helper_counter] * -1 * multiplier;
      }
    }
  }
}

void swap_rows(matrix_t *matrix, int last_row) {
  for (int i = last_row + 1; i < matrix->rows; i++) {
    if (matrix->matrix[i][i] != 0) {
      double *temp = matrix->matrix[last_row];
      matrix->matrix[last_row] = matrix->matrix[i];
      matrix->matrix[i] = temp;
    }
  }
}
