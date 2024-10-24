#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef enum {lparen = 0, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
int stack[MAX] = {0};
char expr[MAX] = {0};

precedence get_token(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(':	return lparen;
	case ')':	return rparen;
	case '+':	return plus;
	case '-':	return minus;
	case '/':	return divide;
	case '*':	return times;
	case '%':	return mod;
	case '\0':	return eos;
	default:	return operand;
	}
}

void print_token(precedence token)
{
	switch (token)
	{
	case lparen:	printf(" ("); break;
	case rparen:	printf(" )"); break;
	case plus:		printf(" +"); break;
	case minus:		printf(" -"); break;
	case divide:	printf(" /"); break;
	case times:		printf(" *"); break;
	case mod:		printf(" %%"); break;
	}
}

precedence pop(int* top)
{
	precedence ret = stack[*top];
	stack[*top] = 0;
	(*top)--;
	return ret;
}

void push(int* top, precedence token)
{
	stack[++(*top)] = token;
}

void postfix()
{
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;
	int isp[] = { 0,19,12,12,13,13,13,0 };
	int icp[] = { 20,19,12,12,13,13,13,0 };
	int fir = 1;
	stack[0] = eos;
	for (token = get_token(&symbol, &n); token != eos; token = get_token(&symbol, &n))
	{
		if (token == operand)
		{
			if (!fir) printf(" ");
			else fir = 0;
			printf("%c", symbol);
		}
		else if (token == rparen)
		{
			while (stack[top] != lparen)
			{
				print_token(pop(&top));

			}
			pop(&top);
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
				print_token(pop(&top));
			push(&top,token);
		}
	}
	while ((token = pop(&top)) != eos)
		print_token(token);
}


int main()
{
	int n;
	char c, input[100] = { 0 };
	scanf(" %d", &n);
	scanf("%c", &c);
	for (int i = 0; i < n; i++)
	{
		if (i) printf("\n");
		gets(input);
		int expri = 0;
		for (int j = 0; j < strlen(input); j++)
		{
			if (input[j] != ' ') {
				expr[expri] = input[i];
				expri++;
			}
		}
		expr[expri] = '\0';
		postfix();
	}
	return 0;
}