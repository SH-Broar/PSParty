#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int six = 0;
	int step = 0;
	while (six != n)
	{
		int continuousSix = 0;
		int tmpStep = step;

		while (tmpStep > 0)
		{
			if (tmpStep % 10 == 6)
			{
				continuousSix++;
				if (continuousSix == 3)
				{
					six++;
					break;
				}
			}
			else
			{
				continuousSix = 0;
			}
			tmpStep /= 10;
		}
		step++;
	}

	cout << step-1;
}