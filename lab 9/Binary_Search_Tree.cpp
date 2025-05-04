//Program to perform the functions of Tree ADT - Binary Searc Tree Implementation
#include <stdio.h>
#include <stdlib.h>

class BinarySearchTree {
private:
    struct Node {
        int data;
        struct Node* left;
        struct Node* right;
    } *root;

    Node* createNode(int data); 
    void preorderTraversal(Node* node);
    void inorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    Node* insertHelper(Node* node, int data);
    int searchHelper(Node* node, int key);

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insertData(int data);
    void preorder();
    void inorder();
    void postorder();
    void searchData(int key);
};

int main() {
    BinarySearchTree tree;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &data);
                tree.insertData(data);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                printf("Enter integer to search: ");
                scanf("%d", &data);
                tree.searchData(data);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

// Create a new node
BinarySearchTree :: Node* BinarySearchTree :: createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an integer following BST rules
BinarySearchTree :: Node* BinarySearchTree :: insertHelper(Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)  // Insert in the left subtree
        node->left = insertHelper(node->left, data);
    else if (data > node->data)  // Insert in the right subtree
        node->right = insertHelper(node->right, data);
    
    return node;
}

// Preorder Traversal (Root-Left-Right)
void BinarySearchTree :: preorderTraversal(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Inorder Traversal (Left-Root-Right) [Sorted Order]
void BinarySearchTree :: inorderTraversal(Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

// Postorder Traversal (Left-Right-Root)
void BinarySearchTree :: postorderTraversal(Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

// Search for an integer in BST
int BinarySearchTree :: searchHelper(Node* node, int key) {
    if (node == NULL) return 0;
    if (node->data == key) return 1;
    if (key < node->data)
        return searchHelper(node->left, key);
    return searchHelper(node->right, key);
}

// Insert function
void BinarySearchTree :: insertData(int data) {
    root = insertHelper(root, data);
}

// Preorder Traversal Wrapper
void BinarySearchTree :: preorder() {
    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");
}

// Inorder Traversal Wrapper
void BinarySearchTree :: inorder() {
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");
}

// Postorder Traversal Wrapper
void BinarySearchTree :: postorder() {
    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");
}

// Search function
void BinarySearchTree :: searchData(int key) {
    if (searchHelper(root, key))
        printf("Element %d found in the tree\n", key);
    else
        printf("Element %d not found in the tree\n", key);
}