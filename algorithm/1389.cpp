#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;

	vector<vector<long long>> dists;
	dists.resize(n);
	for (int i = 0; i < n; ++i)
	{
		dists[i].resize(n);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				dists[i][j] = 0ll;
			else
				dists[i][j] = 100000000000000ll;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		dists[a-1][b-1] = 1;
		dists[b-1][a-1] = 1;
	}

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
			}
		}
	}

	long long ret = 1000000000;
	int c = 0;

	for (int i = 0; i < n; ++i)
	{
		long long tmp = accumulate(dists[i].begin(), dists[i].end(),0ll);
		if (tmp < ret)
		{
			ret = tmp;
			c = i + 1;
		}
	}

	cout << c;

}