#include "s21_string.h"

int s21_strncmp(const char *s1, const char *s2, size_t n) {
  int a = 0;
  for (s21_size_t i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) {
      a = s1[i] - s2[i];
      break;
    }
    if (s1[i] == '\0') {
      break;
    }
  }
  return a;
}
