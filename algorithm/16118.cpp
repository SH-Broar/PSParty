#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graphs;
vector<long long> foxcosts;
vector<long long> odwolfcosts;
vector<long long> evwolfcosts;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> fnexter;
priority_queue<pair<long long, pair<long long, char>>, vector<pair<long long, pair<long long, char>>>, greater<>> wnexter;

#define DIST 4247480000

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	graphs.resize(n+1);
	foxcosts.resize(n+1, DIST);
	odwolfcosts.resize(n+1, DIST);
	evwolfcosts.resize(n+1, DIST);

	//foxcosts[0] = 0;
	//odwolfcosts[0] = 0;
	//evwolfcosts[0] = 0;

	//foxcosts[1] = 0;
	//evwolfcosts[1] = 0;

	for (int i = 0; i < m; ++i)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		graphs[a].emplace_back(c*2, b);
		graphs[b].emplace_back(c*2, a);
	}

	fnexter.push({ 0, 1 });

	while (!fnexter.empty())
	{
		long long first = fnexter.top().first;
		long long second = fnexter.top().second;
		fnexter.pop();

		if (foxcosts[second] != DIST)
			continue;

		foxcosts[second] = first;
		for (auto i : graphs[second])
		{
			long long far = i.first;
			long long nnode = i.second;
			
			if (foxcosts[nnode] == DIST)
			{
				fnexter.push({ first + far, nnode });
			}
		}
	}

	wnexter.push({ 0, {1, 1} });

	while (!wnexter.empty())
	{
		long long first = wnexter.top().first;
		long long second = wnexter.top().second.first;
		char indexes = wnexter.top().second.second;
		wnexter.pop();

		if (indexes > 0)
		{
			if (odwolfcosts[second] != DIST)
				continue;

			odwolfcosts[second] = first;
			for (auto i : graphs[second])
			{
				long long far = i.first;
				long long nnode = i.second;
				//cout << "nnode : " << nnode+1 << " ocosts : " << odwolfcosts[nnode] << endl;

				if (evwolfcosts[nnode] == DIST)
				{
					wnexter.push({ first + far /2, {nnode, -1 * indexes} });
				}
			}
		}
		else
		{
			if (evwolfcosts[second] != DIST)
				continue;

			evwolfcosts[second] = first;
			for (auto i : graphs[second])
			{
				long long far = i.first;
				long long nnode = i.second;
				//cout << "nnode : " << nnode+1 << " ecosts : " << evwolfcosts[nnode] << endl;

				if (odwolfcosts[nnode] == DIST)
				{
					wnexter.push({ first + far * 2, {nnode, -1 * indexes} });
				}
			}
		}
		
	}

	long long resulter = 0;
	for (long long i = 0; i < foxcosts.size(); i++)
	{
		if (foxcosts[i] < min(odwolfcosts[i], evwolfcosts[i]))
			resulter++;
	}
	cout << resulter;
}