#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a;
	vector<vector<int>> b;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
	{
		a[i].resize(m);
		b[i].resize(m);
	}

	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> t;
			a[i][j] = t;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> t;
			b[i][j] = t;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << "\n";
	}
	
}