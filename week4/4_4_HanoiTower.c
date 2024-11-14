#pragma warning(disable:4996)
#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n);
	return 0;
}

int hanoi(int n)
{
	if (n > 0)
	{
		hanoi(n - 1);
		printf("%d\n", n);
		hanoi(n - 1);
	}
}
