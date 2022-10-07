#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> v;
int n, m;

void dfs(vector<int> str)
{
	if (str.size() >= m)
	{
		//copy(str.begin(), str.end(), ostream_iterator<int>(cout," "));
		for (auto& v : str)
			cout << v << " ";
		cout << "\n";
		return;
	}

	for (int k = 0; k < n; ++k)
	{
		vector<int> cpy;
		cpy = str;
		cpy.push_back(v[k]);
		dfs(cpy);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	//copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	vector<int> tmp;
	dfs(tmp);
}