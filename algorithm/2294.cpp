#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, k;
	cin >> n >> k;
	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		coins.push_back(c);
	}

	vector<int> drops;
	drops.resize(k + 1);
	drops[0] = 0;
	for (int i = 1; i <= k; ++i)
	{
		int m = 10e5;
		for (int j = 0; j < coins.size(); ++j)
		{
			if (i - coins[j] >= 0)
			{
				m = min(m, drops[i-coins[j]]+ 1);
			}
		}
		drops[i] = m;
	}

	if (drops[k] == 10e5)
		cout << "-1";
	else
		cout << drops[k];
}