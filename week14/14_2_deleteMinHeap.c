#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SWAP(a,b) int tmp = a;\
				a = b;\
				b = tmp;

int n, heap[1005], tail = 0, now, child;

void push()
{
	for (now = ++tail; now != 1 && n < heap[now >> 1];)
	{
		heap[now] = heap[now >> 1];
		now >>= 1;
	}
	heap[now] = n;
}

void pop()
{
	SWAP(heap[tail], heap[1]);
	tail--;
	now = 1;
	child = 2;

	while (child <= tail)
	{
		if (child + 1 <= tail && heap[child] > heap[child + 1]) child++;
		if (heap[now] > heap[child])
		{
			SWAP(heap[now], heap[child]);
			now = child;
			child <<= 1;
		}
		else break;
	}
}

void print()
{
	for (int i = 1; i <= tail; ++i)
		printf("[%d]%d ", i, heap[i]);
	printf("\n");
}

int main()
{
	while (scanf("%d", &n) != EOF) push();
	while (tail)
	{
		print();
		pop();
	}
	return 0;
}