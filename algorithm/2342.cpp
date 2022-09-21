#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

vector<int> pattern;
vector<vector<vector<int>>> footsteps;

int moving(int f, int t)
{
	if (f == t)
		return 1;

	if (f == 0)
		return 2;

	if (f == 1 || f == 4)
	{
		if (t == 1 || t == 4)
			return 3;
	}

	return abs(f - t) + 2;
	
}

int progress(int left, int right, int p)
{
	if (p == pattern.size())
		return 0;
	
	if (footsteps[left][right][p] != 0)
		return footsteps[left][right][p];

	footsteps[left][right][p] = min(progress(pattern[p], right, p + 1) + moving(left, pattern[p]), progress(left, pattern[p], p + 1) + moving(right, pattern[p]));
	return footsteps[left][right][p];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	while (cin >> t)
	{
		if (t != 0)
			pattern.push_back(t);
		else
			break;
	}

	footsteps.resize(5);
	for (auto& f : footsteps)
	{
		f.resize(5);
		for (auto& ff : f)
		{
			ff.resize(pattern.size());
		}
	}

	cout << progress(0, 0, 0);


}