#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<char, int>>> graphs;
vector<int> costs;
priority_queue<pair<int, short>, vector<pair<int, short>>, greater<>> nexter;

#define DIST 1000000000

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;
	graphs.resize(v);
	costs.resize(v, DIST);

	int start;
	cin >> start;
	costs[start - 1] = 0;

	for (int i = 0; i < e; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a = a - 1;
		b = b - 1;
		graphs[a].emplace_back(c, b);

	}

	nexter.push({ 0, start - 1 });
	costs[start - 1] = 0;

	while (!nexter.empty())
	{
		auto& p = nexter.top();
		int first = p.first;
		int second = p.second;
		nexter.pop();

		if (costs[second] < first)
			continue;

		//cout << p.first << " " << p.second << endl;

		for (auto& i : graphs[second])
		{
			char far = i.first;
			int nnode = i.second;
			//cout << first << " " << second << " " << costs[i] << " " << first + graphs[second][i] << endl;
			
			if (costs[nnode] > first + far)
			{
				costs[nnode] = first + far;
				nexter.push({ first + far, nnode });
			}
		}
	}
	//cout << "m" << endl;
	for (auto i = 0; i < costs.size(); i++)
	{
		if (costs[i] == DIST)
			cout << "INF\n";
		else
			cout << costs[i] << "\n";
	}


}