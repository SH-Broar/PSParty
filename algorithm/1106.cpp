#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int goal, town;
	cin >> goal >> town;

	vector<pair<int, int>> marketing;

	for (int i = 0; i < town; ++i)
	{
		int a, b;
		cin >> a >> b;
		marketing.emplace_back(a, b);
	}

	vector<int> dps;
	dps.resize(100001);
	for (int i = 0; i < 100001; ++i)
	{
		for (int k = 0; k < town; ++k)
		{
			if (i - marketing[k].first >= 0)
			{
				dps[i] = max(dps[i], dps[i - marketing[k].first] + marketing[k].second);
			}
		}
		if (dps[i] >= goal)
		{
			cout << i;
			break;
		}
	}
}