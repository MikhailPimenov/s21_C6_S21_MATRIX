#include "s21_matrix.h"

int s21_mult_matrix(matrix_t* a, matrix_t* b, matrix_t* result) {
    if (a->columns != b->rows)
        return ERROR_CALCULATION_ERROR;

    const int sum_length = a->columns;

    for (int row = 0; row < a->rows; ++row) {
        for (int column = 0; column < b->columns; ++column) {
            double sum = 0.0;
            for (int s = 0; s < sum_length; ++s)
                sum += a->matrix[row][s] * b->matrix[s][column];
            result->matrix[row][column] = sum;
        } 
    }
    return OK;
}
