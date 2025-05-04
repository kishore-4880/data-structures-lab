// C++ program to perfrom Priority Queue implementation

#include <cstdio>
#include <vector>
using namespace std;

class Priority_Queue
{
private:
    int size;
    vector<int> vec;

public:
    Priority_Queue();
    void display();
    void insert(int);
    int remove();
    int search(int);
    void sort();
};

void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

Priority_Queue::Priority_Queue()
{
    size = 0;
}

void Priority_Queue::display()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", vec[i]);
    }
    printf("\n");
}

void Priority_Queue::insert(int num)
{
    vec.push_back(num);
    int index = size;
    while (index > 0 && vec[index] > vec[(index - 1) / 2])
    {
        swap(vec[index], vec[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
    size++;
}

int Priority_Queue::remove()
{
    if (size == 0)
    {
        return -1;
    }
    int del = vec[0];
    size--;
    swap(vec[0], vec[size]);
    vec.pop_back();
    int index = 0;
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int greater = index;
        if (left < size && vec[left] > vec[greater])
        {
            greater = left;
        }
        if (right < size && vec[right] > vec[greater])
        {
            greater = right;
        }
        if (greater == index)
        {
            break;
        }
        swap(vec[index], vec[greater]);
        index = greater;
    }
    return del;
}

int Priority_Queue::search(int num)
{
    for (int i = 0; i < size; i++)
    {
        if (vec[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

void Priority_Queue::sort()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
        return;
    }
    int temp = size;
    for (int i = temp; i > 0; i--)
    {
        vec[i - 1] = remove();
    }
    size = temp;
}

int main()
{
    int choice, val;
    Priority_Queue pq;
    do
    {
        printf("\n\nMENU :\n 1. Insert\n 2. Delete\n 3. Display\n 4. Search\n 5. Sort\n 6. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d", &val);
            pq.insert(val);
            printf("Insertion Successful.\n");
            break;

        case 2:
            val = pq.remove();
            if (val != -1)
            {
                printf("Deletion successful. Deleted value : %d\n", val);
            }
            else
            {
                printf("Deletion failed. Queue is empty.\n");
            }
            break;

        case 3:
            pq.display();
            break;

        case 4:
            printf("Enter element to search for : ");
            scanf("%d", &val);
            if (pq.search(val))
            {
                printf("Element found.\n");
            }
            else
            {
                printf("Element not found.\n");
            }
            break;

        case 5:
            pq.sort();
            printf("Queue Sorted. Enter 3 to display.\n");
            break;

        case 6:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Enter again.\n");
            break;
        }
    } while (choice != 6);
    return 0;
}
