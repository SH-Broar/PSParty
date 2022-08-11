#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> times;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;

		times.push_back(a);
	}
	sort(times.begin(), times.end());
	partial_sum(times.begin(), times.end(),times.begin());
	
	int result;
	result = accumulate(times.begin(), times.end(),0);
	cout << result;
}