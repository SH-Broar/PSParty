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
	
	cout << (2 << (n-1)) - 1 << "\n";	//�ϳ��� �̵� Ƚ��
	harnoi(n, 1, 3);
}

void harnoi(int tower,int from, int destination)
{
	if (tower == 1)
	{
		cout << from << " " << destination << "\n";
		return;
	}

	int newDestination = 6 - from - destination;	// 1 2 3�߿� from�� destination�� �ƴ� ��

	//�� ������ !destination���� �ű��
	harnoi(tower - 1, from, newDestination);
	//���� destination���� �ű��
	cout << from << " " << destination << "\n";
	//�� ���� �ִ� �κ��� destination���� �ű��
	harnoi(tower - 1, newDestination, destination);
}
