// C++ program to implement Hash ADT (Seperate Chaining)
#include <iostream>
using namespace std;
#define SIZE 10

struct node
{
    int data;
    node *next;
};

class HashTable
{
private:
    node *table[SIZE];
    int hash(int);

public:
    HashTable();
    void display();
    int insert(int);
    int remove(int);
    int search(int);
};

int main()
{
    int choice;
    int val, result;
    HashTable ht;
    do
    {
        cout << "\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Search\n 4. Display\n 5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> val;
            result = ht.insert(val);
            cout << "Insertion Successful. Inserted at index " << result << endl;
            break;

        case 2:
            cout << "Enter value to delete : ";
            cin >> val;
            val = ht.remove(val);
            if (val == -1)
            {
                cout << "Deletion Failed. Key not found." << endl;
            }
            else
            {
                cout << "Deletion Successful. Deleted value : " << val << endl;
            }
            break;

        case 3:
            cout << "Enter element to search for : ";
            cin >> val;
            result = ht.search(val);
            if (result != -1)
            {
                cout << "Element found at index " << result << endl;
            }
            else
            {
                cout << "Element not found." << endl;
            }
            break;

        case 4:
            ht.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    } while (choice != 5);
}

// Constructor function to initialize the hash table to NULL
HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }
}

// Hash function
int HashTable::hash(int key)
{
    return key % SIZE;
}

// Function to display the hash table
void HashTable::display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Bucket " << i << " : ";
        node *current = table[i];
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
}

// Function to insert a value in the hash table
int HashTable::insert(int key)
{
    int index = hash(key);
    node *newNode = new node;
    newNode->data = key;
    newNode->next = table[index];
    table[index] = newNode;
    return index;
}

// Function to delete a value from the hash table
int HashTable::remove(int key)
{
    int index = hash(key);
    node *current = table[index];
    node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            return key;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}

// Function to search for a value in the hash table
int HashTable::search(int key)
{
    int index = hash(key);
    node *current = table[index];
    while (current != NULL)
    {
        if (current->data == key)
            return index;
        current = current->next;
    }

    return -1;
}