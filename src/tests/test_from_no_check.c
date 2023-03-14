#include "check_matrix.h"
#include "../s21_common.h"
#include <limits.h>


static const double g_epsilon = 1e-8;

START_TEST(calc_complements_0) {
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
    expected_result.matrix[0][0] =   0.0;
    expected_result.matrix[0][1] =  10.0;
    expected_result.matrix[0][2] = -20.0;
    expected_result.matrix[1][0] =   4.0;
    expected_result.matrix[1][1] = -14.0;
    expected_result.matrix[1][2] =   8.0;
    expected_result.matrix[2][0] =  -8.0;
    expected_result.matrix[2][1] =  -2.0;
    expected_result.matrix[2][2] =   4.0;

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));
    
    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);

} END_TEST

START_TEST(calc_complements_1_calculation_error_not_square) {
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

} END_TEST

START_TEST(calc_complements_2) {
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
    expected_result.matrix[0][0] =  -3.0;  //  1 * (5*9 - 8*6) =  1 * (45 - 48) = -1 * (-3)  =   3
    expected_result.matrix[0][1] =   6.0;  // -1 * (4*9 - 7*6) = -1 * (36 - 42) = -1 * (-6)  =   6
    expected_result.matrix[0][2] =  -3.0;  //  1 * (4*8 - 7*5) =  1 * (32 - 35) =  1 * (-3)  =  -3
    expected_result.matrix[1][0] =   6.0;  // -1 * (2*9 - 8*3) = -1 * (18 - 24) = -1 * (-6)  =   6
    expected_result.matrix[1][1] = -12.0;  //  1 * (1*9 - 7*3) =  1 * (9  - 21) =  1 * (-12) = -12
    expected_result.matrix[1][2] =   6.0;  // -1 * (1*8 - 7*2) = -1 * (8  - 14) = -1 * (-6)  =   6
    expected_result.matrix[2][0] =  -3.0;  //  1 * (2*6 - 5*3) =  1 * (12 - 15) =  1 * (-3)  =  -3
    expected_result.matrix[2][1] =   6.0;  // -1 * (1*6 - 4*3) = -1 * (6  - 12) = -1 * (-6)  =   6
    expected_result.matrix[2][2] =  -3.0;  //  1 * (1*5 - 4*2) =  1 * (5  -  8) =  1 * (-3)  =  -3

    ck_assert_int_eq(actual_code, expected_code);
    if (expected_code == ERROR_OK)
        ck_assert_int_eq(SUCCESS, s21_eq_matrix(&actual_result, &expected_result));
    
    s21_remove_matrix(&expected_result);
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);

} END_TEST

START_TEST(calc_complements_3_incorrect_matrix_null) {
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
} END_TEST

START_TEST(calc_complements_4_incorrect_matrix_null) {
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
} END_TEST




START_TEST(create_matrix_0_incorrect_matrix_negative_row) {
    matrix_t matrix;
    const int rows = -10;
    const int columns = 7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

START_TEST(create_matrix_1_incorrect_matrix_negative_column) {
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

START_TEST(create_matrix_2_incorrect_matrix_negative_both) {
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

START_TEST(create_matrix_3_incorrect_matrix_negative_and_null) {
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

START_TEST(create_matrix_4_incorrect_matrix_null) {
    matrix_t matrix;
    const int rows = 10;
    const int columns = -7;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

START_TEST(create_matrix_5_incorrect_matrix_too_large) {
    matrix_t matrix;
    const int rows = INT_MAX / 2;
    const int columns = INT_MAX / 2;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = s21_create_matrix(rows, columns, &matrix);
    
    ck_assert_int_eq(actual_code, expected_code);
    
    if (actual_code == ERROR_OK)
        s21_remove_matrix(&matrix);
} END_TEST

// determinant============================================================
// determinant============================================================
// determinant============================================================

START_TEST(determinant_0) {
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
} END_TEST

START_TEST(determinant_1) {
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
} END_TEST

START_TEST(determinant_2) {
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
} END_TEST

START_TEST(determinant_3) {
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
} END_TEST

START_TEST(determinant_4) {
    matrix_t m;
    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] =  1.5;
    m.matrix[0][1] =  2.5;
    m.matrix[0][2] =  3.5;
    m.matrix[0][3] =  4.5;
    m.matrix[1][0] =  5.5;
    m.matrix[1][1] =  6.5;
    m.matrix[1][2] =  7.5;
    m.matrix[1][3] =  8.5;
    m.matrix[2][0] =  9.5;
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
} END_TEST

START_TEST(determinant_5) {
    matrix_t m;
    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] =   1.1;
    m.matrix[0][1] =   2.2;
    m.matrix[0][2] =   3.3;
    m.matrix[0][3] =   4.4;
    m.matrix[0][4] =   5.5;
    m.matrix[1][0] =   6.6;
    m.matrix[1][1] =   7.7;
    m.matrix[1][2] =   8.8;
    m.matrix[1][3] =   9.9;
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
} END_TEST

START_TEST(determinant_6) {
    matrix_t m;
    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] =  1.0;
    m.matrix[0][1] =  2.0;
    m.matrix[0][2] =  3.0;
    m.matrix[0][3] =  5.0;
    m.matrix[0][4] =  7.0;
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
} END_TEST

START_TEST(determinant_7_calculation_error_not_square) {
    matrix_t m;
    s21_create_matrix(2, 3, &m);
        
    const int expected_code = ERROR_CALCULATION_ERROR;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
} END_TEST

START_TEST(determinant_8_incorrect_matrix_null) {
    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(NULL, &actual_result);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);
} END_TEST

START_TEST(determinant_9_incorrect_matrix_null) {
    matrix_t m;
    s21_create_matrix(6, 6, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, NULL);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
} END_TEST

START_TEST(determinant_10_incorrect_matrix_null) {
    matrix_t m;
    s21_create_matrix(5, 5, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = s21_determinant(&m, NULL);

    const double expected_result = 0.0;
    ck_assert_int_eq(actual_code, expected_code);
    ck_assert_double_eq_tol(actual_result, expected_result, g_epsilon);

    s21_remove_matrix(&m);
} END_TEST

// eq_matrix==============================================================
// eq_matrix==============================================================
// eq_matrix==============================================================

START_TEST(eq_matrix_0) {
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
} END_TEST

START_TEST(eq_matrix_1) {
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
} END_TEST

START_TEST(eq_matrix_2) {
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
} END_TEST

START_TEST(eq_matrix_3) {
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
} END_TEST

START_TEST(eq_matrix_4) {
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
} END_TEST

START_TEST(eq_matrix_5) {
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
} END_TEST

START_TEST(eq_matrix_6) {
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
} END_TEST

START_TEST(eq_matrix_7) {
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
} END_TEST

START_TEST(eq_matrix_8) {
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
} END_TEST

START_TEST(eq_matrix_9) {
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
} END_TEST

START_TEST(eq_matrix_10) {
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
} END_TEST

START_TEST(eq_matrix_11_set_null) {
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
} END_TEST

START_TEST(eq_matrix_12_set_null) {
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
} END_TEST

START_TEST(eq_matrix_13_set_null) {
    matrix_t m1;
    matrix_t m2;

    set_null(&m1);
    set_null(&m2);
    
    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m1, &m2);

    ck_assert_int_eq(actual, expected);
} END_TEST

START_TEST(eq_matrix_14_null) {
    matrix_t m2;
    s21_create_matrix(2, 2, &m2);
    m2.matrix[0][0] = 1.23;
    
    int expected = FAILURE;
    const int actual = s21_eq_matrix(NULL, &m2);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
} END_TEST

START_TEST(eq_matrix_15_null) {
    matrix_t m2;
    s21_create_matrix(2, 2, &m2);
    m2.matrix[0][0] = 1.23;
    
    int expected = FAILURE;
    const int actual = s21_eq_matrix(&m2, NULL);

    ck_assert_int_eq(actual, expected);

    s21_remove_matrix(&m2);
} END_TEST

START_TEST(eq_matrix_16_null) {
    int expected = FAILURE;
    const int actual = s21_eq_matrix(NULL, NULL);

    ck_assert_int_eq(actual, expected);
} END_TEST





Suite *from_no_check_suite(void) {
    Suite *s1 = suite_create("Ch");
    TCase *tc1_1 = tcase_create("Core");

    // tcase_add_test(tc1_1, calc_complements_0);
    // tcase_add_test(tc1_1, calc_complements_1_calculation_error_not_square);
    // tcase_add_test(tc1_1, calc_complements_2);
    // tcase_add_test(tc1_1, calc_complements_3_incorrect_matrix_null);
    // tcase_add_test(tc1_1, calc_complements_4_incorrect_matrix_null);
    
    // tcase_add_test(tc1_1, create_matrix_0_incorrect_matrix_negative_row);
    // tcase_add_test(tc1_1, create_matrix_1_incorrect_matrix_negative_column);
    // tcase_add_test(tc1_1, create_matrix_2_incorrect_matrix_negative_both);
    // tcase_add_test(tc1_1, create_matrix_3_incorrect_matrix_negative_and_null);
    // tcase_add_test(tc1_1, create_matrix_4_incorrect_matrix_null);
    // tcase_add_test(tc1_1, create_matrix_5_incorrect_matrix_too_large);

    // tcase_add_test(tc1_1, determinant_0);
    // tcase_add_test(tc1_1, determinant_1);
    // tcase_add_test(tc1_1, determinant_2);
    // tcase_add_test(tc1_1, determinant_3);
    // tcase_add_test(tc1_1, determinant_4);
    // tcase_add_test(tc1_1, determinant_5);
    // tcase_add_test(tc1_1, determinant_6);
    // tcase_add_test(tc1_1, determinant_7_calculation_error_not_square);
    // tcase_add_test(tc1_1, determinant_8_incorrect_matrix_null);
    // tcase_add_test(tc1_1, determinant_9_incorrect_matrix_null);
    // tcase_add_test(tc1_1, determinant_10_incorrect_matrix_null);

    // tcase_add_test(tc1_1, eq_matrix_0);
    // tcase_add_test(tc1_1, eq_matrix_1);
    // tcase_add_test(tc1_1, eq_matrix_2);
    // tcase_add_test(tc1_1, eq_matrix_3);
    // tcase_add_test(tc1_1, eq_matrix_4);
    // tcase_add_test(tc1_1, eq_matrix_5);
    // tcase_add_test(tc1_1, eq_matrix_6);
    // tcase_add_test(tc1_1, eq_matrix_7);
    // tcase_add_test(tc1_1, eq_matrix_8);
    // tcase_add_test(tc1_1, eq_matrix_9);
    // tcase_add_test(tc1_1, eq_matrix_10);
    // tcase_add_test(tc1_1, eq_matrix_11_set_null);
    // tcase_add_test(tc1_1, eq_matrix_12_set_null);
    // tcase_add_test(tc1_1, eq_matrix_13_set_null);
    // tcase_add_test(tc1_1, eq_matrix_14_null);
    // tcase_add_test(tc1_1, eq_matrix_15_null);
    // tcase_add_test(tc1_1, eq_matrix_16_null);

    suite_add_tcase(s1, tc1_1);
    return s1;
}
