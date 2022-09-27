#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

deque<char> two;
deque<char> tmp;
long long ones = 0;

void change(long long d)
{
	if (d > 1) change(d / 2);
	tmp.push_back(d%2);
	if (d%2)
		ones++;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long totals = 0;

	long long n, k;
	cin >> n >> k;

	change(n);
	two = deque<char>{ tmp.rbegin(),tmp.rend() };

	while (ones > k)
	{
		for (int i=0;i<two.size()-1;++i)
		{
			//for (auto& v : two)
			//	cout << "- " << v << " ";
			//cout << endl;
			if (two[i])
			{
				totals += pow(2, i);
				//cout << i << " " << pow(2, i) << endl;
				two[i] = 0;
				ones--;
				two[i + 1] += 1;
				int next = i + 1;
				while (two[next] > 1)
				{
					two[next] = 0;
					ones--;
					two[next + 1] += 1;
					next++;
				}
				ones++;
				break;
			}
		}
	}

	cout << totals;
}