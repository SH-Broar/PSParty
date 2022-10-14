#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void manacher_palindrome(vector<int>& s, vector<int>& p)
{
	//r -> 현재까지 발견된 가장 오른쪽 팰린드롬 끝점
	//k -> 해당 팰린드롬 중심점
	int r = 0, k = 0;

	for (int i = 0; i < p.size(); ++i)
	{
		//팰린드롬 내의 글자라면 초기 값 어디선가 가져오기
		if (i <= r)
			p[i] = min(r - i, p[2 * k - i]);

		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < p.size() + 1
			&& s[i - p[i] - 1] == s[i + p[i] + 1])
		{
			p[i]++;
		}

		if (r < i + p[i])
		{
			//끝점 갱신
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


	int n;
	cin >> n;

	vector<int> str;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		str.push_back(c);
	}
	int newstr = -1;
	vector<int> newStr;
	newStr.push_back(-1);
	for (auto c : str)
	{
		newStr.push_back(c);
		newStr.push_back(-1);
	}


	int m;
	cin >> m;

	vector<int> p;
	p.resize(newStr.size(), 0);

	manacher_palindrome(newStr, p);

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		if (p[a + b - 1] >= b - a + 1)
			cout << "1\n";
		else
			cout << "0\n";
	}
}