#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }

  char *buf = NULL;
  size_t buf_size = 0;

  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");

    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    while (getline(&buf, &buf_size, fp) != -1) {
      printf("%s", buf);
    }

    fclose(fp);
  }

  free(buf);

  return 0;
}
