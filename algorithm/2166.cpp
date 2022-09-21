#include <iostream>
#include <vector>
using namespace std;

struct point
{
	long long x;
	long long y;

	point(long long a, long long b)
	{
		x = a;
		y = b;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	
	vector<point> points;
	for (int i = 0; i < n; ++i)
	{
		long long a, b;
		cin >> a >> b;
		points.emplace_back(a, b);
	}

	long long lefts = 0;
	long long rights = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		lefts += points[i].x * points[(i + 1) % points.size()].y;
		rights += points[i].y * points[(i+1)%points.size()].x;
	}
	long long t = abs(lefts - rights);
	cout << t / 2;
	cout << (t % 2 ? ".5" : ".0");
}