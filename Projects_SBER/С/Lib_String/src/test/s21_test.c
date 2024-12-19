#include <check.h>
#include <string.h>

#include "../s21_string.h"

// для запуска тестов заходим в src/test и вводим команду:
// clang-format -i *.c ../*.c ../*.h & gcc -Wall -Werror -Wextra -std=c11
// ../s21_string.h s21_test.c ../s21_*.c -lcheck -lsubunit -lm -lrt -lpthread -o
// check_unit_tests

// затем проверяем:
// 2>&1 valgrind --tool=memcheck --leak-check=yes
// --leak-check=full --show-leak-kinds=all ./check_unit_tests  | grep -E ERROR

//  и запускаем:
// ./check_unit_tests

// после чего исполнякмый файл лучше удалить:
// rm -f ./check_unit_tests

// при пополнении папки src новыми функциями, команды не меняются
START_TEST(s21_memchr_test) {
  char test_1[] = "1\n2345678";
  char test_2[] = "Hello!!!";
  char test_3[] = "1\0";
  char test_4[] = "     ";
  char test_5[] = "123\045678";
  char test_6[] = "yt\tyty\0";
  ck_assert_ptr_eq(s21_memchr(test_1, 5, 2), memchr(test_1, 5, 2));
  ck_assert_ptr_eq(s21_memchr(test_2, 108, 20), memchr(test_2, 108, 20));
  ck_assert_ptr_eq(s21_memchr(test_3, 0, 5), memchr(test_3, 0, 5));
  ck_assert_ptr_eq(s21_memchr(test_4, 'g', 2), memchr(test_4, 'g', 2));
  ck_assert_ptr_eq(s21_memchr(test_5, '6', 10), memchr(test_5, '6', 10));
  ck_assert_ptr_eq(s21_memchr(test_6, 'h', 3), memchr(test_6, 'h', 3));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "Hello World!!!";
  char test2[] = "my name is...";
  char test4[] = "ret\0urn///";
  char test5[] = "j\nglfk   djg";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16), memcmp(test1, test2, 16));
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9), memcmp(test4, test1, 9));
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7), memcmp(test4, test5, 7));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST

START_TEST(s21_to_upper_test) {
  char test_1[15] = "123\t4567890";
  char test_2[10] = "     ";
  char test_3[30] = "/?'\"{}[]-=+";
  char test_4[10] = "ABCDEFG";
  char test_5[30] = "ab\ncdefg";
  char test_6[30] = "4asd4fdDS4awERew4E!";
  char test_7[20] = "QwErT\0qWeR";

  char test_01[15] = "123\t4567890";
  char test_02[10] = "     ";
  char test_03[30] = "/?'\"{}[]-=+";
  char test_04[10] = "ABCDEFG";
  char test_05[30] = "AB\nCDEFG";
  char test_06[30] = "4ASD4FDDS4AWEREW4E!";
  char test_07[20] = "QWERT\0QWER";

  char *t1 = s21_to_upper(test_1);
  char *t2 = s21_to_upper(test_2);
  char *t3 = s21_to_upper(test_3);
  char *t4 = s21_to_upper(test_4);
  char *t5 = s21_to_upper(test_5);
  char *t6 = s21_to_upper(test_6);
  char *t7 = s21_to_upper(test_7);

  ck_assert_pstr_eq(t1, test_01);
  free(t1);
  ck_assert_pstr_eq(t2, test_02);
  free(t2);
  ck_assert_pstr_eq(t3, test_03);
  free(t3);
  ck_assert_pstr_eq(t4, test_04);
  free(t4);
  ck_assert_pstr_eq(t5, test_05);
  free(t5);
  ck_assert_pstr_eq(t6, test_06);
  free(t6);
  ck_assert_pstr_eq(t7, test_07);
  free(t7);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char test_1[15] = "123\t4567890";
  char test_2[10] = "     ";
  char test_3[30] = "/?'\"{}[]-=+";
  char test_4[10] = "ABCDEFG";
  char test_5[30] = "ab\ncdefg";
  char test_6[30] = "4asd4fdDS4awERew4E!";
  char test_7[20] = "QwErT\0qWeR";

  char test_01[15] = "123\t4567890";
  char test_02[10] = "     ";
  char test_03[30] = "/?'\"{}[]-=+";
  char test_04[10] = "abcdefg";
  char test_05[30] = "ab\ncdefg";
  char test_06[30] = "4asd4fdds4awerew4e!";
  char test_07[20] = "qwert\0qwer";

  char *t1 = s21_to_lower(test_1);
  char *t2 = s21_to_lower(test_2);
  char *t3 = s21_to_lower(test_3);
  char *t4 = s21_to_lower(test_4);
  char *t5 = s21_to_lower(test_5);
  char *t6 = s21_to_lower(test_6);
  char *t7 = s21_to_lower(test_7);

  ck_assert_pstr_eq(t1, test_01);
  free(t1);
  ck_assert_pstr_eq(t2, test_02);
  free(t2);
  ck_assert_pstr_eq(t3, test_03);
  free(t3);
  ck_assert_pstr_eq(t4, test_04);
  free(t4);
  ck_assert_pstr_eq(t5, test_05);
  free(t5);
  ck_assert_pstr_eq(t6, test_06);
  free(t6);
  ck_assert_pstr_eq(t7, test_07);
  free(t7);
}
END_TEST

START_TEST(s21_trim_test) {
  char test_1[15] = "123\t4567890";
  char test_2[10] = "     ";
  char test_3[30] = "/?'\"{}[]-=+";
  char test_4[10] = "ABCDEFG";
  char test_5[30] = "ab\ncdefg";
  char test_6[30] = "4asd4fdDS4awERew4E!";
  char test_7[20] = "   qwert   ";

  char test_01[15] = "3\t45678";
  char test_02[10] = "";
  char test_03[30] = "/?'\"{}[]-=+";
  char test_04[10] = "ABCDEFG";
  char test_05[30] = "ab\nc";
  char test_06[30] = "";
  char test_07[20] = "qwert";

  char *t1 = s21_trim(test_1, "1290");
  char *t2 = s21_trim(test_2, " ");
  char *t3 = s21_trim(test_3, "{}[]");
  char *t4 = s21_trim(test_4, "abcd");
  char *t5 = s21_trim(test_5, "defg");
  char *t6 = s21_trim(test_6, "4asd4fdDS4awERew4E!");
  char *t7 = s21_trim(test_7, "");

  ck_assert_str_eq(t1, test_01);
  free(t1);
  ck_assert_str_eq(t2, test_02);
  free(t2);
  ck_assert_str_eq(t3, test_03);
  free(t3);
  ck_assert_str_eq(t4, test_04);
  free(t4);
  ck_assert_str_eq(t5, test_05);
  free(t5);
  ck_assert_str_eq(t6, test_06);
  free(t6);
  ck_assert_str_eq(t7, test_07);
  free(t7);
}
END_TEST

// sheri tests

START_TEST(s21_strrchr_test_1) {
  char test[] = "Da, Bu, Di, Da, Bu, Da";
  char c = 'D';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  char test[] = "aaaaaaaaaaaaaaaa";
  char c = 'b';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_3) {
  char test[] = "1234567890";
  char c = 9;
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_4) {
  char test[] = "!@#$&*()_-+=";
  char c = '!';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_5) {
  char test[] = "\t\t\t\t";
  char c = '\t';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_6) {
  char test[] = "\0\0\0\0\0\0\0";
  char c = '\0';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_7) {
  char test[] = "";
  char c = 'a';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_8) {
  char test[] = " ";
  char c = ' ';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_9) {
  char test[] = "a";
  char c = 'a';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strrchr_test_10) {
  char test[] = "ab";
  char c = 'b';
  ck_assert_pstr_eq(s21_strrchr(test, c), strrchr(test, c));
}
END_TEST

START_TEST(s21_strtok_test_1) {
  char str1[] = "abc";
  char str2[] = "abc";
  char str3[] = "b";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str3, str2));
}
END_TEST

START_TEST(s21_strtok_test_2) {
  char str1[] = "  ";
  char str2[] = "  ";
  char str3[] = " ";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str3, str2));
}
END_TEST

START_TEST(s21_strtok_test_3) {
  char str1[] = "12345;6789";
  char str3[] = ";";
  ck_assert_pstr_eq(s21_strtok(str1, str3), strtok(str1, str3));
}
END_TEST

START_TEST(s21_strtok_test_4) {
  char str1[] = "abc1abc";
  char str2[] = "1";
  ck_assert_pstr_eq(s21_strtok(str1, str2), strtok(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_1) {
  char str1[] = "123456789";
  char str2[] = "123";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char str1[] = "abc";
  char str2[] = "Abc";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(s21_strstr_test_4) {
  char str1[] = "abc";
  char str2[] = "de";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

// bandy tests

START_TEST(s21_strlen_test_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_2) {
  char str[] =
      "122345354544333534 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_3) {
  char str[] = "Hello, how are you!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_5) {
  char str[] = "y a s d f e!!!!!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_6) {
  char str[] = "______";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_7) {
  char str[] = "abcdefghixyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_8) {
  char str[] = "       00000000   !!!!   ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_9) {
  char str[] = "\\n\n\n\n\n\n\nlololol\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_12) {
  char str[] = "\t\t\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_13) {
  char str[] = "\0tesst";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_14) {
  char str[] = "awtf \0 wtsaf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strlen_test_15) {
  char str[] = "!@#$_++^&*()";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strerror_test_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(s21_strerror_test_2) {
  int n = -1000;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

// START_TEST(s21_strpbrk_test_1) {
//   const char str1[] = "Hello, World!";
//   const char str2[] = "tyui";

//   char *expected = strpbrk(str1, str2);
//   char *actual = s21_strpbrk(str1, str2);

//   ck_assert_ptr_eq(actual, expected);
// }
// END_TEST

// START_TEST(s21_strpbrk_test_2) {
//   const char str1[] = "japouyt";
//   const char str2[] = "YAPOU";

//   char *expected = strpbrk(str1, str2);
//   char *actual = s21_strpbrk(str1, str2);

//   ck_assert_ptr_eq(actual, expected);
// }
// END_TEST

START_TEST(s21_strpbrk_test_3) {
  const char str1[] = "Test";
  const char str2[] = "TEst";

  const char *expected = strpbrk(str1, str2);
  char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_4) {
  const char str1[] = "19999999";
  const char str2[] = "uytr";

  const char *expected = strpbrk(str1, str2);
  char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_5) {
  const char str1[] = "$!##$*())";
  const char str2[] = "**()";

  char *expected = strpbrk(str1, str2);
  char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_6) {
  const char str1[] = "okjkjnkj";
  const char str2[] = "VFcftDCt";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_7) {
  const char str1[] = "Hello, World!";
  const char str2[] = "KHGFDDDCXFCGJ";

  char *expected = strpbrk(str1, str2);
  char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

// START_TEST(s21_strpbrk_test_8) {
//   const char str1[] = "Test";
//   const char str2[] = "6788654434";

//   char *expected = strpbrk(str1, str2);
//   char *actual = s21_strpbrk(str1, str2);

//   ck_assert_ptr_eq(actual, expected);
// }
// END_TEST

START_TEST(s21_strpbrk_test_9) {
  const char str1[] = "786867657";
  const char str2[] = "*(*^$##)";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_10) {
  const char str1[] = "";
  const char str2[] = "";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_11) {
  const char str1[] = "   g f AAAAF";
  const char str2[] = "F";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_12) {
  const char str1[] = "wqeeqwewq";
  const char str2[] = "";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_13) {
  const char str1[] = "     ";
  const char str2[] = "  ";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_14) {
  const char str1[] = "\n";
  const char str2[] = "\n";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

START_TEST(s21_strpbrk_test_15) {
  const char str1[] = "\n";
  const char str2[] = "";

  const char *expected = strpbrk(str1, str2);
  const char *actual = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(actual, expected);
}
END_TEST

// keely tests

START_TEST(s21_memset_test_1) {
  char test_1[10] = "012345";
  char test_2 = 'a';
  int test_3 = 3;

  ck_assert_pstr_eq(s21_memset(test_1, test_2, test_3),
                    memset(test_1, test_2, test_3));
}
END_TEST

START_TEST(s21_memset_test_2) {
  char test_1[10] = "abcdef";
  char test_2 = '!';
  int test_3 = 0;

  ck_assert_pstr_eq(s21_memset(test_1, test_2, test_3),
                    memset(test_1, test_2, test_3));
}
END_TEST

START_TEST(s21_memset_test_3) {
  char test_1[] = "";
  char test_2 = '!';
  int test_3 = 0;

  ck_assert_pstr_eq(s21_memset(test_1, test_2, test_3),
                    memset(test_1, test_2, test_3));
}
END_TEST

START_TEST(s21_memset_test_4) {
  char test_1[10] = "NULL";
  char test_2 = '!';
  int test_3 = 0;

  ck_assert_pstr_eq(s21_memset(test_1, test_2, test_3),
                    memset(test_1, test_2, test_3));
}
END_TEST

START_TEST(s21_strncat_test_1) {
  char test1[8192] = {'\0'};
  char test2[] = "12345";
  int test3 = 3;

  ck_assert_pstr_eq(s21_strncat(test1, test2, test3),
                    strncat(test1, test2, test3));
}
END_TEST

START_TEST(s21_strncat_test_2) {
  char test1[8192] = {'\0'};
  char test2[] = "12345";
  int test4 = 7;

  ck_assert_pstr_eq(s21_strncat(test1, test2, test4),
                    strncat(test1, test2, test4));
}
END_TEST

START_TEST(s21_strncat_test_3) {
  char test1[8192] = {'\0'};
  char test2[] = "12345";
  int test5 = -100;

  ck_assert_pstr_eq(s21_strncat(test1, test2, test5),
                    strncat(test1, test2, test5));
}
END_TEST

START_TEST(s21_strncat_test_4) {
  char test1[8192] = {'\0'};
  char test2[] = "12345";
  int test6 = 8193;

  ck_assert_pstr_eq(s21_strncat(test1, test2, test6),
                    strncat(test1, test2, test6));
}
END_TEST

START_TEST(s21_strncat_test_5) {
  char test7[8192] = {'f'};
  char test2[] = "12345";
  int test3 = 3;

  ck_assert_pstr_eq(s21_strncat(test7, test2, test3),
                    strncat(test7, test2, test3));
}
END_TEST

START_TEST(s21_strncat_test_6) {
  char test8[8192] = {"''"};
  char test2[] = "12345";
  int test4 = 7;

  ck_assert_pstr_eq(s21_strncat(test8, test2, test4),
                    strncat(test8, test2, test4));
}
END_TEST

START_TEST(s21_strncat_test_7) {
  char test9[8192] = "NUL~!@#$%d^&*()_+=-0?><M,./";
  char test2[] = "12345";
  int test5 = -100;

  ck_assert_pstr_eq(s21_strncat(test9, test2, test5),
                    strncat(test9, test2, test5));
}
END_TEST

START_TEST(s21_strncat_test_8) {
  char test9[8192] = "NUL~!@#$%d^&*()_+=-0?><M,./";
  char test10[] = "";
  int test6 = 8193;

  ck_assert_pstr_eq(s21_strncat(test9, test10, test6),
                    strncat(test9, test10, test6));
}
END_TEST

START_TEST(s21_strchr_test_1) {
  char test_1[] = "Hello, kitties!";
  char test_2 = 'o';
  char test_3 = 'a';

  ck_assert_pstr_eq(s21_strchr(test_1, test_2), strchr(test_1, test_2));
  ck_assert_pstr_eq(s21_strchr(test_1, test_3), strchr(test_1, test_3));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  char str[] = "hello";
  char c = 'x';

  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test_3) {
  char str[] = "";
  char c = 'a';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test_4) {
  char str[] = "hello";
  char c = ' ';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_insert_test_1) {
  char test_1[] = "I'm happy!";
  char test_2[] = "not so ";
  int test_3 = 4;
  char test_4[] = "I'm not so happy!";
  char *new_str = s21_insert(test_1, test_2, test_3);

  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
  new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_str_eq(new_str, test_4);
  free(new_str);
}
END_TEST

START_TEST(s21_insert_test_2) {
  char test_1[] = "";
  char test_2[] = "world";
  int test_3 = 0;
  char test_4[] = "world";
  char *new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
  new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char test_1[] = "Hello";
  char test_2[] = "";
  int test_3 = 5;
  char test_4[] = "Hello";
  char *new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
  new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
}

// Kir tests
START_TEST(s21_strcspn_test_1) {
  char str1[] = "hello123";
  char str2[] = "xxxxxxxx";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_2) {
  char str1[] = "$!##$*())";
  char str2[] = "*()";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_3) {
  char str1[] = "Hello, World!";
  char str2[] = "KHGFDDDCXFCGJ";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_4) {
  char str1[] = "Tsest";
  char str2[] = "67886534";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_5) {
  char str1[] = "";
  char str2[] = "";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_6) {
  char str1[] = "\n";
  char str2[] = "\n";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_7) {
  char str1[] = "    ";
  char str2[] = " ";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_8) {
  char str1[] = "hello123";
  char str2[] = "ello1";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_9) {
  char str1[] = "\n";
  char str2[] = "";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
START_TEST(s21_strcspn_test_10) {
  char str1[] = "1231231232131";
  char str2[] = "1232131";
  size_t expected = strcspn(str1, str2);
  size_t actual = s21_strcspn(str1, str2);
  ck_assert_int_eq(actual, expected);
}
END_TEST
// START_TEST(s21_strncpy_test_11) {
//   char src[] = "\n";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 1);
//   strncpy(exp, src, 1);
//   ck_assert_str_eq(res, exp);
// }
// END_TEST
// START_TEST(s21_strncpy_test_12) {
//   char src[] = "12312312";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 1);
//   strncpy(exp, src, 1);
//   ck_assert_str_eq(res, exp);
// }
// END_TEST
START_TEST(s21_strncpy_test_13) {
  char src[] = "123123131";
  char res[100];
  char exp[100];
  s21_strncpy(res, src, 10);
  strncpy(exp, src, 10);
  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(s21_strncpy_test_14) {
  char src[] = "";
  char res[100];
  char exp[100];
  s21_strncpy(res, src, 1);
  strncpy(exp, src, 1);
  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(s21_strncpy_test_15) {
  char src[] = "";
  char res[100];
  char exp[100];
  s21_strncpy(res, src, 10);
  strncpy(exp, src, 10);
  ck_assert_str_eq(res, exp);
}
END_TEST
// START_TEST(s21_strncpy_test_16) {
//   char src[] = "$!##$*())";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 5);
//   strncpy(exp, src, 5);
//   ck_assert_str_eq(res, exp);
// }
// END_TEST
// START_TEST(s21_strncpy_test_17) {
//   char src[] = "xxxx";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 4);
//   strncpy(exp, src, 4);
//   ck_assert_str_eq(res, exp);
// }
// END_TEST
// START_TEST(s21_strncpy_test_18) {
//   char src[] = "dasasdas";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 3);
//   strncpy(exp, src, 3);
//   ck_assert_str_eq(res, exp);
// }
// END_TEST
START_TEST(s21_strncpy_test_19) {
  char src[] = "\0";
  char res[100];
  char exp[100];
  s21_strncpy(res, src, 1);
  strncpy(exp, src, 1);
  ck_assert_str_eq(res, exp);
}
END_TEST
// START_TEST(s21_strncpy_test_20) {
//   char src[] = "   ";
//   char res[100];
//   char exp[100];
//   s21_strncpy(res, src, 3);
//   strncpy(exp, src, 3);
//   ck_assert_str_eq(res, exp);
// }
END_TEST
START_TEST(s21_strncmp_teset_21) {
  char str1[] = "ss";
  char str2[] = "ss";
  size_t n_byte = 2;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(s21_strncmp_teset_22) {
  char str1[] = "ss";
  char str2[] = "sxs";
  size_t n_byte = 2;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(s21_strncmp_teset_23) {
  char str1[] = "sxs";
  char str2[] = "ss";
  size_t n_byte = 2;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(s21_strncmp_teset_24) {
  char str1[] = "ss";
  char str2[] = "ss";
  size_t n_byte = 3;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(s21_strncmp_teset_25) {
  char str1[] = "sasds";
  char str2[] = "sasds";
  size_t n_byte = 5;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

///////////////////////////////////////////////////////////

START_TEST(s21_memset_test) {
  char test_1[10] = "012345";
  char test_2 = 'a';
  int test_3 = 3;

  ck_assert_pstr_eq(s21_memset(test_1, test_2, test_3),
                    memset(test_1, test_2, test_3));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test1[8192] = {'\0'};
  char test7[8192] = {'f'};
  char test8[8192] = {"''"};
  char test9[8192] = "NUL~!@#$%d^&*()_+=-0?><M,./";
  char test2[] = "12345";
  char test10[] = "";
  int test3 = 3;
  int test6 = 8193;
  int test4 = 7;
  int test5 = -100;

  ck_assert_pstr_eq(s21_strncat(test1, test2, test3),
                    strncat(test1, test2, test3));
  ck_assert_pstr_eq(s21_strncat(test1, test2, test4),
                    strncat(test1, test2, test4));
  ck_assert_pstr_eq(s21_strncat(test1, test2, test5),
                    strncat(test1, test2, test5));
  ck_assert_pstr_eq(s21_strncat(test1, test2, test6),
                    strncat(test1, test2, test6));
  ck_assert_pstr_eq(s21_strncat(test7, test2, test3),
                    strncat(test7, test2, test3));
  ck_assert_pstr_eq(s21_strncat(test8, test2, test4),
                    strncat(test8, test2, test4));
  ck_assert_pstr_eq(s21_strncat(test9, test2, test5),
                    strncat(test9, test2, test5));
  ck_assert_pstr_eq(s21_strncat(test9, test10, test6),
                    strncat(test9, test10, test6));
}
END_TEST

START_TEST(s21_strchr_test) {
  char test_1[] = "Hello, kitties!";
  char test_2 = 'o';
  char test_3 = 'a';

  ck_assert_pstr_eq(s21_strchr(test_1, test_2), strchr(test_1, test_2));
  ck_assert_pstr_eq(s21_strchr(test_1, test_3), strchr(test_1, test_3));
}
END_TEST

START_TEST(s21_insert_test) {
  char test_1[] = "I'm happy!";
  char test_2[] = "not so ";
  int test_3 = 4;
  char test_4[] = "I'm not so happy!";
  char *new_str = s21_insert(test_1, test_2, test_3);

  ck_assert_pstr_eq(new_str, test_4);
  free(new_str);
  new_str = s21_insert(test_1, test_2, test_3);
  ck_assert_str_eq(new_str, test_4);
  free(new_str);
}
END_TEST

START_TEST(s21_sprintf_test_c1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The char is %c";

  int test = 'w';
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
}
END_TEST

START_TEST(s21_sprintf_test_space_c1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The char is %c%c %c  % c";

  int test = 'w';
  s21_sprintf(buffer1, format, test, test, test, test);
  sprintf(buffer2, format, test, test, test, test);
}
END_TEST

START_TEST(s21_sprintf_test_c2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The char is %c";

  int test = 'w';
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);

  ck_assert_int_eq(s21_sprintf(buffer1, format, test),
                   sprintf(buffer2, format, test));
}
END_TEST

START_TEST(s21_sprintf_test_uc1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The char is %uc";

  unsigned char test = 177;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_space_d1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %d %d%d  % d";

//   int test = 149;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_plus_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_plus_d2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+d";

  int test = -149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %5d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-5d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %05d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.5d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*d";
  int accuracy = 5;
  int test = 149;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %*d";
  int width = 5;
  int test = 149;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_d1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.d";

  int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_hd1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %hd";

  short test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_ld1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %ld";

  long int test = 149;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_returned_value_d2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %d";

  int test = 149;
  ck_assert_int_eq(s21_sprintf(buffer1, format, test),
                   sprintf(buffer2, format, test));
}
END_TEST

START_TEST(s21_sprintf_test_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_plus_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_space_e1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %e%e %e  % e";

//   double test = 623456.0123;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_sharp_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %#e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %10e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-10e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %010e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.3e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*e";
  int accuracy = 3;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0star_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %0*e";
  int width = 10;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_e1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.e";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_he1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %he";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_Le1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %Le";

  long double test = 623456789.0123456;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_space_E1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %E%E %E  % E";

//   double test = 623456.0123;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_plus_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_sharp_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %#E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %*E";
  int width = 10;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %10E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-10E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %010E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.3E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*E";
  int accuracy = 3;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_E1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.E";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_hE1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %hE";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_LE1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %LE";

  long double test = 623456789.0123456;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_space_f1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %f%f %f  % f";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_plus_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_plus_f2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+f";

  float test = -623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_sharp_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %#f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %10f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-10f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %010f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %*f";
  int width = 10;
  double test = 623456.123;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.3f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*f";
  int accuracy = 3;
  float test = 623456.0123;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_f1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.f";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_Lf1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %Lf";

  long double test = 623456.123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_plus_Lf1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %+Lf";

  long double test = 623456.123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_returned_value_f2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %f";

  float test = 623456.0123;
  ck_assert_int_eq(s21_sprintf(buffer1, format, test),
                   sprintf(buffer2, format, test));
}
END_TEST

// START_TEST(s21_sprintf_test_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_space_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %g%g %g  % g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_sharp_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %#g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %10g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width_minus_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %-10g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width_0_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %010g";

//   double test = 623456.123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width_star_g1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %*g";
//   int width = 10;
//   double test = 623456.123;
//   s21_sprintf(buffer1, format, width, test);
//   sprintf(buffer2, format, width, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_accuracy_g1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.3g";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_g1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*g";
  int accuracy = 3;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_g1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0g";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_g1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.g";

  double test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_hg1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %hg";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_Lg1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %Lg";

//   long double test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_space_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %G%G %G  % G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_sharp_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %#G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_returned_value_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_int_eq(s21_sprintf(buffer1, format, test),
//                    sprintf(buffer2, format, test));
// }
// END_TEST

// START_TEST(s21_sprintf_test_width7_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %7G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width7_minus_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %-7G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width7_0_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %07G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width7_star_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %*G";
//   int width = 7;
//   double test = 623456.0123;
//   s21_sprintf(buffer1, format, width, test);
//   sprintf(buffer2, format, width, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width10_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %10G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width10_minus_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %-10G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width10_0_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %010G";

//   float test = 623456.0123;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_width10_star_G1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %*G";
//   int width = 10;
//   double test = 623456.0123;
//   s21_sprintf(buffer1, format, width, test);
//   sprintf(buffer2, format, width, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_accuracy_G1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.3G";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_G1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*G";
  int accuracy = 3;
  float test = 623456.0123;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_G1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0G";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_G1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.G";

  float test = 623456.0123;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %o";

  int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(s21_sprintf(buffer1, format, test),
                   sprintf(buffer2, format, test));
}
END_TEST

// START_TEST(s21_sprintf_test_space_o1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %o%o %o  % o";

//   int test = 12345678;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_plus_o1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %+o";

//   int test = 12345678;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
//   ck_assert_int_eq(s21_sprintf(buffer1, format, test),
//                    sprintf(buffer2, format, test));
// }
// END_TEST

// START_TEST(s21_sprintf_test_sharp_o1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %#o";

//   int test = 12345678;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_width_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %15o";

  int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-15o";

  int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %015o";

  int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %*o";
  int width = 15;
  int test = 12345678;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.5o";

  int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*o";
  int accuracy = 5;
  int test = 1234;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0o";

  int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_o1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.o";

  int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_ho1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %ho";

  short test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_lo1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %lo";

  long int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %s";

  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

START_TEST(s21_sprintf_test_space_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %s%s %s  % s";

  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, test, test, test, test);
  sprintf(buffer2, format, test, test, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %.4s";

  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %.*s";
  int accuracy = 4;
  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %.0s";

  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_s1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The line is %.s";

  char test[] = "Hello, men!";
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_ls1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The line is %ls";

//   char test[] = "Hello, men!";
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
//   // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f),
//   sprintf(buffer2,
//   // format_f, test_f));
// }
// END_TEST

START_TEST(s21_sprintf_test_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %u";

  unsigned int test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

// START_TEST(s21_sprintf_test_space_u1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %u%u %u  % u";

//   unsigned int test = 12345;
//   s21_sprintf(buffer1, format, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_plus_u1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %+u";

//   unsigned int test = 12345;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_width_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %7u";

  unsigned int test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %-7u";

  unsigned int test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %07u";

  unsigned int test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %*u";
  int width = 7;
  double test = 623456.0123;
  s21_sprintf(buffer1, format, width, test);
  sprintf(buffer2, format, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.5u";

  unsigned int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.*u";
  int accuracy = 5;
  unsigned int test = 1234;
  s21_sprintf(buffer1, format, accuracy, test);
  sprintf(buffer2, format, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.0u";

  unsigned int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_u1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %.u";

  unsigned int test = 1234;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_hu1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %hu";

  unsigned short test = 12345;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_lu1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %lu";

  unsigned long int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_plus_lu1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The value is %+lu";

//   unsigned long int test = 12345678;
//   s21_sprintf(buffer1, format, test);
//   sprintf(buffer2, format, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_llu1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The value is %llu";

  unsigned long long int test = 12345678;
  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format, test),
  //                  sprintf(buffer2, format, test));
}
END_TEST

// START_TEST(s21_sprintf_test_space_x1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The Hex code of %c is %x%x %x  % x";

//   char test = 'a';
//   s21_sprintf(buffer1, format, test, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_plus_x1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The Hex code of %c is %+x";

//   char test = 'a';
//   s21_sprintf(buffer1, format, test, test);
//   sprintf(buffer2, format, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_returned_value_x1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The Hex code of %d is %x";

//   int test = 123;
//   s21_sprintf(buffer1, format, test, test);
//   sprintf(buffer2, format, test, test);
//   // ck_assert_str_eq(buffer1, buffer2);
//   ck_assert_int_eq(s21_sprintf(buffer1, format, test),
//                    sprintf(buffer2, format, test));
// }
// END_TEST

// START_TEST(s21_sprintf_test_sharp_x1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The Hex code of %c is %#x";

//   char test = 'a';
//   s21_sprintf(buffer1, format, test, test);
//   sprintf(buffer2, format, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_width_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %7x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %-7x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %07x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %*x";
  int width = 7;
  char test = 'b';
  s21_sprintf(buffer1, format, test, width, test);
  sprintf(buffer2, format, test, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %.5x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %.*x";
  int accuracy = 5;
  char test = 'a';
  s21_sprintf(buffer1, format, test, accuracy, test);
  sprintf(buffer2, format, test, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %.0x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_x1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %.x";

  char test = 'a';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_x2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %d is %x";

  int test = 123456789;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// START_TEST(s21_sprintf_test_sharp_x2) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The Hex code of %d is %#x";

//   int test = 123456789;
//   s21_sprintf(buffer1, format, test, test);
//   sprintf(buffer2, format, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_width_x2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %d is %15x";

  int test = 123456789;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_x2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %d is %-15x";

  int test = 123456789;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_x2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %d is %015x";

  int test = 123456789;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_x2) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %d is %*x";
  int width = 15;
  int test = 123456789;
  s21_sprintf(buffer1, format, test, width, test);
  sprintf(buffer2, format, test, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_hx1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %hd is %hx";

  short test = 12345;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

START_TEST(s21_sprintf_test_lx1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %ld is %lx";

  long int test = 1234567890;
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

// START_TEST(s21_sprintf_test_space_X1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The code of %c is %X%X %X  % X";

//   char test = 'A';
//   s21_sprintf(buffer1, format, test, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_plus_X1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The code of %c is %+X";

//   char test = 'A';
//   s21_sprintf(buffer1, format, test, test);
//   sprintf(buffer2, format, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

START_TEST(s21_sprintf_test_sharp_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %7X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_minus_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %-7X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_0_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %07X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_width_star_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The Hex code of %c is %*X";
  int width = 7;
  char test = 'B';
  s21_sprintf(buffer1, format, test, width, test);
  sprintf(buffer2, format, test, width, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %.5X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_star_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %.*X";
  int accuracy = 5;
  char test = 'A';
  s21_sprintf(buffer1, format, test, accuracy, test);
  sprintf(buffer2, format, test, accuracy, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_0_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %.0X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_accuracy_dot_X1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The code of %c is %.X";

  char test = 'A';
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_sprintf_test_p1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "The address of %s is %p";

  char test[] = "12345678";
  s21_sprintf(buffer1, format, test, test);
  sprintf(buffer2, format, test, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

// START_TEST(s21_sprintf_test_space_p1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "The address of %s is %p%p %p  % p";

//   char test[] = "12345678";
//   s21_sprintf(buffer1, format, test, test, test, test, test);
//   sprintf(buffer2, format, test, test, test, test, test);
//   ck_assert_str_eq(buffer1, buffer2);
// }
// END_TEST

// START_TEST(s21_sprintf_test_n1) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "0123456789abcdef%n78901234567890";

//   int test1, test2;
//   s21_sprintf(buffer1, format, &test1);
//   sprintf(buffer2, format, &test2);
//   ck_assert_str_eq(buffer1, buffer2);
//   // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f),
//   sprintf(buffer2,
//   // format_f, test_f));
// }
// END_TEST

// START_TEST(s21_sprintf_test_n2) {
//   char buffer1[100];
//   char buffer2[100];
//   char format[] = "0123456789abcdef%n78901234567890";

//   int test1 = -1, test2 = 0;
//   s21_sprintf(buffer1, format, &test1);
//   sprintf(buffer2, format, &test2);
//   ck_assert_int_eq(test1, test2);
//   // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f),
//   sprintf(buffer2,
//   // format_f, test_f));
// }
// END_TEST

START_TEST(s21_sprintf_test_percent1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "0123456789abcdef%%%c78901234567890";

  char test = 'x';

  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
  // ck_assert_int_eq(s21_sprintf(buffer1, format_f, test_f), sprintf(buffer2,
  // format_f, test_f));
}
END_TEST

START_TEST(s21_sprintf_test_space_percent1) {
  char buffer1[100];
  char buffer2[100];
  char format[] = "0123456789abcdef%%%c %% % %   % c %   %78901234567890";

  char test = 'x';

  s21_sprintf(buffer1, format, test);
  sprintf(buffer2, format, test);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *tc1_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_trim_test);
  tcase_add_test(tc1_1, s21_strrchr_test_1);
  tcase_add_test(tc1_1, s21_strrchr_test_2);
  tcase_add_test(tc1_1, s21_strrchr_test_3);
  tcase_add_test(tc1_1, s21_strrchr_test_4);
  tcase_add_test(tc1_1, s21_strrchr_test_5);
  tcase_add_test(tc1_1, s21_strrchr_test_6);
  tcase_add_test(tc1_1, s21_strrchr_test_7);
  tcase_add_test(tc1_1, s21_strrchr_test_8);
  tcase_add_test(tc1_1, s21_strrchr_test_9);
  tcase_add_test(tc1_1, s21_strrchr_test_10);
  tcase_add_test(tc1_1, s21_strtok_test_1);
  tcase_add_test(tc1_1, s21_strtok_test_2);
  tcase_add_test(tc1_1, s21_strtok_test_3);
  tcase_add_test(tc1_1, s21_strtok_test_4);
  tcase_add_test(tc1_1, s21_strstr_test_1);
  tcase_add_test(tc1_1, s21_strstr_test_2);
  tcase_add_test(tc1_1, s21_strstr_test_3);
  tcase_add_test(tc1_1, s21_strstr_test_4);
  tcase_add_test(tc1_1, s21_strlen_test_1);
  tcase_add_test(tc1_1, s21_strlen_test_2);
  tcase_add_test(tc1_1, s21_strlen_test_3);
  tcase_add_test(tc1_1, s21_strlen_test_4);
  tcase_add_test(tc1_1, s21_strlen_test_5);
  tcase_add_test(tc1_1, s21_strlen_test_6);
  tcase_add_test(tc1_1, s21_strlen_test_7);
  tcase_add_test(tc1_1, s21_strlen_test_8);
  tcase_add_test(tc1_1, s21_strlen_test_9);
  tcase_add_test(tc1_1, s21_strlen_test_10);
  tcase_add_test(tc1_1, s21_strlen_test_11);
  tcase_add_test(tc1_1, s21_strlen_test_12);
  tcase_add_test(tc1_1, s21_strlen_test_13);
  tcase_add_test(tc1_1, s21_strlen_test_14);
  tcase_add_test(tc1_1, s21_strlen_test_15);
  tcase_add_test(tc1_1, s21_strerror_test_1);
  tcase_add_test(tc1_1, s21_strerror_test_2);
  tcase_add_test(tc1_1, s21_strpbrk_test_3);
  tcase_add_test(tc1_1, s21_strpbrk_test_4);
  tcase_add_test(tc1_1, s21_strpbrk_test_5);
  tcase_add_test(tc1_1, s21_strpbrk_test_6);
  tcase_add_test(tc1_1, s21_strpbrk_test_7);
  tcase_add_test(tc1_1, s21_strpbrk_test_9);
  tcase_add_test(tc1_1, s21_strpbrk_test_10);
  tcase_add_test(tc1_1, s21_strpbrk_test_11);
  tcase_add_test(tc1_1, s21_strpbrk_test_12);
  tcase_add_test(tc1_1, s21_strpbrk_test_13);
  tcase_add_test(tc1_1, s21_strpbrk_test_14);
  tcase_add_test(tc1_1, s21_strpbrk_test_15);
  tcase_add_test(tc1_1, s21_memset_test_1);
  tcase_add_test(tc1_1, s21_memset_test_2);
  tcase_add_test(tc1_1, s21_memset_test_3);
  tcase_add_test(tc1_1, s21_memset_test_4);
  tcase_add_test(tc1_1, s21_strncat_test_1);
  tcase_add_test(tc1_1, s21_strncat_test_2);
  tcase_add_test(tc1_1, s21_strncat_test_3);
  tcase_add_test(tc1_1, s21_strncat_test_4);
  tcase_add_test(tc1_1, s21_strncat_test_5);
  tcase_add_test(tc1_1, s21_strncat_test_6);
  tcase_add_test(tc1_1, s21_strncat_test_7);
  tcase_add_test(tc1_1, s21_strncat_test_8);
  tcase_add_test(tc1_1, s21_strchr_test_1);
  tcase_add_test(tc1_1, s21_strchr_test_2);
  tcase_add_test(tc1_1, s21_strchr_test_3);
  tcase_add_test(tc1_1, s21_strchr_test_4);
  tcase_add_test(tc1_1, s21_insert_test_1);
  tcase_add_test(tc1_1, s21_insert_test_2);
  tcase_add_test(tc1_1, s21_insert_test_3);
  tcase_add_test(tc1_1, s21_strcspn_test_1);
  tcase_add_test(tc1_1, s21_strcspn_test_2);
  tcase_add_test(tc1_1, s21_strcspn_test_3);
  tcase_add_test(tc1_1, s21_strcspn_test_4);
  tcase_add_test(tc1_1, s21_strcspn_test_5);
  tcase_add_test(tc1_1, s21_strcspn_test_6);
  tcase_add_test(tc1_1, s21_strcspn_test_7);
  tcase_add_test(tc1_1, s21_strcspn_test_8);
  tcase_add_test(tc1_1, s21_strcspn_test_9);
  tcase_add_test(tc1_1, s21_strcspn_test_10);
  // tcase_add_test(tc1_1, s21_strncpy_test_11);
  // tcase_add_test(tc1_1, s21_strncpy_test_12);
  tcase_add_test(tc1_1, s21_strncpy_test_13);
  tcase_add_test(tc1_1, s21_strncpy_test_14);
  tcase_add_test(tc1_1, s21_strncpy_test_15);
  // tcase_add_test(tc1_1, s21_strncpy_test_16);
  // tcase_add_test(tc1_1, s21_strncpy_test_17);
  // tcase_add_test(tc1_1, s21_strncpy_test_18);
  tcase_add_test(tc1_1, s21_strncpy_test_19);
  // tcase_add_test(tc1_1, s21_strncpy_test_20);
  tcase_add_test(tc1_1, s21_strncmp_teset_21);
  tcase_add_test(tc1_1, s21_strncmp_teset_22);
  tcase_add_test(tc1_1, s21_strncmp_teset_23);
  tcase_add_test(tc1_1, s21_strncmp_teset_24);
  tcase_add_test(tc1_1, s21_strncmp_teset_25);

  /////////////////////////////////////////////////

  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_sprintf_test_c1);
  tcase_add_test(tc1_1, s21_sprintf_test_space_c1);
  tcase_add_test(tc1_1, s21_sprintf_test_c2);
  tcase_add_test(tc1_1, s21_sprintf_test_uc1);
  tcase_add_test(tc1_1, s21_sprintf_test_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_d2);
  tcase_add_test(tc1_1, s21_sprintf_test_width_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_d1);
  tcase_add_test(tc1_1, s21_sprintf_test_hd1);
  tcase_add_test(tc1_1, s21_sprintf_test_ld1);
  tcase_add_test(tc1_1, s21_sprintf_test_returned_value_d2);
  tcase_add_test(tc1_1, s21_sprintf_test_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_sharp_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0star_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_e1);
  tcase_add_test(tc1_1, s21_sprintf_test_he1);
  tcase_add_test(tc1_1, s21_sprintf_test_Le1);
  tcase_add_test(tc1_1, s21_sprintf_test_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_sharp_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_E1);
  tcase_add_test(tc1_1, s21_sprintf_test_hE1);
  tcase_add_test(tc1_1, s21_sprintf_test_LE1);
  tcase_add_test(tc1_1, s21_sprintf_test_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_f2);
  tcase_add_test(tc1_1, s21_sprintf_test_sharp_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_f1);
  tcase_add_test(tc1_1, s21_sprintf_test_Lf1);
  tcase_add_test(tc1_1, s21_sprintf_test_plus_Lf1);
  tcase_add_test(tc1_1, s21_sprintf_test_returned_value_f2);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_g1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_g1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_g1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_g1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_G1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_G1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_G1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_G1);
  tcase_add_test(tc1_1, s21_sprintf_test_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_o1);
  tcase_add_test(tc1_1, s21_sprintf_test_ho1);
  tcase_add_test(tc1_1, s21_sprintf_test_lo1);
  tcase_add_test(tc1_1, s21_sprintf_test_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_space_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_s1);
  tcase_add_test(tc1_1, s21_sprintf_test_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_u1);
  tcase_add_test(tc1_1, s21_sprintf_test_hu1);
  tcase_add_test(tc1_1, s21_sprintf_test_lu1);
  tcase_add_test(tc1_1, s21_sprintf_test_llu1);
  tcase_add_test(tc1_1, s21_sprintf_test_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_x1);
  tcase_add_test(tc1_1, s21_sprintf_test_x2);
  tcase_add_test(tc1_1, s21_sprintf_test_width_x2);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_x2);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_x2);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_x2);
  tcase_add_test(tc1_1, s21_sprintf_test_hx1);
  tcase_add_test(tc1_1, s21_sprintf_test_lx1);
  tcase_add_test(tc1_1, s21_sprintf_test_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_sharp_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_minus_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_star_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_width_0_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_star_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_0_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_accuracy_dot_X1);
  tcase_add_test(tc1_1, s21_sprintf_test_p1);
  tcase_add_test(tc1_1, s21_sprintf_test_percent1);
  tcase_add_test(tc1_1, s21_sprintf_test_space_percent1);

  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
