#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string theme;
	cin >> theme;
	
	int p = 0;
	bool flag = false;
	int ret = 0;

	for (auto c : theme)
	{
		if (c >= '0' && c <= '9')
		{
			p *= 10;
			p += c - '0';
		}
		else
		{
			if (!flag)
			{
				ret += p;
			}
			else
			{
				ret -= p;
			}
			if (c=='-')
				flag = true;
			p = 0;
		}
	}
	if (flag)
		ret -= p;
	else
		ret += p;
	cout << ret;
}