#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* createTree(int value) {
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree* insert(Tree* root, int value) {
    if (root == NULL) {
        return createTree(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value >= root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void printTree(Tree* root) {
    if (root == NULL) {
        printf(" ()");
        return;
    }
    
    printf(" ( %d ", root->value);

    if (root->left == NULL && root->right == NULL) {
        printf(" ()  () )");
    } else {
        printTree(root->left);
        printf(" ");
        printTree(root->right);
        printf(" )");
    }
}

int main() {
    Tree* root = NULL;
    int value;
    
    printf("----");
    while (scanf("%d", &value) != EOF) {
        root = insert(root, value);
        printf("\nAdicionando %d\n", value);
        printf("  ");
        printTree(root);
        printf(" ");
        printf("\n----");
    }

    return 0;
}