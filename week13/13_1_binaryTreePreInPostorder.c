#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* treePointer;
struct node
{
	char str[15];
	treePointer left;
	treePointer right;
};

int myMax(int a, int b)
{
	return a > b ? a : b;
}

int findDepth(treePointer now)
{
	if (!now) return 0;
	return myMax(findDepth(now->left), findDepth(now->right)) + 1;
}

void preOrder(treePointer now)
{
	if (now)
	{
		printf("%s ", now->str);
		preOrder(now->left);
		preOrder(now->right);
	}
}

void postOrder(treePointer now)
{
	if (now)
	{
		postOrder(now->left);
		postOrder(now->right);		
		printf("%s ", now->str);
	}
}

void inOrder(treePointer now)
{
	if (now)
	{
		inOrder(now->left);
		printf("%s ", now->str);
		inOrder(now->right);
	}
}

void build(treePointer now, char* parent, char* left, char* right)
{
	if (strcmp(now->str, parent) == 0)
	{
		if (strlen(left))
		{
			now->left = (treePointer)malloc(sizeof(*(now->left)));
			strcpy(now->left->str, left);
			now->left->left = NULL;
			now->left->right = NULL;
		}
		if (strlen(right))
		{
			now->right = (treePointer)malloc(sizeof(*(now->right)));
			strcpy(now->right->str, right);
			now->right->left = NULL;
			now->right->right = NULL;
		}
	}
	else
	{
		if (now->left)
			build(now->left, parent, left, right);
		if (now->right)
			build(now->right, parent, left, right);
	}
}

int main()
{
	char s[50] = { 0 };
	char parent[10] = { 0 };
	char left[10] = { 0 };
	char right[10] = { 0 };
	char son[10] = { 0 };
	int si, parenti, soni;
	treePointer root;
	root = (treePointer)malloc(sizeof(*root));
	strcpy(root->str, "r");
	root->left = NULL;
	root->right = NULL;

	while (gets(s))
	{
		if (s[0] == '0') break;
		for (si = 0, parenti = 0; si < strlen(s); si++, parenti++)
		{
			if (s[si] == ' ')break;
			parent[parenti] = s[si];
		}
		for (si++, soni = 0; si < strlen(s); si++)
		{
			if (s[si] == ' ')
			{
				if ((son[soni - 1] - '0') % 2) strcpy(left, son);
				else strcpy(right, son);
				memset(son, 0, sizeof(son));
				soni = 0;
			}
			else
			{
				son[soni++] = s[si];
			}
		}
		if (soni)
		{
			if ((son[soni - 1] - '0') % 2) strcpy(left, son);
			else strcpy(right, son);
		}
		build(root, parent, left, right);
		memset(parent, 0, sizeof(parent));
		memset(son, 0, sizeof(son));
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
	}
	printf("Preorder: ");
	preOrder(root);
	printf("\nInorder: ");
	inOrder(root);
	printf("\nPostorder: ");
	postOrder(root);
	int leftDepth = findDepth(root->left), rightDepth = findDepth(root->right);
	printf("\nThe balance factor is %d", abs(leftDepth - rightDepth));

	return 0;
}