// Header file of stack ADT using a linked list
#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
};



class Stack
{
private:
    node *top;

public:
    Stack();
    node *gettop();
    void push(char);
    char pop();
    char peek();
};

// Constructor function to initialize top to NULL
Stack::Stack()
{
    top = NULL;
}

// Getter function to get top
node *Stack::gettop()
{
    return top;
}

// Function to push a value into the stack
void Stack::push(char val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
// Functon to pop the top element from the stack
char Stack::pop()
{
    if (top == NULL)
    {
        return '\0';
    }
    char value = top->data;
    node *temp = top;
    top = top->next;
    free(temp);
    return value;
}
// Function to peek (view the top element)
char Stack::peek()
{
    if (top == NULL)
    {
        return '\0';
    }
    return top->data;
}