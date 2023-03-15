#include "check_matrix.h"

START_TEST(calc_compl_1)
{
    matrix_t a = {0};
    s21_create_matrix(3, 3, &a);
    matrix_t result = {0};
    s21_create_matrix(3, 3, &result);
    matrix_t m;
    result.matrix[0][0] = 0;
    result.matrix[0][1] = 10;
    result.matrix[0][2] = -20;
    result.matrix[1][0] = 4;
    result.matrix[1][1] = -14;
    result.matrix[1][2] = 8;
    result.matrix[2][0] = -8;
    result.matrix[2][1] = -2;
    result.matrix[2][2] = 4;

    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[1][0] = 0;
    a.matrix[1][1] = 4;
    a.matrix[1][2] = 2;
    a.matrix[2][0] = 5;
    a.matrix[2][1] = 2;
    a.matrix[2][2] = 1;
    s21_calc_complements(&a, &m);
    ck_assert_int_eq(s21_eq_matrix(&result, &m), SUCCESS);
    s21_remove_matrix(&m);
    s21_remove_matrix(&a);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_compl_2)
{
    matrix_t A, B, C;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &C);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 4.0;
    A.matrix[1][2] = 2.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = 2.0;
    A.matrix[2][2] = 1.0;
    s21_calc_complements(&A, &B);
    C.matrix[0][0] = 0.0;
    C.matrix[0][1] = 10.0;
    C.matrix[0][2] = -20.0;
    C.matrix[1][0] = 4.0;
    C.matrix[1][1] = -14.0;
    C.matrix[1][2] = 8.0;
    C.matrix[2][0] = -8.0;
    C.matrix[2][1] = -2.0;
    C.matrix[2][2] = 4.0;
    ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST
START_TEST(empty)
{
    matrix_t A = {0};
    matrix_t B = {0};
    ck_assert_int_eq(s21_calc_complements(&A, &B), ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(size_mismatch)
{
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(1, 2, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &B), ERROR_CALCULATION_ERROR);
    s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements)
{
    const int size = 3;
    matrix_t val1 = {0};
    s21_create_matrix(size, size, &val1);
    val1.matrix[0][0] = 1;
    val1.matrix[0][1] = 2;
    val1.matrix[0][2] = 3;
    val1.matrix[1][1] = 4;
    val1.matrix[1][2] = 2;
    val1.matrix[2][0] = 5;
    val1.matrix[2][1] = 2;
    val1.matrix[2][2] = 1;

    matrix_t expected = {0};
    s21_create_matrix(size, size, &expected);
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;
    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;
    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    matrix_t result = {0};
    ck_assert_int_eq(s21_calc_complements(&val1, &result), ERROR_OK);

    ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
}
END_TEST

Suite *complements_matrix_suite(void)
{
    Suite *s = suite_create("Algebraic complement");
    TCase *tc = tcase_create("");

    tcase_add_test(tc, calc_compl_1);
    tcase_add_test(tc, calc_compl_2);
    tcase_add_test(tc, complements);
    tcase_add_test(tc, empty);
    tcase_add_test(tc, size_mismatch);

    suite_add_tcase(s, tc);

    return s;
}
