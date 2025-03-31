#include <stdio.h>
#include <stdlib.h>

extern void push(int);
extern int pop();
extern int isEmpty();
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();

void printHeapXML(int index) {
  extern int heapGet(int);
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (index >= heapSize()) return;

  printf("<node id=\"%d\">", heapGet(index));
  if (left < heapSize()) printHeapXML(left);
  if (right < heapSize()) printHeapXML(right);
  printf("</node>");
}

int main() {
  int val;
  while (scanf("%d", &val) == 1) {
    addHeap(val);
  }

  printHeapXML(0);
  printf("\n");

  while (heapSize() > 0) {
    int max = heapDelete();
    printf("%d\n", max);
    push(max);
  }

  while (!isEmpty()) {
    printf("%d\n", pop());
  }

  return 0;
}

