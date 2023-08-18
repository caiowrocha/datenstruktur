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

int linkedListIsSubset(Node *firstList, int firstSize, Node *secondList, int secondSize) {
    if(secondSize >= firstSize) {
        return 0;
    }
    while(secondList != NULL) {
        if(searchLinkedList(firstList, secondList->value) != NULL) {
            secondList = secondList->next;
        };
        return 0;
    };
    return 1;
};

int main(void) {

    Node *first = createLinkedList();

    Node *second = createLinkedList();

    int i;
    while(i != 6) {
        int value;
        scanf("%d", &value);
        first = addNode(first, value);
        i++;
    };

    int j;
    while(j != 6) {
        int value;
        scanf("%d", &value);
        second  = addNode(first, value);
        j++;
    };

    int isSubset = linkedListIsSubset(first, 6,  second, 6);

    printf("%d", isSubset);

    return 0;
};