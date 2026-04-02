#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Check mirror
int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;

    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetric
void checkSymmetric(struct Node* root) {
    if (root == NULL || isMirror(root->left, root->right))
        printf("YES");
    else
        printf("NO");
}