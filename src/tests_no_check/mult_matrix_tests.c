#include <stdio.h>

#include "../s21_common.h"
#include "../s21_matrix.h"

static void print_summary(const char *function_name, int test_number,
                          int successful_test_number) {
  printf("Testing %s is over: %d / %d, %.2f%%\n", function_name,
         successful_test_number, test_number,
         100.0f * (float)successful_test_number / (float)test_number);
}

void mult_matrix_tests(int algorithm(const matrix_t *, const matrix_t *,
                                     matrix_t *),
                       const char *function_name) {
  int test_number = 0;
  int successful_test_number = 0;
  printf("Testing %s:\n", function_name);

  {  // 0========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(1, 1, &m1);
    s21_create_matrix(1, 1, &m2);

    m1.matrix[0][0] = 0.0;
    m2.matrix[0][0] = 0.0;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(1, 1, &expected_result);
    expected_result.matrix[0][0] = 0.0;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 1========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 4.0;
    m1.matrix[1][0] = 2.0;
    m1.matrix[1][1] = 5.0;
    m1.matrix[2][0] = 3.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 1.0;
    m2.matrix[0][1] = -1.0;
    m2.matrix[0][2] = 1.0;
    m2.matrix[1][0] = 2.0;
    m2.matrix[1][1] = 3.0;
    m2.matrix[1][2] = 4.0;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 9.0;
    expected_result.matrix[0][1] = 11.0;
    expected_result.matrix[0][2] = 17.0;
    expected_result.matrix[1][0] = 12.0;
    expected_result.matrix[1][1] = 13.0;
    expected_result.matrix[1][2] = 22.0;
    expected_result.matrix[2][0] = 15.0;
    expected_result.matrix[2][1] = 15.0;
    expected_result.matrix[2][2] = 27.0;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 2========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(3, 3, &m2);

    const int expected_code = ERROR_CALCULATION_ERROR;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 3========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 3.0;
    m1.matrix[1][1] = 4.0;
    m1.matrix[2][0] = 5.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 4========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(7, 3, &m1);
    s21_create_matrix(3, 5, &m2);

    m1.matrix[0][0] = 1.5;
    m1.matrix[0][1] = 2.5;
    m1.matrix[0][2] = 3.5;
    m1.matrix[1][0] = 4.5;
    m1.matrix[1][1] = 5.5;
    m1.matrix[1][2] = 6.5;
    m1.matrix[2][0] = 7.5;
    m1.matrix[2][1] = 8.5;
    m1.matrix[2][2] = 9.5;
    m1.matrix[3][0] = 10.5;
    m1.matrix[3][1] = 11.5;
    m1.matrix[3][2] = 12.5;
    m1.matrix[4][0] = 13.5;
    m1.matrix[4][1] = 14.5;
    m1.matrix[4][2] = 15.5;
    m1.matrix[5][0] = 16.5;
    m1.matrix[5][1] = 17.5;
    m1.matrix[5][2] = 18.5;
    m1.matrix[6][0] = 19.5;
    m1.matrix[6][1] = 20.5;
    m1.matrix[6][2] = 21.5;

    m2.matrix[0][0] = 22.5;
    m2.matrix[0][1] = 23.5;
    m2.matrix[0][2] = 24.5;
    m2.matrix[0][3] = 25.5;
    m2.matrix[0][4] = 26.5;
    m2.matrix[1][0] = 27.5;
    m2.matrix[1][1] = 28.5;
    m2.matrix[1][2] = 29.5;
    m2.matrix[1][3] = 30.5;
    m2.matrix[1][4] = 31.5;
    m2.matrix[2][0] = 32.5;
    m2.matrix[2][1] = 33.5;
    m2.matrix[2][2] = 34.5;
    m2.matrix[2][3] = 35.5;
    m2.matrix[2][4] = 36.5;

    const int expected_code = ERROR_OK;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(7, 5, &expected_result);
    expected_result.matrix[0][0] = 216.25;
    expected_result.matrix[0][1] = 223.75;
    expected_result.matrix[0][2] = 231.25;
    expected_result.matrix[0][3] = 238.75;
    expected_result.matrix[0][4] = 246.25;
    expected_result.matrix[1][0] = 463.75;
    expected_result.matrix[1][1] = 480.25;
    expected_result.matrix[1][2] = 496.75;
    expected_result.matrix[1][3] = 513.25;
    expected_result.matrix[1][4] = 529.75;
    expected_result.matrix[2][0] = 711.25;
    expected_result.matrix[2][1] = 736.75;
    expected_result.matrix[2][2] = 762.25;
    expected_result.matrix[2][3] = 787.75;
    expected_result.matrix[2][4] = 813.25;
    expected_result.matrix[3][0] = 958.75;
    expected_result.matrix[3][1] = 993.25;
    expected_result.matrix[3][2] = 1027.75;
    expected_result.matrix[3][3] = 1062.25;
    expected_result.matrix[3][4] = 1096.75;
    expected_result.matrix[4][0] = 1206.25;
    expected_result.matrix[4][1] = 1249.75;
    expected_result.matrix[4][2] = 1293.25;
    expected_result.matrix[4][3] = 1336.75;
    expected_result.matrix[4][4] = 1380.25;
    expected_result.matrix[5][0] = 1453.75;
    expected_result.matrix[5][1] = 1506.25;
    expected_result.matrix[5][2] = 1558.75;
    expected_result.matrix[5][3] = 1611.25;
    expected_result.matrix[5][4] = 1663.75;
    expected_result.matrix[6][0] = 1701.25;
    expected_result.matrix[6][1] = 1762.75;
    expected_result.matrix[6][2] = 1824.25;
    expected_result.matrix[6][3] = 1885.75;
    expected_result.matrix[6][4] = 1947.25;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 5========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(2, 3, &m2);

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
    s21_remove_matrix(&m2);
  }
  ++test_number;

  {  // 6========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    set_null(&m2);

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m1, &m2, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
  }
  ++test_number;

  {  // 7========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(2, 3, &m2);

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m2, &m1, &actual_result);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
    s21_remove_matrix(&m2);
  }
  ++test_number;

  {  // 8========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    set_null(&m1);
    s21_create_matrix(2, 3, &m2);

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m2, &m1, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  {  // 9========================================
    matrix_t m1;
    matrix_t m2;
    matrix_t actual_result;
    s21_create_matrix(3, 2, &m1);
    s21_create_matrix(2, 3, &m2);

    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 3.0;
    m1.matrix[1][1] = 4.0;
    m1.matrix[2][0] = 5.0;
    m1.matrix[2][1] = 6.0;

    m2.matrix[0][0] = 7.0;
    m2.matrix[0][1] = 8.0;
    m2.matrix[0][2] = 9.0;
    m2.matrix[1][0] = 10.0;
    m2.matrix[1][1] = 11.0;
    m2.matrix[1][2] = 12.0;

    const int expected_code = ERROR_INCORRECT_MATRIX;
    const int actual_code = algorithm(&m1, &m2, NULL);

    matrix_t expected_result;
    s21_create_matrix(3, 3, &expected_result);
    expected_result.matrix[0][0] = 27.0;
    expected_result.matrix[0][1] = 30.0;
    expected_result.matrix[0][2] = 33.0;
    expected_result.matrix[1][0] = 61.0;
    expected_result.matrix[1][1] = 68.0;
    expected_result.matrix[1][2] = 75.0;
    expected_result.matrix[2][0] = 95.0;
    expected_result.matrix[2][1] = 106.0;
    expected_result.matrix[2][2] = 117.0;

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
    s21_remove_matrix(&m2);
    s21_remove_matrix(&m1);
  }
  ++test_number;

  print_summary(function_name, test_number, successful_test_number);
}