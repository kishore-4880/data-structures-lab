// C++ program to perform operations such as insertion, deletion, search and display on a doubly linked list
#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    } *head, *tail;

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

int main()
{
    int choice, stop = 0;
    int pos, num;
    list dll;
    while (!stop)
    {
        cout << "\n\nMENU :";
        cout << "\n 1. Insertion in Beginning\n 2. Insertion in End\n 3. Insertion at Position";
        cout << "\n 4. Deletion in Beginning\n 5. Deletion in End\n 6. Deletion at Position";
        cout << "\n 7. Search in List \n 8. Display List\n 9. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> num;
            dll.insertBeg(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 2:
            cout << "Enter value to insert : ";
            cin >> num;
            dll.insertEnd(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 3:
            cout << "Enter value to insert : ";
            cin >> num;
            cout << "Enter position to insert : ";
            cin >> pos;
            if (dll.insertPos(num, pos))
            {
                cout << "Insertion Succesful." << endl;
            }
            else
            {
                cout << "Invalid Position. Insertion Failed." << endl;
            }
            break;

        case 4:
            num = dll.deleteBeg();
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 5:
            num = dll.deleteEnd();
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 6:
            cout << "Enter position to delete : ";
            cin >> pos;
            num = dll.deletePos(pos);
            if (num != -1)
            {
                cout << "Deletion Succesful. Deleted value : " << num;
            }
            else
            {
                cout << "Deletion failed." << endl;
            }
            break;

        case 7:
            cout << "Enter element to search for : ";
            cin >> num;
            pos = dll.search(num);
            if (pos == -1)
            {
                cout << "Search failed." << endl;
            }
            else
            {
                cout << "Search successful.\nElement found at index : " << pos;
            }
            break;

        case 8:
            dll.display();
            break;

        case 9:
            stop = 1;
            cout << "Exitting code." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}

// Constructor function to iniialize head and tail to NULL
list::list()
{
    head = NULL;
    tail = NULL;
}

// Function to display the doubly linked list (both forward and backward)
// Time complexity = O(n)
void list::display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    cout << "\nForward :" << endl;
    node *temp = head;
    cout << "NULL <--> ";
    while (temp != NULL)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL";

    cout << "\nBackward :" << endl;

    temp = tail;
    cout << "NULL <--> ";
    while (temp != NULL)
    {
        cout << temp->data << " <--> ";
        temp = temp->prev;
    }
    cout << "NULL";
}

// Function to insert a given element at the beginning of a doubly linked list
// Time complexity = O(1)
void list::insertBeg(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->data = num;
    newnode->next = head;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    head = newnode;
}

// Function to insert a given element at the end of a doubly linked list
// Time complexity = O(1)
void list::insertEnd(int num)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = tail;
    newnode->data = num;
    newnode->next = NULL;
    if (tail == NULL)
    {
        tail = newnode;
        head = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

// Function to insert a given element at a given position in a doubly linked list
// Time complexity = O(n)
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
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = num;
    node *temp = head;
    while (temp != NULL && pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL)
    {
        return 0;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
    if (newnode->next == NULL)
    {
        tail = newnode;
    }
    else
    {
        newnode->next->prev = newnode;
    }
    return 1;
}

// Function to delete the first element of a doubly linked list
// Time complexity = O(1)
int list::deleteBeg()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return -1;
    }
    int value = head->data;
    node *temp = head;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }
    free(temp);
    return value;
}

// Function to delete the last element of a doubly linked list
// Time complexity = O(1)
int list::deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return -1;
    }
    int value = tail->data;
    node *temp = tail;
    tail = tail->prev;
    if (tail == NULL)
    {
        head = NULL;
    }
    else
    {
        tail->next = NULL;
    }
    free(temp);
    return value;
}

// Function to delete the element at a given position in a doubly linked list
// Time complexity = O(n)
int list::deletePos(int pos)
{
    if (pos < 0)
    {
        return 0;
    }
    if (pos == 0)
    {
        int value = deleteBeg();
        return value;
    }
    node *temp = head;
    while (temp != NULL && pos > 0)
    {
        temp = temp->next;
        pos--;
    }
    if (temp == NULL)
    {
        return -1;
    }
    int value = temp->data;
    temp->prev->next = temp->next;
    if (temp->next == NULL)
    {
        tail = temp->prev;
    }
    else
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return value;
}

// Function to search for an element in a doubly linked list
// Time complexity = O(n)
int list::search(int num)
{
    int index = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == num)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}