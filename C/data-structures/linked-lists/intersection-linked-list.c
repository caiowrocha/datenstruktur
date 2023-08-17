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

struct Node* intersectionLinkedList(Node *firstList, Node *secondList) {
    Node *result = (Node *)malloc(sizeof(Node));
    while(firstList != NULL){
    if(!searchLinkedList(secondList, firstList->value)){
        result = addNode(result, firstList->value);
    };
    firstList = firstList->next;
    };
    return result;
}

int main(void) {

    Node *first = createLinkedList();

    Node *second = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        first = addNode(first, value);
    };

    int j;
    while(j != 6) {
        int value;
        scanf("%d", &value);
        second  = addNode(first, value);
    };

    Node *intersection = intersectionLinkedList(first, second);

    displayLinkedList(intersection);

    return 0;
};