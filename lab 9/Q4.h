// Header file with required functions for binary expression tree
#include <iostream>
#include <stack>

using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

class Tree
{
private:
    node *root;

public:
    Tree();
    node *getRoot();
    void setRoot(node *);
    void constructTree(string);
    void preorder(node *root);
    void inorder(node *root);
    void postorder(node *root);
};

// Constructor function to initialize root to NULL
Tree::Tree()
{
    root = NULL;
}

// Getter function to get root
node *Tree::getRoot()
{
    return root;
}

// Setter function to set root
void Tree::setRoot(node *newroot)
{
    root = newroot;
}

// Function to construct an expression tree from a postfix expression
// Time complexity = O(n)
void Tree::constructTree(string input)
{
    stack<node *> expression;
    for (int i = 0; i < input.length(); i++)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = input[i];
        newnode->left = NULL;
        newnode->right = NULL;
        if (isalnum(input[i]))
        {
            expression.push(newnode);
        }
        else
        {
            newnode->right = expression.top();
            expression.pop();
            newnode->left = expression.top();
            expression.pop();
            expression.push(newnode);
        }
    }
    root = expression.top();
}

// Function to display the tree in preorder format
void Tree::preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to display the tree in inorder format
void Tree::inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to display the tree in postorder format
void Tree::postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}