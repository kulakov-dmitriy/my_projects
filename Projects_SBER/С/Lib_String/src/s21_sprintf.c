#include "s21_string.h"

struct spec {
  int dot;
  int plus;
  int minus;
  int width;
  int precision;
  int spaces;
  int x10;
  int zero;
  int star;
  int numD;
  int sharp;
  long int li;
  long double ld;
  unsigned int numU;
  int num_min;
  int exit;
  double numF;
} flags;

int s21_sprintf(char *str, const char *format, ...) {
  char *res = str;
  flags.x10 = 1;
  va_list args;
  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      while (!flags.exit) {
        format++;
        if (*format == 'c') {
          str = working_C(args, str);
          format++;
          break;
        } else if (*format == 'd' || *format == 'u' || *format == 'f' ||
                   *format == 'e' || *format == 'E' || *format == 'g' ||
                   *format == 'G' || *format == 'x' || *format == 'X' ||
                   *format == 'p' || *format == 'o') {
          str = working_num(args, str, format);
          format++;
          break;
        } else if (*format == 's') {
          str = working_S(args, str);
          format++;
          break;
        } else if (*format == 'l') {
          flags.li++;
        } else if (*format == 'L') {
          flags.ld++;
        } else if (*format == '#') {
          flags.sharp++;
        } else if (*format == ' ') {
          flags.spaces++;
        } else if (*format == '+') {
          flags.plus++;
        } else if (*format == '-') {
          flags.minus++;
        } else if (*format == '.') {
          flags.x10 = 1;
          flags.dot++;
        } else if (*format == '*') {
          working_star(args);
        } else if (*format == '0' && flags.width == 0 && flags.precision == 0) {
          flags.zero++;
        } else if (*format > 47 && *format < 58) {
          format = working_number(format);
        } else if (*format == '%') {
          *str++ = '%';
          format++;
          flags.exit = 1;
        }
      }
      reset_flags();
    } else {
      *str++ = *format++;
    }
  }
  va_end(args);
  *str = '\0';
  int len_arr = 0;
  for (; res[len_arr] != 0; len_arr++)
    ;
  return len_arr;
}

void reset_flags() {
  flags.dot = 0;
  flags.plus = 0;
  flags.minus = 0;
  flags.width = 0;
  flags.precision = 0;
  flags.spaces = 0;
  flags.x10 = 1;
  flags.zero = 0;
  flags.star = 0;
  flags.sharp = 0;
  flags.exit = 0;
  flags.numD = 0;
  flags.li = 0;
  flags.ld = 0;
  flags.numU = 0;
  flags.num_min = 0;
  flags.numF = 0;
}

void working_star(va_list args) {
  if (flags.dot > 0)
    flags.precision = va_arg(args, int);
  else
    flags.width = va_arg(args, int);
  return;
}

char *working_S(va_list args, char *str) {
  char *res = va_arg(args, char *);
  int res_len = 0;
  for (; res[res_len] != 0; res_len++)
    ;
  char spase = ' ';
  int s = ((res_len < flags.precision) ? res_len
           : flags.dot                 ? flags.precision
                                       : res_len);
  if (!flags.minus) {
    while (flags.width-- - s > 0) {
      *str++ = spase;
    }
    for (int i = 0; i < s; i++) *str++ = res[i];
  } else {
    for (int i = 0; i < s; i++) *str++ = res[i];
    while (flags.width-- - s > 0) {
      *str++ = spase;
    }
  }
  flags.exit = 1;
  return str;
}

void flag_L_ge(va_list args, char *arr_num, const char *format) {
  int n = 0, flag = 0, len_n = 0;
  char ar[1000] = {0};
  if ((*format == 'g' || *format == 'G') && flags.precision > 0) flag = 1;
  if (flags.precision == 0 && !flags.dot) {
    if (*format == 'g' || *format == 'G')
      flags.precision = 5;
    else
      flags.precision = 6;
  }
  flags.ld = va_arg(args, long double);
  if (flags.ld < 0) {
    flags.num_min++;
    flags.ld = -flags.numF;
  }
  for (; flags.ld >= 10; flags.ld /= 10, len_n++)
    ;
  int num = flags.ld;
  flags.ld -= num;
  ar[n++] = num + 48;
  int l = len_n;
  if (flags.precision != 0 || !flags.dot || flags.sharp) {
    if ((*format == 'g' || *format == 'G') && flags.precision == 1) {
    } else
      ar[n++] = '.';
  }
  for (int i = flags.precision - flag; i--;) {
    flags.ld *= 10;
    ar[n++] = (int)flags.ld + 48;
    flags.ld -= (int)flags.ld;
  }
  if (*format == 'E' || *format == 'G')
    ar[n++] = 'E';
  else
    ar[n++] = 'e';
  ar[n++] = '+';
  if (l > 9)
    ar[n++] = l / 10 + 48;
  else
    ar[n++] = '0';
  ar[n++] = l % 10 + 48;
  int len_ar = 0;
  for (; ar[len_ar] != 0; len_ar++)
    ;
  for (int b = 0; 0 <= len_ar - 1; b++, len_ar--) arr_num[b] = ar[len_ar - 1];
  if (flags.ld + 0.5 >= 1.0) {
    if (arr_num[4] == '9') {
      arr_num[4] = '0';
      arr_num[5] += 1;
    } else if (arr_num[4] == '.') {
      arr_num[5] += 1;
    } else
      arr_num[4] += 1;
  }
}

void flag_ge(va_list args, char *arr_num, const char *format) {
  int n = 0, flag = 0, len_n = 0;
  char ar[1000] = {0};
  flags.numF = va_arg(args, double);
  if ((*format == 'g' || *format == 'G') && flags.precision > 0) flag = 1;
  if (flags.numF < 0) {
    flags.num_min++;
    flags.numF = -flags.numF;
  }
  for (; flags.numF >= 10; flags.numF /= 10, len_n++)
    ;
  int num = flags.numF;
  flags.numF -= num;
  ar[n++] = num + 48;

  int l = len_n;
  if (flags.precision != 0 || !flags.dot || flags.sharp) {
    if ((*format == 'g' || *format == 'G') && flags.precision == 1) {
    } else
      ar[n++] = '.';
  }
  for (int i = flags.precision - flag; i--;) {
    flags.numF *= 10;
    ar[n++] = (int)flags.numF + 48;
    flags.numF -= (int)flags.numF;
  }
  if (*format == 'E' || *format == 'G')
    ar[n++] = 'E';
  else
    ar[n++] = 'e';
  ar[n++] = '+';
  ar[n++] = '0';
  ar[n++] = l + 48;
  int len_ar = 0;
  for (; ar[len_ar] != 0; len_ar++)
    ;
  for (int b = 0; 0 <= len_ar - 1; b++, len_ar--) arr_num[b] = ar[len_ar - 1];
  if (flags.numF + 0.5 >= 1.0) {
    if (arr_num[4] == '9') {
      arr_num[4] = '0';
      arr_num[5] += 1;
    } else if (arr_num[4] == '.') {
      arr_num[5] += 1;
    } else
      arr_num[4] += 1;
  }
}

void flag_g_e(va_list args, char *arr_num, const char *format) {
  if (flags.precision == 0 && !flags.dot) {
    if (*format == 'g' || *format == 'G')
      flags.precision = 5;
    else
      flags.precision = 6;
  }
  if (flags.ld > 0) {
    flag_L_ge(args, arr_num, format);
  } else {
    flag_ge(args, arr_num, format);
  }
  return;
}

void flag_p_x(va_list args, char *arr_num, const char *format) {
  char arr[1000] = {0};
  unsigned long va = va_arg(args, unsigned long);
  int i = 0;
  while (va > 0) {
    unsigned long remainder = va % 16;
    if (remainder < 10) {
      arr[i++] = '0' + remainder;
    } else {
      if (*format == 'X')
        arr[i++] = 'A' + (remainder - 10);
      else
        arr[i++] = 'a' + (remainder - 10);
    }
    va /= 16;
  }
  if (*format == 'p') {
    arr[i++] = 'x';
    arr[i++] = '0';
  }
  int res_len = 0;
  for (; arr[res_len] != 0; res_len++)
    ;
  for (int l = 0; l < res_len; l++) {
    *arr_num++ = arr[l];
  }
}

void flag_o(va_list args, char *arr_num) {
  char arr[1000] = {0};
  long va = va_arg(args, long);
  int i = 0;
  while (va > 0) {
    long v = va % 8;
    arr[i++] = '0' + v;
    va /= 8;
  }
  int res_len = 0;
  for (; arr[res_len] != 0; res_len++)
    ;
  for (int l = 0; l < res_len; l++) {
    *arr_num++ = arr[l];
  }
}

void flag_L_f(va_list args, char *arr_num) {
  int n = 0;
  char arr[1000] = {0};
  char ar[1000] = {0};
  flags.ld = va_arg(args, long double);
  if (flags.ld < 0) {
    flags.num_min++;
    flags.ld = -flags.ld;
  }
  int num = flags.ld;
  flags.ld -= num;
  for (; num > 0; n++, num /= 10) arr[n] = num % 10 + 48;
  for (int i = 0; i < n; i++) ar[i] = arr[n - i - 1];
  if (flags.precision != 0 || !flags.dot || flags.sharp) ar[n++] = '.';
  for (int i = flags.precision; i--;) {
    flags.ld *= 10, ar[n++] = (int)flags.ld + 48;
    flags.ld -= (int)flags.ld;
  }
  int len_ar = 0;
  for (; ar[len_ar] != 0; len_ar++)
    ;
  for (n = 0; 0 <= len_ar - 1; n++, len_ar--) arr_num[n] = ar[len_ar - 1];
  if (flags.ld + 0.5 >= 1.0) {
    if (arr_num[0] == '9') {
      arr_num[0] = '0';
      arr_num[1] += 1;
    } else if (arr_num[0] == '.') {
      arr_num[1] += 1;
    } else
      arr_num[0] += 1;
  }
  return;
}

void flag_f(va_list args, char *arr_num) {
  int n = 0;
  char arr[1000] = {0};
  char ar[1000] = {0};
  flags.numF = va_arg(args, double);
  if (flags.numF < 0) {
    flags.num_min++;
    flags.numF = -flags.numF;
  }
  int num = flags.numF;
  flags.numF -= num;
  for (; num > 0; n++, num /= 10) arr[n] = num % 10 + 48;
  for (int i = 0; i < n; i++) ar[i] = arr[n - i - 1];
  if (flags.precision != 0 || !flags.dot || flags.sharp) ar[n++] = '.';
  for (int i = flags.precision; i--;) {
    flags.numF *= 10, ar[n++] = (int)flags.numF + 48;
    flags.numF -= (int)flags.numF;
  }
  int len_ar = 0;
  for (; ar[len_ar] != 0; len_ar++)
    ;
  for (n = 0; 0 <= len_ar - 1; n++, len_ar--) arr_num[n] = ar[len_ar - 1];
  if (flags.numF + 0.5 >= 1.0) {
    if (arr_num[0] == '9') {
      arr_num[0] = '0';
      arr_num[1] += 1;
    } else if (arr_num[0] == '.') {
      arr_num[1] += 1;
    } else
      arr_num[0] += 1;
  }
}

char *write_arr(va_list args, char *arr_num, const char *format) {
  int n = 0;
  if (*format == 'o') {
    flag_o(args, arr_num);
  }
  if (*format == 'p' || *format == 'x' || *format == 'X') {
    flag_p_x(args, arr_num, format);
  }
  if (*format == 'e' || *format == 'E' || *format == 'g' || *format == 'G') {
    flag_g_e(args, arr_num, format);
  }
  if (*format == 'f') {
    if (flags.precision == 0 && !flags.dot) flags.precision = 6;

    if (flags.ld > 0) {
      flag_L_f(args, arr_num);
    } else {
      flag_f(args, arr_num);
    }
  }
  if (*format == 'd') {
    flags.numD = va_arg(args, int);
    if (flags.numD < 0) {
      flags.num_min++;
      flags.numD = -flags.numD;
    }
    for (; flags.numD > 0; n++) {
      arr_num[n] = flags.numD % 10 + 48;
      flags.numD /= 10;
    }
  }
  if (*format == 'u') {
    flags.numU = va_arg(args, unsigned int);
    for (; flags.numU > 0; n++) {
      arr_num[n] = flags.numU % 10 + 48;
      flags.numU /= 10;
    }
  }

  return arr_num;
}

int preparation_writing(va_list args, char *str, const char *format,
                        char *arr_num) {
  flags.x10 = 10;
  write_arr(args, arr_num, format);
  printf("%s", arr_num);
  int res_len = 0;
  for (; arr_num[res_len] != 0; res_len++)
    ;
  if (flags.width == 0 || flags.width < flags.precision)
    flags.width = flags.precision;
  if (flags.spaces > 0 && !flags.num_min) {
    *str++ = ' ';
    if (!flags.dot || flags.precision < flags.width) flags.width--;
  }
  return res_len;
}

char *working_num(va_list args, char *str, const char *format) {
  char arr_num[1000] = {0}, spase = ' ';
  if (flags.zero && !flags.dot && !flags.minus) spase = '0';
  int res_len = preparation_writing(args, arr_num, format, arr_num),
      len = res_len;
  if (flags.minus) {
    if (flags.num_min) {
      flags.plus = 0;
      *str++ = '-';
      flags.width--;
    }
    if (flags.plus) {
      *str++ = '+';
      flags.width++;
    }
    if (flags.precision > len) {
      while (0 < flags.precision-- - len) {
        *str++ = '0';
        flags.width--;
      }
    }
    while (0 < len) *str++ = arr_num[--len];
    while (flags.width-- > res_len) *str++ = spase;
  } else {
    if (flags.num_min || flags.plus) flags.width--;
    int flag = (flags.width < flags.precision) ? 0 : 1;
    while (flags.width-- >
           res_len +
               (flags.precision - res_len < 0 ? 0 : flags.precision - res_len))
      *str++ = spase;
    char spase = '0';
    if (flags.num_min) {
      flags.plus = 0;
      *str++ = '-';
      if (!flag) flags.width++;
    }
    if (flags.plus) {
      *str++ = '+';
      flags.width++;
    }
    while (1 + flags.width-- > res_len) *str++ = spase;
    while (0 < res_len) *str++ = arr_num[--res_len];
  }
  flags.exit = 1;
  return str;
}

char *working_C(va_list args, char *str) {
  char spase = ' ';
  if (flags.zero) spase = '0';
  if (!flags.minus) {
    while (flags.width-- > 1) {
      *str++ = spase;
    }
    *str++ = (char)va_arg(args, int);
  } else {
    *str++ = (char)va_arg(args, int);
    while (flags.width-- > 1) {
      *str++ = spase;
    }
  }
  flags.exit = 1;
  return str;
}

const char *working_number(const char *format) {
  if (!flags.dot) {
    flags.width = flags.width * flags.x10 + (*format - 48);
  } else {
    if (*format == '0' && flags.precision == 0) {
      return format++;
    }
    flags.precision = flags.precision * flags.x10 + (*format - 48);
  }
  flags.x10 *= 10;
  return format;
}