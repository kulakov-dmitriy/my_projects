#include <stdio.h>

struct opt {
  int b;
  int e;
  int v;
  int E;
  int n;
  int s;
  int t;
  int T;
  int count;
  int count_file;
  int flag;
  int err;
  char lastCh;
};

void opt_v(unsigned char* buffer, int lenBuff, int flag);
int searchOptions(int argc, char** argv, struct opt* options);
void printText(struct opt* options, FILE* openFile);