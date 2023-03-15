#include <limits.h>

#include "../s21_common.h"
#include "check_matrix.h"

static const double g_epsilon = 1e-8;

START_TEST(calc_complements_0)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);

    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 0.0;
    m.matrix[1][1] = 4.0;
    m.matrix[1][2] = 2.0;
    m.matrix[2][0] = 5.0;
    m.matrix[2][1] = 2.0;
    m.matrix[2][2] = 1.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_calc_complements(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 10.0;
    expected_result.matrix[0][2] = -20.0;
    expected_result.matrix[1][0] = 4.0;
    expected_result.matrix[1][1] = -14.0;
    expected_result.matrix[1][2] = 8.0;
    expected_result.matrix[2][0] = -8.0;
    expected_result.matrix[2][1] = -2.0;
    expected_result.matrix[2][2] = 4.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_1_calculation_error_not_square)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 4, &m);

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_calc_complements(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);

    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_2)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);

    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 4.0;
    m.matrix[1][1] = 5.0;
    m.matrix[1][2] = 6.0;
    m.matrix[2][0] = 7.0;
    m.matrix[2][1] = 8.0;
    m.matrix[2][2] = 9.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_calc_complements(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = -3.0;  //  1 * (5*9 - 8*6) =  1 * (45 - 48) = -1 * (-3)  =   3
    expected_result.matrix[0][1] = 6.0;   // -1 * (4*9 - 7*6) = -1 * (36 - 42) = -1 * (-6)  =   6
    expected_result.matrix[0][2] = -3.0;  //  1 * (4*8 - 7*5) =  1 * (32 - 35) =  1 * (-3)  =  -3
    expected_result.matrix[1][0] = 6.0;   // -1 * (2*9 - 8*3) = -1 * (18 - 24) = -1 * (-6)  =   6
    expected_result.matrix[1][1] = -12.0; //  1 * (1*9 - 7*3) =  1 * (9  - 21) =  1 * (-12) = -12
    expected_result.matrix[1][2] = 6.0;   // -1 * (1*8 - 7*2) = -1 * (8  - 14) = -1 * (-6)  =   6
    expected_result.matrix[2][0] = -3.0;  //  1 * (2*6 - 5*3) =  1 * (12 - 15) =  1 * (-3)  =  -3
    expected_result.matrix[2][1] = 6.0;   // -1 * (1*6 - 4*3) = -1 * (6  - 12) = -1 * (-6)  =   6
    expected_result.matrix[2][2] = -3.0;  //  1 * (1*5 - 4*2) =  1 * (5  -  8) =  1 * (-3)  =  -3

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(calc_complements_3_incorrect_matrix_null)
{
    matrix_t actual_result;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_calc_complements(NULL, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(calc_complements_4_incorrect_matrix_null)
{
    matrix_t m;
    matrix_t actual_result;
    s21_create_matrix(5, 5, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_calc_complements(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_0_incorrect_matrix_negative_row)
{
    matrix_t matrix;
    const int rows = -10;
    const int columns = 7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_1_incorrect_matrix_negative_column)
{
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_2_incorrect_matrix_negative_both)
{
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_3_incorrect_matrix_negative_and_null)
{
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_4_incorrect_matrix_null)
{
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_5_incorrect_matrix_too_large)
{
    matrix_t matrix;
    const int rows = INT_MAX / 2;
    const int columns = INT_MAX / 2;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);

    ck_assert_int_eq(actual_code, expected_code);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
}
END_TEST

// determinant============================================================
// determinant============================================================
// determinant============================================================

START_TEST(determinant_0)
{
    matrix_t m;
    s21_create_matrix(1, 1, &m);
    m.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 1.23;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_1)
{
    matrix_t m;
    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 4.0;
    m.matrix[0][1] = 2.0;
    m.matrix[1][0] = 2.0;
    m.matrix[1][1] = 1.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_2)
{
    matrix_t m;
    s21_create_matrix(3, 3, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 4.0;
    m.matrix[1][1] = 5.0;
    m.matrix[1][2] = 6.0;
    m.matrix[2][0] = 7.0;
    m.matrix[2][1] = 8.0;
    m.matrix[2][2] = 9.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_3)
{
    matrix_t m;
    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 9.0;
    m.matrix[0][1] = 4.0;
    m.matrix[1][0] = 3.0;
    m.matrix[1][1] = 7.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 51.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_4)
{
    matrix_t m;
    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] = 1.5;
    m.matrix[0][1] = 2.5;
    m.matrix[0][2] = 3.5;
    m.matrix[0][3] = 4.5;
    m.matrix[1][0] = 5.5;
    m.matrix[1][1] = 6.5;
    m.matrix[1][2] = 7.5;
    m.matrix[1][3] = 8.5;
    m.matrix[2][0] = 9.5;
    m.matrix[2][1] = 10.5;
    m.matrix[2][2] = 11.5;
    m.matrix[2][3] = 12.5;
    m.matrix[3][0] = 13.5;
    m.matrix[3][1] = 14.5;
    m.matrix[3][2] = 15.5;
    m.matrix[3][3] = 16.5;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_5)
{
    matrix_t m;
    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] = 1.1;
    m.matrix[0][1] = 2.2;
    m.matrix[0][2] = 3.3;
    m.matrix[0][3] = 4.4;
    m.matrix[0][4] = 5.5;
    m.matrix[1][0] = 6.6;
    m.matrix[1][1] = 7.7;
    m.matrix[1][2] = 8.8;
    m.matrix[1][3] = 9.9;
    m.matrix[1][4] = 10.10;
    m.matrix[2][0] = 11.11;
    m.matrix[2][1] = 12.12;
    m.matrix[2][2] = 13.13;
    m.matrix[2][3] = 14.14;
    m.matrix[2][4] = 15.15;
    m.matrix[3][0] = 16.16;
    m.matrix[3][1] = 17.17;
    m.matrix[3][2] = 18.18;
    m.matrix[3][3] = 19.19;
    m.matrix[3][4] = 20.20;
    m.matrix[4][0] = 21.21;
    m.matrix[4][1] = 22.22;
    m.matrix[4][2] = 23.23;
    m.matrix[4][3] = 24.24;
    m.matrix[4][4] = 25.25;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_6)
{
    matrix_t m;
    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[0][3] = 5.0;
    m.matrix[0][4] = 7.0;
    m.matrix[1][0] = 11.0;
    m.matrix[1][1] = 13.0;
    m.matrix[1][2] = 17.0;
    m.matrix[1][3] = 19.0;
    m.matrix[1][4] = 23.0;
    m.matrix[2][0] = 29.0;
    m.matrix[2][1] = 31.0;
    m.matrix[2][2] = 37.0;
    m.matrix[2][3] = 41.0;
    m.matrix[2][4] = 43.0;
    m.matrix[3][0] = 47.0;
    m.matrix[3][1] = 51.0;
    m.matrix[3][2] = 53.0;
    m.matrix[3][3] = 59.0;
    m.matrix[3][4] = 61.0;
    m.matrix[4][0] = 67.0;
    m.matrix[4][1] = 71.0;
    m.matrix[4][2] = 73.0;
    m.matrix[4][3] = 79.0;
    m.matrix[4][4] = 83.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = -2256.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_7_calculation_error_not_square)
{
    matrix_t m;
    s21_create_matrix(2, 3, &m);

    const int expected_code = ERROR_CALCULATION_ERROR;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_8_incorrect_matrix_null)
{
    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(NULL, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);
}
END_TEST

START_TEST(determinant_9_incorrect_matrix_null)
{
    matrix_t m;
    s21_create_matrix(6, 6, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, NULL);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_10_incorrect_matrix_null)
{
    matrix_t m;
    s21_create_matrix(5, 5, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, NULL);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
}
END_TEST

// eq_matrix==============================================================
// eq_matrix==============================================================
// eq_matrix==============================================================

START_TEST(eq_matrix_0)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_1)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.24;

    const int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_2)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_3)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_4)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_5)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231001;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    const int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_6)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231001;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    const int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_7)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_8)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(3, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    m1.matrix[2][0] = 1.0203;
    m2.matrix[2][0] = 1.0203;

    m1.matrix[2][1] = 1.0023;
    m2.matrix[2][1] = 1.0023;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_9)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(3, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    m1.matrix[2][0] = 1.0203;
    m2.matrix[2][0] = 1.0203;

    m1.matrix[2][1] = 1.0023;
    m2.matrix[2][1] = 1.002300000001;

    const int expected = SUCCESS;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_10)
{
    matrix_t m1;
    matrix_t m2;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(3, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    m1.matrix[0][1] = 1.203;
    m2.matrix[0][1] = 1.203;

    m1.matrix[1][0] = 1.231;
    m2.matrix[1][0] = 1.231;

    m1.matrix[1][1] = 1.023;
    m2.matrix[1][1] = 1.023;

    m1.matrix[2][0] = 1.0203;
    m2.matrix[2][0] = 1.0203;

    m1.matrix[2][1] = 1.0023;
    m2.matrix[2][1] = 1.00231;

    const int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(eq_matrix_11_set_null)
{
    matrix_t m1;
    matrix_t m2;

    set_null(&m1);
    s21_create_matrix(3, 2, &m2);

    m2.matrix[0][0] = 1.23;

    m2.matrix[0][1] = 1.203;

    m2.matrix[1][0] = 1.231;

    m2.matrix[1][1] = 1.023;

    m2.matrix[2][0] = 1.0203;

    m2.matrix[2][1] = 1.00231;

    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_12_set_null)
{
    matrix_t m1;
    matrix_t m2;

    set_null(&m1);
    s21_create_matrix(3, 2, &m2);

    m2.matrix[0][0] = 1.23;

    m2.matrix[0][1] = 1.203;

    m2.matrix[1][0] = 1.231;

    m2.matrix[1][1] = 1.023;

    m2.matrix[2][0] = 1.0203;

    m2.matrix[2][1] = 1.00231;

    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m2, &m1);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_13_set_null)
{
    matrix_t m1;
    matrix_t m2;

    set_null(&m1);
    set_null(&m2);

    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);
}
END_TEST

START_TEST(eq_matrix_14_null)
{
    matrix_t m2;
    s21_create_matrix(2, 2, &m2);
    m2.matrix[0][0] = 1.23;

    int expected = FAILURE;
    const int actual = s21_eq_matrix(NULL, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_15_null)
{
    matrix_t m2;
    s21_create_matrix(2, 2, &m2);
    m2.matrix[0][0] = 1.23;

    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m2, NULL);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_matrix_16_null)
{
    int expected = FAILURE;
    const int actual = s21_eq_matrix(NULL, NULL);

    ck_assert_int_eq(actual, expected);
}
END_TEST

// inverse_matrix=========================================================
// inverse_matrix=========================================================
// inverse_matrix=========================================================

START_TEST(inverse_matrix_0)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);
    m.matrix[0][0] = 2.0;
    m.matrix[0][1] = 5.0;
    m.matrix[0][2] = 7.0;
    m.matrix[1][0] = 6.0;
    m.matrix[1][1] = 3.0;
    m.matrix[1][2] = 4.0;
    m.matrix[2][0] = 5.0;
    m.matrix[2][1] = -2.0;
    m.matrix[2][2] = -3.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 1.0;
    expected_result.matrix[0][1] = -1.0;
    expected_result.matrix[0][2] = 1.0;
    expected_result.matrix[1][0] = -38.0;
    expected_result.matrix[1][1] = 41.0;
    expected_result.matrix[1][2] = -34.0;
    expected_result.matrix[2][0] = 27.0;
    expected_result.matrix[2][1] = -29.0;
    expected_result.matrix[2][2] = 24.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_1)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 1.0;
    m.matrix[0][2] = 2.0;
    m.matrix[1][0] = 2.0;
    m.matrix[1][1] = 3.0;
    m.matrix[1][2] = 3.0;
    m.matrix[2][0] = 4.0;
    m.matrix[2][1] = 4.0;
    m.matrix[2][2] = 5.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = -1.0;
    expected_result.matrix[0][1] = -1.0;
    expected_result.matrix[0][2] = 1.0;
    expected_result.matrix[1][0] = -0.66666666666666;
    expected_result.matrix[1][1] = 1.0;
    expected_result.matrix[1][2] = -0.33333333333333;
    expected_result.matrix[2][0] = 1.33333333333333;
    expected_result.matrix[2][1] = 0.0;
    expected_result.matrix[2][2] = -0.33333333333333;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_2)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 9.0;
    m.matrix[1][0] = 3.0;
    m.matrix[1][1] = 7.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = -0.35;
    expected_result.matrix[0][1] = 0.45;
    expected_result.matrix[1][0] = 0.15;
    expected_result.matrix[1][1] = -0.05;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_3)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 0.5;
    m.matrix[0][1] = 1.0;
    m.matrix[1][0] = 3.0;
    m.matrix[1][1] = 7.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 14.0;
    expected_result.matrix[0][1] = -2.0;
    expected_result.matrix[1][0] = -6.0;
    expected_result.matrix[1][1] = 1.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_4)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 4.0;
    m.matrix[0][2] = 8.0;
    m.matrix[1][0] = 8.0;
    m.matrix[1][1] = 2.0;
    m.matrix[1][2] = 2.0;
    m.matrix[2][0] = 8.0;
    m.matrix[2][1] = 6.0;
    m.matrix[2][2] = 6.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.1875;
    expected_result.matrix[0][2] = -0.0625;
    expected_result.matrix[1][0] = -0.25;
    expected_result.matrix[1][1] = -0.453125;
    expected_result.matrix[1][2] = 0.484375;
    expected_result.matrix[2][0] = 0.25;
    expected_result.matrix[2][1] = 0.203125;
    expected_result.matrix[2][2] = -0.234375;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_5)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 4.0;
    m.matrix[0][2] = 8.0;
    m.matrix[0][3] = 7.0;
    m.matrix[1][0] = 1.0;
    m.matrix[1][1] = 4.0;
    m.matrix[1][2] = 8.0;
    m.matrix[1][3] = 9.0;
    m.matrix[2][0] = 2.0;
    m.matrix[2][1] = 2.0;
    m.matrix[2][2] = 8.0;
    m.matrix[2][3] = 2.0;
    m.matrix[3][0] = 2.0;
    m.matrix[3][1] = 8.0;
    m.matrix[3][2] = 6.0;
    m.matrix[3][3] = 6.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 4, &expected_result);
    expected_result.matrix[0][0] = -2.433333333333333;
    expected_result.matrix[0][1] = 1.566666666666666;
    expected_result.matrix[0][2] = 0.666666666666666;
    expected_result.matrix[0][3] = 0.266666666666666;
    expected_result.matrix[1][0] = 0.533333333333333;
    expected_result.matrix[1][1] = -0.466666666666666;
    expected_result.matrix[1][2] = -0.166666666666666;
    expected_result.matrix[1][3] = 0.133333333333333;
    expected_result.matrix[2][0] = 0.6;
    expected_result.matrix[2][1] = -0.4;
    expected_result.matrix[2][2] = 0.0;
    expected_result.matrix[2][3] = -0.1;
    expected_result.matrix[3][0] = -0.5;
    expected_result.matrix[3][1] = 0.5;
    expected_result.matrix[3][2] = 0.0;
    expected_result.matrix[3][3] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_6)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] = -2.433333333333333;
    m.matrix[0][1] = 1.566666666666666;
    m.matrix[0][2] = 0.666666666666666;
    m.matrix[0][3] = 0.266666666666666;
    m.matrix[1][0] = 0.533333333333333;
    m.matrix[1][1] = -0.466666666666666;
    m.matrix[1][2] = -0.166666666666666;
    m.matrix[1][3] = 0.133333333333333;
    m.matrix[2][0] = 0.6;
    m.matrix[2][1] = -0.4;
    m.matrix[2][2] = 0.0;
    m.matrix[2][3] = -0.1;
    m.matrix[3][0] = -0.5;
    m.matrix[3][1] = 0.5;
    m.matrix[3][2] = 0.0;
    m.matrix[3][3] = 0.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 4, &expected_result);
    expected_result.matrix[0][0] = 1.0;
    expected_result.matrix[0][1] = 4.0;
    expected_result.matrix[0][2] = 8.0;
    expected_result.matrix[0][3] = 7.0;
    expected_result.matrix[1][0] = 1.0;
    expected_result.matrix[1][1] = 4.0;
    expected_result.matrix[1][2] = 8.0;
    expected_result.matrix[1][3] = 9.0;
    expected_result.matrix[2][0] = 2.0;
    expected_result.matrix[2][1] = 2.0;
    expected_result.matrix[2][2] = 8.0;
    expected_result.matrix[2][3] = 2.0;
    expected_result.matrix[3][0] = 2.0;
    expected_result.matrix[3][1] = 8.0;
    expected_result.matrix[3][2] = 6.0;
    expected_result.matrix[3][3] = 6.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_7)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] = -2.433333333333333;
    m.matrix[0][1] = 1.566666666666666;
    m.matrix[0][2] = 0.666666666666666;
    m.matrix[0][3] = 0.266666666666666;
    m.matrix[1][0] = 0.533333333333333;
    m.matrix[1][1] = -0.466666666666666;
    m.matrix[1][2] = -0.166666666666666;
    m.matrix[1][3] = 0.133333333333333;
    m.matrix[2][0] = 0.6;
    m.matrix[2][1] = -0.4;
    m.matrix[2][2] = 0.0;
    m.matrix[2][3] = -0.1;
    m.matrix[3][0] = -0.5;
    m.matrix[3][1] = 0.5;
    m.matrix[3][2] = 0.0;
    m.matrix[3][3] = 0.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 4, &expected_result);
    expected_result.matrix[0][0] = 1.0;
    expected_result.matrix[0][1] = 4.0;
    expected_result.matrix[0][2] = 8.0;
    expected_result.matrix[0][3] = 7.0;
    expected_result.matrix[1][0] = 1.0;
    expected_result.matrix[1][1] = 4.0;
    expected_result.matrix[1][2] = 8.0;
    expected_result.matrix[1][3] = 9.0;
    expected_result.matrix[2][0] = 2.0;
    expected_result.matrix[2][1] = 2.0;
    expected_result.matrix[2][2] = 8.0;
    expected_result.matrix[2][3] = 2.0;
    expected_result.matrix[3][0] = 2.0;
    expected_result.matrix[3][1] = 8.0;
    expected_result.matrix[3][2] = 6.0;
    expected_result.matrix[3][3] = 6.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_8_calculation_error_zero_determinant)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 0.5;
    m.matrix[0][1] = 1.0;
    m.matrix[1][0] = 0.5;
    m.matrix[1][1] = 1.0;

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_9_incorrect_matrix_null)
{
    matrix_t actual_result;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_inverse_matrix(NULL, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(inverse_matrix_10_incorrect_matrix_null)
{
    matrix_t m;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 0.5;
    m.matrix[0][1] = 1.0;
    m.matrix[1][0] = 0.5;
    m.matrix[1][1] = 1.1;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_inverse_matrix(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);

    s21_remove_matrix(&expected_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_11_calculation_error_not_square)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(2, 9, &m);

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_12_1x1_matrix)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(1, 1, &m);
    m.matrix[0][0] = 100.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_inverse_matrix(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 1.0 / m.matrix[0][0];

    ck_assert_int_eq(actual_code, expected_code);

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

// mult_matrix============================================================
// mult_matrix============================================================
// mult_matrix============================================================

START_TEST(mult_matrix_0)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 0.0;
    m2.matrix[0][0] = 0.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_1)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 4.0;
    m1.matrix[1][0] = 2.0;
    m1.matrix[1][1] = 5.0;
    m1.matrix[2][0] = 3.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 1.0;
    m2.matrix[0][1] = -1.0;
    m2.matrix[0][2] = 1.0;
    m2.matrix[1][0] = 2.0;
    m2.matrix[1][1] = 3.0;
    m2.matrix[1][2] = 4.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 9.0;
    expected_result.matrix[0][1] = 11.0;
    expected_result.matrix[0][2] = 17.0;
    expected_result.matrix[1][0] = 12.0;
    expected_result.matrix[1][1] = 13.0;
    expected_result.matrix[1][2] = 22.0;
    expected_result.matrix[2][0] = 15.0;
    expected_result.matrix[2][1] = 15.0;
    expected_result.matrix[2][2] = 27.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_2_calculation_error_different_columns)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(3, 3, &m2);

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_3)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 3.0;
    m1.matrix[1][1] = 4.0;
    m1.matrix[2][0] = 5.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_4)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(7, 3, &m1);
    s21_create_matrix(3, 5, &m2);

    m1.matrix[0][0] = 1.5;
    m1.matrix[0][1] = 2.5;
    m1.matrix[0][2] = 3.5;
    m1.matrix[1][0] = 4.5;
    m1.matrix[1][1] = 5.5;
    m1.matrix[1][2] = 6.5;
    m1.matrix[2][0] = 7.5;
    m1.matrix[2][1] = 8.5;
    m1.matrix[2][2] = 9.5;
    m1.matrix[3][0] = 10.5;
    m1.matrix[3][1] = 11.5;
    m1.matrix[3][2] = 12.5;
    m1.matrix[4][0] = 13.5;
    m1.matrix[4][1] = 14.5;
    m1.matrix[4][2] = 15.5;
    m1.matrix[5][0] = 16.5;
    m1.matrix[5][1] = 17.5;
    m1.matrix[5][2] = 18.5;
    m1.matrix[6][0] = 19.5;
    m1.matrix[6][1] = 20.5;
    m1.matrix[6][2] = 21.5;

    m2.matrix[0][0] = 22.5;
    m2.matrix[0][1] = 23.5;
    m2.matrix[0][2] = 24.5;
    m2.matrix[0][3] = 25.5;
    m2.matrix[0][4] = 26.5;
    m2.matrix[1][0] = 27.5;
    m2.matrix[1][1] = 28.5;
    m2.matrix[1][2] = 29.5;
    m2.matrix[1][3] = 30.5;
    m2.matrix[1][4] = 31.5;
    m2.matrix[2][0] = 32.5;
    m2.matrix[2][1] = 33.5;
    m2.matrix[2][2] = 34.5;
    m2.matrix[2][3] = 35.5;
    m2.matrix[2][4] = 36.5;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(7, 5, &expected_result);
    expected_result.matrix[0][0] = 216.25;
    expected_result.matrix[0][1] = 223.75;
    expected_result.matrix[0][2] = 231.25;
    expected_result.matrix[0][3] = 238.75;
    expected_result.matrix[0][4] = 246.25;
    expected_result.matrix[1][0] = 463.75;
    expected_result.matrix[1][1] = 480.25;
    expected_result.matrix[1][2] = 496.75;
    expected_result.matrix[1][3] = 513.25;
    expected_result.matrix[1][4] = 529.75;
    expected_result.matrix[2][0] = 711.25;
    expected_result.matrix[2][1] = 736.75;
    expected_result.matrix[2][2] = 762.25;
    expected_result.matrix[2][3] = 787.75;
    expected_result.matrix[2][4] = 813.25;
    expected_result.matrix[3][0] = 958.75;
    expected_result.matrix[3][1] = 993.25;
    expected_result.matrix[3][2] = 1027.75;
    expected_result.matrix[3][3] = 1062.25;
    expected_result.matrix[3][4] = 1096.75;
    expected_result.matrix[4][0] = 1206.25;
    expected_result.matrix[4][1] = 1249.75;
    expected_result.matrix[4][2] = 1293.25;
    expected_result.matrix[4][3] = 1336.75;
    expected_result.matrix[4][4] = 1380.25;
    expected_result.matrix[5][0] = 1453.75;
    expected_result.matrix[5][1] = 1506.25;
    expected_result.matrix[5][2] = 1558.75;
    expected_result.matrix[5][3] = 1611.25;
    expected_result.matrix[5][4] = 1663.75;
    expected_result.matrix[6][0] = 1701.25;
    expected_result.matrix[6][1] = 1762.75;
    expected_result.matrix[6][2] = 1824.25;
    expected_result.matrix[6][3] = 1885.75;
    expected_result.matrix[6][4] = 1947.25;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_5_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(2, 3, &m2);

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(mult_matrix_6_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(2, 3, &m2);

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_matrix(&m2, &m1, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(mult_matrix_7_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    set_null(&m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(mult_matrix_8_incorrect_matrix_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(2, 3, &m1);
    s21_create_matrix(3, 2, &m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_matrix(&m1, &m2, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(mult_matrix_9_incorrect_matrix_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 3.0;
    m1.matrix[1][1] = 4.0;
    m1.matrix[2][0] = 5.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_matrix(&m1, &m2, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

// mult_number============================================================
// mult_number============================================================
// mult_number============================================================

START_TEST(mult_number_0)
{
    matrix_t m;
    const double number = 2.0;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m);

    m.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_1)
{
    matrix_t m;
    const double number = 0.1;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m);

    m.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.123;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_2)
{
    matrix_t m;
    const double number = 0.1;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m);

    m.matrix[0][0] = 10.5;
    m.matrix[0][1] = 20.5;
    m.matrix[1][0] = 30.5;
    m.matrix[1][1] = 40.5;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 1.05;
    expected_result.matrix[0][1] = 2.05;
    expected_result.matrix[1][0] = 3.05;
    expected_result.matrix[1][1] = 4.05;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_3)
{
    matrix_t m;
    const double number = 0.0;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m);

    m.matrix[0][0] = 10.5;
    m.matrix[0][1] = 20.5;
    m.matrix[1][0] = 30.5;
    m.matrix[1][1] = 40.5;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_4_incorrect_matrix_set_null)
{
    matrix_t m;
    const double number = 0.0;
    matrix_t actual_result;
    set_null(&m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(mult_number_5_incorrect_matrix_null)
{
    matrix_t m;
    const double number = 0.0;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m);

    m.matrix[0][0] = 10.5;
    m.matrix[0][1] = 20.5;
    m.matrix[1][0] = 30.5;
    m.matrix[1][1] = 40.5;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_mult_number(&m, number, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_6_calculation_error_nan)
{
    matrix_t m;
    const double number = NAN;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m);

    m.matrix[0][0] = 10.5;
    m.matrix[0][1] = 20.5;
    m.matrix[1][0] = 30.5;
    m.matrix[1][1] = 40.5;

    // const int expected_code = ERROR_INCORRECT_MATRIX;
    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_mult_number(&m, number, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);

    // just to cover case when removing null-pointer
    s21_remove_matrix(NULL);
    // just to cover case when creating from null-pointer
    s21_create_matrix(4, 3, NULL);
}
END_TEST

// sub_matrix=============================================================
// sub_matrix=============================================================
// sub_matrix=============================================================

START_TEST(sub_matrix_0)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_1_calculation_error_different_columns)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_2_calculation_error_different_rows_and_columns)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(3, 3, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_3)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(1, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_4)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;
    m1.matrix[1][0] = 2.23;
    m1.matrix[1][1] = 2.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;
    m2.matrix[1][0] = 2.23;
    m2.matrix[1][1] = 2.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_5)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m1);
    s21_create_matrix(4, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;
    m1.matrix[1][0] = 2.23;
    m1.matrix[1][1] = 2.00;
    m1.matrix[2][0] = 1.23;
    m1.matrix[2][1] = 1.00;
    m1.matrix[3][0] = 2.23;
    m1.matrix[3][1] = 2.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;
    m2.matrix[1][0] = 2.23;
    m2.matrix[1][1] = 2.00;
    m2.matrix[2][0] = 1.23;
    m2.matrix[2][1] = 1.00;
    m2.matrix[3][0] = 2.23;
    m2.matrix[3][1] = 2.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 0.0;
    expected_result.matrix[1][0] = 0.0;
    expected_result.matrix[1][1] = 0.0;
    expected_result.matrix[2][0] = 0.0;
    expected_result.matrix[2][1] = 0.0;
    expected_result.matrix[3][0] = 0.0;
    expected_result.matrix[3][1] = 0.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_6)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m1);
    s21_create_matrix(4, 2, &m2);

    m1.matrix[0][0] = 8.8;
    m1.matrix[0][1] = 7.7;
    m1.matrix[1][0] = 6.6;
    m1.matrix[1][1] = 5.5;
    m1.matrix[2][0] = 4.4;
    m1.matrix[2][1] = 3.3;
    m1.matrix[3][0] = 2.2;
    m1.matrix[3][1] = 1.1;

    m2.matrix[0][0] = 1.1;
    m2.matrix[0][1] = 2.2;
    m2.matrix[1][0] = 3.3;
    m2.matrix[1][1] = 4.4;
    m2.matrix[2][0] = 5.5;
    m2.matrix[2][1] = 6.6;
    m2.matrix[3][0] = 7.7;
    m2.matrix[3][1] = 8.8;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 7.7;
    expected_result.matrix[0][1] = 5.5;
    expected_result.matrix[1][0] = 3.3;
    expected_result.matrix[1][1] = 1.1;
    expected_result.matrix[2][0] = -1.1;
    expected_result.matrix[2][1] = -3.3;
    expected_result.matrix[3][0] = -5.5;
    expected_result.matrix[3][1] = -7.7;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_7_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m1);
    set_null(&m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 7.7;
    expected_result.matrix[0][1] = 5.5;
    expected_result.matrix[1][0] = 3.3;
    expected_result.matrix[1][1] = 1.1;
    expected_result.matrix[2][0] = -1.1;
    expected_result.matrix[2][1] = -3.3;
    expected_result.matrix[3][0] = -5.5;
    expected_result.matrix[3][1] = -7.7;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sub_matrix_8_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(1, 1, &m2);

    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sub_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 7.7;
    expected_result.matrix[0][1] = 5.5;
    expected_result.matrix[1][0] = 3.3;
    expected_result.matrix[1][1] = 1.1;
    expected_result.matrix[2][0] = -1.1;
    expected_result.matrix[2][1] = -3.3;
    expected_result.matrix[3][0] = -5.5;
    expected_result.matrix[3][1] = -7.7;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(sub_matrix_9_incorrect_matrix_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;

    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sub_matrix(&m1, &m2, NULL);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 7.7;
    expected_result.matrix[0][1] = 5.5;
    expected_result.matrix[1][0] = 3.3;
    expected_result.matrix[1][1] = 1.1;
    expected_result.matrix[2][0] = -1.1;
    expected_result.matrix[2][1] = -3.3;
    expected_result.matrix[3][0] = -5.5;
    expected_result.matrix[3][1] = -7.7;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

// sum_matrix=============================================================
// sum_matrix=============================================================
// sum_matrix=============================================================

START_TEST(sum_matrix_0)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_1_calculation_error_different_columns)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_2_calculation_error_different_rows_and_columns)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(3, 3, &m2);

    m1.matrix[0][0] = 1.23;
    m2.matrix[0][0] = 1.23;

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_3)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 2, &m1);
    s21_create_matrix(1, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 2, &expected_result);
    expected_result.matrix[0][0] = 2.46;
    expected_result.matrix[0][1] = 2.00;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_4)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;
    m1.matrix[1][0] = 2.23;
    m1.matrix[1][1] = 2.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;
    m2.matrix[1][0] = 2.23;
    m2.matrix[1][1] = 2.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 2.46;
    expected_result.matrix[0][1] = 2.00;
    expected_result.matrix[1][0] = 4.46;
    expected_result.matrix[1][1] = 4.00;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_5)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m1);
    s21_create_matrix(4, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;
    m1.matrix[1][0] = 2.23;
    m1.matrix[1][1] = 2.00;
    m1.matrix[2][0] = 1.23;
    m1.matrix[2][1] = 1.00;
    m1.matrix[3][0] = 2.23;
    m1.matrix[3][1] = 2.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;
    m2.matrix[1][0] = 2.23;
    m2.matrix[1][1] = 2.00;
    m2.matrix[2][0] = 1.23;
    m2.matrix[2][1] = 1.00;
    m2.matrix[3][0] = 2.23;
    m2.matrix[3][1] = 2.00;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(4, 2, &expected_result);
    expected_result.matrix[0][0] = 2.46;
    expected_result.matrix[0][1] = 2.00;
    expected_result.matrix[1][0] = 4.46;
    expected_result.matrix[1][1] = 4.00;
    expected_result.matrix[2][0] = 2.46;
    expected_result.matrix[2][1] = 2.00;
    expected_result.matrix[3][0] = 4.46;
    expected_result.matrix[3][1] = 4.00;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_6_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m1);
    set_null(&m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    set_null(&expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m1);
}
END_TEST

START_TEST(sum_matrix_7_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(4, 2, &m2);
    set_null(&m1);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    set_null(&expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(sum_matrix_8_incorrect_matrix_set_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    set_null(&m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sum_matrix(&m1, &m2, &actual_result);

    matrix_t expected_result;
    set_null(&expected_result);

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
}
END_TEST

START_TEST(sum_matrix_9_incorrect_matrix_null)
{
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(2, 2, &m1);
    s21_create_matrix(2, 2, &m2);

    m1.matrix[0][0] = 1.23;
    m1.matrix[0][1] = 1.00;
    m1.matrix[1][0] = 2.23;
    m1.matrix[1][1] = 2.00;

    m2.matrix[0][0] = 1.23;
    m2.matrix[0][1] = 1.00;
    m2.matrix[1][0] = 2.23;
    m2.matrix[1][1] = 2.00;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_sum_matrix(&m1, &m2, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 2, &expected_result);
    expected_result.matrix[0][0] = 2.46;
    expected_result.matrix[0][1] = 2.00;
    expected_result.matrix[1][0] = 4.46;
    expected_result.matrix[1][1] = 4.00;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
}
END_TEST

// transpose==============================================================
// transpose==============================================================
// transpose==============================================================

START_TEST(transpose_0)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(1, 1, &m);
    m.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_transpose(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_1)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(1, 2, &m);

    m.matrix[0][0] = 1.23;
    m.matrix[0][1] = 2.46;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_transpose(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_2)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(2, 3, &m);

    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 4.0;
    m.matrix[1][1] = 5.0;
    m.matrix[1][2] = 6.0;

    const int expected_code = ERROR_OK;
    const int actual_code = s21_transpose(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 2, &expected_result);
    expected_result.matrix[0][0] = 1.0;
    expected_result.matrix[0][1] = 4.0;
    expected_result.matrix[1][0] = 2.0;
    expected_result.matrix[1][1] = 5.0;
    expected_result.matrix[2][0] = 3.0;
    expected_result.matrix[2][1] = 6.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_3_incorrect_matrix_null)
{
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(1, 2, &m);

    m.matrix[0][0] = 1.23;
    m.matrix[0][1] = 2.46;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(transpose_4_incorrect_matrix_set_null)
{
    matrix_t m;
    matrix_t actual_result;

    set_null(&m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(transpose_5_incorrect_matrix_negative_columns)
{
    matrix_t m;
    matrix_t actual_result;

    set_null(&m);
    m.columns = -5;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(transpose_6_incorrect_matrix_negative_rows)
{
    matrix_t m;
    matrix_t actual_result;

    set_null(&m);
    m.rows = -5;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(transpose_7_incorrect_matrix_negative_rows_and_columns)
{
    matrix_t m;
    matrix_t actual_result;

    m.rows = -5;
    m.columns = -15;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

START_TEST(transpose_8_incorrect_matrix_negative_rows_and_columns)
{
    matrix_t m;
    matrix_t actual_result;

    m.matrix = NULL;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_transpose(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(2, 1, &expected_result);
    expected_result.matrix[0][0] = 1.23;
    expected_result.matrix[1][0] = 2.46;

    ck_assert_int_eq(actual_code, expected_code);
    if (actual_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));

    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
}
END_TEST

Suite *from_no_check_suite(void)
{
    Suite *s1 = suite_create("Ch");
    TCase *tc1_1 = tcase_create("Core");

    // calc_complements===================================================================
    // calc_complements===================================================================

    tcase_add_test(tc1_1, calc_complements_0);
    tcase_add_test(tc1_1, calc_complements_1_calculation_error_not_square);
    tcase_add_test(tc1_1, calc_complements_2);
    tcase_add_test(tc1_1, calc_complements_3_incorrect_matrix_null);
    tcase_add_test(tc1_1, calc_complements_4_incorrect_matrix_null);

    // create_matrix======================================================================
    // create_matrix======================================================================

    tcase_add_test(tc1_1, create_matrix_0_incorrect_matrix_negative_row);
    tcase_add_test(tc1_1, create_matrix_1_incorrect_matrix_negative_column);
    tcase_add_test(tc1_1, create_matrix_2_incorrect_matrix_negative_both);
    tcase_add_test(tc1_1, create_matrix_3_incorrect_matrix_negative_and_null);
    tcase_add_test(tc1_1, create_matrix_4_incorrect_matrix_null);
    // tcase_add_test(tc1_1, create_matrix_5_incorrect_matrix_too_large);

    // determinant========================================================================
    // determinant========================================================================

    tcase_add_test(tc1_1, determinant_0);
    tcase_add_test(tc1_1, determinant_1);
    tcase_add_test(tc1_1, determinant_2);
    tcase_add_test(tc1_1, determinant_3);
    tcase_add_test(tc1_1, determinant_4);
    tcase_add_test(tc1_1, determinant_5);
    tcase_add_test(tc1_1, determinant_6);
    tcase_add_test(tc1_1, determinant_7_calculation_error_not_square);
    tcase_add_test(tc1_1, determinant_8_incorrect_matrix_null);
    tcase_add_test(tc1_1, determinant_9_incorrect_matrix_null);
    tcase_add_test(tc1_1, determinant_10_incorrect_matrix_null);

    // eq_matrix==========================================================================
    // eq_matrix==========================================================================

    tcase_add_test(tc1_1, eq_matrix_0);
    tcase_add_test(tc1_1, eq_matrix_1);
    tcase_add_test(tc1_1, eq_matrix_2);
    tcase_add_test(tc1_1, eq_matrix_3);
    tcase_add_test(tc1_1, eq_matrix_4);
    tcase_add_test(tc1_1, eq_matrix_5);
    tcase_add_test(tc1_1, eq_matrix_6);
    tcase_add_test(tc1_1, eq_matrix_7);
    tcase_add_test(tc1_1, eq_matrix_8);
    tcase_add_test(tc1_1, eq_matrix_9);
    tcase_add_test(tc1_1, eq_matrix_10);
    tcase_add_test(tc1_1, eq_matrix_11_set_null);
    tcase_add_test(tc1_1, eq_matrix_12_set_null);
    tcase_add_test(tc1_1, eq_matrix_13_set_null);
    tcase_add_test(tc1_1, eq_matrix_14_null);
    tcase_add_test(tc1_1, eq_matrix_15_null);
    tcase_add_test(tc1_1, eq_matrix_16_null);

    // inverse_matrix=====================================================================
    // inverse_matrix=====================================================================

    tcase_add_test(tc1_1, inverse_matrix_0);
    tcase_add_test(tc1_1, inverse_matrix_1);
    tcase_add_test(tc1_1, inverse_matrix_2);
    tcase_add_test(tc1_1, inverse_matrix_3);
    tcase_add_test(tc1_1, inverse_matrix_4);
    tcase_add_test(tc1_1, inverse_matrix_5);
    tcase_add_test(tc1_1, inverse_matrix_6);
    tcase_add_test(tc1_1, inverse_matrix_7);
    tcase_add_test(tc1_1, inverse_matrix_8_calculation_error_zero_determinant);
    tcase_add_test(tc1_1, inverse_matrix_9_incorrect_matrix_null);
    tcase_add_test(tc1_1, inverse_matrix_10_incorrect_matrix_null);
    tcase_add_test(tc1_1, inverse_matrix_11_calculation_error_not_square);
    tcase_add_test(tc1_1, inverse_matrix_12_1x1_matrix);

    // mult_matrix========================================================================
    // mult_matrix========================================================================

    tcase_add_test(tc1_1, mult_matrix_0);
    tcase_add_test(tc1_1, mult_matrix_1);
    tcase_add_test(tc1_1, mult_matrix_2_calculation_error_different_columns);
    tcase_add_test(tc1_1, mult_matrix_3);
    tcase_add_test(tc1_1, mult_matrix_4);
    tcase_add_test(tc1_1, mult_matrix_5_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, mult_matrix_6_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, mult_matrix_7_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, mult_matrix_8_incorrect_matrix_null);
    tcase_add_test(tc1_1, mult_matrix_9_incorrect_matrix_null);

    // mult_number========================================================================
    // mult_number========================================================================

    tcase_add_test(tc1_1, mult_number_0);
    tcase_add_test(tc1_1, mult_number_1);
    tcase_add_test(tc1_1, mult_number_2);
    tcase_add_test(tc1_1, mult_number_3);
    tcase_add_test(tc1_1, mult_number_4_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, mult_number_5_incorrect_matrix_null);
    tcase_add_test(tc1_1, mult_number_6_calculation_error_nan);

    // sub_matrix=========================================================================
    // sub_matrix=========================================================================

    tcase_add_test(tc1_1, sub_matrix_0);
    tcase_add_test(tc1_1, sub_matrix_1_calculation_error_different_columns);
    tcase_add_test(tc1_1, sub_matrix_2_calculation_error_different_rows_and_columns);
    tcase_add_test(tc1_1, sub_matrix_3);
    tcase_add_test(tc1_1, sub_matrix_4);
    tcase_add_test(tc1_1, sub_matrix_5);
    tcase_add_test(tc1_1, sub_matrix_6);
    tcase_add_test(tc1_1, sub_matrix_7_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, sub_matrix_8_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, sub_matrix_9_incorrect_matrix_null);

    // sum_matrix=========================================================================
    // sum_matrix=========================================================================

    tcase_add_test(tc1_1, sum_matrix_0);
    tcase_add_test(tc1_1, sum_matrix_1_calculation_error_different_columns);
    tcase_add_test(tc1_1, sum_matrix_2_calculation_error_different_rows_and_columns);
    tcase_add_test(tc1_1, sum_matrix_3);
    tcase_add_test(tc1_1, sum_matrix_4);
    tcase_add_test(tc1_1, sum_matrix_5);
    tcase_add_test(tc1_1, sum_matrix_6_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, sum_matrix_7_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, sum_matrix_8_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, sum_matrix_9_incorrect_matrix_null);

    // transpose==========================================================================
    // transpose==========================================================================

    tcase_add_test(tc1_1, transpose_0);
    tcase_add_test(tc1_1, transpose_1);
    tcase_add_test(tc1_1, transpose_2);
    tcase_add_test(tc1_1, transpose_3_incorrect_matrix_null);
    tcase_add_test(tc1_1, transpose_4_incorrect_matrix_set_null);
    tcase_add_test(tc1_1, transpose_5_incorrect_matrix_negative_columns);
    tcase_add_test(tc1_1, transpose_6_incorrect_matrix_negative_rows);
    tcase_add_test(tc1_1, transpose_7_incorrect_matrix_negative_rows_and_columns);
    tcase_add_test(tc1_1, transpose_8_incorrect_matrix_negative_rows_and_columns);

    suite_add_tcase(s1, tc1_1);
    return s1;
}
