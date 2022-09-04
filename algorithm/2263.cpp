#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
	int v;
	node* left = nullptr;
	node* right = nullptr;

	bool operator==(const node& n)
	{
		return v == n.v;
	}
};

vector<node> inorders;
vector<node> postorders;
int p_index;

node* finder(const vector<node>::iterator& a, const vector<node>::iterator& b)
{
	if (a > b)
		return nullptr;

	node* tmp = &postorders[p_index];
	//cout << p_index << " " << tmp->v << "\n";
	p_index--;

	auto it = find(a, b, *tmp);
	
	if (it != inorders.end()-1)
		tmp->right = finder(it + 1, b);
	if (it != inorders.begin())
		tmp->left = finder(a, it - 1);

	return tmp;
}

void preorder(node* n)
{
	if (n != nullptr)
	{
		cout << n->v << " ";
		preorder(n->left);
		preorder(n->right);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		node tmp;
		tmp.v = t;
		inorders.push_back(tmp);
	}
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		node tmp;
		tmp.v = t;
		postorders.push_back(tmp);
	}
	p_index = n - 1;

	auto root = finder(inorders.begin(), inorders.end()-1);
	preorder(root);
}
