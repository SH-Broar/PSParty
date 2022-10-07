#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> v;
//set<vector<int>> s;
int n, m;

void dfs(int now, vector<int> str, vector<char> vc)
{
	if (str.size() >= m)
	{
		//int p = s.size();
		//s.insert(str);
		//if (p != s.size())
		{
			for (auto& v : str)
				cout << v << " ";
			cout << "\n";
		}
		return;
	}

	int pv = 0;
	for (int k = now; k < n; ++k)
	{
		if (!vc[k] && v[k] != pv)
		{
			vector<int> cpy;
			cpy = str;
			cpy.push_back(v[k]);
			pv = v[k];
			vector<char> tc;
			tc = vc;
			tc[k] = 1;
			dfs(k, cpy, tc);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	vector<int> tmp;
	vector<char> tm;
	tm.resize(n);
	dfs(0, tmp, tm);
}