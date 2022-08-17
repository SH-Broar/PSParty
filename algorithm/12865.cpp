#include <iostream>
#include <vector>
using namespace std;

struct ob
{
	int w;
	int v;

	ob(int a, int b)
	{
		w = a;
		v = b;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> capacity{};
	capacity.resize(k + 1);

	vector<ob> datas;
	datas.emplace_back(0, 0);

	for (int k = 0; k < n; ++k)
	{
		int w, v;
		cin >> w >> v;
		datas.emplace_back(w, v);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = k; j >= 1; --j)
		{
			if (datas[i].w <= j)
			{
				//갱신되는 무게 = 현재 가치랑 이거 넣기 전에 제일 고려 많이 된 거 + 이거 비교
				capacity[j] = max(capacity[j], capacity[j - datas[i].w] + datas[i].v);
			}
		}
	}

	cout << capacity[k];



}