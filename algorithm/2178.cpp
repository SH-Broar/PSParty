#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<vector<int>>maps;
vector<vector<int>>dists;

void bfs(int a, int b, int dist)
{

	dists[a][b] = dist;
	
	if (a > 0 && maps[a - 1][b])
	{
		if (dists[a - 1][b] > dist + 1)
		{
			bfs(a - 1, b, dist + 1);
		}
	}
	
	if (b > 0 && maps[a][b-1])
	{
		if (dists[a][b-1] > dist + 1)
		{
			bfs(a, b-1, dist + 1);
		}
	}
	
	if (a < n-1 && maps[a + 1][b])
	{
		if (dists[a + 1][b] > dist + 1)
		{
			bfs(a + 1, b, dist + 1);
		}
	}
	if (b < m-1 && maps[a][b+1])
	{
		if (dists[a][b+1] > dist + 1)
		{
			bfs(a, b + 1, dist + 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	maps.resize(n);
	dists.resize(n);

	for (auto& v : dists)
		v.resize(m,100000);

	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		for (auto c : tmp)
		{
			maps[i].push_back(c - '0');
		}
	}

	bfs(0, 0, 1);
	cout << dists[n - 1][m - 1];
}