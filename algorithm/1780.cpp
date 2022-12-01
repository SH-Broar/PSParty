#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
int xx=0, yy=0, zz=0;

void finder(int x, int y, int nlevel)
{
	int mid = (nlevel - 1) / 2;
	int all = paper[x][y];
	int diff = false;
	for (int i = 0; i < nlevel; ++i)
	{
		for (int k = 0; k < nlevel; ++k)
		{
			if (all != paper[x + i][y + k])
			{
				diff = true;
				break;
			}
		}
	}

	if (diff)
	{
		int llevel = nlevel / 3;
		finder(x, y, llevel);
		finder(x+llevel, y, llevel);
		finder(x+(2*llevel), y, llevel);

		finder(x, y + llevel, llevel);
		finder(x + llevel, y + llevel, llevel);
		finder(x + (2 * llevel), y + llevel, llevel);

		finder(x, y + (2 * llevel), llevel);
		finder(x + llevel, y + (2 * llevel), llevel);
		finder(x + (2 * llevel), y + (2 * llevel), llevel);
	}
	else
	{
		if (all == -1)
			xx++;
		else if (all == 0)
			yy++;
		else
			zz++;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	paper.resize(n);
	for (auto& v : paper)
		v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			int t;
			cin >> t;
			paper[i][k] = t;
		}
	}
	finder(0,0,n);
	cout << xx << "\n" << yy << "\n" << zz;
}