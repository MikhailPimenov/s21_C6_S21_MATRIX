#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"

static void print_summary(const char* function_name, int test_number,
                          int successful_test_number) {
  printf("Testing %s is over: %d / %d, %.2f%%\n", function_name,
         successful_test_number, test_number,
         100.0f * (float)successful_test_number / (float)test_number);
}

void determinant_tests(int algorithm(const matrix_t*, double*),
                       const char* function_name) {
  int test_number = 0;
  int successful_test_number = 0;
  printf("Testing %s:\n", function_name);

  {  // 0========================================
    matrix_t m;

    s21_create_matrix(1, 1, &m);
    m.matrix[0][0] = 1.23;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 1.23;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 1========================================
    matrix_t m;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 4.0;
    m.matrix[0][1] = 2.0;
    m.matrix[1][0] = 2.0;
    m.matrix[1][1] = 1.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 2========================================
    matrix_t m;

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
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 3========================================
    matrix_t m;

    s21_create_matrix(2, 2, &m);
    m.matrix[0][0] = 9.0;
    m.matrix[0][1] = 4.0;
    m.matrix[1][0] = 3.0;
    m.matrix[1][1] = 7.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 51.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 4========================================
    matrix_t m;

    s21_create_matrix(4, 4, &m);
    m.matrix[0][0] = 1.5;
    m.matrix[0][1] = 2.5;
    m.matrix[0][2] = 3.5;
    m.matrix[0][3] = 4.5;
    m.matrix[1][0] = 5.5;
    m.matrix[1][1] = 6.5;
    m.matrix[1][2] = 7.5;
    m.matrix[1][3] = 8.5;
    m.matrix[2][0] = 9.5;
    m.matrix[2][1] = 10.5;
    m.matrix[2][2] = 11.5;
    m.matrix[2][3] = 12.5;
    m.matrix[3][0] = 13.5;
    m.matrix[3][1] = 14.5;
    m.matrix[3][2] = 15.5;
    m.matrix[3][3] = 16.5;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 5========================================
    matrix_t m;

    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] = 1.1;
    m.matrix[0][1] = 2.2;
    m.matrix[0][2] = 3.3;
    m.matrix[0][3] = 4.4;
    m.matrix[0][4] = 5.5;
    m.matrix[1][0] = 6.6;
    m.matrix[1][1] = 7.7;
    m.matrix[1][2] = 8.8;
    m.matrix[1][3] = 9.9;
    m.matrix[1][4] = 10.10;
    m.matrix[2][0] = 11.11;
    m.matrix[2][1] = 12.12;
    m.matrix[2][2] = 13.13;
    m.matrix[2][3] = 14.14;
    m.matrix[2][4] = 15.15;
    m.matrix[3][0] = 16.16;
    m.matrix[3][1] = 17.17;
    m.matrix[3][2] = 18.18;
    m.matrix[3][3] = 19.19;
    m.matrix[3][4] = 20.20;
    m.matrix[4][0] = 21.21;
    m.matrix[4][1] = 22.22;
    m.matrix[4][2] = 23.23;
    m.matrix[4][3] = 24.24;
    m.matrix[4][4] = 25.25;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 6========================================
    matrix_t m;

    s21_create_matrix(5, 5, &m);
    m.matrix[0][0] = 1.0;
    m.matrix[0][1] = 2.0;
    m.matrix[0][2] = 3.0;
    m.matrix[0][3] = 5.0;
    m.matrix[0][4] = 7.0;
    m.matrix[1][0] = 11.0;
    m.matrix[1][1] = 13.0;
    m.matrix[1][2] = 17.0;
    m.matrix[1][3] = 19.0;
    m.matrix[1][4] = 23.0;
    m.matrix[2][0] = 29.0;
    m.matrix[2][1] = 31.0;
    m.matrix[2][2] = 37.0;
    m.matrix[2][3] = 41.0;
    m.matrix[2][4] = 43.0;
    m.matrix[3][0] = 47.0;
    m.matrix[3][1] = 51.0;
    m.matrix[3][2] = 53.0;
    m.matrix[3][3] = 59.0;
    m.matrix[3][4] = 61.0;
    m.matrix[4][0] = 67.0;
    m.matrix[4][1] = 71.0;
    m.matrix[4][2] = 73.0;
    m.matrix[4][3] = 79.0;
    m.matrix[4][4] = 83.0;

    const int expected_code = ERROR_OK;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = -2256.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 7========================================
    matrix_t m;

    s21_create_matrix(2, 3, &m);

    const int expected_code = ERROR_CALCULATION_ERROR;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }

    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 8========================================
    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = algorithm(NULL, &actual_result);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }
  }
  ++test_number;

  {  // 9========================================
    matrix_t m;
    s21_create_matrix(6, 6, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, NULL);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }
    s21_remove_matrix(&m);
  }
  ++test_number;

  {  // 10========================================
    matrix_t m;
    s21_create_matrix(5, 5, &m);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    double actual_result = 0.0;
    const int actual_code = algorithm(&m, NULL);

    const double expected_result = 0.0;

    printf("test #%d:\t", test_number);
    if (actual_code == expected_code &&
        (actual_code != ERROR_OK ||
         are_equal(actual_result, expected_result, 1e-8))) {
      printf("ok\n");
      ++successful_test_number;
    } else {
      printf("FAILED\n");
    }
    s21_remove_matrix(&m);
  }
  ++test_number;

  print_summary(function_name, test_number, successful_test_number);
}