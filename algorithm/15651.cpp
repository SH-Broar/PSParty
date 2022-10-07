#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void dfs(int i,string str)
{
	if (i >= m)
	{
		cout << str << "\n";
		return;
	}

	for (int k = 0; k < n; ++k)
	{
		string tmp = str;
		tmp += v[k]+'0';
		tmp += " ";
		dfs(i + 1, tmp);
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
		v.push_back(i + 1);
	}
	dfs(0,"");
}