#ifndef SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_
#define SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_

#include "../s21_matrix.h"

void create_matrix_tests(int algorithm(int, int, matrix_t *), const char *function_name);
void eq_matrix_tests(int algorithm(matrix_t *, matrix_t *), const char *function_name);
void sum_matrix_tests(int algorithm(matrix_t *, matrix_t *, matrix_t *), const char *function_name);
void sub_matrix_tests(int algorithm(matrix_t *, matrix_t *, matrix_t *), const char *function_name);
void mult_number_tests(int algorithm(matrix_t *, double, matrix_t *), const char *function_name);
void mult_matrix_tests(int algorithm(matrix_t *, matrix_t *, matrix_t *), const char *function_name);
void transpose_tests(int algorithm(matrix_t *, matrix_t *), const char *function_name);
void determinant_tests(int algorithm(matrix_t *, double *), const char *function_name);
void calc_complements_tests(int algorithm(matrix_t *, matrix_t *), const char *function_name);
void inverse_matrix_tests(int algorithm(matrix_t *, matrix_t *), const char *function_name);

#endif //  SRC_TESTS_ALL_TESTS_WITHOUT_CHECK_H_