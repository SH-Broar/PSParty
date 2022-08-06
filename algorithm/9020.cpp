#include <iostream>

using namespace std;

void isPrime(bool* n, int num, int numEnd);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	bool table[10001];
	int n;
	int a;
	cin >> n;

	isPrime(table, 1, 10000);
	for (int i = 0; i < n; ++i)
	{
		cin >> a;

		if (a == 4)
		{
			cout << "2 2\n";
			continue;
		}

		int k = 0;
		if ((a/2)%2 == 1)
		{
			 k = a / 2;
		}
		else
		{
			k = (a / 2) - 1;
		}

		for (; k >= 2; ----k)
		{
			if (!table[k] && !table[a - k])
			{
				cout << k << " " << a - k << "\n";
				break;
			}
		}

	}
}

void isPrime(bool* n, int num, int numEnd)
{
	int result = 0;

	for (int i = 2; i * i <= numEnd; ++i)
	{
		if (!n[i])
		{
			for (int j = i * i; j <= numEnd; j += i)
			{
				n[j] = true;
			}
		}
	}
}