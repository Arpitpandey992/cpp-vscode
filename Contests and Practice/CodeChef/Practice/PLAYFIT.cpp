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
#define endl '\n'
ll i, j, temp;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n - 1; i >= 0; i--)
#define fok(i, k, n) for (i = k; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
int main()
{
    ios_base::sync_with_stdio(false); // just speeds up execution time
    //cin.tie(NULL);                    // to get output after all input is done
    test
    {
        ui n;
        cin >> n;
        ll minm, cur, maxm;
        cin >> cur;
        minm = cur;
        maxm = 0;
        if (n == 1)
        {
            cout << "UNFIT\n";
            continue;
        }
        for (i = 1; i < n; i++)
        {
            cin >> cur;
            if ((cur - minm) > maxm)
            {
                maxm = cur - minm;
            }
            if (cur < minm)
            {
                minm = cur;
            }
        }
        if (maxm <= 0)
            cout << "UNFIT\n";
        else
        {
            cout << maxm << endl;
        }
    }
}