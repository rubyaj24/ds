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

struct node* insertNode(struct node* head, int data){
	struct node* newNode = createNode(data);
	if(head == NULL){
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


struct node* reverseNode(struct node* head){
	struct node* prev = NULL;
	struct node* curr = head;
	struct node* next = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

void display(struct node* head){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	int data;
	printf("Enter the elements of the list (-1 to stop) :");
	while((scanf("%d",&data)) && data != -1){
		head = insertNode(head,data);
	}
	display(head);
	head = reverseNode(head);
	display(head);
	return 0;
}