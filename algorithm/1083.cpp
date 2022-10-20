#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<int> ins;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		ins.push_back(t);
	}

	int s;
	cin >> s;

	int sorted = 0;
	while (s)
	{
		int mx = s > ins.size() ? ins.size() : s;

		auto iter = max_element(ins.begin() + sorted, ins.begin() + mx);
	}

	for (auto i : ins)
	{
		cout << i << " ";
	}
}