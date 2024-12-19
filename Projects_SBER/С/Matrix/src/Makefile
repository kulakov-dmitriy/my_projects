FLAG        = -Wall -Wextra -Werror -std=c11 -lm
FLAG_LIB    = -lcheck -lsubunit -lm
FLAG_GCOV   = -fprofile-arcs -ftest-coverage
ALL_FILES   = *.c *.h

all: s21_matrix.a

s21_matrix.a:
	gcc $(FLAG) -c s21_matrix.c s21_matrix.h
	ar rcs s21_matrix.a s21_matrix.o


test: clean s21_matrix.a
	gcc $(FLAG) unit_test.c s21_matrix.a -o unit_test $(FLAG_LIB)
	cppcheck --enable=all --inconclusive --quiet --std=c11 --language=c --suppress=missingIncludeSystem $(ALL_FILES)
	valgrind -q --tool=memcheck --leak-check=yes ./unit_test
	clang-format -n $(ALL_FILES)
	clang-format -i $(ALL_FILES)


gcov_report: clean
	gcc $(FLAG) $(FLAG_GCOV) -c s21_matrix.c s21_matrix.h
	ar rcs s21_matrix.a s21_matrix.o
	gcc $(FLAG_GCOV) $(FLAG) *.c s21_matrix.a -o gcov_unit_test $(FLAG_LIB)
	./gcov_unit_test
	gcov s21_matrix.o
	lcov -t "gcov_report" -o s21_matrix_coverage.info -c -d .
	genhtml -o report s21_matrix_coverage.info
	open ./report/index.html 


clean:
	rm -rf *.o *.a *.gc* *.info *.out *unit_test
	rm -rf ./report


rebuild: clean all

