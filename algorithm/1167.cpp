#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	int to;
	int weight;

	node(int a, int b)
	{
		to = a;
		weight = b;
	}
};

int n;

vector<vector<node>> trees;
stack<int> finderStack;

int maxIndex = 0;

int findMaxDistance(int node)
{
	finderStack.push(node);
	vector<int> visited;
	visited.resize(n + 1, 0);

	while (!finderStack.empty())
	{
		int from = finderStack.top();
		finderStack.pop();

		for (auto i : trees[from])
		{
			if (visited[i.to] == 0 && i.to != node)
			{
				finderStack.push(i.to);
				visited[i.to] = visited[from] + i.weight;
			}
		}
	}
	maxIndex = distance(visited.begin(), max_element(visited.begin(), visited.end()));
	//cout << maxIndex << " ";
	return *max_element(visited.begin(), visited.end());
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	trees.resize(n + 1);
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a;

		while (true)
		{
			cin >> b;
			if (b == -1)
				break;
			cin >> c;

			trees[a].emplace_back(b, c);
			trees[b].emplace_back(a, c);
		}
	}

	findMaxDistance(1);

	cout << findMaxDistance(maxIndex);
}