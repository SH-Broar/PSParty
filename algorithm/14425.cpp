#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	set<string> con;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		con.insert(tmp);
	}

	int result = 0;

	for (int i = 0; i < m; i++)
	{
		string tmp;
		cin >> tmp;
		if (con.find(tmp) != con.end())
		{
			result++;
		}
	}

	cout << result;
}