#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	int c;

	int zerocount[41];
	int onecount[41];

	zerocount[0] = 1;
	onecount[0] = 0;
	zerocount[1] = 0;
	onecount[1] = 1;

	for (int i = 2; i <= 40; ++i)
	{
		zerocount[i] = zerocount[i-2] + zerocount[i-1];
		onecount[i] = onecount[i - 2] + onecount[i - 1];
	}


	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		
		cout << zerocount[c] << " " << onecount[c] << "\n";
	}
}