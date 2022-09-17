#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

constexpr int MAXX = 1000000000;
constexpr int counts = 16;

int n;

vector<vector<int>> travelCost;
vector<vector<int>> routes;

int finder(int from, bitset<counts> visited)
{
	visited.set(from);

	int v = visited.to_ulong();
	//cout << v << " " << ((1 << n) - 1) << endl;

	if (v == (1 << n) - 1)	// ���� �湮��
	{
		//��� ���÷� ���� ��� �ڽ�Ʈ ���
		if (travelCost[from][0] > 0)
			return travelCost[from][0];
		return MAXX;
	}

	if (routes[from][v] > 0)
	{
		//�̹� ����� ���̽��� ����
		return routes[from][v];
	}

	routes[from][v] = MAXX;
	for (int i = 0; i < n; ++i)
	{
		//�湮�� �����̸� �� ��
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
	for (int i = 0; i < n; ++i)
	{
		routes[i].resize((1 << counts));
	}

	for (int i = 0; i < n; ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < n; ++j)
		{
			int c;
			cin >> c;
			tmp.push_back(c);
		}
		travelCost.push_back(tmp);
	}

	cout << finder(0, 0);

}