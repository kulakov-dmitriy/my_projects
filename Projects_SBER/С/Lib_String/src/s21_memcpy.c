#include "s21_string.h"

// Функция memcpy используется для копирования памяти.
// Она принимает два аргумента: указатель на исходную область памяти и указатель
// на целевую область памяти. Также функция может принимать третий аргумент,
// который указывает количество байт, которые нужно скопировать.

// Функция memcpy работает следующим образом: она начинает копирование с адреса,
// на который указывает первый аргумент, и продолжает до тех пор, пока не будет
// скопировано количество байт, указанное третьим аргументом. Если третий
// аргумент не указан, то копирование продолжается до конца области памяти, на
// которую указывает второй аргумент.

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *p_arr1 = (unsigned char *)dest, *p_arr2 = (unsigned char *)src;
  for (; n-- > 0; p_arr1++, p_arr2++) {
    *p_arr1 = *p_arr2;
  }
  return dest;
}
