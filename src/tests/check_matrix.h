#ifndef SRC_TESTS_CHECK_MATRIX_H_
#define SRC_TESTS_CHECK_MATRIX_H_

#include <check.h>
#include <stdlib.h>
#include <time.h>

#include "../s21_matrix.h"

#define ONE_MATRIX                                             \
  for (int i_row = 0; i_row < A.rows; i_row++) {               \
    for (int i_column = 0; i_column < A.columns; i_column++) { \
      A.matrix[i_row][i_column] = (i_row == i_column) ? 1 : 0; \
    }                                                          \
  }

Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *sub_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *mult_matrix_suite(void);
Suite *transpose_matrix_suite(void);
Suite *complements_matrix_suite(void);
Suite *determinant_matrix_suite(void);
Suite *inverse_matrix_suite(void);
Suite *extrapack_suite(void);
Suite *from_no_check_suite(void);

int s21_print_matrix(matrix_t A);

#endif  // SRC_TESTS_CHECK_MATRIX_H_
