#include "s21_matrix_test.h"

START_TEST(mult_by_zero) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  matrix_t my_result = {0};
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &result);
  s21_create_matrix(rows, cols, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i * cols + j;
      result.matrix[i][j] = 0;
    }
  }
  s21_mult_number(&m, 0, &my_result);
  ck_assert_int_eq(s21_eq_matrix(&my_result, &result), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&my_result);
}
END_TEST

START_TEST(mult_by_negative) {
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  matrix_t my_result = {0};
  s21_create_matrix(rows, cols, &my_result);
  s21_create_matrix(rows, cols, &m);
  s21_create_matrix(rows, cols, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = i * cols + j;
      result.matrix[i][j] = -m.matrix[i][j];
    }
  }
  s21_mult_number(&m, -1, &my_result);
  ck_assert_int_eq(s21_eq_matrix(&m, &result), 0);
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&my_result);
}
END_TEST

START_TEST(mult_null_pointer) {
  int status = s21_mult_number(NULL, 5, NULL);
  ck_assert_int_eq(status, 1);  // ожидается, что функция вернет -1 при попытке
                                // умножить NULL-указатель на число
}
END_TEST

Suite *suite_mult_number_matrix() {
  Suite *s = suite_create("suite_mult_number_matrix");
  TCase *tc = tcase_create("case_mult_number");

  tcase_add_test(tc, mult_by_zero);
  tcase_add_test(tc, mult_by_negative);
  tcase_add_test(tc, mult_null_pointer);

  suite_add_tcase(s, tc);
  return s;
}