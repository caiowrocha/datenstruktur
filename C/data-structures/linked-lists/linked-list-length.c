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

Node *addNode(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
};

int listLength(Node *head) {
    int counter = 0;
    while(head != NULL) {
        counter++;
        head = head->next;
    };
    return counter;
};

int main(void) {

    Node *list = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        list = addNode(list, value);
        i++;
    };

    int size = listLength(list);

    printf("%d", size);

    return 0;
};