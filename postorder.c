#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postorderDelete(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // First, delete the left and right subtrees recursively
    postorderDelete(root->left);
    postorderDelete(root->right);

    // Then, delete the current node
    printf("Deleting node with data: %d\n", root->data);
    free(root);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Deleting nodes using postorder traversal:\n");
    postorderDelete(root);

    return 0;
}

