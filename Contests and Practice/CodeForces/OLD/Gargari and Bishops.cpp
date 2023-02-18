#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define M 1000000007
#define nl cout << '\n'
#define us unsigned short
#define ull unsigned long long
#define ui unsigned int
#define ll long long
#define ld long double
#define ul unsigned long
#define endl '\n'
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pb push_back
#define paus system("pause");
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define Sortg(v) sort(v.begin(), v.end(), greater<int>())
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
//----------------------------------------------------------------------------------//
// Include lines And Stuff Above
int main()
{
    fastio;
    int n;
    cin >> n;
    ll a[n][n], ans[n][n];
    fo(i, n)
    {
        fo(j, n)
        {
            cin >> a[i][j];
        }
    }
    ll sumrd[2 * n + 1], sumldb[n], sumldt[n];
    for (int i = 0, x = n; i < n; i++, x++)
    {
        ll sum1 = 0;
        ll sum2 = 0;
        ll sum3 = 0;
        ll sum4 = 0;
        for (int j = 0, k = i, l = i, m = x - n + 1, o = n - 1; j < n; k++, j++, l--, o--, m++)
        {
            if (k < n)
            {
                sum1 += a[j][k];
                sum2 += a[k][j];
            }
            if (j <= i)
                sum3 += a[l][j];
            if (m < n)
                sum4 += a[o][m];
        }

        sumldt[i] = sum1;
        sumldb[i] = sum2;
        sumrd[i] = sum3;
        sumrd[x] = sum4;
    }
    ll maxo = 0, maxe = 0;
    int io, jo, ie, je;
    fo(i, n)
    {
        fo(j, n)
        {
            if (i <= j)
            {
                ans[i][j] = sumrd[i + j] + sumldt[j - i] - a[i][j];
            }
            else
            {
                ans[i][j] = sumrd[i + j] + sumldb[i - j] - a[i][j];
            }
            if ((i + j) & 1)
            {
                if (ans[i][j] >= maxo)
                {
                    maxo = ans[i][j];
                    io = i + 1;
                    jo = j + 1;
                }
            }
            else
            {
                if (ans[i][j] >= maxe)
                {
                    maxe = ans[i][j];
                    ie = i + 1;
                    je = j + 1;
                }
            }
        }
    }
    cout << maxe + maxo << endl;
    cout << ie << " " << je << " " << io << " " << jo << endl;
}
