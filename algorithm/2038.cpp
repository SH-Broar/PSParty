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
	int fraps = n;
	
	vector<int> golom;
	int inserte = 0;
	int resulte = 0;
	golom.push_back(1);
	golom.push_back(2);

	for (int i = 1; i <= fraps; i++)
	{
		n -= i * golom[i-1];
		if (n <= 0)
		{
			n += i * golom[i - 1];
			int catcher = n / i;
			if (n % i == 0)
				cout << resulte + catcher;
			else
				cout << resulte + catcher +1;
			break;
		}
		resulte += golom[i - 1];

		for (int inner = 1; inner <= golom[i-1]; inner++)
		{
			if (golom.size() > inserte)
			{
				golom[inserte] = i;
			}
			else
			{
				golom.push_back(i);
			}
			inserte++;
		}
	}
}