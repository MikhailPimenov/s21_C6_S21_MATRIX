#include <stdlib.h>
#include "s21_matrix.h"

void s21_remove_matrix(matrix_t* a) {
    free(a->matrix);
    a->matrix = NULL;
    a->rows = 0;
    a->columns = 0;
}