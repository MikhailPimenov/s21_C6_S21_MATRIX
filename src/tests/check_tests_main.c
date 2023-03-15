#include <check.h>

#include "check_matrix.h"

int main() {
  Suite* s1 = eq_matrix_suite();
  Suite* s2 = sum_matrix_suite();
  Suite* s3 = sub_matrix_suite();
  Suite* s4 = mult_number_suite();
  Suite* s5 = mult_matrix_suite();
  Suite* s6 = transpose_matrix_suite();
  Suite* s7 = complements_matrix_suite();
  Suite* s8 = determinant_matrix_suite();
  Suite* s9 = inverse_matrix_suite();
  Suite* s10 = extrapack_suite();
  Suite* s11 = from_no_check_suite();

  SRunner* runner1 = srunner_create(s1);
  srunner_run_all(runner1, CK_ENV);
  srunner_ntests_failed(runner1);
  srunner_free(runner1);

  SRunner* runner2 = srunner_create(s2);
  srunner_run_all(runner2, CK_ENV);
  srunner_ntests_failed(runner2);
  srunner_free(runner2);

  SRunner* runner3 = srunner_create(s3);
  srunner_run_all(runner3, CK_ENV);
  srunner_ntests_failed(runner3);
  srunner_free(runner3);

  SRunner* runner4 = srunner_create(s4);
  srunner_run_all(runner4, CK_ENV);
  srunner_ntests_failed(runner4);
  srunner_free(runner4);

  SRunner* runner5 = srunner_create(s5);
  srunner_run_all(runner5, CK_ENV);
  srunner_ntests_failed(runner5);
  srunner_free(runner5);

  SRunner* runner6 = srunner_create(s6);
  srunner_run_all(runner6, CK_ENV);
  srunner_ntests_failed(runner6);
  srunner_free(runner6);

  SRunner* runner7 = srunner_create(s7);
  srunner_run_all(runner7, CK_ENV);
  srunner_ntests_failed(runner7);
  srunner_free(runner7);

  SRunner* runner8 = srunner_create(s8);
  srunner_run_all(runner8, CK_ENV);
  srunner_ntests_failed(runner8);
  srunner_free(runner8);

  SRunner* runner9 = srunner_create(s9);
  srunner_run_all(runner9, CK_ENV);
  srunner_ntests_failed(runner9);
  srunner_free(runner9);

  SRunner* runner10 = srunner_create(s10);
  srunner_run_all(runner10, CK_ENV);
  srunner_ntests_failed(runner10);
  srunner_free(runner10);

  SRunner* runner11 = srunner_create(s11);
  srunner_run_all(runner11, CK_ENV);
  srunner_ntests_failed(runner11);
  srunner_free(runner11);

  return 0;
}