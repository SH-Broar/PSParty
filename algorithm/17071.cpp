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

	queue<pair<int,int>> crow;
	vector<int> OddZone;
	vector<int> EvenZone;
	OddZone.resize(500001, -1);
	EvenZone.resize(500001, -1);
	crow.push(pair<int,int>(a,0));
	EvenZone[a] = 0;

	int resultOddNums = -1;
	int resultEvenNums = -1;
	while (!crow.empty())
	{
		auto& top = crow.front();
		crow.pop();

		int first = top.first;
		int second = top.second;
		int courage = b + (second * (second + 1)) / 2;

		//if (second <= 3)
		//cout << first << " " << courage << " " << second << "\n";
		if (courage > 500000)
			continue;

		if ((second % 2) == 1)	//odd
		{
			if (resultOddNums != -1 || (resultEvenNums != -1 && second >= resultEvenNums))
				continue;
			if (resultOddNums == -1 && (OddZone[courage] != -1 || first == courage))
			{
				//cout << OddZone[courage] << endl;
				resultOddNums = second;
				continue;
			}

			OddZone[first] = second;

			if (first - 1 >= second && EvenZone[first - 1] == -1)
			{
				crow.push(pair<int,int>(first - 1,second+1));
				//OddZone[first - 1] = second + 1;
			}

			if (first * 2 <= 500000 && EvenZone[first * 2] == -1 && first != 0)
			{
				crow.push(pair<int, int>(first * 2, second + 1));
				//OddZone[first * 2] = second + 1;
			}

			if (first + 1 <= 500000 && first +1 >= second && EvenZone[first + 1] == -1 || first == 0)
			{
				crow.push(pair<int, int>(first + 1, second + 1));
				//OddZone[first + 1] = second + 1;
			}
		}
		else
		{
			if (resultEvenNums != -1 || (resultOddNums != -1 && second >= resultOddNums))
				continue;
			if (resultEvenNums == -1 && (EvenZone[courage] != -1 || first == courage))
			{
				//cout << courage << ".." << endl;
				resultEvenNums = second;
				continue;
			}

			EvenZone[first] = second;

			if (first - 1 >= second && OddZone[first - 1] == -1)
			{
				crow.push(pair<int, int>(first - 1, second + 1));
				//EvenZone[first - 1] = second + 1;
			}

			if (first * 2 <= 500000 && OddZone[first * 2] == -1 && first != 0)
			{
				crow.push(pair<int, int>(first * 2, second + 1));
				//EvenZone[first * 2] = second + 1;
			}

			if (first + 1 <= 500000 && first + 1 >= second && OddZone[first + 1] == -1 || first == 0)
			{
				crow.push(pair<int, int>(first + 1, second + 1));
				//EvenZone[first + 1] = second + 1;
			}
		}

	}
	if (resultOddNums == -1 && resultEvenNums == -1)
	{
		cout << "-1";
	}
	else if (resultOddNums == -1)
	{
		cout << resultEvenNums;
	}
	else if (resultEvenNums == -1)
	{
		cout << resultOddNums;
	}
	else
	{
		cout << (resultEvenNums < resultOddNums ? resultEvenNums : resultOddNums);
	}
}