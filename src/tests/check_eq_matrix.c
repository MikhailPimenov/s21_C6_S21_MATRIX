#include "check_matrix.h"

double loop_dbls_eq[10] = {1, -1, 0, 0.000001, 0.00000001, 10000, 1000000, 1234.5678, 1234567, 12345678};

START_TEST(eq_matrix)
{
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    double value = (rand() - loop_dbls_eq[_i]) / (rand() + 1);
    matrix_t val1 = {0}, val2 = {0};
    s21_create_matrix(rows, columns, &val1);
    s21_create_matrix(rows, columns, &val2);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            val1.matrix[i][j] = value;
            val2.matrix[i][j] = value;
            value += (rand() - 1234) / (rand() + 1);
        }
    }
    ck_assert_int_eq(s21_eq_matrix(&val1, &val2), SUCCESS);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
}
END_TEST

START_TEST(not_eq)
{
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    double value = (rand() - loop_dbls_eq[_i]) / (rand() + 1);
    matrix_t val1 = {0}, val2 = {0};
    s21_create_matrix(rows, columns, &val1);
    s21_create_matrix(rows, columns, &val2);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            val1.matrix[i][j] = value;
            value += (rand() - loop_dbls_eq[_i]) / (rand() + 1);
            val2.matrix[i][j] = value;
        }
    }
    ck_assert_int_eq(s21_eq_matrix(&val1, &val2), FAILURE);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
}
END_TEST

START_TEST(error)
{
    matrix_t val1 = {0}, val2 = {0};
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    s21_create_matrix(rows, columns, &val1);
    rows = rand() % 1000 + 1;
    columns = rand() % 1000 + 1;
    s21_create_matrix(rows, columns, &val2);
    ck_assert_int_eq(s21_eq_matrix(&val1, &val2), FAILURE);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
}
END_TEST

Suite *eq_matrix_suite(void)
{
    Suite *s = suite_create("EQ");
    TCase *tc = tcase_create("eq");

    tcase_add_loop_test(tc, eq_matrix, 0, 10);
    tcase_add_loop_test(tc, not_eq, 0, 10);
    tcase_add_test(tc, error);

    suite_add_tcase(s, tc);

    return s;
}
