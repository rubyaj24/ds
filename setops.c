#include <stdio.h>
#include <stdlib.h>

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

struct node* insert(struct node* head, int data){
    struct node* newNode = createNode(data);
    if (head == NULL){
        head = newNode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

int contains(struct node* head, int data){
    struct node* temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct node* unionset(struct node* head1, struct node* head2){
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* head3 = NULL;

    while(temp1!=NULL){
        if(!contains(head3,temp1->data)){
            head3 = insert(head3,temp1->data);
        }
        temp1= temp1->next;
    }

    while(temp2!=NULL){
        if(!contains(head3,temp2->data)){
            head3 = insert(head3,temp2->data);
        }
        temp2 = temp2->next;
    }
    return head3;
}

struct node* intersection(struct node* head1,struct node* head2){
    struct node* temp1 = head1;
    struct node* head3 = NULL;
    while(temp1!=NULL){
        if(contains(head2,temp1->data)){
            head3 = insert(head3,temp1->data);
        }
        temp1 = temp1->next;
    }
    return head3;
}

struct node* difference(struct node* head1,struct node* head2){
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* head3 = NULL;
    while(temp1!=NULL){
        if(!contains(head2,temp1->data)){
            head3 = insert(head3, temp1->data);
        }
        temp1 = temp1->next;
    }
    return head3;
}


void display(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int data;
    printf("Enter the data for linked list 1(-1 to end):");
    while((scanf("%d",&data))&&data!=-1){
        head1 = insert(head1,data);
    }
    printf("lINKED LIST CREATED\n");
    printf("[");
    display(head1);
    printf("]\n");

    printf("Enter the data for linked list 2(-1 to end):");
    while((scanf("%d",&data))&&data!=-1){
        head2 = insert(head2,data);
    }
    printf("lINKED LIST CREATED\n");
    printf("[");
    display(head2);
    printf("]\n");

    printf("SET OPERATIONS\n");
    printf("1.Union\n");
    printf("2.Intersection\n");
    printf("3.Difference\n");
    printf("4.Exit\n");
    while(1){
        printf("Enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Union of the linked lists is:\n");
                printf("[");
                display(unionset(head1,head2));
                printf("]\n");
                break;
            case 2:
                printf("Intersection of the linked lists is:\n");
                printf("[");
                display(intersection(head1,head2));
                printf("]\n");
                break;
            case 3:
                printf("Difference of the linked lists is:\n");
                printf("[");
                display(difference(head1,head2));
                printf("]\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
