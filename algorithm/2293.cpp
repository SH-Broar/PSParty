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
	drops.resize(k + 1,0);
	
	drops[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			if (drops[j - coins[i]])
			{
				drops[j] += drops[j-coins[i]];
			}
		}
	}

	cout << drops[k];
}