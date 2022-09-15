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
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		string rstr{ str.rbegin(),str.rend() };
		if (str == rstr)
		{
			cout << "1 ";
			if (str.size() % 2 == 1)
			{
				cout << (str.size() + 1) / 2;
			}
			else
			{
				cout << (str.size() / 2) + 1;
			}
		}
		else
		{
			cout << "0 ";
			int t = -1;
			int n = 0;
			do
			{
				n++;
				t++;
			} while (str[t] == rstr[t]);
			cout << n;
		}



		cout << "\n";
	}
}