#include <iostream>
#include <array>
#include <deque>
using namespace std;

struct Point
{
	short x;
	short y;

	Point(int a, int b)
	{
		x = a;
		y = b;
	}
};

array<array<char, 501>, 501> maps{ 0 };
array<array<int, 501>, 501> costs{ };
deque<Point> dq;

void bfs()
{
	int total = 0;
	while (!(dq.empty()))
	{
		auto p = dq.front();
		dq.pop_front();

		if (p.x - 1 >= 0)
		{
			if (maps[p.x - 1][p.y] != -1)
			{
				if (costs[p.x - 1][p.y] > costs[p.x][p.y] + maps[p.x - 1][p.y])
				{
					costs[p.x - 1][p.y] = costs[p.x][p.y] + maps[p.x - 1][p.y];

					if (maps[p.x - 1][p.y])
						dq.emplace_front( p.x - 1, p.y );
					else
						dq.emplace_front(p.x - 1, p.y);
				}
			}
		}
		if (p.y - 1 >= 0)
		{
			if (maps[p.x][p.y-1] != -1)
			{
				if (costs[p.x][p.y - 1] > costs[p.x][p.y] + maps[p.x][p.y - 1])
				{
					costs[p.x][p.y - 1] = costs[p.x][p.y] + maps[p.x][p.y - 1];

					if (maps[p.x][p.y - 1])
						dq.emplace_back(p.x, p.y - 1);
					else
						dq.emplace_front(p.x, p.y - 1);
				}
			}
		}
		if (p.x + 1 <= 500)
		{
			if (maps[p.x + 1][p.y] != -1)
			{
				if (costs[p.x + 1][p.y] > costs[p.x][p.y] + maps[p.x + 1][p.y])
				{
					costs[p.x + 1][p.y] = costs[p.x][p.y] + maps[p.x + 1][p.y];

					if (maps[p.x + 1][p.y])
						dq.emplace_back(p.x + 1, p.y);
					else
						dq.emplace_front(p.x + 1, p.y);
				}
			}
		}
		if (p.y + 1 <= 500)
		{
			if (maps[p.x][p.y + 1] != -1)
			{
				if (costs[p.x][p.y + 1] > costs[p.x][p.y] + maps[p.x][p.y + 1])
				{
					costs[p.x][p.y + 1] = costs[p.x][p.y] + maps[p.x][p.y + 1];

					if (maps[p.x][p.y + 1])
						dq.emplace_back(p.x, p.y + 1);
					else
						dq.emplace_front(p.x, p.y + 1);
				}
			}
		}

	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 501; ++i)
		for (int j = 0; j < 501; ++j)
			costs[i][j] = 1000000;
	costs[0][0] = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
		{
			int t = x1;
			x1 = x2;
			x2 = t;
		}
		if (y1 > y2)
		{
			int t = y1;
			y1 = y2;
			y2 = t;
		}

		for (int x = x1; x <= x2; x++)
		{
			for (int y = y1; y <= y2; y++)
			{
				maps[x][y] = 1;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
		{
			int t = x1;
			x1 = x2;
			x2 = t;
		}
		if (y1 > y2)
		{
			int t = y1;
			y1 = y2;
			y2 = t;
		}

		for (int x = x1; x <= x2; x++)
		{
			for (int y = y1; y <= y2; y++)
			{
				maps[x][y] = -1;
			}
		}
	}
	dq.emplace_back(0, 0);
	bfs();

	if (costs[500][500] == 1000000)
		cout << "-1";
	else
		cout << costs[500][500];
}