#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int evaluateExpressionTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);


    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
    }

    return 0;
}

int main() {

    struct Node* root = createNode('+');
    root->left = createNode('*');
    root->left->left = createNode('5');
    root->left->right = createNode('4');
    root->right = createNode('-');
    root->right->left = createNode('3');
    root->right->right = createNode('2');

    int result = evaluateExpressionTree(root);

    printf("Result: %d\n", result);

    return 0;
}
