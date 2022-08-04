#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct paper_info
{
	int level;
	bool track = false;
};

int main()
{
	int tests;
	cin >> tests;

	for (int t = 0; t < tests; t++)
	{
		int papers;
		cin >> papers;

		int which;
		cin >> which;

		queue<paper_info> paps;
		vector<int> levels;
		levels.reserve(papers);

		int order = 1;

		for (int i = 0; i < papers; i++)
		{
			paper_info tmp;
			cin >> tmp.level;

			if (i == which)
			{
				tmp.track = true;
			}
			paps.push(tmp);
			levels.emplace_back(tmp.level);
		}
		sort(levels.begin(), levels.end(), [](const int& a, const int& b) {return a > b; });

		while (!paps.empty())
		{
			while (paps.front().level < levels[order-1])
			{
				paps.push(paps.front());
				paps.pop();
			}
			if (paps.front().track)
			{
				paps.pop();
				cout << order << endl;
				break;
			}
			else
			{
				paps.pop();
				order++;
			}
		}

	}

}