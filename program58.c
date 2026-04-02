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

// Build tree
struct Node* buildTree(int preorder[], int inorder[],
                       int preStart, int preEnd,
                       int inStart, int inEnd) {

    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    // Root from preorder
    struct Node* root = createNode(preorder[preStart]);

    // Find root in inorder
    int index = inStart;
    while (inorder[index] != root->data) {
        index++;
    }

    int leftSize = index - inStart;

    // Build left and right
    root->left = buildTree(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           index - 1);

    root->right = buildTree(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            index + 1,
                            inEnd);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}