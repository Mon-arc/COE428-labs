#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *pop();
extern void push(char *);
extern int isEmpty();

#define MAX_TAG_LENGTH 100

int readTag(char *buffer) {
  int ch, i = 0;
  while ((ch = getchar()) != EOF && ch != '>') {
    if (i < MAX_TAG_LENGTH - 1) buffer[i++] = ch;
  }
  buffer[i] = '\0';
  return (ch == EOF) ? 0 : 1;
}

int main(int argc, char *argv[]) {
  int ch;
  char tag[MAX_TAG_LENGTH];

  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;

    if (ch == '<') {
      if (!readTag(tag)) {
        printf("Invalid XML\n");
        exit(1);
      }

      if (tag[0] == '/') {
        char *startTag = pop();
        if (startTag == NULL || strcmp(startTag, tag + 1) != 0) {
          printf("Invalid XML\n");
          free(startTag);
          exit(1);
        }
        free(startTag);
      } else {
        push(tag);
      }
    }
  }

  if (isEmpty()) {
    printf("Valid XML\n");
  } else {
    printf("Invalid XML\n");
  }
  exit(0);
}

