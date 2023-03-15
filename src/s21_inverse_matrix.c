#include <stdio.h>

#include "s21_common.h"
#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *a, matrix_t *result) {
  if (is_matrix_not_valid(a) || !result) return ERROR_INCORRECT_MATRIX;

  if (a->rows != a->columns) return ERROR_CALCULATION_ERROR;

  double determinant = 0.0;
  const int determinant_status = s21_determinant(a, &determinant);
  if (ERROR_OK != determinant_status) return determinant_status;

  if (are_equal(0.0, determinant, 1e-8)) return ERROR_CALCULATION_ERROR;

  matrix_t complements;
  const int calc_status = s21_calc_complements(a, &complements);
  if (calc_status != ERROR_OK) return calc_status;

  matrix_t transposed;
  const int transposed_status = s21_transpose(&complements, &transposed);
  s21_remove_matrix(&complements);

  if (ERROR_OK != transposed_status) return transposed_status;

  const double multiplier = 1.0 / determinant;
  const int mult_status = s21_mult_number(&transposed, multiplier, result);
  s21_remove_matrix(&transposed);

  if (ERROR_OK != mult_status) return mult_status;

  return ERROR_OK;
}