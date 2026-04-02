#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Build Tree
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    // Create root
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    // If single node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val)
            break;
    }

    // Build right first
    root->right = build(inorder, i + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, i - 1, postorder, postIndex);

    return root;
}

// Preorder Traversal (Root → Left → Right)
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, 0, n - 1, postorder, &postIndex);

    // Print Preorder
    preorder(root);

    return 0;
}