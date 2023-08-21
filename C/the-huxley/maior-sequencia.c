#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void displayLinkedList(Node *head) {
  while (head != NULL) {
    printf("%d", head->value);
    head = head->next;
  }
}

Node *destroyList(Node *head) {
  Node *current = head;
  Node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  head = NULL;
  return head;
};

int listSize(Node *head) {
  int counter = 0;
  while (head != NULL) {
    counter++;
    head = head->next;
  };
  return counter;
};

Node *createLinkedList() { return NULL; }

Node *addNode(Node *head, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->next = head;
  newNode->value = value;
  return newNode;
};

void insertNode(int position, int value, Node **head) {
  int size = listSize(*head);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  if (position < 0 || position > size) {
    printf("Invalid Position");
  } else if (position == 0) {
    newNode->next = *head;
    *head = newNode;
  } else {
    Node *temp = *head;

    while (--position) {
      temp = temp->next;
    };
    newNode->next = temp->next;
    temp->next = newNode;
  };
};

void fillArray(int *A, int size, Node *head) {
  for (int i = 0; i < size; i++) {
    A[i] = head->value;
    head = head->next;
  };
};

int *checkSequence(int *A, int size) {

  int i, prev = 0, final = 0, counter = 0;

  int *result = (int *)malloc(sizeof(int) * 2);

  for (i = 0; i < size; i++) {
    if (A[i] == 0) {
      counter++;
    } else {
      if (counter > prev) {
        prev = counter;
        final = i;
        counter = 0;
      }
      counter = 0;
    }
  }

  result[1] = final - prev;
  result[2] = final - 1;
  return result;
};

int main() {

  Node *list = createLinkedList();

  char A[1000];
  int i;

  while (i < 1000) {
    scanf("%s", A);
    if (strlen(A) == 1)
      break;
    for (int j = 0; j < strlen(A); j++) {
      int n = A[j] - '0';
      insertNode(j, n, &list);
    };

    int size = listSize(list);
    int Numbers[size];
    fillArray(Numbers, size, list);

    int *x = checkSequence(Numbers, size);

    printf("%d %d\n", x[1], x[2]);
    list = destroyList(list);
    i++;
  };

  return 0;
}
