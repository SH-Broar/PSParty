#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;

		for (int c = 0; c < s.size() - 2; c++)
		{
			if (s[c] == 'F' && s[c+1] == 'B' && s[c+2] == 'I')
			{
				cout << i + 1 << " ";
				result++;
				break;
			}
		}
	}

	if (result == 0)
	{
		cout << "HE GOT AWAY!";
	}
}