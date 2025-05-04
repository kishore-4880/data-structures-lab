//Program to implement List ADT using array of size 5


//Header
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 //Size of the array

//Defining the Class
class ListADT{
    private:
     int list[SIZE]; 
     int count;
    public:
     ListADT() {count = 0;}
     
     void insertBeginning(int value);
     void insertEnd(int value);
     void insertPosition(int pos, int value);
     void deleteBeginning();
     void deleteEnd();
     void deletePosition(int pos);
     void search(int value);
     void display();
     void rotate(int k);
};


// Main function
int main(){
    ListADT lst;
    int choice, value, pos, k;


    while(1){
        printf("\nMenu; \n");
        printf("1. Insert beginning\n");
        printf("2. Insert end\n");
        printf("3. Insert position\n");
        printf("4. Delete beginning\n");
        printf("5. Delete end\n");
        printf("6. Delete position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Rotate\n");
        printf("10. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 10){
            printf("Invalid option. Kindly enter valid option (1-10).");
        }


        switch(choice){
            case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            lst.insertBeginning(value);
            break;

            case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            lst.insertEnd(value);
            break;

            case 3:
            printf("Enter the position: ");
            scanf("%d", &pos);
            printf("Enter the value: ");
            scanf("%d", &value);
            lst.insertPosition(pos, value);
            break;

            case 4:
            lst.deleteBeginning();
            break;

            case 5:
            lst.deleteEnd();
            break;

            case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            lst.deletePosition(pos);
            break;

            case 7:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            lst.search(value);
            break;

            case 8:
            lst.display();
            break;

            case 9:
            printf("Enter how many positions to be rotated: ");
            scanf("%d", &k);
            lst.rotate(k);
            break;

            case 10:
            printf("Exiting the program.\n");
            break;
        }


    }
}

//Function to insert at beginning
void ListADT::insertBeginning(int value){
    if (count == SIZE) {
        printf("List is full!\n");
        return;
    }
    for (int i = count; i > 0; i--) {
        list[i] = list[i - 1];
    }
    list[0] = value;
    count++;
    display();
}


//Function to display the array
void ListADT::display(){
if (count == 0) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}


//Function to insert at end
void ListADT::insertEnd(int value){
    if (count == SIZE) {
        printf("List is full!\n");
        return;
    }
    list[count++] = value;
    display();
}


//Function to insert at a position
void ListADT::insertPosition(int pos, int value){
    if (count == SIZE || pos < 0 || pos > count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = count; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = value;
    count++;
    display();
}


//Function to delete at beginning
void ListADT::deleteBeginning(){
    if (count == 0) {
        printf("List is empty!\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
    display();
}


//Function to delete at end
void ListADT::deleteEnd(){
    if (count == 0) {
        printf("List is empty!\n");
        return;
    }
    count--;
    display();
}


//Function to delete at a position
void ListADT::deletePosition(int pos){
    if (count == 0 || pos < 0 || pos >= count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < count - 1; i++) {
        list[i] = list[i + 1];
    }
    count--;
    display();
}


//Function to seach an element
void ListADT::search(int value){
    for (int i = 0; i < count; i++) {
        if (list[i] == value) {
            printf("Element found at position %d\n", i);
            return;
        }
    }
    printf("Element not found!\n");
}


//Function to rotate the array
void ListADT::rotate(int k){
        if (count == 0) return;
    k = k % count;
    for (int i = 0; i < k; i++) {
        int temp = list[count - 1];
        for (int j = count - 1; j > 0; j--) {
            list[j] = list[j - 1];
        }
        list[0] = temp;
    }
    display();
}

