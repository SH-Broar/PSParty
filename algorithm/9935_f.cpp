#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string base;
	string frula;
	cin >> base >> frula;

	string catcher = "";
	vector<int>nexter;
	nexter.resize(base.size() + 1);
	for (int i = 0; i <= base.size(); ++i)
	{
		nexter[i] = i + 1;
	}

	int tracker = 0;

	int front = 0;
	int pre = 0;
	for (int i = 0; i <= base.size();)
	{
		if (i > 0)
		{
			if (frula[tracker] == base[i - 1])
			{
				if (tracker == 0)
					front = pre;
				catcher += base[i - 1];
				tracker++;
			}
			else
			{
				tracker = 0;
				catcher = "";
				if (frula[tracker] == base[i - 1])
				{
					if (tracker == 0)
						front = pre;
					catcher += base[i - 1];
					tracker++;
				}
			}
		}

		if (catcher == frula)
		{
			nexter[front] = nexter[i];
			i = max(front-((int)frula.size()), 0);
			pre = i;
			front = 0;
			catcher = "";
			tracker = 0;
		}
		else
		{
			pre = i;
			i = nexter[i];
		}
		//for (int i = 0; i <= base.size(); ++i)
		//{
		//	cout << nexter[i] << " ";
		//}
		//cout << endl;
	}

	//for (int i = 0; i <= base.size(); ++i)
	//{
	//	cout << nexter[i] << " ";
	//}
	if (nexter[0] == base.size()+1)
		cout << "FRULA";
	else
	{
		int i = 0;
		while (i <= base.size())
		{
			if (i > 0)
				cout << base[i - 1];
			i = nexter[i];
		}
	}
}