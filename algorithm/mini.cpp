#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int total;
	cin >> total;

	vector<int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int tmp, tmpn;
		cin >> tmp >> tmpn;
		v.push_back(tmp*tmpn);
	}
	if (total == accumulate(v.begin(), v.end(), 0))
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

}