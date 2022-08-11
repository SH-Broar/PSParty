#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct point
{
	int x;
	int y;

	point(int a, int b)
	{
		x = a;
		y = b;
	}


	friend bool operator<(point& a, point& b);
};
bool operator<(const point& a, const point& b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> tomatos;
	set<point> noCell;
	tomatos.resize(n);
	for (int i = 0; i < n; i++)
	{
		tomatos[i].resize(m);
	}

	queue<point> toms;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			tomatos[i][j] = t;

			point tmp{ j, i };
			if (t == 1)
			{
				toms.push(tmp);
			}
			else if (t == 0)
			{
				noCell.insert(tmp);
			}
		}
	}

	while (!toms.empty())
	{
		point tmp = toms.front();
		toms.pop();

		if (tmp.x > 0 && tomatos[tmp.y][tmp.x - 1] == 0)
		{
			toms.emplace(tmp.x - 1, tmp.y);
			tomatos[tmp.y][tmp.x - 1] = tomatos[tmp.y][tmp.x] + 1;
			noCell.erase({ tmp.x - 1, tmp.y });
		}
		if (tmp.y > 0 && tomatos[tmp.y - 1][tmp.x] == 0)
		{
			toms.emplace(tmp.x, tmp.y - 1);
			tomatos[tmp.y-1][tmp.x] = tomatos[tmp.y][tmp.x] + 1;
			noCell.erase({ tmp.x, tmp.y -1});
		}
		if (tmp.x < m - 1 && tomatos[tmp.y][tmp.x + 1] == 0)
		{
			toms.emplace(tmp.x + 1, tmp.y);
			tomatos[tmp.y][tmp.x + 1] = tomatos[tmp.y][tmp.x] + 1;
			noCell.erase({ tmp.x + 1, tmp.y });
		}
		if (tmp.y < n - 1 && tomatos[tmp.y + 1][tmp.x] == 0)
		{
			toms.emplace(tmp.x, tmp.y + 1);
			tomatos[tmp.y+1][tmp.x] = tomatos[tmp.y][tmp.x] + 1;
			noCell.erase({ tmp.x, tmp.y +1 });
		}
	}
	if (!noCell.empty())
		cout << "-1";
	else
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tomatos[i][j] > max)
					max = tomatos[i][j];
			}
		}
		cout << max-1;
	}
}