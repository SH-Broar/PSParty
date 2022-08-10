#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	queue<int> crow;
	vector<int> zone;
	zone.resize(100001,-1);
	crow.push(a);
	zone[a] = 0;

	vector<int> inserter;
	inserter.resize(100001, -1);
	inserter[a] = -2;

	vector<int> resulter;
	while (true)
	{
		int top = crow.front();
		crow.pop();
		if (top == b)
		{
			cout << zone[top] << "\n";
			int cas = top;
			resulter.push_back(cas);
			while (inserter[cas] != -2)
			{
				resulter.push_back(inserter[cas]);
				cas = inserter[cas];
			}
			break;
		}
		
		if (top -1 >= 0 && zone[top - 1] == -1)
		{
			crow.push(top - 1);
			zone[top - 1]= zone[top] +1;
			inserter[top - 1] = top;
		}
		if (top * 2 <= 100000 && zone[top * 2] == -1)
		{
			crow.push(top * 2);
			zone[top * 2] = zone[top] + 1;
			inserter[top *2] = top;
		}
		if (top+1 <= 100000 && zone[top + 1] == -1)
		{
			crow.push(top + 1);
			zone[top + 1] = zone[top] + 1;
			inserter[top + 1] = top;
		}
	}

	for (auto iter = resulter.rbegin(); iter != resulter.rend(); ++iter)
	{
		cout << *iter << " ";
	}
}