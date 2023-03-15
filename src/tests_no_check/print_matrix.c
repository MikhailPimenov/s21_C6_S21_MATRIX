#include "print_matrix.h"

#include <stdio.h>

void print_matrix(const matrix_t *matrix, const char *space,
                  const char *endline) {
  for (int row = 0; row < matrix->rows; ++row) {
    for (int column = 0; column < matrix->columns; ++column) {
      printf("%f%s", matrix->matrix[row][column], space);
    }
    printf("%s", endline);
  }
  printf("\n");
}