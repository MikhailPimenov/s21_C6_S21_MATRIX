#include "s21_matrix.h"
#include "s21_common.h"


int s21_calc_complements(matrix_t* a, matrix_t* result) {
    if (a->rows != a->columns)
        return CALCULATION_ERROR;

    matrix_t little_matrix;
    s21_create_matrix(a->rows - 1, a->columns - 1, &little_matrix);

    for (int row = 0; row < a->rows; ++row) {
        for (int column = 0; column < a->columns; ++column) {
            get_little_matrix(a, row, column, &little_matrix);
            double little_determinant = 0.0;
            s21_determinant(&little_matrix, &little_determinant);
            result->matrix[row][column] = sign(row, column) * little_determinant;
        }
    }

    s21_remove_matrix(&little_matrix);

    return OK;
}