#include "s21_string.h"

void *s21_to_upper(const char *str) {
  int len_str = 0;
  for (; str[len_str] != 0; len_str++)
    ;
  char *arr = (char *)calloc(len_str + 1, sizeof(char));
  if (arr != S21_NULL) {
    for (int i = 0; len_str > i; i++) {
      arr[i] = str[i];
      if (arr[i] > 96 && arr[i] < 123) arr[i] -= 32;
    }
  }
  return arr;
}
