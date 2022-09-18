#include <iostream>
#include <vector>
using namespace std;

#define defactor 1000000007
//#define soongsil 8

int x, y;

vector<vector<long long>> edges;

vector<vector<long long>> operator* (auto& a, auto& b)
{
	vector<vector<long long>> rets;
	rets.resize(x);
	for (auto& v : rets)
		v.resize(x, 0);

	for (int i = 0; i < x; ++i)
	{
		for (int k = 0; k < x; ++k)
		{
			for (int p = 0; p < x; ++p)
			{
				rets[i][k] += (a[i][p]%defactor) * (b[p][k] % defactor);
				rets[i][k] %= defactor;
			}
		}
	}

	return rets;
}

vector<long long> operator* (vector<long long>& a, vector<vector<long long>>& b)
{
	vector<long long> rets;
	rets.resize(x);

	for (int i = 0; i < x; ++i)
	{
		for (int p = 0; p < x; ++p)
		{
			rets[i] += (a[p] % defactor) * (b[p][i] % defactor);
			rets[i] %= defactor;
		}
	}

	return rets;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y;

	edges.resize(x);
	for (auto& v : edges)
		v.resize(x, 0);

	while (y--)
	{
		int f, t;
		cin >> f >> t;
		edges[f-1][t-1] = 1;
		edges[t-1][f-1] = 1;
	}

	vector<long long> routes;
	routes.resize(x,0);
	routes[0] = 1;

	long long n;
	cin >> n;

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			routes = routes * edges;
		}
		edges = edges * edges;
		n /= 2;
	}

	cout << routes[0];
}