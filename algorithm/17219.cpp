#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;

	unordered_map<string,string> maps;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;

		string pass;
		cin >> pass;
		
		maps[tmp] = pass;
	}

	while (m--)
	{
		string tmp;
		cin >> tmp;
		auto p = (*maps.find(tmp)).second;
		cout << p << "\n";
	}
}