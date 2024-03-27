#include "../s21_matrix.h"
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  double det = 0;
  s21_determinant(A, &det);
  if (det == 0) {
    return CALCULATION_ERROR;
  }
  matrix_t new_matrix;
  s21_create_matrix(A->rows, A->columns, &new_matrix);

  s21_calc_complements(A, &new_matrix);
  s21_transpose(&new_matrix, result);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] *= -1;
    }
  }
  s21_remove_matrix(&new_matrix);
  return OK;
}
