#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
	double coef;
	int degree;
}polynomial;

void print_poly(polynomial p[],int i);

int main()
{
	polynomial pA[MAX];
	polynomial pB[MAX];
	polynomial pC[MAX];
	int sizeA, sizeB;
	scanf(" %d", &sizeA);

	for (int i = 0; i < sizeA; i++)
	{
		scanf(" %lf %d", &pA[i].coef, &pA[i].degree);
	}

	scanf(" %d", &sizeB);
	for (int i = 0; i < sizeB; i++)
	{
		scanf(" %lf %d", &pB[i].coef, &pB[i].degree);
	}

	int ci = 0, ai = 0, bi = 0;
	while (ai < sizeA && bi < sizeB)
	{
		if (pA[ai].degree > pB[bi].degree)
		{
			pC[ci++] = pA[ai++];
		}
		else if (pA[ai].degree < pB[bi].degree)
		{
			pC[ci++] = pB[bi++];
		}
		else if (pA[ai].degree == pB[bi].degree)
		{
			pC[ci].degree = pA[ai].degree;
			pC[ci++].coef = pA[ai++].coef + pB[bi++].coef;
		}
	}
	while (ai < sizeA)
	{
		pC[ci++] = pA[ai++];
	}
	while (bi < sizeB)
	{
		pC[ci++] = pB[bi++];
	}

	print_poly(pA,ai);
	print_poly(pB,bi);
	print_poly(pC, ci);
	return 0;
}

void print_poly(polynomial p[], int i)
{
	for (int j = 0; j < i; j++)
	{
		if (p[j].coef == 0);
		else
		{
			if (p[j].degree == 0) printf("%.2f", p[j].coef);
			else if (p[j].degree == 1) printf("%.2fx", p[j].coef);
			else printf("%.2fx^%d", p[j].coef, p[j].degree);
		}
		if (j + 1 < i && p[j + 1].coef > 0)printf("+");
	}
	printf("\n");
}