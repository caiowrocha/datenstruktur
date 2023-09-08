#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int freq;
  char letter;
  struct Node *next;
} Node;

Node *addNode(Node *head, int freq, char letter) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->letter = letter;
  newNode->freq = freq;
  newNode->next = head;

  return newNode;
};

void displayLinkedList(Node *head) {
  while (head != NULL) {
    printf("%c %d\n", head->letter, head->freq);
    head = head->next;
  }
}

Node *createLinkedList() { return NULL; }

int main(void) {

  char sentence[256];
  fgets(sentence, 256, stdin);
  int size = strlen(sentence);

  int charFreq[256] = {0};

  for (int i = 0; i < size; i++) {
    charFreq[(int)sentence[i]]++;
  };

  Node *final = createLinkedList();

  for (int j = 0; j < 256; j++) {
    if (charFreq[j] > 0) {
      final = addNode(final, charFreq[j], (char)j);
    };
  };

  displayLinkedList(final);

  return 0;
}
