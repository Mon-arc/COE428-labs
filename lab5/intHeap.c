#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

#define HEAP_SIZE 100

static int heap[HEAP_SIZE];
static int size = 0;

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  if (size == 0) return -1;
  int maxVal = heap[0];
  heap[0] = heap[--size];
  heapifyDown(0);
  return maxVal;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (heap[index] > heap[parent]) {
      swap(&heap[index], &heap[parent]);
      index = parent;
    } else break;
  }
}

void heapifyDown(int index) {
  while (2 * index + 1 < size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != index) {
      swap(&heap[index], &heap[largest]);
      index = largest;
    } else break;
  }
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
if (size < HEAP_SIZE) {
    heap[size] = thing2add;
    heapifyUp(size);
    size++;
	}
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
	return size;
}

// Helper (getter) function so I can use it in part2Main.c
int heapGet(int index) {
  if (index >= 0 && index < size) {
    return heap[index];
  }
  return -1;
}

