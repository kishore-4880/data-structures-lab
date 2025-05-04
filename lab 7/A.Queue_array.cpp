#include<cstdio>
#include<cstdlib>

//This program will implement various operations of a ADT called Queue using array.

class Queue{
    private:
    int arr[5];
    int front,rear;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    int Enqueue(int);
    int Dequeue();
    int Peek();
};

int main(){
    Queue Q;
    int choice,value,result;
    do{printf("\nMENU\n");
       printf("1.Enqueue\n");
       printf("2.Dequeue\n");
       printf("3.Peek\n");
       printf("4.Exit\n");
       printf("Enter your choice:");
       scanf("%d",&choice);
       switch(choice){
        case 1:
        printf("Enter the value to be inserted:");
        scanf("%d",&value);
        result=Q.Enqueue(value);
        if(result==-1){
            printf("Queue is full.The element cannot not be inserted");
        }
        else{
            printf("Sucessfuly Inserted");
        }
        break;
        case 2:
        result=Q.Dequeue();
        if(result==-1){
            printf("Queue is empty");
        }
        else{
            printf("The removed element is %d",result);
        }
        break;
        case 3:
        result=Q.Peek();
        if(result==-1){
            printf("Queue is empty");
        }
        else{
            printf("The front element of the Queue is %d",result);
        }
        break;
        case 4:
        printf("Exited");
        break;
        default:
        printf("Invalid choice");
    }
     }while(choice!=4);
}
//This function will insert the given element in the queue
int Queue::Enqueue(int value){
    if(rear==4){
        return -1;
    }
    if(front==-1){
        front=0;
    }
    rear+=1;
    arr[rear]=value;
    return 1;
}
//This function will delete the front element in the queue
int Queue::Dequeue(){
    int element=arr[front];
    if(front==-1||front>rear){
        return -1;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=front+1;
    }
    return element;
}
//This function will display the front element of the queue
int Queue::Peek(){
    if(front==-1||front>rear){
        return -1;
    }
    return arr[front];
}