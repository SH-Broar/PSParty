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

	vector<vector<int>> dists;
	dists.resize(n);

	for (auto& v : dists)
	{
		v.resize(n,1000);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			int tmp;
			cin >> tmp;
			if (tmp)
			{
				dists[i][k] = 1;
			}
		}
	}

	for (int mid = 0; mid < n; ++mid)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int k = 0; k < n; ++k)
			{
				dists[i][k] = min(dists[i][k], dists[i][mid] + dists[mid][k]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			if (dists[i][k] == 1000)
				cout << "0 ";
			else
				cout << "1 ";
		}
		cout << "\n";
	}
}