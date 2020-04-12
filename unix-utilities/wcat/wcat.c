#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 200

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }

  char *buf = malloc(BUFSIZE); 
  if (buf == NULL) {
    fprintf(stderr, "wcat: failed to allocate memory\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");

    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
      printf("%s", buf);
    }

    fclose(fp);
  }

  free(buf);

  return 0;
}
