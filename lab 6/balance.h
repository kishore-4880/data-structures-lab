#ifndef STACK_SLL_H
#define STACK_SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void initStack(Stack *stack) {
    stack->top = NULL;
}

bool push(Stack *stack, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
        return false;

    new_node->data = value;
    new_node->next = stack->top;
    stack->top = new_node;
    return true;
}

char pop(Stack *stack) {
    if (stack->top == NULL)
        return -1;

    Node *temp = stack->top;
    char PoppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return PoppedValue;
}

char peek(Stack *stack) {
    if (stack->top == NULL)
        return -1;
    return stack->top->data;
}

bool isEmpty(Stack *stack) {
    return stack->top == NULL;
}

bool isBalanced(const char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) return false;
            pop(&stack);
        }
    }

    bool result = isEmpty(&stack);
    return result;
}

#endif
