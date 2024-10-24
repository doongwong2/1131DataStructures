#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 100

typedef struct {
	int row;
	int col;
	int value;
}term;

term matrix[MAX];
term transpose[MAX];
term ans[MAX];

void add(term ans[], int i, int sum, int row, int col)
{
	ans[i].row = row;
	ans[i].col = col;
	ans[i].value = sum;
}

void insertionSort(term matrix[],int n)
{
	for(int i = 0;i < n -1;i++)
		for (int j = i + 1; j >= 0;j--)
		{
			if (matrix[j].row < matrix[j - 1].row || (matrix[j].row == matrix[j - 1].row && matrix[j].col < matrix[j - 1].col))
			{
				term tmp = matrix[j];
				matrix[j] = matrix[j - 1];
				matrix[j - 1] = tmp;
			}
			else break;
		}
}

int main()
{
	int n;
	char c;
	scanf(" %d%c", &n , &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%c%d%c%d%c%c%d%c", &c, &matrix[i].row, &c, &matrix[i].col, &c, &c, &matrix[i].value, &c);
	}

	insertionSort(matrix, n);
	for (int i = 0; i < n; i++)
		transpose[i] = matrix[i];

	int begin = 0;
	int row, col, sum = 0, ai = 0;

	for (int i = 0; i < n;)
	{
		row = matrix[begin].row;
		col = transpose[0].row;

		for (int j = 0; j < n;)
		{
			if (matrix[i].row == row) 
			{
				if (transpose[j].row == col) 
				{
					if (matrix[i].col == transpose[j].col) sum += matrix[i++].value * transpose[j++].value;
					else if (matrix[i].col > transpose[j].col)j++;
					else if (matrix[i].col < transpose[j].col)i++;
				}
				else
				{
					if (sum) add(ans, ai++, sum, row, col);
					sum = 0;
					i = begin;
					col = transpose[j].row;
				}
			}
			else
			{
				i = begin;
				if (sum) add(ans, ai++, sum, row, col);
				sum = 0;
				while (j < n && transpose[j].row == col)j++;
				col = transpose[j].row;
			}
			if (j == n)
			{
				if (sum) add(ans, ai++, sum, row, col);
				sum = 0;
				while (begin < n && matrix[begin].row == row)begin++;
				i = begin;
			}
		}
	}

	for (int i = 0; i < ai; i++)
	{
		printf("%d %d %d\n", ans[i].row, ans[i].col, ans[i].value);
	}

	return 0;
}