#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct 
{
	int vertical;
	int horizontal;
}offsets;

offsets move[4];
typedef struct
{
	int row;
	int col;
	int dir;
}element;

element pile[105];
int maze[10][10] = { 0 };
bool visited[10][10] = { 0 };

element pop(int* top)
{
	element now = pile[(*top)--];
	return now;
}

void push(int* top, element pos)
{
	pile[++(*top)] = pos;
}

void path()
{
	element pos, next;
	visited[8][8] = true;
	int top = 0;
	pile[0].row = pile[0].col = 8;
	pile[0].dir = next.dir = 0;

	while (top > -1 && !visited[1][1])
	{
		pos = pop(&top);
		while (pos.dir < 4 && !visited[1][1])
		{
			next.row = pos.row + move[pos.dir].vertical;
			next.col = pos.col + move[pos.dir].horizontal;
			if (!maze[next.row][next.col] && !visited[next.row][next.col])
			{
				visited[next.row][next.col] = true;
				pos.dir++;
				push(&top, pos);
				pos = next;
			}
			else pos.dir++;
		}
	}
}

void print()
{
	printf("%s", (visited[1][1]) ? "YES\n" : "NO\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 1 && j == 1) printf("X");
			else if (i == 8 && j == 8) printf("S");
			else printf("%c", (visited[i][j]) ? 'G' : '0' + maze[i][j]);
			printf("%c", j + 1 == 10 ? '\n' : ' ');
		}
	}
}

void init_move()
{
	move[0].vertical = move[2].vertical = 0;
	move[1].horizontal = move[3].horizontal = 0;
	move[0].horizontal = move[3].vertical = 1;
	move[1].vertical = move[2].horizontal = -1;
}

void init_maze()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			scanf(" %d", &maze[i][j]);
		}
	}
}

int main()
{
	init_maze();
	init_move();
	path();
	print();
	return 0;
}