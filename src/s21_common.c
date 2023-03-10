#include "s21_matrix.h"
#include <assert.h>

void set_null(matrix_t* a) {
    a->matrix = (double**)0;  //  same as NULL
    a->rows = 0;
    a->columns = 0;
}

int is_matrix_not_valid(const matrix_t* a) {
    return !a || !a->matrix || a->rows < 1 || a->columns < 1;
}

int sign(int rows, int columns) {
    if ((rows + columns) % 2)
        return -1;
    return 1;
}

void get_little_matrix(const matrix_t* a, int row_to_exclude, int column_to_exclude, matrix_t* result) {
    assert(row_to_exclude < a->rows && column_to_exclude < a->columns && "Row or column is out of range for submatrix!");

    int row_result = 0;
    for (int row = 0; row < a->rows; ++row) {
        if (row == row_to_exclude) 
            continue;
        int column_result = 0;
        for (int column = 0; column < a->columns; ++column) {
            if (column == column_to_exclude) 
                continue;
            result->matrix[row_result][column_result] = a->matrix[row][column];
            ++column_result;
        }
        ++row_result;        
    }
}

int is_nan(double number) {
    return number != number;
}