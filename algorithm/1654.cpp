#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Qfind(long long int l, long long int r);

long long int K, N;
vector<long long int> lines;
long long int res = 0;

int main()
{
	cin >> K >> N;

	lines.reserve(2500);

	for (long long int i = 0; i < K; i++)
	{
		int a;
		cin >> a;
		lines.emplace_back(a);
	}

	long long int max = *max_element(lines.begin(), lines.end());

	sort(lines.begin(), lines.end());

	Qfind(1, lines[K - 1]);

	cout << res;
}

void Qfind(long long int l, long long int r)
{
	if (l > r)
		return;
	long long int mid = (l + r) / 2;
	long long int n = 0;

	for (auto i : lines)
	{
		n += i / mid;
	}

	if (n >= N)
	{
		res = res > mid ? res : mid;
		Qfind(mid + 1, r);
	}

	if (n < N)
	{
		Qfind(l, mid - 1);
	}
}