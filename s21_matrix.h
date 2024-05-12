#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define OK 0
#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0
#define EPS 1e-7
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_print_matrix(matrix_t matrix_str);
int check_matrix(matrix_t *matrix);
int copy_matrix(matrix_t *A, matrix_t *B);
double gauss_method(matrix_t matrix);
int is_triangle_matrix(matrix_t *matrix);
double calc_third_determinant(matrix_t *matrix);
double calc_default_determinant(matrix_t *matrix);
void swap_rows(matrix_t *matrix, int last_row);
void calc_gauss_triangle_matrix(matrix_t *matrix, int row);
void calc_minor(matrix_t *matrix, matrix_t *minor, int row, int column);
#endif  // S21_MATRIX_H