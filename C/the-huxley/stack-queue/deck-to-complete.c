#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _node node_t;
typedef struct _deque deque_t;

struct _node {
    node_t *prev;
    node_t *next;
    int value;
};

struct _deque {
    node_t *front;
    node_t *rear;
    int size;
};

node_t* node_new(int value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node != NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        new_node->value = value;
    }
    return new_node;
}

deque_t* construct() {
    deque_t *new_deque = (deque_t *)malloc(sizeof(deque_t));
    if (new_deque != NULL) {
        new_deque->front = NULL;
        new_deque->rear = NULL;
        new_deque->size = 0;
    }
    return new_deque;
}

void destruct(deque_t *deque) {
    if (deque == NULL) return;
    erase(deque);
    free(deque);
}

int size(deque_t *deque) {
    if (deque == NULL) return 0;
    return deque->size;
}

bool empty(deque_t *deque) {
    return (deque == NULL || deque->size == 0);
}

int front(deque_t *deque) {
    if (empty(deque)) return INT_MIN;
    return deque->front->value;
}

int rear(deque_t *deque) {
    if (empty(deque)) return INT_MIN;
    return deque->rear->value;
}

void enqueue_rear(deque_t *deque, int value) {
    node_t *new_node = node_new(value);
    if (new_node == NULL) return;

    if (empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        new_node->prev = deque->rear;
        deque->rear->next = new_node;
        deque->rear = new_node;
    }
    deque->size++;
}

void enqueue_front(deque_t *deque, int value) {
    node_t *new_node = node_new(value);
    if (new_node == NULL) return;

    if (empty(deque)) {
        deque->front = new_node;
        deque->rear = new_node;
    } else {
        new_node->next = deque->front;
        deque->front->prev = new_node;
        deque->front = new_node;
    }
    deque->size++;
}

void dequeue_rear(deque_t *deque) {
    if (empty(deque)) return;

    node_t *temp = deque->rear;
    if (deque->size == 1) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    deque->size--;
}

void dequeue_front(deque_t *deque) {
    if (empty(deque)) return;

    node_t *temp = deque->front;
    if (deque->size == 1) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    deque->size--;
}

void erase(deque_t *deque) {
    while (!empty(deque)) {
        dequeue_front(deque);
    }
}

void print(deque_t *deque) {
    if (empty(deque)) {
        printf("Deque vazio\n");
        return;
    }

    node_t *current = deque->front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int N, M, num;
    scanf("%d", &N);
    deque_t *deque = construct();

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        enqueue_rear(deque, num);
    }

    scanf("%d", &M); // Lê o número de operações M, mas não lê os valores.

    // Aqui você pode realizar as operações de acordo com o valor de M, como enqueue, dequeue, etc.

    destruct(deque);
    return 0;
}

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();
  
  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    destruct(deque);
       
	return 0;
}