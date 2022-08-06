#include <iostream>
#include <cmath>
using namespace std;

void isPrime(bool* n, int num, int numEnd);

int main()
{
	int num = 0;
	int numEnd = 0;
	while (true)
	{
		bool b[300000];

		cin >> num;
		if (num == 0)
			return 0;
		numEnd = num * 2;

		isPrime(b, num, numEnd);
	}
}

void isPrime(bool* n, int num, int numEnd)
{
	int result = 0;

	for (int i = 2; i*i <= numEnd; ++i)
	{
		if (!n[i])
		{
			for (int j = i * i; j <= numEnd; j += i)
			{
					n[j] = true;
			}
		}
	}

	for (int i = num + 1; i <= numEnd; i++)
	{
		if (!n[i])
			result++;
	}

	cout << result << "\n";

}