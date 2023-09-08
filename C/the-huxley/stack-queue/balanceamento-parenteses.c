#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct Stack {
    char value;
    struct Stack *next;
} Stack;

Stack *createStack() {
    return NULL;
};

void removeSpaces(char *string) {
    char *temp = string;
    do {
        while (*temp == ' ') {
            ++temp;
        }
    } while (*string = *temp++);
};

Stack *push(Stack *top, char value) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    newNode->value = value;
    newNode->next = top;
    return newNode;
};

Stack *pop(Stack *top) {
    if(top == NULL) {
        return NULL;
    };
    Stack *temp = top;
    top = top->next;
    free(temp);
    return top;
};

int isBalanced(char *exp) {
    Stack *stack = createStack();
    int size = strlen(exp);
    
    for(int i = 0; i < size; i++) {
        if(exp[i] == '(' || exp[i] == '[') {
            stack = push(stack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']') {
            if(stack == NULL) {
                return 0;
            }
            char top = stack->value;
            stack = pop(stack);
            if ((exp[i] == ')' && top != '(') || (exp[i] == ']' && top != '[')) {
                return 0; 
            }
        }
    }
    
    if(stack == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    
    int strAmount;
    scanf("%d", &strAmount);
    getchar();
    
    for(int i = 0; i < strAmount; i++) {
        char exp[256];
        fgets(exp, sizeof(exp), stdin);
        exp[strcspn(exp, "\n")] = '\0';
        
        char cleanExp[256];
        int j = 0;
        for(int k = 0; exp[k] != '\0'; k++) {
            if(exp[k] != ' ') {
                cleanExp[j++] = exp[k];
            }
        }
        cleanExp[j] = '\0';
        
        if (isBalanced(cleanExp)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

	return 0;
}