#include "s21_matrix.h"
#include "s21_common.h"

int s21_transpose(matrix_t* a, matrix_t* result) {
    if (is_matrix_not_valid(a))
        return ERROR_INCORRECT_MATRIX;

    if (ERROR_OK != s21_create_matrix(a->columns, a->rows, result))
        return ERROR_INCORRECT_MATRIX;

    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[column][row] = a->matrix[row][column];
    return ERROR_OK;
}
