#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100


typedef struct Stack {
    int currentSize;
    int item[MAX_STACK_SIZE];
} Stack;

Stack *createStack() {
  Stack *newStack = (Stack *)malloc(sizeof(Stack));
  newStack->currentSize = 0;
  return newStack;
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

int stackPop(Stack *stack) {
    if(isEmptyStack(stack)) {
      printf("Stack underflow");
      return -1;
    } else {
      return stack->item[--stack->currentSize];
    };
}

void stackPush(Stack *stack, int item) {
    if(stack->currentSize == MAX_STACK_SIZE) {
      printf("Stack Overflow");
      return;
    }
    stack->item[stack->currentSize++] = item;
}


int main() {

  Stack *stack = createStack();

  stackPush(stack, 10);
  stackPush(stack, 20);
  stackPush(stack, 30);
  stackPush(stack, 40);
  stackPush(stack, 50);
  stackPush(stack, 60);

  printf("Before Pop\n");

  displayStack(stack);

  stackPop(stack);
  stackPop(stack);
  stackPop(stack);
  
   printf("\nAfter Pop\n");
  displayStack(stack);

  return 0;
}