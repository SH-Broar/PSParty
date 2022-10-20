#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<vector<vector<int>>>clears;
	clears.resize(225);
	for (auto& v : clears)
	{
		v.resize(225);
		for (auto& q : v)
		{
			q.resize(225);
		}
	}
	vector<int> qs;
	qs.push_back(4);
	for (int i = 0; i < 225; ++i)
	{
		for (int j = 0; j < 225; ++j)
		{
			for (int k = 0; k < 225; ++k)
			{
				clears[i][j][k] = n - (i * i) - (j  *j) - (k * k);
				if (n - (i * i) - (j * j) - (k * k) == 0)
				{
					int r = 0;
					if (i)
						r++;
					if (j)
						r++;
					if (k)
						r++;
					qs.push_back(r);
				}
			}
		}
	}


	cout << *min_element(qs.begin(), qs.end());
}