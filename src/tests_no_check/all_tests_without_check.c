#include <stdio.h>
#include "all_tests_without_check.h"
#include "../s21_matrix.h"

int main() {
    printf("Testing without check...\n");
    // create_matrix_tests(s21_create_matrix, "s21_create_matrix(int rows, int columns, matrix_t*)");
    // eq_matrix_tests(s21_eq_matrix, "s21_eq_matrix(matrix_t*, matrix_t*)");
    sum_matrix_tests(s21_sum_matrix, "s21_sum_matrix(const matrix_t*, const matrix_t*, matrix_t*)");
    // sub_matrix_tests(s21_sub_matrix, "s21_sub_matrix(const matrix_t*, const matrix_t*, matrix_t*)");
    // mult_number_tests(s21_mult_number, "s21_mult_number(const matrix_t*, double, matrix_t*)");
    // mult_matrix_tests(s21_mult_matrix, "s21_mult_matrix(const matrix_t*, const matrix_t*, matrix_t*)");
    transpose_tests(s21_transpose, "s21_transpose(const matrix_t*, matrix_t*)");
    // determinant_tests(s21_determinant, "s21_determinant(const matrix_t*, double*)");
    // calc_complements_tests(s21_calc_complements, "s21_calc_complements(const matrix_t*, matrix_t*)");
    // inverse_matrix_tests(s21_inverse_matrix, "s21_inverse_matrix(const matirx_t*, matrix_t*)");
    printf("Testing is ended\n");
    return 0;
}