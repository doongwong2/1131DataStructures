#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
#define MAX 100

using namespace std;

char input[100];
stack<int> stk;

int main()
{
	fgets(input, MAX, stdin);
	input[strlen(input) - 1] = { 0 };
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ') continue;
		if (input[i] - '0' < 10 && input[i] - '0' > -1)
			stk.push(input[i] - '0');
		else
		{
			int val1 = stk.top();
			stk.pop();
			int val2 = stk.top();
			stk.pop();
			switch (input[i])
			{
			case '+':
				stk.push(val1 + val2);
				break;
			case '-':
				stk.push(val2 - val1);
				break;
			case '*':
				stk.push(val1 * val2);
				break;
			case '/':
				stk.push(val1 / val2);
				break;
			case '%':
				stk.push(val2 % val1);
				break;
			}

		}
	}
	cout << stk.top();
	return 0;
}