#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	string n;
	cin >> n;

	int result = 0;

	for (char c : n)
	{

		if (c >= 'A' && c <= 'R')
		{
			result += (c - 'A') / 3 + 3;
		}
		else if (c == 'S')
		{
			result += 8;
		}
		else if (c >= 'T' && c <= 'V')
		{
			result += 9;
		}
		else
		{
			result += 10;
		}
	}

	cout << result;
}