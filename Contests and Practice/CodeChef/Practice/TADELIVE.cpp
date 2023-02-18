#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ul unsigned long
ll i, j;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    int n, x, y, temp, ct = 0;
    cin >> n >> x >> y;
    multiset<int> a, b;
    map<int, int> ak, bk;
    fo(i, n)
    {
        cin >> temp;
        a.insert(temp);
        ak[temp] = i;
    }
    fo(i, n)
    {
        cin >> temp;
        b.insert(temp);
        bk[i] = temp;
    }
    auto it1 = a.end();
    it1--;
    fo(i, x)
    {
        int temp1 = ak[*it1];
        int temp2 = bk[temp1];
        cout << *it1 << " " << temp2 << " ";
        if (*it1 >= temp2)
        {
            ct += *it1;
            it1--;
            auto it = b.find(temp2);
            b.erase(it);
        }
        else
        {
            it1--;
            i--;
        }
        cout << ct << endl;
    }
    auto it2 = b.end();
    it2--;
    bool flag = 1;
    for (i = 0; i < y && flag;i++)
    {
        cout << *it2 << " ";
        if(it2==(b.begin()))
            flag = 0;
        ct += *it2;
        it2--;
        cout << ct << endl;
    }
    cout << ct << endl;
}
