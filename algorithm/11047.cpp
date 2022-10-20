#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, key;
	cin >> n >> key;

	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		coins.push_back(c);
	}
	reverse(coins.begin(), coins.end());

	int ret = 0;
	int b = 0;
	while (key > 0)
	{
		if (key >= coins[b])
		{
			ret += key / coins[b];
			key -= (key / coins[b])*coins[b];
		}
		else
		{
			b++;
		}
	}
	cout << ret;
}