#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

struct point
{
	int x;
	int y;
	bool regain = true;

	point(int a, int b, bool r)
	{
		x = a;
		y = b;
		regain = r;
	}
};

vector<vector<int>> protoMap;
array<vector<vector<int>>,2> visitedMap;
queue<point> progress;

int main()
{
	cin.tie(NULL);
	std::cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n,m;
	cin >> n >> m;
	protoMap.resize(n);
	visitedMap[0].resize(n);
	visitedMap[1].resize(n);

	for (int i = 0; i < n; ++i)
	{
		protoMap[i].resize(m);
		visitedMap[0][i].resize(m,-1);
		visitedMap[1][i].resize(m, -1);
		for (int k = 0; k < m; ++k)
		{
			char tmp;
			cin >> tmp;
			protoMap[i][k] = tmp - '0';
		}
	}

	visitedMap[0][0][0] = 1;
	visitedMap[1][0][0] = 1;
	progress.emplace(0, 0,true);

	while (!progress.empty())
	{
		point tmp{0,0,false};
		tmp = progress.front();
		progress.pop();

		int took = 0;
		if (tmp.regain)
		{
			took = 1;
		}

		if (tmp.x > 0)
		{
			if (protoMap[tmp.x - 1][tmp.y] == 0)
			{
				if (visitedMap[took][tmp.x - 1][tmp.y] == -1)
				{
					visitedMap[took][tmp.x - 1][tmp.y] = visitedMap[took][tmp.x][tmp.y] + 1;
					progress.emplace(tmp.x - 1, tmp.y, took);
				}
			}
			else
			{
				if (took)
				{
					if (visitedMap[0][tmp.x - 1][tmp.y] == -1)
					{
						//visitedMap[0][tmp.x][tmp.y] = visitedMap[1][tmp.x][tmp.y];
						visitedMap[0][tmp.x - 1][tmp.y] = visitedMap[1][tmp.x][tmp.y] + 1;
						progress.emplace(tmp.x - 1, tmp.y, 0);
					}
				}
			}
		}

		if (tmp.x < n-1)
		{
			if (protoMap[tmp.x + 1][tmp.y] == 0)
			{
				if (visitedMap[took][tmp.x + 1][tmp.y] == -1)
				{
					visitedMap[took][tmp.x + 1][tmp.y] = visitedMap[took][tmp.x][tmp.y] + 1;
					progress.emplace(tmp.x + 1, tmp.y, took);
				}
			}
			else
			{
				if (took)
				{
					if (visitedMap[0][tmp.x + 1][tmp.y] == -1)
					{
						//visitedMap[0][tmp.x][tmp.y] = visitedMap[1][tmp.x][tmp.y];
						visitedMap[0][tmp.x + 1][tmp.y] = visitedMap[1][tmp.x][tmp.y] + 1;
						progress.emplace(tmp.x + 1, tmp.y, 0);
					}
				}
			}
		}

		if (tmp.y > 0)
		{
			if (protoMap[tmp.x][tmp.y-1] == 0)
			{
				if (visitedMap[took][tmp.x][tmp.y - 1] == -1)
				{
					visitedMap[took][tmp.x][tmp.y - 1] = visitedMap[took][tmp.x][tmp.y] + 1;
					progress.emplace(tmp.x, tmp.y - 1, took);
				}
			}
			else
			{
				if (took)
				{
					if (visitedMap[0][tmp.x][tmp.y - 1] == -1)
					{
						//visitedMap[0][tmp.x][tmp.y] = visitedMap[1][tmp.x][tmp.y];
						visitedMap[0][tmp.x][tmp.y - 1] = visitedMap[1][tmp.x][tmp.y] + 1;
						progress.emplace(tmp.x, tmp.y - 1, 0);
					}
				}
			}
		}

		if (tmp.y < m - 1)
		{
			if (protoMap[tmp.x][tmp.y+1] == 0)
			{
				if (visitedMap[took][tmp.x][tmp.y + 1] == -1)
				{
					visitedMap[took][tmp.x][tmp.y + 1] = visitedMap[took][tmp.x][tmp.y] + 1;
					progress.emplace(tmp.x, tmp.y + 1, took);
				}
			}
			else
			{
				if (took)
				{
					if (visitedMap[0][tmp.x][tmp.y + 1] == -1)
					{
						//visitedMap[0][tmp.x][tmp.y] = visitedMap[1][tmp.x][tmp.y];
						visitedMap[0][tmp.x][tmp.y + 1] = visitedMap[1][tmp.x][tmp.y] + 1;
						progress.emplace(tmp.x, tmp.y + 1, 0);
					}
				}
			}
		}
		
	}


	if (visitedMap[0][n - 1][m - 1] == -1)
		std::cout << visitedMap[1][n-1][m-1];
	else if (visitedMap[1][n - 1][m - 1] == -1)
		std::cout << visitedMap[0][n - 1][m - 1];
	else
		std::cout << min(visitedMap[0][n - 1][m - 1], visitedMap[1][n - 1][m - 1]);
}