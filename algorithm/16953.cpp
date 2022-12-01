#include <iostream>
#include <vector>
using namespace std;

long long re;

constexpr long long maxx = 2000000000ll;

long long bfs(long long n, long long counts)
{
	if (n == re)
		return counts;

	long long min = maxx;
	if (n * 2 <= re)
	{
		long long b = bfs(n * 2, counts + 1);
		if (b < min)
			min = b;
	}
	if (n * 10 + 1 <= re)
	{
		long long b = bfs(n * 10 +1, counts + 1);
		if (b < min)
			min = b;
	}
	return min;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	long long n;
	cin >> n;
	cin >> re;

	long long full = bfs(n, 1);
	if (full == maxx)
		cout << "-1";
	else
		cout << full;
}