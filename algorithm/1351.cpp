#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> seq;

long long finder(long long n, long long p, long long q)
{
	if (n == 0)
	{
		return 1;
	}

	if (seq.find(n) != seq.end())
		return seq[n];

	seq[n] = finder(n / p, p, q) + finder(n / q, p, q);

	return seq[n];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, P, Q;
	cin >> N >> P >> Q;
	
	cout << finder(N, P, Q);
}