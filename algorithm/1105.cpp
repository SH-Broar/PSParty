#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	string n, m;
	cin >> n >> m;
	
	int ret = 0;
	if (n.size() == m.size())
	{
		for (int i = 0; i < n.size(); ++i)
		{
			if (n[i] == m[i])
			{
				if (n[i] == '8')
					ret++;
			}
			else
				break;
		}
	}
	cout << ret;
}