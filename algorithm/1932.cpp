#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> table;
	vector<vector<int>> SumTable;

	int n;
	cin >> n;
	table.resize(n);
	SumTable.resize(n);
	for (int i = 0; i < n; ++i)
	{
		table[i].resize(n - i);
		SumTable[i].resize(n - i, 0);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k <= i; ++k)
		{
			int n;
			cin >> n;

			table[i - k][k] = n;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k <= i; ++k)
		{
			if (i == 0 && k == 0)
			{
				SumTable[i - k][k] = table[i - k][k];
			}
			else if (k == 0)
			{
				SumTable[i - k][k] = SumTable[i - k - 1][k] + table[i - k][k];
			}
			else if (k == i)
			{
				SumTable[i - k][k] = SumTable[i - k][k - 1] + table[i - k][k];
			}
			else
			{
				SumTable[i - k][k] = max(SumTable[i - k - 1][k], SumTable[i - k][k - 1]) + table[i - k][k];
			}
		}
	}

	int m = -1;
	for (int k = 1; k <= n; ++k)
	{
		if (m < SumTable[n - k][k - 1])
		{
			m = SumTable[n - k][k - 1];
		}
	}
	cout << m;
}