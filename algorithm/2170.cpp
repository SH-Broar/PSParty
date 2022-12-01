#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, int>> lines;
	int n;
	cin >> n;
	while (n--)
	{
		int f, t;
		cin >> f >> t;
		lines.emplace_back(f, t);
	}
	sort(lines.begin(), lines.end(), [](auto& a, auto& b)
		{
			return a.first < b.first;
		});


	int dists = 0;
	int from = -10e9;
	int to = from;
	for (auto& L : lines)
	{
		if (L.first > to)	//별도 선분
		{
			dists += to - from;
			from = L.first;
			to = L.second;
		}
		else //동일 선분 시작
		{
			if (L.second > to) // 끝이 더 길면
			{
				to = L.second;
			}
		}
	}
	dists += to - from;

	cout << dists;
}