#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
	char left;
	char right;
};

vector<node> tree;

void preorder(char index)
{
	if (index == '.' - 'A')
		return;

	cout << (char)(index + 'A');
	preorder(tree[index].left - 'A');
	preorder(tree[index].right - 'A');
}

void midorder(char index)
{
	if (index == '.' - 'A')
		return;

	midorder(tree[index].left - 'A');
	cout << (char)(index + 'A');
	midorder(tree[index].right - 'A');
}

void postorder(char index)
{
	if (index == '.' - 'A')
		return;

	postorder(tree[index].left - 'A');
	postorder(tree[index].right - 'A');
	cout << (char)(index + 'A');

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	tree.resize(26);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char a, b, c;
		cin >> a >> b >> c;

		tree[a - 'A'].left = b;
		tree[a - 'A'].right = c;
	}

	preorder(0);
	cout << "\n";
	midorder(0);
	cout << "\n";
	postorder(0);

}