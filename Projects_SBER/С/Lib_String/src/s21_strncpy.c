#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  s21_size_t copied = 0;
  while ((src[copied] != '\0') && (copied < n)) {
    dest[copied] = src[copied];
    copied++;
  }
  dest[copied] = '\0';
  return dest;
}
