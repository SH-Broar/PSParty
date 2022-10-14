#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	while (N--)
	{
		int n, m;
		cin >> n >> m;

		int c = m - n;
		switch (c)
		{
		case 0:
			cout << "0\n";
			break;
		case 1:
			cout << "1\n";
			break;
		case 2:
			cout << "2\n";
			break;
		default:
			int q = sqrt(c);
			if (q * q == c)
			{
				cout << sqrt(c) + (sqrt(c) - 1);
			}
			else
			{
				float sq = sqrt(c);

				if (sq - q <= 0.5f)
				{
					cout << (2 * q);
				}
				else
				{
					cout << (2 * q + 1);
				}
			}
			cout << "\n";

			break;
		}
	}
}