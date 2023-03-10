#include "s21_matrix.h"

void set_null(matrix_t* a) {
    a->matrix = (double**)0;  //  same as NULL
    a->rows = 0;
    a->columns = 0;
}

int is_matrix_not_valid(const matrix_t* a) {
    return !a || !a->matrix || a->rows < 1 || a->columns < 1;
}