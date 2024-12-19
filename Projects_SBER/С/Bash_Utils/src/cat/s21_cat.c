#include "s21_cat.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  struct opt options = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '\n'};
  int optind = searchOptions(argc, argv, &options);
  if (!options.err && optind < argc) {
    while (optind < argc) {
      FILE* openFile = fopen(argv[optind++], "r");
      if (openFile != NULL) {
        printText(&options, openFile);
      } else {
        printf("cat: %s: No such file or directory\n", argv[optind - 1]);
      }
      fclose(openFile);
    }
  }
  return 0;
}

int searchOptions(int argc, char** argv, struct opt* options) {
  int c;
  while (1) {
    int option_index = 0;
    static struct option long_options[] = {{"number", 0, 0, 'n'},
                                           {"number-nonblank", 0, 0, 'b'},
                                           {"squeeze-blank", 0, 0, 's'},
                                           {0, 0, 0, 0}};
    c = getopt_long(argc, argv, "bevEnstT", long_options, &option_index);
    if (c == -1) break;
    switch (c) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'E':
        options->E = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        break;
      case 'T':
        options->T = 1;
        break;
      default:
        options->err = 1;
    }
  }
  if (options->b && options->n) {
    options->n = 0;
  }
  return optind;
}

void printText(struct opt* options, FILE* openFile) {
  int c;
  while ((c = getc(openFile)) != EOF) {
    if (options->b) {
      if (options->lastCh == '\n' && c != '\n') {
        printf("%6d\t", ++options->count);
      }
    }
    if (options->s) {
      if (c == '\n' && options->lastCh == '\n') {
        options->flag++;
      } else {
        options->flag = 0;
      }
      if (options->flag > 1) {
        continue;
      }
    }
    if (options->n && options->lastCh == '\n') {
      printf("%6d\t", ++options->count);
    }
    if ((options->e || options->E) && c == '\n') {
      printf("$");
    }
    if ((options->T || options->t) && c == '\t') {
      printf("^I");
      continue;
    }
    if ((options->t || options->v || options->e) && c != '\t' && c != '\n') {
      if (c >= 128) {
        c -= 128;
        printf("M-");
      }
      if ((c < 32 || c == 127)) {
        c ^= 0x40;
        printf("^");
      }
    }
    printf("%c", c);
    options->lastCh = c;
  }
}