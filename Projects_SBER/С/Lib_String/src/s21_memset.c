#include "s21_string.h"

// Копирует символ symbol (беззнаковый тип) в первые n символов
// строки, на которую указывает аргумент arr.

void *s21_memset(void *arr, int symbol, s21_size_t n) {
  char *s = (char *)arr;

  for (s21_size_t i = 0; i < n; i++) {
    s[i] = symbol;
  }
  return arr;
}
