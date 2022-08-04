#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	vector<int> nums;
	int s;
	scanf("%d", &s);

	nums.reserve(s);

	int stackNum = 1;

	stack<int> stac;		// tmp
	vector<int> stackOpers; // out
	stackOpers.reserve(s);
	for (int i = 0; i < s; i++)
	{
		int k;
		scanf("%d", &k);
		nums.emplace_back(k);
	}

	for (auto i : nums)
	{
		if (!stac.empty())
		{
			if (stac.top() > i || (stac.top() < i && stackNum > i))
			{
				printf("NO");
				return 0;
			}
		}
		while (stackNum <= i)
		{
			stac.push(stackNum);
			stackOpers.emplace_back(1);
			stackNum++;
		}
		if(stac.top() == i)
		{
			stac.pop();
			stackOpers.emplace_back(0);
		}
		
	}
	if (stac.empty())
	{
		for (int i : stackOpers)
		{
			if (i)
			{
				printf("+\n");
			}
			else
			{
				printf("-\n");
			}
		}
	}

	return 0;
}