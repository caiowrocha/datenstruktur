#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack {
  int currentSize;
  int items[MAX_STACK_SIZE];
} Stack;

Stack *createStack() {
  Stack *newStack = (Stack *)malloc(sizeof(Stack));
  newStack->currentSize = 0;
  return newStack;
};

int main (void) {
  Stack *stack = createStack();
  return 0;
};
