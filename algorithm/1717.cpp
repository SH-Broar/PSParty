#include <iostream>
#include <vector>
using namespace std;

int findParent(int s);

vector<int> nodes;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		nodes.push_back(i);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0)
		{
			int newa = findParent(a);
			int newb = findParent(b);
			if (newa > newb)
			{
				nodes[newa] = newb;
			}
			else
			{
				nodes[newb] = newa;
			}
		}
		else if (oper == 1)
		{
			if (findParent(a) == findParent(b))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}

int findParent(int s)
{
	if (nodes[s] == s)
		return s;
	else
		return nodes[s] = findParent(nodes[s]);
}