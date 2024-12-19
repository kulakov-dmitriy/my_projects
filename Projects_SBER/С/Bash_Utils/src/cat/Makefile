FLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

all: s21_cat

s21_cat: clean
	gcc $(FLAGS) s21_cat.c -o s21_cat

test: s21_cat
	bash test_cat.sh

rebuild:
	make clean
	make all

clean:
	rm -rf s21_cat

clangN:
	clang-format -style=Google -n *.c *.h

clangI:
	clang-format -style=Google -i *.c *.h