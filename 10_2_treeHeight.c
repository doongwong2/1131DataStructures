#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* treePointer;
struct node {
	int key;
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

treePointer modifiedSearch(treePointer root, int k)
{
	if (!root) return root;
	if (k == root->key) return NULL;
	if (k > root->key)
	{
		if (root->right == NULL) return root;
		else return modifiedSearch(root->right, k);
	}
	else
	{
		if (root->left == NULL) return root;
		else return modifiedSearch(root->left,k);
	}
}

void insert(treePointer* root, int k)
{
	treePointer ptr, temp = modifiedSearch(*root, k);
	if (temp || !(*root))
	{
		ptr = (treePointer)malloc(sizeof(*ptr));
		ptr->key = k;
		ptr->left = ptr->right = NULL;
		if (*root)
		{
			if (k < temp->key) temp->left = ptr;
			else temp->right = ptr;
		}
		else
		{
			*root = ptr;
		}
			
	}
}

int main()
{
	int key;
	treePointer root = NULL;
	while (scanf("%d", &key) != EOF)
	{
		insert(&root, key);
	}
	printf("%d", findDepth(root));
}