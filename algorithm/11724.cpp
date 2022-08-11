#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<bool>> computers;
	set<int> checkered;
	computers.resize(n);
	for (int i = 0; i < n; i++)
	{
		computers[i].resize(n);
		checkered.insert(i);
	}
	
	int nodes;
	cin >> nodes;

	for (int i = 0; i < nodes; ++i)
	{
		int a, b;
		cin >> a >> b;

		computers[a-1][b-1] = true;
		computers[b-1][a-1] = true;
	}

	int result = 0;

	while (!checkered.empty())
	{
		queue<int> checker;

		checker.push(*(checkered.begin()));
		while (!checker.empty())
		{
			int top = checker.front();
			checker.pop();

			if (computers[top][top] == false)
			{
				computers[top][top] = true;
				checkered.erase(top);
				for (int i = 0; i < n; i++)
				{
					if (computers[top][i] == true)
					{
						checker.push(i);
					}
				}
			}
		}

		result++;
	}

	cout << result;
}