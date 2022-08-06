#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	string input;

	getline(cin, input);
	while (input != ".")
	{
		stack<bool> brackets;
		bool cracked = false;
		for (char c : input)
		{
			if (c == '(')
			{
				brackets.push(false);
			}
			else if (c == ')')
			{
				if (!brackets.empty() && brackets.top() == false)
				{
					brackets.pop();
				}
				else
				{
					cracked = true;
					break;
				}
			}
			else if (c == '[')
			{
				brackets.push(true);
			}
			else if (c == ']')
			{
				if (!brackets.empty() && brackets.top() == true)
				{
					brackets.pop();
				}
				else
				{
					cracked = true;
					break;
				}
			}
		}
		if (brackets.empty() && !cracked)
			cout << "yes\n";
		else
			cout << "no\n";

		getline(cin, input);
	}
}