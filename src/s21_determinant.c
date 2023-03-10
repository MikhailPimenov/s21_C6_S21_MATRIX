#include "s21_matrix.h"
#include <assert.h>

static double determinant2x2(double a00, double a01, double a10, double a11) {
    return a00 * a11 - a01 * a10;
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
        if (row != row_to_exclude) {
            int column_result = 0;
            for (int column = 0; column < a->columns; ++column) {
                if (column != column_to_exclude) {
                    result->matrix[row_result][column_result] = a->matrix[row][column];
                    ++column_result;
                }
            }
            ++row_result;
        }
    }

    /*
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
    */

    /*
    int row_result = 0;
    for (int row = 0; row < row_to_exclude; ++row) {
        int column_result = 0;
        for (int column = 0; column < column_to_exclude; ++column) {
            result->matrix[row_result][column_result] = a->matrix[row][column];
            ++column_result;            
        }
        for (int column = column_to_exclude + 1; column < a->columns; ++column) {
            result->matrix[row_result][column_result] = a->matrix[row][column];
            ++column_result;            
        }
        ++row_result;
    }

    for (int row = row_to_exclude + 1; row < a->rows; ++row) {
        int column_result = 0;
        for (int column = 0; column < column_to_exclude; ++column) {
            result->matrix[row_result][column_result] = a->matrix[row][column];
            ++column_result;            
        }
        for (int column = column_to_exclude + 1; column < a->columns; ++column) {
            result->matrix[row_result][column_result] = a->matrix[row][column];
            ++column_result;            
        }
        ++row_result;
    }

    */
}

static double determinant(const matrix_t* a) {
    assert(a->rows == a->columns && "Matrix should have same dimensions to calculate determinant!");

    if (a->rows == 1)
        return a->matrix[0][0];

    if (a->rows == 2)
        return determinant2x2(a->matrix[0][0], a->matrix[0][1], a->matrix[1][0], a->matrix[1][1]);

    double result = 0.0;
    for (int column = 0; column < a->columns; ++column) {

        matrix_t little_matrix;
        s21_create_matrix(a->rows - 1, a->columns - 1, &little_matrix);
        get_little_matrix(a, 0, column, &little_matrix);
    
        result += (a->matrix[0][column] * sign(0, column) * determinant(&little_matrix));

        s21_remove_matrix(&little_matrix);
    }

    return result;
}

int s21_determinant(matrix_t* a, double* result) {
    if (a->rows != a->columns)
        return CALCULATION_ERROR;

    *result = determinant(a);
    return OK;
}