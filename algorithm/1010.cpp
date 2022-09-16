#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		
		long long k = 1;
		for (int n = 0; n < l; ++n)
		{
			k *= (r - n);
			k /= n + 1;
		}
		cout << k << "\n";
	}
}