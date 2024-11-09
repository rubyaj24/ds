#include <stdio.h>
#include <stdlib.h>

//FUNCTION PROTOTyPES

void insert(int arr[], int n);
void insertAtBegin(int arr[], int *n, int key);
void insertAtEnd(int arr[], int *n, int key);
void insertAtPos(int arr[], int *n, int key,int value);
int delAtBeg(int arr[], int *n);
int delAtEnd(int arr[], int *n);
int delAtPos(int arr[], int *n, int key);
void display(int arr[], int n);


int main(int argc, char const *argv[])
{
	int n, choice, val, key, pos;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	insert(arr,n);
	printf("Array Saved\n");
	printf("ARRAY OPERATIONS\n");

	printf("1.Insert at the beginning\n");
	printf("2.Insert at the end\n");
	printf("3.Insert after a position\n");
	printf("4.delete from beginning\n");
	printf("5.delete from end\n");
	printf("6.Delete a position\n");
	printf("7.Display all contents\n");
	printf("8.Exit\n");
	while(1){
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		printf("Enter the value:");
		scanf("%d",&val);
		insertAtBegin(arr,&n,val);
		printf("%d inserted at beginning\n",val);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 2:
		printf("Enter the value:");
		scanf("%d",&val);
		insertAtEnd(arr,&n,val);
		printf("%d inserted at the end\n",val);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 3:
		printf("Enter the position:");
		scanf("%d",&pos);
		if(pos>=n){
			printf("Invalid position\n");
			break;
		}
		printf("Enter the value:");
		scanf("%d",&val);
		insertAtPos(arr,&n,pos,val);
		printf("%d inserted at the position %d\n",val, pos);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 4:
		int del = delAtBeg(arr,&n);
		printf("%d deleted from the beginning\n",del);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 5:
		del = delAtEnd(arr,&n);
		printf("%d deleted from the end\n", del);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 6:
		printf("Enter the position:");
		scanf("%d",&pos);
		if(pos>=n){
			printf("Invalid position\n");
			break;
		}
		del = delAtPos(arr,&n,pos);
		printf("%d deleted from position %d\n", del, pos);
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 7:
		printf("saved contents are :[");
		display(arr,n);
		printf("]\n");
		break;
	case 8:
		printf("Exiting...\n");
		exit(0);
	}
}
	return 0;
}

void insert(int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
}

void insertAtBegin(int arr[], int *n, int key){
	for (int i = *n; i>0; i--)
	{
		arr[i]=arr[i-1];
	}
	arr[0] = key;
	(*n)++;
}

void insertAtEnd(int arr[], int *n, int key){
	arr[*n]=key;
	(*n)++;
}
void insertAtPos(int arr[], int *n, int key,int value){
	for (int i = *n; i>key; i--)
	{
		arr[i]=arr[i-1];
	}
	arr[key]=value;
	(*n)++;
}

int delAtBeg(int arr[], int *n){
	int temp=arr[0];
	for(int i = 0; i<*n; i++){
		arr[i]=arr[i+1];
	}
	(*n)--;
	return temp;
}

int delAtEnd(int arr[], int *n){
	int temp=arr[*n];
	(*n)--;
	return temp;
}

int delAtPos(int arr[], int *n, int key){
	int temp = arr[key];
	for (int i = key; i<*n; i++)
	{
		arr[i]=arr[i+1];
	}
	(*n)--;
	return temp;
}

void display(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i] );
	}
}