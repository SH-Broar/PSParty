#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	stack<int> sck;
	stack<int> mul;
	string str;

	int idx = 0;

	int total = 0;

	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			idx++;
		}
		else if (str[i] == '(')
		{
			sck.push(idx-1);
			mul.push(str[i - 1]-'0');
			idx = 0;
		}
		else if (str[i] == ')')
		{
			idx = idx * mul.top();
			mul.pop();
			idx += sck.top();
			sck.pop();
		}
	}
	cout << idx;
}