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
int main()
{
    ios_base::sync_with_stdio(false); // just speeds up execution time
    cin.tie(NULL);                    // to get output after all input is done
    test 
    {
        int n, k, num;
        cin >> n;
        int a[n], ct = 0;
        fo(i, n)
        {
            cin >> a[i];
        }
        cin >> k;
        fo(i, k)
        {
            if (a[i] < a[k - 1])
                ct++;
           // cout << ct << " ";
        }
        fok(i, k, n)
        {
            if (a[i] < a[k - 1])
                ct++;
        }

        cout << ct+1 << endl;
    }
}