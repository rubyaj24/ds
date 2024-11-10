#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    struct Node* temp = stack->top;
    char popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->top->data;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

void infixToPostfix(char* infix) {
    struct Stack* stack = createStack();
    int i;

    for (i = 0; infix[i]; i++) {
        if (isOperand(infix[i])) {
            printf("%c", infix[i]);
        }
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");
    free(stack);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    printf("Postfix expression: ");
    infixToPostfix(infix);
    return 0;
}