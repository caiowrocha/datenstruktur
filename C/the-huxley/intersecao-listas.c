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

Node* swap(struct Node* first, struct Node* second)
{
    struct Node* tmp = second->next;
    second->next = first;
    first->next = tmp;
    return second;
};

int bubbleSort(Node **head, int count)
{
    Node **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++) {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {

            Node* first = *h;
            Node* second = first->next;

            if (first->value > second->value) {

                *h = swap(first, second);
                swapped = 1;
            }

            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
}

Node *addNode(Node *head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = head;
    return newNode;
};

void displayLinkedList(Node *head) {
    while(head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    };
};

int listLength(Node *head) {
    int counter = 0;
    while(head != NULL) {
        counter++;
        head = head->next;
    };
    return counter;
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


Node  *intersectionList(Node *firstList, Node *secondList) {
    Node *intersectionList = createLinkedList();
    while(firstList != NULL){
        if(linearSearchList(secondList, firstList->value)){

            if(!linearSearchList(intersectionList, firstList->value)) {
                intersectionList = addNode(intersectionList, firstList->value);
            }
        }
        firstList = firstList->next;
    }
    return intersectionList;
}

int main() {

    Node *firstList = createLinkedList();
    Node *secondList = createLinkedList();
    Node *resultList = createLinkedList();

    int i = 0;
    while(i < 20) {
        int value;
        scanf("%d", &value);
        firstList = addNode(firstList, value);
        i++;
    };

    int j = 0;
    while(j < 20) {
        int value;
        scanf("%d", &value);
        secondList = addNode(secondList, value);
        j++;
    };

    resultList = intersectionList(firstList, secondList);

    int listSize = listLength(resultList);

    bubbleSort(&resultList, listSize);

    listSize > 0 ? displayLinkedList(resultList) : printf("VAZIO");

	return 0;
}