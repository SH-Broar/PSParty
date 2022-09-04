#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> stairs;
	vector<int> oneStepScores;
	vector<int> twoStepScores;

	int n;
	cin >> n;

	oneStepScores.resize(n);
	twoStepScores.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		stairs.push_back(tmp);
	}

	if (n == 1)
	{
		cout << stairs[0];
		return 0;
	}
	if (n == 2)
	{
		cout << stairs[0] + stairs[1];
		return 0;
	}

	oneStepScores[0] = stairs[0];
	twoStepScores[0] = stairs[0];
	oneStepScores[1] = oneStepScores[0] + stairs[1];
	twoStepScores[1] = stairs[1];

	for (int i = 2; i < n; ++i)
	{
		oneStepScores[i] = twoStepScores[i - 1] + stairs[i];
		twoStepScores[i] = max(oneStepScores[i - 2], twoStepScores[i - 2]) + stairs[i];
	}

	cout << max(oneStepScores[n - 1], twoStepScores[n - 1]);
}