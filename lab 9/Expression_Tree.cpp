#include <iostream>
#include <string.h>
#include "Q4.h"
using namespace std;

int main()
{
    int choice;
    Tree tree;
    string input;
    while (true)
    {
        printf("\n\nMENU :\n 1. Get Postfix\n 2. Construct Tree\n 3. Display Prefix\n 4. Display Infix\n 5. Display Postfix\n 6. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        if (choice == 6)
        {
            printf("Exitting code.\n");
            break;
        }
        else if (choice > 6 || choice < 1)
        {
            printf("Invalid choice. Enter again.\n");
        }
        else if (choice == 1)
        {
            char buffer[100];
            printf("Enter a valid postfix expression : ");
            scanf("%s", buffer);
            input = buffer;
        }
        else
        {
            if (input.empty())
            {
                printf("No expression entered. Please enter a valid postfix expression to proceed.\n");
            }
            else
            {
                switch (choice)
                {
                case 2:
                    tree.constructTree(input);
                    printf("Tree constructed.\n");
                    break;

                case 3:
                    tree.preorder(tree.getRoot());
                    break;

                case 4:
                    tree.inorder(tree.getRoot());
                    break;

                case 5:
                    tree.postorder(tree.getRoot());
                    break;
                }
            }
        }
    }
}