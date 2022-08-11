#include <iostream>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		int absa;
		int absb;
		if (a < 0)
			absa = -a;
		else
			absa = a;
		if (b < 0)
			absb = -b;
		else
			absb = b;

		if (absa == absb)
			return a > b;
		else
			return absa > absb;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(t);
		}
	}
}