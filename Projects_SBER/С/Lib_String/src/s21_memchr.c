#include "s21_string.h"

// memchr – поиск первого вхождения указанного символа в массиве.
// функция принимает массив arr, символ который будем искать в массиве,
// число искомых ячеек в массиве начиная с 0.
// И возвращает указатель на этот символ в массиве если нашли, иначе s21_NULL
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p_arr = str;
  for (; n-- > 0; p_arr++) {
    if (p_arr[0] == (unsigned char)c) {
      return (void *)p_arr;
    }
  }
  return S21_NULL;
}
