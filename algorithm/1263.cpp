#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<pair<int, int>> tasks;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		tasks.emplace_back(a, b);
	}

	sort(tasks.begin(), tasks.end(), [](pair<int, int> a, pair<int, int> b)
		{
			return a.second > b.second;
		});

	int tmax = tasks[0].second;

	for (auto& p : tasks)
	{
		if (tmax > p.second)
			tmax = p.second - p.first;
		else
			tmax -= p.first;
	}
	if (tmax < 0)
		cout << "-1";
	else
		cout << tmax;
}