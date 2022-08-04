#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;

	cin >> n;


	int cycle = 0;
	int prev = n;
	int newer = -1;
	while (newer != n)
	{
		newer = (prev / 10) + (prev % 10);
		newer = (prev % 10) * 10 + (newer	 % 10);
		cycle++;
		prev = newer;
	}

	cout << cycle;
}