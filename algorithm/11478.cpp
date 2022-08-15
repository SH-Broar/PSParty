#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	string n;
	cin >> n;
	int l = n.size();

	set<string> mp;

	for (int i = 0; i < l; ++i)
	{
		for (int j = 1; j <= l; ++j)
		{
			mp.insert(n.substr(i, j));
		}
	}

	cout << mp.size();
}