#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodes
{
	vector<int> edges;
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<nodes> graph;
	vector<int> degrees;
	vector<int> ender;

	queue<int> q;

	int N, M;
	cin >> N >> M;
	graph.resize(N + 1);
	degrees.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int f, t;
		cin >> f >> t;
		graph[f].edges.push_back(t);
		degrees[t] += 1;
	}
	degrees[0] = -1;

	for (int f = 0; auto & i : degrees)
	{
		if (i == 0)
		{
			i = -1;
			q.push(f);
		}
		f++;
	}

	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		ender.push_back(front);

		for (auto& i : graph[front].edges)
		{
			degrees[i]--;
			if (degrees[i] == 0)
			{
				q.push(i);
				degrees[i] = -1;
			}
		}
	}

	for (auto& i : ender)
	{
		cout << i << " ";
	}

}