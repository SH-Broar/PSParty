#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<int> liner;
	liner.resize(n+1,10000000);
	vector<int> header;
	header.resize(n + 1, -1);

	liner[n] = 0;

	queue<int> nexter;
	nexter.push(n);

	while (!nexter.empty() && header[1] == -1)
	{
		int t = nexter.front();
		nexter.pop();

		if (t % 3 == 0 && t > 0)
		{
			if (liner[t / 3] > liner[t] + 1)
			{
				liner[t / 3] = liner[t] + 1;
				header[t / 3] = t;
				nexter.push(t / 3);
			}
		}
		if (t % 2 == 0 && t > 0)
		{
			if (liner[t / 2] > liner[t] + 1)
			{
				liner[t / 2] = liner[t] + 1;
				header[t / 2] = t;
				nexter.push(t / 2);
			}
		}
		if (t > 1)
		{
			if (liner[t - 1] > liner[t] + 1)
			{
				liner[t - 1] = liner[t] + 1;
				header[t -1] = t;
				nexter.push(t - 1);
			}
		}
	}

	cout << liner[1] << "\n";
	vector<int> result;
	int courage = 1;
	while (courage != -1)
	{
		result.push_back(courage);
		courage = header[courage];
	}
	for (auto i = result.rbegin(); i != result.rend(); i++)
	{
		cout << (*i) << " ";
	}
}