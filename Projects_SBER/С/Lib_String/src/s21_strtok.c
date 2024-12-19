#include "s21_string.h"

// Функция делит строку на подстроки с помощью заданных разделителей.
// Разделители могут быть любыми символами, кроме пробелов.
// Функция возвращает указатель на массив подстрок, а также количество подстрок.
// Если разделителей нет, функция возвращает NULL и 0.

char *s21_strtok(char *str, const char *delim) {
  static char *last;
  register int ch;

  if (str == 0) {
    str = last;
  }
  do {
    if ((ch = *str++) == '\0') {
      return 0;
    }
  } while (s21_strchr(delim, ch));
  --str;
  last = str + s21_strcspn(str, delim);
  if (*last != 0) {
    *last++ = 0;
  }
  return str;
}
/*
int main() {
    char str[] = "hello,world;foo,bar";
    char* token;

    token = s21_strtok(str, ",;");
    while (token) {
        printf("%s\n", token);
        token = s21_strtok(s21_NULL, ",;");
    }

    return 0;
}
*/