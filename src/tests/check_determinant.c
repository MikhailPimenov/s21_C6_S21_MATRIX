#include "check_matrix.h"

START_TEST(determinant_1)
{
    int size = 5;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            val1.matrix[i][j] = j;
    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, 0, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

START_TEST(determinant_2)
{
    int size = 4;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            val1.matrix[i][j] = j + i;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, 0, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

START_TEST(determinant_3)
{
    int size = 5;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);
    val1.matrix[0][1] = 6;
    val1.matrix[0][2] = -2;
    val1.matrix[0][3] = -1;
    val1.matrix[0][4] = 5;
    val1.matrix[1][3] = -9;
    val1.matrix[1][4] = -7;
    val1.matrix[2][1] = 15;
    val1.matrix[2][2] = 35;
    val1.matrix[3][1] = -1;
    val1.matrix[3][2] = -11;
    val1.matrix[3][3] = -2;
    val1.matrix[3][4] = 1;
    val1.matrix[4][0] = -2;
    val1.matrix[4][1] = -2;
    val1.matrix[4][2] = 3;
    val1.matrix[4][4] = -2;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, 2480, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

START_TEST(determinant_4)
{
    const int size = 3;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);
    val1.matrix[0][0] = 2;
    val1.matrix[0][1] = 3;
    val1.matrix[0][2] = 1;
    val1.matrix[1][0] = 7;
    val1.matrix[1][1] = 4;
    val1.matrix[1][2] = 1;
    val1.matrix[2][0] = 9;
    val1.matrix[2][1] = -2;
    val1.matrix[2][2] = 1;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, -32, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

START_TEST(determinant_5)
{
    const int size = 2;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);
    val1.matrix[0][0] = -5;
    val1.matrix[0][1] = -4;
    val1.matrix[1][0] = -2;
    val1.matrix[1][1] = -3;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, 7, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

START_TEST(determinant_6)
{
    const int size = 8;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);
    val1.matrix[0][0] = 2;
    val1.matrix[0][1] = 8;
    val1.matrix[0][2] = 7;
    val1.matrix[0][3] = 4;
    val1.matrix[0][4] = 1;
    val1.matrix[0][5] = 8;
    val1.matrix[0][6] = 3;
    val1.matrix[0][7] = 9;
    val1.matrix[1][0] = 4;
    val1.matrix[1][1] = 2;
    val1.matrix[1][2] = 6;
    val1.matrix[1][3] = 2;
    val1.matrix[1][4] = 2;
    val1.matrix[1][5] = 1;
    val1.matrix[1][6] = 5;
    val1.matrix[1][7] = 8;
    val1.matrix[2][0] = 8;
    val1.matrix[2][1] = 6;
    val1.matrix[2][2] = 7;
    val1.matrix[2][3] = 7;
    val1.matrix[2][4] = 3;
    val1.matrix[2][5] = 4;
    val1.matrix[2][6] = 4;
    val1.matrix[2][7] = 1;
    val1.matrix[3][0] = 1;
    val1.matrix[3][1] = 7;
    val1.matrix[3][2] = 0;
    val1.matrix[3][3] = 4;
    val1.matrix[3][4] = 4;
    val1.matrix[3][5] = 3;
    val1.matrix[3][6] = 0;
    val1.matrix[3][7] = 5;
    val1.matrix[4][0] = 5;
    val1.matrix[4][1] = 7;
    val1.matrix[4][2] = 5;
    val1.matrix[4][3] = 6;
    val1.matrix[4][4] = 8;
    val1.matrix[4][5] = 3;
    val1.matrix[4][6] = 1;
    val1.matrix[4][7] = 9;
    val1.matrix[5][0] = 3;
    val1.matrix[5][1] = 7;
    val1.matrix[5][2] = 8;
    val1.matrix[5][3] = 0;
    val1.matrix[5][4] = 5;
    val1.matrix[5][5] = 7;
    val1.matrix[5][6] = 0;
    val1.matrix[5][7] = 2;
    val1.matrix[6][0] = 5;
    val1.matrix[6][1] = 8;
    val1.matrix[6][2] = 3;
    val1.matrix[6][3] = 5;
    val1.matrix[6][4] = 9;
    val1.matrix[6][5] = 1;
    val1.matrix[6][6] = 2;
    val1.matrix[6][7] = 0;
    val1.matrix[7][0] = 7;
    val1.matrix[7][1] = 8;
    val1.matrix[7][2] = 7;
    val1.matrix[7][3] = 4;
    val1.matrix[7][4] = 7;
    val1.matrix[7][5] = 9;
    val1.matrix[7][6] = 1;
    val1.matrix[7][7] = 5;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&val1, &result), ERROR_OK);
    ck_assert_double_eq_tol(result, -616458, 1e-6);

    s21_remove_matrix(&val1);
}
END_TEST

Suite *determinant_matrix_suite(void)
{
    Suite *s = suite_create("Determinant");
    TCase *tc = tcase_create("");

    tcase_add_test(tc, determinant_1);
    tcase_add_test(tc, determinant_2);
    tcase_add_test(tc, determinant_3);
    tcase_add_test(tc, determinant_4);
    tcase_add_test(tc, determinant_5);
    tcase_add_test(tc, determinant_6);

    suite_add_tcase(s, tc);

    return s;
}
