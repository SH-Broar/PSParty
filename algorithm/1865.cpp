#include <iostream>
#include <vector>
using namespace std;

struct edges
{
	int s;
	int e;
	int t;

	edges(int a, int b, int c)
	{
		s = a;
		e = b;
		t = c;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int TC;
	cin >> TC;
	for (int i = 0; i < TC; ++i)
	{
		int n, m, w;
		cin >> n >> m >> w;

		vector<edges> holes;
		for (int k = 0; k < m; ++k)
		{
			int a, b, c;
			cin >> a >> b >> c;
			holes.emplace_back(a, b, c);
			holes.emplace_back(b, a, c);
		}
		for (int k = 0; k < w; ++k)
		{
			int a, b, c;
			cin >> a >> b >> c;
			holes.emplace_back(a, b, -c);
		}

		vector<int> shortestTable;
		shortestTable.resize(n + 1 , 0);

		shortestTable[0] = 10001;

		bool loop = false;
		for (int k = 1; k <= n; ++k)
		{
			for (auto& e : holes)
			{
				int cur = e.s;
				int next = e.e;
				int cost = e.t;

				if (shortestTable[cur] != 10001 && shortestTable[next] > shortestTable[cur] + cost)
				{
					shortestTable[next] = shortestTable[cur] + cost;
					if (k == n)
					{
						loop = true;
						break;
					}
				}
			}
		}
		if (loop)
			cout << "YES\n";
		else
			cout << "NO\n";


	}
}