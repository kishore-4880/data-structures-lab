//Menu driven program to implement tree ADT using a character binary tree.

#include <iostream>
using namespace std;

class Tree {
private:
    struct Node {
        char data;
        Node *left, *right;
    };
    Node *root;

    void preorderTraversal(Node* node);
    void inorderTraversal(Node* node);
    void postorderTraversal(Node* node);
    bool searchTree(Node* node, char key);

public:
    Tree(){
        root = nullptr;
    };

    void insert(char value);
    void preorder();
    void inorder();
    void postorder();
    bool search(char key);
};

int main() {
    int ch;
    Tree t;
    while (1) {
        cout << "\nMenu:\n1) Insert\n2) Preorder\n3) Inorder\n4) Postorder\n5) Search\n6) Exit\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                char value;
                cout << "Enter a character: ";
                cin >> value;
                t.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                t.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                t.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                t.postorder();
                break;
            case 5:
                char key;
                cout << "Enter character to search: ";
                cin >> key;
                if (t.search(key)) {
                    cout << "Element found in tree." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

//Function to insert a character.
void Tree::insert(char value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    if (root == nullptr) {
        root = newNode;
        return;
    }
    
    Node* temp = root;
    char choice;
    while (true) {
        cout << "Insert left or right of " << temp->data << "? (l/r): ";
        cin >> choice;
        if (choice == 'l') {
            if (temp->left == nullptr) {
                temp->left = newNode;
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                break;
            } else {
                temp = temp->right;
            }
        }
    }
}

//Function for preorder traversal.
//The time complexity is O(n).
void Tree::preorderTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

//Function for inorder traversal.
//The time complexity is O(n).
void Tree::inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

//Function for postorder traversal.
//The time complexity is O(n).
void Tree::postorderTraversal(Node* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

//Function to search for a character in the tree.
//The time complexity is O(n).
bool Tree::searchTree(Node* node, char key) {
    if (node == nullptr) return false;
    if (node->data == key) return true;
    return searchTree(node->left, key) || searchTree(node->right, key);
}

void Tree::preorder() {
    preorderTraversal(root);
    cout << endl;
}

void Tree::inorder() {
    inorderTraversal(root);
    cout << endl;
}

void Tree::postorder() {
    postorderTraversal(root);
    cout << endl;
}

bool Tree::search(char key) {
    return searchTree(root, key);
}