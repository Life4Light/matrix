#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->columns || A->rows != B->rows) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);

  int result_row = A->rows;
  int result_column = A->columns;
  for (int row = 0; row < result_row; row++) {
    for (int column = 0; column < result_column; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] + B->matrix[row][column];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->columns || A->rows != B->rows) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);

  int result_row = A->rows;
  int result_column = A->columns;
  for (int row = 0; row < result_row; row++) {
    for (int column = 0; column < result_column; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] - B->matrix[row][column];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  s21_create_matrix(A->rows, A->columns, result);

  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] = A->matrix[row][column] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B)) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }

  return OK;
}