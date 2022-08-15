#include <iostream>

using namespace std;

void harnoi(int tower,int from, int destination);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	
	cout << (2 << (n-1)) - 1 << "\n";	//하노이 이동 횟수
	harnoi(n, 1, 3);
}

void harnoi(int tower,int from, int destination)
{
	if (tower == 1)
	{
		cout << from << " " << destination << "\n";
		return;
	}

	int newDestination = 6 - from - destination;	// 1 2 3중에 from도 destination도 아닌 곳

	//내 위에를 !destination으로 옮긴다
	harnoi(tower - 1, from, newDestination);
	//나를 destination으로 옮긴다
	cout << from << " " << destination << "\n";
	//내 위에 있던 부분을 destination으로 옮긴다
	harnoi(tower - 1, newDestination, destination);
}
