#include "../s21_matrix.h"

int check_matrix(matrix_t *matrix) {
  if (matrix == NULL || matrix->matrix == NULL || matrix->columns == 0 ||
      matrix->rows == 0) {
    return INCORRECT_MATRIX;
  }
  return OK;
}