#include <iostream>
#include <queue>
using namespace std;

struct study
{
	int s;
	int t;
};

struct cmp
{
	bool operator()(study& a, study& b) const
	{
		//cout << a.s << " " << b.s << endl;
		if (a.s == b.s)
			return a.t > b.t;
		return a.s > b.s;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<study, vector<study>, cmp> pq;
	priority_queue<int,vector<int>,greater<>> rooms;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ a, b });
	}

	while (!pq.empty())
	{
		auto t = pq.top();
		pq.pop();

		if (rooms.empty() || rooms.top() > t.s)
		{
			rooms.push(t.t);
		}
		else
		{
			rooms.pop();
			rooms.push(t.t);
		}
	}
	cout << rooms.size();
}