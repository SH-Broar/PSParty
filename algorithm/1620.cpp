#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<int, string> con;
	map<string, int> rev;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		con.insert(pair<int, string>(i+1,tmp));
		rev.insert(pair<string, int>(tmp, i + 1));
	}

	for (int i = 0; i < m; i++)
	{
		string tmp;
		cin >> tmp;

		try {
			int cover = stoi(tmp);
			cout << con[cover] << "\n";
		}
		catch (...)
		{
			cout << rev[tmp] << "\n";
		}
	}
}