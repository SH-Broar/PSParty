#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<pair<int, pair<int, int>>> platforms;
	for (int i = 0; i < n; ++i)
	{
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		
		platforms.emplace_back(y, make_pair(x1, x2));
	}

	sort(platforms.begin(), platforms.end());

	for (auto iter = platforms.rbegin(); iter != platforms.rend(); iter++)
	{
		bool lx = true;
		bool rx = true;
		for (auto pits = iter; pits != platforms.rend(); pits++)
		{
			if (pits != iter)
			{
				if (lx && (*iter).second.first >= (*pits).second.first && (*iter).second.first < (*pits).second.second)
				{
					(*iter).second.first = (*iter).first - (*pits).first;
					lx = false;
				}
				if (rx && (*iter).second.second > (*pits).second.first && (*iter).second.second <= (*pits).second.second)
				{
					(*iter).second.second = (*iter).first - (*pits).first;
					rx = false;
				}
			}
			if (!lx && !rx)
				break;
		}
		if (lx)
			(*iter).second.first = (*iter).first;
		if (rx)
			(*iter).second.second = (*iter).first;
	}

	int ret = 0;
	for (auto& v : platforms)
	{
		//cout << v.first << " " << v.second.first << " " << v.second.second << "\n";
		ret += v.second.first + v.second.second;
	}
	cout << ret;

}