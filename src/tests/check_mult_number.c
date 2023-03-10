//
//  check_mult_number.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "check_matrix.h"

double loop_dbls_mnum[10] = {1, -1, 0, 0.000001, 0.00000001, 10000, 1000000, 1234.5678, 1234567, 12345678};

START_TEST(mult_num) {
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    double value1 = (rand() - loop_dbls_mnum[_i])/ (rand() + 1);
    double value2 = (rand() - loop_dbls_mnum[_i])/ (rand() + 1);
    matrix_t val1 = {0}, result = {0}, expected = {0};
    s21_create_matrix(rows, columns, &val1);
    s21_create_matrix(rows, columns, &expected);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            val1.matrix[i][j] = value1;
            expected.matrix[i][j] = value1 * value2;
            value1 += (rand() - loop_dbls_mnum[_i]) / (rand() + 1);
        }
    }
    ck_assert_int_eq(s21_mult_number(&val1, value2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite(void) {
    Suite *s = suite_create("Mult number");
    TCase *tc = tcase_create("");

    tcase_add_loop_test(tc, mult_num, 0, 10);

    suite_add_tcase(s, tc);

    return s;
}

