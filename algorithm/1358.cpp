#include <iostream>
using namespace std;

int W, H, X, Y, P;

bool intersect(int a, int b)
{
	// 직사각형
	if (X <= a && a <= X + W && Y <= b && b <= Y + H)
	{
		return true;
	}

	//왼쪽 원
	int newx = X - a;
	if (newx >= 0)
	{
		int newy = abs(Y + (H / 2) - b);

		if (newx * newx + newy * newy <= (H / 2) * (H / 2))
			return true;
	}

	int mewx = a - (X+W);
	if (mewx >= 0)
	{
		int mewy = abs(Y + (H / 2) - b);

		if (mewx * mewx + mewy * mewy <= (H / 2) * (H / 2))
			return true;
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> W >> H >> X >> Y >> P;

	int total = 0;
	for (int i = 0; i < P; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (intersect(a, b))
		{
			total++;
		}
	}

	cout << total;
}