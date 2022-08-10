#include <iostream>

using namespace std;


void Checker(long long left, long long right);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	long long n, k;
	cin >> n >> k;
	
	Checker(n, k);
}

void Checker(long long siz, long long k)
{
	long long left = 1;
	long long right = k;

	while (left < right)
	{
		long long mid = (left + right) / 2;
		
		int cnt = 0;

		for (int i = 1; i <= siz; i++)
		{
			if (mid / i > siz)
				cnt += siz;
			else
				cnt += mid / i;
		}
		
		if (cnt < k)
			left = mid + 1;
		else
			right = mid;

	}
	cout << left;
}