#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 100

void dfs(int x, int n, int arr[][MAX], bool visit[]);

int main()
{
	int n;
	int arr[MAX][MAX];
	bool visit[MAX] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	dfs(0, n, arr, visit);

	int flag = true;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			flag = false;
			break;
		}
	}

	if (flag) {
		printf("1\n");
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}

void dfs(int x, int n, int arr[][MAX], bool visit[])
{
	visit[x] = true;
	for (int i = 0; i < n; i++)
	{
		if (arr[x][i] && !visit[i])
		{
			dfs(i, n, arr, visit);
		}
	}
}