#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrix(A) || check_matrix(B)) {
    return FAILURE;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  int status = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      if (fabs(fabs(A->matrix[i][j]) - fabs(B->matrix[i][j])) > EPS) {
        status = FAILURE;
      }
    }
  }
  return status;
}