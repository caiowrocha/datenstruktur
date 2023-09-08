#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createNode(int value) {
    Tree *newNode = (Tree *)malloc(sizeof(Tree));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

Tree *buildTree(const char *userInput, int *index) {
        if (userInput[*index] == '\0' || userInput[*index] == ')') {
        (*index)++;
        return NULL;
    }
    if (userInput[*index] == '(') {
        (*index)++;
        if (userInput[*index] == ')') {
            (*index)++;
            return NULL;
        }
        int value = 0;
        int sign = 1;
        if (userInput[*index] == '-') {
            sign = -1;
            (*index)++;
        }
        while (userInput[*index] >= '0' && userInput[*index] <= '9') {
            value = value * 10 + (userInput[*index] - '0');
            (*index)++;
        }
        value *= sign;

        Tree* Node = createNode(value);
        Node->left = buildTree(userInput, index);
        Node->right = buildTree(userInput, index);
        (*index)++;
        return Node;
    }
    return NULL;
};


bool findEqualNode(Tree *root, int N, int depth, int *outputDepth) {
    if(root == NULL) {
        return false;
    }
    if(root->value == N) {
        *outputDepth = depth;
        return true;
    }
    if(findEqualNode(root->left, N, depth + 1, outputDepth) || findEqualNode(root->right, N, depth + 1, outputDepth)) {
        return true;
    }
    return false;
}


int main() {
    char userInput[1000];
    
    int N = 0,
        index = 0,
        depth = 0,
        outputDepth = -1;
    
    scanf("%s", userInput);
    scanf("%d", &N);
    
    Tree *root = buildTree(userInput, &index);
    
    if(findEqualNode(root, N, depth, &outputDepth)) {
        printf("ESTA NA ARVORE\n%d", outputDepth);
    } else {
        printf("NAO ESTA NA ARVORE\n-1");
    };
    
    
	return 0;
}