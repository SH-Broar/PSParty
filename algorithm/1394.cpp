#include <iostream>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;

constexpr int mod = 900528;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string cas;
	cin >> cas;

	string key;
	cin >> key;
	string rkey{ key.rbegin(),key.rend() };

	unordered_map<char,int> mapper;
	for (int i=0;i<cas.size();++i)
	{
		mapper[cas[i]] = i + 1;
	}
	
	long long total = 0;
	long long poww = 1;
	for (int i = 0; i < rkey.size(); ++i)
	{
		total += poww * mapper[rkey[i]];
		total %= mod;
		poww *= cas.size();
		poww %= mod;
	}

	cout << total;
	
}