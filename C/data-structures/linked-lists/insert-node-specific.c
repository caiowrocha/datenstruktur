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

void insertNode(int position, int value, Node **head) {
    int size = listLength(*head);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if(position < 0 || position > size) {
        printf("Invalid Position");
    } else if(position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;

        while(--position) {
            temp = temp->next;
        };
        newNode->next = temp->next;
        temp->next = newNode;
    };
};

int main(void) {

    Node *list = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        insertNode(0, value, &list);
    };

    displayLinkedList(list);

    return 0;
};

