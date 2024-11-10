#include <stdio.h>
#include <stdlib.h>

struct node{
	int coeff;
	int exp;
	struct node* next;
};

struct poly{
	struct node* head;
};

struct node* createNode(int coeff, int exp){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL;
	return newNode;
}

void insertNode(struct poly* p,int coeff, int exp){
	struct node* newNode = createNode(coeff, exp);
	if(p->head == NULL){
		p->head = newNode;
	}
	else{
		struct node* temp = p->head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void inputPoly(struct poly* p){
	p->head = NULL;
	int deg;
	printf("Enter the degree of polynomial: ");
	scanf("%d",&deg);
	for(int i = 0; i<=deg; i++){
		int coeff;
		printf("Enter the coeffcient of x^%d: ",i);
		scanf("%d",&coeff);
		insertNode(p, coeff, i);
	}
}

struct poly addPoly(struct poly p1, struct poly p2){
	struct poly result;
	result.head = NULL;
	struct node* temp1 = p1.head;
	struct node* temp2 = p2.head;
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->exp==temp2->exp){
			insertNode(&result,temp1->coeff+temp2->coeff,temp1->exp);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->exp<temp2->exp){
			insertNode(&result,temp1->coeff,temp1->exp);
			temp1 = temp1->next;
		}
		else{
			insertNode(&result,temp2->coeff,temp2->exp);
			temp2 = temp2->next;
		}
	}
	while(temp1!=NULL){
		insertNode(&result,temp1->coeff,temp1->exp);
		temp1 = temp1->next;
	}
	while(temp2!=NULL){
		insertNode(&result,temp2->coeff,temp2->exp);
		temp2 = temp2->next;
	}
	return result;
}

struct poly multiplyPoly(struct poly p1, struct poly p2){
	struct poly result;
	result.head = NULL;
	struct node* temp1 = p1.head;
	struct node* temp2 = p2.head;
	while(temp1!=NULL){
		struct poly tempResult;
		tempResult.head = NULL;
		temp2 = p2.head;
		while(temp2!=NULL){
			insertNode(&tempResult,temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
			temp2 = temp2->next;
		}
		result = addPoly(result,tempResult);
		temp1 = temp1->next;
	}

	return result;
}

void display(struct poly p){
	struct node* temp = p.head;
	while(temp!=NULL){
		printf("%dx^%d",temp->coeff,temp->exp);
		if(temp->next!=NULL){
			printf(" + ");
		}
		temp = temp->next;
	}
}

int main(int argc, char const *argv[])
{
	struct poly p1,p2;
	inputPoly(&p1);
	printf("\nPolynomial 1 is : ");
	display(p1);
	printf("\n");
	inputPoly(&p2);
	printf("\nPolynomial 2 is : ");
	display(p2);
	printf("\n");
	printf("Sum of the polynomials is :\n");
	display(addPoly(p1,p2));
	printf("\n");
	printf("Product of the polynomials is :\n");
	display(multiplyPoly(p1,p2));
	return 0;
}