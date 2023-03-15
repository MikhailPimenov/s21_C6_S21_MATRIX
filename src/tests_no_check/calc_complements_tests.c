#include <stdio.h>

#include "../s21_matrix.h"

static void print_summary(const char *function_name, int test_number,
                          int successful_test_number) {
  printf("Testing %s is over: %d / %d, %.2f%%\n", function_name,
         successful_test_number, test_number,
         100.0f * (float)successful_test_number / (float)test_number);
}

void calc_complements_tests(int algorithm(const matrix_t *, matrix_t *),
                            const char *function_name) {
  int test_number = 0;
  int successful_test_number = 0;
  printf("Testing %s:\n", function_name);

  {  // 0========================================
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);

    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 0.0;
    m.matrix[1][1] = 4.0;
    m.matrix[1][2] = 2.0;
    m.matrix[2][0] = 5.0;
    m.matrix[2][1] = 2.0;
    m.matrix[2][2] = 1.0;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 0.0;
    expected_result.matrix[0][1] = 10.0;
    expected_result.matrix[0][2] = -20.0;
    expected_result.matrix[1][0] = 4.0;
    expected_result.matrix[1][1] = -14.0;
    expected_result.matrix[1][2] = 8.0;
    expected_result.matrix[2][0] = -8.0;
    expected_result.matrix[2][1] = -2.0;
    expected_result.matrix[2][2] = 4.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         s21_eq_matrix(&actual_result, &expected_result))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&expected_result);
    s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 1========================================
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 4, &m);

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = algorithm(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         s21_eq_matrix(&actual_result, &expected_result))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&expected_result);
    if (ERROR_OK == actual_code) s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 2========================================
    matrix_t m;
    matrix_t actual_result;

    s21_create_matrix(3, 3, &m);

    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[1][0] = 4.0;
    m.matrix[1][1] = 5.0;
    m.matrix[1][2] = 6.0;
    m.matrix[2][0] = 7.0;
    m.matrix[2][1] = 8.0;
    m.matrix[2][2] = 9.0;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] =
        -3.0;  //  1 * (5*9 - 8*6) =  1 * (45 - 48) = -1 * (-3)  =   3
    expected_result.matrix[0][1] =
        6.0;  // -1 * (4*9 - 7*6) = -1 * (36 - 42) = -1 * (-6)  =   6
    expected_result.matrix[0][2] =
        -3.0;  //  1 * (4*8 - 7*5) =  1 * (32 - 35) =  1 * (-3)  =  -3
    expected_result.matrix[1][0] =
        6.0;  // -1 * (2*9 - 8*3) = -1 * (18 - 24) = -1 * (-6)  =   6
    expected_result.matrix[1][1] =
        -12.0;  //  1 * (1*9 - 7*3) =  1 * (9  - 21) =  1 * (-12) = -12
    expected_result.matrix[1][2] =
        6.0;  // -1 * (1*8 - 7*2) = -1 * (8  - 14) = -1 * (-6)  =   6
    expected_result.matrix[2][0] =
        -3.0;  //  1 * (2*6 - 5*3) =  1 * (12 - 15) =  1 * (-3)  =  -3
    expected_result.matrix[2][1] =
        6.0;  // -1 * (1*6 - 4*3) = -1 * (6  - 12) = -1 * (-6)  =   6
    expected_result.matrix[2][2] =
        -3.0;  //  1 * (1*5 - 4*2) =  1 * (5  -  8) =  1 * (-3)  =  -3

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         s21_eq_matrix(&actual_result, &expected_result))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&expected_result);
    if (ERROR_OK == actual_code) s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 3========================================
    matrix_t actual_result;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(NULL, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         s21_eq_matrix(&actual_result, &expected_result))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&expected_result);
    if (ERROR_OK == actual_code) s21_remove_matrix(&actual_result);
  }
  ++test_number;

  {  // 4========================================
    matrix_t m;
    matrix_t actual_result;
    s21_create_matrix(5, 5, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 4, &expected_result);

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         s21_eq_matrix(&actual_result, &expected_result))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&expected_result);
    if (ERROR_OK == actual_code) s21_remove_matrix(&actual_result);
    s21_remove_matrix(&m);
  }
  ++test_number;

  print_summary(function_name, test_number, successful_test_number);
}