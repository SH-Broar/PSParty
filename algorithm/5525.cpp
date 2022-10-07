#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	int s;
	cin >> s;

	string str;
	cin >> str;

	string checker = "I";
	for (int i = 0; i < n; ++i)
		checker += "OI";

	char pre = 'X';
	int catcher = 0;
	int total = 0;
	for (auto c : str)
	{
		if (c == 'O' && pre == 'I')
		{
			catcher++;
		}
		else if (c == 'I' && pre == 'O')
		{
			if (catcher == n)
			{
				total++;
				catcher--;
			}
		}
		else
		{
			catcher = 0;
		}
		pre = c;
	}
	cout << total;
}