#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(char *search_term, FILE *fs);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }

  if (argc < 3) {
    search_file(argv[1], stdin);
  } else {
    for (int i = 2; i < argc; i++) {
      FILE *fs = fopen(argv[i], "r");

      if (fs == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
      }

      search_file(argv[1], fs);

      fclose(fs);
    }
  }
  
  return 0;
}

void search_file(char *search_term, FILE *fs) {
  char *buf = NULL;
  size_t buf_size = 0;

  while (getline(&buf, &buf_size, fs) != -1) {
    if (strstr(buf, search_term) != NULL) {
      printf("%s", buf);
    }
  }

  free(buf);
}

