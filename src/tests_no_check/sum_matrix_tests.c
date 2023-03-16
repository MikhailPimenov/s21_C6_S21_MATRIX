#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"

static void print_summary(const char *function_name, int test_number, int successful_test_number)
{
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number,
           100.0f * (float)successful_test_number / (float)test_number);
}

void sum_matrix_tests(int algorithm(const matrix_t *, const matrix_t *, matrix_t *), const char *function_name)
{
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    { // 0========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);
        expected_result.matrix[0][0] = 2.46;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 1========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        s21_create_matrix(1, 2, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected_code = ERROR_CALCULATION_ERROR;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 2========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        s21_create_matrix(1, 2, &m1);
        s21_create_matrix(3, 3, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected_code = ERROR_CALCULATION_ERROR;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 3========================================
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
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 2, &expected_result);
        expected_result.matrix[0][0] = 2.46;
        expected_result.matrix[0][1] = 2.00;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 4========================================
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
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);
        expected_result.matrix[0][0] = 2.46;
        expected_result.matrix[0][1] = 2.00;
        expected_result.matrix[1][0] = 4.46;
        expected_result.matrix[1][1] = 4.00;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 5========================================
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
        const int actual_code = algorithm(&m1, &m2, &actual_result);

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

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 6========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        s21_create_matrix(4, 2, &m1);
        set_null(&m2);

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
    }
    ++test_number;

    { // 7========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        s21_create_matrix(4, 2, &m2);
        set_null(&m1);

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 8========================================
        matrix_t m1;
        matrix_t m2;
        matrix_t actual_result;
        set_null(&m1);
        set_null(&m2);

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m1, &m2, &actual_result);

        matrix_t expected_result;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
    }
    ++test_number;

    { // 9========================================
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
        const int actual_code = algorithm(&m1, &m2, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);
        expected_result.matrix[0][0] = 2.46;
        expected_result.matrix[0][1] = 2.00;
        expected_result.matrix[1][0] = 4.46;
        expected_result.matrix[1][1] = 4.00;

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code &&
            (actual_code != ERROR_OK || s21_eq_matrix(&actual_result, &expected_result)))
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&m2);
        s21_remove_matrix(&m1);
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}