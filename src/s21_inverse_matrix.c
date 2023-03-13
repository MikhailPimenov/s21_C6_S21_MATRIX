#include "s21_matrix.h"
#include "s21_common.h"

#include <stdio.h>

int s21_inverse_matrix(matrix_t* a, matrix_t* result) {
    // printf("here1\n");
    if (is_matrix_not_valid(a) || !result)
    {
        // printf("exit1\n");
        return ERROR_INCORRECT_MATRIX;
    }
    
    // printf("here2\n");
    if (a->rows != a->columns)
    {
        // printf("exit2\n");
        return ERROR_CALCULATION_ERROR;
    }

    double determinant = 0.0;
    const int determinant_status = s21_determinant(a, &determinant);
    // printf("here3\n");
    if (ERROR_OK != determinant_status)
    {
        // printf("exit3\n");
        return determinant_status;
    }

    // printf("here4\n");
    if (are_equal(0.0, determinant, 1e-8))
    {
        // printf("exit4\n");
        return ERROR_CALCULATION_ERROR;
    }

    matrix_t complements;    
    const int calc_status = s21_calc_complements(a, &complements);
    // printf("here5\n");
    if (calc_status != ERROR_OK)
    {
        // printf("exit5\n");
        return calc_status;
    }

    matrix_t transposed;
    // printf("here6\n");
    const int transposed_status = s21_transpose(&complements, &transposed);
    s21_remove_matrix(&complements);

    // printf("here7\n");
    if (ERROR_OK != transposed_status)   
    {
        // printf("exit6\n");
        return transposed_status;
    } 
    
    const double multiplier = 1.0 / determinant;
    const int mult_status = s21_mult_number(&transposed, multiplier, result);
    s21_remove_matrix(&transposed);
    // printf("here8\n");

    if (ERROR_OK != mult_status) 
    {
        // printf("exit7\n");
        return mult_status;
    }

    return ERROR_OK;
}