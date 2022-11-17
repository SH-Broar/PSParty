#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> maps;
int totalmax;

void bfs(int a, int b, int deep, int currmax, vector<pair<int,int>> visited)
{
	currmax += maps[a][b];
	visited.push_back(make_pair(a, b));

	if (deep == 4)
	{
		if (currmax > totalmax)
			totalmax = currmax;
		return;
	}

	pair<int, int> p;
	if (a > 0)
	{
		p.first = a-1;
		p.second = b;
		if (find(visited.begin(), visited.end(), p) == visited.end())
		{
			bfs(a - 1, b, deep + 1, currmax, visited);
		}
	}
	if (b > 0)
	{
		p.first = a;
		p.second = b-1;
		if (find(visited.begin(), visited.end(), p) == visited.end())
		{
			bfs(a, b-1, deep + 1, currmax, visited);
		}
	}
	if (a < n - 1)
	{
		p.first = a + 1;
		p.second = b;
		if (find(visited.begin(), visited.end(), p) == visited.end())
		{
			bfs(a + 1, b, deep + 1, currmax, visited);
		}
	}
	if (b < m - 1)
	{
		p.first = a;
		p.second = b+1;
		if (find(visited.begin(), visited.end(), p) == visited.end())
		{
			bfs(a, b +1, deep + 1, currmax, visited);
		}
	}

}

void tags(int a, int b)
{
	if (b > 0 && a < n - 1 && b < m - 1)
	{
		int r = maps[a][b] + maps[a][b - 1] + maps[a + 1][b] + maps[a][b + 1];
		if (r > totalmax)
			totalmax = r;
	}

	if (b > 0 && a > 0 && b < m - 1)
	{
		int r = maps[a][b] + maps[a][b - 1] + maps[a - 1][b] + maps[a][b + 1];
		if (r > totalmax)
			totalmax = r;
	}

	if (a > 0 && b > 0 && a < n - 1)
	{
		int r = maps[a][b] + maps[a][b - 1] + maps[a + 1][b] + maps[a - 1][b];
		if (r > totalmax)
			totalmax = r;
	}

	if (a > 0 && b < m - 1 && a < n - 1)
	{
		int r= maps[a][b] + maps[a][b + 1] + maps[a + 1][b] + maps[a - 1][b];
		if (r > totalmax)
			totalmax = r;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	totalmax = 0;

	cin >> n >> m;
	maps.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < m; ++k)
		{
			int t;
			cin >> t;
			maps[i].push_back(t);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < m; ++k)
		{
			vector<pair<int, int>> vis{};
			bfs(i, k, 1, 0, vis);
			tags(i, k);
		}
	}

	cout << totalmax;
}