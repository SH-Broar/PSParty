#include <iostream>
#include <cmath>
using namespace std;

void visit(int x, int y, int factor);

int Rcount = 0;
int a, b;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;

	cin >> n >> a >> b;
	
	int underunit = pow(2, n - 1);
	int unit = pow(2, n);
	visit(0, 0, unit);
}

void visit(int x, int y, int factor)
{
	if (factor == 1)
	{
		if (x == a && y == b)
		{
			cout << Rcount;
		}
		return;
	}

	int nFactor = factor / 2;

	if (a < x + nFactor && b < y + nFactor)
	{
		visit(x, y, nFactor);
	}
	else if (a < x + nFactor && b >= y + nFactor)
	{
		Rcount += nFactor * nFactor;
		visit(x, y + nFactor, nFactor);
	}
	else if (a >= x + nFactor && b < y + nFactor)
	{
		Rcount += 2 * nFactor * nFactor;
		visit(x + nFactor, y, nFactor);
	}
	else if (a >= x + nFactor && b >= y + nFactor)
	{
		Rcount += 3 * nFactor * nFactor;
		visit(x + nFactor, y + nFactor, nFactor);
	}
}