#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);



	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int n;
		cin >> n;
		
		vector<pair<int, int>> points;
		vector<bool> lines;
		lines.resize(n);

		int xtotal = 0;
		int ytotal = 0;
		for (int x = 0; x < n; ++x)
		{
			int a, b;
			cin >> a >> b;
			points.push_back({ a, b });
			xtotal += a;
			ytotal += b;
		}

		int mag = n / 2;
		long long minner = -1;
		fill(lines.begin(), lines.begin() + mag, true);

		int kos = 1;
		do
		{
			int dataxTotal = 0;
			int datayTotal = 0;

			for (int l = 0; l < lines.size(); ++l)
			{
				if (lines[l])
				{
					dataxTotal += points[l].first;
					datayTotal += points[l].second;
				}
			}

			int rxTotal = xtotal - dataxTotal;
			int ryTotal = ytotal - datayTotal;
			long long tots = pow(dataxTotal - rxTotal, 2) + pow(datayTotal - ryTotal, 2);
			if (tots < minner || minner == -1)
			{
				minner = tots;
			}
			kos++;
			//cout << kos << "\n";
		} while (prev_permutation(lines.begin(), lines.end()));
		
		//cout << kos << endl;
		cout << fixed;
		cout.precision(6);
		cout << sqrt(minner) << "\n";
	}
}