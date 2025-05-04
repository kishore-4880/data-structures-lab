//Program to implement Stack ADT using array and perform Push, Pop and Peek functions.

#include <stdio.h>
#include <stdlib.h>
 
class Stack {
private:
    char arr[5];  
    int top;      
public:
    Stack();
    char push(char);   
    char pop();               
    char peek();        
};

int main() {
    Stack stack;
    int choice;
    char value;

    while(1){
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
                    printf("Popped ' %c' from the stack.\n", poppedValue);
                }
                break;
            }
            case 3: {
                char topValue = stack.peek();  
                if (topValue != -1) {
                    printf("Top element is ' %c'.\n", topValue);
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

//Constructor
Stack::Stack() {
    top = -1;  
}

// Push function to add an element to the stack 
char Stack::push(char) {
    char value;
    if (top == 4) {  
        printf("Stack Overflow! Cannot push '%c'.\n", value);
    } else {
        top++;
        arr[top] = value;
        printf("Pushed '%c' to the stack.\n", value);
    }
}

// Pop function to remove the top element from the stack
char Stack::pop() {
    if (top == -1) {  
        printf("Stack empty! No elements to pop.\n");
        return -1;  
    } else {
        char poppedData = arr[top];
        top--;
        return poppedData;  
    }
}                

// Peek function to return the top element of the stack
char Stack::peek() {
    if (top == -1) {  
        printf("Stack is empty!\n");
        return -1;  
    } else {
        return arr[top];  
    }
}

// Time complexity for push - O(1)
// Time complexity for pop - O(1)
// Time complexity for peek - O(1)