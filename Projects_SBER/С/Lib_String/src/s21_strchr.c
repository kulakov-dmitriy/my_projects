#include "s21_string.h"

char *s21_strchr(const char *arr, int symbol) {
  const unsigned char *p_arr = (const unsigned char *)arr;
  for (; *p_arr != '\0'; p_arr++) {
    if (*p_arr == (unsigned char)symbol) {
      return (void *)p_arr;
    }
  }
  return S21_NULL;
}
