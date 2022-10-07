#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<char> characters;

void dfs(string str, int level, int last, vector<int> visited, int aeiou, int other)
{
	if (level == L)
	{
		if (aeiou >= 1 && other >= 2)
			cout << str << "\n";
		return;
	}

	for (int i = last; i < C; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			if (characters[i] == 'a' || characters[i] == 'e' || characters[i] == 'i' || characters[i] == 'o' || characters[i] == 'u')
				dfs(str + characters[i], level + 1, i, visited, aeiou+1, other);
			else
				dfs(str + characters[i], level + 1, i, visited, aeiou, other+1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L >> C;

	for (int i = 0; i < C; ++i)
	{
		char p;
		cin >> p;
		characters.push_back(p);
	}
	
	sort(characters.begin(), characters.end());

	for (int i = 0; auto c : characters)
	{
		vector<int> visits;
		visits.resize(C);
		visits[i] = 1;
		string tmp{ c };
		
		if (c =='a' || c== 'e' || c == 'i' || c== 'o' || c== 'u')
			dfs(tmp, 1, i, visits,1,0);
		else
			dfs(tmp, 1, i, visits, 0, 1);
		i++;
	}
	
}