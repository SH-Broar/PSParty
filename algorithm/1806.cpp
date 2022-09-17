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

	int sett;
	cin >> sett;

	vector<int> cage;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		cage.push_back(t);
	}

	int left = 0;
	int right = 0;
	int sum = 0;

	int minleg = n+1;

	while (left < n)
	{
		if (sum < sett)
		{
			if (right < cage.size())
			{
				sum += cage[right];
				right++;
			}
			else
				break;
		}
		else if (sum >= sett)
		{
			if (right - left < minleg)
				minleg = right - left;

			sum -= cage[left];
			left++;
		}
	}
	if (minleg == n + 1)
		minleg = 0;
	cout << minleg;
}