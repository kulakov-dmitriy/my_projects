#include <stdio.h>

struct opt {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int count_file;
  int err;
  char paternF[1000];
  char *name_file;
  char argE[100];
  char template[1000];
};

int searchOptions(int argc, char **argv, struct opt *options);
void printText(struct opt options, FILE *openFile);
void flag_f(char *nameF, struct opt *options);
int writeTemp(char **argv, struct opt *options);
void flag_c_h(struct opt options, int countC);