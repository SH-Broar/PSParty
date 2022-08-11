#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<>> pq;
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