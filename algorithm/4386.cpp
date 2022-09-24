#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge
{
	int f;
	int t;
	float cost;

	edge(int a, int b, float c)
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
vector<pair<float, float>> stars;

float distance(pair<float, float> a, pair<float, float> b)
{
	return sqrt(((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second)));
}

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


	int v;
	cin >> v;
	parent.resize(v + 1);
	for (int i = 0; i <= v; ++i)
	{
		parent[i] = i;
	}

	vector<edge> edges;
	for (int i = 0; i < v; ++i)
	{
		float a, b;
		cin >> a >> b;
		stars.emplace_back(a, b);
		for (int k = i-1; k >= 0; --k)
		{
			//cout << distance(stars[i], stars[k]) << endl;
			edges.emplace_back(i, k, distance(stars[i],stars[k]));
		}

	}

	float totals = 0.f;
	sort(edges.begin(), edges.end());
	for (auto& e : edges)
	{
		if (unions(e.f, e.t))
		{
			totals += e.cost;
		}
	}

	cout << totals;
}