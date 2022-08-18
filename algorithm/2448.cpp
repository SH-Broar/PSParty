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
	printer.resize(2*n);
	for (int i = 0; i < 2*n; i++)
	{
		printer[i].resize(2*n);
	}

	recursive(n, n, n);



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2*n; j++)
		{
			if (printer[j][i])
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	
}

void recursive(int x, int y, int factor)
{
	if (factor <= 3)
	{
		y = y - 2;
		x = x - 1;
		printer[x][y-1] = true;
		printer[x - 1][y] = true;
		printer[x + 1][y] = true;
		printer[x - 2][y + 1] = true;
		printer[x - 1][y +1] = true;
		printer[x ][y + 1] = true;
		printer[x + 1][y + 1] = true;
		printer[x + 2][y + 1] = true;
		return;
	}
	int unitFactor = factor/2;

	recursive(x + unitFactor, y, unitFactor);
	recursive(x - unitFactor, y, unitFactor);
	recursive(x, y - unitFactor, unitFactor);
}