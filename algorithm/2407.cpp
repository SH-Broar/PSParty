#include <iostream>

using namespace std;

int combination(int n, int r);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	cout << combination(n, m);
}
int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}