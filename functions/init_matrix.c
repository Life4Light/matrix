#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return INCORRECT_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = malloc(rows * (sizeof(double *)));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->columns = 0;
  A->rows = 0;
}