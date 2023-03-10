#include "s21_matrix.h"

int s21_sum_matrix(matrix_t* a, matrix_t* b, matrix_t* result) {
    if (a->rows != b->rows || a->columns != b->columns)
        return CALCULATION_ERROR;

    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[row][column] = a->matrix[row][column] + b->matrix[row][column];

    return OK;
}
