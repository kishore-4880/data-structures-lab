// C++ program to implement Hash ADT (Quadratic Probing)
#include <iostream>
using namespace std;
#define SIZE 10

class HashTable
{
private:
    int table[SIZE];
    int occupied[SIZE]; // 1 -> Occupied, 0 -> Empty, -1 -> Deleted
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
            if (result != -1)
            {
                cout << "Insertion Successful." << endl;
            }
            else
            {
                cout << "Hash Table is full." << endl;
            }
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

// Constructor function to initialize the hash table and occupancy table
HashTable::HashTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
        occupied[i] = 0;
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
        if (occupied[i] != 1)
        {
            cout << i << " --> " << "Empty." << endl;
        }
        else
        {
            cout << i << " --> " << table[i] << endl;
        }
    }
}

// Function to insert a value in the hash table
int HashTable::insert(int key)
{
    int index = hash(key);
    int i = 0;
    while (occupied[(index + i * i) % SIZE] == 1)
    {
        i++;
        if (i == SIZE)
        {
            return -1;
        }
    }
    int probeIndex = (index + i * i) % SIZE;
    table[probeIndex] = key;
    occupied[probeIndex] = 1;
    return probeIndex;
}

// Function to delete a value from the hash table
int HashTable::remove(int key)
{
    int index = hash(key);
    int i = 0;
    while (i < SIZE && occupied[(index + i * i) % SIZE] != 0)
    {
        if (table[(index + i * i) % SIZE] == key)
        {
            table[(index + i * i) % SIZE] = -1;
            occupied[(index + i * i) % SIZE] = -1;
            return key;
        }
        i++;
    }
    return -1;
}

// Function to search for a value in the hash table
int HashTable::search(int key)
{
    int index = hash(key);
    int i = 0;
    while (i < SIZE && occupied[(index + i * i) % SIZE] != 0)
    {
        if (table[(index + i * i) % SIZE] == key)
        {
            return (index + i * i) % SIZE;
        }
        i++;
    }
    return -1;
}