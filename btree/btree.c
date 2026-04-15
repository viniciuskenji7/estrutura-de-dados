#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

Node *insertData(Node *root, int value) {

    if(root == NULL) {
        return createNode(value);
        printf("\nRoot Inicializado com sucesso!\n");
    }

    if (value < root->data) {
        root->left = insertData(root->left, value);
        printf("\nValor no esquerdo: %d", root->left->data);
    } else if (value > root->data) {
        root->right = insertData(root->right, value);
        printf("\nValor no direito: %d", root->right->data);
    }
    return root;
}

int main() {
    Node *root = NULL;
    root = insertData(root, 15);
    root = insertData(root, 50);
    root = insertData(root, 10);
    return 0;
}