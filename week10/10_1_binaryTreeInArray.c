#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 1<<10

int tree[MAX] = {0};

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int n, root, left, right;
	int last = 1;
	scanf(" %d", &n);
	bool init = true;
	while (scanf("%d", &root) && root != -1)
	{
		if (init)
		{
			tree[1] = root;
			init = false;
		}
		scanf(" %d %d", &left, &right);
		int rootId = 1;
		while (tree[rootId] != root)rootId++;
		tree[rootId * 2] = left;
		tree[rootId * 2 + 1] = right;
		if (left) last = rootId * 2;
		if (right) last = rootId * 2 + 1;
	}

	for (int i = 1; i <= last; i++)
	{
		if (i > 1) printf(" ");
		printf("%d", tree[i]);
	}
	printf("\n");

	return 0;
}
