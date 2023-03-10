#include <stdlib.h>
#include <stdio.h>

#include "../s21_matrix.h"
#include "print_matrix.h"

void create_matrix_tests(int algorithm(int, int, matrix_t*), const char* function_name) {
    printf("Testing %s:\n", function_name);
    int test_number = 0;
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
    printf("Visual test #%d:\n", test_number);
    {
        matrix_t matrix;
        const int rows = 10;
        const int columns = 7;

        algorithm(rows, columns, &matrix);
        print_matrix(&matrix, "\t", "\n");

        free(matrix.matrix);
    }
}