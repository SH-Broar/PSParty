#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n >> m;
	
	stack<pair<int,string>> s;
	
	for (int i = n; i >= 1; --i)
	{
		s.push({ i, "" });
	}
	while (!(s.empty()))
	{
		auto sets = s.top();
		s.pop();
		sets.second += (sets.first + '0');

		if (sets.second.size() < m)
		{
			for (int i = n; i >= sets.first; --i)
			{
				s.push({ i, sets.second });
			}
		}
		else
		{
			for (auto c : sets.second)
			{
				cout << c << " ";
			}
			cout << "\n";
		}
	}
}