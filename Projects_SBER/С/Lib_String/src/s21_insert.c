#include "s21_string.h"

// Функция для вставки подстроки в строку
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  // Проверяем, что индекс вставки находится в пределах исходной строки
  if (start_index > s21_strlen(src)) {
    printf("Index out of range\n");
    return S21_NULL;
  }

  // Вычисляем размер новой строки
  s21_size_t new_length = s21_strlen(src) + s21_strlen(str);

  // Создаем новую строку
  char *new_str = malloc(new_length + 1);
  if (!new_str) {
    printf("Error of memory allocation for summary line\n");
    return S21_NULL;
  }

  // Копируем часть исходной строки до места вставки
  s21_memcpy(new_str, src, start_index);

  // Вставляем подстроку
  s21_memcpy(new_str + start_index, str, s21_strlen(str));

  // Копируем остаток исходной строки после места вставки
  s21_memcpy(new_str + start_index + s21_strlen(str), src + start_index,
             s21_strlen(src) - start_index);

  // Добавляем нулевой символ в конец новой строки
  new_str[new_length] = '\0';

  // Возвращаем указатель на новую строку
  return new_str;
}
