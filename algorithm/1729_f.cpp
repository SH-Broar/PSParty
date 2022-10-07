#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;

bool e_plus(int& to, int amount)
{
	to += amount;
	if (to >= 10)
	{
		to -= 10;
		return false;
	}
	return true;
}

void e_minus(int& to, int amount)
{
	to -= amount;
	if (to <= -1)
		to += 10;
}

bool columnCalc(int column, int amount, bool plus)
{
	bool ret = true;
	for (int i = 0; i < 6; ++i)
	{
		if (plus)
			ret &= e_plus(arr[column][i], amount);
		else
			e_minus(arr[column][i], amount);
	}
	return ret;
}

bool rowCalc(int row, int amount, bool plus)
{
	bool ret = true;
	for (int i = 0; i < 6; ++i)
	{
		if (plus)
			ret &= e_plus(arr[i][row], amount);
		else
			e_minus(arr[i][row], amount);
	}
	return ret;
}

bool XCalc(bool leftupLine, int amount, bool plus)
{
	bool ret = true;
	for (int i = 0; i < 6; ++i)
	{
		if (leftupLine)
		{
			if (plus)
				ret &= e_plus(arr[i][i], amount);
			else
				e_minus(arr[i][i], amount);
		}
		else
		{
			if (plus)
				ret &= e_plus(arr[i][6 - i - 1], amount);
			else
				e_minus(arr[i][6 - i - 1], amount);
		}
	}
	return ret;
}

int finder()
{
	int maxx = -1;
	for (int i = 0; i < 6; ++i)
	{
		for (int am = 9; am >= 0; --am)
		{
			if (columnCalc(i, am, true))	//더했는데 0이 안 되면
			{
				for (int k = 0; k < 6; ++k)
				{
					for (int amt = 9; amt >= 0; --amt)
					{
						if (rowCalc(i, amt, true))	//더했는데 0이 안 되면
						{
							for (int amt = 9; amt >= 0; --amt)
							{
								if (XCalc(true, amt, true))	//더했는데 0이 안 되면
								{
									for (int amt = 9; amt >= 0; --amt)
									{
										if (XCalc(false, amt, true))	//더했는데 0이 안 되면
										{
											int tmpMax = 0;
											for (int i = 0; i < 6; ++i)
											{
												for (int j = 0; j < 6; ++j)
												{
													cout << arr[i][j];
													tmpMax += arr[i][j];
												}
												cout << endl;
											}
											cout << endl;
											if (tmpMax > maxx)
												maxx = tmpMax;
										}
										else
										{
											XCalc(false, amt, false);
										}
									}
								}
								else
								{
									XCalc(true, amt, false);
								}
							}
						}
						else
						{
							rowCalc(i, amt, false);
						}
					}

				}
			}
			else
			{
				columnCalc(i, am, false);
			}
		}

	}
	return maxx;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	arr.resize(6);
	for (auto& v : arr)
		v.resize(6);


	int maxx = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			int a;
			cin >> a;
			maxx += a;
			arr[i][j] = a;
		}
	}

	int r = finder();
	cout << r;

}