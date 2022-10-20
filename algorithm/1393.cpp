#include <iostream>
using namespace std;

int distanced(int x, int y, int dx, int dy)
{
	return (x - dx) * (x - dx) + (y - dy) * (y - dy);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int sx, sy;
	cin >> sx >> sy;
	int ex, ey, dx, dy;
	cin >> ex >> ey >> dx >> dy;

	if (dx != 0 && dy != 0)
	{
		if (dx % dy)
		{
			dx = dx / abs(dy);
			dy = dy / abs(dy);
		}
		else if (dy % dx)
		{
			dy = dy / abs(dx);
			dx = dx / abs(dx);
		}
	}

	int delta = 0;
	int mindelta = 10e7;
	int rx = ex, ry = ey;
	int prev = -1;
	int now = -1;
	while (true)
	{
		now = distanced(sx, sy, ex, ey);

		delta = prev - now;
		if (prev == -1)
			delta = now;

		if (delta < 0)
			break;

		rx = delta < mindelta ? ex : rx;
		ry = delta < mindelta ? ey : ry;
		mindelta = delta < mindelta ? delta : mindelta;
		prev = now;

		//cout << rx << " " << ry << " ";
		//cout << now << "\n";

		ex += dx;
		ey += dy;
	}
	cout << rx << " " << ry;
}