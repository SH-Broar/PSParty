#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool q(string a, string b);

bool q( string a,  string b)
{
    if (a.size() > b.size())
    {
        return false;
    }
    else if (a.size() < b.size())
    {
        return true;
    }
    else
    {
        if (a.compare(b) == 0)
            return false;
        else if (a.compare(b) < 0)
            return true;
        else
            return false;

    }
}

int main()
{
    vector<string> ex;
    ex.reserve(100);

    int num = 0;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string tmp;
        cin >> tmp;
        ex.push_back(tmp);
    }

    sort(ex.begin(), ex.end(), q);
    ex.erase(unique(ex.begin(), ex.end()), ex.end());

    for (int i = 0; i < ex.size(); i++)
    {
        cout << ex[i] << endl;
    }

    return 0;
}