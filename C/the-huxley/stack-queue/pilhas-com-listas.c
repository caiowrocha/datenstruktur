#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
  char value[5000];
  struct Node* next;
} Node;

typedef struct Stack {
  struct Node *top;
} Stack;

void *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

int printNode(Stack *stack) {
  Node *temp = stack->top;
  if(temp != NULL) {
    printf("%s\n", temp->value);
    return 0;
  }
  printf("EMPTY STACK\n");
  return 1;
};

void pop(Stack *stack) {
  Node *temp = stack->top->next;
  free(stack->top);
  stack->top = temp;
};

void push(Stack *stack, char value[]) {
  Node *newNode = (Stack *)malloc(sizeof(Node));
  strcpy(newNode->value, value);
  newNode->next = stack->top;
  stack->top = newNode;
}

int main()
{
	Stack *stack = createStack();

	char whatToDo[5];
	char value[5000];

	while(scanf("%[^\n]", whatToDo) != EOF)
	{
		getchar();
		if(strcmp(whatToDo, "POP") == 0)
		{
			if(printNode(stack) != 1)
			{
			    pop(stack);   
			}
		}
		else if(strcmp(whatToDo, "PUSH") == 0)
		{
			scanf("%[^\n]", value);
			getchar();

			push(stack, value);
		}
	}
	return 0;
}