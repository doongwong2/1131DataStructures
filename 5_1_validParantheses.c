#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char s);
void pop();
bool isFull();
bool isEmpty();

int main()
{
	char input[MAX];
	while (scanf(" %s", &input) != EOF)
	{
		if (strcmp(input, "end") == 0) break;
		
		for (int i = 0; input[i] != '\0'; i++)
		{
			if (input[i] == '(') push('(');
			else if (input[i] == ')')
				if(stack[top] == '(')
				{
					pop();
				}
				else
				{
					push(')');
				}
		}

		printf("%d\n", isEmpty() ? 1 : -1);
		
	}

	return 0;
}

void push(char s)
{
	if (isFull())
	{
		return;
	}
	else
	{
		top++;
		stack[top] = s;
	}
}

void pop()
{
	if (isEmpty())
	{
		return;
	}
	top--;
}

bool isFull()
{
	return top >= MAX - 1;
}

bool isEmpty()
{
	return top == -1;
}