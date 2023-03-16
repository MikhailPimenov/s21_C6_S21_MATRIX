#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"

static void print_summary(const char *function_name, int test_number, int successful_test_number)
{
    printf("Testing %s is over: %d / %d, %.2f%%\n", function_name, successful_test_number, test_number,
           100.0f * (float)successful_test_number / (float)test_number);
}

void eq_matrix_tests(int algorithm(const matrix_t *, const matrix_t *), const char *function_name)
{
    int test_number = 0;
    int successful_test_number = 0;
    printf("Testing %s:\n", function_name);

    { // 0========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 1========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.24;

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 2========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 2, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 3========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(1, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 4========================================
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

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 5========================================
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

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 6========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(2, 2, &m1);
        s21_create_matrix(2, 3, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        m1.matrix[0][1] = 1.203;
        m2.matrix[0][1] = 1.203;

        m1.matrix[1][0] = 1.231;
        m2.matrix[1][0] = 1.231;

        m1.matrix[1][1] = 1.023;
        m2.matrix[1][1] = 1.023;

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 7========================================
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

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 8========================================
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

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 9========================================
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

        const int expected = 1;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 10=======================================
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

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }
        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 11=======================================
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

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
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

    { // 12=======================================
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

        const int expected = 0;
        const int actual = algorithm(&m2, &m1);

        printf("test #%d:\t", test_number);
        if (actual == expected)
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

    { // 13=======================================
        matrix_t m1;
        matrix_t m2;

        set_null(&m1);
        set_null(&m2);

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
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

    { // 14========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(2, 1, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    { // 15========================================
        matrix_t m1;
        matrix_t m2;

        s21_create_matrix(1, 1, &m1);
        s21_create_matrix(2, 2, &m2);

        m1.matrix[0][0] = 1.23;
        m2.matrix[0][0] = 1.23;

        const int expected = 0;
        const int actual = algorithm(&m1, &m2);

        printf("test #%d:\t", test_number);
        if (actual == expected)
        {
            printf("ok\n");
            ++successful_test_number;
        }
        else
        {
            printf("FAILED\n");
        }

        s21_remove_matrix(&m1);
        s21_remove_matrix(&m2);
    }
    ++test_number;

    print_summary(function_name, test_number, successful_test_number);
}