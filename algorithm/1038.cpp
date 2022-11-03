#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void vplus(vector<int>& v, int p)
{
	v[0] += p;


	for (int i = 0; i < v.size(); ++i)
	{
		while (v[i] >= 10)
		{
			if (i == v.size() - 1)
			{
				v.push_back(1);
				v[i] -= 10;
			}
			else
			{
				v[i + 1]++;
				v[i] -= 10;
			}
		}
	}

}

void vprint(vector<int>& v)
{
	long long lo = 0;
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
	{
		lo *= 10;
		lo += (*iter);
	}
	cout << lo << "\n";
}

int isSorted(vector<int>& v, int& pp)
{
	int increas = -1;
	int p = 0;
	for (auto i : v)
	{
		if (i > increas)
			increas = i;
		else
		{
			pp = p;
			return false;
		}
		p++;
	}
	pp = -1;
	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	if (n >= 1023)
	{
		cout << "-1";
		return 0;
	}
	if (n < 10)
	{
		cout << n;
		return 0;
	}

	int idx = 0;
	vector<int> dcage;
	int p = -1;
	dcage.push_back(0);

	vplus(dcage, 1);
	idx++;

	while (true)
	{
		while (!isSorted(dcage, p))
		{
			dcage[p]++;
			dcage[p - 1] = 0;
			vplus(dcage, 0);
		}
		//vprint(dcage);

		if (idx == n)
		{
			vprint(dcage);
			break;
		}
		else
		{
			idx++;
			vplus(dcage, 1);
		}
	}
}