#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<bool>> computers;
	computers.resize(101);
	for (int i = 0; i < 101; i++)
	{
		computers[i].resize(101);
	}

	int nodes;
	cin >> nodes;

	for (int i = 0; i < nodes; ++i)
	{
		int a, b;
		cin >> a >> b;

		computers[a][b] = true;
		computers[b][a] = true;
	}

	queue<int> checker;
	checker.push(1);

	int result = -1;
	while (!checker.empty())
	{
		int top = checker.front();
		checker.pop();
		
		if (computers[top][top] == false)
		{
			computers[top][top] = true;
			result++;
			for (int i = 1; i < 101; i++)
			{
				if (computers[top][i] == true)
				{
					checker.push(i);
				}
			}
		}
	}

	cout << result;
}