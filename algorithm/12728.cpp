#include <iostream>
#include <vector>
using namespace std;

constexpr long long defactor = 1000;

vector<vector<long long>> operator* (auto& a, auto& b)
{
	vector<vector<long long>> rets;
	rets.resize(2);
	rets[0].resize(2);
	rets[1].resize(2);

	for (int i = 0; i < 2; ++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int p = 0; p < 2; ++p)
			{
				rets[i][k] += a[i][p] * b[p][k];
			}
			rets[i][k] %= defactor;
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

	for (int i=0;i<n;++i)
	{
		long long q;
		cin >> q;
		vector<vector<long long>> data{ {1, 0}, {0, 1} };
		vector<vector<long long>> times{ {6,-4}, {1,0} };
		q--;

		while (q > 0)
		{
			if (q % 2 == 1)
			{
				data = data * times;
			}
			times = times * times;
			q /= 2;
		}

		int ret = (((28 * data[1][0] + 6 * data[1][1] - 1) %defactor + 1000) % 1000);
		cout << "Case #" << i + 1 << ": ";

		cout.width(3); cout.fill('0'); cout << ret;
		cout << "\n";
	}
}