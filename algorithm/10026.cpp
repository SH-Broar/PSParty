#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

vector<vector<int>> maps;
vector<vector<int>> district;
int dmax;
vector<vector<int>> cdistrict;
int cdmax;

void bfs(int x, int y, int dist, int color)
{
	district[x][y] = dist;

	if (x > 0)
	{
		if (maps[x - 1][y] == color && !district[x-1][y])
		{
			bfs(x - 1, y, dist, color);
		}
	}
	if (y > 0)
	{
		if (maps[x][y-1] == color && !district[x][y-1])
		{
			bfs(x, y-1, dist, color);
		}
	}
	if (x < n - 1)
	{
		if (maps[x+1][y] == color && !district[x +1][y])
		{
			bfs(x + 1, y, dist, color);
		}
	}
	if (y < n - 1)
	{
		if (maps[x][y + 1] == color && !district[x][y + 1])
		{
			bfs(x, y + 1, dist, color);
		}
	}
}

void cbfs(int x, int y, int dist, char color)
{
	cdistrict[x][y] = dist;

	if (x > 0)
	{
		if (((color == 'B' && maps[x - 1][y] == color) || (color != 'B' && maps[x - 1][y] != 'B')) && !cdistrict[x - 1][y])
		{
			cbfs(x - 1, y, dist, color);
		}
	}
	if (y > 0)
	{
		if (((color == 'B' && maps[x][y-1] == color) || (color != 'B' && maps[x][y - 1] != 'B')) && !cdistrict[x][y - 1])
		{
			cbfs(x, y - 1, dist, color);
		}
	}
	if (x < n - 1)
	{
		if (((color == 'B' && maps[x + 1][y] == color) || (color != 'B' && maps[x + 1][y] != 'B')) && !cdistrict[x + 1][y])
		{
			cbfs(x + 1, y, dist, color);
		}
	}
	if (y < n - 1)
	{
		if (((color == 'B' && maps[x ][y+1] == color) || (color != 'B' && maps[x][y+1] != 'B')) && !cdistrict[x][y+1])
		{
			cbfs(x, y + 1, dist, color);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	dmax = 0;
	cdmax = 0;

	maps.resize(n);
	district.resize(n);
	cdistrict.resize(n);
	for (int i = 0; i < n; ++i)
	{
		district[i].resize(n,0);
		cdistrict[i].resize(n,0);
		string str;
		cin >> str;

		for (auto c : str)
		{
			maps[i].push_back(c);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!district[i][j])
			{
				dmax++;
				bfs(i, j, dmax, maps[i][j]);
			}
			if (!cdistrict[i][j])
			{
				cdmax++;
				cbfs(i, j, cdmax, maps[i][j]);
			}
		}
	}

	cout << dmax << " " << cdmax;
}