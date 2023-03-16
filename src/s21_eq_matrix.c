#include <assert.h>
#include <stdio.h>

#include "s21_common.h"
#include "s21_matrix.h"

enum Result
{
    NOT_EQUAL = 0,
    EQUAL = 1,
};

static const double s_epsilon = 1e-8;
int are_equal(double a, double b, double epsilon)
{
    if (a < b)
        return b - a < epsilon;
    else
        return a - b < epsilon;
}
int not_equal(double a, double b, double epsilon)
{
    return !are_equal(a, b, epsilon);
}

int s21_eq_matrix(matrix_t *a, matrix_t *b)
{
    if (is_matrix_not_valid(a) || is_matrix_not_valid(b))
        return NOT_EQUAL;

    if (a->rows != b->rows || a->columns != b->columns)
        return NOT_EQUAL;

    for (int row = 0; row < a->rows; ++row)
        for (int column = 0; column < a->columns; ++column)
            if (not_equal(a->matrix[row][column], b->matrix[row][column], s_epsilon))
                return NOT_EQUAL;

    return EQUAL;
}
