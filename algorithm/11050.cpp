#include <iostream>
using namespace std;

int choose(int n, int r);

int main()
{
	int n, r;

	cin >> n >> r;

	cout << choose(n, r);
}

int choose(int n, int r)
{
	if (n == r || r == 0)
		return 1;

	return choose(n - 1, r - 1) + choose(n - 1, r);
}