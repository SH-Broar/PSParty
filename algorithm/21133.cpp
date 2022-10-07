#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	int t = n / 2;

	if (n % 6 == 2)
	{
		for (int i = 1; i <= t; ++i)
		{
			cout << i * 2 << "\n";
		}
		cout << "3\n1\n";
		for (int i = 3; i < t; ++i)
		{
			cout << i * 2 +1 << "\n";
		}
		cout << "5\n";
	}
	else if (n % 6 == 3)
	{
		for (int i = 2; i <= t; ++i)
		{
			cout << i * 2 << "\n";
		}
		cout << "2\n";
		for (int i = 2; i <= t; ++i)
		{
			cout << i * 2 + 1 << "\n";
		}
		cout << "1\n3\n";
	}
	else
	{
		for (int i = 1; i <= t; ++i)
		{
			cout << i + t << "\n";
			cout << i << "\n";
		}
		if (n & 1)
			cout << n;
	}
}