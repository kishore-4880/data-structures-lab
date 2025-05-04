#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balance.h"

void clear_invalid_input() {
    if (scanf("%*[^
]")) {
        getchar();
    }
}

int main() {
    int choice;
    char expression[100];

    do {
        clear_invalid_input();
        printf("\nMenu:\n1. Check Balance\n2. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            clear_invalid_input();
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                printf("Enter a string of parentheses: ");
                fgets(expression, sizeof(expression), stdin);
                expression[strcspn(expression, "\n")] = 0;  // Remove newline character
                
                if (isBalanced(expression)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("The parentheses are NOT balanced.\n");
                }
                break;

            case 2:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 2);

    return 0;
}
