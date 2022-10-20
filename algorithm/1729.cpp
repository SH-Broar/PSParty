#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;

int finder(int idx)
{
	int maxx = -1;
	for (int i = 5 - idx; i >= 0; --i)
	{

	}

	return maxx;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	arr.resize(6);
	for (auto& v : arr)
		v.resize(6);


	int maxx = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			int a;
			cin >> a;
			maxx += a;
			arr[i][j] = a;
		}
	}

	int r = finder(0);
	cout << r;

}