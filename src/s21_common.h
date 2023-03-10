#ifndef SRC_S21_COMMON_H_
#define SRC_S21_COMMON_H_

#include "s21_matrix.h"

int are_equal(double a, double b, double epsilon);
int not_equal(double a, double b, double epsilon);
int sign(int rows, int columns);
void get_little_matrix(const matrix_t* a, int row_to_exclude, int column_to_exclude, matrix_t* result);
int is_matrix_not_valid(const matrix_t* a);
void set_null(matrix_t* a);

#endif  //  SRC_S21_COMMON_H_