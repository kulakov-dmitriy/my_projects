
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define S21_NULL ((void *)0)
typedef long unsigned int s21_size_t;
#define BUFF_SIZE 128

void *s21_memchr(const void *arr, int symbol, s21_size_t size);
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t size);
void *s21_memcpy(void *arr1, const void *arr2, s21_size_t size);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
void s21_errnum_tostring(char str[], int num);
s21_size_t s21_strlen(const char *arr);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_upper(const char *string);
void *s21_to_lower(const char *string);
void *s21_trim(const char *src, const char *trim_chars);
void s21_trim_start(char *arr, const char *src, const char *trim_c, int len_src,
                    int len_trim_chars);
void s21_trim_end(char *arr, const char *trim_chars, int len_arr,
                  int len_trim_chars);

const char *working_number(const char *format);
char *working_C(va_list args, char *str);
char *working_num(va_list args, char *str, const char *format);
char *working_S(va_list args, char *str);
void working_star(va_list args);
char *write_arr(va_list args, char *arr_num, const char *format);
void reset_flags();
char *working_P_X(va_list args, char *str, const char *format);
void flag_g_e(va_list args, char *arr_num, const char *format);
void flag_L_ge(va_list args, char *arr_num, const char *format);
void flag_ge(va_list args, char *arr_num, const char *format);
void flag_p_x(va_list args, char *arr_num, const char *format);
void flag_o(va_list args, char *arr_num);
void flag_L_f(va_list args, char *arr_num);
void flag_f(va_list args, char *arr_num);
int preparation_writing(va_list args, char *str, const char *format,
                        char *arr_num);
