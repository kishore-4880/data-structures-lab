#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>

class Node
{
 public:
 int data;
 class Node* next=nullptr;
};

class ListADT
{
private:
 Node* head1=nullptr;
 Node* head2=nullptr;
 Node* head3=nullptr;
 Node* gethead(int list)
 {
    if(list==1)
    {
        return(head1);
    }
    else if(list==2)
    {
        return(head2);
    }
 };
 public:
 int Insert_Ascending(int,int);
 int Merge();
 void Display();
 void Delete();
 void Exit();
};

int ListADT::Insert_Ascending(int num,int list)
{
    Node* head=nullptr;
    if(list==1&&head1!=nullptr)
    {
        head=head1;
    }
    else if(list==2 &&head2!=nullptr)
    {
        head=head2;
    }
    Node* curr;
    Node* prev;
    Node* newnode=new Node;
    newnode->data=num;
    newnode->next=nullptr;
    if(head==nullptr)
    {
        head=newnode;
        if(list==1)
        {
            head1=head;
        }
        else if(list==2)
        {
            head2=head;
        }
    }
    else
    {
        if(head->data>num)
        {
            newnode->next=head;
            head=newnode;
            if(list==1)
            {
                head1=head;
            }
            else if(list==2)
            {
                head2=head;
            }
        }
        else
        {
         curr=head;
            while(curr!=nullptr && curr->data <= num)
            {
                prev=curr;
                curr=curr->next;
            }
            if(curr!=nullptr &&curr->data>num)
            {
             newnode->next=curr;
             prev->next=newnode;
            }
            else 
            {
                prev->next=newnode;
            }
            
        }
    }
    return(num);
}

int ListADT::Merge()
{
    int choice;
    Node* temp1;
    Node* temp2;
    Node* temp3=nullptr;
    if(head1==nullptr && head2==nullptr)
    {
        printf("List 1 and List2 are empty\nTry again\n");
        if(head3!=nullptr)
        {
            printf("Although do you want to empty the merged list?\n1.Yes\n2.No\nEnter Your Choice:");
            scanf("%d",&choice);
            if(choice==1)
            {
            Delete();
            printf("Deleted successfully\n");
            }
        }
        return(0);
    }
    else
    {
        temp1=head1;
        temp2=head2;
        if(head3!=nullptr)
        {
            Delete();
        }
        while(temp1!=nullptr && temp2!=nullptr)
        {
                if(head3==nullptr)
                {
                    if(temp1->data<temp2->data)
                    {
                        head3=temp1;
                        temp1=temp1->next;
                        temp3=head3;
                    }
                    else if(temp2->data<temp1->data)
                    {
                        head3=temp2;
                        temp2=temp2->next;
                        temp3=head3;
                    }
                    else if(temp1->data==temp2->data)
                    {
                        head3=temp1;
                        temp1=temp1->next;
                        temp3=head3;
                        temp3->next=temp2;
                        temp2=temp2->next;
                        temp3=temp3->next;
                    }
                    
                }
                else
                {
                    if(temp1->data<temp2->data)
                    {
                        temp3->next=temp1;
                        temp1=temp1->next;
                        temp3=temp3->next;
                    }
                    else if(temp2->data<temp1->data)
                    {
                        temp3->next=temp2;
                        temp2=temp2->next;
                        temp3=temp3->next;
                    }
                    else
                    {
                        temp3->next=temp1;
                        temp1=temp1->next;
                        temp3=temp3->next;
                        temp3->next=temp2;
                        temp2=temp2->next;
                        temp3=temp3->next;
                    }
                }   
        }
        if(temp1==nullptr && temp2!=nullptr)
        {
            temp3->next=temp2;
        }
        else if(temp1!=nullptr && temp2==nullptr)
        {
            temp3->next=temp1;
        }
    }
    head1=nullptr;
    head2=nullptr;
}


void ListADT::Display()
{
    Node* temp;
    if(head1!=nullptr)
    {
    temp=head1;
    printf("List 1:\n");
    while(temp!=nullptr)
    {
     printf("%d ",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else{
        printf("List 1 is Empty\n");
    }
    if(head2!=nullptr)
    {
    temp=head2;
    printf("List 2:\n");
    while(temp!=nullptr)
    {
     printf("%d ",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else
    {
        printf("List 2 is Empty\n");
    }
    if(head3!=nullptr)
    {
    temp=head3;
    printf("List 3:\n");
    while(temp!=nullptr)
    {
     printf("%d ",temp->data);
     temp=temp->next;
    }
    printf("\n");
    }
    else{
        printf("List 3 is Empty\n");
    }
}

void ListADT::Exit()
{
    Node* temp;
    while(head1!=nullptr)
    {
        temp=head1;
        head1=head1->next;
        delete temp;
    }
    while(head2!=nullptr)
    {
        temp=head2;
        head2=head2->next;
        delete temp;
    }
    while(head3!=nullptr)
    {
        temp=head3;
        head3=head3->next;
        delete temp;
    }
    printf("Exiting...\n");
}

void ListADT::Delete()
{
    Node* temp;
    while(head3!=nullptr)
    {
        temp=head3;
        head3=head3->next;
        delete temp;
    }
}