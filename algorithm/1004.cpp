#include <iostream>
#include <vector>
using namespace std;

struct Points
{
	int x;
	int y;

	Points(int a, int b)
	{
		x = a;
		y = b;
	}
};

float distance(Points a, Points b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmpx;
		int tmpy;
		cin >> tmpx >> tmpy;
		Points startP{ tmpx, tmpy };

		cin >> tmpx >> tmpy;
		Points endP{ tmpx, tmpy };

		int planet;
		cin >> planet;

		int outs = 0;
		int ins = 0;

		for (int k = 0; k < planet; ++k)
		{
			int px, py, r;
			cin >> px >> py >> r;

			Points planetP{ px,py };
			if (distance(startP, planetP) < r*r)
			{
				outs++;
			}
			if (distance(endP, planetP) < r * r)
			{
				ins++;
			}
			if (distance(startP, planetP) < r * r && distance(endP, planetP) < r * r)
			{
				outs--;
				ins--;
			}
		}
		cout << outs + ins << "\n";
	}
}