#include "s21_matrix.h"
#include "s21_common.h"

int s21_mult_matrix(matrix_t* a, matrix_t* b, matrix_t* result) {
    if (a->columns != b->rows)
        return ERROR_CALCULATION_ERROR;

    if (is_matrix_not_valid(a) || is_matrix_not_valid(b))
        return ERROR_INCORRECT_MATRIX;

    if (ERROR_OK != s21_create_matrix(a->rows, b->columns, result))
        return ERROR_INCORRECT_MATRIX;

    const int sum_length = a->columns;

    for (int row = 0; row < a->rows; ++row) {
        for (int column = 0; column < b->columns; ++column) {
            double sum = 0.0;
            for (int s = 0; s < sum_length; ++s)
                sum += a->matrix[row][s] * b->matrix[s][column];
            result->matrix[row][column] = sum;
        } 
    }
    return ERROR_OK;
}
