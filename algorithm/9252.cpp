#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string a, b;
	cin >> a >> b;
	vector<vector<int>> table;
	table.resize(a.size() + 1);
	for (int i = 0; i < a.size() + 1; i++)
	{
		table[i].resize(b.size() + 1, 0);
	}
	for (int i = 1; i <= a.size(); i++)
	{
		for (int k = 1; k <= b.size(); k++)
		{
			if (a[i - 1] == b[k - 1])
			{
				table[i][k] = table[i - 1][k - 1] + 1;
			}
			else
			{
				table[i][k] = max(table[i - 1][k], table[i][k - 1]);
			}
		}
	}

	int tx = a.size(), ty = b.size();
	string newer{};
	while (table[tx][ty])
	{
		if (table[tx][ty] == table[tx - 1][ty])
			tx--;
		else if (table[tx][ty] == table[tx][ty - 1])
			ty--;
		else
		{
			newer = a[tx-1] + newer;
			tx--;
			ty--;
		}
		
	}

	cout << table[a.size()][b.size()];
	cout << (table[a.size()][b.size()] == 0 ? "" : newer);
}