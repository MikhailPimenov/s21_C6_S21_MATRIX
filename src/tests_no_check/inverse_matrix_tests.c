#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"
#include "print_matrix.h"

static void print_summary(const char *function_name, int test_number, int successful_test_number)
{
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number,
           100.0f * (float)successful_test_number / (float)test_number);
}

void inverse_matrix_tests(int algorithm(const matrix_t *, matrix_t *), const char *function_name)
{
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    { // 0========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 1========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 2========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(2, 2, &m);

        m.matrix[0][0] = 1.0;
        m.matrix[0][1] = 9.0;
        m.matrix[1][0] = 3.0;
        m.matrix[1][1] = 7.0;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);
        expected_result.matrix[0][0] = -0.35;
        expected_result.matrix[0][1] = 0.45;
        expected_result.matrix[1][0] = 0.15;
        expected_result.matrix[1][1] = -0.05;

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 3========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(2, 2, &m);

        m.matrix[0][0] = 0.5;
        m.matrix[0][1] = 1.0;
        m.matrix[1][0] = 3.0;
        m.matrix[1][1] = 7.0;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);
        expected_result.matrix[0][0] = 14.0;
        expected_result.matrix[0][1] = -2.0;
        expected_result.matrix[1][0] = -6.0;
        expected_result.matrix[1][1] = 1.0;

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 4========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 5========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 6========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 7========================================
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
        const int actual_code = algorithm(&m, &actual_result);

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
            printf("expected:\n");
            print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 8========================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(2, 2, &m);

        m.matrix[0][0] = 0.5;
        m.matrix[0][1] = 1.0;
        m.matrix[1][0] = 0.5;
        m.matrix[1][1] = 1.0;

        const int expected_code = ERROR_CALCULATION_ERROR;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);

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
            printf("expected:\n");
            if (is_matrix_not_valid(&expected_result))
                print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            if (is_matrix_not_valid(&actual_result))
                print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 9========================================
        matrix_t actual_result;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(NULL, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);

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
            printf("expected:\n");
            if (!is_matrix_not_valid(&expected_result))
                print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            if (!is_matrix_not_valid(&actual_result))
                print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
    }
    ++test_number;

    { // 10========================================
        matrix_t m;

        s21_create_matrix(2, 2, &m);

        m.matrix[0][0] = 0.5;
        m.matrix[0][1] = 1.0;
        m.matrix[1][0] = 0.5;
        m.matrix[1][1] = 1.1;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(&m, NULL);

        printf("test #%d:\t", test_number);
        if (actual_code == expected_code)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 11=======================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(2, 9, &m);

        const int expected_code = ERROR_CALCULATION_ERROR;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(2, 2, &expected_result);

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
            printf("expected:\n");
            if (!is_matrix_not_valid(&expected_result))
                print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            if (!is_matrix_not_valid(&actual_result))
                print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    { // 12=======================================
        matrix_t m;
        matrix_t actual_result;

        s21_create_matrix(1, 1, &m);
        m.matrix[0][0] = 100.0;

        const int expected_code = ERROR_OK;
        const int actual_code = algorithm(&m, &actual_result);

        matrix_t expected_result;
        s21_create_matrix(1, 1, &expected_result);
        expected_result.matrix[0][0] = 1.0 / m.matrix[0][0];

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
            printf("expected:\n");
            if (!is_matrix_not_valid(&expected_result))
                print_matrix(&expected_result, "\t", "\n");
            printf("actual:\n");
            if (!is_matrix_not_valid(&actual_result))
                print_matrix(&actual_result, "\t", "\n");
        }

        s21_remove_matrix(&expected_result);
        s21_remove_matrix(&actual_result);
        s21_remove_matrix(&m);
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}