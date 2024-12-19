
FLAG        = -Wall -Wextra -Werror -std=c11 -lm
FLAG_LIB    = -lcheck -lsubunit -lm
FLAG_GCOV   = -fprofile-arcs -ftest-coverage

SRC_ARITH   = $(wildcard arithmetic/*.c)
OBJ_ARITH   = $(patsubst arithmetic/%.c,%.o, $(SRC_ARITH))

SRC_COM     = $(wildcard comparison/*.c)
OBJ_COM     = $(patsubst comparison/%.c,%.o, $(SRC_COM))

SRC_HEL     = $(wildcard helper/*.c)
OBJ_HEL     = $(patsubst helper/%.c,%.o, $(SRC_HEL))

SRC_OTHER   = $(wildcard other/*.c)
OBJ_OTHER   = $(patsubst other/%.c,%.o, $(SRC_OTHER))

SRC_CONV   = $(wildcard conversion/*.c)
OBJ_CONV   = $(patsubst conversion/%.c,%.o, $(SRC_CONV))

SRC_TEST    = $(wildcard test.c)

ALL_FILES := $(SRC_ARITH) $(SRC_COM) $(SRC_HEL) $(SRC_OTHER) $(SRC_CONV) *.c *.h


s21_decimal.a: $(SRC_ARITH) $(SRC_COM) $(SRC_HEL) $(SRC_OTHER) $(SRC_CONV)
	gcc $(FLAG) -c $(SRC_ARITH) $(SRC_COM) $(SRC_HEL) $(SRC_OTHER) $(SRC_CONV) s21_decimal.h
	ar rcs s21_decimal.a $(OBJ_ARITH) $(OBJ_COM) $(OBJ_HEL) $(OBJ_OTHER) $(OBJ_CONV)

all: s21_decimal.a

test: clean s21_decimal.a
	gcc $(FLAG) $(SRC_TEST) s21_decimal.a -o unit_test $(FLAG_LIB)
	cppcheck $(ALL_FILES)
	valgrind -q --tool=memcheck --leak-check=yes ./unit_test
	clang-format -n $(ALL_FILES)

gcov_s21_decimal.a: $(SRC_ARITH) $(SRC_HEL) $(SRC_CONV) $(SRC_OTHER) $(SRC_COM)
	gcc -c $(FLAG_GCOV) $(FLAG) $(SRC_ARITH) $(SRC_HEL) $(SRC_CONV) $(SRC_OTHER) $(SRC_COM) s21_decimal.h
	ar rcs s21_decimal.a $(OBJ_ARITH) $(OBJ_HEL) $(OBJ_CONV) $(OBJ_OTHER) $(OBJ_COM)

gcov_report: clean gcov_s21_decimal.a
	gcc $(FLAG_GCOV) $(FLAG) $(SRC_TEST) s21_decimal.a -o gcov_unit_test $(FLAG_LIB)
	./gcov_unit_test
	gcov $(OBJ_ARITH) $(OBJ_HEL) $(OBJ_CONV) $(OBJ_OTHER) $(OBJ_COM)
	lcov -t "gcov_report" -o s21_decimal_coverage.info -c -d .
	genhtml -o report s21_decimal_coverage.info
	open ./report/index.html

clean:
	rm -f s21_decimal.a
	rm -f *.o
	rm -f *.h.gch
	rm -f unit_test
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f gcov_unit_test
	rm -rf report
	rm -f *.info
	rm -f cppcheck_errors.log
	rm -f valgrind_errors.log

rebuild: clean all
