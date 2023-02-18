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
#define Fo(i, n) for (i = n; i >= 0; i--)
#define fok(i, k, n) for (i = k; i < n; i++)
#define forj for (j = 0; j < n; j++)
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
using namespace std;
//----------------------------------------------------------------------------------//
us fun(us a[],us n, us m)
{
    if (n == 0)
        return 0;
    else if((a[n-1]+fun(a,n-1,m-a[n-1]))==m)
    {
        return m;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); // just speeds up execution time
    cin.tie(NULL);                    // to get output after all input is done
    test 
    {
        us n,m;
        cin >> n >> m;
        us a[n];
        fo(i,n)
        {
            cin >> a[i];
        }
        cout<<fun(a, n, m);
    }
}