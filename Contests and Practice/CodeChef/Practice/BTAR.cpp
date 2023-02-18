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
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    //cin.tie(NULL);                    \
    //cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
void chk(ll tmp, int &c1, int &c2, int &c3)
{
    if (tmp == 1)
        c1++;
    else if (tmp == 2)
        c2++;
    else if (tmp == 3)
        c3++;
}
int main()
{
    fastio;
    test
    {
        int n, c1 = 0, c2 = 0, c3 = 0, ct = 0;
        cin >> n;
        ll tmp;
        multiset<ll> m;
        fo(i, n)
        {
            cin >> tmp;
            tmp %= 4;
            //cout << " -> " << tmp << " ";
            chk(tmp, c1, c2, c3);
        }
        //cout << c1 << c2 << c3;
        ct += (c2 / 2);
        c2 %= 2;
        int min, max;
        if (c3 >= c1)
        {
            max = c3;
            min = c1;
        }
        else
        {
            max = c1;
            min = c3;
        }

        //cout << max<<min;
        ct += min;
        max = max - min;
        min = 0;
        ct += (max / 4) * 3;
        max %= 4;

        if (c2 == 1)
        {
            if (max == 2)
            {
                ct += 2;
            }
            else
            {
                ct = -1;
            }
        }
        else if (max != 0)
        {
            ct = -1;
        }

        cout << ct << endl;
    }
}