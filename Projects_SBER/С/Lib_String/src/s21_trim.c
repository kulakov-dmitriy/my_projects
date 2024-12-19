#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  int len_src = 0;
  for (; src[len_src] != 0; len_src++)
    ;

  int len_trim_chars = 0;
  if (trim_chars != S21_NULL)
    for (; trim_chars[len_trim_chars] != 0; len_trim_chars++)
      ;

  char *arr = (char *)calloc(len_src + 1, sizeof(char));
  if (len_trim_chars > 0) {
    s21_trim_start(arr, src, trim_chars, len_src, len_trim_chars);
    int len_arr = 0;
    for (; arr[len_arr] != 0; len_arr++)
      ;
    s21_trim_end(arr, trim_chars, len_arr, len_trim_chars);
  } else {
    s21_trim_start(arr, src, " \n\t", len_src, 3);
    int len_arr = 0;
    for (; arr[len_arr] != 0; len_arr++)
      ;
    s21_trim_end(arr, " \n\t", len_arr, 3);
  }
  return arr;
}

void s21_trim_start(char *arr, const char *src, const char *trim_c, int len_src,
                    int len_trim_chars) {
  int flag = 1, count = 0;
  for (int i = 0; i < len_src; ++i) {
    for (int j = 0; j < len_trim_chars && flag > 0; ++j) {
      if (src[i] == trim_c[j]) {
        flag++;
        break;
      }
    }
    if (flag > 1) {
      flag = 1;
      continue;
    }
    if (flag == 1) {
      flag = 0;
    }
    arr[count++] = src[i];
  }
}

void s21_trim_end(char *arr, const char *trim_chars, int len_arr,
                  int len_trim_chars) {
  int flag = 1;
  for (int i = len_arr - 1; i > 0 && flag > 0; --i) {
    for (int j = 0; j < len_trim_chars; ++j) {
      if (arr[i] == trim_chars[j]) {
        printf("%c", arr[i]);
        arr[i] = 0;
        flag++;
        break;
      }
    }
    if (flag == 1) {
      flag = 0;
    }
    if (flag > 1) {
      flag = 1;
    }
  }
}
