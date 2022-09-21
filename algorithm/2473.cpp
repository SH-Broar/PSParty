#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	long long n;
	cin >> n;

	vector<long long> axs;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		axs.push_back(a);
	}
	sort(axs.begin(), axs.end());


	int mid = 0;

	long long f = axs[1];
	long long b = axs[mid];
	long long t = axs[n-1];

	long long mined = 210000000000;

	for (mid=0; mid < axs.size()-2; ++mid)
	{
		int left = mid+1;
		int right = n - 1;
		while (left < right)
		{
			long long aaa = axs[left] + axs[right] + axs[mid];
			long long abc = abs(axs[left] + axs[right] + axs[mid]);

			if (abc < mined)
			{
				f = axs[left];
				b = axs[mid];
				t = axs[right];
				mined = abc;
			}
			if (aaa < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}

	cout << b << " " << f << " " << t;
}