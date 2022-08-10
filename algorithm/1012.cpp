#include <iostream>
#include <queue>
#include <array>
using namespace std;

struct pos
{
	int x;
	int y;

	pos(int a, int b)
	{
		x = a;
		y = b;
	}
};

void paint(array<array<int, 50>, 50>& stage, queue<pos>& finder);

int result = 0;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int x, y, b;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		array<array<int, 50>, 50> stage{};
		queue<pos> finder;
		result = 0;
		cin >> x >> y >> b;
		
		int tmpx;
		int tmpy;
		for (int k = 0; k < b; ++k)
		{
			cin >> tmpx >> tmpy;
			stage[tmpx][tmpy] = 1;
		}

		for (int rollX = 0; rollX < x; rollX++)
		{
			for (int rollY = 0; rollY < y; rollY++)
			{
				if (stage[rollX][rollY] == 1)
				{
					finder.emplace(rollX,rollY);

					paint(stage, finder);
				}
			}
		}
		cout << result << "\n";

	}
}

void paint(array<array<int, 50>, 50>& stage, queue<pos>& finder)
{
	while (!finder.empty())
	{
		pos catcher = finder.front();
		finder.pop();

		if (stage[catcher.x][catcher.y] == 1)
		{
			stage[catcher.x][catcher.y] = 2;

			if (catcher.x-1 >= 0 && stage[catcher.x-1][catcher.y] == 1)
				finder.emplace(catcher.x-1, catcher.y);

			if (catcher.x + 1 < 50 && stage[catcher.x + 1][catcher.y] == 1)
				finder.emplace(catcher.x+1, catcher.y);

			if (catcher.y - 1 >= 0 && stage[catcher.x][catcher.y - 1] == 1)
				finder.emplace(catcher.x, catcher.y-1);

			if (catcher.y + 1 < 50 && stage[catcher.x][catcher.y+1] == 1)
				finder.emplace(catcher.x, catcher.y+1);
		}
	}
	result++;
}