#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int r;
	cin >> r;

	int result = r;

	for (int i = 0; i < r; i++)
	{
		string n;
		cin >> n;

		set<char> alpha;

		char prev = ' ';
		for (char c : n)
		{
			if (c != prev)
			{
				if (alpha.find(c) == alpha.end())
				{
					alpha.insert(c);
				}
				else
				{
					result--;
					break;
				}
			}
			prev = c;
		}
	}
	cout << result;

}