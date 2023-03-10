// #define CREATE_ENABLED  // uncomment this line to enable tests for s21_create_matrix
// #define REMOVE_ENABLED  // uncomment this line to enable tests for s21_remove_matrix
// #define EQ_ENABLED  // uncomment this line to enable tests for s21_eq_matrix
// #define SUM_ENABLED  // uncomment this line to enable tests for s21_sum_matrix
// #define SUB_ENABLED  // uncomment this line to enable tests for s21_sub_matrix
// #define MULT_NUMBER_ENABLED  // uncomment this line to enable tests for s21_mult_number
// #define MULT_MATRIX_ENABLED  // uncomment this line to enable tests for s21_mult_matrix
// #define TRANSPOSE_ENABLED  // uncomment this line to enable tests for s21_transpose
// 
// #define CALC_COMPLEMENTS_ENABLED     // uncomment this line to enable tests for
                                    //  s21_calc_complements
// #define DETERMINANT_ENABLED           // uncomment this line to enable tests for
                                    //  s21_determinant
// #define INVERSE_ENABLED  // uncomment this line to enable tests for
                                    //  s21_inverse_matrix
#include <check.h>
#include <assert.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define TRUE 1
#define FALSE 0


START_TEST(eq_test_1) {
  matrix_t m1;
  m1.rows = 5;
  m1.columns = 6;

  double** line = malloc(sizeof(double) * m1.rows * m1.columns + sizeof(double*) * m1.rows);
  for (int row = 0; row < m1.rows; ++row)
    line[row] = m1.rows + ((double*)line + row * m1.columns);
  
  line[1][1] = 88.1;
  m1.matrix = line;

  const int result = s21_eq_matrix(&m1, NULL, 78);
  ck_assert_int_eq(1, result);
}
END_TEST

START_TEST(eq_test_2) {
  s21_eq_matrix(NULL, NULL,12);
  ck_assert_int_eq(1, 0);
}
END_TEST

START_TEST(eq_test_3) {
  s21_eq_matrix(NULL, NULL,34);
  ck_assert_int_eq(1, 0);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc);





  tcase_add_test(tc, eq_test_1);
  tcase_add_test(tc, eq_test_2);
  tcase_add_test(tc, eq_test_3);
  
  

  srunner_run_all(sr, CK_NORMAL);
  // srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
