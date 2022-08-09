#include <iostream>
#include <vector>
using namespace std;

void recursive(int x, int y, int factor);

vector<vector<bool>> printer{ false };

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	printer.resize(n);
	for (int i = 0; i < n; i++)
	{
		printer[i].resize(n);
	}

	recursive((n + 1) / 2, (n + 1) / 2, n);

	for (auto& list : printer)
	{
		for (bool b : list)
		{
			if (b)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}

void recursive(int x, int y, int factor)
{
	if (factor <= 1)
	{
		printer[x-1][y-1] = true;
		return;
	}
	int unitFactor = factor/3;

	recursive(x - unitFactor, y - unitFactor, unitFactor);
	recursive(x, y - unitFactor, unitFactor);
	recursive(x + unitFactor, y - unitFactor, unitFactor);

	recursive(x - unitFactor, y, unitFactor);

	recursive(x + unitFactor, y, unitFactor);

	recursive(x - unitFactor, y + unitFactor, unitFactor);
	recursive(x, y + unitFactor, unitFactor);
	recursive(x + unitFactor, y + unitFactor, unitFactor);
}