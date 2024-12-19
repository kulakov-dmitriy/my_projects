#include "s21_string.h"

// функия принимает строку и подстроку
//  возвращает указатель на вхождение подстроки в строку либо NULL

char *s21_strstr(const char *haystack, const char *needle) {
  char *position = S21_NULL;
  size_t haystack_len = s21_strlen(haystack);
  size_t needle_len = s21_strlen(needle);

  if (needle_len == 0) {
    return (char *)haystack;
  }

  for (size_t i = 0; i <= haystack_len - needle_len; i++) {
    int match = 1;
    for (size_t j = 0; j < needle_len; j++) {
      if (haystack[i + j] != needle[j]) {
        match = 0;
        break;
      }
    }
    if (match) {
      position = (char *)&haystack[i];
      break;
    }
  }

  return position;
}
