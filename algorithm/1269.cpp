#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	set<int> left;
	set<int> right;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		left.insert(t);
	}
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		right.insert(t);
	}

	set<int> resulter;
	set_symmetric_difference(left.begin(), left.end(), right.begin(), right.end(), inserter(resulter,resulter.begin()));

	cout << resulter.size();
}