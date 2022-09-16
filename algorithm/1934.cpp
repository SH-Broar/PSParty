#include <iostream>

using namespace std;

int euc(int a, int b)
{ 
	return b ? euc(b, a % b) : a;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int f, s;
		cin >> f >> s;

		cout << f*s / euc(f,s) << "\n";
	}
}