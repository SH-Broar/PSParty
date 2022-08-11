#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct timetable
{
	int start;
	int end;

	timetable(int a, int b)
	{
		start = a;
		end = b;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<timetable> tt;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		tt.emplace_back(a, b);
	}

	sort(tt.begin(), tt.end(), [](auto& a, auto& b) {
		if (a.end == b.end)
		{
			return a.start < b.start;
		}
		return a.end < b.end;
		});

	int laster = 0;
	int result = 0;

	for (auto& t : tt)
	{
		if (t.start >= laster)
		{
			result++;
			laster = t.end;
		}
	}
	cout << result;

}