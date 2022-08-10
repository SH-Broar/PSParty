#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	set<int> hands;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		hands.insert(tmp);
	}

	cin >> n;

	vector<int> checker;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		checker.push_back(tmp);
	}

	for (auto& v : checker)
	{
		if (hands.find(v) != hands.end())
		{
			cout << "1 ";
		}
		else
		{
			cout << "0 ";
		}
	}
	
}