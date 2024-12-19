SHELL := /bin/bash

GCC_FLAGS = -Wall -Werror -Wextra -std=c11
FSANITAIZE_FLAGS = -g -fsanitize=address
TEST_FLAGS = -lcheck -lsubunit -lm -lrt -lpthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

 # папка с исходниками тестов наших функций
TEST_DIR = ./test
 # папка для временного хранения объектных файлов наших функций
OBJ_DIR = ./objs
 # папка для временного хранения объектных файлов наших функций, скомпилированных с флагами gcov
GCOV_OBJ_DIR = ./gcov_obj
 # папка для временного хранения объектного файла тестов (main)
TEST_OBJ_DIR = ./test/objs
 # исполняемый файл, тестирующий наши функции в стат библиотеке
TEST.OUT = check_unit_tests.out
 # исполняемый файл для генерации файлов данных покрытия (.gcda и .gcno)
GCOV.OUT = gcov.out

CLANG = clang-format -i $(TEST_DIR)/*.c *.c *.h
VALGRIND = 2>&1 valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all


all: s21_string.a # цели прописанные в задании

# rebuild: clean all # цели прописанные в задании

# компиляция и запуск исполняемого файла тестирующего наши функции (с использованием стат библиотеки)
# проверка исполняемого файла на утечки памяти
test: clean $(TEST_OBJ_DIR)/s21_test.o s21_string.a
	$(CLANG) & gcc $(GCC_FLAGS) $(TEST_OBJ_DIR)/s21_test.o s21_string.a $(TEST_FLAGS) -o $(TEST.OUT)
	$(VALGRIND) ./$(TEST.OUT)  | grep -E ERROR
	./$(TEST.OUT)


# создание статической библиотеки для вертера
s21_string.a: $(OBJ_DIR)/s21_*.o
	ar r s21_string.a $(OBJ_DIR)/s21_*.o
	# ranlib s21_string.a

# создание статической библиотеки с флагами gcov
s21_string_gcov.a: $(GCOV_OBJ_DIR)/s21_*.o
	ar r s21_string.a $(GCOV_OBJ_DIR)/s21_*.o
	# ranlib s21_string.a

# создание объектных файлов наших функций для "чистой" библиотеки для вертера
$(OBJ_DIR)/%.o: ./%.c | $(OBJ_DIR)
	gcc $(GCC_FLAGS) -c s21_memchr.c -o $(OBJ_DIR)/s21_memchr.o
	gcc $(GCC_FLAGS) -c s21_memcmp.c -o $(OBJ_DIR)/s21_memcmp.o
	gcc $(GCC_FLAGS) -c s21_memcpy.c -o $(OBJ_DIR)/s21_memcpy.o
	gcc $(GCC_FLAGS) -c s21_memset.c -o $(OBJ_DIR)/s21_memset.o
	gcc $(GCC_FLAGS) -c s21_strncat.c -o $(OBJ_DIR)/s21_strncat.o
	gcc $(GCC_FLAGS) -c s21_strchr.c -o $(OBJ_DIR)/s21_strchr.o
	gcc $(GCC_FLAGS) -c s21_strncmp.c -o $(OBJ_DIR)/s21_strncmp.o
	gcc $(GCC_FLAGS) -c s21_strncpy.c -o $(OBJ_DIR)/s21_strncpy.o
	gcc $(GCC_FLAGS) -c s21_strcspn.c -o $(OBJ_DIR)/s21_strcspn.o
	gcc $(GCC_FLAGS) -c s21_strerror.c -o $(OBJ_DIR)/s21_strerror.o
	gcc $(GCC_FLAGS) -c s21_strlen.c -o $(OBJ_DIR)/s21_strlen.o
	gcc $(GCC_FLAGS) -c s21_strpbrk.c -o $(OBJ_DIR)/s21_strpbrk.o
	gcc $(GCC_FLAGS) -c s21_strrchr.c -o $(OBJ_DIR)/s21_strrchr.o
	gcc $(GCC_FLAGS) -c s21_strstr.c -o $(OBJ_DIR)/s21_strstr.o
	gcc $(GCC_FLAGS) -c s21_strtok.c -o $(OBJ_DIR)/s21_strtok.o
	gcc $(GCC_FLAGS) -c s21_to_lower.c -o $(OBJ_DIR)/s21_to_lower.o
	gcc $(GCC_FLAGS) -c s21_to_upper.c -o $(OBJ_DIR)/s21_to_upper.o
	gcc $(GCC_FLAGS) -c s21_trim.c -o $(OBJ_DIR)/s21_trim.o
	gcc $(GCC_FLAGS) -c s21_insert.c -o $(OBJ_DIR)/s21_insert.o
	gcc $(GCC_FLAGS) -c s21_sprintf.c -o $(OBJ_DIR)/s21_sprintf.o

# создание объектных файлов наших функций с флагами gcov
$(GCOV_OBJ_DIR)/%.o: ./%.c | $(GCOV_OBJ_DIR)
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_memchr.c -o $(GCOV_OBJ_DIR)/s21_memchr.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_memcmp.c -o $(GCOV_OBJ_DIR)/s21_memcmp.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_memcpy.c -o $(GCOV_OBJ_DIR)/s21_memcpy.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_memset.c -o $(GCOV_OBJ_DIR)/s21_memset.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strncat.c -o $(GCOV_OBJ_DIR)/s21_strncat.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strchr.c -o $(GCOV_OBJ_DIR)/s21_strchr.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strncmp.c -o $(GCOV_OBJ_DIR)/s21_strncmp.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strncpy.c -o $(GCOV_OBJ_DIR)/s21_strncpy.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strcspn.c -o $(GCOV_OBJ_DIR)/s21_strcspn.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strerror.c -o $(GCOV_OBJ_DIR)/s21_strerror.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strlen.c -o $(GCOV_OBJ_DIR)/s21_strlen.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strpbrk.c -o $(GCOV_OBJ_DIR)/s21_strpbrk.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strrchr.c -o $(GCOV_OBJ_DIR)/s21_strrchr.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strstr.c -o $(GCOV_OBJ_DIR)/s21_strstr.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_strtok.c -o $(GCOV_OBJ_DIR)/s21_strtok.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_to_lower.c -o $(GCOV_OBJ_DIR)/s21_to_lower.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_to_upper.c -o $(GCOV_OBJ_DIR)/s21_to_upper.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_trim.c -o $(GCOV_OBJ_DIR)/s21_trim.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_insert.c -o $(GCOV_OBJ_DIR)/s21_insert.o
	gcc $(GCC_FLAGS) $(GCOV_FLAGS) -c s21_sprintf.c -o $(GCOV_OBJ_DIR)/s21_sprintf.o

# создание объектного файла с тестами для последующей компиляции со статической библиотекой
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(TEST_OBJ_DIR)
	gcc $(GCC_FLAGS) -c $< -o $@

# создание папки для хранения объектных файлов наших функций
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# создание папки для хранения объектных файлов наших функций, скомпиллированных с флагами gcov
$(GCOV_OBJ_DIR):
	mkdir -p $(GCOV_OBJ_DIR)

# создание папки для хранения объектного файла тестов (с функцией main!)
$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

# компиляция и запуск исполняемого файла для генерации файлов данных покрытия (.gcda и .gcno)
# (с использованием стат библиотеки)
gcov_report: clean $(TEST_OBJ_DIR)/s21_test.o s21_string_gcov.a
	$(CLANG) & gcc $(GCC_FLAGS) $(GCOV_FLAGS) $(TEST_OBJ_DIR)/s21_test.o s21_string.a $(TEST_FLAGS) -o $(TEST_DIR)/$(GCOV.OUT)
	$(VALGRIND) $(TEST_DIR)/$(GCOV.OUT)  | grep -E ERROR
	$(TEST_DIR)/$(GCOV.OUT)
	lcov -t "Report" -c -d ./gcov_obj/ --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

# clean, он и в Африке clean
clean: 
	rm -rf *.a $(TEST_DIR)/*.out *.out *.info
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(TEST_OBJ_DIR)/*.o
	rm -rf $(GCOV_OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJ_DIR)
	rm -rf $(GCOV_OBJ_DIR)
	rm -rf *.o
	rm -rf *.gcno $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcov $(TEST_DIR)/*.gcda
	rm -rf report/
