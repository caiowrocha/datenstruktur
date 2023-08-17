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

int main(void) {

    Node *list = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        list = addNode(list, value);
    };

    displayLinkedList(list);

    return 0;
};