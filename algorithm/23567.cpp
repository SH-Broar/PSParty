#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<int> rainbows;

	int c;
	cin >> c;

	vector<int> rains;
	rains.resize(n);
	vector<int> doubleRains;
	doubleRains.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		rainbows.push_back(t);

		doubleRains[t - 1]++;
	}

	int left = 0;
	int right = 0;

	int totalRains = 0;
	int outertask = c;

	int minleg = n + 1;

	while(left < n)
	{
		if (totalRains < c && outertask == c)
		{
			if (right < n)
			{
				if (rains[(rainbows[right] - 1)] == 0)
					totalRains++;

				rains[(rainbows[right] - 1)]++;
				doubleRains[(rainbows[right] - 1)]--;

				if (doubleRains[(rainbows[right] - 1)] == 0)
					outertask--;

				right++;
			}
			else
				break;
		}
		else if (totalRains >= c && outertask == c)
		{
			if (right - left < minleg)
				minleg = right - left;

			rains[(rainbows[left] - 1)]--;
			doubleRains[(rainbows[left] - 1)]++;
				
			if (rains[(rainbows[left] - 1)] == 0)
				totalRains--;

			left++;
		}
		else
		{
			if (doubleRains[(rainbows[left] - 1)] == 0)
				outertask++;

			rains[(rainbows[left] - 1)]--;
			doubleRains[(rainbows[left] - 1)]++;

			if (rains[(rainbows[left] - 1)] == 0)
				totalRains--;

			left++;
		}
	}

	if (minleg == n + 1)
		minleg = 0;
	cout << minleg;
}