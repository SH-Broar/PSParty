#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct body
{
	int index;
	int weight;
	int height;

	body(int a,int b, int c)
	{
		index = a;
		weight = b;
		height = c;
	}

};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int a, b;
	cin >> n;

	vector<body> ps;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		
		ps.emplace_back(i, a, b);
	}
	
	for (body& b : ps)
	{
		int rank = 1;
		for (body& c : ps)
		{
			if (b.index != c.index)
			{
				if (c.height > b.height && c.weight > b.weight)
				{
					rank++;
				}
			}
		}
		cout << rank << " ";
	}
}