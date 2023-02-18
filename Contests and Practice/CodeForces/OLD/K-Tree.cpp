#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <stack>
#include <list>
#include <queue>
#include <sstream>
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
ll i, j, temp;
#define fok(i, k, n) for (i = k; i < n; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, n) for (i = n; i >= 0; i--)
#define Sort(v) sort(v.begin(), v.end())
#define fastio ios_base::sync_with_stdio(false);
//cin.tie(NULL);                    \
//cout.tie(NULL); // to get output after all input is done
#define test  \
    ul t;     \
    cin >> t; \
    while (t--)
//----------------------------------------------------------------------------------//
//Include lines And Stuff Above
int dpp[101];
int dpp1[101];
ll dp(int n, int k, int d)
{
    if (n == 0 && d != -1)
    {
        return 0;
    }
    else if (n == 0 && d == -1)
        return 1;
    else if (d == -1)
    {
        ll sum = 0;
        int i;
        fok(i, 1, k + 1)
        {
            if (n - i >= 0)
            {
                if (dpp1[n - i] == -1)
                    dpp1[n - i] = dp(n - i, k, -1);
                sum += (dpp1[n - i]);
            }
            else
            {
                break;
            }
        }
        return sum%M;
    }
    else
    {
        ll sum = 0;
        int i;
        fok(i, 1, k + 1)
        {
            if (n - i >= 0)
            {
                if (i < d)
                {
                    if (dpp[n - i] == -1)
                        dpp[n - i] = dp(n - i, k, d);
                    sum += (dpp[n - i]);
                }
                else
                {
                    if (dpp1[n - i] == -1)
                        dpp1[n - i] = dp(n - i, k, -1);
                    sum += (dpp1[n - i]);
                }
            }
            else
            {
                break;
            }
        }
        return sum%M;
    }
}

int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    fo(i, 101)
    {
        dpp[i] = -1;
        dpp1[i] = -1;
    }
    cout << dp(n, k, d) << endl;
}