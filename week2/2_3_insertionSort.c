#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 1008

int arr[MAX] = { 0 };

void insertionSort(int n)
{
	for (int i = 0; i < n; i++)
	{
		int currentVal = arr[i];
		int insertIdx = i;
		for (int j = i -1; j > -1; j--)
		{
			if (arr[j] > currentVal)
			{
				arr[j + 1] = arr[j];
				insertIdx = j;
			}
			else
				break;
			
		}
		arr[insertIdx] = currentVal;
	}
}

void printArr(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%s", arr[i],(i == n -1)? "" :" ");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &arr[i]);
	}
	insertionSort(2);
	printArr(2);
	printf("\n");
	insertionSort(3);
	printArr(3);
	printf("\n");
	insertionSort(n);
	printArr(n);

	return 0;
}