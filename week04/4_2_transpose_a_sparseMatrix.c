#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 200

typedef struct {
	int row;
	int col;
	int value;
}term;

term a[MAX];
term b[MAX];

int main()
{
	scanf(" %d %d %d", &a[0].row, &a[0].col, &a[0].value);
	for (int i = 1; i <= a[0].value; i++)
	{
		scanf(" %d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}

	int currentb = 1;
	b[0].row = a[0].col;
	b[0].col = a[0].col;
	b[0].value = a[0].value;

	for (int i = 0; i < a[0].col; i++)
	{
		for (int j = 1; j <= b[0].value; j++)
		{
			if (a[j].col == i)
			{
				b[currentb].row = a[j].col;
				b[currentb].col = a[j].row;
				b[currentb].value = a[j].value;
				currentb++;
			}
		}
	}

	for (int i = 0; i <= b[0].value; i++)
	{
		printf("%d %d %d%s", b[i].row, b[i].col, b[i].value, (i == b[0].value) ? "" : "\n");
	}

	return 0;
}