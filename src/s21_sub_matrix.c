#include "s21_matrix.h"
#include "s21_common.h"

int s21_sub_matrix(matrix_t* a, matrix_t* b, matrix_t* result) {
    if (is_matrix_not_valid(a) || is_matrix_not_valid(b))
        return INCORRECT_MATRIX;

    if (a->rows != b->rows || a->columns != b->columns)
        return CALCULATION_ERROR;

    if (OK != s21_create_matrix(a->rows, a->columns, result))
        return INCORRECT_MATRIX;
        
    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[row][column] = a->matrix[row][column] - b->matrix[row][column];

    return OK;
}
