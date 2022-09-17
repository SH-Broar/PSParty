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

	int cat;
	cin >> cat;

	vector<int> datas;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		datas.push_back(t);
	}

	int left = 0;
	int right = 0;
	int tsum = 0;

	int ret = 0;
	
	while (left < datas.size())
	{
		if (tsum < cat)
		{
			if (right < datas.size())
			{
				tsum += datas[right];
				right++;
			}
			else
				break;
		}
		else if (tsum > cat)
		{
			tsum -= datas[left];
			left++;
		}

		if (tsum == cat)
		{
			ret++;
			tsum -= datas[left];
			left++;
		}

	}

	cout << ret;
}

