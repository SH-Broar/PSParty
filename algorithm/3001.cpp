#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> cage;

int types(long long a, int b)
{
	int idx =0;
	long long tmp = a;
	long long front = 0;
	vector<int> v;
	while (tmp)
	{
		front = tmp;
		v.push_back(tmp%10);
		tmp /= 10;
		idx++;
	}

	cage.resize(17);
	for (auto& v : cage)
	{
		v.resize(136, 0);
	}
	for (int k = 1; k < 10; ++k)
	{
		cage[1][k] = 1;
	}

	for (int i = 1; i < idx; ++i)
	{
		for (int k = 1; k <= 9 * i; ++k)
		{
			if (!cage[i][k])
			{
				for (int o = 0; o <= 9; ++o)
				{
					if (k - o > 0)
					{
						cage[i][k] += cage[i - 1][k - o];
					}
				}
			}
		}
	}

	for (int i = 0; i < idx; ++i)
	{

	}
	for (int t = b; t >= b - 9; --t)
	{
		if (t > 0)
		{
			cage[idx - 1][t - front];
		}
	}

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	long long A, B, S;
	cin >> A >> B >> S;





	
	
	/*long long idx = (S - 1) / 9 + 1;
	long long starter = 0;

	if (A < pow(10ll, (idx - 1)))
	{
		starter = pow(10ll, (idx - 1));
	}
	else
	{
		int checker = 0;
		int tmp = A;
		int tidx = 0;
		while (tmp)
		{
			tidx++;
			checker += tmp % 10;
			tmp /= 10;
		}
		if (checker > S)
		{
			starter = pow(10ll, tidx);
		}
		else
		{
			starter = A;
		}
	}

	vector<int> distracter;
	int p_sum = 0;
	while (starter)
	{
		distracter.push_back(starter % 10);
		p_sum += starter % 10;
		starter /= 10;
	}

	int detacter = 0;
	while (p_sum < S)
	{
		if (distracter[detacter] == 9)
			detacter++;

		distracter[detacter]++;
		p_sum++;
	}

	for (auto iter = distracter.rbegin(); iter != distracter.rend(); ++iter)
	{
		cout << (*iter);
	}*/

}