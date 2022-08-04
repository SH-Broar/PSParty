#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void isPrime(vector<int>& n, int num, int numEnd);

int main()
{
	int num = 0;
	int numEnd = 0;
	vector<int> nums;
	cin >> num;
	cin >> numEnd;
	nums.reserve(numEnd - num);

	for (int i = num; i <= numEnd; i++)
	{
		nums.emplace_back(i);
	}

	isPrime(nums,num,numEnd);

}

void isPrime(vector<int>& n,int num, int numEnd)
{
	for (auto j : n)
	{
		if (j == 1)
			continue;
		bool isPrime = true;
		for (int i = 2; i <= sqrt(j); i++)
		{
			if (j % i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			printf("%d\n", j);
	}

}