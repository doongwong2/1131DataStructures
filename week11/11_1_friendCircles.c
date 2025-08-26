#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#define MAX (a,b)(((a)>(b))?(a):(b)) wrong way to declare.
#define MAX(a,b) (((a)>(b))?(a):(b))
int arr[1001];

int find(int x)
{
	if (x == arr[x]) return x;
	else return arr[x] = find(arr[x]);
}

void merge(int a, int b)
{
	arr[find(a)] = find(b);
}

int query(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			arr[i] = i;
		}

		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			merge(a, b);
		}
		int num[1001] = { 0 };
		int ans = 0;

		for (int i = 1; i <= n; i++)
		{
			num[find(i)]++;
			ans = MAX(num[find(i)], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}