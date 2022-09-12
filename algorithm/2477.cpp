#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct points
{
	int x;
	int y;
	points(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator==(const points& p)
	{
		if (x == p.x && y == p.y)
			return true;
		else
			return false;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<points> ps;
	int n;
	cin >> n;

	ps.emplace_back(500, 500);
	int taskX = 500;
	int taskY = 500;
	int maxX = 0;
	int maxY = 0;
	int minpX = 10000;
	int minpY = 10000;
	int maxpX = 0;
	int maxpY = 0;
	for (int i = 0; i < 6; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		switch (a)
		{
		case 1:
			taskX += b;
			if (b > maxX)
				maxX = b;
			break;
		case 2:
			taskX -= b;
			if (b > maxX)
				maxX = b;
			break;
		case 3:
			taskY -= b;
			if (b > maxY)
				maxY = b;
			break;
		case 4:
			taskY += b;
			if (b > maxY)
				maxY = b;
			break;
		}
		if (taskX < minpX)
			minpX = taskX;
		if (taskY < minpY)
			minpY = taskY;
		if (taskX > maxpX)
			maxpX = taskX;
		if (taskY > maxpY)
			maxpY = taskY;

		ps.emplace_back(taskX, taskY);


	}
	int total = maxX * maxY;
	auto inner = find_if(ps.begin(), ps.end(), [=](points& p) {
		if (p.x != minpX && p.x != maxpX && p.y != minpY && p.y != maxpY)
			return true;
		else
			return false;
		});
	int innerx = (*inner).x;
	int innery = (*inner).y;

	if (find(ps.begin(), ps.end(), points{ minpX,minpY }) == ps.end())
	{
		cout << n * (total - ((innerx - minpX) * (innery - minpY)));
	}
	else if (find(ps.begin(), ps.end(), points{ minpX,maxpY }) == ps.end())
	{
		cout << n * (total - ((innerx - minpX) * (maxpY - innery)));
	}
	else if (find(ps.begin(), ps.end(), points{ maxpX,maxpY }) == ps.end())
	{
		cout << n * (total - ((maxpX - innerx) * (maxpY - innery)));
	}
	else if (find(ps.begin(), ps.end(), points{ maxpX,minpY }) == ps.end())
	{
		cout << n * (total - ((maxpX - innerx) * (innery - minpY)));
	}
}