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
      result.matrix[i][j] = 0;
    }
  }
  matrix_t sub = {0};
  s21_create_matrix(rows, cols, &sub);
  s21_sub_matrix(&m1, &m2, &sub);
  ck_assert_int_eq(s21_eq_matrix(&sub, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sub);
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
      result.matrix[i][j] = i - j;
    }
  }
  matrix_t sub = {0};
  s21_sub_matrix(&m1, &m2, &sub);
  ck_assert_int_eq(s21_eq_matrix(&sub, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sub);
}
END_TEST

START_TEST(sub_different_sizes) {
  const int rows1 = 3;
  const int cols1 = 3;
  const int rows2 = 2;
  const int cols2 = 2;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows1, cols1, &m1);
  s21_create_matrix(rows2, cols2, &m2);
  matrix_t sub = {0};
  int status = s21_sub_matrix(&m1, &m2, &sub);
  ck_assert_int_eq(status, 2);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&sub);
}
END_TEST

START_TEST(sub_null_pointers) {
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t sub = {0};
  int status = s21_sub_matrix(NULL, &m2, &sub);
  ck_assert_int_eq(status, 1);
  status = s21_sub_matrix(&m1, NULL, &sub);
  ck_assert_int_eq(status, 1);
  status = s21_sub_matrix(&m1, &m2, NULL);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(sub_zero_matrix) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m1 = {0};
  matrix_t m2 = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  s21_create_matrix(rows, cols, &result);
  matrix_t sub = {0};
  s21_sub_matrix(&m1, &m2, &sub);
  ck_assert_int_eq(s21_eq_matrix(&sub, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sub);
}
END_TEST

START_TEST(sub_negative_values) {
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
      result.matrix[i][j] = -i + j;
    }
  }
  matrix_t sub = {0};
  s21_sub_matrix(&m1, &m2, &sub);
  ck_assert_int_eq(s21_eq_matrix(&sub, &result), 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&sub);
}
END_TEST

Suite *suite_sub_matrix() {
  Suite *s = suite_create("suite_sub_matrix");
  TCase *tc = tcase_create("case_sub_matrix");

  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_different_sizes);
  tcase_add_test(tc, sub_null_pointers);
  tcase_add_test(tc, sub_zero_matrix);
  tcase_add_test(tc, sub_negative_values);

  suite_add_tcase(s, tc);
  return s;
}