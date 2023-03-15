#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../s21_matrix.h"
#include "../s21_common.h"
#include "print_matrix.h"

void create_matrix_tests(int algorithm(int, int, matrix_t*), const char* function_name) {
    printf("Testing %s:\n", function_name);
    int test_number = 0;

    //0==============================================
    printf("Visual test #%d:\n", test_number);
    {
        matrix_t matrix;
        const int rows = 3;
        const int columns = 5;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
    ++test_number;

    //1==============================================
    printf("Visual test #%d:\n", test_number);
    {
        matrix_t matrix;
        const int rows = 4;
        const int columns = 2;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
    ++test_number;

    //2==============================================
    printf("Visual test #%d:\n", test_number);
    {
        matrix_t matrix;
        const int rows = 1;
        const int columns = 1;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
    ++test_number;

    //3==============================================
    printf("Visual test #%d:\n", test_number);
    {
        matrix_t matrix;
        const int rows = 10;
        const int columns = 7;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
    ++test_number;
    
    //4==============================================
    printf("test #%d:\t", test_number);
    {
        matrix_t matrix;
        const int rows = -10;
        const int columns = 7;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(rows, columns, &matrix);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
    }
    ++test_number;

    //5==============================================
    printf("test #%d:\t", test_number);
    {
        matrix_t matrix;
        const int rows = 10;
        const int columns = -7;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(rows, columns, &matrix);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
    }
    ++test_number;

    //6==============================================
    printf("test #%d:\t", test_number);
    {
        matrix_t matrix;
        const int rows = -10;
        const int columns = -7;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(rows, columns, &matrix);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
    }
    ++test_number;

    //7==============================================
    printf("test #%d:\t", test_number);
    {
        const int rows = -10;
        const int columns = -7;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(rows, columns, NULL);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
    }
    ++test_number;

    //8==============================================
    printf("test #%d:\t", test_number);
    {
        const int rows = 10;
        const int columns = 7;

        const int expected_code = ERROR_INCORRECT_MATRIX;
        const int actual_code = algorithm(rows, columns, NULL);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
    }
    ++test_number;

    //9==============================================
    printf("test #%d:\t", test_number);
    {
        matrix_t m;
        set_null(&m);
        const int rows = INT_MAX / 2;                               // too large matrix
        const int columns = INT_MAX / 2;                            // too large matrix

        const int expected_code = ERROR_INCORRECT_MATRIX;           // can allocate or can not
        const int actual_code = algorithm(rows, columns, &m);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
        
        if (ERROR_OK == actual_code)
            free(m.matrix);
    }
    ++test_number;

    //10=============================================
    printf("test #%d:\t", test_number);
    {
        const int rows = 4;                              
        const int columns = 3;                         

        const int expected_code = ERROR_INCORRECT_MATRIX;           
        const int actual_code = algorithm(rows, columns, NULL);
        if (actual_code == expected_code)
            printf("ok\n");
        else
            printf("FAILED\n");
        
    }
    ++test_number;
        
}