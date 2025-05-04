// Header file consisting of operations on a circularly linked list
#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        int data;
        struct node *next;
    } *head;

public:
    list();
    void display();
    void insertBeg(int);
    void insertEnd(int);
    bool insertPos(int, int);
    int deleteBeg();
    int deleteEnd();
    int deletePos(int);
    int search(int);
};

// Constructor function to intialize head to NULL
list::list()
{
    head = NULL;
}

// Function to display the circularly linked list
// Time Complexity = O(n)
void list::display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << " (HEAD)";
}

// Function to insert a given element at the beginning of a circularly linked list
// Time Complexity = O(n)
void list::insertBeg(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

// Function to insert a given element at the end of a circularly linked list
// Time Complexity = O(n)
void list::insertEnd(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    if (head == NULL)
    {
        head = newnode;
        head->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

// Function to insert a given element at a given position in a circularly linked list
// Time Complexity = O(n)
bool list::insertPos(int num, int pos)
{
    if (pos < 0)
    {
        return 0;
    }
    if (pos == 0)
    {
        insertBeg(num);
        return 1;
    }
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    while (pos > 1)
    {
        temp = temp->next;
        if (temp == head)
        {
            return 0;
        }
        pos--;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

// Function to delete the first element of a circularly linked list
// Time Complexity = O(n)
int list::deleteBeg()
{
    if (head == NULL)
    {
        return -1;
    }
    int value = head->data;
    node *del = head;
    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
    }
    free(del);
    return value;
}

// Function to delete the last element of a circularly linked list
// Time Complexity = O(n)
int list::deleteEnd()
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->next == head)
    {

        int value = head->data;
        free(head);
        head = NULL;
        return value;
    }
    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    int value = temp->next->data;
    node *del = temp->next;
    temp->next = head;
    free(del);
    return value;
}

// Function to delete the element at a given position in a circularly linked list
// Time Complexity = O(n)
int list::deletePos(int pos)
{
    if (head == NULL)
    {
        return -1;
    }
    if (pos < 0)
    {
        return -1;
    }
    if (pos == 0)
    {
        int value = deleteBeg();
        return value;
    }
    node *del = head;
    node *temp = (node *)malloc(sizeof(node));
    while (pos > 0)
    {
        temp = del;
        del = del->next;
        if (del == head)
        {
            return -1;
        }
        pos--;
    }
    int value = del->data;
    temp->next = del->next;
    free(del);
    return value;
}

// Function to search for an element in a circularly linked list
// Time Complexity = O(n)
int list::search(int num)
{
    int index = 0;
    if (head == NULL)
    {
        return -1;
    }
    node *temp = head;
    do
    {
        if (num == temp->data)
        {
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != head);
    return -1;
}
