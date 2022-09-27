#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> sets;
vector<string> goal;

bool compare()
{
	bool ret = true;
	for (int i = 0; i < sets.size(); ++i)
	{
		if (sets[i] != goal[i])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		sets.push_back(tmp);
	}
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		goal.push_back(tmp);
	}

	int ret = 0;

	for (int i = 0; i < n - 2; ++i)
	{
		for (int k = 0; k < m - 2; ++k)
		{
			//cout << sets[i][k] << " " << goal[i][k] << endl;
			if (sets[i][k] != goal[i][k])
			{
				for (int t = i; t < i + 3; ++t)
				{
					for (int p = k; p < k + 3; ++p)
					{
						sets[t][p] = sets[t][p] == '0' ? '1' : '0';
					}
				}
				ret++;
			}

		}
	}
	if (compare())
	{
		cout << ret;
	}
	else
		cout << "-1";
}