#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long fibonacci(int n)
{
	long long f0 = 0, f1 = 1, ans = 0;

	for (int i = 1; i < n; i++)
	{
		ans = f0 + f1;
		f0 = f1;
		f1 = ans;
	}

	return ans;
}

int main()
{
	int n;
	scanf(" %d", &n);
	printf("%lld", fibonacci(n));
	return 0;
}