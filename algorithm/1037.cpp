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
	vector<int> y;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		y.push_back(a);
	}
	sort(y.begin(), y.end());

	cout << y[0] * y[y.size() - 1];
}