#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n,m;
	cin >> n >> m;

	vector<vector<int>> maps;
	maps.resize(n);
	for (auto& v : maps)
		v.resize(m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int txt;
			cin >> txt;
			maps[i][j] = txt - 'A';
		}
	}

	vector<int> visited;
	visited.resize(26);

	stack<int> lefts;


}