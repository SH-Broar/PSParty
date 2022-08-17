#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<int> parents;
queue<int> readyNodes;

void bfs();

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	edges.resize(n);
	parents.resize(n);

	for (int i = 0; i < n-1; ++i)
	{
		parents[i] = -1;
		int tx, ty;
		cin >> tx >> ty;
		edges[tx-1].push_back(ty-1);
		edges[ty-1].push_back(tx-1);
	}
	parents[n - 1] = -1;

	readyNodes.push(0);
	bfs();
	
	parents.erase(parents.begin());
	for (auto& r : parents)
	{
		cout << r+1 << "\n";
	}
}

void bfs()
{
	parents[0] = 0;
	while (!readyNodes.empty())
	{
		int index = readyNodes.front();
		readyNodes.pop();

		//if (parents[index] == -1)
		{
			for (auto& k : edges[index])
			{
				if (parents[k] == -1)
				{
					//cout << index+1 << " -> " << k+1 << "\n";
					parents[k] = index;
					readyNodes.push(k);
				}
			}
			
		}

	}
}