#include "check_matrix.h"

START_TEST(transpose) {
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    matrix_t val1 = {0}, result = {0}, expected = {0};
    s21_create_matrix(rows, columns, &val1);
    s21_create_matrix(columns, rows, &expected);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            double value1 = (rand() - 298.3)/ (rand() + 1);
            val1.matrix[i][j] = value1;
            expected.matrix[j][i] = value1;
        }
    }

    ck_assert_int_eq(s21_transpose(&val1, &result), ERROR_OK);
    ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);

    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
}
END_TEST

Suite *transpose_matrix_suite(void) {
    Suite *s = suite_create("Transpose");
    TCase *tc = tcase_create("");

    tcase_add_loop_test(tc, transpose, 0, 100);

    suite_add_tcase(s, tc);

    return s;
}
