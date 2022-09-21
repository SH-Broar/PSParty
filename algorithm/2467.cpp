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

	vector<int> axs;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		axs.push_back(a);
	}

	int left = 0;
	int right = n - 1;

	int f = axs[left];
	int t = axs[right];

	int mined = 2100000000;

	while (left < right)
	{
		int aa = axs[left] + axs[right];
		int ab = abs(axs[left] + axs[right]);
		//cout << left << " " << right << " " << axs[left] << " " << axs[right] << " " << ab;
		
		if (ab < mined)
		{
			f = axs[left];
			t = axs[right];
			mined = ab;
		}
		if (aa < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << f << " " << t;
}