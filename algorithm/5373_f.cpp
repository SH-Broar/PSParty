#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Space
{
	int a, b, c;
	int d, e, f;
	int h, i, j;

	int tmpa, tmpb, tmpc;
	int *toa, *tob, *toc;

	int thisSpace;

	Space* L;
	Space* R;
	Space* U;
	Space* D;

public:
	Space()
	{
		a = b = c = d = e = f = h = i = j = 0;
		tmpa = tmpb = tmpc = thisSpace = 0;
		toa = tob = toc = nullptr;
		L = R = U = D = nullptr;
	}
	
	void SetPointer(Space* aa, Space* bb, Space* cc, Space* dd)
	{
		L = aa;
		R = bb;
		U = cc;
		D = dd;
	}

	void SetColor(int color)
	{
		a = b = c = d = e = f = h = i = j = color;
		thisSpace = color - 1;
	}

	void LSpin()
	{
		int tmp = h, tmp2 = d;
		h = a; d = b; a = c;
		b = f; c = j; f = i;
		j = tmp; i = tmp2;
		L->LSpin_Rec(this);
		R->LSpin_Rec(this);
		U->LSpin_Rec(this);
		D->LSpin_Rec(this);
		L->Spin_Set();
		R->Spin_Set();
		U->Spin_Set();
		D->Spin_Set();
	}
	void RSpin()
	{
		int tmp = a, tmp2 = d;
		a = h; d = i; h = j;
		i = f; j = c; f = b;
		c = tmp; b = tmp2;
		L->RSpin_Rec(this);
		R->RSpin_Rec(this);
		U->RSpin_Rec(this);
		D->RSpin_Rec(this);
		L->Spin_Set();
		R->Spin_Set();
		U->Spin_Set();
		D->Spin_Set();
	}

	void LSpin_Rec(Space* from)
	{
		if (from == L)
		{
			tmpa = D->a;
			tmpb = D->d;
			tmpc = D->h;
			toa = &a;
			tob = &d;
			toc = &h;
			if (thisSpace == 4)
			{
				tmpa = D->h;
				tmpb = D->i;
				tmpc = D->j;
			}
			if (thisSpace == 5)
			{
				tmpa = D->c;
				tmpb = D->b;
				tmpc = D->a;
			}
		}
		else if (from == R)
		{
			tmpa = U->c;
			tmpb = U->f;
			tmpc = U->j;
			toa = &c;
			tob = &f;
			toc = &j;
			if (thisSpace == 4)
			{
				tmpa = U->j;
				tmpb = U->i;
				tmpc = U->h;
			}
			if (thisSpace == 5)
			{
				tmpa = U->a;
				tmpb = U->b;
				tmpc = U->c;
			}
		}
		else if (from == U)
		{
			tmpa = L->a;
			tmpb = L->b;
			tmpc = L->c;
			toa = &a;
			tob = &b;
			toc = &c;
			if (thisSpace == 0)
			{
				tmpa = L->h;
				tmpb = L->d;
				tmpc = L->a;
			}
			if (thisSpace == 1)
			{
				tmpa = L->c;
				tmpb = L->f;
				tmpc = L->j;
			}
			if (thisSpace == 3)
			{
				tmpa = L->j;
				tmpb = L->i;
				tmpc = L->h;
			}
			if (thisSpace == 4)
			{
				tmpa = L->j;
				tmpb = L->i;
				tmpc = L->h;
			}
		}
		else if (from == D)
		{
			tmpa = R->h;
			tmpb = R->i;
			tmpc = R->j;
			toa = &h;
			tob = &i;
			toc = &j;
			if (thisSpace == 0)
			{
				tmpa = R->a;
				tmpb = R->d;
				tmpc = R->h;
			}
			if (thisSpace == 1)
			{
				tmpa = R->j;
				tmpb = R->f;
				tmpc = R->c;
			}
			if (thisSpace == 3)
			{
				tmpa = R->c;
				tmpb = R->b;
				tmpc = R->a;
			}
			if (thisSpace == 5)
			{
				tmpa = R->c;
				tmpb = R->b;
				tmpc = R->a;
			}
		}
	}
	void RSpin_Rec(Space* from)
	{
		if (from == L)
		{
			tmpa = U->a;
			tmpb = U->d;
			tmpc = U->h;
			toa = &a;
			tob = &d;
			toc = &h;
			if (thisSpace == 4)
			{
				tmpa = D->c;
				tmpb = D->b;
				tmpc = D->a;
			}
			if (thisSpace == 5)
			{
				tmpa = D->h;
				tmpb = D->i;
				tmpc = D->j;
			}
		}
		else if (from == R)
		{
			tmpa = D->c;
			tmpb = D->f;
			tmpc = D->j;
			toa = &c;
			tob = &f;
			toc = &j;
			if (thisSpace == 4)
			{
				tmpa = D->a;
				tmpb = D->b;
				tmpc = D->c;
			}
			if (thisSpace == 5)
			{
				tmpa = D->j;
				tmpb = D->i;
				tmpc = D->h;
			}
		}
		else if (from == U)
		{
			tmpa = R->a;
			tmpb = R->b;
			tmpc = R->c;
			toa = &a;
			tob = &b;
			toc = &c;
			if (thisSpace == 0)
			{
				tmpa = R->c;
				tmpb = R->f;
				tmpc = R->j;
			}
			if (thisSpace == 1)
			{
				tmpa = R->h;
				tmpb = R->d;
				tmpc = R->a;
			}
			if (thisSpace == 3)
			{
				tmpa = R->j;
				tmpb = R->i;
				tmpc = R->h;
			}
			if (thisSpace == 5)
			{
				tmpa = R->j;
				tmpb = R->i;
				tmpc = R->h;
			}
		}
		else if (from == D)
		{
			tmpa = L->h;
			tmpb = L->i;
			tmpc = L->j;
			toa = &h;
			tob = &i;
			toc = &j;
			if (thisSpace == 0)
			{
				tmpa = L->j;
				tmpb = L->f;
				tmpc = L->c;
			}
			if (thisSpace == 1)
			{
				tmpa = L->a;
				tmpb = L->d;
				tmpc = L->h;
			}
			if (thisSpace == 3)
			{
				tmpa = L->c;
				tmpb = L->b;
				tmpc = L->a;
			}
			if (thisSpace == 4)
			{
				tmpa = L->c;
				tmpb = L->b;
				tmpc = L->a;
			}
		}
	}

	void Spin_Set()
	{
		*toa = tmpa;
		*tob = tmpb;
		*toc = tmpc;
	}
	vector<int> print()
	{
		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		v.push_back(e);
		v.push_back(f);
		v.push_back(h);
		v.push_back(i);
		v.push_back(j);
		return v;
	}
};

class Cube
{
	vector<Space> maps;
public:
	Cube()
	{
		maps.resize(6);
		for (int i = 0; i < 6; ++i)
			maps[i].SetColor(i + 1);

		maps[0].SetPointer(&maps[4], &maps[5], &maps[3], &maps[2]);
		maps[1].SetPointer(&maps[4], &maps[5], &maps[2], &maps[3]);
		maps[2].SetPointer(&maps[4], &maps[5], &maps[0], &maps[1]);
		maps[3].SetPointer(&maps[4], &maps[5], &maps[1], &maps[0]);
		maps[4].SetPointer(&maps[3], &maps[2], &maps[0], &maps[1]);
		maps[5].SetPointer(&maps[2], &maps[3], &maps[0], &maps[1]);
	}
	void operation(string oper)
	{
		switch (oper[0])
		{
		case 'U':
			if (oper[1] == '-')
				maps[0].LSpin();
			else
				maps[0].RSpin();
			break;
		case 'D':
			if (oper[1] == '-')
				maps[1].LSpin();
			else
				maps[1].RSpin();
			break;
		case 'F':
			if (oper[1] == '-')
				maps[2].LSpin();
			else
				maps[2].RSpin();
			break;
		case 'B':
			if (oper[1] == '-')
				maps[3].LSpin();
			else
				maps[3].RSpin();
			break;
		case 'L':
			if (oper[1] == '-')
				maps[4].LSpin();
			else
				maps[4].RSpin();
			break;
		case 'R':
			if (oper[1] == '-')
				maps[5].LSpin();
			else
				maps[5].RSpin();
			break;
		}
	}

	void printUpper()
	{
		vector<int> v;
		v = maps[0].print();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				switch (v[(i * 3) + j])
				{
				case 1:
					cout << "w";
					break;
				case 2:
					cout << "y";
					break;
				case 3:
					cout << "r";
					break;
				case 4:
					cout << "o";
					break;
				case 5:
					cout << "g";
					break;
				case 6:
					cout << "b";
					break;
				}
			}
			cout << "\n";
		}
	}


};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Cube cube;

		int num;
		cin >> num;
		for (int k = 0; k < num; ++k)
		{
			string oper;
			cin >> oper;

			cube.operation(oper);
		}

		cube.printUpper();
	}
}

/*
8
U- D+ B+ U+ D+ R- B- R+

10
B- U- L- L+ L- B+ L- R- U- F+

11
D+ F- D+ B+ R- L+ L+ U+ U+ B+ U-


*/
/*
bwr
wwb
wwr

goo
www
yyr

ryy
rwb
wrr
*/