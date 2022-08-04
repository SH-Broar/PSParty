#include <stdio.h>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;


int main()
{
	int nums = 0;
	vector<int> vec;
	scanf("%d", &nums);
	vec.reserve(nums);

	for (int i = 0; i < nums; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		vec.emplace_back(tmp);
	}
	sort(vec.begin(), vec.end());

	double sum = accumulate(vec.begin(), vec.end(), 0.0);
	double average = round(sum / vec.size());
	int av = (int)average;
	printf("%d\n", av);

	printf("%d\n", vec[nums / 2]);

	if (vec.size() == 1)
	{
		printf("%d\n", vec[0]);
	}
	else
	{
		int max = 1;
		int line = 0;

		int prev = vec[0];

		vector<int> list;

		for (int i : vec)
		{
			if (prev != i)
			{
				if (line > max)
				{
					max = line;
				}
				line = 1;
			}
			else
			{
				line++;
			}
			prev = i;
		}
		if (line > max)
			max = line;

		line = 0;
		prev = vec[0];
		for (int i : vec)
		{
			if (prev != i)
			{
				if (line == max)
				{
					list.push_back(prev);
				}
				line = 1;
			}
			else
			{
				line++;
			}
			prev = i;
		}
		if (line == max)
			list.push_back(prev);

		if (list.size() > 1)
			printf("%d\n",list[1]);
		else
			printf("%d\n", list[0]);
	}


	printf("%d", vec[nums - 1] - vec[0]);

}