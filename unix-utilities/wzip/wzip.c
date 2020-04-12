/*
 * wzip.c --- This program compresses files using the
 *            run-length encoding (RLE) algorithm.
 */

#include <stdio.h>
#include <stdlib.h>

void write_compressed(int *count, char *character);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

  int count = 0;
  char prev;
  char cur;

  for (int i = 1; i < argc; i++) {
    FILE *fs = fopen(argv[i], "r");

    if (fs == NULL) {
      printf("wzip: cannot open file\n");
      exit(1);
    }

    while ((cur = (char) fgetc(fs)) > 0) {
      if (prev == cur) {
        count++;
      } else if (count == 0) {
        count++;
        prev = cur;
      } else {
        write_compressed(&count, &prev);
        count = 1;
        prev = cur;
      }
    }
    fclose(fs);
  }

  write_compressed(&count, &prev);

  return 0;
}

void write_compressed(int *count, char *character) {
  fwrite(count, sizeof (int), 1, stdout);
  fwrite(character, sizeof (char), 1, stdout);
}
