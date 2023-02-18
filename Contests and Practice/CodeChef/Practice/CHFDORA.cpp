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
int main()
{
    fastio;
    test
    {
        int n, m, ct;
        cin >> n >> m;
        ct = n * m;
        ll a[n][m];
        fo(i, n)
        {
            fo(j, m)
            {
                cin >> a[i][j];
            }
        }
        for (i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {   
                for (int r = 1, c = 1;;)
                {
                    if ((j - c) < 0 || (i - r < 0) || (j + c) >= m || (i + r) >= n)
                        break;
                    else if (a[i - r][j] == a[i + r][j] && a[i][j - c] == a[i][j + c])
                    {
                        ct++;
                        r++;
                        c++;
                    }
                    else
                        break;
                }
            }
        }
        cout << ct << endl;
    }
}
