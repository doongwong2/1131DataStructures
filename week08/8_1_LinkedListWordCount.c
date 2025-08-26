#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char* str;
	int count;
	struct node* nxt;
}listNode;

listNode* create_node(char* str)
{
	listNode* ret = malloc(sizeof(listNode));
	ret->nxt = NULL;
	ret->str = calloc(strlen(str) + 1, sizeof(char));
	strcpy(ret->str, str);
	ret->count = 1;
	return ret;
}

void delete_linkedList(listNode* l)
{
	listNode* cur = l;
	while (cur)
	{
		listNode* temp = cur;
		cur = cur->nxt;
		free(temp);
	}
}

int my_strcmp(char* str1, char* str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (toupper(*str1) != toupper(*str2)) return 0;
		str1++; str2++;
	}
	return *str1 == *str2;
}

void insert_linkedList(listNode* l, int pos, char* str)
{
	listNode* cur = l;
	listNode* i = NULL;
	while (cur)
	{
		if (my_strcmp(str, cur->str))
		{
			cur->count++;
			return;
		}
		if (pos == 0) i = cur;
		pos--;
		cur = cur->nxt;
	}
	if (i)
	{
		listNode* tem = i->nxt;
		i->nxt = create_node(str);
		i->nxt->nxt = tem;
	}
}

void add_linkedList(listNode* l, char* str)
{
	listNode* cur = l;
	while (l)
	{
		if (my_strcmp(str, cur->str))
		{
			cur->count++;
			return;
		}
		if (!cur->nxt)break;
		cur = cur->nxt;
	}
	cur->nxt = create_node(str);
}

void print_linkedList(listNode* l)
{
	listNode* cur = l->nxt;
	while (cur)
	{
		printf("%s, %d\n", cur->str, cur->count);
		cur = cur->nxt;
	}
}

int main()
{
	char buf[128];
	listNode* head = create_node("");
	while (1)
	{
		scanf("%s", buf);
		if (strcmp(buf, "#Finish") == 0) break;
		add_linkedList(head, buf);
	}
	while (1)
	{
		scanf("%s", buf);
		if (strcmp(buf, "#Insert") == 0) 
		{
			int index;
			char tem[128];
			scanf("%d", &index);
			scanf("%s", tem);
			insert_linkedList(head, index ,tem);
		}
		else if (strcmp(buf, "#Add") == 0)
		{
			char tem[128];
			scanf("%s", tem);
			add_linkedList(head, tem);
		}
		else if (strcmp(buf, "#Print") == 0)
		{
			print_linkedList(head);
		}
		else { break; }
	}
	delete_linkedList(head);
	return 0;
}