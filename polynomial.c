#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Polynomial;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Polynomial* p, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (p->head == NULL) {
        p->head = newNode;
    } else {
        Node* temp = p->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void inputPoly(Polynomial* p) {
    p->head = NULL;
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    for (int i = 0; i <= degree; i++) {
        int coeff;
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &coeff);
        insertNode(p, coeff, i);
    }
}

Polynomial addPoly(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.head = NULL;
    Node* temp1 = p1.head;
    Node* temp2 = p2.head;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            insertNode(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp < temp2->exp) {
            insertNode(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            insertNode(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertNode(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertNode(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

Polynomial multiplyPoly(Polynomial p1, Polynomial p2) {
    Polynomial result;
    result.head = NULL;
    Node* temp1 = p1.head;
    Node* temp2 = p2.head;

    while (temp1 != NULL) {
        Polynomial tempResult;
        tempResult.head = NULL;
        temp2 = p2.head;
        while (temp2 != NULL) {
            insertNode(&tempResult, temp1->coeff * temp2->coeff, temp1->exp + temp2->exp);
            temp2 = temp2->next;
        }
        result = addPoly(result, tempResult);
        temp1 = temp1->next;
    }

    return result;
}

void displayPoly(Polynomial p) {
    Node* temp = p.head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freePoly(Polynomial* p) {
    Node* temp = p->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    p->head = NULL;
}

int main(int argc, char const *argv[]) {
    Polynomial p1, p2, sum, product;

    printf("Enter first polynomial:\n");
    inputPoly(&p1);
    printf("Enter second polynomial:\n");
    inputPoly(&p2);

    sum = addPoly(p1, p2);
    product = multiplyPoly(p1, p2);

	printf("The first polynomial is:");
	displayPoly(p1);
	printf("The second polynomial is:");
	displayPoly(p2);
	
    printf("The resultant polynomial after addition is:\n");
    displayPoly(sum);

    printf("The resultant polynomial after multiplication is:\n");
    displayPoly(product);

    freePoly(&p1);
    freePoly(&p2);
    freePoly(&sum);
    freePoly(&product);

    return 0;
}