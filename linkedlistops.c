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

struct node* insertAtBeg(struct node* head, int data){
	struct node* temp = head;
	struct node* newNode = createNode(data);
	if(temp == NULL){
		head = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
	return head;
}

struct node* insertAtEnd(struct node* head, int data){
	struct node* temp = head;
	struct node* newNode = createNode(data);
	if(temp == NULL){
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

struct node* insertAfterKey(struct node* head, int key, int data){
	struct node* temp = head;
	struct node* newNode = createNode(data);
	if(temp == NULL){
		return insertAtBeg(head,data);
	}
	else{
		while(temp!=NULL){
			if(key == temp->data){
				newNode->next = temp->next;
				temp->next = newNode;
				return head;
			}
			temp = temp->next;
		}
	}
	printf("Key not found\n");
    return head;
}

struct node* deleteBeg(struct node* head){
	if(head == NULL){
		printf("Empty list\n");
		return NULL;
	}
	struct node* temp = head;
	head = head->next;
	free(temp);
	return head;
}

struct node* deleteEnd(struct node* head){
	struct node* temp = head;
	struct node* prev = NULL;
	if(head == NULL){
		printf("Empty list\n");
		return NULL;
	}
	else if(head->next == NULL){
		free(head);
		return NULL;
	}
	else{
		while(temp->next!=NULL){
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
	}
	return head;
}

struct node* deleteKey(struct node* head, int key){
	struct node* temp = head;
	struct node* prev = NULL;
	if(head == NULL){
		printf("Empty list\n");
		return head;
	}
	else if (head->data == key){
		return deleteBeg(head);
	}
	else{
		while(temp->next!=NULL){
			if(key == temp->data){
				prev->next = temp->next;
				free(temp);
				return head;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	printf("Key not found\n");
	return head;

}

void display(struct node* head){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

int main(int argc, char const *argv[])
{
	struct node* head = NULL;
	int choice, key, data;
	printf("LINKED LIST OPERATIONS\n");
	printf("1. Insert at Beginning\n2. Insert at End\n3. Insert after Key\n4.Delete at beginning\n5.Delete from end\n6.Delete a key\n7.Exit\n");
	while(1){
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Insert your data : ");
			scanf("%d",&data);
			head = insertAtBeg(head,data);
			printf("%d inserted at beginning\n", data);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 2:
			printf("Insert your data : ");
			scanf("%d",&data);
			head = insertAtEnd(head,data);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 3:
			printf("insert the key and data ; ");
			scanf("%d%d",&key,&data);
			head = insertAfterKey(head,key,data);
			printf("%d inserted after %d\n", data, key);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 4:
			head = deleteBeg(head);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 5:
			head = deleteEnd(head);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 6:
			printf("Delete the key : ");
			scanf("%d",&key);
			head = deleteKey(head,key);
			printf("Updated lisked list : [");
			display(head);
			printf("]\n");
			break;
		case 7:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice");
			break;
		}
	}
	return 0;
}