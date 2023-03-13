#include <stdlib.h>
#include "s21_matrix.h"

enum Error_allocation {
    CREATION_OK = 0,
    ALLOCATION_ERROR = 1,
};

static void initialize_matrix(matrix_t* matrix, double number) {
    for (int row = 0; row < matrix->rows; ++row)
        for (int column = 0; column < matrix->columns; ++column)
            matrix->matrix[row][column] = number;
}

int s21_create_matrix(int rows, int columns, matrix_t* result) {
    if (!result)
        return ERROR_INCORRECT_MATRIX;

    if (rows < 1 || columns < 1)
        return ERROR_INCORRECT_MATRIX;

    double** matrix = malloc(sizeof(double) * rows * columns + sizeof(double*) * rows);
    if (!matrix)
        return ALLOCATION_ERROR;

    for (int row = 0; row < rows; ++row)
        *(matrix + row) = (double*)((double**)((double*)matrix + row * columns) + rows);

    result->matrix = matrix;
    result->rows = rows;
    result->columns = columns;

    initialize_matrix(result, 0.0);
    return ERROR_OK;
}