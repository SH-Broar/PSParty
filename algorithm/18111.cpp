#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int a, b;
	cin >> a >> b >> n;

	int minBlocks = 300;
	int maxBlocks = 0;
	vector<vector<int>> maps;
	maps.resize(a);
	for (int i = 0; i < a; i++)
	{
		maps[i].resize(b);
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int tmp;
			cin >> tmp;
			maps[i][j] = tmp;

			if (tmp < minBlocks)
				minBlocks = tmp;
			if (tmp > maxBlocks)
				maxBlocks = tmp;
		}
	}

	//
	int r_time=-1;
	int r_height=0;
	for (int block = minBlocks; block <= maxBlocks; block++)
	{
		//
		int times = 0;
		int stocks = n;
		bool could = true;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if (maps[i][j] > block)
				{
					times += (maps[i][j] - block)*2;
					stocks += maps[i][j] - block;
				}				
			}
		}

		for (int i = 0; i < a; i++)
		{
			if (could)
			{
				for (int j = 0; j < b; j++)
				{
					if (maps[i][j] < block)
					{
						times += block - maps[i][j];
						stocks -= block -maps[i][j];

						if (stocks < 0)
						{
							could = false;
							break;
						}
					}
				}
			}
		}

		if (could)
		{
			if (times <= r_time || r_time == -1)
			{
				r_time = times;
				r_height = block;
			}
		}
	}

	cout << r_time << " " << r_height;
}