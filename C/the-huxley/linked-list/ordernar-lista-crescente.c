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

void displayLinkedList(Node *head) {
    while(head != NULL) {
        printf("%d ", head->value);
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

Node* swap(struct Node* first, struct Node* second)
{
    struct Node* tmp = second->next;
    second->next = first;
    first->next = tmp;
    return second;
};

int bubbleSort(Node **head, int count) {
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

int main() {

    Node *list = createLinkedList();

    int value;

    while(scanf("%d", &value) != EOF) {
        list = addNode(list, value);
        }

    int size = listLength(list);

    bubbleSort(&list, size);

    displayLinkedList(list);

	return 0;
}