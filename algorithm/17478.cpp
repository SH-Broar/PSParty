#include <iostream>

using namespace std;

void p(int t,int h);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);


	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	p(n,n);

}

void p(int t,int h)
{
	if (t == 0)
	{
		for (int count = 0; count < h * 4; count++)
			cout << "_";
		cout << "\"����Լ��� ������?\"\n";
		for (int count = 0; count < h * 4; count++)
			cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else
	{
		for (int count = 0; count < (h - t) * 4; count++)
			cout << "_";
		cout << "\"����Լ��� ������?\"\n";
		for (int count = 0; count < (h - t) * 4; count++)
			cout << "_";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int count = 0; count < (h - t) * 4; count++)
			cout << "_";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int count = 0; count < (h - t) * 4; count++)
			cout << "_";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		p(t - 1,h);
	}
	for (int count = 0; count < (h - t) * 4; count++)
		cout << "_";
	cout << "��� �亯�Ͽ���.\n";
}