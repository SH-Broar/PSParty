#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	
	vector<int> cases;
	cases.resize(n+1);
	cases[0] = 0;
	cases[1] = 1;
	cases[2] = 3;

	for (int i = 3; i <= n; ++i)
	{
		cases[i] = cases[i - 1];
		cases[i] += cases[i - 2]*2;
		cases[i] %= 10007;
	}

	cout << cases[n];
}