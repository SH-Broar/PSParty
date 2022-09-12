#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string n;
	cin >> n;

	vector<int> alphas;
	alphas.resize('Z' - 'A' + 1);

	for (auto c : n)
	{
		alphas[c - 'A']++;
	}
	
	char odd = -1;
	for (int d=0; auto& c : alphas)
	{
		if (c % 2 == 1)
		{
			if (odd != -1)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else
			{
				odd = d + 'A';
				c--;
			}
		}
		
		c /= 2;

		d++;
	}
	string newer;
	for (int d = 0; auto c : alphas)
	{
		for (int i = 0; i < c; ++i)
		{
			newer += 'A' + d;
		}
		d++;
	}
	
	cout << newer;
	if (odd != -1)
		cout << odd;
	cout << string{ newer.rbegin(),newer.rend() };
}