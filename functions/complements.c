#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns || A->rows == 1) {
    return CALCULATION_ERROR;
  }

  s21_create_matrix(A->rows, A->columns, result);

  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      calc_minor(A, &minor, i, j);
      double determinant;
      s21_determinant(&minor, &determinant);
      result->matrix[i][j] = pow(-1, i + j) * determinant;
    }
  }
  s21_remove_matrix(&minor);
  return OK;
}

void calc_minor(matrix_t *matrix, matrix_t *minor, int row, int column) {
  int minor_row = 0;
  int minor_column = 0;
  for (int i = 0; i < matrix->rows; i++) {
    if (i != row) {
      for (int j = 0; j < matrix->columns; j++) {
        if (j != column) {
          minor->matrix[minor_row][minor_column] = matrix->matrix[i][j];
          minor_column++;
        }
      }
      minor_row++;
      minor_column = 0;
    }
  }
}