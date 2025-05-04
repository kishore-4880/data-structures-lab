//program to sort the elements of given array

#include <stdio.h>

//function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void displayArray(int arr[], int n);

int main(){
    int arr[50], n, choice;

        do{
         printf("\nMenu: \n");
         printf("1. Bubble sort\n");
         printf("2. Selection sort\n");
         printf("3. Insertion sort\n");
         printf("4. Exit\n");
         printf("Enter your choice: \n");
         scanf("%d", &choice);

             if(choice == 4) {
             printf("Exiting the program");
             break;
         }

             if(choice < 1 || choice > 4){
             printf("Invalid choice. Kindly re-enter your choice");
            continue;
         }

          printf("Enter the size of array: \n");
          scanf("%d", &n);

              if( n <= 1 || n > 50){
             printf("Kindly enter valid no. of elements (1-50).");
             continue;
         }

             printf("Enter the elements: \n");
             for(int i = 0; i < n; i++){
             scanf("%d", &arr[i]);
             }
             
         switch(choice){
         case 1:
         bubbleSort(arr, n);
         break;
        
         case 2:
         selectionSort(arr, n);
         break;

         case 3:
         insertionSort(arr, n);
         break;

         


         }

         printf("Sorted Array: \n");
         displayArray(arr, n);

         
        }while(choice != 4);
        
        return 0;
}

 
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
 }

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j = 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
