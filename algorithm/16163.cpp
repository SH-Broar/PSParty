#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

void manacher_palindrome(string s, vector<long long>& p)
{
	//r -> ������� �߰ߵ� ���� ������ �Ӹ���� ����
	//k -> �ش� �Ӹ���� �߽���
	long long r = 0, k = 0;

	for (long long i = 0; i < p.size(); ++i)
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

	vector<long long> p;
	p.resize(newstr.size(),1);

	manacher_palindrome(newstr, p);
	
	//for (auto& i : p)
	//{
	//	cout << i << " ";
	//}
	//cout << "\n";

	for_each(p.begin(), p.end(), [](auto& i) {
		i = (i + 1) / 2;
		});
	cout << accumulate(p.begin(),p.end(),(long long)0);
}