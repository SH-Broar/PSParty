#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isHan(int c);

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;

	cin >> n;

	int count = 0;
	for (int i = n; i > 0; --i)
	{
		if (isHan(i))
		{
			count++;
		}
	}
	cout << count;
}

bool isHan(int c)
{
	int d = c;
	vector<int> digit;
	while (d != 0)
	{
		digit.push_back(d % 10);
		d /= 10;
	}
	if (digit.size() == 1)
		return true;

	bool ret = true;
	int beg = digit[1] - digit[0];
	
	for (auto iter = digit.begin(); iter != digit.end() - 1; iter++)
	{
		if (*(iter + 1) - *iter != beg)
			ret = false;
	}
	
	return ret;
}