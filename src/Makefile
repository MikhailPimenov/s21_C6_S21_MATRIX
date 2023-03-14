# all, clean, test, s21_matrix.a, gcov_report

CC=gcc
STRICT_CFLAGS=-Wall -Werror -Wextra -std=c11 -pedantic

# CHECK_FLAGS=$(shell pkg-config --cflags --libs check)
CHECK_CFLAGS=$(shell pkg-config --cflags check)
CHECK_LFLAGS=$(shell pkg-config --libs check)

# GCOVR_CFLAGS=$(shell pkg-config --cflags gcovr)
GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
# -fprofile-arcs -ftest-coverage
# GCOVR_LFLAGS=$(shell pkg-config --libs gcovr)
GCOVR_LFLAGS=-lgcov


REPORT_DIRECTORY=report
REPORT_DIRECTORY_NO_CHECK=report_no_check
VALGRIND_REPORT_DIRECTORY=valgrind_report

all: tests_no_check gcov_report


gcov_report_no_check: tests_no_check	
		mkdir -p $(REPORT_DIRECTORY_NO_CHECK)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY_NO_CHECK)/coverage_report.html
		open $(REPORT_DIRECTORY_NO_CHECK)/coverage_report.functions.html
# open $(REPORT_DIRECTORY_NO_CHECK)/coverage_report.s21_eq_matrix* 
# START "" $(REPORT_DIRECTORY_NO_CHECK)/coverage_report.functions.html  
# START "" $(REPORT_DIRECTORY_NO_CHECK)/coverage_report.s21_eq_matrix*   
		
gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details -o $(REPORT_DIRECTORY)/coverage_report.html
		open $(REPORT_DIRECTORY)/coverage_report.functions.html
# open $(REPORT_DIRECTORY)/coverage_report.s21_eq_matrix* 
# START "" $(REPORT_DIRECTORY)/coverage_report.functions.html  
# START "" $(REPORT_DIRECTORY)/coverage_report.s21_eq_matrix*  




test: tests_check.out
		-./tests_check.out

tests_check.out: tests/check_tests_main.o tests/check_calc_complements.o tests/check_determinant.o tests/check_eq_matrix.o tests/check_inverse_matrix.o tests/check_mult_matrix.o tests/check_mult_number.o tests/check_sub_matrix.o tests/check_sum_matrix.o tests/check_transpose.o tests/test_extrapack.o s21_calc_complements.o s21_determinant.o s21_inverse_matrix.o s21_mult_matrix.o s21_mult_number.o s21_sub_matrix.o s21_transpose.o s21_eq_matrix.o s21_sum_matrix.o s21_create_matrix.o s21_remove_matrix.o s21_common.o 
		$(CC)  -o $@ $^ $(CHECK_LFLAGS) $(GCOVR_LFLAGS)

tests/check_tests_main.o: tests/check_tests_main.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_calc_complements.o: tests/check_calc_complements.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_determinant.o: tests/check_determinant.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_eq_matrix.o: tests/check_eq_matrix.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_inverse_matrix.o: tests/check_inverse_matrix.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_mult_matrix.o: tests/check_mult_matrix.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_mult_number.o: tests/check_mult_number.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_sub_matrix.o: tests/check_sub_matrix.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_sum_matrix.o: tests/check_sum_matrix.c tests/check_matrix.h 
		$(CC) -c -o $@ $<
tests/check_transpose.o: tests/check_transpose.c tests/check_matrix.h
		$(CC) -c -o $@ $<
tests/test_extrapack.o: tests/test_extrapack.c tests/check_matrix.h
		$(CC) -c -o $@ $<


s21_create_matrix.o: s21_create_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_remove_matrix.o: s21_remove_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_eq_matrix.o: s21_eq_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_sum_matrix.o: s21_sum_matrix.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_sub_matrix.o: s21_sub_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_mult_number.o: s21_mult_number.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_mult_matrix.o: s21_mult_matrix.c s21_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_transpose.o: s21_transpose.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_determinant.o: s21_determinant.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_calc_complements.o: s21_calc_complements.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)
s21_inverse_matrix.o: s21_inverse_matrix.c s21_matrix.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_common.o: s21_common.c s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)




create_matrix_tests.o: tests_no_check/create_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
eq_matrix_tests.o: tests_no_check/eq_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
sum_matrix_tests.o: tests_no_check/sum_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
sub_matrix_tests.o: tests_no_check/sub_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
mult_number_tests.o: tests_no_check/mult_number_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
mult_matrix_tests.o: tests_no_check/mult_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
transpose_tests.o: tests_no_check/transpose_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
determinant_tests.o: tests_no_check/determinant_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
calc_complements_tests.o: tests_no_check/calc_complements_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@
inverse_matrix_tests.o: tests_no_check/inverse_matrix_tests.c tests_no_check/all_tests_without_check.h s21_common.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


print_matrix.o: tests_no_check/print_matrix.c tests_no_check/print_matrix.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@


tests_no_check:	tests_no_check.out
		-./tests_no_check.out

tests_no_check.out: s21_common.o s21_create_matrix.o s21_remove_matrix.o all_tests_without_check.o create_matrix_tests.o print_matrix.o s21_eq_matrix.o eq_matrix_tests.o s21_sum_matrix.o sum_matrix_tests.o s21_sub_matrix.o sub_matrix_tests.o s21_mult_number.o mult_number_tests.o s21_mult_matrix.o mult_matrix_tests.o transpose_tests.o s21_transpose.o s21_determinant.o determinant_tests.o s21_calc_complements.o calc_complements_tests.o s21_inverse_matrix.o inverse_matrix_tests.o
		$(CC) -o $@ $^ $(GCOVR_LFLAGS)

all_tests_without_check.o: tests_no_check/all_tests_without_check.c tests_no_check/all_tests_without_check.h
		$(CC) -c $< -o $@ $(STRICT_CFLAGS) 

valgrind: tests_no_check.out tests_check.out
		mkdir -p $(VALGRIND_REPORT_DIRECTORY)
		-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./tests_no_check.out > $(VALGRIND_REPORT_DIRECTORY)/valgrind_report.txt
		-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./tests_check.out > $(VALGRIND_REPORT_DIRECTORY)/valgrind_report.txt



clean:
		rm -rf report
		rm -f *.o
		rm -f *.gcda
		rm -f *.gcno
		rm -f tests/*.o
		rm -f tests/*.gcda
		rm -f tests/*.gcno
		rm -f test.out
		rm -f *.out