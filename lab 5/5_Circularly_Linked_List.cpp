// C++ program to perform operations such as insertion, deletion, search, display and reverse on a circularly linked list
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

int main()
{
    int choice, stop = 0;
    int pos, num;
    list cll;
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
            cll.insertBeg(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 2:
            cout << "Enter value to insert : ";
            cin >> num;
            cll.insertEnd(num);
            cout << "Insertion Succesful." << endl;
            break;

        case 3:
            cout << "Enter value to insert : ";
            cin >> num;
            cout << "Enter position to insert : ";
            cin >> pos;
            if (cll.insertPos(num, pos))
            {
                cout << "Insertion Succesful." << endl;
            }
            else
            {
                cout << "Invalid Position. Insertion Failed." << endl;
            }
            break;

        case 4:
            num = cll.deleteBeg();
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
            num = cll.deleteEnd();
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
            num = cll.deletePos(pos);
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
            cout << "\nEnter element to search for : ";
            cin >> num;
            pos = cll.search(num);
            if (pos == -1)
            {
                cout << "Search failed. Element not found." << endl;
            }
            else
            {
                cout << "Search successful.\nElement found at index : " << pos;
            }
            break;

        case 8:
            cll.display();
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
