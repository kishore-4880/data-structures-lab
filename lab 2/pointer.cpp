#include <iostream>
#include <cmath>
using namespace std;

int length(int *num);
int reverse(int *num);
void palindrome(int *num);
void armstrong(int *num);
void perfect(int *num);

int main()
{
    int *num = (int *)malloc(sizeof(int));
    int *choice = (int *)malloc(sizeof(int));
    int *stop = (int *)calloc(1, sizeof(int));

    while (!(*stop))
    {
        printf("\n\nMENU :");
        printf("\n a. To check whether a number is a palindrome");
        printf("\n b. To check whether a number is an Armstrong number");
        printf("\n c. To check whether a number is a Perfect number");
        printf("\n d. Exit");

        printf("\n\nEnter your choice : ");
        scanf("%c", choice);

        if (*choice == 'a' || *choice == 'b' || *choice == 'c')
        {
            printf("Enter number to check : ");
            scanf("%d", num);
        }

        switch (*choice)
        {
        case 'a':
            palindrome(num);
            break;
        case 'b':
            armstrong(num);
            break;
        case 'c':
            perfect(num);
            break;
        case 'd':
            printf("Exitting Program.");
            *stop = 1;
            break;
        default:
            printf("Invalid Choice.");
            break;
        }
    }
}

int length(int *num)
{
    int *digit = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    while (*temp > 0)
    {
        (*digit)++;
        *temp /= 10;
    }
    free(temp);
    return *digit;
}

int reverse(int *num)
{
    int *rev = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    for (int *i = (int *)calloc(1, sizeof(int)); *i < length(num); (*i)++)
    {
        *rev += (*temp % 10) * pow(10, length(num) - (*i) - 1);
        *temp /= 10;
    }
    free(temp);
    return *rev;
}

void palindrome(int *num)
{
    if (reverse(num) == *num)
    {
        printf("%d is a palindrome.", *num);
    }
    else
    {
        printf("%d is NOT a palindrome.", *num);
    }
}

void armstrong(int *num)
{
    int *sum = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;
    while (*temp)
    {
        *sum += pow(*temp % 10, length(num));
        *temp /= 10;
    }
    if (*num == *sum)
    {
        printf("%d is an Armstrong number.", *num);
    }
    else
    {
        printf("%d is NOT an Armstrong number.", *num);
    }
    free(temp);
    free(sum);
}

void perfect(int *num)
{
    int *sum = (int *)calloc(1, sizeof(int));
    for (int *i = (int *)calloc(1, sizeof(int)); *i <= (*num) / 2; (*i)++)
    {
        if ((*i) != 0)
        {
            if ((*num % *i) == 0)
            {
                *sum += *i;
            }
        }
    }
    if (*num == *sum)
    {
        printf("%d is a Perfect number.", *num);
    }
    else
    {
        printf("%d is NOT a Perfect number.", *num);
    }
    free(sum);
}