#include <stdio.h>

typedef struct
{
	int degree;
	int coeff[10];
}Polynomial;

Polynomial addPoly(Polynomial p1, Polynomial p2)
{
	Polynomial result;

	result.degree=(p1.degree>p2.degree)?p1.degree:p2.degree;

	for (int i = 0; i <= result.degree; i++)
	{
		result.coeff[i]=0;
	}
	for (int i = 0; i <= p1.degree; i++)
	{
		result.coeff[i]+=p1.coeff[i];
	}
	for (int i = 0; i <= p2.degree; i++)
	{
		result.coeff[i]+=p2.coeff[i];
	}
	return result;
}

void inputPoly(Polynomial *p)
{
	printf("Enter the degree of the Polynomial : ");
	scanf("%d",&p->degree);

	printf("Enter the coefficients\n");
	for (int i = 0; i <= p->degree; i++)
	{
		printf("Coefficient of x^%d : ", i);
		scanf("%d",&p->coeff[i]);
	}
}

int main(int argc, char const *argv[])
{
	Polynomial p1, p2, result;
	printf("Enter first polynomial:\n");
	inputPoly(&p1);
	printf("Enter second polynomial:\n");
	inputPoly(&p2);
	result=addPoly(p1,p2);

	printf("The resultant polynomial is :\n");
	for(int i = result.degree;i>=0;i--)
	{
		printf("%dx^%d", result.coeff[i],i);
		if(i!=0)
		{
			printf("+");
		}
	}
	return 0;
}