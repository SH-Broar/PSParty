#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void manacher_palindrome(string s, vector<int>& p)
{
	//r -> ������� �߰ߵ� ���� ������ �Ӹ���� ����
	//k -> �ش� �Ӹ���� �߽���
	int r = 0, k = 0;

	for (int i = 0; i < p.size(); ++i)
	{
		//�Ӹ���� ���� ���ڶ�� �ʱ� �� ��𼱰� ��������
		if (i <= r)
			p[i] = min(r - i, p[2 * k - i]);

		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < p.size()
			&& s[i - p[i] - 1] == s[i + p[i] + 1])
		{
			p[i]++;
		}

		if (r < i + p[i])
		{
			//���� ����
			r = i + p[i];
			k = i;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string str;
	cin >> str;
	string newstr = "#";
	for (auto c : str)
	{
		newstr += c;
		newstr += "#";
	}
	//cout << newstr;
	//cout << "\n";

	vector<int> p;
	p.resize(newstr.size(),0);

	manacher_palindrome(newstr, p);
	
	//for (auto& i : p)
	//{
	//	cout << i << " ";
	//}
	//cout << "\n";
	cout << *(max_element(p.begin(),p.end()));
}