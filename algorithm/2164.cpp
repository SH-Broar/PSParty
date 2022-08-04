#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int cards = 0;
	cin >> cards;

	queue<int> q;

	for (int i = 1; i <= cards; i++)
	{
		q.push(i);
	}

	int last = 0;
	while (!q.empty())
	{
		last = q.front();
		q.pop();
		if (q.empty())
			break;
		q.push(q.front());
		q.pop();
	}
	cout << last;
}