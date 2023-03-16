#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"

static void print_summary(const char *function_name, int test_number, int successful_test_number)
{
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number,
           100.0f * (float)successful_test_number / (float)test_number);
}

void transpose_tests(int algorithm(const matrix_t *, matrix_t *), const char *function_name)
{
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    { // 0========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(1, 1, &m);

        m.matrix[0][0] = 1.23;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;

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
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 1========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(1, 2, &m);

        m.matrix[0][0] = 1.23;
        m.matrix[0][1] = 2.46;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 2========================================
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
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(3, 2, &expected_result);
        expected_result.matrix[0][0] = 1.0;
        expected_result.matrix[0][1] = 4.0;
        expected_result.matrix[1][0] = 2.0;
        expected_result.matrix[1][1] = 5.0;
        expected_result.matrix[2][0] = 3.0;
        expected_result.matrix[2][1] = 6.0;

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
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 3========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(1, 2, &m);

        m.matrix[0][0] = 1.23;
        m.matrix[0][1] = 2.46;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 4========================================
        matrix_t m;
        matrix_t actual_result;

        set_null(&m);

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
    }
    ++test_number;

    { // 5========================================
        matrix_t m;
        matrix_t actual_result;

        set_null(&m);
        m.columns = -5;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
    }
    ++test_number;

    { // 6========================================
        matrix_t m;
        matrix_t actual_result;

        set_null(&m);
        m.rows = -5;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
    }
    ++test_number;

    { // 7========================================
        matrix_t m;
        matrix_t actual_result;

        set_null(&m);
        m.rows = -5;
        m.columns = -15;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
    }
    ++test_number;

    { // 8========================================
        matrix_t m;
        matrix_t actual_result;

        set_null(&m);
        m.matrix = NULL;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 1, &expected_result);
        expected_result.matrix[0][0] = 1.23;
        expected_result.matrix[1][0] = 2.46;

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
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}