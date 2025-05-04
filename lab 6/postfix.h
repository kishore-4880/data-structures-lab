// Header function to implement infix to postfix and postfix evaluation.

#ifndef STACK_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

typedef struct {
    struct Node* top;
} Stack;

void initStack(Stack* s);
int isEmpty(const Stack* s);
void push(Stack* s, char value);
char pop(Stack* s);
char peek(const Stack* s);

// Initialize stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Function to Check if stack is empty
inline int isEmpty(const Stack* s) {
    return s->top == NULL;
}

// Function to Push an element onto the stack
void push(Stack* s, char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Function to Pop an element from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    struct Node* temp = s->top;
    char value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Function to Peek the top element
inline char peek(const Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return '\0';
    }
    return s->top->data;
}

#endif