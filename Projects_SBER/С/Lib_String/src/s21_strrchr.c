#include "s21_string.h"

// Функция  принимает указатель на строку и символ.
// и возвращает указатель на последнее вхождение этого символа.
// если символа нет, то возвращает  NULL

char *s21_strrchr(const char *str, int c) {
  char target_char = c;
  char *res = S21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == target_char) {
      res = (char *)str;
    }
  }
  if (res == S21_NULL && target_char == '\0') {
    res = (char *)str;
  }
  return res;
}