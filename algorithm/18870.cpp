#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Vdata
{
	int index;
	int n;

	Vdata(int a, int b)
	{
		index = a;
		n = b;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int tmp;
	cin >> n;
	vector<Vdata> Vlist;
	vector<int> compressed;
	compressed.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		Vlist.emplace_back(i, tmp);
	}
	
	sort(Vlist.begin(), Vlist.end(), [](auto& a, auto& b) {
		return a.n < b.n;
		});

	compressed[Vlist[0].index] = 0;
	for (int i=1;i<Vlist.size();++i)
	{
		if (Vlist[i].n == Vlist[i - 1].n)
		{
			compressed[Vlist[i].index] = compressed[Vlist[i - 1].index];
		}
		else
		{
			compressed[Vlist[i].index] = compressed[Vlist[i - 1].index] +1;
		}
	}

	for (auto& c : compressed)
	{
		cout << c << " ";
	}
}