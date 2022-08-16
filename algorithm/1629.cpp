#include <iostream>

using namespace std;

long long moder(int r);
long long n, r, m;
long long ticker;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r >> m;
	
	ticker = n % m;

	cout << moder(r);
}

long long moder(int r)
{
	if (r == 1)
		return ticker;
	else if (r % 2 == 0)
	{
		long long af = moder(r/2);
		return (af * af) % m;
	}
	else
	{
		long long af = moder(r / 2);
		return (((af * af) % m) * ticker) % m;
	}
}