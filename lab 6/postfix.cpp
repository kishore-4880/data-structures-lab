#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "stack.h"

int main() {
    char infix[1000] = "", postfix[1000] = "";
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Get Infix Expression\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter a valid infix expression: ");
                fgets(infix, sizeof(infix), stdin);
                infix[strcspn(infix, "\n")] = 0;
                break;
                
            case 2:
                if (infix[0] == '\0') {
                    printf("No infix expression stored! Please enter one first.\n");
                } else {
                    strcpy(postfix, infixToPostfix(infix));
                    printf("Postfix expression: %s\n", postfix);
                }
                break;
                
            case 3:
                if (postfix[0] == '\0') {
                    printf("No postfix expression to evaluate! Convert infix first.\n");
                } else {
                    int result = evaluatePostfix(postfix);
                    printf("Result of postfix evaluation: %d\n", result);
                }
                break;
                
            case 4:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to return precedence of operators
int getPrecedence(const char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0) return 2;
    if (strcmp(op, "^") == 0) return 3;
    if (strcmp(op, "=") == 0 || strcmp(op, "+=") == 0 || strcmp(op, "-=") == 0 || 
        strcmp(op, "*=") == 0 || strcmp(op, "/=") == 0 || strcmp(op, "%=") == 0)
        return 4;
    return 0;
}

// Check if string is an arithmetic or assignment operator
int isOperator(const char* op) {
    return (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || 
            strcmp(op, "/") == 0 || strcmp(op, "%") == 0 || strcmp(op, "^") == 0 ||
            strcmp(op, "=") == 0 || strcmp(op, "+=") == 0 || strcmp(op, "-=") == 0 || 
            strcmp(op, "*=") == 0 || strcmp(op, "/=") == 0 || strcmp(op, "%=") == 0);
}

// Check if character is an operand (digit or letter)
int isOperand(char ch) {
    return isalnum(ch);
}

// Convert infix to postfix
char* infixToPostfix(char* infix) {
    Stack s;
    initStack(&s);
    static char postfix[1000] = "";
    int len = strlen(infix);
    int i = 0, k = 0;

    while (i < len) {
        char ch = infix[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (isOperand(ch)) {
            postfix[k++] = ch;
            i++;
        }
        else if (ch == '(') {
            push(&s, ch);
            i++;
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            if (!isEmpty(&s)) pop(&s);
            i++;
        }
        else {
            char op[3] = {ch, '\0', '\0'};
            if (i + 1 < len && (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') && infix[i + 1] == '=') {
                op[1] = '=';
                i++;
            }
            if (isOperator(op)) {
                while (!isEmpty(&s) && peek(&s) != '(') {
                    char topOp[2] = {peek(&s), '\0'};
                    int topPrec = getPrecedence(topOp);
                    int currPrec = getPrecedence(op);

                    if ((topPrec > currPrec) || 
                        (topPrec == currPrec && (strcmp(op, "^") != 0 && strcmp(op, "=") != 0 && 
                         strcmp(op, "+=") != 0 && strcmp(op, "-=") != 0 && strcmp(op, "*=") != 0 && 
                         strcmp(op, "/=") != 0 && strcmp(op, "%=") != 0))) {
                        postfix[k++] = pop(&s);
                    } else {
                        break;
                    }
                }
                for (int j = 0; op[j] != '\0'; j++) push(&s, op[j]);
            }
            i++;
        }
    }

    while (!isEmpty(&s)) {
        if (peek(&s) != '(') {
            postfix[k++] = pop(&s);
        } else {
            pop(&s);
        }
    }
    postfix[k] = '\0';
    return postfix;
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        else if (isOperator((char[]){ch, '\0'})) {
            if (isEmpty(&s)) {
                printf("Invalid postfix expression: stack underflow\n");
                return 0;
            }
            int b = pop(&s) - '0';
            if (isEmpty(&s)) {
                printf("Invalid postfix expression: not enough operands\n");
                return 0;
            }
            int a = pop(&s) - '0';

            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': 
                    if (b == 0) {
                        printf("Division by zero!\n");
                        return 0;
                    }
                    push(&s, a / b); break;
                case '%': push(&s, a % b); break;
                case '^': push(&s, (int)pow(a, b)); break;
                default:
                    printf("Unsupported operator in evaluation: %c\n", ch);
                    return 0;
            }
        }
    }

    if (isEmpty(&s)) {
        printf("Invalid postfix expression: no result\n");
        return 0;
    }
    return pop(&s);
}

//Time complexity of inflix - O(n)
//Time complexity of inflix to postfix - O(n)
//Time complexity to evaluate postfix - O(n)