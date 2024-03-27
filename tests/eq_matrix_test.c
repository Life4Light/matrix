#include "s21_matrix_test.h"

START_TEST(create_1) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &m2), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(create_2) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }
  m2.matrix[2][2] = 0;
  ck_assert_int_eq(s21_eq_matrix(&m, &m2), 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(create_3) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }
  m2.matrix[0][0] = 0;
  ck_assert_int_eq(s21_eq_matrix(&m, &m2), 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(create_4) {
  const int rows = 1;
  const int cols = 1;
  matrix_t m = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &m2), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(create_5) {
  const int rows = 1;
  const int cols = 1;
  matrix_t m = {0};
  matrix_t m2 = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&m, &m2), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&m2);
}
END_TEST

Suite *suite_eq_matrix() {
  Suite *s = suite_create("suite_eq_matrix");
  TCase *tc = tcase_create("case_eq_matrix");

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_4);
  tcase_add_test(tc, create_5);

  suite_add_tcase(s, tc);
  return s;
}