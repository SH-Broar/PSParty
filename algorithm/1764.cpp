#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	
	vector<string> notd;
	vector<string> notb;
	for (int i = 0; i < a; ++i)
	{
		string tmp;
		cin >> tmp;
		notd.push_back(tmp);
	}
	for (int i = 0; i < b; ++i)
	{
		string tmp;
		cin >> tmp;
		notb.push_back(tmp);
	}
	vector<string> notdb;
	sort(notd.begin(), notd.end());
	sort(notb.begin(), notb.end());
	set_intersection(notd.begin(), notd.end(), notb.begin(), notb.end(), back_inserter(notdb));

	cout << notdb.size() << "\n";
	for (auto& db : notdb)
	{
		cout << db << "\n";
	}
}