#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tay;
		cin >> tay;
		multiset<int,greater<>> pq;

		for (int k = 0; k < tay; k++)
		{
			string oper;
			int num;
			cin >> oper >> num;
			if (oper == "I")
			{
				pq.insert(num);
			}
			else if (oper == "D")
			{
				if (!pq.empty())
				{
					if (num == 1)
					{
						pq.erase(pq.begin());
					}
					else if (num == -1)
					{
						pq.erase(--pq.end());
					}
				}
			}
		}
		if (pq.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << *(pq.begin()) << " " << *(--pq.end()) << "\n";
		}
	}
}