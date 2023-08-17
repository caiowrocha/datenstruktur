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

int linearSearchList(Node *head, int value) {
    while(head != NULL) {
        if(head->value == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
};

int main(void) {

    Node *list = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        list = addNode(list, value);
    };

    int search = linearSearchList(list, 2);

    printf("%d", search);

    return 0;
};