#include <iostream>
#include <queue>
using namespace std;

int bfs();

struct cell
{
	int x;
	int connected;
	int visitLevel;
};

queue<int> commandments;
cell board[101];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);


	for (int i = 0; i <= 100; i++)
	{
		board[i].x = i;
	}

	int a, b;
	cin >> a >> b;

	int from;
	int to;
	for (int i = 0; i < a; ++i)
	{
		cin >> from >> to;
		board[from].connected = to;
	}
	for (int i = 0; i < b; ++i)
	{
		cin >> from >> to;
		board[from].connected = to;
	}

	commandments.push(1);

	int result = bfs();
	cout << result;
}

int bfs()
{
	while (true)
	{
		int top = commandments.front();
		commandments.pop();

		if (top == 100)
			return board[top].visitLevel;
				
		if (board[top].connected > 0)
		{
			board[board[top].connected].visitLevel = board[top].visitLevel;
			top = board[top].connected;
		}

		
		for (int i = 1; i <= 6; i++)
		{
			if (top + i <= 100)
			{
				if (board[top + i].visitLevel == 0 || board[top + i].visitLevel == 0 > board[top].visitLevel + 1)
				{
					board[top + i].visitLevel = board[top].visitLevel + 1;
					commandments.push(top + i);
				}
			}
		}
	}
}