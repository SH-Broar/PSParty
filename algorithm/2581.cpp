#include <iostream>

using namespace std;

bool isD(int num);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int m,n;
	cin >> m >> n;

	int result = 0;
	int min = 0;
	for (int i = n; i >= m && i > 1; --i)
	{
		if (isD(i))
		{
			result += i;
			min = i;
		}
	}
	if (result == 0)
		cout << "-1";
	else
		cout << result << "\n" << min;

}

bool isD(int num)
{
	for (int i = num / 2; i >= 2; --i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}