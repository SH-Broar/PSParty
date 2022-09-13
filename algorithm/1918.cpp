#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string n;
	cin >> n;

	stack<int> opers; // +-*/

	for (auto c : n)
	{
		if (c >= 'A' && c <= 'Z')
		{
			cout << c;
		}
		else if (c == '(')
		{
			opers.push(c);
		}
		else if (c == ')')
		{
			while (opers.top() != '(')
			{
				cout << (char)opers.top();
				opers.pop();
			}
			opers.pop();
		}
		else if (c == '*' || c == '/')
		{
			while (!opers.empty() && opers.top() != '(' && opers.top() != '+' && opers.top() != '-')
			{
				cout << (char)opers.top();
				opers.pop();
			}
			opers.push(c);
		}
		else if (c == '+' || c == '-')
		{
			while (!opers.empty() && opers.top() != '(')
			{
				cout << (char)opers.top();
				opers.pop();
			}
			opers.push(c);
		}

	}
	while (!opers.empty())
	{
		cout << (char)opers.top();
		opers.pop();
	}
}