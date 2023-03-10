#include "s21_matrix.h"

int s21_transpose(matrix_t* a, matrix_t* result) {
    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            result->matrix[column][row] = a->matrix[row][column];
    return OK;
}
