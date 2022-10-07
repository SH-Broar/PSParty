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

	vector<int> peoples;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		peoples.push_back(t);
	}

	sort(peoples.begin(), peoples.end());

	long long count = 0;
	for (int i = 0; i < peoples.size(); ++i)
	{
		for (int j = i+1; j < peoples.size(); ++j)
		{
			auto it = equal_range(peoples.begin() + j+1, peoples.end(), -(peoples[i] + peoples[j]));
			count += distance(it.first,it.second);
		}
	}

	cout << count;
}