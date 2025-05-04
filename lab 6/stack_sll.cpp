//Program to implement Stack ADT using array and perform Push, Pop and Peek functions.

#include <stdio.h>
#include <stdlib.h>

class Stack {
private:
struct Node {
    char data;
    Node* next;
    };
    Node* top;
public:
    Stack() {top = NULL;}

    void push(char);
    char pop();
    char peek();
};

int main() {
    Stack stack;
    int choice;
    char value;

    while(1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push: ");
                scanf(" %c", &value);
                stack.push(value);
                break;
            case 2: {
                char poppedValue = stack.pop();
                if (poppedValue != -1) {
                    printf("Popped '%c' from the stack.\n", poppedValue);
                }
                break;
            }
            case 3: {
                char topValue = stack.peek();
                if (topValue != -1) {
                    printf("Top element is '%c'.\n", topValue);
                }
                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

//Function to Push an element to the stack
void Stack::push(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("The list is full!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed '%c' to the stack.\n", value);
}

//Function to Pop the top element from the stack
char Stack::pop() {
    if (top == NULL) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    } else {
        Node* temp = top;
        char poppedData = top->data;
        top = top->next;
        free(temp);
        return poppedData;
    }
}

//Function to return the top element of the stack(Peek)
char Stack::peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return top->data;
    }
}

// Time complexity for push - O(1)
// Time complexity for pop - O(1)
// Time complexity for peek - O(1)