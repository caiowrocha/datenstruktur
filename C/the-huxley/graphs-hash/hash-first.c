#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node *next;
} Node;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
};

void insertKey(Node *table[], int key, int tableSize) {
    int i = hashFunction(key, tableSize);
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    
    if(table[i] == NULL) {
        table[i] = newNode;
    } else {
        Node *current = table[i];
        while(current->next != NULL) {
            current = current->next;
        };
        current->next = newNode;
    };
};

void listTable(Node *table[], int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        printf("%d -> ", i);
        Node *current = table[i];
        while(current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        };
        printf("\\\n");
    };
};

int main() {
    int testsAmount = 0;
    scanf("%d", &testsAmount);
    getchar();
    
    for(int i = 0; i < testsAmount; i++) {
        int M = 0,
            C = 0;
            scanf("%d %d", &M, &C);
            getchar();
        
        Node *table[M];
        int j = 0;
        while(j < M) {
            table[j] = NULL;
            j++;
        }
        
        int k = 0;
        while(k < C) {
            int key;
            scanf("%d", &key);
            insertKey(table, key, M);
            k++;
        };
        
        listTable(table, M);
        
        if(i < testsAmount - 1) {
            printf("\n");
        }
    }
    
	return 0;
}