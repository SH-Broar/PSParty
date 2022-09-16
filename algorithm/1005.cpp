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


	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vector<nodes> graph;
		vector<int> buildCosts;
		vector<int> degrees;
		vector<int> maxBuildCost;

		vector<int> ender;

		queue<int> q;

		int fin;

		int N, K;
		cin >> N >> K;
		graph.resize(N + 1);
		buildCosts.resize(N + 1);
		degrees.resize(N + 1);
		maxBuildCost.resize(N + 1);

		for (int i = 1; i <= N; ++i)
		{
			int c;
			cin >> c;
			buildCosts[i] = c;
		}

		for (int i = 0; i < K; ++i)
		{
			int f, t;
			cin >> f >> t;
			graph[f].edges.push_back(t);
			degrees[t] += 1;
		}
		degrees[0] = -1;

		cin >> fin;

		for (int f = 0; auto& i : degrees)
		{
			if (i == 0)
			{
				i = -1;
				q.push(f);
				maxBuildCost[f] = buildCosts[f];
			}
			f++;
		}
		
		bool flag = true;
		while (!q.empty() && flag)
		{
			int front= q.front();
			q.pop();
			ender.push_back(front);

			for (auto& i : graph[front].edges)
			{
				degrees[i]--;
				if (maxBuildCost[i] < maxBuildCost[front] + buildCosts[i])
				{
					maxBuildCost[i] = maxBuildCost[front] + buildCosts[i];
				}
				if (degrees[i] == 0)
				{
					if (i == fin)
					{
						flag = false;
						break;
					}
					q.push(i);
					degrees[i] = -1;
				}
			}
		}
		
		cout << maxBuildCost[fin] << "\n";
	}
}