#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int roop, now, goal, up, down;
	cin >> roop >> now >> goal >> up >> down;
	
	queue<pair<int,int>> goElevator;
	goElevator.push({ now,0 });

	vector<int> selected;
	selected.resize(roop+1,-1);

	bool finder = false;

	while (!(goElevator.empty()))
	{
		auto nowOn = goElevator.front();
		goElevator.pop();

		if (nowOn.first == goal)
		{
			finder = true;
			cout << nowOn.second;
			break;
		}
		if (selected[nowOn.first] > 0)
			continue;

		selected[nowOn.first] = nowOn.second;

		if (nowOn.first + up <= roop)
		{
			goElevator.push({ nowOn.first + up, nowOn.second + 1 });
		}
		if (nowOn.first - down >= 1)
		{
			goElevator.push({ nowOn.first - down, nowOn.second + 1 });
		}
	}
	if (!finder)
	{
		cout << "use the stairs";
	}
}