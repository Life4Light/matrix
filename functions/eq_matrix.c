#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (check_matrix(A) || check_matrix(B)) {
    printf("check");
    return FAILURE;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    printf("rows");
    return FAILURE;
  }

  int status = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      if (fabs(fabs(A->matrix[i][j]) - fabs(B->matrix[i][j])) > EPS) {
        printf("%lf, %lf\n", A->matrix[i][j], B->matrix[i][j]);
        status = FAILURE;
      }
    }
  }
  return status;
}