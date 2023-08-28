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

int isEmptyStack(Stack *stack) {
    if(stack->currentSize == 0) {
      return 1;
    }
    return 0;
};

int peekStack(Stack *stack) {
  if(isEmptyStack(stack)) {
    printf("Stack Underflow");
    return -1;
  } else {
    return stack->item[stack->currentSize-1];
  };
}


int main (void) {
  
  Stack *stack = createStack();

  stackPush(stack, -200);
  stackPush(stack, -100);
  stackPush(stack, 100);
  stackPush(stack, 200);
  stackPush(stack, 300);
  stackPush(stack, 400);

  int peek = peekStack(stack);
  
  printf("%d\n", peek);
  
  return 0;
};