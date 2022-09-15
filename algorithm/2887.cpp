#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct turn
{
	int from;
	int to;

	turn(int a, int b)
	{
		from = a;
		to = b;
	}
};

struct planet
{
	int x;
	int y;
	int z;

	planet(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}
};

int n;

vector<int> parent;

vector<turn> xAxis;
vector<turn> yAxis;
vector<turn> zAxis;
vector<planet> costs;

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

	int total = 0;

	cin >> n;
	parent.resize(n);
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
		int a, b, c;
		cin >> a >> b >> c;

		xAxis.emplace_back(a,i);
		yAxis.emplace_back(b, i);
		zAxis.emplace_back(c, i);
	}

	sort(xAxis.begin(), xAxis.end(), [](turn& x, turn& y)
		{
			if (x.from < y.from)
				return true;
			else if (x.from > y.from)
				return false;
			else if (x.to < y.to)
				return true;
			else
				return false;
		});
	sort(yAxis.begin(), yAxis.end(), [](turn& x, turn& y)
		{
			if (x.from < y.from)
				return true;
			else if (x.from > y.from)
				return false;
			else if (x.to < y.to)
				return true;
			else
				return false;
		});
	sort(zAxis.begin(), zAxis.end(), [](turn& x, turn& y)
		{
			if (x.from < y.from)
				return true;
			else if (x.from > y.from)
				return false;
			else if (x.to < y.to)
				return true;
			else
				return false;
		});
	
	for (int i = 0; i < n - 1; ++i)
	{
		costs.emplace_back(xAxis[i + 1].from - xAxis[i].from, xAxis[i].to, xAxis[i + 1].to);
		costs.emplace_back(yAxis[i + 1].from - yAxis[i].from, yAxis[i].to, yAxis[i + 1].to);
		costs.emplace_back(zAxis[i + 1].from - zAxis[i].from, zAxis[i].to, zAxis[i + 1].to);
	}

	sort(costs.begin(), costs.end(), [](planet& a, planet& b)
		{
			if (a.x < b.x)
				return true;
			else if (a.x > b.x)
				return false;
			else if (a.y < b.y)
				return true;
			else if (a.y > b.y)
				return false;
			else if (a.z < b.z)
				return true;
			else
				return false;
		});

	for (int i = 0; i < costs.size(); ++i)
	{
		if (unions(costs[i].y, costs[i].z))
		{
			total += costs[i].x;
		}
	}

	cout << total;
}