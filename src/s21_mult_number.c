#include "s21_matrix.h"
#include "s21_common.h"

int s21_mult_number(matrix_t* a, double number, matrix_t* result) {
    if (is_matrix_not_valid(a) || !result)
        return ERROR_INCORRECT_MATRIX;

    if (is_nan(number))
        return ERROR_CALCULATION_ERROR;

    if (ERROR_OK != s21_create_matrix(a->rows, a->columns, result))
        return ERROR_INCORRECT_MATRIX;

    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[row][column] = a->matrix[row][column] * number;
    return ERROR_OK;
}