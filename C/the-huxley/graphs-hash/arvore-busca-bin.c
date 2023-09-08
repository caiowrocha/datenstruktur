#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

bool isValidBstAssistant(Tree *root, Tree **prev) {
    if(root == NULL) {
        return true;
    } 
    
    if(!isValidBstAssistant(root->left, prev)) {
        return false;
    }
    
    if (*prev != NULL && root->value <= (*prev)->value) {
        return false;
    }
    
    *prev = root;
    
    return isValidBstAssistant(root->right, prev);
};

bool isValidBst(Tree *root) {
    Tree *prev = NULL;
    return isValidBstAssistant(root, &prev);
};

void freeTree(Tree *root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
};


Tree* buildTree(const char* input, int* index) {
    if (input[*index] == '\0') {
        return NULL;
    }
    if (input[*index] == '(') {
        (*index)++;
        if (input[*index] == ')') {
            (*index)++; 
            return NULL;
        }
        int value = 0;
        int sign = 1;
        if (input[*index] == '-') {
            sign = -1;
            (*index)++; 
        }
        while (input[*index] >= '0' && input[*index] <= '9') {
            value = value * 10 + (input[*index] - '0');
            (*index)++;
        }
        value *= sign;

        Tree* Node = createNode(value);
        Node->left = buildTree(input, index);
        Node->right = buildTree(input, index); 
        (*index)++; 
        return Node;
    }
    return NULL;
}


int main() {
    char treeRead[1000];
    int index = 0;
    
    scanf("%s", treeRead);
    
    Tree* root = buildTree(treeRead, &index);

    if (isValidBst(root)) {
        printf("VERDADEIRO\n");
    } else {
        printf("FALSO\n");
    }
    
    freeTree(root);

    return 0;
}

