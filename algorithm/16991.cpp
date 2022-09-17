#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

constexpr double MAXX = 20000000;
constexpr int counts = 16;

int n;

vector<vector<double>> travelCost;
vector<vector<double>> routes;

double dist(double a, double b, double x, double y)
{
	return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}

double finder(int from, bitset<counts> visited)
{
	visited.set(from);

	int v = visited.to_ulong();
	//cout << v << " " << ((1 << n) - 1) << endl;

	if (v == (1 << n) - 1)	// 전부 방문함
	{
		//출발 도시로 가는 경로 코스트 출력
		if (travelCost[from][0] > 0)
			return travelCost[from][0];
		return MAXX;
	}

	if (routes[from][v] > 0)
	{
		//이미 계산한 케이스면 퇴장
		return routes[from][v];
	}

	routes[from][v] = MAXX;
	for (int i = 0; i < n; ++i)
	{
		//방문한 정점이면 안 감
		if (visited.test(i) || i == from)
			continue;

		if (travelCost[from][i] > 0)
		{
			routes[from][v] = min(routes[from][v], finder(i, visited) + travelCost[from][i]);
		}
	}

	return routes[from][v];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	routes.resize(n);
	travelCost.resize(n);
	for (int i = 0; i < n; ++i)
	{
		travelCost[i].resize(n);
		routes[i].resize((1 << counts));
	}

	vector<pair<double, double>> points;
	for (int i = 0; i < n; ++i)
	{
		double a, b;
		cin >> a >> b;

		points.emplace_back(a, b);

		for (int j = 0; j < i; ++j)
		{
			travelCost[i][j] = dist(points[j].first, points[j].second, points[i].first, points[i].second);
			travelCost[j][i] = travelCost[i][j];
		}
	}

	cout << fixed;
	cout.precision(6);
	cout << finder(0, 0);

}