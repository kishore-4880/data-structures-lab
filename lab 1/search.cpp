//program to search for an element in an array

#include <stdio.h>
#include "sort.h"

// Function declaration
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);

int main() {
    int n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int target;
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                int result = linearSearch(arr, n, target);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 2: {
                insertionSort(arr, n); // Sorting before binary search
                printf("Array sorted before Binary Search: ");
                displayArray(arr, n);

                int target;
                printf("Enter the element to search for: ");
                scanf("%d", &target);
                int result = binarySearch(arr, n, target);
                if (result != -1) {
                    printf("Element found at index: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Linear Search implementation
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search implementation
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

