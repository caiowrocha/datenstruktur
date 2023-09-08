#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_EVENTS 100

typedef struct Event {
    char event[10];
} Event;


typedef struct Stack {
    struct Event events[MAX_EVENTS];
    int top;
} Stack;


void stackInitialize(Stack *stack) {
    stack->top = -1;
};

void push(Stack *stack, const char *event) {
   if(stack->top < MAX_EVENTS - 1) {
       strcpy(stack->events[++stack->top].event, event);
   };
};



int main() {
    
    char event[10];
    
    int bCounter = 0,
        fCounter = 0;
    
    
    Stack b;
    stackInitialize(&b);
    Stack f;
    stackInitialize(&f);
    
    while(scanf("%s", event) != EOF) {
        if(strcmp(event, "ENTER") == 0) {
            while(f.top >= 0) {
                push(&b, f.events[f.top--].event);
            }
            if(fCounter > 0) {
              fCounter--;
            }
            // if(fCounter <= 0) {
            //   bCounter++;
            // } 
            bCounter++;
            push(&b, "ENTER");
            f.top = -1;
            } else if (strcmp(event, "BACK") == 0) {
            if (b.top >= 0 && strcmp(b.events[b.top].event, "ENTER") == 0) {
                push(&f, b.events[b.top--].event);
                if(bCounter >= 1) {
                  bCounter--;
                }
                fCounter++;
            }
        } else if (strcmp(event, "FORWARD") == 0) {
            if (f.top >= 0) {
                push(&b, f.events[f.top--].event);
            if(fCounter >= 0) {
                bCounter++;
            }
            if(bCounter >= 0) {
              fCounter--;
            }
            }
        }
    }

    printf("BACK: %d\n", bCounter - 1);
    printf("FORWARD: %d\n", fCounter);

    return 0;
}
