#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//Josephus problem
typedef struct node {
	int id;
	struct node* nxt;
}node;

node* init_node(int point)
{
	node* p = (node*)malloc(sizeof(node));
	p->id = point;
	p->nxt = NULL;
	return p;
}

node* create_circle(int n, int start) {
	node* head = NULL;
	node* last = NULL;

	for (int i = 0; i < n; i++)
	{
		node* newNode = init_node((start + i - 1) % n + 1);
		if (head == NULL)
		{
			head = newNode;
			last = newNode;
			newNode->nxt = head;
		}
		else
		{
			last->nxt = newNode;
			last = newNode;
			last->nxt = head;
		}
	}
	return head;
}

void solve(node* head, int count)
{
	node* current = head;
	node* previous = NULL;

	while (current->nxt != current)
	{
		for (int i = 0; i < count - 1; i++)
		{
			previous = current;
			current = current->nxt;
		}//this loop will go on for b - 1 times.
		printf("%d ", current->id);
		previous->nxt = current->nxt;
		free(current);
		current = previous->nxt;
	}
	printf("%d\n", current->id);
	free(current);
}

int main()
{
	int n, a, b;
	scanf(" %d %d %d", &n, &a, &b);
	node* head = create_circle(n, a);
	solve(head, b);
	return 0;
}