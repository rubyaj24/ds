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

void infixToPostfix(char* infix,char* postfix){
	struct stack* s = createStack();
	int j = 0;
	for(int i = 0; infix[i]; i++){
		if(isOperand(infix[i])){
			postfix[j++] = infix[i];
		}
		else if(isOperator(infix[i])){
			while (!isEmpty(s) && precedence(infix[i])<=precedence(peek(s))){
				postfix[j++] = pop(s);
			}
			push(s,infix[i]);
		}
	}
	while(!isEmpty(s)){
		postfix[j++] = pop(s);
	}
	postfix[j] = '\0';
	free(s);
}

void reverseString(char* str){
	int n = strlen(str);
	for(int i = 0; i<n/2; i++){
		char temp = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = temp;
	}
}

void infixToPrefix(char* infix,char* prefix){
	reverseString(infix);
	char postfix[100];
	infixToPostfix(infix,postfix);
	reverseString(postfix);
	strcpy(prefix,postfix);
}

int main(int argc, char const *argv[])
{
	char infix[100], postfix[100], prefix[100];
	printf("Enter the infix expression : ");
	scanf("%s",infix);
	infixToPostfix(infix,postfix);
	printf("%s\n", postfix);
	printf("\n");
	infixToPrefix(infix,prefix);
	printf("%s\n", prefix);

	return 0;
}