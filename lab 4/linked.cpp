// This code is to show the list ADT in the linked list !!!
#include <iostream>
#include <cstdlib>

class list {
private:
    struct node {
        int data;
        struct node* link;
    };
    struct node* head;

public:
    list() : head(NULL) {}
    int inbeg(int num);
    int inend(int num);
    int inmid(int num, int index);
    int delbeg();
    int delend();
    int delmid(int index);
    int search(int num);
    void revdisplay(node* head);
    void revdisplay();
    int reverse();
    void dis();
};

int main() {
    list linked;
    int num, choice, index, ans;
    while (true) {
        printf("\n MENU \n 1)Insert Beginning \n 2)Insert End \n 3)Insert Position \n 4)Delete Beginning \n 5)Delete End \n 6)Delete Position \n 7)Search \n 8)Display \n 9)Display Reverse  \n 10)Reverse Link \n 11)Exit \n");
        printf("Enter the option :");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the number to be inserted :");
            scanf("%d", &num);
            ans = linked.inbeg(num);
            if (ans == 0) {
                printf("Failed to insert !!\n");
            } else {
                printf("Added !!\n");
            }
            break;

        case 2:
            printf("Enter the number to be inserted :");
            scanf("%d", &num);
            ans = linked.inend(num);
            if (ans == 0) {
                printf("Failed to insert !!\n");
            } else {
                printf("Added !!\n");
            }
            break;

        case 3:
            printf("Enter the index to be inserted :");
            scanf("%d", &index);
            printf("Enter the number to be inserted :");
            scanf("%d", &num);
            ans = linked.inmid(num, index);
            if (ans == 0) {
                printf("Failed to insert !!\n");
            } else {
                printf("Added !!\n");
            }
            break;

        case 4:
            ans = linked.delbeg();
            if (ans == -1) {
                printf("Failed to delete !!\n");
            } else {
                printf("Deleted %d !!\n", ans);
            }
            break;

        case 5:
            ans = linked.delend();
            if (ans == -1) {
                printf("Failed to delete !!\n");
            } else {
                printf("Deleted %d !!\n", ans);
            }
            break;

        case 6:
            printf("Enter the index to be deleted :");
            scanf("%d", &index);
            ans = linked.delmid(index);
            if (ans == -1) {
                printf("Failed to delete !!\n");
            } else {
                printf("Deleted %d !!\n", ans);
            }
            break;

        case 7:
            printf("Enter the number to be searched :");
            scanf("%d", &num);
            ans = linked.search(num);
            if (ans == 0) {
                printf("Number not found !!\n");
            } else {
                printf("The index of the %d is %d \n", num, ans);
            }
            break;

        case 8:
            printf("The list : \n");
            linked.dis();
            break;

        case 9:
            printf("The list printed in the reverse order : \n");
            linked.revdisplay();
            break;

        case 10:
            printf("The list is reversed !!\n");
            linked.reverse();
            break;

        case 11:
            printf("Exiting the loop .....\n");
            break;

        default:
            printf("You have entered the wrong option !!!\n");
        }
        if (choice == 11) {
            break;
        } else {
            continue;
        }
    }

    return 0;
}

//To insert in the beginning
int list::inbeg(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        return 0;
    }
    newnode->data = num;
    newnode->link = head;
    head = newnode;
    return 1;
}

//To insert in the end
int list::inend(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        return 0;
    }
    newnode->data = num;
    newnode->link = NULL;
    if (head == NULL) {
        head = newnode;
        return 1;
    }
    struct node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
    return 1;
}

//To insert in the Position
int list::inmid(int num, int index) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        return 0;
    }
    newnode->data = num;
    newnode->link = NULL;
    if (index == 0) {
        head = newnode;
        return 1;
    }
    struct node* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->link;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    return 1;
}

//To Delete in the beginning
int list::delbeg() {
    if (head == NULL) {
        return -1;
    }
    struct node* temp = head;
    int re = head->data;
    head = head->link;
    free(temp);
    return re;
}

//To Delete in the end
int list::delend() {
    int re;
    if (head == NULL) {
        return -1;
    }
    struct node* temp = head;
    if (head->link == NULL) {
        struct node* temp = head;
        int re = head->data;
        head = head->link;
        free(temp);
        return re;
    }
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    re = temp->link->data;
    temp->link = NULL;
    free(temp->link);
    return re;
}

//To Delete in the position
int list::delmid(int index) {
    if (head == NULL) {
        return -1;
    }
    int re;
    struct node* temp = head;
    if (index == 0) {
        re = head->data;
        head = head->link;
        free(temp);
        return re;
    }
    for (int i = 0; i < index - 1; i++) {
        temp = temp->link;
    }
    struct node* del = temp->link;
    temp->link = (del->link);
    re = del->data;
    free(del);
    return re;
}

//To search the index of the given element
int list::search(int num) {
    struct node* temp = head;
    int i = 0;
    while (temp != NULL) {
        if (temp->data == num) {
            return i;
        }
        temp = temp->link;
        i++;
    }
    return 0;
}

//To reverse print the linked list
void list::revdisplay(node* head) {
    if (head == NULL) return;
    revdisplay(head->link);
    printf("%d ", head->data);
}

void list::revdisplay() {
    revdisplay(head);
}

//To reverse the linked list
int list::reverse() {
    struct node* pre = NULL;
    struct node* cur = head;
    struct node* next = NULL;
    while (cur != NULL) {
        next = cur->link;
        cur->link = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
}

//To print the list
void list::dis() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
