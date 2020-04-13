/*
 * wunzip.c --- This program uncompresses files using the
 *              run-length encoding (RLE) algorithm.
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *fs = fopen(argv[i], "r");

    if (fs == NULL) {
      printf("wzip: cannot open file\n");
      exit(1);
    }

    int count;
    char cur;

    while (((int) fread(&count, sizeof (int), 1, fs)) > 0) {
      fread(&cur, sizeof (char), 1, fs);

      for (int j = 0; j < count; j++) {
        printf("%c", cur);
      }
    }

    fclose(fs);
  }

  return 0;
}
