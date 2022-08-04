#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ser(vector<int>& pool, int from, int end, int num);

int main()
{

	int N, M;
	scanf("%d", &N);

	vector<int> pool;
	vector<int> cases;

	for (int i = 0; i < N; i++)
	{
		int k;
		scanf("%d", &k);
		pool.emplace_back(k);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int k;
		scanf("%d", &k);
		cases.emplace_back(k);
	}

	sort(pool.begin(), pool.end());

	for (auto num : cases)
	{
		if (ser(pool,0,pool.size()-1,num))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
		
}

bool ser(vector<int>& pool,int from,int end, int num)
{
	int mid = (from + end) / 2;

	if (from > end)
	{
		return false;
	}
	if (pool[mid] == num)
	{
		return true;
	}
	else
	{
		if (pool[mid] > num)
			return ser(pool, from, mid - 1, num);
		else if (pool[mid] < num)
			return ser(pool, mid + 1, end, num);
	}
}
