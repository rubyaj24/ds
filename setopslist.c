#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data){
	struct node* newNode = createNode(data);
	struct node* temp = head;
	if(head == NULL){
		head = newNode;
	}
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return head;
}

int contains(struct node* head, int data){
	struct node* temp = head;
	while(temp!=NULL){
		if(temp->data == data)
			return 1;
		temp = temp->next;
	}
	return 0;
}

struct node* setIntersection(struct node* head1, struct node* head2){
	struct node* temp1 = head1;
	struct node* head3 = NULL;
	while(temp1!=NULL){
		if(contains(head2,temp1->data)){
			head3 = insertNode(head3 , temp1->data);
		}
		temp1 = temp1->next;
	}
	return head3;
}

struct node* setDifference(struct node* head1, struct node* head2){
	struct node* temp1 = head1;
	struct node* head3 = NULL;
	while(temp1!=NULL){
		if(!contains(head2,temp1->data)){
			head3 = insertNode(head3 , temp1->data);
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
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
	int data;
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	printf("Enter list 1:\n");
	while((scanf("%d",&data)) && data != -1){
		head1 = insertNode(head1, data);
	}
	display(head1);
	printf("Enter list 2:\n");
	while((scanf("%d",&data)) && data != -1){
		head2 = insertNode(head2, data);
	}
	display(head2);
	printf("Intersection : ");
	display(setIntersection(head1,head2));
	display(setDifference(head1,head2));
	return 0;
}