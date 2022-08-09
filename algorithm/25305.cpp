#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int rank;
	int a;
	cin >> n >> rank;

	vector<int> lists;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		lists.push_back(a);
	}

	sort(lists.begin(), lists.end(), greater<>());
	cout << lists[rank - 1];
}