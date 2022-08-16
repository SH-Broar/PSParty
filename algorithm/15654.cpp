#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int length;

	cin >> n;
	cin >> length;

	vector<int> bases;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		bases.push_back(t);
	}
	sort(bases.begin(), bases.end());

	vector<int> resulter;
	vector<int> challenger;

	do
	{
		vector<int> challenger{ bases.begin(), bases.begin() + length };
		//if (is_sorted(challenger.begin(), challenger.end()))
		{
			if (resulter != challenger)
			{
				resulter = challenger;
				copy(resulter.begin(), resulter.end(), ostream_iterator<int>(cout, " "));
				cout << "\n";
			}
		}
	} while (next_permutation(bases.begin(), bases.end()));

}