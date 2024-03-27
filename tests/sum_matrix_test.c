#include "s21_matrix_test.h"
START_TEST(sub_1) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  s21_create_matrix(rows, cols, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
      result.matrix[i][j] = 2;
    }
  }
  matrix_t sum = {0};
  s21_sum_matrix(&m1, &m2, &sum);
  ck_assert_int_eq(s21_eq_matrix(&sum, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sum);
}
END_TEST

START_TEST(sub_2) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  s21_create_matrix(rows, cols, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = i;
      m2.matrix[i][j] = j;
      result.matrix[i][j] = i + j;
    }
  }
  matrix_t sum = {0};
  s21_sum_matrix(&m1, &m2, &sum);
  ck_assert_int_eq(s21_eq_matrix(&sum, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sum);
}
END_TEST

START_TEST(sum_different_sizes) {
  const int rows1 = 3;
  const int cols1 = 3;
  const int rows2 = 2;
  const int cols2 = 2;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows1, cols1, &m1);
  s21_create_matrix(rows2, cols2, &m2);
  matrix_t sum = {0};
  int status = s21_sum_matrix(&m1, &m2, &sum);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&sum);
}
END_TEST

START_TEST(sum_null_pointers) {
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t sum = {0};
  int status = s21_sum_matrix(NULL, &m2, &sum);
  ck_assert_int_eq(status, 1);
  status = s21_sum_matrix(&m1, NULL, &sum);
  ck_assert_int_eq(status, 1);
  status = s21_sum_matrix(&m1, &m2, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(sum_zero_matrix) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  s21_create_matrix(rows, cols, &result);
  matrix_t sum = {0};
  s21_sum_matrix(&m1, &m2, &sum);
  ck_assert_int_eq(s21_eq_matrix(&sum, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sum);
}
END_TEST

START_TEST(sum_negative_values) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  s21_create_matrix(rows, cols, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = -i;
      m2.matrix[i][j] = -j;
      result.matrix[i][j] = -i - j;
    }
  }
  matrix_t sum = {0};
  s21_sum_matrix(&m1, &m2, &sum);
  ck_assert_int_eq(s21_eq_matrix(&sum, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sum);
}
END_TEST

Suite *suite_sum_matrix() {
  Suite *s = suite_create("suite_sum_matrix");
  TCase *tc = tcase_create("case_sum_matrix");

  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sum_different_sizes);
  tcase_add_test(tc, sum_null_pointers);
  tcase_add_test(tc, sum_zero_matrix);
  tcase_add_test(tc, sum_negative_values);

  suite_add_tcase(s, tc);
  return s;
}