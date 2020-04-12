#include <stdio.h>
#include <stdlib.h>

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
        fwrite(&count, sizeof (int), 1, stdout);
        fwrite(&prev, sizeof (char), 1, stdout);
        count = 1;
        prev = cur;
      }
    }

    fclose(fs);
  }

  fwrite(&count, sizeof (int), 1, stdout);
  fwrite(&prev, sizeof (char), 1, stdout);

  return 0;
}
