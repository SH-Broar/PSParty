#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string n;
	cin >> n;

	char prev = ' ';
	char pprev = ' ';
	int num = 0;
	for (char c : n)
	{
		if (c == '=' && prev == 'z' && pprev == 'd')
		{
			pprev = prev;
			prev = c;
			num--;
			continue;
		}

		if (!(c >= 'a' && c <= 'z'))
		{
			pprev = prev;
			prev = c;
			continue;
		}

		if (c == 'j' && (prev == 'l' || prev == 'n'))
		{
			pprev = prev;
			prev = c;
			continue;
		}

		pprev = prev;
		prev = c;
		num++;
	}

	cout << num;
}