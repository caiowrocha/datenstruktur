#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE_STACK 100

typedef struct Stack {
  int currentSize;
  int item[MAX_SIZE_STACK];
} Stack;

Stack *createStack() {
  Stack *newStack = (Stack *)malloc(sizeof(Stack));
  newStack->currentSize = 0;
  return newStack;
};

void stackPush(Stack *stack, int item) {
    if(stack->currentSize == MAX_SIZE_STACK) {
      printf("Stack Overflow");
    } else {
      stack->item[stack->currentSize++] = item;
    };
};

void displayStack(Stack *stack) {
   int i;
   for(i = stack->currentSize - 1; i >= 0; i--) {
       printf("%d ", stack->item[i]);
       printf("\n");
  };
};

int main (void) {
  
  Stack *stack = createStack();

  stackPush(stack, 10);
  stackPush(stack, 10);
  stackPush(stack, 10);
  stackPush(stack, 10);
  stackPush(stack, 10);
  stackPush(stack, 100);

  displayStack(stack);
  
  return 0;
};