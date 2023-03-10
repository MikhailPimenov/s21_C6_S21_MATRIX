//
//  check_sub_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "check_matrix.h"

double loop_dbls_sub[10] = {1, -1, 0, 0.000001, 0.00000001, 10000, 1000000, 1234.5678, 1234567, 12345678};

START_TEST(normal_sub) {
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    double value1 = (rand() - loop_dbls_sub[_i])/ (rand() + 1);
    double value2 = (rand() - loop_dbls_sub[_i])/ (rand() + 1);
    matrix_t val1 = {0}, val2 = {0}, result = {0}, expected = {0};
    s21_create_matrix(rows, columns, &val1);
    s21_create_matrix(rows, columns, &val2);
    s21_create_matrix(rows, columns, &expected);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            val1.matrix[i][j] = value1;
            val2.matrix[i][j] = value2;
            expected.matrix[i][j] = value1 - value2;
            value1 += (rand() - loop_dbls_sub[_i]) / (rand() + 1);
            value2 -= (rand() - loop_dbls_sub[_i]) / (rand() + 1);
        }
    }
    ck_assert_int_eq(s21_sub_matrix(&val1, &val2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(error) {
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    matrix_t val1 = {0}, val2 = {0}, result = {0};
    s21_create_matrix(rows, columns, &val1);
    rows = rand() % 1000 + 1;
    columns = rand() % 1000 + 1;
    s21_create_matrix(rows, columns, &val2);

    ck_assert_int_eq(s21_sub_matrix(&val1, &val2, &result), C_ERROR);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
}
END_TEST

Suite *sub_matrix_suite(void) {
    Suite *s = suite_create("Sub matrix");
    TCase *tc = tcase_create("");

    tcase_add_loop_test(tc, normal_sub, 0, 10);
    tcase_add_test(tc, error);

    suite_add_tcase(s, tc);

    return s;
}

