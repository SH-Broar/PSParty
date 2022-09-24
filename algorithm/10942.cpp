#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> tags(2000);
vector<vector<int>> ps(2000, vector<int>(2000, -1));

int makeboard(int s, int e)
{
	if (s == e)
		return ps[s][e] = 1;

	if (ps[s][e] != -1)
		return ps[s][e];

	if (tags[s] != tags[e])
	{
		ps[s][e] = 0;
		return ps[s][e] = 0;
	}
	else
	{
		ps[s][e] = 1;
		if (s < n-1 && e > 0 && s+1 <= e-1)
			ps[s][e] = makeboard(s + 1, e - 1);
		return ps[s][e];
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i=0; i<n; ++i)
	{
		int t;
		cin >> t;
		tags[i] = t;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << makeboard(a-1, b - 1) << "\n";

	}
}