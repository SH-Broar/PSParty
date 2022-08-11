#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> papers;
int result[2]{0,0};

void slice(int x, int y, int size);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	papers.resize(n);
	for (int i = 0; i < n; ++i)
	{
		papers[i].resize(n);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; k++)
		{
			int op;
			cin >> op;
			papers[k][i] = op;
		}
	}

	slice(0,0,n);

	cout << result[0] << "\n" << result[1];
}

void slice(int x,int y,int size)
{
	if (size == 1)
	{
		result[papers[x][y]]++;
	}
	else
	{
		int symm = true;
		int tag = -1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (tag == -1)
				{
					tag = papers[i+x][j+y];
				}
				else
				{
					if (tag != papers[i + x][j + y])
					{
						symm = false;
						break;
					}
				}
			}
			if (!symm)
				break;
		}
		if (tag == -1)
			return;

		if (symm)
		{
			result[tag]++;
			return;
		}
		else
		{
			slice(x, y, size / 2);
			slice(x+size/2, y, size / 2);
			slice(x, y + size / 2, size / 2);
			slice(x + size / 2, y + size / 2, size / 2);
		}

	}
}