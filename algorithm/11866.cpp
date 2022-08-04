#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int K, N;
	cin >> N >> K;

	vector<int> arr;
	vector<int> replace;
	
	for (int i = 0; i < N; i++)
	{
		arr.push_back(i + 1);
	}
	int ex = -1;
	for (int i = 0; i < N; i++)
	{
		int gap = 0;

		while (gap < K)
		{
			ex++;

			if (ex >= N)
				ex %= N;

			if (arr[ex] > 0)
				gap++;
		}

		replace.push_back(arr[ex]);
		arr[ex] = 0;

	}
	cout << "<";
	for (int i = 0; i < replace.size(); i++)
	{
		cout << replace[i];
		if (i < replace.size() - 1)
			cout << ", ";
	}
	cout << ">";

	return 0;
}