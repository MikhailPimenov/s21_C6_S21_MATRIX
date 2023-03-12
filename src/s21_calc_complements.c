#include "s21_matrix.h"
#include "s21_common.h"

int s21_calc_complements(matrix_t* a, matrix_t* result) {
    if (a->rows != a->columns)
        return ERROR_CALCULATION_ERROR;

    if (is_matrix_not_valid(a))
        return ERROR_INCORRECT_MATRIX;

    if (ERROR_OK != s21_create_matrix(a->rows, a->columns, result))
        return ERROR_INCORRECT_MATRIX;

    matrix_t little_matrix;
    if (ERROR_OK != s21_create_matrix(a->rows - 1, a->columns - 1, &little_matrix)) {
        s21_remove_matrix(result);
        return ERROR_INCORRECT_MATRIX;    
    }

    for (int row = 0; row < a->rows; ++row) {
        for (int column = 0; column < a->columns; ++column) {
            get_little_matrix(a, row, column, &little_matrix);
            double little_determinant = 0.0;
            const int determinant_status = s21_determinant(&little_matrix, &little_determinant);
            if (determinant_status != ERROR_OK) {
                s21_remove_matrix(&little_matrix);
                s21_remove_matrix(result);
                return ERROR_INCORRECT_MATRIX;
            }
            result->matrix[row][column] = sign(row, column) * little_determinant;
        }
    }
    s21_remove_matrix(&little_matrix);
    return ERROR_OK;
}