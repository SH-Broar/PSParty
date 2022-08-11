#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<int> resulter;
	resulter.resize(n);
	resulter[0] = 1;
	resulter[1] = 2;

	for (int i = 2; i < n; ++i)
	{
		resulter[i] = (resulter[i-1] + resulter[i-2] ) % 10007;
	}

	cout << resulter[n - 1];
}