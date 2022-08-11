#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> nn{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int n;
	int t;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		if (tmp == "add")
		{
			cin >> t;
			s.insert(t);
		}
		else if (tmp == "remove")
		{
			cin >> t;
			s.erase(t);
		}
		else if (tmp == "check")
		{
			cin >> t;
			if (s.find(t) != s.end())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (tmp == "toggle")
		{
			cin >> t;
			if (s.find(t) != s.end())
			{
				s.erase(t);
			}
			else
			{
				s.insert(t);
			}
		}
		else if (tmp == "all")
		{
			s = nn;
		}
		else
		{
			s.clear();
		}
	}
}