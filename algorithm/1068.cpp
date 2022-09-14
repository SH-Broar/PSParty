#include <iostream>
#include <vector>
using namespace std;

struct nodes
{
	int parents;
	int nleafs;
	bool end;

	nodes()
	{
		parents = 0;
		nleafs = 1;
		end = true;
	}

	nodes(int a)
	{
		parents = a;
		nleafs = 1;
		end = true;
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;

	vector<nodes> leafs;
	leafs.resize(n);

	int head = -2;
	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		
		nodes tmp{ p };
		tmp.end = leafs[i].end;
		tmp.nleafs = leafs[i].nleafs;
		
		if (p != -1)
		{
			leafs[p].end = false;
			leafs[p].nleafs = 0;
		}
		else
		{
			head = i;
		}
		leafs[i] = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		if (leafs[i].end)
		{
			nodes* q;
			q = &leafs[i];
			while (q->parents != -1)
			{
				leafs[q->parents].nleafs += leafs[i].nleafs; //(1)
				q = &leafs[q->parents];
			}
		}
	}

	//for (auto& v : leafs)
	//{
	//	cout << v.nleafs << " ";
	//}

	int delLeaf;
	cin >> delLeaf;
	if (delLeaf != head && leafs[leafs[delLeaf].parents].nleafs == leafs[delLeaf].nleafs)
	{
		cout << leafs[head].nleafs - leafs[delLeaf].nleafs + 1;
	}
	else
	{
		cout << leafs[head].nleafs - leafs[delLeaf].nleafs;
	}
}