#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct queue{
	struct node* front;
	struct node* rear;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct queue* createQueue(){
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int isEmpty(struct queue* q){
	return q->front == NULL;
}

void enqueue(struct queue* q, int data){
	struct node* newNode = createNode(data);
	if(q->rear == NULL){
		q->front = q->rear = newNode;
		return;
	}
	q->rear->next = newNode;
	q->rear = newNode;
}

int dequeue(struct queue* q){
	if(isEmpty(q)){
		return -1;
	}
	struct node* temp = q->front;
	int data = temp->data;
	q->front = q->front->next;
	if(q->front == NULL){
		q->rear = NULL;
	}
	free(temp);
	return data;
}

void display(struct queue* q){
    struct node* temp = q->front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(int argc, char const *argv[])
{
	struct queue* q = createQueue();
	int data, choice;
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	printf("QUEUE OPERATIONS\n");
    printf("1.EN\n");
    printf("2.DE\n");
    printf("3.DIS\n");
    printf("4.Exit\n");
    while(1){
        printf("Enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data:\n");
                scanf("%d",&data);
                enqueue(q,data);
                break;
            case 2:
                data = dequeue(q);
                printf("%d",data);
                break;
            case 3:
                display(q);
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