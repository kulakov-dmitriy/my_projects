FLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

all: s21_grep

s21_grep: clean
	gcc $(FLAGS) s21_grep.c -o s21_grep

test: s21_grep
	bash test_grep.sh

rebuild:
	make clean
	make all

clean:
	rm -rf s21_grep

clangN:
	clang-format -style=Google -n *.c *.h

clangI:
	clang-format -style=Google -i *.c *.h
