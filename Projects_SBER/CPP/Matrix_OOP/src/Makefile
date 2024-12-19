FLAG        = -Wall -Wextra --std=c++17 -Werror -lm
FLAG_LIB    = -lgtest_main -lgtest -pthread -lm
FLAG_GCOV   = --coverage -fprofile-arcs -ftest-coverage
ALL_FILES   = *.cpp *.hpp

all: s21_matrix_oop.a

s21_matrix_oop.a:
	g++ $(FLAG) -c s21_matrix_oop.cpp s21_matrix_oop.hpp
	ar rcs s21_matrix_oop.a s21_matrix_oop.o


test: clean s21_matrix_oop.a
	g++ $(FLAG) test_matrix_class.cpp -L . s21_matrix_oop.a -o test_matrix_class $(FLAG_LIB)
	valgrind --tool=memcheck --leak-check=yes ./test_matrix_class
	cppcheck --std=c++17 --language=c++ $(ALL_FILES)
	clang-format -n $(ALL_FILES)
	clang-format -i $(ALL_FILES)


gcov_report: clean s21_matrix_oop.a
	g++ $(FLAG_GCOV) $(FLAG) *.cpp -L . s21_matrix_oop.a -o gcov_test_matrix_class $(FLAG_LIB)
	./gcov_test_matrix_class
	gcov gcov_test_matrix_class.o
	lcov -t "gcov_report" -o s21_matrix_coverage.info -c -d .
	genhtml -o report s21_matrix_coverage.info
	open ./report/index.html


clean:
	rm -rf *.o *.a *.gc* *.info *.out *test_matrix_class
	rm -rf ./report


rebuild: clean all
