#include "s21_string.h"  // Для s21_size_t

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  // Проверяем, что dest и src не являются NULL
  if (dest == S21_NULL || src == S21_NULL) {
    return S21_NULL;
  }

  // Находим конец строки dest
  char *end = dest + s21_strlen(dest);

  // Копируем до n символов из src в dest
  while (*src != '\0' && n > 0) {
    *end++ = *src++;
    --n;
  }

  // Добавляем нулевой символ в конец dest
  *end = '\0';

  // Возвращаем указатель на начало dest
  return dest;
}
