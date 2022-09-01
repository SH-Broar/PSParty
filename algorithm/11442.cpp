#include <iostream>
#include <vector>
using namespace std;

constexpr long long defactor = 1000000007;
vector<vector<long long>> mats;

vector<vector<long long>> operator* (auto& a, auto& b)
{
	vector<vector<long long>> rets;
	rets.resize(2);
	rets[0].resize(2);
	rets[1].resize(2);

	for (int i=0;i<2;++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int p = 0; p < 2; ++p)
			{
				rets[i][k] += a[i][p] * b[p][k];
				rets[i][k] %= defactor;
			}
		}
	}

	return rets;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long n;
	cin >> n;

	if (n % 2 == 0)
		n++;
	
	vector<vector<long long>> data{{1,0}, {0,1}};
	vector<vector<long long>> times{ {1,1}, {1,0}};

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			data = data * times;
		}
		times = times * times;
		n /= 2;
	}

	cout << data[0][1] - 1;
}