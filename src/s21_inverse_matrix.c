#include "s21_matrix.h"
#include "s21_common.h"

int s21_inverse_matrix(matrix_t* a, matrix_t* result) {
    if (a->rows != a->columns)
        return ERROR_CALCULATION_ERROR;

    double determinant = 0.0;
    s21_determinant(a, &determinant);

    if (are_equal(0.0, determinant, 1e-8))
        return ERROR_CALCULATION_ERROR;

    matrix_t complements;
    s21_create_matrix(a->rows, a->columns, &complements);
    
    s21_calc_complements(a, &complements);

    matrix_t transposed;
    s21_create_matrix(a->rows, a->columns, &transposed);
    s21_transpose(&complements, &transposed);

    const double multiplier = 1.0 / determinant;
    s21_mult_number(&transposed, multiplier, result);

    s21_remove_matrix(&transposed);
    s21_remove_matrix(&complements);
    return ERROR_OK;
}