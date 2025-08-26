#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node* treePtr;
struct node {
	int key;
	treePtr left;
	treePtr right;
};

treePtr modifiedSearch(treePtr root, int k)
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
		else return modifiedSearch(root->left, k);
	}
}

void insert(treePtr *root, int k)
{
	treePtr ptr, temp = modifiedSearch(*root, k);
	if (temp || !(*root))
	{
		ptr = (treePtr)malloc(sizeof(*ptr));
		ptr->key = k;
		ptr->left = ptr->right = NULL;
		if (*root)
		{
			if (k < temp->key) temp->left = ptr;
			else temp->right = ptr;
		}
		else
			*root = ptr;
	}
}

void preOrder(treePtr ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->key);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

treePtr search(treePtr root, int k)
{
	if (!root) return NULL;
	if (root->key == k) return root;
	if (root->key > k)
		return search(root->left, k);
	else
		return search(root->right, k);
}

treePtr searchParent(treePtr root, int k)
{
	if (root->key == k) return NULL;
	if(((root->left) &&(root->left->key == k)) || ((root->right) && (root->right->key == k))) return root;
	if (root->key > k)
		return searchParent(root->left, k);
	else
		return searchParent(root->right, k);
}

int findLeftMax(treePtr root)
{
	if (!(root->right)) return root->key;
	else return findLeftMax(root->right);
}

void delete(treePtr root, int k)
{
	treePtr target = search(root, k);
	if (!target) printf("no %d\n", k);
	else 
	{
		treePtr parent = searchParent(root, k);
		if (!parent) parent = root;
		if (!(target->left) && !(target->right))
		{
			if (parent->left && parent->left->key == k) parent->left = NULL;
			else parent->right = NULL;
		}
		else if (!(target->left))
		{
			if ((parent->left) && parent->left->key == k) parent->left = target->right;
			else parent->right = target->right;
		}
		else if (!(target->right))
		{
			if (parent->left && parent->left->key == k) parent->left = target->left;
			else parent->right = target->left;
		}
		else
		{
			int max = findLeftMax(target->left);
			delete(root, max);
			target->key = max;
		}
	}
}

int main()
{
	int key;
	char c;
	treePtr root = NULL;
	while (scanf("%d%c", &key, &c))
	{
		insert(&root, key);
		if (c == '\n') break;
	}
	printf("Binary search tree (before):\n");
	preOrder(root);
	printf("\n");
	while (scanf("%d%c", &key, &c))
	{
		delete(root, key);
		if (c == '\n') break;
	}
	printf("Binary search tree (after):\n");
	preOrder(root);

	return 0;
}