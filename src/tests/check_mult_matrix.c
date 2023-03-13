#include "check_matrix.h"

START_TEST(mmatr_1) {
    matrix_t val1 = {0}, val2 = {0}, result = {0}, expected = {0};
    s21_create_matrix(3, 3, &val1);
    s21_create_matrix(3, 3, &val2);
    s21_create_matrix(3, 3, &expected);
    val1.matrix[0][0] = 1;
    val1.matrix[0][1] = 1;
    val1.matrix[0][2] = 2;
    val1.matrix[1][0] = 2;
    val1.matrix[1][1] = 4;
    val1.matrix[1][2] = 5;
    val1.matrix[2][0] = 12;
    val1.matrix[2][1] = 13;
    val1.matrix[2][2] = 14;

    val2.matrix[0][0] = 1;
    val2.matrix[0][1] = -4;
    val2.matrix[0][2] = -4;
    val2.matrix[1][0] = -7;
    val2.matrix[1][1] = -7;
    val2.matrix[1][2] = -16;
    val2.matrix[2][0] = -16;
    val2.matrix[2][1] = -17;
    val2.matrix[2][2] = -17;

    expected.matrix[0][0] = -38;
    expected.matrix[0][1] = -45;
    expected.matrix[0][2] = -54;
    expected.matrix[1][0] = -106;
    expected.matrix[1][1] = -121;
    expected.matrix[1][2] = -157;
    expected.matrix[2][0] = -303;
    expected.matrix[2][1] = -377;
    expected.matrix[2][2] = -494;

    ck_assert_int_eq(s21_mult_matrix(&val1, &val2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mmatr_2) {
    matrix_t val1 = {0}, val2 = {0}, result = {0}, expected = {0};
    s21_create_matrix(3, 3, &val1);
    s21_create_matrix(3, 1, &val2);
    s21_create_matrix(3, 1, &expected);
    val1.matrix[0][0] = 5;
    val1.matrix[0][1] = 8;
    val1.matrix[0][2] = -4;
    val1.matrix[1][0] = 6;
    val1.matrix[1][1] = 9;
    val1.matrix[1][2] = -5;
    val1.matrix[2][0] = 4;
    val1.matrix[2][1] = 7;
    val1.matrix[2][2] = -2;

    val2.matrix[0][0] = 2;
    val2.matrix[1][0] = -3;
    val2.matrix[2][0] = 1;

    expected.matrix[0][0] = -18;
    expected.matrix[1][0] = -20;
    expected.matrix[2][0] = -15;

    ck_assert_int_eq(s21_mult_matrix(&val1, &val2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mmatr_3) {
    matrix_t val1 = {0}, val2 = {0}, result = {0}, expected = {0};
    s21_create_matrix(2, 4, &val1);
    s21_create_matrix(4, 6, &val2);
    s21_create_matrix(2, 6, &expected);
    val1.matrix[0][0] = 9;
    val1.matrix[0][1] = 9;
    val1.matrix[0][2] = 2;
    val1.matrix[0][3] = 8;
    val1.matrix[1][0] = 6;
    val1.matrix[1][1] = 7;
    val1.matrix[1][2] = 8;
    val1.matrix[1][3] = 5;

    val2.matrix[0][0] = 2;
    val2.matrix[0][1] = 5;
    val2.matrix[0][2] = 6;
    val2.matrix[0][3] = 8;
    val2.matrix[0][4] = 5;
    val2.matrix[0][5] = 1;
    val2.matrix[1][0] = 0;
    val2.matrix[1][1] = 7;
    val2.matrix[1][2] = 6;
    val2.matrix[1][3] = 4;
    val2.matrix[1][4] = 8;
    val2.matrix[1][5] = 9;
    val2.matrix[2][0] = 0;
    val2.matrix[2][1] = 7;
    val2.matrix[2][2] = 1;
    val2.matrix[2][3] = 6;
    val2.matrix[2][4] = 2;
    val2.matrix[2][5] = 7;
    val2.matrix[3][0] = 1;
    val2.matrix[3][1] = 4;
    val2.matrix[3][2] = 8;
    val2.matrix[3][3] = 4;
    val2.matrix[3][4] = 0;
    val2.matrix[3][5] = 6;

    expected.matrix[0][0] = 26;
    expected.matrix[0][1] = 154;
    expected.matrix[0][2] = 174;
    expected.matrix[0][3] = 152;
    expected.matrix[0][4] = 121;
    expected.matrix[0][5] = 152;
    expected.matrix[1][0] = 17;
    expected.matrix[1][1] = 155;
    expected.matrix[1][2] = 126;
    expected.matrix[1][3] = 144;
    expected.matrix[1][4] = 102;
    expected.matrix[1][5] = 155;

    ck_assert_int_eq(s21_mult_matrix(&val1, &val2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(mmatr_4) {
    matrix_t val1 = {0}, val2 = {0}, result = {0}, expected = {0};
    s21_create_matrix(3, 3, &val1);
    s21_create_matrix(3, 3, &val2);
    s21_create_matrix(3, 3, &expected);
    val1.matrix[0][0] = 3;
    val1.matrix[0][1] = 27;
    val1.matrix[0][2] = 18;
    val1.matrix[1][0] = 0;
    val1.matrix[1][1] = 18;
    val1.matrix[1][2] = 15;
    val1.matrix[2][0] = 24;
    val1.matrix[2][1] = 9;
    val1.matrix[2][2] = 9;

    val2.matrix[0][0] = 3;
    val2.matrix[0][1] = 18;
    val2.matrix[0][2] = 24;
    val2.matrix[1][0] = 21;
    val2.matrix[1][1] = 15;
    val2.matrix[1][2] = 24;
    val2.matrix[2][0] = 0;
    val2.matrix[2][1] = 27;
    val2.matrix[2][2] = 3;

    expected.matrix[0][0] = 576;
    expected.matrix[0][1] = 945;
    expected.matrix[0][2] = 774;
    expected.matrix[1][0] = 378;
    expected.matrix[1][1] = 675;
    expected.matrix[1][2] = 477;
    expected.matrix[2][0] = 261;
    expected.matrix[2][1] = 810;
    expected.matrix[2][2] = 819;

    ck_assert_int_eq(s21_mult_matrix(&val1, &val2, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(error) {
    int rows = rand() % 1000 + 1;
    int columns = rand() % 1000 + 1;
    matrix_t val1 = {0}, val2 = {0}, result = {0};
    s21_create_matrix(rows, columns, &val1);
    rows = rand() % 1000 + 1;
    columns = rand() % 1000 + 1;
    s21_create_matrix(rows, columns, &val2);

    ck_assert_int_eq(s21_mult_matrix(&val1, &val2, &result), C_ERROR);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
}
END_TEST

Suite *mult_matrix_suite(void) {
    Suite *s = suite_create("Mult matrix");
    TCase *tc = tcase_create("");

    tcase_add_test(tc, mmatr_1);
    tcase_add_test(tc, mmatr_2);
    tcase_add_test(tc, mmatr_3);
    tcase_add_test(tc, mmatr_4);
    tcase_add_test(tc, error);

    suite_add_tcase(s, tc);

    return s;
}

