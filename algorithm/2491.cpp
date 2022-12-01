#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	int mx=0, my=0;
	vector<int> ns;
	vector<int> longs;
	longs.resize(n);
	vector<int> dlongs;
	dlongs.resize(n);
	while (n--)
	{
		int a;
		cin >> a;
		ns.push_back(a);
	}
	for (int i = 0; i < ns.size(); ++i)
	{
		int x = 1, y = 1;
		if (i > 0)
		{
			if (ns[i - 1] <= ns[i])
			{
				x = longs[i - 1] + 1;
			}

			if (ns[i - 1] >= ns[i])
			{
				y = dlongs[i - 1] + 1;
			}
		}
		if (x > mx)
			mx = x;
		if (y > my)
			my = y;
		longs[i] = x;
		dlongs[i] = y;
	}

	cout << (mx > my ? mx : my);
}