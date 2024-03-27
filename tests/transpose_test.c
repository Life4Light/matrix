#include "s21_matrix_test.h"

START_TEST(transpose_square_matrix) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i * cols + j;
      result.matrix[j][i] = i * cols + j;
    }
  }
  matrix_t transposed = {0};
  s21_transpose(&m, &transposed);
  ck_assert_int_eq(s21_eq_matrix(&transposed, &result), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&transposed);
}
END_TEST

START_TEST(transpose_rectangular_matrix) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(cols, rows, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i * cols + j;
      result.matrix[j][i] = m.matrix[i][j];
    }
  }
  matrix_t transposed = {0};
  s21_transpose(&m, &transposed);
  ck_assert_int_eq(s21_eq_matrix(&transposed, &result), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&transposed);
}
END_TEST

START_TEST(transpose_null_pointer) {
  matrix_t m = {0};
  matrix_t transposed = {0};
  int status = s21_transpose(NULL, &transposed);
  ck_assert_int_eq(status, 1);
  status = s21_transpose(&m, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

Suite *suite_transpose_matrix() {
  Suite *s = suite_create("suite_transpose_matrix");
  TCase *tc = tcase_create("case_transpose_matrix");

  tcase_add_test(tc, transpose_square_matrix);
  tcase_add_test(tc, transpose_rectangular_matrix);
  tcase_add_test(tc, transpose_null_pointer);

  suite_add_tcase(s, tc);
  return s;
}