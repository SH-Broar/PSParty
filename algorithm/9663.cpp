#include <iostream>
#include <vector>
using namespace std;

int n;
void nQueen(int c);
bool checkBoard(int c, int i);
vector<vector<int>> boards;

int result = 0;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	boards.resize(n);
	for (int i = 0; i < n; ++i)
	{
		boards[i].resize(n);
	}

	nQueen(n-1);
	cout << result;
}

void nQueen(int c)
{
	for (int i = 0; i < n; i++)
	{
		boards[c][i] = 1;
		if (checkBoard(c, i))
		{
			if (c == 0)
			{
				result++;
			}
			else
				nQueen(c - 1);
		}
		boards[c][i] = 0;
	}
}

bool checkBoard(int c, int i)
{
	for (int v = n-1; v >= 0; v--)
	{
		if (boards[v][i] == 1 && v != c)
		{
			return false;
		}
		else if (boards[c][v] == 1 && v != i)
		{
			return false;
		}
		else if (i + c - v >= 0 && i + c - v < n && boards[v][i+c-v] == 1 && v != c)
		{
			return false;
		}
		else if (i - c + v >= 0 && i - c + v < n && boards[v][i-c+v] == 1 && v != c)
		{
			return false;
		}
	}
	return true;

}