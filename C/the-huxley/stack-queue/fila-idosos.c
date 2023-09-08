#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Person {
    int id;
    int age;
} Person;

typedef struct Queue {
    Person *people;
    int size;
    int capacity;
    int start;
    int end;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->people = (Person *)malloc(sizeof(Person)*capacity);
    queue->capacity = capacity;
    queue->size = 0;
    queue->start = 0;
    queue->end = -1;
    return queue;
};

void addPerson(Queue *queue, int id, int age) {
    if (queue->size < queue->capacity) {
        queue->end = (queue->end + 1) % queue->capacity;
        queue->people[queue->end].id = id;
        queue->people[queue->end].age = age;
        queue->size++;
    };
};

void removePerson(Queue *queue) {
    if (queue->size > 0) {
        queue->start = (queue->start + 1) % queue->capacity;
        queue->size--;
    }
}

void printQueue(Queue *queue, const char *queueName) {
    printf("fila de %s:\n", queueName);
    if(queue->size == 0) {
      printf("fila vazia!\n");
    }
    else {
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("ID: %d IDADE: %d\n", queue->people[(queue->start + i) % queue->capacity].id,
               queue->people[(queue->start + i) % queue->capacity].age);
       }
    }
}

int main() {
    int priority; 
    scanf("%d", &priority);
    int velhinhosAtendidos = 0;

    Queue *old = createQueue(100);    
    Queue *notOld = createQueue(100); 

    char op;
    while (1) {
        scanf(" %c", &op);

        if (op == 'f') {
            break;
        } else if (op == 'a') {
            int id, idade;
            scanf("%d %d", &id, &idade);
            if (idade > 60) {
                addPerson(old, id, idade);
            } else {
                addPerson(notOld, id, idade);
            }
        } else if (op == 'r') {
            if (old->size > 0) {
              if(velhinhosAtendidos < priority) {
                  removePerson(old);
                  velhinhosAtendidos++;
              } else {
                velhinhosAtendidos = 0;
                if(notOld->size > 0) {
                  removePerson(notOld);
                }
              }
            } else if(notOld->size > 0) {
              removePerson(notOld);
              velhinhosAtendidos = 0;
            } 
          } else if (op == 'i') {
            printQueue(old, "idosos");
            printQueue(notOld, "nao-idosos");
            printf("----------\n");
            printf("\n");
        }
    }
    free(old->people);
    free(old);
    free(notOld->people);
    free(notOld);

    return 0;
}
