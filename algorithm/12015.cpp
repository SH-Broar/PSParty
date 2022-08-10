#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> lists;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		lists.push_back(tmp);
	}

	vector<int> increasingLists;

	increasingLists.push_back(0);

	for (int i = 0; i < lists.size(); ++i)
	{
		if (lists[i] > increasingLists.back())
		{
			increasingLists.push_back(lists[i]);
		}
		else
		{
			int left = 1;
			int right = increasingLists.size() - 1;

			while (true)
			{
				if (right - left == 1 || right - left == 0)
				{
					// ¸¶Áö¸·
					if (increasingLists[left] >= lists[i])
						increasingLists[left] = lists[i];
					else
						increasingLists[right] = lists[i];
					break;
				}

				int mid = (left + right) / 2;
				if (increasingLists[mid] <= lists[i])
					left = mid;
				else
					right = mid;
			}

		}
	}
	cout << increasingLists.size() - 1;
}
