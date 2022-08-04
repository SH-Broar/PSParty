
#include <vector>
#include <numeric>


long long sum(std::vector<int>&a)
{
	long long s;
	s = accumulate(a.begin(), a.end(), (long long)0);
	return s;
}