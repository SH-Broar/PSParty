#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	queue<int> crow;
	vector<int> zone;
	zone.resize(100001, -1);
	crow.push(a);
	zone[a] = 0;

	int resultRange = -1;
	int resultNums = 0;
	while (!crow.empty())
	{
		int top = crow.front();
		crow.pop();
		if (top == b)
		{
			if (resultRange == -1)
			{
				cout << zone[top] << "\n";
				resultRange = zone[top];
				resultNums++;
			}
			else if (zone[top] == resultRange)
			{
				resultNums++;
			}
			continue;
		}

		if (top - 1 >= 0 && (zone[top - 1] == -1 || zone[top-1] == zone[top]+1))
		{
			crow.push(top - 1);
			zone[top - 1] = zone[top] + 1;
		}
		if (top * 2 <= 100000 &&( zone[top * 2] == -1 || zone[top * 2] == zone[top]+1))
		{
			crow.push(top * 2);
			zone[top * 2] = zone[top] + 1;
		}
		if (top + 1 <= 100000 && (zone[top + 1] == -1 || zone[top + 1] == zone[top]+1))
		{
			crow.push(top + 1);
			zone[top + 1] = zone[top] + 1;
		}

	}
	cout << resultNums;
}