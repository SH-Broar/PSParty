#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct SpreadTable
{
	vector<string> xTable;
	vector<string> yTable;

	SpreadTable(int x, int y)
	{
		xTable.resize(x);
		yTable.resize(y);
	}

	void push(string& str)
	{
		xTable.push_back(str);
		for (int i = 0; i < yTable.size(); ++i)
		{
			yTable[i] += str[i];
		}
	}

	string getX(int l)
	{
		return xTable[l];
	}

	string getY(int l)
	{
		return yTable[l];
	}

	bool isDuplicated(int mid)
	{
		set<string> s;
		for (auto& str : yTable)
		{
			s.emplace(str.begin()+mid, str.end());
		}
		if (s.size() != yTable.size())
			return true;
		else
			return false;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	SpreadTable ST{n,m};
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		ST.push(tmp);
	}

	int left = 0;
	int right = n;
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (ST.isDuplicated(mid))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left-1;
}