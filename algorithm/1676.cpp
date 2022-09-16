#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	
	int r = 0;
	r += n / 5;
	r += n / 25;
	r += n / 125;

	cout << r;
}