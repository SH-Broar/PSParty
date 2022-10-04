#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parents;

struct edge
{
	int f;
	int t;
	int cost;

	edge(int a, int b, int c)
	{
		f = a;
		t = b;
		cost = c;
	}
};

int finder(int a)
{
	if (a == parents[a])
		return a;
	else
		return parents[a] = finder(parents[a]);
}


bool unions(auto& e)
{
	int a = finder(e.f);
	int b = finder(e.t);

	if (a == b)
	{
		return false;
	}
	else
	{
		parents[a] = b;
		return true;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	while (true)
	{
		int m, n;
		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		parents.clear();
		for (int i = 0; i < m; ++i)
		{
			parents.push_back(i);
		}

		vector<edge> edges;

		int maxx = 0;
		for (int i = 0; i < n; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			maxx += c;
			edges.emplace_back(a, b, c);
		}

		sort(edges.begin(), edges.end(), [](auto& a, auto& b)
			{
				return a.cost < b.cost;
			});


		int mst = 0;
		for (auto& e : edges)
		{
			if (unions(e))
			{
				mst += e.cost;
			}
		}

		cout << maxx - mst << "\n";
	}
}