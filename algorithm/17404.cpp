#include <iostream>
#include <vector>
#include <array>

#define MAXX 100000000

using namespace std;

int mini(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	vector<array<int,3>> houses;

	for (int i = 0; i < n; ++i)
	{
		int r, g, b;
		cin >> r >> g >> b;
		array<int, 3> t{r, g, b};
		houses.push_back(t);
	}

	int ret = MAXX;

	for (int color = 0; color < 3; ++color)
	{
		vector<array<int, 3>> totalCost;
		array<int, 3> t{ houses[0][0], houses[0][1], houses[0][2] };

		for (int c = 0; c < 3; ++c)
		{
			if (color != c)
				t[c] = MAXX;
		}

		totalCost.push_back(t);
		for (int i = 1; i < n; ++i)
		{
			int newR, newG, newB;
			newR = mini(totalCost[i - 1][1], totalCost[i - 1][2]) + houses[i][0];
			newG = mini(totalCost[i - 1][0], totalCost[i - 1][2]) + houses[i][1];
			newB = mini(totalCost[i - 1][0], totalCost[i - 1][1]) + houses[i][2];
			array<int, 3> t{ newR, newG, newB };
			totalCost.push_back(t);
		}

		//for (auto& c : totalCost)
		//{
		//	cout << c[0] << " " << c[1] << " " << c[2] << "\n\n";
		//}

		for (int c = 0; c < 3; ++c)
		{
			//cout << c << " " << color << endl;
			if (c == color)
				continue;
			//cout << c << " " << color << " " << totalCost[totalCost.size() - 1][c] << endl << endl;
			ret = min(ret, totalCost[totalCost.size() - 1][c]);
		}
	}

	cout << ret;
}