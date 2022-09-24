#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

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

	bool operator<(const edge& other) const
	{
		return cost < other.cost;
	}
};

vector<int> parent;

int finder(int n)
{
	if (parent[n] == n)
		return n;
	else
		return parent[n] = finder(parent[n]);
}

bool unions(int p, int c)
{
	p = finder(p);
	c = finder(c);

	if (p == c)	// ±ÝÁö
		return false;
	else
	{
		parent[p] = c;
		return true;
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int v, e;
	cin >> v >> e;
	parent.resize(v + 1);
	for (int i = 0; i <= v; ++i)
	{
		parent[i] = i;
	}

	vector<edge> edges;
	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
	}

	int totals = 0;
	int last = 0;
	sort(edges.begin(), edges.end());
	for (auto& e : edges)
	{
		if (unions(e.f, e.t))
		{
			last = e.cost;
			totals += e.cost;
		}
	}

	cout << totals - last;
}