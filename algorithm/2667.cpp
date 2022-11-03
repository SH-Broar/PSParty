#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> maps;
vector<vector<int>> dongs;
vector<int> maxx;
int n;
int counter = 0;

int spread(int i, int k, int counts)
{
	if (dongs[i][k])
	{
		return dongs[i][k];
	}
	dongs[i][k] = counts;
	counter++;

	if (i > 0 && maps[i-1][k] > 0)
	{
		spread(i - 1, k, counts);
	}
	if (k > 0 && maps[i][k-1] > 0)
	{
		spread(i, k-1, counts);
	}
	if (i < n-1 && maps[i+1][k] > 0)
	{
		spread(i + 1, k, counts);
	}
	if (k < n-1 && maps[i][k+1] > 0)
	{
		spread(i, k +1, counts);
	}
	return counter;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n;

	maps.resize(n);
	dongs.resize(n);
	for (auto& v : dongs)
		v.resize(n,0);
	for (int i = 0; i < n*n; ++i)
	{
		char c;
		cin >> c;

		if (c >= '0' && c <= '9')
		{
			maps[i/n].push_back(c - '0');
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			if (maps[i][k] && !dongs[i][k])
			{
				counter = 0;
				int c = spread(i, k, maxx.size() + 1);
				if (c)
					maxx.push_back(c);
			}
		}
	}
	sort(maxx.begin(), maxx.end());
	cout << maxx.size() << "\n";
	for (int i=0;i<maxx.size();++i)
	{
		cout << maxx[i] << "\n";
	}
}