#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 105
bool visited[MAX];

typedef struct node {
	int point;
	struct node* link;
}node;

typedef struct chain {
	node* front, * rear;
}chain;

chain graph[MAX], queue;

node* init_node(int p)
{
	node* tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->point = p;
	tmp->link = NULL;

	return tmp;
}

void linked(int p1, int p2)
{
	node* tmp = init_node(p1);
	if (!graph[p2].front)
	{
		graph[p2].front = graph[p2].rear = tmp;
	}
	else
	{
		graph[p2].rear->link = tmp;
		graph[p2].rear = tmp;
	}
}

void init()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		linked(a, b);
		linked(b, a);
	}
}

void dfs(int u)
{
	visited[u] = true;
	if (u)printf(" ");
	printf("%d", u);

	for (node* v = graph[u].front; v; v = v->link)
	{
		if (!visited[v->point])
		{
			dfs(v->point);
		}
	}
	return;
}

void addqueue(int p)
{
	node* tmp = init_node(p);
	if (!queue.front) queue.front = queue.rear = tmp;
	else
	{
		queue.rear->link = tmp;
		queue.rear = tmp;
	}
}

int popqueue()
{
	int v = queue.front->point;
	node* tmp = queue.front;
	queue.front = queue.front->link;
	free(tmp);
	return v;
}

void bfs(int u)
{
	printf("%d", u);
	visited[u] = true;
	addqueue(u);
	while (queue.front)
	{
		u = popqueue();
		for (node* v = graph[u].front; v; v = v->link)
		{
			if (!visited[v->point])
			{
				printf(" %d", v->point);
				addqueue(v->point);
				visited[v->point] = true;
			}
		}
	}
}

int main()
{
	init();
	memset(visited, false, sizeof(visited));
	printf("Depth First Search:\n");
	dfs(0);
	printf("\n\n");
	memset(visited, false, sizeof(visited));
	printf("Breadth First Search:\n");
	bfs(0);
	printf("\n");
	return 0;
}