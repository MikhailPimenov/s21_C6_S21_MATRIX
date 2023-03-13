#include "s21_matrix.h"
#include "s21_common.h"
#include <assert.h>

static double determinant2x2(double a00, double a01, double a10, double a11) {
    return a00 * a11 - a01 * a10;
}

static double determinant(const matrix_t* a) {
    assert(a->rows == a->columns && "Matrix should have same dimensions to calculate determinant!");

    if (a->rows == 1)
        return a->matrix[0][0];

    if (a->rows == 2)
        return determinant2x2(a->matrix[0][0], a->matrix[0][1], a->matrix[1][0], a->matrix[1][1]);

    double result = 0.0;

    matrix_t little_matrix;
    s21_create_matrix(a->rows - 1, a->columns - 1, &little_matrix);

    for (int column = 0; column < a->columns; ++column) {
        get_little_matrix(a, 0, column, &little_matrix);
        result += (a->matrix[0][column] * sign(0, column) * determinant(&little_matrix));
    }
    
    s21_remove_matrix(&little_matrix);

    return result;
}

int s21_determinant(matrix_t* a, double* result) {
    if (is_matrix_not_valid(a) || !result)
        return ERROR_INCORRECT_MATRIX;

    if (a->rows != a->columns)
        return ERROR_CALCULATION_ERROR;

    *result = determinant(a);
    return ERROR_OK;
}