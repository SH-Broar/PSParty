#include <iostream>
#include <vector>
using namespace std;

void dfs(int preVisited, int top);

vector<vector<bool>> nodesVisits;
int n;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	nodesVisits.resize(n, vector<bool>{});
	for (int i = 0; i < n; i++)
	{
		nodesVisits[i].resize(n);
	}

	dfs(n - 1, 0);

	cout << "a1";
}

void dfs(int preVisited, int top)
{
	if (!(preVisited == 0 && top == 0))
	{
		nodesVisits[top][preVisited] = true;
		nodesVisits[preVisited][top] = true;

		cout << "a" << top + 1 << " ";
	}

	for (int i = 0; i < n; i++)
	{
		if (top != i)
		{
			if (!nodesVisits[top][i])
			{
				dfs(top, i);
			}
		}
	}

}