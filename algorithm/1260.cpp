#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> edges;
	edges.resize(n);
	for (auto& e : edges)
		e.resize(n);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1][b - 1] = 1;
		edges[b - 1][a - 1] = 1;
	}
	
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << edges[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//dfs
	{
		stack<int> remains;
		vector<int> visited;
		visited.resize(n,0);
		remains.push(v-1);

		while (!remains.empty())
		{
			int t = remains.top();
			remains.pop();

			if (visited[t] != 0)
				continue;

			cout << t+1 << " ";
			visited[t] = 1;

			for (int tmp = n-1; tmp>= 0; --tmp)
			{
				if (edges[t][tmp] && !visited[tmp])
					remains.push(tmp);
			}

		}
	}
	cout << "\n";

	//bfs
	{
		queue<int> remains;
		vector<int> visited;
		visited.resize(n, 0);
		remains.push(v - 1);

		while (!remains.empty())
		{
			int t = remains.front();
			remains.pop();

			if (visited[t] != 0)
				continue;

			cout << t + 1 << " ";
			visited[t] = 1;

			for (int tmp = 0; tmp < n; ++tmp)
			{
				if (edges[t][tmp] && !visited[tmp])
					remains.push(tmp);
			}

		}
	}
}