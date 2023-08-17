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

Node *searchLinkedList(Node *head, void *value) {
    while(head != NULL) {
        if(head->value == value) {
            return head;
        };
        head = head->next;
    };
    return NULL;
};

int listLength(Node *head) {
    int counter = 0;
    while(head != NULL) {
        counter++;
        head = head->next;
    };
    return counter;
};

void insertNode(int position, int value, Node **head) {
    int size = listLength(*head);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if(position < 0 || position > size) {
        return;
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


int linkedListIsSubset(Node *firstList, int firstSize, Node *secondList, int secondSize) {
    if(secondSize >= firstSize) {
        return 0;
    }
    while(secondList != NULL) {
        if(searchLinkedList(firstList, secondList->value) == NULL) {
            return 0;
        };
        secondList = secondList->next;
    };
    return 1;
};

int main(void) {

    Node *firstList = createLinkedList();
    Node *secondList = createLinkedList();

    int firstSize = 0
    ,   secondSize = 0
    , i = 0;

    scanf("%d", &firstSize);

        while(i < firstSize) {
        int value;
        scanf("%d", &value);
        insertNode(0, value, &firstList);
        i++;
    };


    scanf("%d", &secondSize);
        while(i < secondSize) {
        int value;
        scanf("%d", &value);
        insertNode(0, value, &secondList);
        i++;
    };

    linkedListIsSubset(firstList, firstSize, secondList, secondSize) == 1 ? printf("1\n") : printf("0\n");

    return 0;
}