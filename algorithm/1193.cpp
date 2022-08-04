#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	int r = n;
	int i = 1;
	while (r > 0)
	{
		r -= i;
		i++;
	}
	
	int z = i - 1 + r;

	if (i % 2)
	{
		cout << z << "/" << i - z;
	}
	else
	{
		cout << i - z << "/" << z;
	}
}