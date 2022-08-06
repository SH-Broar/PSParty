#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	stack<int> sta;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			sta.pop();
		}
		else
		{
			sta.push(input);
		}
	}

	int result = 0;
	while (!sta.empty())
	{
		result += sta.top();
		sta.pop();
	}
	cout << result;
}