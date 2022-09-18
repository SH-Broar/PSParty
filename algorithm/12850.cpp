#include <iostream>
#include <vector>
using namespace std;

#define defactor 1000000007
#define soongsil 8

vector<vector<long long>> edges;

vector<vector<long long>> operator* (auto& a, auto& b)
{
	vector<vector<long long>> rets;
	rets.resize(soongsil);
	for (auto& v : rets)
		v.resize(soongsil, 0);

	for (int i = 0; i < soongsil; ++i)
	{
		for (int k = 0; k < soongsil; ++k)
		{
			for (int p = 0; p < soongsil; ++p)
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
	rets.resize(soongsil);

	for (int i = 0; i < soongsil; ++i)
	{
		for (int p = 0; p < soongsil; ++p)
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


	edges.resize(soongsil);
	for (auto& v : edges)
		v.resize(soongsil, 0);
	{
		edges[0][1] = 1;
		edges[0][2] = 1;
		edges[1][2] = 1;
		edges[1][3] = 1;
		edges[2][3] = 1;
		edges[2][4] = 1;
		edges[3][4] = 1;
		edges[3][5] = 1;
		edges[4][5] = 1;
		edges[4][6] = 1;
		edges[5][7] = 1;
		edges[6][7] = 1;
		edges[1][0] = 1;
		edges[2][0] = 1;
		edges[2][1] = 1;
		edges[3][1] = 1;
		edges[3][2] = 1;
		edges[4][2] = 1;
		edges[4][3] = 1;
		edges[5][3] = 1;
		edges[5][4] = 1;
		edges[6][4] = 1;
		edges[7][5] = 1;
		edges[7][6] = 1;
	}

	vector<long long> routes{ 1,0,0,0,0,0,0,0 };

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