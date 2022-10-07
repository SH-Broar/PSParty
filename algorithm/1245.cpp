#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> mountain;
vector<vector<int>> visited;
queue<pair<int, int>> tags;

int bfs()
{
	int ret = 1;
	while (!(tags.empty()))
	{
		auto pos = tags.front();
		visited[pos.first][pos.second] = 1;
		tags.pop();

		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (mountain[pos.first +i][pos.second +j] == mountain[pos.first][pos.second] && !visited[pos.first +i][pos.second +j])
				{
					tags.push({ pos.first +i,pos.second +j});
				}
				else if (mountain[pos.first +i][pos.second+j] > mountain[pos.first][pos.second])
				{
					ret = 0;
				}
			}
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

	mountain.resize(n+2);
	visited.resize(n+2);
	for (int i = 0; i < n+2; ++i)
	{
		mountain[i].resize(m+2);
		visited[i].resize(m+2,0);
	}
		
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k <= m; ++k)
		{
			int t;
			cin >> t;
			mountain[i][k] = t;
		}
	}

	int tops = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k <= m; ++k)
		{
			//0이 아니면 산봉우리인지 확인
			if (mountain[i][k] != 0 && visited[i][k] == 0)
			{
				tags.push({ i,k });
				tops += bfs();
				//if (bfs())
					//cout << i << " " << k << endl;
			}
			else
			{
				visited[i][k] = 1;
			}
		}
	}
	cout << tops;
}