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
		if (L.first > to)	//���� ����
		{
			dists += to - from;
			from = L.first;
			to = L.second;
		}
		else //���� ���� ����
		{
			if (L.second > to) // ���� �� ���
			{
				to = L.second;
			}
		}
	}
	dists += to - from;

	cout << dists;
}