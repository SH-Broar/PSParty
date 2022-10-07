#include <iostream>
#include <set>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n, k;
	cin >> n >> k;

	vector<string> rgx;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		rgx.push_back(tmp);
	}
	deque<bool> coms;
	coms.resize(rgx[0].size());

	
}