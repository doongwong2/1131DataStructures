#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

string str;
stack <string> stk;

void postfix();
void prefix();

int main()
{
	int x = 3;
	while (x--)
	{
		cin >> str;
		if ((str[0] - '0' >= 0) && (str[1] - '0' < 0))  cout << "same";
		else if ((str[0] - '0' >= 0) && (str[1] - '0' >= 0)) postfix();
		else prefix();
		cout << "\n";
	}

	return 0;
}

void postfix()
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] - '0' >= 0)
			stk.push(string(1,str[i]));
		else
		{
			string b = stk.top();
			stk.pop();
			string a = stk.top();
			stk.pop();
			stk.push("(" + a + str[i] + b + ")");
		}
	}
	for (int i = 1; i < stk.top().size() - 1; i++)cout << stk.top()[i];
}

void prefix()
{
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] - '0' >= 0)
			stk.push(string(1, str[i]));
		else
		{
			string b = stk.top();
			stk.pop();
			string a = stk.top();
			stk.pop();
			stk.push("(" + b + str[i] + a + ")");
		}
	}
	for (int i = 1; i < stk.top().size() - 1; i++)cout << stk.top()[i];
}