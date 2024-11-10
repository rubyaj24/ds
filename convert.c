#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node* next; 
};

struct stack{
	struct node* top;
};

struct node* createNode(int data){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct stack* createStack(){
	struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
	stack->top = NULL;
	return stack;
}

int isEmpty(struct stack* stack){
	return stack->top == NULL;
}

void push(struct stack* stack, char data){
	struct node* newNode = createNode(data);
	newNode->next = stack->top;
	stack->top = newNode;
}

char pop(struct stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return '\0';
    }
    struct node* temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

char peek(struct stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return '\0';
    }
    return stack->top->data;
}

int precedence(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int isOperand(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>= '0' && c<= '9');
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void infixToPostfix(char* infix){
	struct stack* s = createStack();
	for(int i = 0; infix[i]; i++){
		if(isOperand(infix[i])){
			printf("%c", infix[i]);
		}
		else if(isOperator(infix[i])){
			while (!isEmpty(s) && precedence(infix[i])<=precedence(peek(s))){
				printf("%c", pop(s));
			}
			push(s,infix[i]);
		}
	}
	while(!isEmpty(s)){
		printf("%c", pop(s));
	}
	printf("\n");
	free(s);
}

int main(int argc, char const *argv[])
{
	char infix[100];
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	infixToPostfix(infix);

	return 0;
}