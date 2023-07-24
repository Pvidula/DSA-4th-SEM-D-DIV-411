#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to get the height of a binary tree
int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to print nodes at a given level
void printLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Function to perform level-order traversal
void levelOrderTraversal(struct Node* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printLevel(root, i);
    }
}

// Driver code
int main() {
    // Create a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform level-order traversal
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
