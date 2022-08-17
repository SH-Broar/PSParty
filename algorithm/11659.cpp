#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int m;
	cin >> m;

	vector<int> stackedLines;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if (i > 0)
		{
			stackedLines.push_back(stackedLines[i - 1] + tmp);
		}
		else
		{
			stackedLines.push_back(tmp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		if (from == 1)
			cout << stackedLines[to - 1] << "\n";
		else
			cout << stackedLines[to - 1] - stackedLines[from-2] << "\n";
	}
}