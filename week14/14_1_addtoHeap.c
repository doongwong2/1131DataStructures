#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, heap[1005], tail = 0, now;

void push()
{
	for (now = ++tail; now != 1 && n < heap[now >> 1];)
	{
		heap[now] = heap[now >> 1];
		now >>= 1;
	}
	heap[now] = n;
}

void print()
{
	for (int i = 1; i <= tail; i++)
		printf("[%d]%d ", i, heap[i]);
	printf("\n");
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		push();
		print();
	}
	return 0;
}