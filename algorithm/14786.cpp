#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	double a, b, c;
	
	cin >> a >> b >> c;

	double incest;
	incest = 0;

	while (fabs(a * incest + b * sin(incest) - c) > 0.000000001)
	{
		incest = incest - ((a * incest) + (b * sin(incest)) - c) / (a + (b * cos(incest)));
	}

	cout << fixed;
	cout.precision(9);
	cout << incest;
}