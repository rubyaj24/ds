#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(int argc, char const *argv[])
{
    int choice, data;
    struct node* head = NULL;
    printf("INSERTIONAL SORT\n1. Enter the data\n2. Exit\n");
    while(1){
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter your data : ");
            scanf("%d",&data);
            head = insertNode(head,data);
            printf("Updated lisked list : [");
            display(head);
            printf("]\n");
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}