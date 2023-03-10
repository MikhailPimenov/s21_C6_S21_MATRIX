#include "s21_matrix.h"

int s21_mult_number(matrix_t* a, double number, matrix_t* result) {
    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[row][column] = a->matrix[row][column] * number;
    return OK;
}