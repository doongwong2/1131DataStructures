#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 25

int arr[MAX][MAX] = {0};

void magicArr(int n)
{
	//lr = left right, ud = updown;
	int lr = n / 2, ud = 0;
	for (int i = 1; i <= n * n; i++)
	{
		arr[ud][lr] = i;
		int tud, tlr;
		tud = ud -1; tlr = lr + 1;
		if (tud < 0)tud = n -1;
		if (tud == n)tud = 0;
		if (tlr < 0)tlr = n -1;
		if (tlr == n)tlr = 0;

		if (arr[tud][tlr] != 0)
		{
			tud = ud + 1;
			tlr = lr;
			if (tud < 0)tud = n -1;
			if (tud == n)tud = 0;
			if (tlr < 0)tlr = n -1;
			if (tlr == n)tlr = 0;
		}
		ud = tud;
		lr = tlr;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d%s", arr[i][j],(j < n - 1) ?" " : "");
		}
		printf("%s",(i < n-1) ? "\n": "");
	}
}

int main()
{
	int n;
	scanf(" %d", &n);

	magicArr(n);

	return 0;
}