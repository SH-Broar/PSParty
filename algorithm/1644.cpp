#include <iostream>

using namespace std;

bool tables[4000001]{ false };

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

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	isPrime(tables, 0, 4000000);

	int n;
	cin >> n;

	int left = 2;
	int right = 3;
	int sum = 2;

	int ret = 0;

	while (left <= n)
	{
		if (sum < n)
		{
			do
			{
				right++;
			}while (tables[right-1] == true);

			sum += right - 1;
		}
		else if (sum > n)
		{
			sum -= left;
			do
			{
				left++;
			} while (tables[left] == true);
		}
		if (sum == n)
		{
			ret++;
			sum -= left;
			do
			{
				left++;
			} while (tables[left] == true);
		}
	}

	cout << ret;
}