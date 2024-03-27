#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrix(A) || check_matrix(B)) {
    return FAILURE;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      if (A->matrix[i][j] != B->matrix[i][j]) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}