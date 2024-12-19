#include "s21_string.h"

// Функция memcmp сравнивает две области памяти, возвращая отрицательное число,
// ноль или положительное число, если первый аргумент меньше, равен или
// больше второго соответственно.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p_arr1 = str1, *p_arr2 = str2;
  for (; n-- > 1 && !(*p_arr1 - *p_arr2); p_arr1++, p_arr2++)
    ;
  return *p_arr1 - *p_arr2;
}
