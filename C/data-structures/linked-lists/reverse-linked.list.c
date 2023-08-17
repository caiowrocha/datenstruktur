#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createLinkedList() {
    return NULL;
};

void displayLinkedList(Node *head) {
    while(head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    };
};

Node *addNode(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
};

void reverseLinkedList(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    if(head == NULL || head->next == NULL) {
    return head;
    }

    while(curr != NULL) {
 	next = curr->next;
  	curr->next = prev;
  	prev = curr;
  	curr = next;
    };
    head = prev;
};



int main(void) {

    Node *list = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        list = addNode(list, value);
    };
    
    displayLinkedList(list);
    reverseLinkedList(list);
    displayLinkedList(list);

    return 0;
};