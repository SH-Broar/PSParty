#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		string oper;
		cin >> oper;

		int n;
		cin >> n;

		string d;
		cin >> d;

		deque<int> arr;

		bool s = false;
		int tmp = 0;
		for (auto c : d)
		{
			if (c == '[')
			{
				s = true;
				continue;
			}

			if (c == ']')
			{
				if (tmp)
					arr.push_back(tmp);
				s = false;
			}

			if (s == true)
			{
				if (c >= '0' && c <= '9')
				{
					tmp *= 10;
					tmp += c - '0';
				}
				else if (c == ',')
				{
					arr.push_back(tmp);
					tmp = 0;
				}
			}			
		}
		

		bool order = 0;
		bool error = 0;
		
		for (auto c : oper)
		{
			if (c == 'R')
			{
				order ^= 1;
			}
			else if (c == 'D')
			{
				if (arr.size())
				{
					if (order)
					{
						arr.pop_back();
					}
					else
					{
						arr.pop_front();
					}
				}
				else
				{
					error = 1;
					break;
				}
			}
		}

		if (error)
		{
			cout << "error\n";
		}
		else
		{
			cout << "[";
			if (order)
			{
				for (auto iter = arr.rbegin(); iter != arr.rend(); iter++)
				{
					cout << (*iter);
					if (iter + 1 != arr.rend())
						cout << ",";
				}
			}
			else
			{
				for (auto iter = arr.begin(); iter != arr.end(); iter++)
				{
					cout << (*iter);
					if (iter + 1 != arr.end())
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}