#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	string txt;
	cin >> txt;

	long long result = 0;

	for (int i = 0; i < txt.size(); i++)
	{
		long long c=1;
		for (int k = 0; k < i; k++)
		{
			c *= 31;
			c %= 1234567891;
		}

		result += ((txt[i] - 'a' + 1) * c) % 1234567891;
	}
	result %= 1234567891;
	cout << result;
}