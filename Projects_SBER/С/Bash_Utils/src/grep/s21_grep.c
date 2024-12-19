#include "s21_grep.h"

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  struct opt options = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", "", ""};
  if (argc - (optind = searchOptions(argc, argv, &options)) > 1)
    options.count_file++;
  if (!options.err && optind < argc) {
    while (optind < argc) {
      if (options.v && options.o) {
        break;
      }
      FILE *openFile = fopen(argv[optind++], "r");
      if (openFile != NULL) {
        options.name_file = argv[optind - 1];
        printText(options, openFile);
        fclose(openFile);
      } else {
        if (!options.s) {
          printf("grep: %s: No such file or directory\n", argv[optind - 1]);
        }
      }
    }
  }
  return 0;
}

int searchOptions(int argc, char **argv, struct opt *options) {
  int c;
  while (1) {
    c = getopt(argc, argv, "e:ivclnhsf:o");
    if (c == -1) break;
    switch (c) {
      case 'e':
        options->e = 1;
        strcat(options->argE, optarg++);
        strcat(options->argE, "|");
        break;
      case 'i':
        options->i = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        options->f = 1;
        flag_f(optarg, options);
        break;
      case 'o':
        options->o = 1;
        break;
      default:
        options->err = 1;
    }
  }
  int wt = writeTemp(argv, options);
  return wt;
}

int writeTemp(char **argv, struct opt *options) {
  if (!options->e && !options->f) {
    strcat(options->template, argv[optind++]);
  } else {
    if (options->e) {
      if (options->f) {
        strcat(options->template, "|");
      }
      options->argE[strlen(options->argE) - 1] = '\0';
      strcat(options->template, options->argE);
    }
  }
  return optind;
}

void flag_f(char *nameF, struct opt *options) {
  if (options->e) {
    strcat(options->template, "|");
  }
  char c;
  int count = 0;
  FILE *opFile = fopen(nameF, "r");
  if (opFile != NULL) {
    while ((c = getc(opFile)) != EOF) {
      if (c == '\n') {
        c = '|';
      }
      options->paternF[count++] = c;
    }
    fclose(opFile);
  }
  options->paternF[count - 1] = '\0';
  strcat(options->template, options->paternF);
}

void printText(struct opt options, FILE *openFile) {
  regex_t re;
  int countC = 0, countN = 0, cflag = REG_EXTENDED, rx;
  char buffer[10000];
  while (fgets(buffer, sizeof(buffer), openFile) != NULL) {
    countN++;
    if (buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer) - 1] = '\0';
    if (options.i) {
      cflag |= REG_ICASE;
    }
    if (regcomp(&re, options.template, cflag)) {
      if (!options.s) {
        printf("grep: Unmatched [, [^, [:, [., or [=\n");
      }
      regfree(&re);
      break;
    }
    rx = regexec(&re, buffer, 0, 0, 0);
    regfree(&re);
    if ((rx == 0 && !options.v) || (rx == 1 && options.v)) {
      if (options.c && !options.l) {
        countC++;
      } else {
        if (options.l) {
          printf("%s\n", options.name_file);
          break;
        }
        if (options.count_file && !options.h) {
          printf("%s:", options.name_file);
        }
        if (options.n) {
          printf("%d:", countN);
        }
        if (options.o) {
          printf("%s\n", options.template);
        } else {
          printf("%s\n", buffer);
        }
      }
    }
  }
  flag_c_h(options, countC);
}

void flag_c_h(struct opt options, int countC) {
  if (options.c && !options.l) {
    if (options.count_file) {
      if (options.h) {
        printf("%d\n", countC);
      } else {
        printf("%s:%d\n", options.name_file, countC);
      }
    } else {
      printf("%d\n", countC);
    }
  }
}