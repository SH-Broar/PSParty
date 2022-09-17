#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int TC;
	cin >> TC;
	while (TC--)
	{
		int in;
		cin >> in;

		double call = 1;
		while (in)
		{
			call = call + log10(in);
			in--;
		}
		cout << static_cast<int>(call) << "\n";
	}
}