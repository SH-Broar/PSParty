#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

constexpr long long INF = 10e15;

list<pair<int, int>> lis;

int main()
{
	//freopen("teleport.in1", "rt", stdin);

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m, k;
	cin >> n >> m;
	vector<vector<long long>> graphs;
	map<pair<int, int>, long long> result;

	if (n == 1)
	{
		cout << "1 1";
		return 0;
	}

	graphs.resize(n);
	for (int a = 0; a < n; ++a)
	{
		graphs[a].resize(n, INF);
		for (int b = 0; b < n; ++b)
		{
			if (a == b)
				graphs[a][b] = 0;
			if (a < b)
				lis.push_back({ a,b });
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graphs[a - 1][b - 1] = c;
		graphs[b - 1][a - 1] = c;

	}
	//for (int from = 0; from < n; ++from)
	//{
	//	for (int to = 0; to < n; ++to)
	//	{
	//		cout << graphs[from][to] << " ";
	//	}
	//	cout << endl;
	//}

	for (int mid = 0; mid < n; ++mid)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				graphs[i][j] = min(graphs[i][j], graphs[i][mid] + graphs[mid][j]);
			}
		}
	}

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int f, g, t;
		cin >> f >> g >> t;
		f--; g--;

		for (auto iter = lis.begin(); iter != lis.end();)
		{
			auto tmp = iter;
			int d = graphs[f][g];
			int from = (*iter).first;
			int to = (*iter).second;

			if (d > graphs[f][from] + graphs[to][g])
				d = graphs[f][from] + graphs[to][g];
			if (d > graphs[f][to] + graphs[from][g])
				d = graphs[f][to] + graphs[from][g];

			iter++;
			if (d != t)
			{
				lis.erase(tmp);
			}
		}
	}

	cout << lis.front().first + 1 << " " << lis.front().second + 1;

}