#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;


	for (int t = 0; t < T; ++t)
	{
		int n;
		cin >> n;

		vector<vector<int>> lines;
		lines.resize(2);
		lines[0].resize(n);
		lines[1].resize(n);

		vector<vector<int>> scores;
		scores.resize(3);
		scores[0].resize(n);
		scores[1].resize(n);
		scores[2].resize(n);

		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			lines[0][i] = tmp;
		}
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			lines[1][i] = tmp;
		}

		scores[0][0] = lines[0][0];
		scores[1][0] = lines[1][0];
		scores[2][0] = 0;

		for (int i = 1; i < n; ++i)
		{
			scores[0][i] = max(scores[1][i - 1], scores[2][i - 1]) + lines[0][i];
			scores[1][i] = max(scores[0][i - 1], scores[2][i - 1]) + lines[1][i];
			scores[2][i] = max(scores[0][i - 1], scores[1][i - 1]);
		}

		cout << max(max(scores[0][n - 1], scores[1][n - 1]), scores[2][n - 1]) << "\n";
	}
}