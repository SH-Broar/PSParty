#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	while (n > 1)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (n % i == 0)
			{
				cout << i << "\n";
				n = n / i;
				break;
			}
		}
		
	}
}