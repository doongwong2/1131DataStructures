#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

typedef struct {
	double coef;
	int degree;
}terms;

terms a[MAX];
terms b[MAX];
terms c[MAX];

void print(terms a[], int n);

int COMPARE(const void* a, const void* b)
{
	return((terms*)b)->degree - ((terms*)a)->degree;
}

int main()
{
	int m, n, o;
	scanf(" %d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf(" %lf %d", &a[i].coef, &a[i].degree);
	}

	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %lf %d", &b[i].coef, &b[i].degree);
	}

	int ai = 0, bi = 0, ci = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			c[ci].coef = a[i].coef * b[j].coef;
			c[ci++].degree = a[i].degree + b[j].degree;
		}

	qsort(c, ci, sizeof(terms), COMPARE);

	for (int i = 0; i < ci; i++)
	{
		if (c[i].coef == 0.00) continue;
		for (int j = i + 1; j < ci; j++)
		{
			if (c[i].degree == c[j].degree)
			{
				c[i].coef += c[j].coef;
				c[j].degree = 0;
				c[j].coef = 0;
			}
		}
	}

	print(a, m);
	print(b, n);
	print(c, ci);

	return 0;
}

void print(terms p[], int n)
{
	bool isEmpty = true;
	for (int i = 0; i < n; i++)
	{
		if (p[i].coef == 0)
		{
			printf("%s", (p[i + 1].coef > 0 && i < n - 1) ? "+" : "");
			continue;
		}

		isEmpty = false;
		if (p[i].degree == 0) {
			printf("%.2f", p[i].coef);
		}
		else if (p[i].degree == 1) {
			printf("%.2fx", p[i].coef);
		}
		else {
			printf("%.2fx^%d", p[i].coef, p[i].degree);
		}

		printf("%s", (p[i + 1].coef > 0 && i < n - 1) ? "+" : "");
	}
	if (isEmpty)
		printf("0\n");
	else
	{
		printf("\n");
	}

}