#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Node* buildBSTFromPreOrderUtil(int preOrder[], int* preIndex, int key, int min, int max, int n) {
    if (*preIndex >= n) return NULL;

    struct Node* root = NULL;

    if (key > min && key < max) {
        root = createNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < n) {
            root->left = buildBSTFromPreOrderUtil(preOrder, preIndex, preOrder[*preIndex], min, key, n);
        }
        if (*preIndex < n) {
            root->right = buildBSTFromPreOrderUtil(preOrder, preIndex, preOrder[*preIndex], key, max, n);
        }
    }
    return root;
}

struct Node* buildBSTFromPreOrder(int preOrder[], int n) {
    int preIndex = 0;
    return buildBSTFromPreOrderUtil(preOrder, &preIndex, preOrder[0], INT_MIN, INT_MAX, n);
}

struct Node* buildBSTFromPostOrderUtil(int postOrder[], int* postIndex, int key, int min, int max, int n) {
    if (*postIndex < 0) return NULL;

    struct Node* root = NULL;

    if (key > min && key < max) {
        root = createNode(key);
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0) {
            root->right = buildBSTFromPostOrderUtil(postOrder, postIndex, postOrder[*postIndex], key, max, n);
        }
        if (*postIndex >= 0) {
            root->left = buildBSTFromPostOrderUtil(postOrder, postIndex, postOrder[*postIndex], min, key, n);
        }
    }
    return root;
}

struct Node* buildBSTFromPostOrder(int postOrder[], int n) {
    int postIndex = n - 1;
    return buildBSTFromPostOrderUtil(postOrder, &postIndex, postOrder[postIndex], INT_MIN, INT_MAX, n);
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int preOrderArr[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(preOrderArr) / sizeof(preOrderArr[0]);

    struct Node* rootFromPreOrder = buildBSTFromPreOrder(preOrderArr, n);

    printf("Tree built from PreOrder Traversal:\n");
    printf("In-order: ");
    inOrder(rootFromPreOrder);
    printf("\nPost-order: ");
    postOrderTraversal(rootFromPreOrder);
    printf("\n");

    int postOrderArr[] = {20, 40, 30, 60, 80, 70, 50};
    n = sizeof(postOrderArr) / sizeof(postOrderArr[0]);

    struct Node* rootFromPostOrder = buildBSTFromPostOrder(postOrderArr, n);

    printf("Tree built from PostOrder Traversal:\n");
    printf("In-order: ");
    inOrder(rootFromPostOrder);
    printf("\nPre-order: ");
    preOrderTraversal(rootFromPostOrder);
    printf("\n");

    return 0;
}

