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

	vector<vector<int>> stackedLines;
	stackedLines.resize(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int tmp;
			cin >> tmp;
			if (i > 0 && j > 0)
			{
				stackedLines[i].push_back(stackedLines[i][j - 1] + stackedLines[i-1][j] - stackedLines[i-1][j - 1] + tmp);
			}
			else if (j > 0)
			{
				stackedLines[i].push_back(stackedLines[i][j - 1] + tmp);
			}
			else if (i > 0)
			{
				stackedLines[i].push_back(stackedLines[i-1][j] + tmp);
			}
			else
			{
				stackedLines[i].push_back(tmp);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int fromx, fromy, tox, toy;
		cin >> fromx >> fromy >> tox >> toy;
		fromx--;
		fromy--;
		tox--;
		toy--;

		if (fromx == 0 && fromy == 0)
		{
			cout << stackedLines[tox][toy] << "\n";
		}
		else if (fromx == 0)
		{
			cout << stackedLines[tox][toy] - stackedLines[tox][fromy - 1] << "\n";
		}
		else if (fromy == 0)
		{
			cout << stackedLines[tox][toy] - stackedLines[fromx -1][toy] << "\n";
		}
		else
		{
			cout << stackedLines[tox][toy] - stackedLines[fromx-1][toy] - stackedLines[tox][fromy-1] + stackedLines[fromx - 1][fromy-1] << "\n";
		}
	}
}