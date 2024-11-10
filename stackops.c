#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct stack{
    int top;
    char array[MAX];
};

int isEmpty(struct stack* s){
    return s->top == -1;
}

int isFull(struct stack* s){
    return s->top == MAX-1;
}

void push(struct stack* s, char c){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->array[s->top] = c;
}

char pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return '\0';
    }
    char c = s->array[s->top];
    s->top--;
    return c;
}

int main(int argc, char const *argv[])
{
    struct stack s;
    s.top = -1;
    char str[MAX];
    printf("STACK IMPLEMENTATION\n");
    printf("1. Push\n2. Pop\n3. Exit\n4. Display\n");
    int choice;
    while(1){
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the character to push : ");
                char c;
                scanf(" %c",&c);
                push(&s,c);
                break;
            case 2:
                printf("Popped character is : %c\n",pop(&s));
                break;
            case 4:
                exit(0);
            case 3:
                for(int i=0;i<=s.top;i++){
                    printf("%c ",s.array[i]);
                }
                printf("\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


