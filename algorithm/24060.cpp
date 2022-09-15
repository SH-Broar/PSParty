#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int s;
int taer = 0;

vector<int> v;

void merge(int p, int q, int r)
{
	vector<int> tmp;

	int i = p;
	int j = q + 1;
	int t = 0;
	
	while (i <= q && j <= r)
	{
		if (v[i] <= v[j])
		{
			tmp.push_back(v[i++]);
		}
		else
		{
			tmp.push_back(v[j++]);
		}
	}
	while (i <= q)
		tmp.push_back(v[i++]);
	while (j <= r)
		tmp.push_back(v[j++]);
	i = p;
	t = 0;
	while (i <= r)
	{
		v[i] = tmp[t++];
		taer++;
		if (s == taer)
		{
			cout << v[i];
			exit(0);
		}

		i++;
	}
}

void merge_sort(int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	
	if (s > n * log2(n))
		cout << "-1";
	else
	{
		merge_sort(0, v.size() - 1);
		if (s < taer)
			cout << "-1";
	}
}