#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graphs;
int n, e;

constexpr auto DIST = 1000000000;

int dijk(int from, int to)
{
	vector<int> costs;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	costs.resize(n,DIST);
	costs[from] = 0;

	pq.emplace(0, from);

	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		for (int i=0;i<n;++i)
		{
			int v = graphs[p.second][i];
			if (v != 0)
			{
				if (costs[i] > p.first + v)
				{
					costs[i] = p.first + v;
					pq.emplace(costs[i],i);
				}
				
			}
		}
	}

	return costs[to];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);



	cin >> n >> e;

	graphs.resize(n);
	for (auto& v : graphs)
		v.resize(n);
	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graphs[a-1][b-1] = c;
		graphs[b - 1][a - 1] = c;
	}

	int point1, point2;
	cin >> point1 >> point2;
	point1--;
	point2--;

	int p1 = dijk(0, point1);
	int p2 = dijk(0, point2);
	int mid = dijk(point1, point2);
	int d1 = dijk(point1, n-1);
	int d2 = dijk(point2, n - 1);

	if (p1 >= DIST || p2 >= DIST || (d1 >= DIST && d2 >= DIST) || mid >= DIST)
		cout << "-1";
	else
		cout << (p1 + d2 > p2 + d1 ? p2 + d1 + mid : p1 + d2 + mid);
}