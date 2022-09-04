#include <iostream>
#include <vector>
using namespace std;

#define INF 100000001

vector<vector<int>> maps;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	maps.resize(n);

	for (int i = 0; i < n; ++i)
	{
		maps[i].resize(n, INF);
		maps[i][i] = 0;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a-1][b-1] = min(maps[a-1][b-1], c);
	}

	for (int node = 0; node < n; ++node)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				maps[i][j] = min(maps[i][j], maps[i][node] + maps[node][j]);
			}
		}
	}


	for (auto v : maps)
	{
		for (auto vv : v)
		{
			if (vv == INF)
				cout << 0 << " ";
			else
				cout << vv << " ";
		}
		cout << "\n";
	}
}