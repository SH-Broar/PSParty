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

	vector<long long> padoban;
	padoban.resize(101);
	padoban[0] = 1;
	padoban[1] = 1;
	padoban[2] = 1;
	for (int i = 3; i < 101; ++i)
	{
		padoban[i] = padoban[i - 3] + padoban[i - 2];
	}
	for (int i = 0; i < n; ++i)
	{
		int in;
		cin >> in;
		cout << padoban[in-1] << "\n";
	}
}