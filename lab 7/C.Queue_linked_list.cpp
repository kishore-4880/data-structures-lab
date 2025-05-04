#include <cstdio>
#include <cstdlib>

class Queue {
private:
    struct Node {
        int data;
        struct Node* next;
    };
    struct Node* front;
    struct Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    int Enqueue(int);
    int Dequeue();
    int Peek();
};

int main() {
    Queue Q;
    int choice, value, result;
    do {
        printf("\nMENU\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                result = Q.Enqueue(value);
                if (result == -1) {
                    printf("Invalid memory allocation");
                } else {
                    printf("Successfully Inserted\n");
                }
                break;
            case 2:
                result = Q.Dequeue();
                if (result == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("The removed element is %d\n", result);
                }
                break;
            case 3:
                result = Q.Peek();
                if (result == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("The front element of the Queue is %d\n", result);
                }
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
}

// This function will insert the given element in the queue
int Queue::Enqueue(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Invalid memory allocation\n");
        return -1;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    return 1;
}

// This function will delete the front element in the queue
int Queue::Dequeue() {
    if (front == NULL) {
        return -1;
    }
    struct Node* temp = front;
    int element = temp->data;

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return element;
}

// This function will display the front element of the queue
int Queue::Peek() {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}

