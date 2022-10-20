#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m;
		cin >> m;

		map<string, int> umap;
		for (int k = 0; k < m; ++k)
		{
			string f, s;
			cin >> f >> s;

			umap[s] ++;
		}
		
		int ret = 1;
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
		{
			ret *= (*iter).second + 1;
		}
		cout << ret - 1<< "\n";
	}
}